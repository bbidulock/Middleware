/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Network_Priority_Mapping_Manager.h
 *
 *  $Id$
 *
 *  @author Yamuna Krishnamurthy (yamuna@oomworks.com)
 */
//=============================================================================


#ifndef TAO_NETWORK_PRIORITY_MAPPING_MANAGER_H
#define TAO_NETWORK_PRIORITY_MAPPING_MANAGER_H
#include /**/ "ace/pre.h"

#include "tao/orbconf.h"
#include "rtcorba_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#include "Network_Priority_Mapping.h"
#include "tao/LocalObject.h"

class TAO_Network_Priority_Mapping_Manager;
class TAO_Network_Priority_Mapping_Manager_var;
typedef TAO_Network_Priority_Mapping_Manager *TAO_Network_Priority_Mapping_Manager_ptr;


namespace RTCORBA
{
}
/**
 * @class TAO_Network_Priority_Mapping_Manager
 *
 * @brief Network_Priority_Mapping_Manager pseudo-objref.
 *
 * Allows setting of user-defined Network_Priority_Mapping at run-time.
 */
class TAO_RTCORBA_Export TAO_Network_Priority_Mapping_Manager :
  public virtual TAO_Local_RefCounted_Object
{

public:
  /// Constructor.
  TAO_Network_Priority_Mapping_Manager (RTCORBA::NetworkPriorityMapping * mapping);

  ///
  void mapping (RTCORBA::NetworkPriorityMapping * mapping);

  ///
  RTCORBA::NetworkPriorityMapping *mapping (void);

public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef TAO_Network_Priority_Mapping_Manager_ptr _ptr_type;
  typedef TAO_Network_Priority_Mapping_Manager_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static TAO_Network_Priority_Mapping_Manager_ptr _duplicate (
      TAO_Network_Priority_Mapping_Manager_ptr obj
    );
  static TAO_Network_Priority_Mapping_Manager_ptr _narrow (
      CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  static TAO_Network_Priority_Mapping_Manager_ptr _nil (void)
    {
      return (TAO_Network_Priority_Mapping_Manager_ptr)0;
    }

  virtual const char* _interface_repository_id (void) const;

protected:

  /// Protected destructor to enforce proper memory management of this
  /// reference counted object.
  ~TAO_Network_Priority_Mapping_Manager (void);

private:

  TAO_Network_Priority_Mapping_Manager (const TAO_Network_Priority_Mapping_Manager &);
  void operator= (const TAO_Network_Priority_Mapping_Manager &);

private:

  TAO_Network_Priority_Mapping *mapping_;
};

class TAO_RTCORBA_Export TAO_Network_Priority_Mapping_Manager_var : public TAO_Base_var
{
public:
  TAO_Network_Priority_Mapping_Manager_var (void); // default constructor
  TAO_Network_Priority_Mapping_Manager_var (TAO_Network_Priority_Mapping_Manager_ptr);
  TAO_Network_Priority_Mapping_Manager_var (const TAO_Network_Priority_Mapping_Manager_var &); // copy constructor
  ~TAO_Network_Priority_Mapping_Manager_var (void); // destructor

  TAO_Network_Priority_Mapping_Manager_var &operator= (TAO_Network_Priority_Mapping_Manager_ptr);
  TAO_Network_Priority_Mapping_Manager_var &operator= (const TAO_Network_Priority_Mapping_Manager_var &);
  TAO_Network_Priority_Mapping_Manager_ptr operator-> (void) const;

  /// in, inout, out, _retn
  operator const TAO_Network_Priority_Mapping_Manager_ptr &() const;
  operator TAO_Network_Priority_Mapping_Manager_ptr &();
  TAO_Network_Priority_Mapping_Manager_ptr in (void) const;
  TAO_Network_Priority_Mapping_Manager_ptr &inout (void);
  TAO_Network_Priority_Mapping_Manager_ptr &out (void);
  TAO_Network_Priority_Mapping_Manager_ptr _retn (void);
  TAO_Network_Priority_Mapping_Manager_ptr ptr (void) const;

  // Hooks used by template sequence and object manager classes
  // for non-defined forward declared interfaces.
  static TAO_Network_Priority_Mapping_Manager_ptr duplicate (TAO_Network_Priority_Mapping_Manager_ptr);
  static void release (TAO_Network_Priority_Mapping_Manager_ptr);
  static TAO_Network_Priority_Mapping_Manager_ptr nil (void);
  static TAO_Network_Priority_Mapping_Manager_ptr narrow (CORBA::Object * ACE_ENV_ARG_DECL_NOT_USED);
  static CORBA::Object * upcast (void *);

private:
  /// Unimplemented - prevents widening assignment.
  TAO_Network_Priority_Mapping_Manager_ptr ptr_;
  TAO_Network_Priority_Mapping_Manager_var (const TAO_Base_var &rhs);
  TAO_Network_Priority_Mapping_Manager_var &operator= (const TAO_Base_var &rhs);
};

class TAO_RTCORBA_Export TAO_Network_Priority_Mapping_Manager_out
{
public:
  TAO_Network_Priority_Mapping_Manager_out (TAO_Network_Priority_Mapping_Manager_ptr &);
  TAO_Network_Priority_Mapping_Manager_out (TAO_Network_Priority_Mapping_Manager_var &);
  TAO_Network_Priority_Mapping_Manager_out (const TAO_Network_Priority_Mapping_Manager_out &);
  TAO_Network_Priority_Mapping_Manager_out &operator= (const TAO_Network_Priority_Mapping_Manager_out &);
  TAO_Network_Priority_Mapping_Manager_out &operator= (const TAO_Network_Priority_Mapping_Manager_var &);
  TAO_Network_Priority_Mapping_Manager_out &operator= (TAO_Network_Priority_Mapping_Manager_ptr);
  operator TAO_Network_Priority_Mapping_Manager_ptr &();
  TAO_Network_Priority_Mapping_Manager_ptr &ptr (void);
  TAO_Network_Priority_Mapping_Manager_ptr operator-> (void);

private:
  TAO_Network_Priority_Mapping_Manager_ptr &ptr_;
};

#if defined (__ACE_INLINE__)
#include "Network_Priority_Mapping_Manager.i"
#endif /* __ACE_INLINE__ */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_CORBA_MESSAGING != 0 */

#include /**/ "ace/post.h"
#endif /* TAO_NETWORK_PRIORITY_MAPPING_MANAGER_H */
