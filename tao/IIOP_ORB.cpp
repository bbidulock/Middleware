// $Id$
//
// @(#)iioporb.cpp      1.8 95/09/19
// Copyright 1994-1995 by Sun Microsystems Inc.
// All Rights Reserved
//
// IIOP:                ORB pseudo-object
//
// This includes objref stringification/destringification for IIOP
// object references.

#include "tao/IIOP_ORB.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Stub.h"
#include "tao/IIOP_Profile.h"
#include "tao/GIOP.h"
#include "tao/POA.h"
#include "tao/ORB_Core.h"

#if !defined (__ACE_INLINE__)
# include "tao/IIOP_ORB.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(tao, IIOP_ORB, "$Id$")

static const char ior_prefix [] = "IOR:";

// Objref stringification.

CORBA::String
IIOP_ORB::object_to_string (CORBA::Object_ptr obj,
                            CORBA::Environment &env)
{
  env.clear ();

  // Application writer controls what kind of objref strings they get,
  // maybe along with other things, by how they initialize the ORB.

  if (use_omg_ior_format_)
    {
      // By default, orbs use IOR strings; these are ugly (and error
      // prone) but specified by CORBA.
      //
      // XXX there should be a simple way to reuse this code in other
      // ORB implementations ...

      // @@ Is BUFSIZ the right size here?
      char buf [BUFSIZ];
      TAO_OutputCDR cdr (buf,
                         sizeof buf,
                         TAO_ENCAP_BYTE_ORDER);

      // support limited oref ACE_OS::strcmp.
      (void) ACE_OS::memset (buf, 0, BUFSIZ);

      // Marshal the objref into an encapsulation bytestream.
      (void) cdr.write_octet (TAO_ENCAP_BYTE_ORDER);
      if (cdr.encode (CORBA::_tc_Object,
                        &obj, 0,
                        env) != CORBA::TypeCode::TRAVERSE_CONTINUE)
        return 0;

      // Now hexify the encapsulated CDR data into a string, and
      // return that string.

      CORBA::String cp;
      size_t len = cdr.length ();

      CORBA::String string;
      ACE_ALLOCATOR_RETURN (string,
                            CORBA::string_alloc (sizeof ior_prefix + 2 * len),
                            0);

      ACE_OS::strcpy ((char *) string,
                      ior_prefix);

      const char *bytes = cdr.buffer ();

      for (cp = (CORBA::String) ACE_OS::strchr ((char *) string, ':') + 1;
           len--;
           bytes++)
        {
          *cp++ = ACE::nibble2hex ((*bytes) >> 4);
          *cp++ = ACE::nibble2hex (*bytes);
        }

      *cp = 0;
      return string;
    }
  else
    {
      // The "internet" ORB uses readable URL style objrefs, as used
      // in the World Wide Web.
      //
      // This only works for IIOP objrefs.  If we're handed an objref
      // that's not an IIOP objref, fail -- application must use an
      // ORB that's configured differently.  @@ Is this true? FRED

      if (obj->_stubobj () == 0)
        return CORBA::string_copy ((CORBA::String) TAO_IIOP_Profile::prefix ());
        // @@ This should be some sort of default prefix, not
        // hardcoded to IIOP!! FRED

      CORBA::String buf =
        obj->_stubobj ()->profile_in_use ()->to_string (env);
      return buf;
    }
}

// Destringify OMG-specified "IOR" string.
//
// XXX there should be a simple way to reuse this code in other ORB
// implementations ...

static CORBA::Object_ptr
ior_string_to_object (const char *str,
                      CORBA::Environment &env)
{
  // Unhex the bytes, and make a CDR deencapsulation stream from the
  // resulting data.
  ACE_Message_Block mb (ACE_OS::strlen ((char *) str) / 2
                        + 1 + CDR::MAX_ALIGNMENT);

  CDR::mb_align (&mb);

  char *buffer = mb.rd_ptr ();

  const char *tmp = str;
  size_t len = 0;

  while (tmp [0] && tmp [1])
    {
      u_char byte;

      if (!(isxdigit (tmp [0]) && isxdigit (tmp [1])))
        break;

      byte = (u_char) (ACE::hex2byte (tmp [0]) << 4);
      byte |= ACE::hex2byte (tmp [1]);

      buffer [len++] = byte;
      tmp += 2;
    }

  if (tmp [0] && !isspace (tmp [0]))
    {
      env.exception (new CORBA::BAD_PARAM (CORBA::COMPLETED_NO));
      return CORBA::Object::_nil ();
    }

  // Create deencapsulation stream ... then unmarshal objref from that
  // stream.

  int byte_order = *(mb.rd_ptr ());
  mb.rd_ptr (1);
  mb.wr_ptr (len);
  TAO_InputCDR stream (&mb, byte_order);

  CORBA::Object_ptr objref=0;
  if (stream.decode (CORBA::_tc_Object,
		     &objref, 0,
		     env) != CORBA::TypeCode::TRAVERSE_CONTINUE)
    objref = 0;

  return objref;
}

// Destringify URL style IIOP objref.

