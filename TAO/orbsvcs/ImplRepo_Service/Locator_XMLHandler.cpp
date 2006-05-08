// $Id$

#include "Locator_XMLHandler.h"
#include "ace/OS_NS_strings.h"

ACE_RCSID (ImplRepo_Service,Locator_XMLHandler,"$Id$")

  const ACE_TCHAR* Locator_XMLHandler::ROOT_TAG = ACE_TEXT("ImplementationRepository");
const ACE_TCHAR* Locator_XMLHandler::SERVER_INFO_TAG = ACE_TEXT("Servers");
const ACE_TCHAR* Locator_XMLHandler::ACTIVATOR_INFO_TAG = ACE_TEXT("Activators");
const ACE_TCHAR* Locator_XMLHandler::ENVIRONMENT_TAG = ACE_TEXT("EnvironmentVariables");

Locator_XMLHandler::Locator_XMLHandler (Callback& cb)
  : callback_ (cb)
{
}

void
Locator_XMLHandler::startElement (const ACEXML_Char*,
                                  const ACEXML_Char*,
                                  const ACEXML_Char* qName,
                                  ACEXML_Attributes* attrs ACEXML_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACE_ASSERT (qName != 0);
  if (ACE_OS::strcasecmp (qName, SERVER_INFO_TAG) == 0)
    {
      // We'll use this as a key to determine if we've got a valid record
      this->server_name_ = "";
      this->env_vars_.clear();

      if (attrs != 0 && attrs->getLength () == 8)
        {
          this->server_name_.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)0)));
          this->activator_name_.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)1)));
          this->command_line_.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)2)));
          this->working_dir_.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)3)));
          this->activation_.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)4)));

          this->env_vars_.clear();

          int limit = ACE_OS::atoi (attrs->getValue((size_t)5));
          this->start_limit_ = limit;
          this->partial_ior_.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)6)));
          this->server_object_ior_.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)7)));
        }
    }
  else if (ACE_OS::strcasecmp (qName, ACTIVATOR_INFO_TAG) == 0)
    {
      if (attrs != 0 && attrs->getLength () == 3)
        {
          ACE_CString aname (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)0)));
          ACE_CString token_str (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)1)));
          long token = ACE_OS::atoi (token_str.c_str());
          ACE_CString ior (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)2)));
          this->callback_.next_activator(aname, token, ior);
        }
    }
  else if (ACE_OS::strcasecmp (qName, ENVIRONMENT_TAG) == 0)
    {
      if (attrs != 0 && attrs->getLength() == 2)
        {
          EnvVar ev;
          ev.name.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)0)));
          ev.value.set (ACE_TEXT_TO_CHAR_IN (attrs->getValue((size_t)1)));
          this->env_vars_.push_back(ev);
        }
    }
}

void
Locator_XMLHandler::endElement (const ACEXML_Char*,
                                const ACEXML_Char*,
                                const ACEXML_Char* qName ACEXML_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACE_ASSERT(qName != 0);
  if (ACE_OS::strcasecmp (qName, SERVER_INFO_TAG) == 0
      && this->server_name_.length () > 0)
    {
      this->callback_.next_server (this->server_name_,
                                   this->activator_name_, this->command_line_,
                                   this->env_vars_, this->working_dir_, this->activation_,
                                   this->start_limit_, this->partial_ior_, this->server_object_ior_);
    }
  // activator info is handled in the startElement
}

bool
Locator_XMLHandler::EnvVar::operator== (const EnvVar& rhs) const
{
  return name == rhs.name && value == rhs.value;
}
bool
Locator_XMLHandler::EnvVar::operator!= (const EnvVar& rhs) const
{
  return ! (rhs == *this);
}
