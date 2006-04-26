package GNUACEWorkspaceCreator;

# ************************************************************
# Description   : A GNU Workspace (GNUmakefile) creator for ACE
# Author        : Chad Elliott
# Create Date   : 5/13/2002
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;
use File::Basename;

use GNUACEProjectCreator;
use WorkspaceCreator;

use vars qw(@ISA);
@ISA = qw(WorkspaceCreator);

# ************************************************************
# Data Section
# ************************************************************

my($base) = 'GNUmakefile';

# ************************************************************
# Subroutine Section
# ************************************************************

sub generate_implicit_project_dependencies {
  #my($self) = shift;
  return 1;
}


sub workspace_file_name {
  my($self) = shift;
  return $self->get_modified_workspace_name($base, '');
}


sub workspace_per_project {
  #my($self) = shift;
  return 1;
}


sub pre_workspace {
  my($self) = shift;
  my($fh)   = shift;
  my($crlf) = $self->crlf();

  print $fh '# -*- makefile -*-', $crlf,
            '#-------------------------------------------------------------------------', $crlf,
            '#       GNU ACE Workspace', $crlf,
            '#', $crlf,
            '# $Id$', $crlf,
            '#', $crlf,
            '# This file was generated by MPC.  Any changes made directly to', $crlf,
            '# this file will be lost the next time it is generated.', $crlf,
            '#', $crlf,
            '# MPC Command:', $crlf,
            "# $0 @ARGV", $crlf,
            '#', $crlf,
            '#-------------------------------------------------------------------------', $crlf,
            'MAKEFILE = ', $self->get_modified_workspace_name($base, '', 1),
            $crlf;
}