// @@ Fred, can you please put this into a class as a static method
// rather than having it floating around as a stand-alone function?
static CORBA::Object_ptr
iiop_string_to_object (const char *string,
                       CORBA::Environment &env)
{
  // NIL objref encodes as just "iiop:" ... which has already been
  // removed, so we see it as an empty string.

  if (!string || !*string)
    return CORBA::Object::_nil ();

  // type ID not encoded in this string ... makes narrowing rather
  // expensive, though it does ensure that type-safe narrowing code
  // gets thoroughly excercised/debugged!  Without a typeID, the
  // _narrow will be required to make an expensive remote "is_a" call.

  TAO_IIOP_Profile *pfile;

  ACE_NEW_RETURN (pfile,
                  TAO_IIOP_Profile (string,
                                    env),
                  CORBA::Object::_nil ());
  // pfile refcount == 1

  // Now make the STUB_Object ...
  STUB_Object *data;
  ACE_NEW_RETURN (data,
                  STUB_Object ((char *) 0,
                               pfile),
                  CORBA::Object::_nil ());
  // pfile refcount == 2

  pfile->_decr_refcnt ();
  // pfile refcount == 1

  // Create the CORBA level proxy.
  TAO_ServantBase *servant =
    TAO_ORB_Core_instance ()->orb ()->_get_collocated_servant (data);

  // This will increase the ref_count on data by one
  CORBA_Object *obj;
  ACE_NEW_RETURN (obj,
                  CORBA_Object (data,
                                servant,
                                servant != 0),
                  CORBA::Object::_nil ());

  // Set the ref_count on data to 1, which is correct, because only
  // obj has now a reference to it.
  // data->_decr_refcnt ();

  return obj;
}

// Destringify arbitrary objrefs.  called from resolve_name_service ()
// with an IOR multicast_to_service ().
CORBA::Object_ptr
IIOP_ORB::string_to_object (const char *str,
                            CORBA::Environment &env)
{
  env.clear ();

  CORBA::Object_ptr obj = 0;

  // Use the prefix code to choose which destringify algorithm to use.
  const size_t iiop_prefix_len =
    ACE_OS::strlen (TAO_IIOP_Profile::prefix ());
  if (ACE_OS::strncmp (str,
                       TAO_IIOP_Profile::prefix (),
                       iiop_prefix_len) == 0)
    obj = iiop_string_to_object (str + iiop_prefix_len, env);

  else if (ACE_OS::strncmp (str,
                            ior_prefix,
                            sizeof ior_prefix - 1) == 0)
    obj = ior_string_to_object (str + sizeof ior_prefix - 1, env);

  // Return the object.
  return obj;
}

TAO_ServantBase *
IIOP_ORB::_get_collocated_servant (STUB_Object *sobj)
{
  // ACE_DEBUG ((LM_DEBUG, "IIOP_ORB: get_collocated_servant\n"));

  if (this->optimize_collocation_objects_ && sobj != 0)
    {

      TAO_Profile *pfile = sobj->profile_in_use ();

      // Make sure users passed in a valid STUB_Object otherwise, we
      // don't know what to do next.
      if (pfile == 0)
        {
          // @@ Fred, can you please either keep these debugging
          // statements in or remove them, but please don't leave the
          // #if 0's around!
#if 0
          ACE_ERROR ((LM_ERROR,
		      "%p: Passing IIOP ORB and non-IIOP object\n",
		      "_get_collocated_object"));
#endif
	  // Something must be wrong!
          return 0;
        }
#if 0
      ACE_DEBUG ((LM_DEBUG,
                  "IIOP_ORB: checking collocation for <%s>\n",
                  pfile->addr_to_string ()));
#endif

      CORBA::Environment env;
      TAO_ObjectKey_var objkey = pfile->_key (env);

      if (env.exception ())
        {
#if 0
          ACE_DEBUG ((LM_DEBUG,
                      "IIOP_ORB: cannot find key for <%s>\n",
                      pfile->addr_to_string ()));
#endif
          return 0;
        }

      // Check if the object requested is a collocated object.
      // @@ FRED - can we make this more generic!!
      TAO_POA *poa = 0;
      if (pfile->tag () == TAO_IOP_TAG_INTERNET_IOP)
        {
          ACE_INET_Addr &addr =
            ACE_dynamic_cast (ACE_INET_Addr &,
                              pfile->object_addr());

          poa = TAO_ORB_Core_instance ()->get_collocated_poa (addr);
        }
      else
        ACE_ERROR ((LM_ERROR,
                    "get_collocated_poa NOT Supported for NON-IIOP profile!\n"));

      if (poa != 0)
        {
          PortableServer::Servant servant =
            poa->find_servant (objkey.in (), env);
          if (env.exception ())
            {
#if 0
              ACE_DEBUG ((LM_DEBUG,
                          "IIOP_ORB: cannot find servant for <%s>\n",
                          pfile->addr_to_string ()));
#endif
              return 0;
            }

#if 0
          ACE_DEBUG ((LM_DEBUG,
                      "IIOP_ORB: object at <%s> is collocated\n",
                      pfile->addr_to_string ()));
#endif
          return servant;
        }
    }

#if 0
  ACE_DEBUG ((LM_DEBUG,
	      "IIOP_ORB: collocation failed for \n"));
#endif

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Singleton<IIOP_ORB, ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Unbounded_Set<ACE_INET_Addr>;
template class ACE_Unbounded_Set_Iterator<ACE_INET_Addr>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Singleton<IIOP_ORB, ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Unbounded_Set<ACE_INET_Addr>
#pragma instantiate ACE_Unbounded_Set_Iterator<ACE_INET_Addr>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
