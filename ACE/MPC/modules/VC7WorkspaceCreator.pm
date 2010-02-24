package VC7WorkspaceCreator;

# ************************************************************
# Description   : A VC7 Workspace Creator
# Author        : Chad Elliott
# Create Date   : 5/14/2002
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;

use VC7ProjectCreator;
use WinWorkspaceBase;
use WorkspaceCreator;

use vars qw(@ISA);
@ISA = qw(WinWorkspaceBase WorkspaceCreator);

# ************************************************************
# Data Section
# ************************************************************

my %guids = (Creator::cplusplus => '8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942',
             Creator::csharp    => 'FAE04EC0-301F-11D3-BF4B-00C04F79EFBC',
             Creator::java      => 'E6FDF86B-F3D1-11D4-8576-0002A516ECE8',
             Creator::vb        => 'F184B08F-C81C-45F6-A57F-5ABD9991F28F',
             Creator::website   => 'E24C65DC-7377-472B-9ABA-BC803B73C61A',
            );

# ************************************************************
# Subroutine Section
# ************************************************************

sub compare_output {
  #my $self = shift;
  return 1;
}


sub workspace_file_extension {
  #my $self = shift;
  return '.sln';
}


sub pre_workspace {
  my($self, $fh) = @_;
  my $crlf = $self->crlf();

  ## This identifies it as a Visual Studio file
  print $fh 'Microsoft Visual Studio Solution File, Format Version 7.00', $crlf;

  ## Optionally print the workspace comment
  $self->print_workspace_comment($fh,
            '#', $crlf,
            '# $Id$', $crlf,
            '#', $crlf,
            '# This file was generated by MPC.  Any changes made directly to', $crlf,
            '# this file will be lost the next time it is generated.', $crlf,
            '#', $crlf,
            '# MPC Command:', $crlf,
            '# ', $self->create_command_line_string($0, @ARGV), $crlf);
}


sub print_inner_project {
  #my $self             = shift;
  #my $fh               = shift;
  #my $gen              = shift;
  #my $pguid            = shift;
  #my $deps             = shift;
  #my $name             = shift;
  #my $name_to_guid_map = shift;
  #my $proj_language    = shift;
  #my $cfgs             = shift;

}


sub print_configs {
  my($self, $fh, $configs) = @_;
  my $crlf = $self->crlf();
  my $count = 0;

  ## Print out the configurations for the solution
  foreach my $key (sort keys %$configs) {
    print $fh "\t\tConfigName.$count = $key$crlf";
    $count++;
  }
}


sub print_dependencies {
  my($self, $fh, $gen, $list, $pjs) = @_;
  my $crlf = $self->crlf();

  ## I hate to add yet another loop through all the projects, but
  ## we must have some way to map plain project names to guids.
  my %name_to_guid_map;
  foreach my $project (@$list) {
    my($name, $deps, $guid) = @{$$pjs{$project}};
    $name_to_guid_map{$name} = $guid;
  }

  ## Project Dependencies
  print $fh "\tGlobalSection(ProjectDependencies) = postSolution$crlf";
  foreach my $project (@$list) {
    my($name, $rawdeps, $project_guid) = @{$$pjs{$project}};
    my $deps = $self->get_validated_ordering($project);
    if (defined $$deps[0]) {
      my $i = 0;
      foreach my $dep (@$deps) {
        my $guid = $name_to_guid_map{$dep};
        if (defined $guid) {
          print $fh "\t\t{$project_guid}.$i = {$guid}$crlf";
          $i++;
        }
      }
    }
  }
  print $fh "\tEndGlobalSection$crlf";
}


