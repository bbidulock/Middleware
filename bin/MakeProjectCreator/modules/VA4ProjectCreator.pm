package VA4ProjectCreator;

# ************************************************************
# Description   : A VA4 Project Creator
# Author        : Chad Elliott
# Create Date   : 7/8/2002
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;

use ProjectCreator;

use vars qw(@ISA);
@ISA = qw(ProjectCreator);

# ************************************************************
# Subroutine Section
# ************************************************************

sub convert_slashes {
  #my($self) = shift;
  return 0;
}


sub file_sorter {
  my($self)  = shift;
  my($left)  = shift;
  my($right) = shift;
  return lc($left) cmp lc($right);
}


sub crlf {
  my($self) = shift;
  return $self->windows_crlf();
}


sub project_file_name {
  my($self) = shift;
  my($name) = shift;

  if (!defined $name) {
    $name = $self->project_name();
  }

  return $self->get_modified_project_file_name($name, '.icc');
}


sub get_dll_exe_template_input_file {
  #my($self) = shift;
  return 'va4iccdllexe';
}


sub get_lib_exe_template_input_file {
  #my($self) = shift;
  return 'va4icclibexe';
}


sub get_lib_template_input_file {
  #my($self) = shift;
  return 'va4icclib';
}


sub get_dll_template_input_file {
  #my($self) = shift;
  return 'va4iccdll';
}


sub get_template {
  #my($self) = shift;
  return 'va4icc';
}


1;
