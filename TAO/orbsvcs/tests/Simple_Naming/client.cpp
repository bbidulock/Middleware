// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/Naming_Service/
//
// = FILENAME
//    client.cpp
//
// = DESCRIPTION
//      This class implements a simple CORBA client for the CosNaming
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//      Sergio Flores-Gaitan <sergio@cs.wustl.edu>,
//      Marina Spivak <marina@cs.wustl.edu>, and
//      Douglas C. Schmidt <schmidt@cs.wustl.edu>
// ============================================================================

#include "client.h"
#include "tao/debug.h"
#include "ace/Get_Opt.h"

ACE_RCSID(Simple_Naming, client, "$Id$")

#if defined (_MSC_VER)
# pragma warning (disable : 4250)
#endif /* _MSC_VER */

class My_Test_Object :
  public virtual PortableServer::RefCountServantBase,
  public virtual POA_Test_Object
{
public:
  // = Initialization and termination methods.
  My_Test_Object (CORBA::Short id = 0);
  // Constructor.

  ~My_Test_Object (void);
  // Destructor.

  // = Interface implementation accessor methods.

  void id (CORBA::Short id ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Sets id.

  CORBA::Short id (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Gets id.

private:
  short id_;
};

My_Test_Object::My_Test_Object (CORBA::Short id)
  : id_ (id)
{
}

My_Test_Object::~My_Test_Object (void)
{
}

CORBA::Short
My_Test_Object::id (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return id_;
}

void
My_Test_Object::id (CORBA::Short id ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  id_ = id;
}

// Constructor.

CosNaming_Client::CosNaming_Client (void)
  : argc_ (0),
    argv_ (0),
    test_ (0)
{
}

// Parses the command line arguments and returns an error status.

int
CosNaming_Client::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "p:dstieym:c:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag
        TAO_debug_level++;
        break;
      case 's':
        if (this->test_ == 0)
          ACE_NEW_RETURN (this->test_,
                          Simple_Test,
                          -1);
        break;
      case 'm':
        if (this->test_ == 0)
          {
            int size = ACE_OS::atoi (get_opts.opt_arg ());
            if (size <= 0)
              size = 10;

            ACE_NEW_RETURN (this->test_,
                            MT_Test (this->orbmgr_.orb (), size),
                            -1);
          }

        break;
      case 't':
        if (this->test_ == 0)
          ACE_NEW_RETURN (this->test_,
                          Tree_Test,
                          -1);
        break;
      case 'i':
        if (this->test_ == 0)
          ACE_NEW_RETURN (this->test_,
                          Iterator_Test,
                          -1);
        break;
      case 'e':
        if (this->test_ == 0)
          ACE_NEW_RETURN (this->test_,
                          Exceptions_Test,
                          -1);
        break;
      case 'y':
        if (this->test_ == 0)
          ACE_NEW_RETURN (this->test_,
                          Destroy_Test,
                          -1);
        break;
      case 'p':
        if (this->test_ == 0)
          {
            FILE * ior_output_file =
              ACE_OS::fopen (get_opts.opt_arg (), "w");

            if (ior_output_file == 0)
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Unable to open %s for writing: %p\n",
                                 get_opts.opt_arg ()), -1);

            ACE_NEW_RETURN (this->test_,
                            Persistent_Test_Begin (this->orbmgr_.orb (),
                                                   ior_output_file),
                            -1);
          }
        break;
      case 'c':
        if (this->test_ == 0)
          ACE_NEW_RETURN (this->test_,
                          Persistent_Test_End (this->orbmgr_.orb (),
                                               get_opts.opt_arg ()),
                          -1);
        break;
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Argument %c \n usage:  %s"
                           " [-d]"
                           " [-s or -e or -t or -i or -y or -p or -c<ior> or -m<size>]"
                           "\n",
                           c,
                           this->argv_ [0]),
                          -1);
      }

  if (this->test_ == 0)
    ACE_NEW_RETURN (this->test_,
                    Simple_Test,
                    -1);

  // Indicates successful parsing of command line.
  return 0;
}

// Execute client example code.

int
CosNaming_Client::run (void)
{
  return test_->execute (naming_client_);
}

CosNaming_Client::~CosNaming_Client (void)
{
  delete test_;
}

