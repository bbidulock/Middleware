// -*- C++ -*- $Id$ */
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


#if !defined (_CORBA_CURRENT___CI_)
#define _CORBA_CURRENT___CI_

ACE_INLINE CORBA_Current_ptr
tao_CORBA_Current_duplicate (
    CORBA_Current_ptr p
  )
{
  return CORBA_Current::_duplicate (p);
}

ACE_INLINE void
tao_CORBA_Current_release (
    CORBA_Current_ptr p
  )
{
  CORBA::release (p);
}

ACE_INLINE CORBA_Current_ptr
tao_CORBA_Current_nil (
    void
  )
{
  return CORBA_Current::_nil ();
}

ACE_INLINE CORBA_Current_ptr
tao_CORBA_Current_narrow (
    CORBA::Object *p,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return CORBA_Current::_narrow (p, ACE_TRY_ENV);
}

ACE_INLINE CORBA::Object *
tao_CORBA_Current_upcast (
    void *src
  )
{
  CORBA_Current **tmp =
    ACE_static_cast (CORBA_Current **, src);
  return *tmp;
}


#endif /* end #if !defined */

