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

#ifndef _TAO_IDL_ORIG_BIDIRPOLICYC_H_
#define _TAO_IDL_ORIG_BIDIRPOLICYC_H_

#ifndef TAO_BIDIRGIOP_SAFE_INCLUDE
#error "You should not include BiDirPolicyC.h directly, use BiDirGIOP.h"
#endif /* !TAO_BIDIRGIOP_SAFE_INCLUDE */

#include "ace/pre.h"
#include "bidirgiop_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_BiDirGIOP_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_BiDirGIOP_Export
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

TAO_NAMESPACE  BiDirPolicy
{
  typedef CORBA::UShort BidirectionalPolicyValue;
  typedef CORBA::UShort_out BidirectionalPolicyValue_out;
    TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_BidirectionalPolicyValue;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::UShort NORMAL;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::UShort BOTH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong BIDIRECTIONAL_POLICY_TYPE;


#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY___PTR_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY___PTR_CH_

  class BidirectionalPolicy;
  typedef BidirectionalPolicy *BidirectionalPolicy_ptr;
  
#endif /* end #if !defined */


#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY___VAR_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY___VAR_CH_

  class TAO_BiDirGIOP_Export BidirectionalPolicy_var : public TAO_Base_var
  {
  public:
    BidirectionalPolicy_var (void); // default constructor
    BidirectionalPolicy_var (BidirectionalPolicy_ptr p) : ptr_ (p) {} 
    BidirectionalPolicy_var (const BidirectionalPolicy_var &); // copy constructor
    ~BidirectionalPolicy_var (void); // destructor
    
    BidirectionalPolicy_var &operator= (BidirectionalPolicy_ptr);
    BidirectionalPolicy_var &operator= (const BidirectionalPolicy_var &);
    BidirectionalPolicy_ptr operator-> (void) const;
    
    operator const BidirectionalPolicy_ptr &() const;
    operator BidirectionalPolicy_ptr &();
    // in, inout, out, _retn 
    BidirectionalPolicy_ptr in (void) const;
    BidirectionalPolicy_ptr &inout (void);
    BidirectionalPolicy_ptr &out (void);
    BidirectionalPolicy_ptr _retn (void);
    BidirectionalPolicy_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static BidirectionalPolicy_ptr tao_duplicate (BidirectionalPolicy_ptr);
    static void tao_release (BidirectionalPolicy_ptr);
    static BidirectionalPolicy_ptr tao_nil (void);
    static BidirectionalPolicy_ptr tao_narrow (CORBA::Object *, CORBA::Environment &);
    static CORBA::Object * tao_upcast (void *);
  
  private:
    BidirectionalPolicy_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    BidirectionalPolicy_var (const TAO_Base_var &rhs);
    BidirectionalPolicy_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */


#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY___OUT_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY___OUT_CH_

  class TAO_BiDirGIOP_Export BidirectionalPolicy_out
  {
  public:
    BidirectionalPolicy_out (BidirectionalPolicy_ptr &);
    BidirectionalPolicy_out (BidirectionalPolicy_var &);
    BidirectionalPolicy_out (const BidirectionalPolicy_out &);
    BidirectionalPolicy_out &operator= (const BidirectionalPolicy_out &);
    BidirectionalPolicy_out &operator= (const BidirectionalPolicy_var &);
    BidirectionalPolicy_out &operator= (BidirectionalPolicy_ptr);
    operator BidirectionalPolicy_ptr &();
    BidirectionalPolicy_ptr &ptr (void);
    BidirectionalPolicy_ptr operator-> (void);
  
  private:
    BidirectionalPolicy_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY_CH_

class TAO_BiDirGIOP_Export BidirectionalPolicy: public virtual CORBA::Policy
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef BidirectionalPolicy_ptr _ptr_type;
    typedef BidirectionalPolicy_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

  static int _tao_class_id;

    // the static operations
    static BidirectionalPolicy_ptr _duplicate (BidirectionalPolicy_ptr obj);
    static BidirectionalPolicy_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
    static BidirectionalPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
    static BidirectionalPolicy_ptr _nil (void)
      {
        return (BidirectionalPolicy_ptr)0;
      }

    virtual BiDirPolicy::BidirectionalPolicyValue value (
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;

  protected:
    BidirectionalPolicy ();
    
    virtual ~BidirectionalPolicy (void);
  private:
    BidirectionalPolicy (const BidirectionalPolicy &);
    void operator= (const BidirectionalPolicy &);
  };


#endif /* end #if !defined */


}
TAO_NAMESPACE_CLOSE // module BiDirPolicy


#ifndef __ACE_INLINE__


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "BiDirPolicyC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
