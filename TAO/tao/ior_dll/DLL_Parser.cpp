// $Id$

#include "DLL_Parser.h"
#include "Object_Loader.h"
#include "tao/Object.h"
#include "tao/Exception.h"
#include "tao/Environment.h"
#include "ace/Dynamic_Service.h"

#if !defined(__ACE_INLINE__)
#include "DLL_Parser.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(tao, DLL_Parser, "$Id$")

TAO_DLL_Parser::~TAO_DLL_Parser (void)
{
}

static const char dll_prefix[] = "DLL:";

int
TAO_DLL_Parser::match_prefix (const char *ior_string) const
{
  return (ACE_OS::strncmp (ior_string,
                           dll_prefix,
                           sizeof dll_prefix - 1) == 0);
}

CORBA::Object_ptr
TAO_DLL_Parser::parse_string (const char *ior,
                              CORBA::ORB_ptr orb,
                              CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Skip the prefix, we know it is there because this method in only
  // called if <match_prefix> returns 1.
  const char *name =
    ior + sizeof dll_prefix - 1;

  TAO_Object_Loader *loader =
    ACE_Dynamic_Service<TAO_Object_Loader>::instance (name);

  if (loader == 0)
    {
      ACE_THROW_RETURN
        (CORBA::INV_OBJREF
         (CORBA_SystemException::_tao_minor_code (
            TAO_DEFAULT_MINOR_CODE,
            EINVAL),
          CORBA::COMPLETED_NO),
         CORBA::Object::_nil ());
    }

  return loader->create_object (orb, ACE_TRY_ENV);
}

ACE_FACTORY_DEFINE (TAO_IOR_DLL, TAO_DLL_Parser)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
