eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;
use Cwd;

my $debug_level = '0';
my $redirection_enabled = 0;

foreach $i (@ARGV) {
    if ($i eq '-debug') {
        $debug_level = '10';
        $redirection_enabled = 0;
    }
}

my $server  = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";
my $client  = PerlACE::TestTarget::create_target (2) || die "Create target 2 failed\n";


# Variables for command-line arguments to client and server
# executables.
my $hostname = $server->HostName ();

my $ns_orb_port1 = 10001 + $server->RandomPort ();
my $ns_orb_port2 = 10002 + $server->RandomPort ();

my $ns_endpoint1 = "iiop://$hostname:$ns_orb_port1";
my $ns_endpoint2 = "iiop://$hostname:$ns_orb_port2";

# References to primary naming service only
my $primary_default_init_ref = "-ORBDefaultInitRef corbaloc:iiop:$hostname:$ns_orb_port1";

# References to backup naming service only
my $backup_default_init_ref = "-ORBDefaultInitRef corbaloc:iiop:$hostname:$ns_orb_port2";

## Allow the user to determine where the persistent file will be located
## just in case the current directory is not suitable for locking.
## We can't change the name of the persistent file because that is not
## sufficient to work around locking problems for Tru64 when the current
## directory is NFS mounted from a system that does not properly support
## locking.
foreach my $possible ($ENV{TMPDIR}, $ENV{TEMP}, $ENV{TMP}) {
    if (defined $possible && -d $possible) {
      if (chdir($possible)) {
        last;
      }
    }
}

my $status = 0;
my $POSITIVE_TEST_RESULT = 0;
my $NEGATIVE_TEST_RESULT = 1;

my $NSGROUP = $client->CreateProcess ("$ENV{ACE_ROOT}/bin/tao_nsgroup");
my $NSLIST  = $client->CreateProcess ("$ENV{ACE_ROOT}/bin/tao_nslist");
my $NSADD   = $client->CreateProcess ("$ENV{ACE_ROOT}/bin/tao_nsadd");
my $NSDEL   = $client->CreateProcess ("$ENV{ACE_ROOT}/bin/tao_nsdel");

sub cat_file($)
{
    my $file_name = shift;
    if (-s $file_name ) # size of file is greater than zero
    {
        open TESTFILE, $file_name or die "Couldn't open file: $!";
        my @teststring = <TESTFILE>; # read in all of the file
        print STDERR "\n@teststring\n";
        close TESTFILE;
    }
}

sub redirect_output()
{
    open (OLDOUT, ">&", \*STDOUT) or die "Can't dup STDOUT: $!";
    open (OLDERR, ">&", \*STDERR) or die "Can't dup STDERR: $!";
    open STDERR, '>', $client_stderr_file;
    open STDOUT, '>', $client_stdout_file;
}

sub restore_output()
{
    open (STDERR, ">&OLDERR") or die "Can't dup OLDERR: $!";
    open (STDOUT, ">&OLDOUT") or die "Can't dup OLDOUT: $!";
}

sub run_nsgroup ($$)
{
    my $args = shift;
    my $expected_test_result = shift;

    my $arglist = "$args";

    $NSGROUP->Arguments ($arglist);

    if ($redirection_enabled) {
        redirect_output();
    }

    my $nsgroup_status = $NSGROUP->SpawnWaitKill ($client->ProcessStartWaitInterval());

    if ($redirection_enabled) {
        restore_output();
    }

    if ($nsgroup_status != $expected_test_result) {
        my $time = localtime;
        print STDERR "ERROR: nsgroup returned $nsgroup_status at $time\n";
        if ($redirection_enabled) {
            cat_file($client_stderr_file);
            cat_file($client_stdout_file);
        }
        $status = 1;
    }
}

sub run_nslist($$)
{
    my $args = shift;
    my $expected_test_result = shift;

    $NSLIST->Arguments ($args);

    if ($redirection_enabled) {
        redirect_output();
    }

    #tao_nslist --ns file://ns.ior
    my $nslist_status = $NSLIST->SpawnWaitKill ($client->ProcessStartWaitInterval());

    if ($redirection_enabled) {
        restore_output();
    }

    if ($nslist_status != $expected_test_result) {
        my $time = localtime;
        print STDERR "ERROR: nslist returned $nslist_status at $time\n";
        if ($redirection_enabled) {
            cat_file($client_stderr_file);
            cat_file($client_stdout_file);
        }
        $status = 1;
    }
}

sub run_nsadd($$)
{
    my $args = shift;
    my $expected_test_result = shift;

    $NSADD->Arguments ($args);

    if ($redirection_enabled) {
        redirect_output();
    }

    #tao_nsadd --ns file://ns.ior --name iso --ctx
    my $nsadd_status = $NSADD->SpawnWaitKill ($client->ProcessStartWaitInterval());

    if ($redirection_enabled) {
        restore_output();
    }

    if ($nsadd_status != $expected_test_result) {
        my $time = localtime;
        print STDERR "ERROR: nsadd returned $nsadd_status at $time\n";
        if ($redirection_enabled) {
            cat_file($client_stderr_file);
            cat_file($client_stdout_file);
        }
        $status = 1;
    }
}

sub run_nsdel($$)
{
    my $args = shift;
    my $expected_test_result = shift;

    $NSDEL->Arguments ($args);

    if ($redirection_enabled) {
        redirect_output();
    }

    #tao_nsdel --ns file://ns.ior --name iso --destroy
    my $nsdel_status = $NSDEL->SpawnWaitKill ($client->ProcessStartWaitInterval());

    if ($redirection_enabled) {
        restore_output();
    }

    if ($nsdel_status != $expected_test_result) {
        my $time = localtime;
        print STDERR "ERROR: nsdel returned $nsdel_status at $time\n";
        if ($redirection_enabled) {
            cat_file($client_stderr_file);
            cat_file($client_stdout_file);
        }
        $status = 1;
    }
}

