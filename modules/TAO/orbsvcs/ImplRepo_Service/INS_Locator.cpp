//=============================================================================
/**
*  @file   INS_Locator.cpp
*
*  $Id$
*
*  @brief  Implementation of the ImR's INS Locator class
*
*  @author Darrell Brunsch <brunsch@cs.wustl.edu>
*/
//=============================================================================

#include "INS_Locator.h"
#include "ImR_Locator_i.h"
#include "tao/ORB_Constants.h"

INS_Locator::INS_Locator (ImR_Locator_i& loc)
: imr_locator_ (loc)
{
}

char *
INS_Locator::locate (const char* object_key ACE_ENV_ARG_DECL)
ACE_THROW_SPEC ((CORBA::SystemException, IORTable::NotFound))
{
  ACE_ASSERT (object_key != 0);
  ACE_TRY
    {
      ACE_CString key (object_key);
      ssize_t poaidx = key.find ('/');
      if (poaidx >= 0)
      {
        key = key.substring (0, poaidx);
      }

      if (imr_locator_.debug () > 1)
        ACE_DEBUG ((LM_DEBUG, "ImR: Activating server <%s>.\n", key.c_str ()));

      CORBA::String_var located =
        this->imr_locator_.activate_server_by_object (key.c_str () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_CString tmp = located.in ();
      tmp += object_key;

      if (imr_locator_.debug () > 0)
        ACE_DEBUG ((LM_DEBUG, "ImR: Forwarding invocation on <%s> to <%s>\n", key.c_str (), tmp.c_str()));

      return CORBA::string_dup (tmp.c_str ());
    }
  ACE_CATCH (ImplementationRepository::CannotActivate, ex)
    {
      ACE_TRY_THROW (CORBA::TRANSIENT (
        CORBA::SystemException::_tao_minor_code (TAO_IMPLREPO_MINOR_CODE, 0),
        CORBA::COMPLETED_NO));
    }
  ACE_CATCH (ImplementationRepository::NotFound, ex)
    {
      ACE_TRY_THROW (CORBA::TRANSIENT (
        CORBA::SystemException::_tao_minor_code (TAO_IMPLREPO_MINOR_CODE, 0),
        CORBA::COMPLETED_NO));
    }
  ACE_ENDTRY;
}