sub write_comps {
  my($self)    = shift;
  my($fh)      = shift;
  my($crlf)    = $self->crlf();
  my(%targnum) = ();
  my($pjs)     = $self->get_project_info();
  my($named)   = !defined $ENV{MPC_GNUACE_DIRECTORY_DEPS};
  my(@list)    = $self->number_target_deps($self->get_projects(),
                                           $pjs, \%targnum,
                                           $named ? 0 : 1);

  ## Print out some preliminary information
  print $fh $crlf,
            "ifeq (\$(findstring k,\$(MAKEFLAGS)),k)$crlf",
            "  KEEP_GOING = -$crlf",
            "endif$crlf$crlf",
            "include \$(ACE_ROOT)/include/makeinclude/macros.GNU$crlf",
            $crlf;

  if ($named) {
    $self->write_named_targets($fh, $crlf, \%targnum, \@list);
  }
  else {
    ## Determine the ordering of the sub-directories
    my(@dirs)  = ();
    my(%found) = ();
    foreach my $file (reverse @list) {
      my($dir) = $self->get_first_level_directory($file);
      if ($dir ne '.') {
        if (!defined $found{$dir}) {
          $found{$dir} = 1;
          unshift(@dirs, $dir);
        }
      }
    }
    my($need_dirs) = ($#dirs > -1);

    ## Store the local projects in a separate list
    my(@lprj)   = ();
    my(%dirprj) = ();
    foreach my $project (@list) {
      if ($project !~ /\//) {
        push(@lprj, $project);
        if ($need_dirs && defined $targnum{$project}) {
          foreach my $number (@{$targnum{$project}}) {
            if ($list[$number] =~ /\//) {
              ## If any local project depends on a project that is not
              ## in this directory, we can not rely on the directory
              ## recursion to get the correct dependencies.  We will do
              ## all projects as local targets.
              @lprj = ();
              foreach my $prj (@list) {
                push(@lprj, $prj);
                if ($prj =~ /\//) {
                  $dirprj{$prj} = 1;
                }
              }
              $need_dirs = 0;
              last;
            }
          }
          if (!$need_dirs) {
            last;
          }
        }
      }
    }

    if ($#lprj >= 0) {
      ## Print out the all target first.  This will allow multiple projects
      ## within the same directory to build in parallel.
      print $fh 'all:';
      foreach my $project (@lprj) {
        print $fh ' ', $$pjs{$project}->[0];
      }
      print $fh $crlf;
      if ($need_dirs) {
        foreach my $dir (@dirs) {
          print $fh "\t\$(KEEP_GOING)\@cd $dir && ",
                    "\$(MAKE) -f \$(MAKEFILE) \$(\@)$crlf";
        }
      }

      ## Print out each target separately.  Make can decide on which
      ## targets can be built in parallel because we add the local
      ## dependencies.
      foreach my $project (@lprj) {
        print $fh $crlf, '.PHONY: ', $$pjs{$project}->[0],
                  $crlf, $$pjs{$project}->[0], ':';
        if (defined $targnum{$project}) {
          foreach my $number (@{$targnum{$project}}) {
            print $fh ' ', $$pjs{$list[$number]}->[0];
          }
        }
        print $fh $crlf,
                  "\t\$(KEEP_GOING)\@";
        if (defined $dirprj{$project}) {
          print $fh "cd ", $self->mpc_dirname($project),
                    " && \$(MAKE) -f ", basename($project), $crlf;
        }
        else {
          print $fh "\$(MAKE) -f $project$crlf";
        }
      }
      print $fh $crlf,
                'REMAINING_TARGETS := ',
                '$(subst all, , $(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)',
                $crlf;
    }
    else {
      print $fh 'REMAINING_TARGETS := $(TARGETS_NESTED:.nested=) ',
                '$(CUSTOM_TARGETS)', $crlf;
    }

    ## Print out the remaing targets.
    ## They will be handled serially by make.
    print $fh "\$(REMAINING_TARGETS):$crlf";
    foreach my $project (@lprj) {
      print $fh "\t\$(KEEP_GOING)\@";
      if (defined $dirprj{$project}) {
        print $fh "cd ", $self->mpc_dirname($project),
                  " && \$(MAKE) -f ", basename($project), " \$(\@)", $crlf;
      }
      else {
        print $fh "\$(MAKE) -f $project \$(\@)$crlf";
      }
    }
    if ($need_dirs) {
      foreach my $dir (@dirs) {
        print $fh "\t\$(KEEP_GOING)\@cd $dir && ",
                  "\$(MAKE) -f \$(MAKEFILE) \$(\@)$crlf";
      }
    }
    print $fh $crlf;
  }
}

sub write_named_targets {
  my($self)    = shift;
  my($fh)      = shift;
  my($crlf)    = shift;
  my($targnum) = shift;
  my($list)    = shift;
  my($trans)   = $self->project_target_translation(1);

  ## Print out the "all" target
  print $fh 'all:';
  foreach my $project (@$list) {
    print $fh " $$trans{$project}";
  }

  ## Print out all other targets here
  print $fh $crlf,
            'REMAINING_TARGETS := ',
            '$(subst all, , $(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)',
            "$crlf$crlf\$(REMAINING_TARGETS):$crlf";
  foreach my $project (@$list) {
    my($dname) = $self->mpc_dirname($project);
    print $fh "\t\@",
              ($dname ne '.' ? "cd $dname && " : ''),
              "\$(MAKE) -f ",
              ($dname eq '.' ? $project : basename($project)),
              " \$(\@)$crlf";
  }

  ## Print out each target separately
  foreach my $project (@$list) {
    my($dname) = $self->mpc_dirname($project);
    print $fh $crlf, '.PHONY: ', $$trans{$project},
              $crlf, $$trans{$project}, ':';
    if (defined $$targnum{$project}) {
      foreach my $number (@{$$targnum{$project}}) {
        print $fh " $$trans{$$list[$number]}";
      }
    }

    print $fh $crlf,
              "\t\@",
              ($dname ne '.' ? "cd $dname && " : ''),
              "\$(MAKE) -f ",
              ($dname eq '.' ? $project : basename($project)),
              ' all', $crlf;
  }

  ## Print out the project_name_list target
  print $fh $crlf, "project_name_list:$crlf";
  foreach my $project (sort @$list) {
    print $fh "\t\@echo $$trans{$project}$crlf";
  }
}

1;
