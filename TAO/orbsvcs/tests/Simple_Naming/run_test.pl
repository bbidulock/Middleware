# $Id$
# -*- perl -*-
eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# This is a Perl script that runs the client and all the other servers that
# are needed

unshift @INC, '../../../../bin';
require Process;
require Uniqueid;

# amount of delay between running the servers

$sleeptime = 8;

# variables for parameters

$nsmport = 10000 + uniqueid ();

sub name_server
{
  my $args = "-ORBnameserviceport $nsmport";
  my $prog = "..$DIR_SEPARATOR..$DIR_SEPARATOR"."Naming_Service".$DIR_SEPARATOR.
             "Naming_Service".$Process::EXE_EXT;

  $NS = Process::Create ($prog, $args);
}

sub client
{
  my $args = $_[0]." "."-ORBnameserviceport $nsmport";
  my $prog = $EXEPREFIX."client".$Process::EXE_EXT;
    
  system ($prog." ".$args);
}

# Options for all tests recognized by the 'client' program. 
@opts = ("-s", "-t", "-i", "-e", "-y");

@comments = ("Simple Test: \n", 
	     "Tree Test: \n",
	     "Iterator Test: \n",
	     "Exceptions Test: \n",
	     "Destroy Test: \n");

$test_number = 0;

# Run server and client with each option available to the client.
foreach $o (@opts)
{
  name_server ();

  sleep $sleeptime;
  print "\n";
  print "          ".$comments[$test_number];

  client ($o);

  $NS->Kill ();
  $test_number++;
}

print "\n";

# @@ Capture any exit status from the processes.
exit 0;
