// $Id$
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_SCIOP_ENDPOINTSC_H_
#define _TAO_IDL_SCIOP_ENDPOINTSC_H_

#include /**/ "ace/pre.h"

#include "strategies_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Managed_Types.h"
#include "tao/Sequence.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Strategies_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Strategies_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

struct TAO_SCIOP_Endpoint_Info;
class TAO_SCIOP_Endpoint_Info_var;

struct TAO_Strategies_Export TAO_SCIOP_Endpoint_Info
{

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef TAO_SCIOP_Endpoint_Info_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  static void _tao_any_destructor (void*);

  TAO_String_Manager host;
  CORBA::Short port;
  CORBA::Short priority;
};

extern TAO_Strategies_Export CORBA::TypeCode_ptr  _tc_TAO_SCIOP_Endpoint_Info;


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_TAO_SCIOPENDPOINTSEQUENCE_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_TAO_SCIOPENDPOINTSEQUENCE_CH_

  class TAO_EXPORT_NESTED_MACRO _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence : public TAO_Unbounded_Base_Sequence
  {
  public:
    // = Initialization and termination methods.

    _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (void); // Default constructor.
    _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (CORBA::ULong maximum);
    _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (CORBA::ULong maximum,
      CORBA::ULong length,
      TAO_SCIOP_Endpoint_Info *data,
      CORBA::Boolean release = 0);
    _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (const _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence &rhs);
    _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence &operator= (const _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence &rhs);
    virtual ~_TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (void); // Dtor.
    // = Accessors.
    TAO_SCIOP_Endpoint_Info &operator[] (CORBA::ULong i);
    const TAO_SCIOP_Endpoint_Info &operator[] (CORBA::ULong i) const;
    // = Static operations.
    static TAO_SCIOP_Endpoint_Info *allocbuf (CORBA::ULong size);
    static void freebuf (TAO_SCIOP_Endpoint_Info *buffer);
    virtual void _allocate_buffer (CORBA::ULong length);
    virtual void _deallocate_buffer (void);
    // Implement the TAO_Base_Sequence methods (see Sequence.h)

    TAO_SCIOP_Endpoint_Info *get_buffer (CORBA::Boolean orphan = 0);
    const TAO_SCIOP_Endpoint_Info *get_buffer (void) const;
    void replace (CORBA::ULong max,
      CORBA::ULong length,
      TAO_SCIOP_Endpoint_Info *data,
      CORBA::Boolean release);
  };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_TAO_SCIOPENDPOINTSEQUENCE_CH_)
#define _TAO_SCIOPENDPOINTSEQUENCE_CH_

class TAO_SCIOPEndpointSequence;
class TAO_SCIOPEndpointSequence_var;

// *************************************************************
// TAO_SCIOPEndpointSequence
// *************************************************************

class TAO_Strategies_Export TAO_SCIOPEndpointSequence : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<TAO_SCIOP_Endpoint_Info>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
{
public:
  TAO_SCIOPEndpointSequence (void); // default ctor
  TAO_SCIOPEndpointSequence (CORBA::ULong max); // uses max size
  TAO_SCIOPEndpointSequence (
    CORBA::ULong max,
    CORBA::ULong length,
    TAO_SCIOP_Endpoint_Info *buffer,
    CORBA::Boolean release=0
  );
  TAO_SCIOPEndpointSequence (const TAO_SCIOPEndpointSequence &); // copy ctor
  ~TAO_SCIOPEndpointSequence (void);
  static void _tao_any_destructor (void*);

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef TAO_SCIOPEndpointSequence_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

};

#endif /* end #if !defined */


#if !defined (_TAO_SCIOPENDPOINTSEQUENCE___VAR_CH_)
#define _TAO_SCIOPENDPOINTSEQUENCE___VAR_CH_

// *************************************************************
// class TAO_SCIOPEndpointSequence_var
// *************************************************************

class TAO_Strategies_Export TAO_SCIOPEndpointSequence_var
{
public:
  TAO_SCIOPEndpointSequence_var (void); // default constructor
  TAO_SCIOPEndpointSequence_var (TAO_SCIOPEndpointSequence *);
  TAO_SCIOPEndpointSequence_var (const TAO_SCIOPEndpointSequence_var &); // copy constructor
  ~TAO_SCIOPEndpointSequence_var (void); // destructor

  TAO_SCIOPEndpointSequence_var &operator= (TAO_SCIOPEndpointSequence *);
  TAO_SCIOPEndpointSequence_var &operator= (const TAO_SCIOPEndpointSequence_var &);
  TAO_SCIOPEndpointSequence *operator-> (void);
  const TAO_SCIOPEndpointSequence *operator-> (void) const;

  operator const TAO_SCIOPEndpointSequence &() const;
  operator TAO_SCIOPEndpointSequence &();
  operator TAO_SCIOPEndpointSequence &() const;
  operator TAO_SCIOPEndpointSequence *&(); // variable-size base types only

  TAO_SCIOP_Endpoint_Info &operator[] (CORBA::ULong index);
  // in, inout, out, _retn
  const TAO_SCIOPEndpointSequence &in (void) const;
  TAO_SCIOPEndpointSequence &inout (void);
  TAO_SCIOPEndpointSequence *&out (void);
  TAO_SCIOPEndpointSequence *_retn (void);
  TAO_SCIOPEndpointSequence *ptr (void) const;

private:
  TAO_SCIOPEndpointSequence *ptr_;
};


#endif /* end #if !defined */


extern TAO_Strategies_Export CORBA::TypeCode_ptr  _tc_TAO_SCIOPEndpointSequence;

#ifndef __ACE_INLINE__

TAO_Strategies_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_SCIOP_Endpoint_Info &);
TAO_Strategies_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_SCIOP_Endpoint_Info &);

#if !defined _TAO_CDR_OP_TAO_SCIOPEndpointSequence_H_
#define _TAO_CDR_OP_TAO_SCIOPEndpointSequence_H_

TAO_Strategies_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const TAO_SCIOPEndpointSequence &
  );
TAO_Strategies_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    TAO_SCIOPEndpointSequence &
  );

#endif /* _TAO_CDR_OP_TAO_SCIOPEndpointSequence_H_ */


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "sciop_endpoints.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* ifndef */
