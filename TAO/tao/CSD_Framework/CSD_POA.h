/* -*- C++ -*- */

//=============================================================================
/**
 *  @file CSD_POA.h
 *
 *  $Id$
 *
 *  @author Yan Dai (dai_y@ociweb.com)
 */
//=============================================================================

#ifndef TAO_CSD_POA_H
#define TAO_CSD_POA_H

#include /**/ "ace/pre.h"

#include "CSD_FW_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/Regular_POA.h"
#include "CSD_Strategy_Proxy.h"


/**
 * @class TAO_CSD_POA
 *
 * @brief Implementation of the CSD_Framework::POA interface.
 *
 * Implementation of the CSD_Framework::POA interface.
 */
class TAO_CSD_FW_Export TAO_CSD_POA 
  : public virtual CSD_Framework::POA, 
    public virtual TAO_Regular_POA
{
public:
  //Constructor 
  TAO_CSD_POA (const String &name,
              TAO_POA_Manager &poa_manager,
              const TAO_POA_Policy_Set &policies,
              TAO_Root_POA *parent,
              ACE_Lock &lock,
              TAO_SYNCH_MUTEX &thread_lock,
              TAO_ORB_Core &orb_core,
              TAO_Object_Adapter *object_adapter
              ACE_ENV_ARG_DECL);
  
  //Destructor 
  virtual ~TAO_CSD_POA (void);
  
  /// Pass the Strategy object reference to the CSD poa.
  virtual
  void set_csd_strategy (
      ::CSD_Framework::Strategy_ptr s
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  /// Hook - The POA has been (or is being) activated.
  virtual void poa_activated_hook ();

  /// Hook - The POA has been deactivated.
  virtual void poa_deactivated_hook ();

  /// Hook - A servant has been activated.
  virtual void servant_activated_hook (PortableServer::Servant servant, 
                              const PortableServer::ObjectId& oid
                              ACE_ENV_ARG_DECL);

  /// Hook - A servant has been deactivated.
  virtual void servant_deactivated_hook (PortableServer::Servant servant, 
                                const PortableServer::ObjectId& oid
                                ACE_ENV_ARG_DECL);

  ///Method for creating new CSD POA.
  TAO_Root_POA * new_POA (const String &name,
                          TAO_POA_Manager &poa_manager,
                          const TAO_POA_Policy_Set &policies,
                          TAO_Root_POA *parent,
                          ACE_Lock &lock,
                          TAO_SYNCH_MUTEX &thread_lock,
                          TAO_ORB_Core &orb_core,
                          TAO_Object_Adapter *object_adapter
                          ACE_ENV_ARG_DECL);

  /// Servant Dispatching Strategy proxy accessor.
  TAO::CSD::Strategy_Proxy& 
    servant_dispatching_strategy_proxy (void) const;

private:

  TAO::CSD::Strategy_Proxy* sds_proxy_;
};


#if defined (__ACE_INLINE__)
# include "CSD_POA.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_CSD_POA_H  */

