package Preprocessor;

# ************************************************************
# Description   : Preprocesses the supplied file.
# Author        : Chad Elliott
# Create Date   : 2/10/2002
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;
use FileHandle;
use File::Basename;

# ************************************************************
# Subroutine Section
# ************************************************************

sub new {
  my($class)   = shift;
  my($macros)  = shift;
  my($ipaths)  = shift;
  my($exclude) = shift;
  return bless {'macros'  => $macros,
                'ipaths'  => $ipaths,
                'exclude' => $exclude,
                'files'   => {},
                'ifound'  => {},
                'recurse' => 0,
               }, $class;
}


sub process {
  my($self)     = shift;
  my($file)     = shift;
  my($noinline) = shift;
  my($noincs)   = shift;
  my($fh)       = new FileHandle();

  if (open($fh, $file)) {
    my($ifcount) = 0;
    my(@zero)    = ();
    my($files)   = $self->{'files'};
    my($recurse) = ++$self->{'recurse'};
    my($dir)     = dirname($file);

    $$files{$file} = [];
    while(<$fh>) {
      ## As an optimization, use a very simple regular expression on the
      ## outside that all of the inner regular expressions have in
      ## common.  That way we go down the path of if elsif only if it is
      ## even possible due to the outside regular expression.
      if (/#/) {
        ## Remove c++ and same line c comments inside this if statement.
        ## This saves about 5% off of processing the ace directory
        ## and we only need to strip comments if we are actually
        ## going to look at the string.
        $_ =~ s/\/\/.*//o;
        $_ =~ s/\/\*.*\*\///o;

        if (/#\s*endif/) {
          --$ifcount;
          if (defined $zero[0] && $ifcount == $zero[$#zero]) {
            pop(@zero);
          }
        }
        elsif (/#\s*if\s+0/) {
          push(@zero, $ifcount);
          ++$ifcount;
        }
        elsif (/#\s*if/) {
          ++$ifcount;
        }
        elsif (!defined $zero[0] &&
               /#\s*include\s+[<"]([^">]+)[">]/o) {
          ## Locate the include file
          my($inc) = undef;
          if (exists $self->{'ifound'}->{$1}) {
            $inc = $self->{'ifound'}->{$1};
          }
          else {
            foreach my $dirp (@{$self->{'ipaths'}}) {
              if (-r "$dirp/$1") {
                $inc = "$dirp/$1";
                last;
              }
            }

            if (!defined $inc) {
              ## If the file we're currently looking at contains a
              ## directory name then, we need to look for include
              ## files in that directory.
              if (-r "$dir/$1") {
                $inc = "$dir/$1";
              }
            }
            $self->{'ifound'}->{$1} = $inc;
          }

          ## If we've found the include file, then process it too.
          if (defined $inc) {
            $inc =~ s/\\/\//go;
            if (!$noinline ||
                ($recurse == 1 || $inc !~ /\.i(nl)?$/o)) {
              push(@{$$files{$file}}, $inc);
              if (!defined $$files{$inc}) {
                ## Process this file, but do not return the include files
                if (!defined $self->{'exclude'}->{basename($inc)}) {
                  $self->process($inc, $noinline, 1);
                }
              }
            }
          }
        }
      }
    }
    close($fh);

    --$self->{'recurse'};
  }

  ## This has to be outside the if (open(...
  ## If the last file to be processed isn't accessable then
  ## we still need to return the array reference of includes.
  if (!$noincs) {
    my(@files)  = ($file);
    my(%ifiles) = ();

    for(my $i = 0; $i <= $#files; ++$i) {
      foreach my $inc (@{$self->{'files'}->{$files[$i]}}) {
        if (!defined $ifiles{$inc}) {
          $ifiles{$inc} = 1;
          push(@files, $inc);
        }
      }
    }
    shift(@files);
    return \@files;
  }
}


1;
