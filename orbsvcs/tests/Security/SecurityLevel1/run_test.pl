eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# -*- perl -*-
# $Id$

use Env (ACE_ROOT);

unshift @INC, "$ACE_ROOT/bin";
require ACEutils;

$status = 0;

# Set the SSL environment
$ENV{'SSL_CERT_FILE'} = 'ca.pem';

$iorfile = "server.ior";
unlink $iorfile;
$SV = Process::Create ($EXEPREFIX."server$EXE_EXT ",
                       " -ORBSvcConf server.conf "
                       . " -o $iorfile -ORBDebugLevel 4");

if (ACE::waitforfile_timed ($iorfile, 10) == -1) {
  print STDERR "ERROR: cannot find file <$iorfile>\n";
  $SV->Kill (); $SV->TimedWait (1);
  exit 1;
}

$CL = Process::Create ($EXEPREFIX."client$EXE_EXT ",
                       " -ORBSvcConf client.conf "
                       . " -k file://$iorfile -ORBDebugLevel 4");

$client = $CL->TimedWait (60);
if ($client == -1) {
  print STDERR "ERROR: client timedout\n";
  $CL->Kill (); $CL->TimedWait (1);
  $status = 1;
}

$server = $SV->TimedWait (15);
if ($server == -1) {
  print STDERR "ERROR: server timedout\n";
  $SV->Kill (); $SV->TimedWait (1);
  $status = 1;
}

unlink $iorfile;

exit $status;
