// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#include <sstream>
#include <ace/High_Res_Timer.h>
#include "FTTask_exec.h"
#include "FTTask_svnt.h"
#include "ciao/CIAO_common.h"
#include "ciao/Containers/Container_Base.h"
#include "ciao/FTComponentServer/Name_Helper_T.h"
#include "orbsvcs/orbsvcs/LWFT/StateSynchronizationAgentC.h"
#include "orbsvcs/orbsvcs/LWFT/ReplicationManagerC.h"

namespace CIDL_FTTask_Impl
{
  //==================================================================
  // Component Executor Implementation Class:   FTTask_exec_i
  //==================================================================

  FTTask_exec_i::FTTask_exec_i (void)
    : orb_ (CORBA::ORB::_nil ()),
      agent_ (StateSynchronizationAgent::_nil ()),
      context_ (DeCoRAM::CCM_FTTask_Context::_nil ()),
      myself_ (CORBA::Object::_nil ()),
      object_id_ ("Fault Tolerant Task"),
      load_ (30),
      primary_ (true),
      state_ (0)
  {
    CIAO_TRACE ("FTTask_exec_i::FTTask_exec_i (void)");
  }

  FTTask_exec_i::~FTTask_exec_i (void)
  {
    CIAO_TRACE ("FTTask_exec_i::~FTTask_exec_i (void)");
  }

  // Supported or inherited operations.

  void
  FTTask_exec_i::run_task (
    ::CORBA::Double execution_time)
  {
    ACE_hrtime_t start, end;

    std::cerr << object_id_ << "@" << this->get_process_id () << " ";

    start = ACE_OS::gethrtime ();    

    this->cpu_.run (static_cast <size_t> (execution_time));

    end = ACE_OS::gethrtime ();

    ++state_;

    agent_->state_changed (object_id_.c_str ());

    CIAO_DEBUG ((LM_INFO, 
                 ACE_TEXT ("Task %s #%d: start=%Tu end=%T time=%d ms\n"),
                 object_id_.c_str (),
                 state_,
                 start,
                 end,
                 end - start));
  }

  void 
  FTTask_exec_i::stop (void)
  {
    ACE_OS::exit (1);
  }

  void
  FTTask_exec_i::set_state (
    const ::CORBA::Any & state_value)
  {
    // extract value to an intermediate long variable since it's not possible
    // to extract to a long & directly
    CORBA::Long value;

    if (state_value >>= value)
      state_ = value;
    else
      CIAO_DEBUG ((LM_WARNING,
		  "FTTask_exec_i::set_state () "
		  "could not extract state value from Any."));

    CIAO_DEBUG ((LM_TRACE, "FTTask_exec_i::set_state (%d) called.\n", value));
  }

  ::CORBA::Any *
  FTTask_exec_i::get_state ()
  {
    // create new any object
    CORBA::Any_var state (new CORBA::Any);

    // create intermediate object with the value
    CORBA::Long value = state_;

    ACE_DEBUG ((LM_INFO, "FTTask_exec_i::get_state returns %d.\n", value));

    // insert value into the any object
    *state <<= value;

    return state._retn ();
  }

  ::StateSynchronizationAgent_ptr
  FTTask_exec_i::agent ()
  {
    CIAO_TRACE ("FTTask_exec_i::agent () getter");
    return StateSynchronizationAgent::_duplicate (agent_.in ());
  }

  void
  FTTask_exec_i::agent (::StateSynchronizationAgent_ptr agent)
  {
    CIAO_TRACE ("FTTask_exec_i::agent () setter");
    agent_ = agent;
  }

  char *
  FTTask_exec_i::object_id (void)
  {
    CIAO_TRACE ("FTTask_exec_i::object_id () getter");
    return CORBA::string_dup (object_id_.c_str ());
  }

  void
  FTTask_exec_i::object_id (const char * object_id)
  {
    CIAO_TRACE ("FTTask_exec_i::object_id () setter");    
    object_id_ = object_id;
  }

  // Attribute operations.

