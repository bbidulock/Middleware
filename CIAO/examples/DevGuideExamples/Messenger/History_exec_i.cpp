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

#include "History_exec_i.h"
#include "ciao/CIAO_common.h"

namespace CIDL_Messenger_Impl
{
  //==================================================================
  // Facet Executor Implementation Class:   History_exec_i
  //==================================================================

  History_exec_i::History_exec_i (void)
  {
  }

  History_exec_i::~History_exec_i (void)
  {
  }

  // Operations from ::History

  ::Messages *
  History_exec_i::get_all ()
  {
    // Your code here.

    // MY CODE
    ACE_Guard<TAO_SYNCH_MUTEX> guard(this->lock_);

    ACE_DEBUG((LM_INFO, ACE_TEXT("History_i::get_all\n") ));

    // create a Messages sequence, set its length
    ::Messages* retval = new ::Messages();
    retval->length( this->messages_.size() );

    // iterate through the MessageList, copying messages into the return sequence
    CORBA::ULong i = 0;
    for ( MessageList::iterator messageItr = this->messages_.begin();
          messageItr != this->messages_.end();
          ++messageItr )
      {
        // because the MessageList contains Message_vars, reference counting
        // upon assignment into the sequence is handled properly for us.
        (*retval)[i++] = *messageItr;
      }
    return retval;
  }

  ::Message *
  History_exec_i::get_latest ()
  {
    // Your code here.

    // MY CODE
    ACE_Guard<TAO_SYNCH_MUTEX> guard(this->lock_);

    ACE_DEBUG((LM_INFO, ACE_TEXT("History_i::get_latest\n") ));

    // just get the last message from the history.  because the MessageList
    // contains Message_vars, _var to _var assigmnent handles the reference
    // counting properly for us.
    ::Message_var retval = this->messages_.back();
    return retval._retn();
  }

  // MY CODE
  void
  History_exec_i::add( ::Message* message )
  {
    ACE_Guard<TAO_SYNCH_MUTEX> guard(lock_);

    // bump up the reference count; we don't own it.
    // the _var in the STL list takes ownership of the "copy"
    message->_add_ref();
    this->messages_.push_back( message );
  }
}

