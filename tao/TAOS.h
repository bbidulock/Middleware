/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_TAOS_H_
#define _TAO_IDL_TAOS_H_

#include "tao/TAOC.h"

#if defined (TAO_HAS_CORBA_MESSAGING)

#include "tao/POA_CORBA.h"

#endif /* TAO_HAS_CORBA_MESSAGING */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  POA_TAO
{

#if defined (TAO_HAS_CORBA_MESSAGING)

  class ClientPriorityPolicy;
  typedef ClientPriorityPolicy *ClientPriorityPolicy_ptr;
  class TAO_Export ClientPriorityPolicy : public virtual POA_CORBA::Policy
  {
  protected:
    ClientPriorityPolicy (void);

  public:
    virtual ~ClientPriorityPolicy (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    TAO::ClientPriorityPolicy *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;

    virtual TAO::PrioritySpecification priority_specification (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;


  };


#if !defined (_TAO_CLIENTPRIORITYPOLICY___DIRECT_COLLOCATED_SH_)
#define _TAO_CLIENTPRIORITYPOLICY___DIRECT_COLLOCATED_SH_

  class TAO_Export _tao_direct_collocated_ClientPriorityPolicy     : public virtual TAO::ClientPriorityPolicy,
      public virtual POA_CORBA::_tao_collocated_Policy
  {
  public:
    _tao_direct_collocated_ClientPriorityPolicy (
        ClientPriorityPolicy_ptr  servant,
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

    ClientPriorityPolicy_ptr _get_servant (void) const;

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

        virtual TAO::PrioritySpecification priority_specification (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );


  private:
    ClientPriorityPolicy_ptr servant_;
  };


#endif /* end #if !defined */


  class BufferingConstraintPolicy;
  typedef BufferingConstraintPolicy *BufferingConstraintPolicy_ptr;
  class TAO_Export BufferingConstraintPolicy : public virtual POA_CORBA::Policy
  {
  protected:
    BufferingConstraintPolicy (void);

  public:
    virtual ~BufferingConstraintPolicy (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    TAO::BufferingConstraintPolicy *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;

    virtual TAO::BufferingConstraint buffering_constraint (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;


  };


#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___DIRECT_COLLOCATED_SH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___DIRECT_COLLOCATED_SH_

  class TAO_Export _tao_direct_collocated_BufferingConstraintPolicy     : public virtual TAO::BufferingConstraintPolicy,
      public virtual POA_CORBA::_tao_collocated_Policy
  {
  public:
    _tao_direct_collocated_BufferingConstraintPolicy (
        BufferingConstraintPolicy_ptr  servant,
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

    BufferingConstraintPolicy_ptr _get_servant (void) const;

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

        virtual TAO::BufferingConstraint buffering_constraint (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );


  private:
    BufferingConstraintPolicy_ptr servant_;
  };


#endif /* end #if !defined */


#endif /* TAO_HAS_CORBA_MESSAGING */

}
TAO_NAMESPACE_CLOSE

#include "tao/TAOS_T.h"

#if defined (__ACE_INLINE__)
#include "tao/TAOS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* ifndef */