  ::CORBA::Object_ptr
  FTTask_exec_i::COMPONENT_REFERENCE ()
  {
    CIAO_TRACE ("FTTask_exec_i::COMPONENT_REFERENCE () getter");
    return CORBA::Object::_duplicate (myself_.in ());
  }

  void
  FTTask_exec_i::COMPONENT_REFERENCE (::CORBA::Object_ptr COMPONENT_REFERENCE)
  {
    CIAO_TRACE ("FTTask_exec_i::COMPONENT_REFERENCE () setter");
    myself_ = CORBA::Object::_duplicate (COMPONENT_REFERENCE);
  }

  CORBA::Double
  FTTask_exec_i::load ()
  {
    return load_;
  }
    
  void
  FTTask_exec_i::load (CORBA::Double load)
  {
    CIAO_DEBUG ((LM_DEBUG, "FTTask_exec_i::load (%d)\n", load));
    load_ = load;
  }

  ::CORBA::Short
  FTTask_exec_i::role ()
  {
    CIAO_DEBUG ((LM_DEBUG, "FTTask_exec_i::role () getter\n"));
    if (primary_)
      return 1;
    else
      return 2;
  }

  void
  FTTask_exec_i::role (::CORBA::Short role)
  {
    CIAO_DEBUG ((LM_DEBUG, "FTTask_exec_i::role (%d)\n", role));
    if (role == 1)
      primary_ = true;
    else
      primary_ = false;
  }

  // Port operations.

  // Operations from Components::SessionComponent

  void
  FTTask_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::DeCoRAM::CCM_FTTask_Context::_narrow (ctx);

    if (CORBA::is_nil (this->context_.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }

    CIDL_FTTask_Impl::FTTask_Context * ft_context = 
      CIDL_FTTask_Impl::FTTask_Context::_narrow (context_.in ());

    if (0 == ft_context)
      {
	CIAO_ERROR ((LM_ERROR, "could not narrow to SimpleFT_Context\n"));
	return;
      }

    CIAO::Container_var container = ft_context->_ciao_the_Container ();

    CIAO::Container_i * ci = dynamic_cast <CIAO::Container_i*> (container.in ());

    if (ci == 0)
      {
	CIAO_ERROR ((LM_WARNING, "could not cast to Container_i\n"));
	return;
      }

    orb_ = ci->the_ORB ();
  }

  void
  FTTask_exec_i::configuration_complete ()
  {
    CIAO_TRACE ("FTTask_exec_i::configuration_complete (void)");

    try
      {
	if (CORBA::is_nil (orb_.in ()))
	  {
	    CIAO_ERROR ((LM_WARNING, "FTTask_exec_i::configuration_complete - orb_ member is nil.\n"));
	    return;
	  }

	// register application with StateSynchronizationAgent
	Name_Helper_T <StateSynchronizationAgent> nh (orb_.in ());

	CIAO_DEBUG ((LM_DEBUG, "resolving the StateSynchronizationAgent in the NamingService.\n"));

	std::string ssa_path = "FLARe/" + nh.escape_dots (this->get_hostname ()) + "/" + 
          this->get_process_id () + "/StateSynchronizationAgent";

	CIAO_DEBUG ((LM_DEBUG, "\tpath = %s\n", ssa_path.c_str ()));

	agent_ = nh.resolve (ssa_path);

	if (CORBA::is_nil (agent_.in ()))
	  {
	    CIAO_ERROR ((LM_WARNING, "FTTask_exec_i::configuration_complete - could not find agent.\n"));
	    return;
	  }
	
	CIAO_DEBUG ((LM_DEBUG, "FTTask_exec_i::configuration_complete - registering the application with the agent.\n"));

        if (CORBA::is_nil (myself_.in ()))
          {
            CIAO_ERROR ((LM_ERROR, "FTTask_exec_i::configuration_complete - Could not resolve my own reference!\n"));
            return;
          }

	ReplicatedApplication_var myself = ReplicatedApplication::_narrow (myself_.in ());

	if (CORBA::is_nil (myself.in ()))
	  {
	    CIAO_ERROR ((LM_WARNING, "FTTask_exec_i::configuration_complete - could not get reference to itself.\n"));
	    return;
	  }

	agent_->register_application (object_id_.c_str (), myself.in ());
      }
    catch (Name_Helper_Exception & ex)
      {
	CIAO_ERROR ((LM_ERROR, 
		     "FTTask_exec_i::configuration_complete - "
		     "caught Name_Helper_Exception: %s", 
		     ex.what ()));
      }
    catch (CORBA::Exception &ex)
      {
	CIAO_ERROR ((LM_ERROR, "FTTask_exec_i::configuration_complete - caught: %s", ex._info ().c_str ()));
      }
  }

