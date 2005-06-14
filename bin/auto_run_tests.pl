eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-
# This file is for running the run_test.pl scripts listed in
# auto_run_tests.lst.

use lib "$ENV{ACE_ROOT}/bin";
if (defined $ENV{srcdir}) {
  use lib "$ENV{srcdir}/bin";
}
use PerlACE::Run_Test;

use English;
use Getopt::Std;
use Cwd;

use Env qw(ACE_ROOT PATH);

################################################################################

if (!getopts ('ados:tC') || $opt_h) {
    print "auto_run_tests.pl [-a] [-h] [-s sandbox] [-o] [-t]\n";
    print "\n";
    print "Runs the tests listed in auto_run_tests.lst\n";
    print "\n";
    print "Options:\n";
    print "    -a          ACE tests only\n";
    print "    -c config   Run the tests for the <config> configuration\n";
    print "    -h          display this help\n";
    print "    -s sandbox  Runs each program using a sandbox program\n";
    print "    -o          ORB test only\n";
    print "    -t          TAO tests (other than ORB tests) only\n";
    print "    -C          CIAO tests only\n";
    print "    -Config cfg Run the tests for the <cfg> configuration\n";
    print "\n";
    $ace_config_list = new PerlACE::ConfigList;
    $ace_config_list->load ($ACE_ROOT."/bin/ace_tests.lst");
    print "ACE Test Configs: " . $ace_config_list->list_configs () . "\n";
    $orb_config_list = new PerlACE::ConfigList;
    $orb_config_list->load ($ACE_ROOT."/bin/tao_orb_tests.lst");
    print "ORB Test Configs: " . $orb_config_list->list_configs () . "\n";
    $tao_config_list = new PerlACE::ConfigList;
    $tao_config_list->load ($ACE_ROOT."/bin/tao_other_tests.lst");
    print "TAO Test Configs: " . $tao_config_list->list_configs () . "\n";
    $ciao_config_list = new PerlACE::ConfigList;
    $ciao_config_list->load ($ACE_ROOT."/bin/ciao_tests.lst");
    print "CIAO Test Configs: " . $ciao_config_list->list_configs () . "\n";
    exit (1);
}

my @file_list;

if ($opt_a) {
push (@file_list, "/bin/ace_tests.lst");
}

if ($opt_o) {
push (@file_list, "/bin/tao_orb_tests.lst");
}

if ($opt_t) {
push (@file_list, "/bin/tao_other_tests.lst");
}

if ($opt_C) {
push (@file_list, "/bin/ciao_tests.lst");
}

if (scalar(@file_list) == 0) {
push (@file_list, "/bin/ace_tests.lst");
push (@file_list, "/bin/tao_orb_tests.lst") if -d "$ACE_ROOT/TAO";
push (@file_list, "/bin/tao_other_tests.lst") if -d "$ACE_ROOT/TAO";
push (@file_list, "/bin/ciao_tests.lst") if -d "$ACE_ROOT/TAO/CIAO";
}

foreach my $test_lst (@file_list) {

    my $config_list = new PerlACE::ConfigList;
    $config_list->load ($ACE_ROOT.$test_lst);

    # Insures that we search for stuff in the current directory.
    $PATH .= $Config::Config{path_sep} . '.';

    foreach $test ($config_list->valid_entries ()) {
        my $directory = ".";
        my $program = ".";

        if ($test =~ /(.*)\/([^\/]*)$/) {
            $directory = $1;
            $program = $2;
        }
        else {
            $program = $test;
        }

        # this is to ensure that we dont print out the time for tests/run_test.pl
        # that test prints out the times for each of the ace tests individually
        my $is_ace_test = ($directory eq "tests");

        if (! $is_ace_test) {
            print "auto_run_tests: $test\n";
        }

        chdir ($ACE_ROOT."/$directory")
            || die "Error: Cannot chdir to $ACE_ROOT/$directory";

        if ($program =~ /(.*?) (.*)/) {
            if (! -e $1) {
                print STDERR "Error: $directory.$1 does not exist\n";
                next;
              }
          }
        else {
            if (! -e $program) {
                print STDERR "Error: $directory.$program does not exist\n";
                next;
              }
          }

        ### Generate the -ExeSubDir and -Config options
        my $inherited_options = " -ExeSubDir $PerlACE::Process::ExeSubDir ";

        foreach my $config ($config_list->my_config_list ()) {
             $inherited_options .= " -Config $config ";
        }

        $cmd = '';
        if ($opt_s) {
            $cmd = "$opt_s \"perl $program $inherited_options\"";
        }
        else {
            $cmd = $program.$inherited_options;
        }


        my $result = 0;

        if (defined $opt_d) {
            print "Running: $cmd\n";
        }
        else {
            $start_time = time();
            $result = system ($cmd);
            $time = time() - $start_time;

            # see note about tests/run_test.pl printing reports for ace tests individually
            if (! $is_ace_test) {    
                if ($result > 0) {
                    print "Error: $test returned with status $result\n";
                }

                print "\nauto_run_tests_finished: $test Time:$time"."s Result:$result\n";
            }
        }
    }
}
