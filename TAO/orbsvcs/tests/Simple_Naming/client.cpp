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
#include "ace/Get_Opt.h"
#include "test_objectS.h"

ACE_RCSID(Simple_Naming, client, "$Id$")

class My_Test_Object : public POA_Test_Object
{
public:
  // = Initialization and termination methods.
  My_Test_Object (CORBA::Short id = 0);
  // Constructor.

  ~My_Test_Object (void);
  // Destructor.

  // = Interface implementation accessor methods.

  void id (CORBA::Short id, CORBA::Environment &_env);
  // Sets id.

  CORBA::Short id (CORBA::Environment &_env);
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
My_Test_Object::id (CORBA::Environment &_env)
{
  return id_;
}

void
My_Test_Object::id (CORBA::Short id, CORBA::Environment &_env)
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
  ACE_Get_Opt get_opts (argc_, argv_, "dstiey");
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
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
                           " [-s or -e or -t or -i or -y]"
                           "\n",
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

  TAO_TRY
    {
      // Initialize ORB.
      this->orbmgr_.init (argc,
                          argv,
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Parse command line and verify parameters.
      if (this->parse_args () == -1)
        return -1;

      return this->naming_client_.init (this->orbmgr_.orb ());
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("init");
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

int
Simple_Test::execute (TAO_Naming_Client &root_context)
{
  TAO_TRY
    {
      // Dummy object instantiation.
      My_Test_Object test_obj_impl (CosNaming_Client::OBJ1_ID);
      Test_Object_var test_obj_ref =
        test_obj_impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Bind an object to the Naming Context.
      CosNaming::Name test_name;
      test_name.length (1);
      test_name[0].id = CORBA::string_dup ("Foo");
      root_context->bind (test_name,
                          test_obj_ref.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      ACE_DEBUG ((LM_DEBUG,
                  "Bound name OK\n"));

      // Resolve the object from the Naming Context.
      CORBA::Object_var result_obj_ref =
        root_context->resolve (test_name,
                               TAO_TRY_ENV);
      TAO_CHECK_ENV;
      Test_Object_var result_object =
        Test_Object::_narrow (result_obj_ref.in (),
                              TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (!CORBA::is_nil (result_object.in ())
          && result_object->id (TAO_TRY_ENV) == CosNaming_Client::OBJ1_ID)
        ACE_DEBUG ((LM_DEBUG,
                    "Resolved name OK\n"));
      TAO_CHECK_ENV;

      // Unbind the object from the Naming Context.
      root_context->unbind (test_name,
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
      ACE_DEBUG ((LM_DEBUG,
                  "Unbound name OK\n"));
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Unexpected exception in Simple test");
      return -1;
    }
  TAO_ENDTRY;
  return 0;
}

int
Tree_Test::execute (TAO_Naming_Client &root_context)
{
  TAO_TRY
    {
      // Create a tree of contexts: root->level1->level2.  Bind object
      // foo under context level2.

      // Bind level1 context under root.
      CosNaming::Name level1;
      level1.length (1);
      level1[0].id = CORBA::string_dup ("level1_context");
      CosNaming::NamingContext_var level1_context;
      level1_context = root_context->bind_new_context (level1,
                                                       TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Create a new context.
      CosNaming::NamingContext_var level2_context;
      level2_context = root_context->new_context (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Instantiate a dummy object and bind it under the new context.
      My_Test_Object impl1 (CosNaming_Client::OBJ1_ID);
      Test_Object_var obj1 = impl1._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CosNaming::Name obj_name;
      obj_name.length (1);
      obj_name[0].id = CORBA::string_dup ("foo");
      level2_context->bind (obj_name, obj1.in (),
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Bind the context we just created under level1.
      CosNaming::Name level2 (level1);
      level2.length (2);
      level2[1].id = CORBA::string_dup ("level2_context");
      root_context->bind_context (level2,
                                  level2_context.in (),
                                  TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Resolve and unbind level1/level2/foo, and bind it back.
      CosNaming::Name test_name (level2);
      test_name.length (3);
      test_name[2].id = obj_name[0].id;
      CORBA::Object_var result_obj_ref =
        root_context->resolve (test_name,
                               TAO_TRY_ENV);
      TAO_CHECK_ENV;
      Test_Object_var result_object =
        Test_Object::_narrow (result_obj_ref.in (),
                              TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (CORBA::is_nil (result_object.in ())
          || !(result_object->id (TAO_TRY_ENV) == CosNaming_Client::OBJ1_ID))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Problems with resolving foo in Tree Test\n"),
                          -1);
      TAO_CHECK_ENV;

      // Unbind the object from the Naming Context and bind it back
      // in.
      root_context->unbind (test_name,
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->bind (test_name,
                          obj1.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Create new context and rebind under the name level1/level2.
      CosNaming::NamingContext_var new_level2_context;
      new_level2_context =
        root_context->new_context (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->rebind_context (level2,
                                  new_level2_context.in (),
                                  TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Bind, resolve, rebind, and resolve foo under level1/level2.
      root_context->bind (test_name,
                          obj1.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      result_obj_ref = root_context->resolve (test_name,
                                              TAO_TRY_ENV);
      TAO_CHECK_ENV;
      result_object = Test_Object::_narrow (result_obj_ref.in (),
                                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (CORBA::is_nil (result_object.in ())
          || !(result_object->id (TAO_TRY_ENV) == CosNaming_Client::OBJ1_ID))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Problems in the Tree Test\n"),
                          -1);
      TAO_CHECK_ENV;

      My_Test_Object impl2 (CosNaming_Client::OBJ2_ID);
      Test_Object_var obj2 = impl2._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->rebind (test_name,
                            obj2.in (),
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
      result_obj_ref = root_context->resolve (test_name,
                                              TAO_TRY_ENV);
      TAO_CHECK_ENV;
      result_object = Test_Object::_narrow (result_obj_ref.in (),
                                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (CORBA::is_nil (result_object.in ())
          || !(result_object->id (TAO_TRY_ENV) == CosNaming_Client::OBJ2_ID))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Problems with rebind in Tree Test\n"),
                          -1);
      TAO_CHECK_ENV;
    }

  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Unexpected exception in Tree test");
      return -1;
    }

  TAO_ENDTRY;
  ACE_DEBUG ((LM_DEBUG,
              "All functions work properly \n"));
  return 0;
}

int
Exceptions_Test::execute (TAO_Naming_Client &root_context)
{
  TAO_TRY
    {
      // Set things up.

      // Create a tree of contexts root->level1->level2.
      CosNaming::Name context_name;
      context_name.length (1);
      context_name[0].id = CORBA::string_dup ("level1_context");
      CosNaming::NamingContext_var level1_context;
      level1_context = root_context->bind_new_context (context_name,
                                                       TAO_TRY_ENV);
      TAO_CHECK_ENV;
      context_name[0].id = CORBA::string_dup ("level2_context");
      CosNaming::NamingContext_var level2_context;
      level2_context = level1_context->bind_new_context (context_name,
                                                         TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Bind a dummy object foo under each context.
      My_Test_Object impl;
      Test_Object_var obj = impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CosNaming::Name object_name;
      object_name.length (1);
      object_name[0].id = CORBA::string_dup ("foo");
      root_context->bind (object_name,
                          obj.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      level1_context->bind (object_name,
                            obj.in (),
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
      level2_context->bind (object_name,
                            obj.in (),
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Run exceptions tests.
      invalid_name_test (root_context,
                         TAO_TRY_ENV);
      TAO_CHECK_ENV;
      already_bound_test (root_context,
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      already_bound_test2 (root_context,
                           TAO_TRY_ENV);
      TAO_CHECK_ENV;
      not_found_test (root_context,
                      TAO_TRY_ENV);
      TAO_CHECK_ENV;
      not_found_test2 (root_context,
                       TAO_TRY_ENV);
      TAO_CHECK_ENV;
      not_found_test3 (root_context,
                       TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Unexpected exception in Exceptions test");
      return -1;
    }
  TAO_ENDTRY;
  return 0;
}

void
Exceptions_Test::invalid_name_test (TAO_Naming_Client &root_context,
                                    CORBA::Environment &_env)
{
  TAO_TRY
    {
      CosNaming::Name test_name;
      test_name.length (0);

      root_context->resolve (test_name,
                             TAO_TRY_ENV);
      TAO_CHECK_ENV;
      }

  TAO_CATCH (CosNaming::NamingContext::InvalidName, ex)
    {
      TAO_TRY_ENV.clear ();
      ACE_DEBUG ((LM_DEBUG,
                  "InvalidName exception works properly\n"));
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }
  TAO_ENDTRY;
}

void
Exceptions_Test::already_bound_test (TAO_Naming_Client &root_context,
                                     CORBA::Environment &_env)
{
  TAO_TRY
    {
      CosNaming::Name test_name;
      test_name.length (1);
      test_name[0].id = CORBA::string_dup ("foo");
      My_Test_Object impl;
      Test_Object_var obj = impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->bind (test_name,
                          obj,
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }

  TAO_CATCH (CosNaming::NamingContext::AlreadyBound, ex)
    {
      TAO_TRY_ENV.clear ();
      ACE_DEBUG ((LM_DEBUG,
                  "AlreadyBound exception (case 1) works properly\n"));
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }

  TAO_ENDTRY;
}

void
Exceptions_Test::already_bound_test2 (TAO_Naming_Client &root_context,
                                      CORBA::Environment &_env)
{
  TAO_TRY
    {
      CosNaming::Name test_name;
      test_name.length (2);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("foo");
      My_Test_Object impl;
      Test_Object_var obj = impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->bind (test_name,
                          obj,
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }

  TAO_CATCH (CosNaming::NamingContext::AlreadyBound, ex)
    {
      TAO_TRY_ENV.clear ();
      ACE_DEBUG ((LM_DEBUG,
                  "AlreadyBound  exception (case 2) works properly\n"));
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }
  TAO_ENDTRY;
}

void
Exceptions_Test::not_found_test (TAO_Naming_Client &root_context,
                                 CORBA::Environment &_env)
{
  TAO_TRY
    {
      CosNaming::Name test_name;
      test_name.length (3);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("level2_context");
      test_name[2].id = CORBA::string_dup ("bar");

      root_context->unbind (test_name,
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }

  TAO_CATCH (CosNaming::NamingContext::NotFound, ex)
    {
      if (ex.why == CosNaming::NamingContext::not_object &&
          ex.rest_of_name.length () == 1
          && ACE_OS::strcmp (ex.rest_of_name[0].id.in (),
                             "bar") == 0)
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 1) works properly\n"));
      else
        ACE_DEBUG ((LM_DEBUG,
                    "NotFound  exception (case 1)"
                    " - parameters aren't set correctly\n"));
      TAO_TRY_ENV.clear ();
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }
  TAO_ENDTRY;
}

void
Exceptions_Test::not_found_test2 (TAO_Naming_Client &root_context,
                                  CORBA::Environment &_env)
{
  TAO_TRY
    {
      CosNaming::Name test_name;
      test_name.length (3);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("level3_context");
      test_name[2].id = CORBA::string_dup ("foo");

      root_context->unbind (test_name,
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }

  TAO_CATCH (CosNaming::NamingContext::NotFound, ex)
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
      TAO_TRY_ENV.clear ();
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }

  TAO_ENDTRY;
}

void
Exceptions_Test::not_found_test3 (TAO_Naming_Client &root_context,
                                  CORBA::Environment &_env)
{
  TAO_TRY
    {
      CosNaming::Name test_name;
      test_name.length (3);
      test_name[0].id = CORBA::string_dup ("level1_context");
      test_name[1].id = CORBA::string_dup ("foo");
      test_name[2].id = CORBA::string_dup ("foo");

      root_context->unbind (test_name, TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }

  TAO_CATCH (CosNaming::NamingContext::NotFound, ex)
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
      TAO_TRY_ENV.clear ();
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }
  TAO_ENDTRY;
}

int
Iterator_Test::execute (TAO_Naming_Client &root_context)
{
  TAO_TRY
    {
      // Instantiate four dummy objects.
      My_Test_Object impl1;
      Test_Object_var obj1 = impl1._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      My_Test_Object impl2;
      Test_Object_var obj2 = impl2._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      My_Test_Object impl3;
      Test_Object_var obj3 = impl3._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      My_Test_Object impl4;
      Test_Object_var obj4 = impl4._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

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
                          obj1.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->bind (name2,
                          obj2.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->bind (name3,
                          obj3.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      root_context->bind (name4,
                          obj4.in (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // List the content of the Naming Context.
      CosNaming::BindingIterator_var iter;
      CosNaming::BindingList_var bindings_list;
      root_context->list (1,
                          bindings_list.out (),
                          iter.out (),
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (CORBA::is_nil (iter.in ())
          || bindings_list->length () != 1
          || bindings_list[0].binding_type != CosNaming::nobject)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::list does not function properly\n"),
                          -1);
      ACE_DEBUG ((LM_DEBUG,
                  "First binding: %s\n",
                  bindings_list[0].binding_name[0].id.in ()));

      // Invoke operations on the iterator.
      CosNaming::Binding_var binding;
      iter->next_one (binding.out (),
                      TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (binding->binding_type != CosNaming::nobject)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::next_one does not function properly\n"),
                          -1);
      ACE_DEBUG ((LM_DEBUG,
                  "Second binding: %s\n",
                  binding->binding_name[0].id.in ()));

      iter->next_n (2, bindings_list.out (), TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (bindings_list->length () != 2
          || bindings_list[0].binding_type != CosNaming::nobject
          || bindings_list[1].binding_type != CosNaming::nobject)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::BindingIterator does not function properly\n"),
                          -1);
      ACE_DEBUG ((LM_DEBUG,
                  "Third binding: %s\n"
                  "Fourth binding: %s\n",
                  bindings_list[0].binding_name[0].id.in (),
                  bindings_list[1].binding_name[0].id.in ()));

      // We already iterated over all the bindings, so the following
      // should return false.
      CORBA::Boolean result = iter->next_one (binding.out (),
                                              TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (result)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "CosNaming::BindingIterator does not function properly\n"),
                          -1);
      iter->destroy (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Unexpected exception in Iterator test");
      return -1;
    }
  TAO_ENDTRY;
  return 0;
}

int
Destroy_Test::execute (TAO_Naming_Client &root_context)
{
  TAO_TRY
    {
      // Create a context and bind an object under it.

      CosNaming::NamingContext_var my_context;
      my_context = root_context->new_context (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Bind a dummy object foo under my_context.
      My_Test_Object impl;
      Test_Object_var obj = impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CosNaming::Name object_name;
      object_name.length (1);
      object_name[0].id = CORBA::string_dup ("foo");
      my_context->bind (object_name,
                            obj.in (),
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Do the testing.
      not_empty_test (my_context,
                         TAO_TRY_ENV);
      TAO_CHECK_ENV;

      my_context->unbind (object_name, TAO_TRY_ENV);
      TAO_CHECK_ENV;
      my_context->destroy (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      not_exist_test (my_context,
                         TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Unexpected exception in Exceptions test");
      return -1;
    }
  TAO_ENDTRY;
  return 0;
}

void
Destroy_Test::not_empty_test (CosNaming::NamingContext_var &ref,
                                    CORBA::Environment &_env)
{
  TAO_TRY
    {
      ref->destroy (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }

  TAO_CATCH (CosNaming::NamingContext::NotEmpty, ex)
    {
      TAO_TRY_ENV.clear ();
      ACE_DEBUG ((LM_DEBUG,
                  "NotEmpty exception works properly\n"));
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }
  TAO_ENDTRY;
}

void
Destroy_Test::not_exist_test (CosNaming::NamingContext_var &ref,
                                    CORBA::Environment &_env)
{
  TAO_TRY
    {
      ref->destroy (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }

  TAO_CATCH (CORBA::OBJECT_NOT_EXIST, ex)
    {
      TAO_TRY_ENV.clear ();
      ACE_DEBUG ((LM_DEBUG,
                  "Destroy works properly\n"));
    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }
  TAO_ENDTRY;
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
