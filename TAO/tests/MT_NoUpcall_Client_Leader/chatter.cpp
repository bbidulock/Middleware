#include "SharedIntf_i.h"
#include "worker.h"
#include "chatter.h"

Chatter::Chatter (CORBA::ORB_ptr orb, const char *ior, ACE_Condition<ACE_Mutex>& cond)
	: Worker (orb),
        nrequests_ (0),
        nreplies_ (0),
	ior_ (ior),
        cond_ (cond)
{
}

long
Chatter::nreplies (void)
{
  return this->nreplies_;
}

long
Chatter::nrequests (void)
{
  return this->nrequests_;
}

int 
Chatter::svc (void)
{
  long nrq = nrequests ();
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
  {
     //sleep(1);

     // get server ior from file
     CORBA::Object_var rawObject = orb_->string_to_object( ior_.in () ACE_ENV_ARG_PARAMETER);
     ACE_TRY_CHECK;
     
     Test_Idl::SharedIntf_var intf_var = 
        Test_Idl::SharedIntf::_narrow(rawObject.in() ACE_ENV_ARG_PARAMETER);
     ACE_TRY_CHECK;
     
     if (CORBA::is_nil (intf_var.in ()))
       ACE_ERROR_RETURN ((LM_ERROR, "Nil reference <%s>\n", ior_.in()), -1);

     // make call on server
     ACE_DEBUG((LM_INFO,"(%P|%t) Chatter[%d] started for %s\n", nrq, ior_.in ()));
     nrequests_++;
     intf_var->ping(ACE_ENV_SINGLE_ARG_PARAMETER);
     nreplies_++;
     ACE_TRY_CHECK;

     ACE_DEBUG((LM_INFO,"(%P|%t) Chatter[%d] completed for %s\n", nrq, ior_.in ()));
     cond_.signal();
     return 0;
   }
   ACE_CATCHANY
   {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Exception caught:");
      ACE_DEBUG((LM_INFO,"(%P|%t) Chatter[%d] %p for %s\n", nrq, "failed", ior_.in ()));
   }
   ACE_ENDTRY;
   return -1;
}

int 
Chatter::farewell (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_TRY
  {
     ACE_DEBUG((LM_INFO,"(%P|%t) Farewell requested for %s\n", ior_.in ()));

     // get server ior from file
     CORBA::Object_var rawObject = orb_->string_to_object( ior_.in () ACE_ENV_ARG_PARAMETER);
     ACE_TRY_CHECK;
     
     Test_Idl::SharedIntf_var intf_var = 
        Test_Idl::SharedIntf::_narrow(rawObject.in() ACE_ENV_ARG_PARAMETER);
     ACE_TRY_CHECK;
     
     if (CORBA::is_nil (intf_var.in ()))
       ACE_ERROR_RETURN ((LM_ERROR, "Nil reference <%s>\n", ior_.in()), -1);

     // make call on server
     ACE_DEBUG((LM_INFO,"(%P|%t) farewell START for %s\n", ior_.in ()));
      intf_var->farewell(ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_DEBUG((LM_INFO,"(%P|%t) farewell COMPLETE for %s\n", ior_.in ()));
   }
   ACE_CATCHANY
   {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Exception caught:");
      ACE_DEBUG((LM_INFO,"(%P|%t) %p for %s\n", "farewell FAILED", ior_.in ()));
   }
   ACE_ENDTRY;
   return 0;
}


