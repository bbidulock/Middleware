# This is a Perl script that runs the client and all the other servers that
# are needed

use Process;

$nsiorfile = "qns_ior";

# amount of delay between running the servers

$sleeptime = 1;

# variables for parameters

$nsport = 20002;
$clport = 20003;
$svport = 20004;
$ffport = 20005;
$gfport = 20006;

# other variables

$n = 1;
$leave = 0;
$ior = 0;
$done = "";
$debug = "";
$cm = "";
$sm = "";
$other = "";

sub read_nsior
{
	open (FH, "<".$nsiorfile);

	read (FH, $ior, 255);

	close (FH);
}

sub name_server
{
	my $args = sprintf ("%s -ORBport %d -ORBobjrefstyle url -o %s",
	                    $other,
	                    $nsport,
	                    $nsiorfile);

	$NS = Process::Create ("..".$DIR_SEPARATOR."..".$DIR_SEPARATOR."orbsvcs".$DIR_SEPARATOR.
	                       "Naming_Service".$DIR_SEPARATOR."Naming_Service".$Process::EXE_EXT, $args);

}

sub server
{
	my $args = sprintf ("%s %s %s -ORBport %d -ORBobjrefstyle url -ORBnameserviceior %s -ORBsvcconf server.conf",
	                   $other,
                           $debug,
                           $sm,
                           $svport,
                           $ior);

	$SV = Process::Create ("server".$Process::EXE_EXT, $args);
}

sub factory_finder
{
	my $args = sprintf ("%s -ORBport %d -ORBobjrefstyle url -ORBnameserviceior %s -ORBsvcconf svc.conf",
	                    $other,
	                    $ffport,
	                    $ior);
	
	$FF = Process::Create ("Factory_Finder".$Process::EXE_EXT, $args);
}

sub generic_factory
{
	my $args = sprintf ("%s -ORBport %d -ORBobjrefstyle url -ORBnameserviceior %s -ORBsvcconf svc.conf",
	                    $other,
	                    $gfport,
	                    $ior);


	print ("Generic_Factory".$Process::EXE_EXT);
	$GF = Process::Create ("Generic_Factory".$Process::EXE_EXT, $args);
}

sub client
{
	my $exe = sprintf ("client".$Process::EXE_EXT." %s %s %s -ORBobjrefstyle url -ORBport %d -ORBnameserviceior %s -ORBsvcconf client.conf",
	                   $other,
	                   $debug,
	                   $cm,
	                   $clport,
	                   $ior);

	for ($j = 0; $j < $n; $j++)
	{
		system ($exe);
	}
}

# Parse the arguments

for ($i = 0; $i <= $#ARGV; $i++)
{
	SWITCH: {
		if ($ARGV[i] eq "-h" || $ARGV[i] eq "-?")
		{
			print "run_test [-n num] [-leave] [-d] [-h] [-cm] [-sm] [-ns|sv|ff|cl|gf]\n";
			print "\n";
			print "-n num              -- runs the client num times\n";
			print "-leave              -- leaves the servers running and their windows open\n";
			print "-d	               -- runs each in debug mode\n";
			print "-h                  -- prints this information\n";
			print "-cm                 -- use more than one thread in the client\n";
			print "-sm                 -- use more than one thread in the server\n";
			print "-ns -sv -ff -cl -gf -- runs only one of the executables\n";
			exit;
		}
		if ($ARGV[i] eq "-n")
		{
			$n = $ARGV[i + 1];
			$i++;
			last SWITCH;
		}
		if ($ARGV[i] eq "-d")
		{
			$debug = $debug." -d";
			last SWITCH;
		}
		if ($ARGV[i] eq "-cm")
		{
			$cm = "-m";
			last SWITCH;
		}
		if ($ARGV[i] eq "-sm")
		{
			$sm = "-m";
			last SWITCH;
		}

		if ($ARGV[i] eq "-leave")
		{
			$leave = 1;
			last SWITCH;
		}
		if ($ARGV[i] eq "-ns")
		{
			name_server ();
			exit;
		}
		if ($ARGV[i] eq "-sv")
		{
			server ();
			exit;
		}
		if ($ARGV[i] eq "-ff")
		{
			factory_finder ();
			exit;
		}
		if ($ARGV[i] eq "-gf")
		{
			generic_factory ();
			exit;
		}
		if ($ARGV[i] eq "-cl")
		{
			client;
			exit;
		}
		$other = $other." ".$ARGV[i];
	}
}

name_server ();

read_nsior ();

sleep $sleeptime;

server ();

sleep $sleeptime;

factory_finder ();

sleep $sleeptime;

generic_factory ();

sleep $sleeptime;

client ();

if (leave == 0)
{
	$GF->Kill ();
	$FF->Kill ();
	$SV->Kill ();
	$NS->Kill ();
}