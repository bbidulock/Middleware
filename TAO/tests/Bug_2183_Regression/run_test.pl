eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# -*- perl -*-
# $Id$

use lib '../../../bin';
use PerlACE::Run_Test;

# The server IOR file
$server_ior_file = PerlACE::LocalFile ("server.ior");

# The client and server processes
if (PerlACE::is_vxworks_test()) {
  $SERVER     = new PerlACE::ProcessVX(PerlACE::LocalFile("server"));
}
else {
  $SERVER     = new PerlACE::Process(PerlACE::LocalFile("server"));
}
$perl_executable = $^X;
$perl_executable =~ s/\.exe//g;
$DUMMY_CLIENT = new PerlACE::Process($perl_executable);
$CLIENT     = new PerlACE::Process(PerlACE::LocalFile("client"));

$DUMMY_CLIENT->Arguments("hang_client.pl");
$DUMMY_CLIENT->IgnoreExeSubDir(1);

$SERVER->Arguments("-o $server_ior_file -ORBEndpoint iiop://:15000 -ORBSvcConf server.conf");

# Fire up the server
$sv = $SERVER->Spawn();

if ($sv != 0) {
   print STDERR "ERROR: server returned $sv\n";
   exit 1;
}

# We can wait on the IOR file 
if (PerlACE::waitforfile_timed ($server_ior_file, 10) == -1) 
{
   print STDERR "ERROR: cannot find $server_ior_file\n";
   $SERVER->Kill();
   exit 1;
}

$DUMMY_CLIENT->Spawn();

$DUMMY_CLIENT->Wait (2);

$CLIENT->Arguments("-k file://$server_ior_file");
if ($CLIENT->SpawnWaitKill (10) != 0)
{
   print STDERR "ERROR: Bug #2183 Regression failed. Non zero result from client.\n";
   $SERVER->Kill();
   $DUMMY_CLIENT->Kill();
   unlink $server_ior_file;
   exit 1;
}

print "Test succeeded !!!\n";

# Clean up and return
$SERVER->TerminateWaitKill (5);
$DUMMY_CLIENT->TerminateWaitKill (5);
unlink $server_ior_file;
exit 0;
