eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "../../../bin";

require ACEutils;
require Process;
use Cwd;

$cwd = getcwd();
for($i = 0; $i <= $#ARGV; $i++) {
  if ($ARGV[$i] eq '-chorus') {
    $i++;
    if (defined $ARGV[$i]) {
      $EXEPREFIX = "rsh $ARGV[$i] arun $cwd$DIR_SEPARATOR";
    }
    else {
      print STDERR "The -chorus option requires the hostname of the target\n";
      exit(1);
    }
  }
}

$status = 0;
$iorfile = "$cwd$DIR_SEPARATOR" . "chapter_test.ior";
unlink $iorfile;



# Hacked call
$server = Process::Create ("exec ".$EXEPREFIX."server".$EXE_EXT.">$iorfile",
                           "");
# Proper call
#$server = Process::Create ($EXEPREFIX."server".$EXE_EXT, ">$iorfile");

if (ACE::waitforfile_timed ($iorfile, 15) == -1) {
  print STDERR "ERROR: timedout waiting for file <$iorfile>\n";
  $server->Kill (); $server->TimedWait (1);
  exit 1;
}

open(ior_handle, "$iorfile");
$ior_content = <ior_handle>;

$client = Process::Create($EXEPREFIX."client$EXE_EXT", "$ior_content");

if ($client->TimedWait (60) == -1) {
  print STDERR "ERROR: client timedout\n";
  $status = 1;
  $client->Kill (); $client->TimedWait (1);
}




$server->Terminate (); 
if ($server->TimedWait (5) == -1) {
  print STDERR "ERROR: cannot terminate the server\n";
  $server->Kill (); $server->TimedWait (1);
  $status = 1;
}

unlink $iorfile;

exit $status;
