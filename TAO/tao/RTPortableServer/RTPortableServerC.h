// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_RTPORTABLESERVERC_H_
#define _TAO_IDL_ORIG_RTPORTABLESERVERC_H_

#include "ace/pre.h"
#include "rtportableserver_export.h"
#include "tao/PortableServer/PortableServerC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/RTCORBA/RTCORBA.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_RTPortableServer_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_RTPortableServer_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

TAO_NAMESPACE  RTPortableServer
{

#if !defined (_RTPORTABLESERVER_POA___PTR_CH_)
#define _RTPORTABLESERVER_POA___PTR_CH_

  class POA;
  typedef POA *POA_ptr;
  
#endif /* end #if !defined */


#if !defined (_RTPORTABLESERVER_POA___VAR_CH_)
#define _RTPORTABLESERVER_POA___VAR_CH_

  class TAO_RTPortableServer_Export POA_var : public TAO_Base_var
  {
  public:
    POA_var (void); // default constructor
    POA_var (POA_ptr p) : ptr_ (p) {} 
    POA_var (const POA_var &); // copy constructor
    ~POA_var (void); // destructor
    
    POA_var &operator= (POA_ptr);
    POA_var &operator= (const POA_var &);
    POA_ptr operator-> (void) const;
    
    operator const POA_ptr &() const;
    operator POA_ptr &();
    // in, inout, out, _retn 
    POA_ptr in (void) const;
    POA_ptr &inout (void);
    POA_ptr &out (void);
    POA_ptr _retn (void);
    POA_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static POA_ptr tao_duplicate (POA_ptr);
    static void tao_release (POA_ptr);
    static POA_ptr tao_nil (void);
    static POA_ptr tao_narrow (CORBA::Object *, CORBA::Environment &);
    static CORBA::Object * tao_upcast (void *);
  
  private:
    POA_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    POA_var (const TAO_Base_var &rhs);
    POA_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */


#if !defined (_RTPORTABLESERVER_POA___OUT_CH_)
#define _RTPORTABLESERVER_POA___OUT_CH_

  class TAO_RTPortableServer_Export POA_out
  {
  public:
    POA_out (POA_ptr &);
    POA_out (POA_var &);
    POA_out (const POA_out &);
    POA_out &operator= (const POA_out &);
    POA_out &operator= (const POA_var &);
    POA_out &operator= (POA_ptr);
    operator POA_ptr &();
    POA_ptr &ptr (void);
    POA_ptr operator-> (void);
  
  private:
    POA_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_RTPORTABLESERVER_POA_CH_)
#define _RTPORTABLESERVER_POA_CH_

class TAO_RTPortableServer_Export POA: public virtual PortableServer::POA
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef POA_ptr _ptr_type;
    typedef POA_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

  static int _tao_class_id;

    // the static operations
    static POA_ptr _duplicate (POA_ptr obj);
    static POA_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
    static POA_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
    static POA_ptr _nil (void)
      {
        return (POA_ptr)0;
      }

    virtual CORBA::Object_ptr create_reference_with_priority (
        const char * intf,
        RTCORBA::Priority priority,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        PortableServer::POA::WrongPolicy
      )) = 0;

    virtual CORBA::Object_ptr create_reference_with_id_and_priority (
        const PortableServer::ObjectId & oid,
        const char * intf,
        RTCORBA::Priority priority,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        PortableServer::POA::WrongPolicy
      )) = 0;

    virtual PortableServer::ObjectId * activate_object_with_priority (
        PortableServer::Servant p_servant,
        RTCORBA::Priority priority,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        PortableServer::POA::ServantAlreadyActive,
        PortableServer::POA::WrongPolicy
      )) = 0;

    virtual void activate_object_with_id_and_priority (
        const PortableServer::ObjectId & oid,
        PortableServer::Servant p_servant,
        RTCORBA::Priority priority,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        PortableServer::POA::ServantAlreadyActive,
        PortableServer::POA::ObjectAlreadyActive,
        PortableServer::POA::WrongPolicy
      )) = 0;

    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;

  protected:
    POA ();
    
    virtual ~POA (void);
  private:
    POA (const POA &);
    void operator= (const POA &);
  };


#endif /* end #if !defined */


}
TAO_NAMESPACE_CLOSE // module RTPortableServer


#ifndef __ACE_INLINE__


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "RTPortableServerC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
