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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_POLLABLEC_H_
#define _TAO_IDL_ORIG_POLLABLEC_H_

#include "ace/pre.h"
#include "Exception.h"

#if (TAO_HAS_AMI_POLLER == 1)

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Object.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  CORBA
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:567

#if !defined (_CORBA_POLLABLESET__ODDS_N_ENDS_CH_)
#define _CORBA_POLLABLESET__ODDS_N_ENDS_CH_
  
  class PollableSet;
  typedef PollableSet *PollableSet_ptr;
  struct tao_PollableSet_life;
  typedef TAO_Objref_Var_T<PollableSet, tao_PollableSet_life> PollableSet_var;
  typedef TAO_Objref_Out_T<PollableSet, tao_PollableSet_life> PollableSet_out;
  
  struct TAO_Export tao_PollableSet_life
  {
    static PollableSet_ptr tao_duplicate (PollableSet_ptr);
    static void tao_release (PollableSet_ptr);
    static PollableSet_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        PollableSet_ptr,
        TAO_OutputCDR &
      );
  };
  
  struct TAO_Export tao_PollableSet_cast
  {
    static PollableSet_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:567

#if !defined (_CORBA_POLLABLE__ODDS_N_ENDS_CH_)
#define _CORBA_POLLABLE__ODDS_N_ENDS_CH_
  
  class Pollable;
  typedef Pollable *Pollable_ptr;
  struct tao_Pollable_life;
  typedef TAO_Objref_Var_T<Pollable, tao_Pollable_life> Pollable_var;
  typedef TAO_Objref_Out_T<Pollable, tao_Pollable_life> Pollable_out;
  
  struct TAO_Export tao_Pollable_life
  {
    static Pollable_ptr tao_duplicate (Pollable_ptr);
    static void tao_release (Pollable_ptr);
    static Pollable_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        Pollable_ptr,
        TAO_OutputCDR &
      );
  };
  
  struct TAO_Export tao_Pollable_cast
  {
    static Pollable_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_POLLABLE_CH_)
#define _CORBA_POLLABLE_CH_
  
  class TAO_Export Pollable
    : public virtual CORBA::Object
  {
  public:
    typedef Pollable_ptr _ptr_type;
    typedef Pollable_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static Pollable_ptr _duplicate (Pollable_ptr obj);
    
    static Pollable_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Pollable_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Pollable_ptr _nil (void)
      {
        return (Pollable_ptr)0;
      }
    
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::Boolean is_ready (
        CORBA::ULong timeout
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::PollableSet_ptr create_pollable_set (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:211
    
    virtual void *_tao_QueryInterface (ptrdiff_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    Pollable (void);
    virtual ~Pollable (void);
  
  private:
    Pollable (const Pollable &);
    void operator= (const Pollable &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:567

#if !defined (_CORBA_DIIPOLLABLE__ODDS_N_ENDS_CH_)
#define _CORBA_DIIPOLLABLE__ODDS_N_ENDS_CH_
  
  class DIIPollable;
  typedef DIIPollable *DIIPollable_ptr;
  struct tao_DIIPollable_life;
  typedef TAO_Objref_Var_T<DIIPollable, tao_DIIPollable_life> DIIPollable_var;
  typedef TAO_Objref_Out_T<DIIPollable, tao_DIIPollable_life> DIIPollable_out;
  
  struct TAO_Export tao_DIIPollable_life
  {
    static DIIPollable_ptr tao_duplicate (DIIPollable_ptr);
    static void tao_release (DIIPollable_ptr);
    static DIIPollable_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        DIIPollable_ptr,
        TAO_OutputCDR &
      );
  };
  
  struct TAO_Export tao_DIIPollable_cast
  {
    static DIIPollable_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_DIIPOLLABLE_CH_)
#define _CORBA_DIIPOLLABLE_CH_
  
  class TAO_Export DIIPollable
    : public virtual CORBA::Pollable
  {
  public:
    typedef DIIPollable_ptr _ptr_type;
    typedef DIIPollable_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static DIIPollable_ptr _duplicate (DIIPollable_ptr obj);
    
    static DIIPollable_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DIIPollable_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DIIPollable_ptr _nil (void)
      {
        return (DIIPollable_ptr)0;
      }
    
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:211
    
    virtual void *_tao_QueryInterface (ptrdiff_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    DIIPollable (void);
    virtual ~DIIPollable (void);
  
  private:
    DIIPollable (const DIIPollable &);
    void operator= (const DIIPollable &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_POLLABLESET_CH_)
#define _CORBA_POLLABLESET_CH_
  
  class TAO_Export PollableSet
    : public virtual CORBA::Object
  {
  public:
    typedef PollableSet_ptr _ptr_type;
    typedef PollableSet_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static PollableSet_ptr _duplicate (PollableSet_ptr obj);
    
    static PollableSet_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PollableSet_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PollableSet_ptr _nil (void)
      {
        return (PollableSet_ptr)0;
      }
    
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_)
#define _CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_
    
    class TAO_Export NoPossiblePollable : public CORBA::UserException
    {
    public:
      
      NoPossiblePollable (void);
      NoPossiblePollable (const NoPossiblePollable &);
      ~NoPossiblePollable (void);

      NoPossiblePollable &operator= (const NoPossiblePollable &);
      
      static NoPossiblePollable *_downcast (CORBA::Exception *);
      static CORBA::Exception *_alloc (void);

      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void);

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        );
      
      // TAO_IDL - Generated from
      // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:125
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_)
#define _CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_
    
    class TAO_Export UnknownPollable : public CORBA::UserException
    {
    public:
      
      UnknownPollable (void);
      UnknownPollable (const UnknownPollable &);
      ~UnknownPollable (void);

      UnknownPollable &operator= (const UnknownPollable &);
      
      static UnknownPollable *_downcast (CORBA::Exception *);
      static CORBA::Exception *_alloc (void);

      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void);

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        );
      
      // TAO_IDL - Generated from
      // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:125
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::DIIPollable_ptr create_dii_pollable (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void add_pollable (
        CORBA::Pollable_ptr potential
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Pollable_ptr poll (
        CORBA::ULong timeout
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , CORBA::PollableSet::NoPossiblePollable
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void remove (
        CORBA::Pollable_ptr potential
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , CORBA::PollableSet::UnknownPollable
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::UShort number_left (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:211
    
    virtual void *_tao_QueryInterface (ptrdiff_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    PollableSet (void);
    virtual ~PollableSet (void);
  
  private:
    PollableSet (const PollableSet &);
    void operator= (const PollableSet &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module CORBA

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "PollableC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#endif /* TAO_HAS_AMI_POLLER == 1 */

#include "ace/post.h"
#endif /* ifndef */