  void
  FTTask_exec_i::ccm_activate ()
  {
    CIAO_TRACE ("FTTask_exec_i::ccm_activate");

    try 
      {
	if (CORBA::is_nil (orb_.in ()))
	  {
	    CIAO_ERROR ((LM_WARNING, "FTTask_exec_i::ccm_activate - orb_ member is nil.\n"));
	    return;
	  }

	// register application with ReplicationManager

	CIAO_DEBUG ((LM_DEBUG, "resolving the ReplicationManager in the NamingService.\n"));

	Name_Helper_T <ReplicationManager> rmh (orb_.in ());

	ReplicationManager_var rm = rmh.resolve ("ReplicationManager");

	std::string hn = this->get_hostname ();
	std::string pid = this->get_process_id ();

	rm->register_application (object_id_.c_str (),
				  load_,
				  hn.c_str (),
				  pid.c_str (),
				  (primary_ ? 1 : 2),
				  myself_.in ());

	// publish application in NameService for the client
	if (primary_)
	  {
	    Name_Helper_T <Worker> tnh (orb_.in ());

            DeCoRAM::Worker_var ref = DeCoRAM::Worker::_narrow (myself_.in ());

	    tnh.bind ("FLARE_TESTAPPLICATION/" + object_id_,
		      ref.in ());

            // and write it to a file
            std::string iorfilename = object_id_ + ".ior";
            std::ofstream file (iorfilename.c_str ());
            file << orb_->object_to_string (ref.in ());
            file.flush ();
            file.close ();
	  }
      }
    catch (Name_Helper_Exception & ex)
      {
	CIAO_ERROR ((LM_ERROR, 
		     "FTTask_exec_i::ccm_activate - "
		     "caught Name_Helper_Exception: %s", 
		     ex.what ()));
      }
    catch (CORBA::Exception &ex)
      {
	CIAO_ERROR ((LM_ERROR, "FTTask_exec_i::ccm_activate - caught: %s", ex._info ().c_str ()));
      }
  }

  void
  FTTask_exec_i::ccm_passivate ()
  {
    CIAO_TRACE ("FTTask_exec_i::ccm_passivate");
  }

  void
  FTTask_exec_i::ccm_remove ()
  {
    CIAO_TRACE ("FTTask_exec_i::ccm_remove");
  }

  std::string
  FTTask_exec_i::get_hostname ()
  {
    char hn_str [100];
    gethostname (hn_str, sizeof (hn_str));
    
    return std::string (hn_str);
  }


  std::string
  FTTask_exec_i::get_process_id ()
  {
    pid_t pid = ACE_OS::getpid ();
    std::stringstream ss;
    ss << pid;
    
    return ss.str ();
  }


  extern "C" FTTASK_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_DeCoRAM_FTTask_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_RETURN (retval,
                    FTTask_exec_i,
                    ::Components::EnterpriseComponent::_nil ());
    
    return retval;
  }


  //==================================================================
  // Home Executor Implementation Class:   FTTaskHome_exec_i
  //==================================================================

  FTTaskHome_exec_i::FTTaskHome_exec_i (void)
  {
  }

  FTTaskHome_exec_i::~FTTaskHome_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  FTTaskHome_exec_i::create ()
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      FTTask_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" FTTASK_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_DeCoRAM_FTTaskHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      FTTaskHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}
