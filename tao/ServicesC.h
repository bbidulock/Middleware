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

#ifndef _TAO_IDL_ORIG_SERVICESC_H_
#define _TAO_IDL_ORIG_SERVICESC_H_

#include "ace/pre.h"
#include "tao/OctetSeqC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/CDR.h"

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
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:334
  
  typedef CORBA::UShort ServiceType;
  typedef CORBA::UShort_out ServiceType_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceType;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:334
  
  typedef CORBA::ULong ServiceOption;
  typedef CORBA::ULong_out ServiceOption_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceOption;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:334
  
  typedef CORBA::ULong ServiceDetailType;
  typedef CORBA::ULong_out ServiceDetailType_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceDetailType;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::ServiceType Security = 1U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:49
  
  class ServiceDetail_var;
  
  struct TAO_Export ServiceDetail
  {
    typedef ServiceDetail_var _var_type;
    
    static void _tao_any_destructor (void *);
    CORBA::ServiceDetailType service_detail_type;
    CORBA::OctetSeq service_detail;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:71
  
  class TAO_Export ServiceDetail_var
  {
  public:
    ServiceDetail_var (void);
    ServiceDetail_var (ServiceDetail *);
    ServiceDetail_var (const ServiceDetail_var &);
    ~ServiceDetail_var (void);
    
    ServiceDetail_var &operator= (ServiceDetail *);
    ServiceDetail_var &operator= (const ServiceDetail_var &);
    ServiceDetail *operator-> (void);
    const ServiceDetail *operator-> (void) const;
    
    operator const ServiceDetail &() const;
    operator ServiceDetail &();
    operator ServiceDetail &() const;
    
    // Variable-size types only.
    operator ServiceDetail *&();
    
    // in, inout, out, _retn 
    const ServiceDetail &in (void) const;
    ServiceDetail &inout (void);
    ServiceDetail *&out (void);
    ServiceDetail *_retn (void);
    ServiceDetail *ptr (void) const;
  
  private:
    ServiceDetail *ptr_;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:445
  
  class TAO_Export ServiceDetail_out
  {
  public:
    ServiceDetail_out (ServiceDetail *&);
    ServiceDetail_out (ServiceDetail_var &);
    ServiceDetail_out (const ServiceDetail_out &);
    ServiceDetail_out &operator= (const ServiceDetail_out &);
    ServiceDetail_out &operator= (ServiceDetail *);
    operator ServiceDetail *&();
    ServiceDetail *&ptr (void);
    ServiceDetail *operator-> (void);
    
  private:
    ServiceDetail *&ptr_;
    // Assignment from T_var not allowed.
    void operator= (const ServiceDetail_var &);
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceDetail;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:49
  
  class ServiceInformation_var;
  
  struct TAO_Export ServiceInformation
  {
    typedef ServiceInformation_var _var_type;
    
    static void _tao_any_destructor (void *);
    
    
    // TAO_IDL - Generated from 
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_ch.cpp:65

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_
    
    class TAO_Export _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
      : public TAO_Unbounded_Base_Sequence
    {
    public:
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (CORBA::ULong maximum); 
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (
          CORBA::ULong maximum,
          CORBA::ULong length,
          CORBA::ULong *data,
          CORBA::Boolean release = 0
        );
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (
          const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption &rhs
        );
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption &operator= (
          const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption &rhs
        );
      virtual ~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void);
      
      // = Accessors.
      CORBA::ULong &operator[] (CORBA::ULong i);
      const CORBA::ULong &operator[] (CORBA::ULong i) const;
      
      // = Static operations.
      static CORBA::ULong *allocbuf (CORBA::ULong size);
      static void freebuf (CORBA::ULong *buffer);
      
      // Implement the TAO_Base_Sequence methods (see Sequence.h)
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      CORBA::ULong *get_buffer (CORBA::Boolean orphan = 0);
      const CORBA::ULong *get_buffer (void) const;
      void replace (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::ULong *data,
          CORBA::Boolean release
        );
    };

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:371
    
    class _tao_seq_ServiceOption;
    
    // *************************************************************
    // CORBA::ServiceInformation::_tao_seq_ServiceOption
    // *************************************************************
    
    class TAO_Export _tao_seq_ServiceOption : public 
    
    // TAO_IDL - Generated from 
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:51

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
    _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
    TAO_Unbounded_Sequence<CORBA::ULong>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
    {
    public:
      _tao_seq_ServiceOption (void);
      _tao_seq_ServiceOption (CORBA::ULong max);
      _tao_seq_ServiceOption (
          CORBA::ULong max, 
          CORBA::ULong length, 
          CORBA::ULong *buffer, 
          CORBA::Boolean release = 0
        );
      _tao_seq_ServiceOption (const _tao_seq_ServiceOption &);
      ~_tao_seq_ServiceOption (void);
      
      static void _tao_any_destructor (void*);
      
      
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_field/field_ch.cpp:447
    
    typedef _tao_seq_ServiceOption _service_options_seq;
    _tao_seq_ServiceOption service_options;
    
    
    // TAO_IDL - Generated from 
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_ch.cpp:65

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_
    
    class TAO_Export _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
      : public TAO_Unbounded_Base_Sequence
    {
    public:
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (CORBA::ULong maximum); 
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (
          CORBA::ULong maximum,
          CORBA::ULong length,
          ACE_NESTED_CLASS (CORBA, ServiceDetail) *data,
          CORBA::Boolean release = 0
        );
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (
          const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail &rhs
        );
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail &operator= (
          const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail &rhs
        );
      virtual ~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void);
      
      // = Accessors.
      ACE_NESTED_CLASS (CORBA, ServiceDetail) &operator[] (CORBA::ULong i);
      const ACE_NESTED_CLASS (CORBA, ServiceDetail) &operator[] (CORBA::ULong i) const;
      
      // = Static operations.
      static ACE_NESTED_CLASS (CORBA, ServiceDetail) *allocbuf (CORBA::ULong size);
      static void freebuf (ACE_NESTED_CLASS (CORBA, ServiceDetail) *buffer);
      
      // Implement the TAO_Base_Sequence methods (see Sequence.h)
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      ACE_NESTED_CLASS (CORBA, ServiceDetail) *get_buffer (CORBA::Boolean orphan = 0);
      const ACE_NESTED_CLASS (CORBA, ServiceDetail) *get_buffer (void) const;
      void replace (
          CORBA::ULong max,
          CORBA::ULong length,
          ACE_NESTED_CLASS (CORBA, ServiceDetail) *data,
          CORBA::Boolean release
        );
    };

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:371
    
    class _tao_seq_ServiceDetail;
    
    // *************************************************************
    // CORBA::ServiceInformation::_tao_seq_ServiceDetail
    // *************************************************************
    
    class TAO_Export _tao_seq_ServiceDetail : public 
    
    // TAO_IDL - Generated from 
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:51

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
    _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
    TAO_Unbounded_Sequence<ACE_NESTED_CLASS (CORBA, ServiceDetail)>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
    {
    public:
      _tao_seq_ServiceDetail (void);
      _tao_seq_ServiceDetail (CORBA::ULong max);
      _tao_seq_ServiceDetail (
          CORBA::ULong max, 
          CORBA::ULong length, 
          ACE_NESTED_CLASS (CORBA, ServiceDetail) *buffer, 
          CORBA::Boolean release = 0
        );
      _tao_seq_ServiceDetail (const _tao_seq_ServiceDetail &);
      ~_tao_seq_ServiceDetail (void);
      
      static void _tao_any_destructor (void*);
      
      
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_field/field_ch.cpp:447
    
    typedef _tao_seq_ServiceDetail _service_details_seq;
    _tao_seq_ServiceDetail service_details;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:71
  
  class TAO_Export ServiceInformation_var
  {
  public:
    ServiceInformation_var (void);
    ServiceInformation_var (ServiceInformation *);
    ServiceInformation_var (const ServiceInformation_var &);
    ~ServiceInformation_var (void);
    
    ServiceInformation_var &operator= (ServiceInformation *);
    ServiceInformation_var &operator= (const ServiceInformation_var &);
    ServiceInformation *operator-> (void);
    const ServiceInformation *operator-> (void) const;
    
    operator const ServiceInformation &() const;
    operator ServiceInformation &();
    operator ServiceInformation &() const;
    
    // Variable-size types only.
    operator ServiceInformation *&();
    
    // in, inout, out, _retn 
    const ServiceInformation &in (void) const;
    ServiceInformation &inout (void);
    ServiceInformation *&out (void);
    ServiceInformation *_retn (void);
    ServiceInformation *ptr (void) const;
  
  private:
    ServiceInformation *ptr_;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:445
  
  class TAO_Export ServiceInformation_out
  {
  public:
    ServiceInformation_out (ServiceInformation *&);
    ServiceInformation_out (ServiceInformation_var &);
    ServiceInformation_out (const ServiceInformation_out &);
    ServiceInformation_out &operator= (const ServiceInformation_out &);
    ServiceInformation_out &operator= (ServiceInformation *);
    operator ServiceInformation *&();
    ServiceInformation *&ptr (void);
    ServiceInformation *operator-> (void);
    
  private:
    ServiceInformation *&ptr_;
    // Assignment from T_var not allowed.
    void operator= (const ServiceInformation_var &);
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceInformation;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module CORBA

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceDetail &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceDetail*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceDetail *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceDetail *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceInformation &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceInformation*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceInformation *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceInformation *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceDetail &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceDetail &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceInformation &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceInformation &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:57

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceOption_H_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceOption_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceInformation::_tao_seq_ServiceOption &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ServiceInformation::_tao_seq_ServiceOption &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceOption_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:57

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceDetail_H_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceDetail_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceInformation::_tao_seq_ServiceDetail &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ServiceInformation::_tao_seq_ServiceDetail &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceDetail_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1009

#if defined (__ACE_INLINE__)
#include "ServicesC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

