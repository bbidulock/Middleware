#!/bin/sh
# $Id$

# =TITLE
#  Restart script
#
# =AUTHOR
#  Michael Kircher (mk1@cs.wustl.edu)
#
# =DESCRIPTION
#  This script restarts the Naming, Scheduling and Event Service,
#  "clean"  if it is specified as a parameter, then the old
#            services are only killed and not restarted
#  "lifecycle" if it is specified as a parameter, then
#              the LifeCycle Service Object is used
#              inbetween to ask the Generic Factory to
#              create an Quoter.

# save the old working dir
old_dir=`pwd`

#### Get the user name
if [ "$LOGNAME" ]; then
  #### LOGNAME is preserved across su
  login=$LOGNAME
else
  #### whoami returns the users login, which changes across su
  login=`whoami`
fi

# get the user id
uid=`id | cut -c5-20 | cut -f1 -d"("`

#### Set TAO_ROOT, if it wasn't set.
if [ ! "$TAO_ROOT" ]; then
  if [ "$ACE_ROOT" ]; then
    TAO_ROOT=$ACE_ROOT/TAO
  else
    echo $0: you must set ACE_ROOT or TAO_ROOT!
    exit 1
  fi
fi

echo // Killing the old services

if [ `uname -s` = 'SunOS' ]; then
  ps_opts=-ef
else
  ps_opts=aux
fi

ps $ps_opts | grep ORBnameserviceior | grep $login | grep -v grep | cut -c10-17 > /tmp/pids$login

if [ -s /tmp/pids$login ]; then
  pids=`cat /tmp/pids$login`
  kill $pids
fi


ps $ps_opts | grep Service | grep $login | grep -v grep | cut -c10-17 > /tmp/pids$login

if [ -s /tmp/pids$login ]; then
  pids=`cat /tmp/pids$login`
  kill $pids
fi


# stop here if "ss clean" was called
if [ $1 ]; then
  if [ $1 =  "clean" ]; then
     exit
  fi
fi

echo // Initializing the log file

if [ -r /tmp/logfile_$login ]; then
  rm /tmp/logfile_$login
fi

nameserviceport=`expr 20023 + $uid`
serverport=`expr 20024 + $uid`
factoryfinderport=`expr 20025 + $uid`
# the next port number is an exception, because we have nested call-backs
genericfactoryport=0     #   `expr 20026 + $uid`
lifecycleserviceport=`expr 20027 + $uid`
clientport=`expr 20028 + $uid`

cd $TAO_ROOT/orbsvcs/Naming_Service
./Naming_Service -ORBobjrefstyle URL -ORBport $nameserviceport >> /tmp/logfile_$login 2>&1  &

sleep 2

IOR=`cat /tmp/logfile_$login | grep IOR | cut -c21-300 | cut -f1 -d">" `

echo // The IOR of the Naming Service: $IOR

echo // Started Naming Service on port $nameserviceport

cd $TAO_ROOT/tests/Quoter
./server -ORBsvcconf server.conf -ORBnameserviceior $IOR -ORBport $serverport >> /tmp/logfile_$login  2>&1 &

echo // Started server on port $serverport

sleep  1

./Factory_Finder -ORBnameserviceior $IOR -ORBport $factoryfinderport >> /tmp/logfile_$login 2>&1 &


echo // Started Factory Finder on port $factoryfinderport

if [ $1 ]; then
  if [ $1 =  "lifecycle" ]; then

    sleep 1

    cd ../../orbsvcs/LifeCycle_Service

    ./Life_Cycle_Service -ORBnameserviceior $IOR -ORBport $lifecycleserviceport >>  /tmp/logfile_$login 2>&1 &

    cd $old_dir

    echo // Started Life Cycle Service on port $lifecycleserviceport
    sleep 1

    ./Generic_Factory -l -ORBnameserviceior $IOR -ORBport $genericfactoryport >> /tmp/logfile_$login 2>&1 &

    echo // Started Generic Factory on port $genericfactoryport
    echo // using the LifeCycle Service;

  fi
else
  sleep 1

  ./Generic_Factory  -ORBnameserviceior $IOR -ORBport $genericfactoryport >> /tmp/logfile_$login 2>&1 &

  echo // Started Generic Factory on port $genericfactoryport

fi

echo "// Enjoy the use ;-)"
echo See what is running:
echo ..
ps $ps_opts | grep $login | grep ORBnameserviceior
echo ..
echo call the client:
echo ..
./client -ORBsvcconf client.conf -ORBnameserviceior $IOR -ORBport $clientport

cd $old_dir
