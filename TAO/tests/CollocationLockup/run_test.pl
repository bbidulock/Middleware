eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib '../../../bin';
use PerlACE::Run_Test;

use strict;

# Amount of delay (in seconds) between starting a server and a client
# to allow proper server initialization.
my $sleeptime = 10;

# Variables for command-line arguments to client and server
# executables.
my $iorbase = "SimpleNamingService.ior";
my $iorfile = PerlACE::LocalFile ($iorbase);

my $status = 0;

my $NS = new PerlACE::Process ("SimpleNamingService");

unlink $iorfile;

$NS->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile, $sleeptime) == -1) {
  print STDERR "ERROR: cannot find IOR file <$iorfile>\n";
  $NS->Kill ();
  exit 1;
}

my $CL;
if (PerlACE::is_vxworks_test()) {
  $CL = new PerlACE::ProcessVX ("CollocationLockup",
                                "-ORBInitRef " .
                                "SimpleNamingService=file://$iorbase");
}
else {
  $CL = new PerlACE::Process ("CollocationLockup",
                              "-ORBInitRef " .
                              "SimpleNamingService=file://$iorfile");
}

my $client;
if ($^O eq "VMS") {
  # On OpenVMS this test does not lock up but takes much longer
  $client = $CL->SpawnWaitKill (300);
}
else {
# In testing on various platforms, the builds with the bug failed before
# 20 seconds and when the bug was fixed it returned before 20 seconds.
  $client = $CL->SpawnWaitKill (20);
}

if ($client != 0) {
  print STDERR "ERROR: client returned $client\n";
  $status = 1;
}

$NS->Kill ();

unlink $iorfile;

exit $status;
