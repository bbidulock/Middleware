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

#ifndef TAO_IDL_IIOPC_H
#define TAO_IDL_IIOPC_H

#include "ace/pre.h"
#include "tao/TAO_Export.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/corbafwd.h"
#include "tao/Managed_Types.h"
#include "tao/Sequence_T.h"
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

TAO_NAMESPACE  IIOP
{
  struct ListenPoint;
  class ListenPoint_var;

  struct TAO_Export ListenPoint
  {

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef ListenPoint_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

    static void _tao_any_destructor (void*);

    TAO_String_Manager host;
    CORBA::UShort port;
  };

  class TAO_Export ListenPoint_var
  {
  public:
    ListenPoint_var (void); // default constructor
    ListenPoint_var (ListenPoint *);
    ListenPoint_var (const ListenPoint_var &); // copy constructor
    ~ListenPoint_var (void); // destructor

    ListenPoint_var &operator= (ListenPoint *);
    ListenPoint_var &operator= (const ListenPoint_var &);
    ListenPoint *operator-> (void);
    const ListenPoint *operator-> (void) const;

    operator const ListenPoint &() const;
    operator ListenPoint &();
    operator ListenPoint &() const;
    operator ListenPoint *&(); // variable-size types only

    // in, inout, out, _retn
    const ListenPoint &in (void) const;
    ListenPoint &inout (void);
    ListenPoint *&out (void);
    ListenPoint *_retn (void);
    ListenPoint *ptr (void) const;

  private:
    ListenPoint *ptr_;
  };

  class TAO_Export ListenPoint_out
  {
  public:
    ListenPoint_out (ListenPoint *&);
    ListenPoint_out (ListenPoint_var &);
    ListenPoint_out (const ListenPoint_out &);
    ListenPoint_out &operator= (const ListenPoint_out &);
    ListenPoint_out &operator= (ListenPoint *);
    operator ListenPoint *&();
    ListenPoint *&ptr (void);
    ListenPoint *operator-> (void);

  private:
    ListenPoint *&ptr_;
    // assignment from T_var not allowed
    void operator= (const ListenPoint_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ListenPoint;


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_IIOP_LISTENPOINTLIST_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_IIOP_LISTENPOINTLIST_CH_

    class TAO_EXPORT_NESTED_MACRO _TAO_Unbounded_Sequence_IIOP_ListenPointList : public TAO_Unbounded_Base_Sequence
    {
    public:
      // = Initialization and termination methods.

      _TAO_Unbounded_Sequence_IIOP_ListenPointList (void); // Default constructor.
      _TAO_Unbounded_Sequence_IIOP_ListenPointList (CORBA::ULong maximum);
      _TAO_Unbounded_Sequence_IIOP_ListenPointList (CORBA::ULong maximum,
        CORBA::ULong length,
        ListenPoint *data,
        CORBA::Boolean release = 0);
      _TAO_Unbounded_Sequence_IIOP_ListenPointList (const _TAO_Unbounded_Sequence_IIOP_ListenPointList &rhs);
      _TAO_Unbounded_Sequence_IIOP_ListenPointList &operator= (const _TAO_Unbounded_Sequence_IIOP_ListenPointList &rhs);
      virtual ~_TAO_Unbounded_Sequence_IIOP_ListenPointList (void); // Dtor.
      // = Accessors.
      ListenPoint &operator[] (CORBA::ULong i);
      const ListenPoint &operator[] (CORBA::ULong i) const;
      // = Static operations.
      static ListenPoint *allocbuf (CORBA::ULong size);
      static void freebuf (ListenPoint *buffer);
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      // Implement the TAO_Base_Sequence methods (see Sequence.h)

      ListenPoint *get_buffer (CORBA::Boolean orphan = 0);
      const ListenPoint *get_buffer (void) const;
      void replace (CORBA::ULong max,
        CORBA::ULong length,
        ListenPoint *data,
        CORBA::Boolean release);
    };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_IIOP_LISTENPOINTLIST_CH_)
#define _IIOP_LISTENPOINTLIST_CH_

  class ListenPointList;
  class ListenPointList_var;

  // *************************************************************
  // ListenPointList
  // *************************************************************

  class TAO_Export ListenPointList : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
    _TAO_Unbounded_Sequence_IIOP_ListenPointList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
    TAO_Unbounded_Sequence<ListenPoint>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
  {
  public:
    ListenPointList (void); // default ctor
    ListenPointList (CORBA::ULong max); // uses max size
    ListenPointList (
      CORBA::ULong max,
      CORBA::ULong length,
      ListenPoint *buffer,
      CORBA::Boolean release = 0
    );
    ListenPointList (const ListenPointList &); // copy ctor
    ~ListenPointList (void);
    static void _tao_any_destructor (void*);

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef ListenPointList_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  };

#endif /* end #if !defined */


#if !defined (_IIOP_LISTENPOINTLIST___VAR_CH_)
#define _IIOP_LISTENPOINTLIST___VAR_CH_

  // *************************************************************
  // class IIOP::ListenPointList_var
  // *************************************************************

  class TAO_Export ListenPointList_var
  {
  public:
    ListenPointList_var (void); // default constructor
    ListenPointList_var (ListenPointList *);
    ListenPointList_var (const ListenPointList_var &); // copy constructor
    ~ListenPointList_var (void); // destructor

    ListenPointList_var &operator= (ListenPointList *);
    ListenPointList_var &operator= (const ListenPointList_var &);
    ListenPointList *operator-> (void);
    const ListenPointList *operator-> (void) const;

    operator const ListenPointList &() const;
    operator ListenPointList &();
    operator ListenPointList &() const;
    operator ListenPointList *&(); // variable-size base types only

    ListenPoint & operator[] (CORBA::ULong index);
    const ListenPoint & operator[] (CORBA::ULong index) const;

    // in, inout, out, _retn
    const ListenPointList &in (void) const;
    ListenPointList &inout (void);
    ListenPointList *&out (void);
    ListenPointList *_retn (void);
    ListenPointList *ptr (void) const;

  private:
    ListenPointList *ptr_;
  };


#endif /* end #if !defined */


#if !defined (_IIOP_LISTENPOINTLIST___OUT_CH_)
#define _IIOP_LISTENPOINTLIST___OUT_CH_

  class TAO_Export ListenPointList_out
  {
  public:
    ListenPointList_out (ListenPointList *&);
    ListenPointList_out (ListenPointList_var &);
    ListenPointList_out (const ListenPointList_out &);
    ListenPointList_out &operator= (const ListenPointList_out &);
    ListenPointList_out &operator= (ListenPointList *);
    operator ListenPointList *&();
    ListenPointList *&ptr (void);
    ListenPointList *operator-> (void);
    ListenPoint & operator[] (CORBA::ULong index);

  private:
    ListenPointList *&ptr_;
    // assignment from T_var not allowed
    void operator= (const ListenPointList_var &);
  };


#endif /* end #if !defined */

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ListenPointList;

  struct BiDirIIOPServiceContext;
  class BiDirIIOPServiceContext_var;

  struct TAO_Export BiDirIIOPServiceContext
  {

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef BiDirIIOPServiceContext_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

    static void _tao_any_destructor (void*);

    ACE_NESTED_CLASS (IIOP, ListenPointList) listen_points;
  };

  class TAO_Export BiDirIIOPServiceContext_var
  {
  public:
    BiDirIIOPServiceContext_var (void); // default constructor
    BiDirIIOPServiceContext_var (BiDirIIOPServiceContext *);
    BiDirIIOPServiceContext_var (const BiDirIIOPServiceContext_var &); // copy constructor
    ~BiDirIIOPServiceContext_var (void); // destructor

    BiDirIIOPServiceContext_var &operator= (BiDirIIOPServiceContext *);
    BiDirIIOPServiceContext_var &operator= (const BiDirIIOPServiceContext_var &);
    BiDirIIOPServiceContext *operator-> (void);
    const BiDirIIOPServiceContext *operator-> (void) const;

    operator const BiDirIIOPServiceContext &() const;
    operator BiDirIIOPServiceContext &();
    operator BiDirIIOPServiceContext &() const;
    operator BiDirIIOPServiceContext *&(); // variable-size types only

    // in, inout, out, _retn
    const BiDirIIOPServiceContext &in (void) const;
    BiDirIIOPServiceContext &inout (void);
    BiDirIIOPServiceContext *&out (void);
    BiDirIIOPServiceContext *_retn (void);
    BiDirIIOPServiceContext *ptr (void) const;

  private:
    BiDirIIOPServiceContext *ptr_;
  };

  class TAO_Export BiDirIIOPServiceContext_out
  {
  public:
    BiDirIIOPServiceContext_out (BiDirIIOPServiceContext *&);
    BiDirIIOPServiceContext_out (BiDirIIOPServiceContext_var &);
    BiDirIIOPServiceContext_out (const BiDirIIOPServiceContext_out &);
    BiDirIIOPServiceContext_out &operator= (const BiDirIIOPServiceContext_out &);
    BiDirIIOPServiceContext_out &operator= (BiDirIIOPServiceContext *);
    operator BiDirIIOPServiceContext *&();
    BiDirIIOPServiceContext *&ptr (void);
    BiDirIIOPServiceContext *operator-> (void);

  private:
    BiDirIIOPServiceContext *&ptr_;
    // assignment from T_var not allowed
    void operator= (const BiDirIIOPServiceContext_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_BiDirIIOPServiceContext;


}
TAO_NAMESPACE_CLOSE // module IIOP

TAO_Export void operator<<= (CORBA::Any &, const IIOP::ListenPoint &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IIOP::ListenPoint*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IIOP::ListenPoint *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IIOP::ListenPoint *&);
TAO_Export void operator<<= (CORBA::Any &, const IIOP::ListenPointList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IIOP::ListenPointList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IIOP::ListenPointList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IIOP::ListenPointList *&);
TAO_Export void operator<<= (CORBA::Any &, const IIOP::BiDirIIOPServiceContext &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IIOP::BiDirIIOPServiceContext*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IIOP::BiDirIIOPServiceContext *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IIOP::BiDirIIOPServiceContext *&);

#ifndef __ACE_INLINE__

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IIOP::ListenPoint &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IIOP::ListenPoint &);

#if !defined _TAO_CDR_OP_IIOP_ListenPointList_H_
#define _TAO_CDR_OP_IIOP_ListenPointList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IIOP::ListenPointList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IIOP::ListenPointList &
  );

#endif /* _TAO_CDR_OP_IIOP_ListenPointList_H_ */

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IIOP::BiDirIIOPServiceContext &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IIOP::BiDirIIOPServiceContext &);

#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "IIOPC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* ifndef */
