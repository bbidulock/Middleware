// $Id$

#include "Policy_Validator.h"
#include "Environment.h"
#include "debug.h"

#include "ace/Log_Msg.h"

ACE_RCSID (tao,
           Policy_Validator,
           "$Id$")

TAO_Policy_Validator::TAO_Policy_Validator (TAO_ORB_Core &orb_core)
  : orb_core_ (orb_core),
    next_ (0)
{
  // No-Op.
}

TAO_Policy_Validator::~TAO_Policy_Validator (void)
{
  if (this->next_)
    {
      delete this->next_;
    }
}

void
TAO_Policy_Validator::add_validator (TAO_Policy_Validator *validator)
{
  // The validator we're adding can't be part of another list
  ACE_ASSERT (validator->next_ == 0);

  // Why would we want to add ourself to our list 
  if (this != validator)
    {
      // Get to the end of the list and make sure that the
      // new validator isn't already part of our list
      TAO_Policy_Validator* current = this;
      while (current->next_ != 0)
        {                        
          if (current->next_ == validator)
            {
              if (TAO_debug_level > 3)
                ACE_DEBUG ((LM_DEBUG,
                            ACE_LIB_TEXT ("(%P|%t) Skipping validator [0x%x] ")
                            ACE_LIB_TEXT ("since it would create a circular list\n"),
                            validator));

              return;
            }
          current = current->next_;
        }

      // Add the new validator to the end of the list
      current->next_ = validator;
    }
}


void
TAO_Policy_Validator::validate (TAO_Policy_Set &policies
                                ACE_ENV_ARG_DECL)
{
  this->validate_impl (policies ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (this->next_ != 0)
    {
      this->next_->validate (policies ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void
TAO_Policy_Validator::merge_policies (TAO_Policy_Set &policies
                                      ACE_ENV_ARG_DECL)
{
  this->merge_policies_impl (policies ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (this->next_ != 0)
    {
      this->next_->merge_policies (policies ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

CORBA::Boolean
TAO_Policy_Validator::legal_policy (CORBA::PolicyType type)
{
  return (this->legal_policy_impl (type) 
          || ((this->next_ != 0) 
              && this->next_->legal_policy_impl (type)));
}
