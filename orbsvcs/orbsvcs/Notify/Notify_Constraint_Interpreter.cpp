// $Id$

#include "Notify_Constraint_Interpreter.h"
#include "Notify_Constraint_Visitors.h"

TAO_Notify_Constraint_Interpreter::TAO_Notify_Constraint_Interpreter(void)
{
}

TAO_Notify_Constraint_Interpreter::~TAO_Notify_Constraint_Interpreter (void)
{
}

void
TAO_Notify_Constraint_Interpreter::build_tree (const char* constraints,
                                            CORBA::Environment& ACE_TRY_ENV)
  ACE_THROW_SPEC ((CosNotifyFilter::InvalidConstraint,
                   CORBA::NO_MEMORY))
{
  if (TAO_Interpreter::is_empty_string (constraints))
    {
      // root is deleted in the TAO_Interpreter's destructor.
      ACE_NEW_THROW_EX (this->root_,
                        TAO_Literal_Constraint ((CORBA::Boolean) 1),
                        CORBA::NO_MEMORY ());
      ACE_CHECK;
    }
  else
    {
      if (TAO_Interpreter::build_tree (constraints) != 0)
          ACE_THROW (CosNotifyFilter::InvalidConstraint ());
    }
}

CORBA::Boolean
TAO_Notify_Constraint_Interpreter::evaluate (TAO_Constraint_Evaluator& evaluator)
{
  return evaluator.evaluate_constraint (this->root_);
}
