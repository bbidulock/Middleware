/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    Functor.i
//
// = DESCRIPTION
//    Inlinable method definitions for non-templatized classes
//    and template specializations implementing the GOF Command Pattern,
//    and STL-style functors.
//
// = AUTHOR
//    Chris Gill           <cdgill@cs.wustl.edu>
//
//    Based on Command Pattern implementations originally done by
//
//    Carlos O'Ryan        <coryan@cs.wustl.edu>  and
//    Douglas C. Schmidt   <schmidt@cs.wustl.edu> and
//    Sergio Flores-Gaitan <sergio@cs.wustl.edu>
//
//    and on STL-style functor implementations originally done by
//
//    Irfan Pyarali  <irfan@cs.wustl.edu>
//
// ============================================================================

//////////////////////////////////////////////////////////////
// GOF Command Pattern Classes and Template Specializations //
//////////////////////////////////////////////////////////////

// Default constructor.

ACE_INLINE
ACE_Command_Base::ACE_Command_Base (void)
{
}

// Virtaul destructor.

ACE_INLINE
ACE_Command_Base::~ACE_Command_Base (void)
{
}

////////////////////////////////////////////////////////////
// STL-style Functor Classes and Template Specializations //
////////////////////////////////////////////////////////////

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE 
u_long
ACE_Hash<char>::operator () (char t) const
{
  return t;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<signed char>::operator () (signed char t) const
{
  return t;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<unsigned char>::operator () (unsigned char t) const
{
  return t;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<ACE_INT16>::operator () (ACE_INT16 t) const
{
  return t;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<ACE_UINT16>::operator () (ACE_UINT16 t) const
{
  return t;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<ACE_INT32>::operator () (ACE_INT32 t) const
{
  return t;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<ACE_UINT32>::operator () (ACE_UINT32 t) const
{
  return t;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<ACE_UINT64>::operator () (ACE_UINT64 t) const
{
  return ACE_U64_TO_U32 (t);
}


ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<const ACE_TCHAR *>::operator () (const ACE_TCHAR *t) const
{
  return ACE::hash_pjw (t);
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE u_long
ACE_Hash<ACE_TCHAR *>::operator () (const ACE_TCHAR *t) const
{
  return ACE::hash_pjw (t);
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE int
ACE_Equal_To<const ACE_TCHAR *>::operator () (const ACE_TCHAR *lhs, const ACE_TCHAR *rhs) const
{
  return !ACE_OS::strcmp (lhs, rhs);
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE int
ACE_Equal_To<ACE_TCHAR *>::operator () (const ACE_TCHAR *lhs, const ACE_TCHAR *rhs) const
{
  return !ACE_OS::strcmp (lhs, rhs);
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE int
ACE_Less_Than<const ACE_TCHAR *>::operator () (const ACE_TCHAR *lhs, const ACE_TCHAR *rhs) const
{
  return (ACE_OS::strcmp (lhs, rhs) < 0) ? 1 : 0;
}

ACE_TEMPLATE_METHOD_SPECIALIZATION
ACE_INLINE int
ACE_Less_Than<ACE_TCHAR *>::operator () (const ACE_TCHAR *lhs, const ACE_TCHAR *rhs) const
{
  return (ACE_OS::strcmp (lhs, rhs) < 0) ? 1 : 0;
}
