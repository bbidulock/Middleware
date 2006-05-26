
/* -*- C++ -*- */

/***
 * file RMClient.cpp
 *
 * $Id$
 *
 * A sample client to the RepositoryManager showcasing how to use it
 *
 * author Stoyan Paunov <spaunov@isis.vanderbilt.edu>
 **/

#include "RepositoryManagerDaemonC.h"
#include "Options.h"

#include "ace/OS_NS_fcntl.h"      //for open
#include "ace/OS_NS_unistd.h"        //for close
#include "ace/OS_NS_sys_stat.h"        //for filesize and fstat and mkdir

#include "Config_Handlers/DnC_Dump.h"

#include <iostream>
using namespace std;

#include "RM_Helper.h"          //to be able to externalize/internalize a PackageConfiguration
#include "tao/CDR.h"          //for TAO CDR classes
#include "ace/Message_Block.h"      //for ACE_Message_Block

#include "Config_Handlers/Utils/XML_Helper.h"
#include "Config_Handlers/Package_Handlers/PCD_Handler.h"

#include "orbsvcs/CosNamingC.h"


//IOR file of the RM
const char *ior = "file://RepositoryManagerDeamon.ior";

//Name service of the RM
char *RMname_service;


///=============================COUPLE OF HELPER METHORS==================================
CORBA::Octet* read_from_disk (
  const char* full_path,
  size_t &length
  );

int write_to_disk (
  const char* full_path,
  const CORBA::Octet* buffer,
  size_t length
  );
///========================================================================================


