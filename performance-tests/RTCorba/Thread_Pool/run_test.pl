eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

require Process;
use lib '../../../../bin';
use PerlACE::Run_Test;

$status = 0;
$experiment_timeout = 300;
$iorfile_timeout = 10;

$min_rate = 100; 
$max_rate = 100;
#$max_rate = 250;
$rate_increment = 25;

$min_work = 10; 
$max_work = 15;
#$max_work = 50;
$work_increment = 5;

$min_thread = 0; 
$max_thread = 2;
#$max_thread = 10;
$thread_increment = 1;

#@workers = (1, 2, 3, 5, 10, 15, 20);
@workers = (1, 2);

$results_directory = "results";

@test_types = 
    (
     "rates", 
     "workers",
     "workers-2",
     "work-nolanes",
     "work-lanes-increase",
     "work-lanes-decrease",
     "thread-nolanes",
     "thread-lanes-increase",
     "thread-lanes-decrease",
     );

$iorfile = "ior";
$work = 10;
$time_for_test = 1;
$max_throughput_timeout = 1;

# Parse the arguments
for ($i = 0; $i <= $#ARGV; $i++) {
    if ($ARGV[$i] eq "-h" || $ARGV[$i] eq "-?") 
    {
        print STDERR "\nusage:  run_test\n";

        print STDERR "\t-h shows options menu\n";

        print STDERR "\t-a test types (";
        for $test_type (@test_types)
        {
            print STDERR "$test_type, ";
        }
        print STDERR ")\n";

        print STDERR "\n";

        $CL = new PerlACE::Process ("client", "-h");
        $CL->Spawn ();
        $CL->WaitKill (5);
        
        $SV = new PerlACE::Process ("server", "-h");
        $SV->Spawn ();
        $SV->WaitKill (5);

        exit;
    }
    elsif ($ARGV[$i] eq "-a") {
      @test_types = split (',', $ARGV[$i + 1]);
      $i++;
    }
    elsif ($ARGV[$i] eq "-o") 
    {
        $extra_args .= " " . $ARGV[$i];
        $i++;
        $iorfile = $ARGV[$i];
        $extra_args .= " " . $ARGV[$i];
    }
    elsif ($ARGV[$i] eq "-w") 
    {
        $i++;
        $work = $ARGV[$i];
    }
    elsif ($ARGV[$i] eq "-t") 
    {
        $i++;
        $time_for_test = $ARGV[$i];
    }
    elsif ($ARGV[$i] eq "-z") 
    {
        $i++;
        $max_throughput_timeout = $ARGV[$i];
    }
    else
    {
        $extra_args .= " " . $ARGV[$i];
    }
}

$fixed_client_args = "-w $work -t $time_for_test -z $max_throughput_timeout";

@configurations = 
    (
     {
         description => "rates",
         server => "-n 1", 
     },
     {
         description => "workers",
         server => "-n 1", 
     },
     {
         description => "workers-2",
         server => "-n 1 -s 2", 
     },
     {
         description => "work-nolanes",
         server => "-l one-zero-lane -b one-full-band", 
     },
     {
         description => "work-lanes-increase",
         server => "-n 3", 
     },
     {
         description => "work-lanes-decrease",
         server => "-n 3", 
     },
     {
         description => "thread-nolanes",
         server => "-l one-zero-lane -b one-full-band", 
     },
     {
         description => "thread-lanes-increase",
         server => "-l three-lanes-with-best-effort -b three-bands-with-best-effort", 
     },
     {
         description => "thread-lanes-decrease",
         server => "-l three-lanes-with-best-effort -b three-bands-with-best-effort", 
     },
     );

