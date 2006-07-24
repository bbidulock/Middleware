#!/opt/local/bin/python

""" This script implements branching and tagging in the DOC group
repository, and automates the process of creating sets. """

import os

def parse_args ():
    from optparse import OptionParser
    
    parser = OptionParser ("usage: %prog [optoins] name")
    parser.add_option ("-A", "--ACE", dest="project", action="store_const",
                       help="Branch/tag only ACE", default=None, const="ace")
    parser.add_option ("-T", "--TAO", dest="project", action="store_const",
                       help="Branch/tag ACE and TAO", default=None, const="tao")
    parser.add_option ("-C", "--CIAO", dest="project", action="store_const",
                       help="Branch/tag ACE, TAO, and CIAO", default=None, const="ciao")
    parser.add_option ("-t", "--tag", dest="action", 
                       help="Create a tag", action="store_true", default=None)
    parser.add_option ("-b", "--branch", dest="action", action="store_false",
                       help="Create a branch", default=None)
    parser.add_option ("-v", "--verbose", dest="verbose", action="store_true",
                       help="Print out verbose debugging output", default=False)
    parser.add_option ("-s", "--svn", dest="svn", default="svn",
                       help="Full path to svn binary, if not in path")
    parser.add_option ("-r", "--repo", dest="repo", 
                       default="https://svn.dre.vanderbilt.edu/DOC/ACE/",
                       help="Repository to use, defaults to s.d.v.e/DOC/ACE.")
    parser.add_option ("--src", dest="source", default="trunk/",
                       help="Path in repository from which to branch, defaults to trunk")
    parser.add_option ("--dest", dest="dest", default="",
                       help="Specifies a subdirectory of branches or tags in which " +
                       "to place the new branch/tag. dest must already exist.")
    parser.add_option ("-n", dest="take_action", action="store_false", default=True,
                       help="Take no action")
    (opts, args) = parser.parse_args ()

    if len(args) != 1:
        parser.error ("must specify exactly one branch or tag name")

    if opts.action is None:
        parser.error ("must specify either a branch or tag action")

    if opts.project is None:
        parser.error ("must specity a project to branch")
        
    return (opts, args)

def execute (command):
    from os import system

    if opts.verbose:
        print "executing " + command
    if opts.take_action and os.system (command) != 0:
        raise Exception ("Command failed: " + command)

def svn_copy (source, dest):
    command = " ".join ([opts.svn,
                         "copy",
                         '-m "branching/tagging"',
                         source,
                         dest])
    execute (command)

def svn_propset (path, prop, value):
    command = " ".join ([opts.svn,
                        "propset",
                        prop,
                        "'" + value + "'",
                        path])
    execute (command)

def svn_mkdir (path):
    command = " ".join ([opts.svn,
                         "mkdir",
                         '-m "branching/tagging"',
                         path])
    execute (command)

def svn_mkdir_local (path):
    command = " ".join ([opts.svn,
                        "mkdir",
                        path])
    execute (command)

def branch_ACE ():
    # Perform branching
    destination = opts.repo + opts.dest
    svn_copy (opts.repo + opts.source + "/ACE",
              destination + "modules/ACE")
    #Create the set
    svn_mkdir_local ("sets/ACE")
    svn_propset ("sets/ACE",
                 "svn:externals",
                 "%s\t%s" % ("ACE_wrappers",
                             destination + "modules/ACE"))

def branch_TAO ():
    branch_ACE ()
    
    # Perform branching
    destination = opts.repo + opts.dest
    svn_copy (opts.repo + opts.source + "/TAO",
              destination + "modules/TAO")

    #Create the set
    svn_mkdir_local ("sets/ACE+TAO")
    svn_propset ("sets/ACE+TAO",
                 "svn:externals",
                 "%s\t%s\n%s\t%s" % ("ACE_wrappers",
                                     destination + "modules/ACE",
                                     "ACE_wrappers/TAO",
                                     destination + "modules/TAO"))

def branch_CIAO ():
    branch_TAO ()

    #Perform branching
    destination = opts.repo + opts.dest
    svn_copy (opts.repo + opts.source + "/CIAO",
              destination + "modules/CIAO")

    # Create the set
    svn_mkdir_local ("sets/ACE+TAO+CIAO")
    svn_propset ("sets/ACE+TAO+CIAO",
                 "svn:externals",
                 "%s\t%s\n%s\t%s\n%s\t%s" %
                 ("ACE_wrappers",
                  destination + "modules/ACE",
                  "ACE_wrappers/TAO",
                  destination + "modules/TAO",
                  "ACE_wrappers/TAO/CIAO",
                  destination + "modules/CIAO"))                         

def main (opts, args):
    # Lets make opts global
    globals ()['opts'] = opts

    path = str ()
    if opts.action:
        # True for tag
        path = "tags/"
    else: # Branch
        path = "branches/"

    path += "%s/%s" % (opts.dest, args[0])
    # Make branch/tag directory
    svn_mkdir (opts.repo + path)

    # Make modules and sets subdirectory
    svn_mkdir (opts.repo + path + "/modules")
    svn_mkdir (opts.repo + path + "/sets")

    # We need a local copy of the sets directory, as svn:externals
    # can only be modified locally
    execute ("svn co " + opts.repo + path + "/sets")
    
    # opts.dest should now be set to path, all of the branching
    # functions assume dest now points to the branch/tag in which
    # the copies should be places
    opts.dest = path + '/'

    {'ace': branch_ACE,
     'tao': branch_TAO,
     'ciao': branch_CIAO}[opts.project] ()

    # Commit the sets directory
    execute ('svn commit -m "branching/tagging" sets')

    # remove the sets directory
    for root, dirs, files in os.walk ('sets', False):
        for name in files:
            os.remove (os.path.join (root, name))
        for name in dirs:
            os.rmdir (os.path.join (root, name))
    
if __name__ == "__main__":
    opts, args = parse_args ()
    main (opts, args)