///main function that provides a sample interface for RM clients

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_TRY_NEW_ENV
    {
      // Initialize orb
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv,
                      ""ACE_ENV_ARG_PARAMETER);

      ACE_TRY_CHECK;

      Options* options = TheOptions::instance ();
      if (!options->parse_args (argc, argv))
        return -1;

      CORBA::Object_var obj;

      if (options->write_to_ior_)
      {
        obj = orb->string_to_object (ior ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }

      else if (options->register_with_ns_)
      {
        if (options->repoman_name_ != "")
          RMname_service = const_cast<char*> (options->repoman_name_.c_str ());

        // Naming Service related operations
        CORBA::Object_var naming_context_object =
          orb->resolve_initial_references ("NameService"
          ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (false);

        CosNaming::NamingContext_var naming_context =
          CosNaming::NamingContext::_narrow (naming_context_object.in ());
        ACE_TRY_CHECK;

        // Initialize the Naming Sequence
        CosNaming::Name name (1);
        name.length (1);

        // String dup required for MSVC6
        name[0].id = CORBA::string_dup (RMname_service);

        // Resolve object from name
        obj = naming_context->resolve (name);
        ACE_TRY_CHECK;
      }


    CIAO::RepositoryManagerDaemon_var rm =
      CIAO::RepositoryManagerDaemon::_narrow (obj.in ()
                                ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (rm.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to acquire RepositoryManagerDaemon's objref\n"),
                            -1);
        }

    if (options->shutdown_)
    {
      rm->shutdown ();
    }
    else if (options->all_names_)
    {
      try
      {
        CORBA::StringSeq_var seq = rm->getAllNames ();
        cout << "Known Names:\n";
        cout << "Seq length () : " << seq->length () << endl;
        for (size_t i = 0;
           i < seq->length ();
           ++i)
           cout << seq[i] << endl;
      }
      catch (CORBA::Exception & ex)
      {
        cout << "\nException caught!" << ex << "\n";
        return 0;
      }
    }
    else if (options->all_types_)
    {
      try
      {
        CORBA::StringSeq_var seq = rm->getAllTypes ();
        cout << "Known Component Interface Types:\n";
        for (size_t i = 0;
           i < seq->length ();
           ++i)
           cout << seq[i] << endl;
      }
      catch (CORBA::Exception & ex)
      {
        cout << "\nException caught!" << ex << "\n";
        return 0;
      }
    }
    else if (options->uuid_ != "" && options->names_by_type_)
    {
      try
      {
        CORBA::StringSeq_var seq = rm->findNamesByType (options->uuid_.c_str ());
        cout << "Known Component Interface Types:\n";
        for (size_t i = 0;
           i < seq->length ();
           ++i)
           cout << seq[i] << endl;
      }
      catch (CORBA::Exception & ex)
      {
        cout << "\nException caught!" << ex << "\n";
        return 0;
      }
    }
    else if (options->install_)
    {
      try
      {
        rm->installPackage (options->name_.c_str (), options->path_.c_str ());
      }
      catch (CORBA::Exception & ex)
      {
        cout << "\nException caught!" << ex << "\n";
        return 0;
      }

      cout << "\nReassuring that the package in the repository ..." << endl;
      try
      {
        Deployment::PackageConfiguration_var pc = rm->findPackageByName (options->name_.c_str ());
        cout << "The package was found!" << endl;
        cout << "Label: " << pc->label << endl;
        cout << "UUID: " << pc->UUID << endl;
      }
      catch (CORBA::Exception &)
      {
        cout << "\nError! Package not found!" << endl;
      }
    }
    else if (options->create_)
    {
      try
      {
        // Change the working dir.
        char cwd [1024];
        ACE_OS::getcwd (cwd, 1024);
        ACE_CString descriptor_dir (cwd);
        descriptor_dir += "/packageDescriptors/RACE/descriptors/";
        ACE_OS::chdir (descriptor_dir.c_str ());

        Deployment::PackageConfiguration *pc = new Deployment::PackageConfiguration ();

        // Parse the PCD to make sure that there are no package errors.
        ACE_TRY
        {
          xercesc::DOMDocument *doc =
            CIAO::Config_Handlers::XML_HELPER->create_dom ("default.pcd");

          if (0 != doc)
            {
              CIAO::Config_Handlers::Packaging::PCD_Handler::package_config (
                "default.pcd",
                *pc);
            }
        }
        ACE_CATCHALL
        {
          ACE_ERROR ((
            LM_ERROR,
            "(%P|%t) [RM::retrieve_PC_from_descriptors] Error parsing the PCD\n"));

          ACE_THROW (Deployment::PackageError ());
        }
        ACE_ENDTRY;

        ACE_OS::chdir (cwd);

        rm->createPackage (options->name_.c_str (), *pc, options->path_.c_str (), false);
      }
      catch (CORBA::Exception & ex)
      {
        cout << "\nException caught!" << ex << "\n";
        return 0;
      }
    }
    else if (options->delete_)
    {
      try
      {
        rm->deletePackage (options->name_.c_str ());
        cout << options->name_.c_str () << " deleted" << endl;
      }
      catch (CORBA::Exception & ex)
      {
        cout << "\nException: " << ex << endl;
      }

    }
    else if (options->find_)
    {
      if (options->name_ != "")
      {
        Deployment::PackageConfiguration_var pc = rm->findPackageByName (options->name_.c_str ());
        cout << "The package was found!" << endl;
        //Deployment::DnC_Dump::dump (pc);
      }
      else
      {
        Deployment::PackageConfiguration_var pc = rm->findPackageByUUID (options->uuid_.c_str ());
        cout << "The package was found!" << endl;
        //Deployment::DnC_Dump::dump (pc);
      }
    }

      orb->shutdown (1);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Unknown exception \n");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}

CORBA::Octet* read_from_disk (
  const char* full_path,
  size_t &length
  )
{
  //open the file

  ACE_HANDLE handle = ACE_OS::open (full_path, O_RDONLY);
    if (handle == ACE_INVALID_HANDLE)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("[RM::read_from_disk] file open error")),
                           0);

  ACE_stat file_info;

  ACE_OS::fstat (handle, &file_info);

  CORBA::Octet* buffer = 0;
  ACE_NEW_RETURN (buffer, CORBA::Octet[file_info.st_size], 0);

  // read the contents of the file into the buffer
  if (ACE_OS::read_n (handle, buffer, file_info.st_size) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
               ACE_TEXT ("[RM::write_to_disk] file write error")),
                           0);

  // Close the file handle
    ACE_OS::close (handle);

  length = file_info.st_size;
  return buffer;
}


int write_to_disk (
  const char* full_path,
  const CORBA::Octet* buffer,
  size_t length
  )
{
  // Open a file handle to the local filesystem
    ACE_HANDLE handle = ACE_OS::open (full_path, O_CREAT | O_TRUNC | O_WRONLY);
    if (handle == ACE_INVALID_HANDLE)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("[RM::write_to_disk] file creation error")),
                           -1);

  //write the data to the file
  if (ACE_OS::write (handle, buffer, length) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("[RM::write_to_disk] file write error")),
                           -1);

  // Close the file handle
    ACE_OS::close (handle);

  return 1;
}