for $test (@configurations)
{
    #
    # setup rates test
    #
    if ($test->{description} eq "rates")
    {
        for ($rate = $min_rate, $i = 0; 
             $rate <= $max_rate; 
             $rate += $rate_increment, $i += 1)
        {
            $test->{clients}[$i] = "-r $rate $fixed_client_args";
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }

    #
    # setup workers test
    #
    elsif ($test->{description} eq "workers" or
           $test->{description} eq "workers-2")
    {
        $i = 0;
        for $worker (@workers)
        {
            $test->{clients}[$i] = "-c $worker -r empty-file $fixed_client_args";
            $i++;
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }

    #
    # setup work-nolanes test
    #
    elsif ($test->{description} eq "work-nolanes")
    {
        for ($work = $min_work, $i = 0; 
             $work <= $max_work; 
             $work += $work_increment, $i += 1)
        {
            $test->{clients}[$i] = "-w $work -r increasing-rates -u 1000 -t $time_for_test -z $max_throughput_timeout";
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }

    #
    # setup work-lanes-increase test
    #
    elsif ($test->{description} eq "work-lanes-increase")
    {
        for ($work = $min_work, $i = 0; 
             $work <= $max_work; 
             $work += $work_increment, $i += 1)
        {
            $test->{clients}[$i] = "-w $work -r increasing-rates -t $time_for_test -z $max_throughput_timeout";
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }

    #
    # setup work-lanes-decrease test
    #
    elsif ($test->{description} eq "work-lanes-decrease")
    {
        for ($work = $min_work, $i = 0; 
             $work <= $max_work; 
             $work += $work_increment, $i += 1)
        {
            $test->{clients}[$i] = "-w $work -r decreasing-rates -t $time_for_test -z $max_throughput_timeout";
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }

    #
    # setup thread-nolanes test
    #
    elsif ($test->{description} eq "thread-nolanes")
    {
        for ($thread = $min_thread, $i = 0; 
             $thread <= $max_thread; 
             $thread += $thread_increment, $i += 1)
        {
            $test->{clients}[$i] = "-c $thread -r increasing-rates -u 1000 $fixed_client_args";
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }

    #
    # setup thread-lanes-increase test
    #
    elsif ($test->{description} eq "thread-lanes-increase")
    {
        for ($thread = $min_thread, $i = 0; 
             $thread <= $max_thread; 
             $thread += $thread_increment, $i += 1)
        {
            $test->{clients}[$i] = "-c $thread -r increasing-rates $fixed_client_args";
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }

    #
    # setup thread-lanes-decrease test
    #
    elsif ($test->{description} eq "thread-lanes-decrease")
    {
        for ($thread = $min_thread, $i = 0; 
             $thread <= $max_thread; 
             $thread += $thread_increment, $i += 1)
        {
            $test->{clients}[$i] = "-c $thread -r decreasing-rates $fixed_client_args";
        }

        $test->{clients}[$i - 1] .= " -x 1";
    }
}

sub run_client
{
    print STDOUT "\n______________________________________________________\n";

    print STDOUT "\nclient @_\n";

    print STDOUT "______________________________________________________\n";

    $CL = new PerlACE::Process ("client", @_);

    $CL->Spawn ();
    
    $client = $CL->WaitKill ($experiment_timeout);

    if ($client != 0) 
    {
        print STDERR "ERROR: client returned $client\n";
        $status = 1;
        zap_server (1);
    }
}

sub run_server 
{
    print STDOUT "\n______________________________________________________\n";

    print STDOUT "\nserver @_\n";

    print STDOUT "______________________________________________________\n";

    $SV = new PerlACE::Process ("server", @_);

    $SV->Spawn ();

    if (PerlACE::waitforfile_timed ($iorfile, $iorfile_timeout) == -1)
    {
        print STDERR "ERROR: cannot find ior file: $iorfile\n";
        $status = 1;
        zap_server (1);
    }
}

sub zap_server
{
    $server = $SV->WaitKill (5);
    
    if ($server != 0) 
    {
        print STDERR "ERROR: server returned $server\n";
        $status = 1;
    }

    unlink $iorfile;
    
    if ($_[0] || $status)
    {
        exit $status;
    }
}

unlink $iorfile;

mkdir $results_directory;

print STDOUT "\n______________________________________________________\n";

for $test (@configurations)
{
    $run_configuration = 0;
    for $test_type (@test_types)
    {
        if ($test_type eq $test->{description})
        {
            $run_configuration = 1;
        }
    }
    
    if ($run_configuration == 0)
    {
        next;
    }

    $output_file = $results_directory . $DIR_SEPARATOR . $test->{description};

    print STDOUT "\nResults of $test->{description} test being redirected to $output_file\n";

    print STDOUT "______________________________________________________\n";

    open (OLDOUT, ">&STDOUT");
    open (STDOUT, ">$output_file") 
        or die "can't redirect stdout: $!";
    open (OLDERR, ">&STDERR");
    open (STDERR, ">&STDOUT") 
        or die "can't redirect stderror: $!";

    run_server ($test->{server} . $extra_args);

    my $clients = $test->{clients};
    for $args (@$clients)
    {
        run_client ($args . $extra_args);
    }

    zap_server (0);

    close (STDERR);
    close (STDOUT);
    open (STDOUT, ">&OLDOUT");
    open (STDERR, ">&OLDERR");
}

exit $status;
