/* -*- C++ -*- */
//$Id$
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_BOUNDSC_H_
#define _TAO_IDL_BOUNDSC_H_

#include "tao/corbafwd.h"
#include "tao/Exception.h"
#include "tao/CDR.h"
#include "tao/Any.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO
#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO
#endif /* TAO_EXPORT_NESTED_CLASSES */
#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if !defined (_CORBA_BOUNDS_CH_)
#define _CORBA_BOUNDS_CH_

  class  TAO_Export CORBA_Bounds : public CORBA::UserException
  {
  public:

    CORBA_Bounds (void); // default ctor
    CORBA_Bounds (const CORBA_Bounds &); // copy ctor
    ~CORBA_Bounds (void); // dtor
    CORBA_Bounds &operator= (const CORBA_Bounds &);


    virtual void _raise (void);

    virtual void _tao_encode (TAO_OutputCDR &cdr,
                              CORBA::Environment &) const;
    virtual void _tao_decode (TAO_InputCDR &cdr,
                              CORBA::Environment &);

    static CORBA_Bounds *_narrow (CORBA::Exception *);
    static void _tao_any_destructor (void*);

    // = TAO extension
    static CORBA::Exception *_alloc (void);

  }; // exception CORBA::Bounds

#endif /* end #if !defined */


void  operator<<= (CORBA::Any &, const CORBA::Bounds &); // copying version
void  operator<<= (CORBA::Any &, CORBA::Bounds*); // noncopying version
CORBA::Boolean  operator>>= (const CORBA::Any &, CORBA::Bounds *&);

#ifndef __ACE_INLINE__

CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA::Bounds &); //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA::Bounds &);

#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "tao/BoundsC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* ifndef */
