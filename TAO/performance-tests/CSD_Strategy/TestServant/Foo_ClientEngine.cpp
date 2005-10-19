// $Id$
#include "Foo_ClientEngine.h"
#include "Foo_Statistics.h"
#include "TestInf/TestAppExceptionC.h"
#include "TestInf/AppHelper.h"
#include "ace/Log_Msg.h"


Foo_ClientEngine::Foo_ClientEngine(Foo_ptr obj, unsigned client_id)
  : obj_(Foo::_duplicate(obj)),
    client_id_(client_id)
{
}


Foo_ClientEngine::~Foo_ClientEngine()
{
}


bool
Foo_ClientEngine::execute(unsigned num_loops ACE_ENV_ARG_DECL)
{
  // Make sure the connection is established before making  
  // remote invocations.
  if (AppHelper::validate_connection(this->obj_.in()) == false)
    {
      ACE_ERROR((LM_ERROR,
                 "(%P|%t)Foo_ClientEngine::execute - "
                 "client %d connect failed.\n", this->client_id_));
      return false;
    }

  // Verify the return values and return the results.
  bool success = true;

  for (unsigned loop = 0; loop < num_loops; loop++)
    {
      CORBA::Long i = this->client_id_;

      this->obj_->op1(ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (false);
      this->obj_->op2(i ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (false);

      CORBA::Long value = this->obj_->op3(i ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (false);
      success = (value != i) ? false : success;

      for (CORBA::Long j = 1; j <= 5; j++)
        {
          this->obj_->op4(495 + (i * 5) + j ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (false);
        }

      bool caught_exception = false;

      ACE_TRY_NEW_ENV
      {
        this->obj_->op5(ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }
      ACE_CATCH (FooException, ex)
      {
        // Expected
        caught_exception = true;
      }
      ACE_ENDTRY;

      success = (!caught_exception) ? false : success;
    }

  this->obj_->done(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (false);
  return success;
}


void
Foo_ClientEngine::expected_results(Foo_Statistics& stats)
{
  stats.expected(1, 1);
  stats.expected(2, 1);
  stats.expected(3, 1);
  stats.expected(4, 0);
  stats.expected(4, 5);
  stats.expected(5, 1);
}
