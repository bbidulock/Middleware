eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

unshift @INC, '../../../bin';
require ACEutils;

$iorfile = "ior";

sub run_client
{
  my $args = shift;

  $CL = Process::Create ($EXEPREFIX."client$EXE_EXT ",
                         $args);

  $client = $CL->TimedWait (200);
  if ($client == -1) {
      $time = localtime;
      print STDERR "ERROR: client timedout at $time\n";
      $CL->Kill (); $CL->TimedWait (1);
  }
}

sub run_clients
{
  print STDERR "\n\n*** No event loop threads ***\n\n\n";

  print STDERR "\nSelect Reactor\n\n";

  run_client ("-e 0");

  print STDERR "\nTP Reactor\n\n";

  run_client ("-ORBsvcconf multi_threaded_event_loop.conf -e 0");

  print STDERR "\n\n*** Single-threaded client event loop: Select Reactor ***\n\n\n";

  print STDERR "\nSingle-threaded client running event loop for 3 seconds\n\n";

  run_client ("-e 1 -t 3000");

  print STDERR "\nSingle-threaded client running event loop for 10 seconds\n\n";

  run_client ("-e 1 -t 10000");

  print STDERR "\nSingle-threaded client running event loop for 20 seconds\n\n";

  run_client ("-e 1 -t 20000");

  print STDERR "\n\n*** Single-threaded client event loop: TP Reactor ***\n\n\n";

  print STDERR "\nSingle-threaded client running event loop for 3 seconds\n\n";

  run_client ("-ORBsvcconf multi_threaded_event_loop.conf -e 1 -t 3000");

  print STDERR "\nSingle-threaded client running event loop for 10 seconds\n\n";

  run_client ("-ORBsvcconf multi_threaded_event_loop.conf -e 1 -t 10000");

  print STDERR "\nSingle-threaded client running event loop for 20 seconds\n\n";

  run_client ("-ORBsvcconf multi_threaded_event_loop.conf -e 1 -t 20000");

  print STDERR "\n\n*** Multi-threaded client event loop: TP Reactor ***\n\n\n";

  print STDERR "\nMulti-threaded client running event loop for 3 seconds\n\n";

  run_client ("-ORBsvcconf multi_threaded_event_loop.conf -e 5 -t 3000");

  print STDERR "\nMulti-threaded client running event loop for 10 seconds\n\n";

  run_client ("-ORBsvcconf multi_threaded_event_loop.conf -e 5 -t 10000");

  print STDERR "\nMulti-threaded client running event loop for 20 seconds\n\n";

  run_client ("-ORBsvcconf multi_threaded_event_loop.conf -e 5 -t 20000 -x");
}

unlink $iorfile;

print STDERR "\n\n*** Single threaded server ***\n\n\n";

$SV = Process::Create ($EXEPREFIX."server$EXE_EXT");

if (ACE::waitforfile_timed ($iorfile, 5) == -1) {
  print STDERR "ERROR: cannot find file <$iorfile>\n";
  $SV->Kill (); $SV->TimedWait (1);
  exit 1;
}

run_clients ();

$server = $SV->TimedWait (100);
if ($server == -1) {
  $time = localtime;
  print STDERR "ERROR: server timedout at $time\n";
  $SV->Kill (); $SV->TimedWait (1);
}

unlink $iorfile;

if ($server != 0 || $client != 0) {
  exit 1;
}

print STDERR "\n\n*** Thread-per-connection server ***\n\n\n";

$SV = Process::Create ($EXEPREFIX."server$EXE_EXT",
                       "-ORBsvcconf thread_per_connection.conf");

if (ACE::waitforfile_timed ($iorfile, 5) == -1) {
  print STDERR "ERROR: cannot find file <$iorfile>\n";
  $SV->Kill (); $SV->TimedWait (1);
  exit 1;
}

run_clients ();

$server = $SV->TimedWait (100);
if ($server == -1) {
  $time = localtime;
  print STDERR "ERROR: server timedout at $time\n";
  $SV->Kill (); $SV->TimedWait (1);
}

unlink $iorfile;

if ($server != 0 || $client != 0) {
  exit 1;
}

exit 0;