sub write_comps {
  my($self, $fh, $gen) = @_;
  my $projects = $self->get_projects();
  my $pjs  = $self->get_project_info();
  my @list = sort @$projects;
  my $crlf = $self->crlf();

  ## I hate to add yet another loop through all the projects, but
  ## we must have some way to map plain project names to guids.
  my %name_to_guid_map;
  foreach my $project (@list) {
    my($name, $deps, $guid) = @{$$pjs{$project}};
    $name_to_guid_map{$name} = $guid;
  }

  ## Project Information
  foreach my $project (@list) {
    my($pname, $rawdeps, $guid, $language, $custom_only, $nocross, $managed, @cfgs) = @{$$pjs{$project}};
    my $pguid = $guids{$language};
    my $deps = $self->get_validated_ordering($project);
    my($name, $proj) = $self->adjust_names($pname, $project, $language);
    print $fh "Project(\"{$pguid}\") = \"$name\", \"$proj\", \"{$guid}\"$crlf";
    $self->print_inner_project($fh, $gen, $guid, $deps,
                               $name, \%name_to_guid_map,
                               $language, \@cfgs);
    print $fh "EndProject$crlf";
  }

  ## This block creates the different possible configurations for this
  ## solution.
  print $fh "Global$crlf",
            "\tGlobalSection(",
            $self->get_solution_config_section_name(),
            ") = preSolution$crlf";
  my %configs;
  foreach my $project (@list) {
    my($name, $deps, $pguid, $lang, $custom_only, $nocross, $managed, @cfgs) = @{$$pjs{$project}};
    foreach my $cfg (@cfgs) {
      $configs{$self->get_short_config_name($cfg)} = $cfg;
    }
  }
  $self->print_configs($fh, \%configs);
  print $fh "\tEndGlobalSection$crlf";

  ## Print dependencies if there are any
  $self->print_dependencies($fh, $gen, \@list, $pjs);

  ## Project Configuration Names
  print $fh "\tGlobalSection(",
            $self->get_project_config_section_name(),
            ") = postSolution$crlf";

  ## See if there is an 'Any CPU' or '.NET' configuration
  my $anycpu;
  foreach my $key (keys %configs) {
    if (index($key, 'Any CPU') >= 0 || index($key, '.NET') >= 0) {
      $anycpu = 1;
      last;
    }
  }

  ## Go through each project and print out the settings per GUID
  foreach my $project (@list) {
    my($name, $deps, $pguid, $lang, $custom_only, $nocross, $managed, @cfgs) = @{$$pjs{$project}};
    my %all_configs = %configs;
    foreach my $cfg (sort @cfgs) {
      my $c = $self->get_short_config_name($cfg);
      my $deployable = !$nocross;
      my $buildable = $deployable;
      if (index($cfg, 'Win32') >= 0 || index($cfg, 'x64') >= 0) {
        $deployable = 0;
        $buildable = 1;
      } elsif ($custom_only) {
        $deployable = 0;
      }
      if (defined $anycpu) {
        ## There is a non-C++ project; there is no need to explicitly
        ## enable building of the configurations for this project.  So, we
        ## get rid of the configuration settings from the copy of the
        ## configs map.
        delete $all_configs{$c};
      }
      else {
        print $fh "\t\t{$pguid}.$c.ActiveCfg = $cfg$crlf";
        print $fh "\t\t{$pguid}.$c.Build.0 = $cfg$crlf"  if ($buildable == 1);
        print $fh "\t\t{$pguid}.$c.Deploy.0 = $cfg$crlf" if ($deployable == 1);
      }
    }

    ## If this is a mixed language workspace, we need to explicitly
    ## enable the building of the non-C++ projects when any platform
    ## other than Any CPU/.NET is selected.
    if (defined $anycpu) {
      my %printed;
      foreach my $c (sort @cfgs) {
        if ($c =~ /(.+\|)/) {
          my $cfg = $1;
          foreach my $remainder (sort keys %all_configs) {
            if (index($remainder, $cfg) == 0) {
              if (!$printed{$pguid.$remainder}) {
                print $fh "\t\t{$pguid}.$remainder.ActiveCfg = $c$crlf",
                          "\t\t{$pguid}.$remainder.Build.0 = $c$crlf";
                $printed{$pguid.$remainder} = 1;
              }
            }
          }
        }
        print $fh "\t\t{$pguid}.$c.ActiveCfg = $c$crlf",
                  "\t\t{$pguid}.$c.Build.0 = $c$crlf";
      }
    }
    else {
      ## Non-C++ projects have no configurations
      if (!defined $cfgs[0]) {
        foreach my $c (sort keys %configs) {
          my $cfg = $c . '|.NET';
          print $fh "\t\t{$pguid}.$c.ActiveCfg = $cfg$crlf",
                    "\t\t{$pguid}.$c.Build.0 = $cfg$crlf";
        }
      }
    }
  }
  print $fh "\tEndGlobalSection$crlf";

  $self->print_additional_sections($fh);

  print $fh "EndGlobal$crlf";
}


sub adjust_names {
  my($self, $name, $proj, $lang) = @_;
  $proj =~ s/\//\\/g;
  return $name, $proj;
}


sub get_short_config_name {
  my($self, $cfg) = @_;
  $cfg =~ s/\|.*//;
  return $cfg;
}


sub get_solution_config_section_name {
  #my $self = shift;
  return 'SolutionConfiguration';
}


sub get_project_config_section_name {
  #my $self = shift;
  return 'ProjectConfiguration';
}


sub print_additional_sections {
  my($self, $fh) = @_;
  my $crlf = $self->crlf();

  print $fh "\tGlobalSection(ExtensibilityGlobals) = postSolution$crlf",
            "\tEndGlobalSection$crlf",
            "\tGlobalSection(ExtensibilityAddIns) = postSolution$crlf",
            "\tEndGlobalSection$crlf";
}


1;
