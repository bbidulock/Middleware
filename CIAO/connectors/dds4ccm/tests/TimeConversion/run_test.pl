eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

my $program = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";

$PROG = $program->CreateProcess ("TimeConversion", "");
$program_status = $PROG->Spawn ();

if ($program_status != 0) {
    print STDERR "ERROR: TimeConversion returned $program_status\n";
    exit 1;
}

sleep (2);

$program_status = $PROG->Kill ();

exit 0;
