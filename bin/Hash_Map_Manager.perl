#
# $Id$
#

#
# This script helps in fixing the template instantiations changes
# required by the new design of ACE_Hash_Map_Manager.  Note that this
# script is not a 100% fool proof: (a) It uses commas to delimit the
# types in ACE_Hash_Map_Manager<X, Y, Z>.  If X, Y, or Z are
# complicated types containing commas (e.g., T<a, b>), this script
# will not work. (b) The second problem is for g++ users (version
# lower than 2.8). g++ is broken such that if you explicitly
# instantiate templates, it will ignore template specialization.
# Therefore if you are using the template instantiation provided in
# ACE for ACE_Hash and ACE_Equal_To, don't instantiate those
# templates.
#
# This script is used by Hash_Map_Manager_Helper.csh.
#

$template_instantiation = "template class";
$end_of_template_instantiation = ";";

$pragma_instantiation = "#pragma instantiate";
$end_of_pragma_instantiation = "";

while ($line = <>) 
{
    find_match ("ACE_Hash_Map_Entry");
    if ($match)
    {
        $template_parameters =~ /(.*),\s*(.*)/;
        $X = $1;
        $Y = $2;
        
        print "$instantiation ACE_Hash_Map_Entry<$template_parameters>$end_of_instantiation\n";           
        print "$instantiation ACE_Hash<$X>$end_of_instantiation\n";
        print "$instantiation ACE_Equal_To<$X>$end_of_instantiation\n";
        next;
    }         

    add_ex ("ACE_Hash_Map_Manager", 1);
    add_ex ("ACE_Hash_Map_Iterator", 1);
    add_ex ("ACE_Hash_Map_Reverse_Iterator", 1);
    add_ex ("ACE_Hash_Map_Iterator_Base", 0);

    print $line;
}

sub find_match
{
    $key = $_[0].'\s*<\s*(.*)>\s*';
    if ($line =~ /$template_instantiation $key$end_of_template_instantiation$/) 
    {
        $match = 1;
        $template_parameters = $1;        
        $instantiation = $template_instantiation;
        $end_of_instantiation = $end_of_template_instantiation;
    }
    elsif ($line =~ /$pragma_instantiation $key$end_of_pragma_instantiation$/) 
    {
        $match = 1;
        $template_parameters = $1;        
        $instantiation = $pragma_instantiation;
        $end_of_instantiation = $end_of_pragma_instantiation;
    }
    else
    {
        $match = 0;
    }
}

sub add_ex
{
    $add_original_line = $_[1];
    find_match ($_[0]);
    if ($match)
    {
        $template_parameters =~ /(.*),\s*(.*),\s*(.*)/;
        $X = $1;
        $Y = $2;
        $Z = $3;
        
        if ($add_original_line)
        {
            print "$instantiation $_[0]<$template_parameters>$end_of_instantiation\n";           
        }

        print "$instantiation $_[0]_Ex<$X, $Y, ACE_Hash<$X>, ACE_Equal_To<$X>, $Z>$end_of_instantiation\n";           
        next;
    }         
}