sub clean_persistence_dir($$)
{
    my $target = shift;
    my $directory_name = shift;

    chdir $directory_name;
    opendir(THISDIR, ".");
    @allfiles = grep(!/^\.\.?$/, readdir(THISDIR));
    closedir(THISDIR);
    foreach $tmp (@allfiles){
        $target->DeleteFile ($tmp);
    }
    chdir "..";
}

# Make sure that the directory to use to hold the naming contexts exists
# and is cleaned out
sub init_naming_context_directory($$)
{
    my $target = shift;
    my $directory_name = shift;

    if ( ! -d $directory_name ) {
        mkdir ($directory_name, 0777);
    } else {
        clean_persistence_dir ($target, $directory_name);
    }
}

my $name_dir           = "NameService";
my $ns_primary_iorfile = "$name_dir/ns_replica_primary.ior";
my $ns_multi_iorfile   = "ns_multi.ior";
my $nm_multi_iorfile   = "nm_multi.ior";
my $stderr_file        = "test.err";
my $stdout_file        = "test.out";

################################################################################
# setup END block to cleanup after exit call
################################################################################
END
{
    $server->DeleteFile ($ns_primary_iorfile);
    $server->DeleteFile ($ns_multi_iorfile);
    $server->DeleteFile ($nm_multi_iorfile);
    $client->DeleteFile ($stdout_file);
    $client->DeleteFile ($stderr_file);
    clean_persistence_dir ($server, $name_dir);
    rmdir ($name_dir);
}

################################################################################
# Validate that a client can seamlessly invoke naming operations on either
# server instance.
################################################################################
sub redundant_equivalancy_test()
{
    my $previous_status = $status;
    $status = 0;

    print_msg("Redundant Equivalancy Test");

    init_naming_context_directory ($server, $name_dir);

    # The file that is written by the primary when ready to start backup
    my $server_primary_iorfile  = $server->LocalFile ($ns_primary_iorfile);
    my $server_ns_multi_iorfile = $server->LocalFile ($ns_multi_iorfile);
    my $server_nm_multi_iorfile       = $server->LocalFile ($nm_multi_iorfile);
    my $client_stdout_file      = $client->LocalFile ($stdout_file);
    my $client_stderr_file      = $client->LocalFile ($stderr_file);

    my $tao_ft_naming = "$ENV{TAO_ROOT}/orbsvcs/Naming_Service/tao_ft_naming";

    # Run two Naming Servers
    my $ns1_args = "--primary -ORBListenEndPoints $ns_endpoint1 -r $name_dir";
    my $ns2_args = "--backup -ORBListenEndPoints $ns_endpoint2 -c $server_ns_multi_iorfile -g $server_nm_multi_iorfile -r $name_dir";

    $NS1 = $server->CreateProcess ($tao_ft_naming, $ns1_args);
    $NS2 = $server->CreateProcess ($tao_ft_naming, $ns2_args);

    $server->DeleteFile ($ns_primary_iorfile);
    $NS1->Spawn ();
    if ($server->WaitForFileTimed ($ns_primary_iorfile,
                                   $server->ProcessStartWaitInterval()) == -1) {
        print STDERR "ERROR: cannot find file <$server_primary_iorfile>\n";
        $NS1->Kill (); $NS1->TimedWait (1);
        exit 1;
    }

    $server->DeleteFile ($ns_multi_iorfile);
    $NS2->Spawn ();
    if ($server->WaitForFileTimed ($ns_multi_iorfile,
                                   $server->ProcessStartWaitInterval()) == -1) {
        print STDERR "ERROR: cannot find file <$server_ns_multi_iorfile>\n";
        $NS2->Kill (); $NS2->TimedWait (1);
        $NS1->Kill (); $NS1->TimedWait (1);
        exit 1;
    }

    run_nsadd ("$primary_default_init_ref --name iso --ctx", $POSITIVE_TEST_RESULT);
    run_nsgroup ("$backup_default_init_ref group_create -group ieee -policy round -type_id IDL:FT_Naming/NamingManager:1.0", $POSITIVE_TEST_RESULT);
    run_nsgroup ("$primary_default_init_ref group_bind -group ieee -name iso/ieee", $POSITIVE_TEST_RESULT);
    run_nsgroup ("$backup_default_init_ref group_list", $POSITIVE_TEST_RESULT);
    run_nslist ("$backup_default_init_ref", $POSITIVE_TEST_RESULT);

    $server_status = $NS2->TerminateWaitKill ($server->ProcessStopWaitInterval());
    if ($server_status != 0) {
        print STDERR "ERROR: server 2 returned $server_status\n";
        $status = 1;
    }

    $server_status = $NS1->TerminateWaitKill ($server->ProcessStopWaitInterval());
    if ($server_status != 0) {
        print STDERR "ERROR: server 1 returned $server_status\n";
        $status = 1;
    }

    if ( $status == 0 ) {
        $status = $previous_status;
    }

    return $status;
}

sub print_msg($)
{
    my $msg = shift;
    my $bar = "===============================================================================";
    print STDERR "\n\n$bar\n$msg\n$bar\n";
}

sub show_result($$)
{
    my $test_result = shift;
    my $test_name = shift;

    if ( 0 == $test_result ) {
        print_msg("$test_name: SUCCESS");
    } else {
        print_msg("$test_name: ERROR");
    }
}

my $result = redundant_equivalancy_test ();
show_result($result, "Redundant Equivalancy Test");

exit $result;