int
CosNaming_Client::init (int argc, char **argv)
{
  this->argc_ = argc;
  this->argv_ = argv;

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Initialize ORB.
      this->orbmgr_.init (this->argc_,
                          this->argv_
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      this->orbmgr_.activate_poa_manager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Parse command line and verify parameters.
      if (this->parse_args () == -1)
        return -1;

      CORBA::ORB_var orb = this->orbmgr_.orb ();
      return this->naming_client_.init (orb.in ());
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "init");
      // and return -1 below . . .
    }
  ACE_ENDTRY;

  return -1;
}

MT_Test::MT_Test (CORBA::ORB_ptr orb,
                  int size)
   :size_ (size),
    orb_ (orb),
    name_service_ior_ (0)
{
}

int
MT_Test::svc (void)
{
  // Obtain object reference to the Naming Service (create new stub.)

  CosNaming::NamingContext_var name_service;

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY_EX (SETUP)
    {
      CORBA::Object_var name_service_obj =
        orb_->string_to_object (name_service_ior_ ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK_EX (SETUP);

      name_service =
        CosNaming::NamingContext::_narrow (name_service_obj.in ()
                                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK_EX (SETUP);
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in MT test setup");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  if (name_service.in () == 0)
    return -1;

  // Bind the object.
  ACE_TRY_EX (BIND)
    {
      name_service->bind (test_name_,
                          test_ref_.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK_EX (BIND);
      ACE_DEBUG ((LM_DEBUG,
                  "Bound name OK in thread %t\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::AlreadyBound, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Unable to bind in thread %t\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in MT test bind");
      // This debug statement works around a IRIX/MIPSPro 7.3 bug (it
      // fails with optimize=1 debug=0; but works with any other
      // settings for those flags).
      ACE_DEBUG ((LM_DEBUG, "MT_Test(%t) - bind[3] %d\n",
                  test_name_.length ()));
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  // Resolve the object from the Naming Context.
  ACE_TRY_EX (RESOLVE)
    {
      CORBA::Object_var result_obj_ref =
        name_service->resolve (test_name_
                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK_EX (RESOLVE);

      Test_Object_var result_object =
        Test_Object::_narrow (result_obj_ref.in ()
                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK_EX (RESOLVE);

      if (!CORBA::is_nil (result_object.in ()))
        {
          CORBA::Short id = result_object->id (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK_EX (RESOLVE);

          if (id == CosNaming_Client::OBJ1_ID)
            ACE_DEBUG ((LM_DEBUG,
                        "Resolved name OK in thread %t\n"));
        }
    }
  ACE_CATCH (CosNaming::NamingContext::NotFound, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Unable to resolve in thread %t\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in MT test resolve");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  // Unbind the object from the Naming Context.
  ACE_TRY_EX (UNBIND)
    {
      name_service->unbind (test_name_
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK_EX (UNBIND);
      ACE_DEBUG ((LM_DEBUG,
                  "Unbound name OK in thread %t\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::NotFound, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Unable to unbind in thread %t\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in MT test unbind");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

int
MT_Test::execute (TAO_Naming_Client &root_context)
{
  if (CORBA::is_nil (this->orb_.in ()))
    return -1;

  // Create data which will be used by all threads.

  // Dummy object instantiation.
  My_Test_Object *test_obj_impl =
    new My_Test_Object (CosNaming_Client::OBJ1_ID);

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      test_ref_ =
        test_obj_impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      test_obj_impl->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Get the IOR for the Naming Service.  Each thread can use it
      // in <string_to_object> to create its own stub for the Naming
      // Service.  This 'trick' is necessary, because multiple threads
      // cannot be using the same stub - bad things happen...  This is
      // just a way to give each thread its own stub.

      CosNaming::NamingContext_var context =
        root_context.get_context ();

      name_service_ior_ =
        orb_->object_to_string (context.in ()
                                ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception while instantiating dummy");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  // Create a name for dummy.
  test_name_.length (1);
  test_name_[0].id = CORBA::string_dup ("Foo");

  // Spawn threads, each of which will be executing svc ().
  int status = this->activate (THR_NEW_LWP | THR_JOINABLE,
                               size_);

  if (status == -1)
    return -1;

  status = this->wait ();
  return status;
}

int
Simple_Test::execute (TAO_Naming_Client &root_context)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Dummy object instantiation.
      My_Test_Object *test_obj_impl = new My_Test_Object (CosNaming_Client::OBJ1_ID);
      Test_Object_var test_obj_ref =
        test_obj_impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Give ownership of this object to POA.
      test_obj_impl->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Bind an object to the Naming Context.
      CosNaming::Name test_name;
      test_name.length (1);
      test_name[0].id = CORBA::string_dup ("Foo");
      root_context->bind (test_name,
                          test_obj_ref.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG,
                  "Bound name OK\n"));

      // Resolve the object from the Naming Context.
      CORBA::Object_var result_obj_ref =
        root_context->resolve (test_name
                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      Test_Object_var result_object =
        Test_Object::_narrow (result_obj_ref.in ()
                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      if (!CORBA::is_nil (result_object.in ()))
        {
          CORBA::Short id = result_object->id (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
          if (id == CosNaming_Client::OBJ1_ID)
            ACE_DEBUG ((LM_DEBUG, "Resolved name OK\n"));
        }

      // Unbind the object from the Naming Context.
      root_context->unbind (test_name
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG,
                  "Unbound name OK\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in Simple test");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

int
Tree_Test::execute (TAO_Naming_Client &root_context)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Create a tree of contexts: root->level1->level2.  Bind object
      // foo under context level2.

      // Bind level1 context under root.
      CosNaming::Name level1;
      level1.length (1);
      level1[0].id = CORBA::string_dup ("level1_context");
      CosNaming::NamingContext_var level1_context;
      level1_context = root_context->bind_new_context (level1
                                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Create a new context.
      CosNaming::NamingContext_var level2_context;
      level2_context = root_context->new_context (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Instantiate a dummy object and bind it under the new context.
      My_Test_Object *impl1 =
        new My_Test_Object (CosNaming_Client::OBJ1_ID);
      Test_Object_var obj1 = impl1->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      impl1->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CosNaming::Name obj_name;
      obj_name.length (1);
      obj_name[0].id = CORBA::string_dup ("foo");
      level2_context->bind (obj_name, obj1.in ()
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Bind the context we just created under level1.
      CosNaming::Name level2 (level1);
      level2.length (2);
      level2[1].id = CORBA::string_dup ("level2_context");
      root_context->bind_context (level2,
                                  level2_context.in ()
                                  ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Resolve and unbind level1/level2/foo, and bind it back.
      CosNaming::Name test_name (level2);
      test_name.length (3);
      test_name[2].id = obj_name[0].id;
      CORBA::Object_var result_obj_ref =
        root_context->resolve (test_name
                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      Test_Object_var result_object =
        Test_Object::_narrow (result_obj_ref.in ()
                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (result_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Problems with resolving foo in Tree Test - nil object ref.\n"),
                          -1);

      CORBA::Short id = result_object->id (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (id != CosNaming_Client::OBJ1_ID)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Problems with resolving foo in Tree Test - wrong id.\n"),
                          -1);

      // Unbind the object from the Naming Context and bind it back
      // in.
      root_context->unbind (test_name
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      root_context->bind (test_name,
                          obj1.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Create new context and rebind under the name level1/level2.
      CosNaming::NamingContext_var new_level2_context;
      new_level2_context =
        root_context->new_context (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      root_context->rebind_context (level2,
                                  new_level2_context.in ()
                                  ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Bind, resolve, rebind, and resolve foo under level1/level2.
      root_context->bind (test_name,
                          obj1.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      result_obj_ref = root_context->resolve (test_name
                                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      result_object = Test_Object::_narrow (result_obj_ref.in ()
                                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Short obj_id = result_object->id (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (result_object.in ())
          || !(obj_id == CosNaming_Client::OBJ1_ID))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Problems in the Tree Test\n"),
                          -1);

      My_Test_Object *impl2 =
        new My_Test_Object (CosNaming_Client::OBJ2_ID);
      Test_Object_var obj2 = impl2->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      impl2->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      root_context->rebind (test_name,
                            obj2.in ()
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      result_obj_ref = root_context->resolve (test_name
                                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      result_object = Test_Object::_narrow (result_obj_ref.in ()
                                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      obj_id = result_object->id (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (result_object.in ())
          || !( obj_id == CosNaming_Client::OBJ2_ID))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Problems with rebind in Tree Test\n"),
                          -1);
    }

  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in Tree test");
      return -1;
    }

  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  ACE_DEBUG ((LM_DEBUG,
              "All functions work properly \n"));
  return 0;
}

int
Exceptions_Test::execute (TAO_Naming_Client &root_context)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Set things up.

      // Create a tree of contexts root->level1->level2.
      CosNaming::Name context_name;
      context_name.length (1);
      context_name[0].id = CORBA::string_dup ("level1_context");
      CosNaming::NamingContext_var level1_context;
      level1_context = root_context->bind_new_context (context_name
                                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      context_name[0].id = CORBA::string_dup ("level2_context");
      CosNaming::NamingContext_var level2_context;
      level2_context = level1_context->bind_new_context (context_name
                                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Bind a dummy object foo under each context.
      My_Test_Object *impl = new My_Test_Object;
      Test_Object_var obj = impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      impl->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CosNaming::Name object_name;
      object_name.length (1);
      object_name[0].id = CORBA::string_dup ("foo");
      root_context->bind (object_name,
                          obj.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      level1_context->bind (object_name,
                            obj.in ()
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      level2_context->bind (object_name,
                            obj.in ()
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Run exceptions tests.
      invalid_name_test (root_context
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      already_bound_test (root_context
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      already_bound_test2 (root_context
                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      not_found_test (root_context
                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      not_found_test2 (root_context
                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      not_found_test3 (root_context
                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in Exceptions test");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

void
Exceptions_Test::invalid_name_test (TAO_Naming_Client &root_context
                                    ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      CosNaming::Name test_name;
      test_name.length (0);

      root_context->resolve (test_name
                             ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG, "Invalid name test failed\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::InvalidName, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "InvalidName exception works properly\n"));
    }
  ACE_CATCHANY
    {
      ACE_DEBUG ((LM_DEBUG, "Invalid name test failed\n"));
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
}

void
Exceptions_Test::already_bound_test (TAO_Naming_Client &root_context
                                     ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      CosNaming::Name test_name;
      test_name.length (1);
      test_name[0].id = CORBA::string_dup ("foo");
      My_Test_Object *impl = new My_Test_Object;
      Test_Object_var obj = impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      impl->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      root_context->bind (test_name,
                          obj.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG, "Already bound (case 1) test failed\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::AlreadyBound, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "AlreadyBound exception (case 1) works properly\n"));
    }
  ACE_CATCHANY
    {
      ACE_DEBUG ((LM_DEBUG, "Already bound (case 1) test failed\n"));
      ACE_RE_THROW;
    }

  ACE_ENDTRY;
  ACE_CHECK;
}

void
Exceptions_Test::already_bound_test2 (TAO_Naming_Client &root_context
                                      ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      CosNaming::Name test_name;
      test_name.length (2);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("foo");
      My_Test_Object *impl = new My_Test_Object;
      Test_Object_var obj = impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      impl->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      root_context->bind (test_name,
                          obj.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG, "Already bound (case 2) test failed\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::AlreadyBound, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "AlreadyBound  exception (case 2) works properly\n"));
    }
  ACE_CATCHANY
    {
      ACE_DEBUG ((LM_DEBUG, "Already bound (case 2) test failed\n"));
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
}

void
Exceptions_Test::not_found_test (TAO_Naming_Client &root_context
                                 ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      CosNaming::Name test_name;
      test_name.length (3);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("level2_context");
      test_name[2].id = CORBA::string_dup ("bar");

      root_context->unbind (test_name
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG, "Not found test failed\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::NotFound, ex)
    {
      if (ex.why == CosNaming::NamingContext::missing_node &&
          ex.rest_of_name.length () == 1
          && ACE_OS::strcmp (ex.rest_of_name[0].id.in (),
                             "bar") == 0)
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 1) works properly\n"));
      else
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 1)"
                    " - parameters aren't set correctly\n"));
    }
  ACE_CATCHANY
    {
      ACE_DEBUG ((LM_DEBUG, "Not found test failed\n"));
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
}

void
Exceptions_Test::not_found_test2 (TAO_Naming_Client &root_context
                                  ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      CosNaming::Name test_name;
      test_name.length (3);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("level3_context");
      test_name[2].id = CORBA::string_dup ("foo");

      root_context->unbind (test_name
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG, "Unbind test failed\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::NotFound, ex)
    {
      if (ex.why == CosNaming::NamingContext::missing_node
          && ex.rest_of_name.length () == 2
          && ACE_OS::strcmp (ex.rest_of_name[0].id.in (),
                             "level3_context") == 0
          && ACE_OS::strcmp (ex.rest_of_name[1].id.in (),
                             "foo") == 0)
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 2) works properly\n"));
      else
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 2)"
                    " - parameters aren't set correctly\n"));
    }
  ACE_CATCHANY
    {
      ACE_DEBUG ((LM_DEBUG, "Unbind test failed\n"));
      ACE_RE_THROW;
    }

  ACE_ENDTRY;
  ACE_CHECK;
}

void
Exceptions_Test::not_found_test3 (TAO_Naming_Client &root_context
                                  ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      CosNaming::Name test_name;
      test_name.length (3);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("foo");
      test_name[2].id = CORBA::string_dup ("foo");

      root_context->unbind (test_name ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ACE_DEBUG ((LM_DEBUG, "Not found (case 3) test failed - no exception was thrown\n"));
    }
  ACE_CATCH (CosNaming::NamingContext::NotFound, ex)
    {
      if (ex.why == CosNaming::NamingContext::not_context
          && ex.rest_of_name.length () == 2
          && ACE_OS::strcmp (ex.rest_of_name[0].id.in (),
                             "foo") == 0
          && ACE_OS::strcmp (ex.rest_of_name[1].id.in (),
                             "foo") == 0)
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 3) works properly\n"));
      else
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 3)"
                    " - parameters aren't set correctly\n"));
    }
  ACE_CATCHANY
    {
      ACE_DEBUG ((LM_DEBUG, "Not found (case 3) test failed\n"));
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
}

int
Iterator_Test::execute (TAO_Naming_Client &root_context)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Instantiate four dummy objects.
      My_Test_Object *impl = new My_Test_Object;
      Test_Object_var obj = impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      impl->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Bind objects to the naming context.
      CosNaming::Name name1;
      name1.length (1);
      name1[0].id = CORBA::string_dup ("foo1");
      CosNaming::Name name2;
      name2.length (1);
      name2[0].id = CORBA::string_dup ("foo2");
      CosNaming::Name name3;
      name3.length (1);
      name3[0].id = CORBA::string_dup ("foo3");
      CosNaming::Name name4;
      name4.length (1);
      name4[0].id = CORBA::string_dup ("foo4");
      root_context->bind (name1,
                          obj.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      root_context->bind (name2,
                          obj.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      root_context->bind (name3,
                          obj.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      root_context->bind (name4,
                          obj.in ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // List the content of the Naming Context.
      CosNaming::BindingIterator_var iter;
      CosNaming::BindingList_var bindings_list;
      root_context->list (1,
                          bindings_list.out (),
                          iter.out ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      if (CORBA::is_nil (iter.in ())
          || bindings_list->length () != 1
          || bindings_list[0u].binding_type != CosNaming::nobject)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::list does not function properly\n"),
                          -1);
      ACE_DEBUG ((LM_DEBUG,
                  "First binding: %s\n",
                  bindings_list[0u].binding_name[0u].id.in ()));

      // Invoke operations on the iterator.
      CosNaming::Binding_var binding;
      iter->next_one (binding.out ()
                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      if (binding->binding_type != CosNaming::nobject)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::next_one does not function properly\n"),
                          -1);
      ACE_DEBUG ((LM_DEBUG,
                  "Second binding: %s\n",
                  binding->binding_name[0].id.in ()));

      iter->next_n (2, bindings_list.out () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      if (bindings_list->length () != 2
          || bindings_list[0u].binding_type != CosNaming::nobject
          || bindings_list[1u].binding_type != CosNaming::nobject)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::BindingIterator does not function properly\n"),
                          -1);
      ACE_DEBUG ((LM_DEBUG,
                  "Third binding: %s\n"
                  "Fourth binding: %s\n",
                  bindings_list[0u].binding_name[0].id.in (),
                  bindings_list[1u].binding_name[0].id.in ()));

      // We already iterated over all the bindings, so the following
      // should return false.
      CORBA::Boolean result = iter->next_one (binding.out ()
                                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      if (result)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::BindingIterator does not function properly\n"),
                          -1);
      iter->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in Iterator test");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

int
Destroy_Test::execute (TAO_Naming_Client &root_context)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Create a context and bind an object under it.

      CosNaming::NamingContext_var my_context;
      my_context = root_context->new_context (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Bind a dummy object foo under my_context.
      My_Test_Object *impl = new My_Test_Object;
      Test_Object_var obj = impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      impl->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CosNaming::Name object_name;
      object_name.length (1);
      object_name[0].id = CORBA::string_dup ("foo");
      my_context->bind (object_name,
                            obj.in ()
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Do the testing.
      not_empty_test (my_context
                                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      my_context->unbind (object_name ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      my_context->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      not_exist_test (my_context
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }

  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Unexpected exception in Destroy test");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

void
Destroy_Test::not_empty_test (CosNaming::NamingContext_var &ref
                                    ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      ref->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }

  ACE_CATCH (CosNaming::NamingContext::NotEmpty, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "NotEmpty exception works properly\n"));
    }
  ACE_ENDTRY;
  ACE_CHECK;
}

void
Destroy_Test::not_exist_test (CosNaming::NamingContext_var &ref
                                    ACE_ENV_ARG_DECL)
{
  ACE_TRY
    {
      ref->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }

  ACE_CATCH (CORBA::OBJECT_NOT_EXIST, ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Destroy works properly\n"));
    }
  ACE_ENDTRY;
  ACE_CHECK;
}

Persistent_Test_Begin::Persistent_Test_Begin (CORBA::ORB_ptr orb,
                                              FILE * ior_output_file)
  : orb_ (orb),
    file_ (ior_output_file)
{
}

Persistent_Test_Begin::~Persistent_Test_Begin (void)
{
}

int
Persistent_Test_Begin::execute (TAO_Naming_Client &root_context)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Create a name structure we will reuse.
      CosNaming::Name test_name;
      test_name.length (1);
      test_name[0].id = CORBA::string_dup ("level1");

      // Create and bind a naming context under the <root> context.
      CosNaming::NamingContext_var level1_context =
        root_context->bind_new_context (test_name
                                        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Create and bind a naming context under <level1> context.
      test_name[0].id = CORBA::string_dup ("level2");
      CosNaming::NamingContext_var level2_context =
        level1_context->bind_new_context (test_name
                                        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Log the ior of <level1_context> for use by <Persistent_Test_End>.
      CORBA::String_var ior =
        orb_->object_to_string (level1_context.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_OS::fprintf (this->file_,
                       "%s",
                       ior.in ());
      ACE_OS::fclose (this->file_);

      ACE_DEBUG ((LM_DEBUG, "Persistent Naming test (part 1) OK.\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Unexpected exception in Persistent Test (part 1)");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

Persistent_Test_End::Persistent_Test_End (CORBA::ORB_ptr orb,
                                          const char *ior)
  : orb_ (orb),
    ior_ (ior)
{
}

Persistent_Test_End::~Persistent_Test_End (void)
{
}

int
Persistent_Test_End::execute (TAO_Naming_Client &root_context)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Create a name structure we will reuse.
      CosNaming::Name test_name;
      test_name.length (1);
      test_name[0].id = CORBA::string_dup ("level2");

      // Convert stringified ior we got from <Persistent_Test_Begin>
      // for <level1> Naming Context to Naming Context reference.
      CORBA::Object_var obj =
        orb_->string_to_object (ior_ ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CosNaming::NamingContext_var level1_context =
        CosNaming::NamingContext::_narrow (obj.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (level1_context.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot narrow object to Naming Context\n"),
                          -1);

      //  Resolve for <level2> context through the persistent ior we
      // got from part 1 of this test.
      obj = level1_context->resolve (test_name ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Now, resolve for <level2> context using the <root> context
      // reference which we obtained through <resolve_initial_references>.
      test_name.length (2);
      test_name[0].id = CORBA::string_dup ("level1");
      test_name[1].id = CORBA::string_dup ("level2");
      CORBA::Object_var obj2 =
        root_context->resolve (test_name ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Make sure we got the same answer through both methods.
      if (obj2->_is_equivalent (obj.in ()))
        ACE_DEBUG ((LM_DEBUG, "Persistent Naming test (part 2) OK.\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Unexpected exception in Persistent Test (part 2)");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

// This function runs the test.

int
main (int argc, char **argv)
{
  CosNaming_Client cosnaming_client;

  if (cosnaming_client.init (argc, argv) == -1)
    return 1;

  return cosnaming_client.run ();
}
