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

#include "Publication_exec_i.h"
#include "ciao/CIAO_common.h"

namespace CIAO_Messenger_Impl
{
  //==================================================================
  // Facet Executor Implementation Class:   Publication_exec_i
  //==================================================================

  Publication_exec_i::Publication_exec_i (
    const char* text, CORBA::UShort period)
    : text_( text ),
      period_( period)
  {
  }

  Publication_exec_i::~Publication_exec_i (void)
  {
  }

  // Operations from ::Publication

  char*
  Publication_exec_i::text ()
  {
    ACE_Guard<TAO_SYNCH_MUTEX> guard(this->lock_);

    return CORBA::string_dup( this->text_.c_str() );
  }

  void
  Publication_exec_i::text (
  const char* text)
  {
    ACE_Guard<TAO_SYNCH_MUTEX> guard(this->lock_);

    this->text_ = text;
    ACE_DEBUG((LM_INFO, ACE_TEXT("publication text changed to %C\n"), text ));
  }

  CORBA::UShort
  Publication_exec_i::period ()
  {
    ACE_Guard<TAO_SYNCH_MUTEX> guard(this->lock_);

    return this->period_;
  }

  void
  Publication_exec_i::period (CORBA::UShort period)
  {
    ACE_Guard<TAO_SYNCH_MUTEX> guard( this->lock_ );

    if ( period > 0 ) {
      this->period_ = period;
      ACE_DEBUG((LM_INFO, ACE_TEXT("publication period changed to %d seconds\n"), period ));
    } else {
      ACE_DEBUG((LM_INFO, ACE_TEXT("ignoring a negative period of %d\n"), period ));
    }
  }
}

