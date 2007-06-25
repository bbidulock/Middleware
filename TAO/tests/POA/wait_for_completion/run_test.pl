eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

if (PerlACE::is_vxworks_test()) {
    $T = new PerlACE::ProcessVX ("wait_for_completion");
}
else {
    $T = new PerlACE::Process ("wait_for_completion");
}

$test = $T->SpawnWaitKill ($PerlACE::wait_interval_for_process_creation);

if ($test != 0) {
    print STDERR "ERROR: test returned $test\n";
    exit 1;
}

exit 0;
