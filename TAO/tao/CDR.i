// This may look like C, but it's really -*- C++ -*-
// $Id$

// ****************************************************************

ACE_INLINE void
CDR::mb_align (ACE_Message_Block* mb)
{
  char* start = ptr_align_binary (mb->base (), CDR::MAX_ALIGNMENT);
  mb->rd_ptr (start);
  mb->wr_ptr (start);

#if defined(ACE_PURIFY)
  // This is a good place to zero the buffer; this is not needed
  // by IIOP, but makes Purify happy.
  if (mb->base () != 0)
    {
      (void) ACE_OS::memset (mb->base(), 0, mb->size());
    }
#endif
}

// ****************************************************************

// Decode the CDR stream.

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_char (CORBA::Char x)
{
  return this->write_1 (ACE_reinterpret_cast(const CORBA::Octet*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_wchar (CORBA::WChar x)
{
  return this->write_2 (ACE_reinterpret_cast(const CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_octet (CORBA::Octet x)
{
  return this->write_1 (ACE_reinterpret_cast(const CORBA::Octet*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_boolean (CORBA::Boolean x)
{
  return this->write_octet (x?1:0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_short (CORBA::Short x)
{
  return this->write_2 (ACE_reinterpret_cast(const CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_ushort (CORBA::UShort x)
{
  return this->write_2 (ACE_reinterpret_cast(const CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_long (CORBA::Long x)
{
  return this->write_4 (ACE_reinterpret_cast(const CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_ulong (CORBA::ULong x)
{
  return this->write_4 (ACE_reinterpret_cast(const CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_longlong (const CORBA::LongLong &x)
{
  return this->write_8 (ACE_reinterpret_cast(const CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_ulonglong (const CORBA::ULongLong &x)
{
  return this->write_8 (ACE_reinterpret_cast(const CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_float (CORBA::Float x)
{
  return this->write_4 (ACE_reinterpret_cast(const CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_double (const CORBA::Double &x)
{
  return this->write_8 (ACE_reinterpret_cast(const CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_longdouble (const CORBA::LongDouble &x)
{
  return this->write_16 (ACE_reinterpret_cast(const CORBA::LongDouble*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_string (const CORBA::Char *x)
{
  if (x != 0)
    return this->write_string (ACE_OS::strlen (x), x);
  return this->write_string (0, 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_wstring (const CORBA::WChar *x)
{
  if (x != 0)
    return this->write_wstring (ACE_OS::wslen (x), x);
  return this->write_wstring (0, 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_char_array (const CORBA::Char* x,
				 CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::OCTET_SIZE,
			    CDR::OCTET_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_wchar_array (const CORBA::WChar* x,
				  CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::SHORT_SIZE,
			    CDR::SHORT_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_octet_array (const CORBA::Octet* x,
                                  CORBA::ULong length)
{
  return this->write_array (x,
                            CDR::OCTET_SIZE,
                            CDR::OCTET_ALIGN,
                            length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_short_array (const CORBA::Short* x,
				  CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::SHORT_SIZE,
			    CDR::SHORT_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_ushort_array (const CORBA::UShort* x,
				   CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::SHORT_SIZE,
			    CDR::SHORT_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_long_array (const CORBA::Long* x,
				 CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::LONG_SIZE,
			    CDR::LONG_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_ulong_array (const CORBA::ULong* x,
				  CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::LONG_SIZE,
			    CDR::LONG_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_longlong_array (const CORBA::LongLong* x,
				     CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::LONGLONG_SIZE,
			    CDR::LONGLONG_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_ulonglong_array (const CORBA::ULongLong* x,
				      CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::LONGLONG_SIZE,
			    CDR::LONGLONG_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_float_array (const CORBA::Float* x,
				  CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::LONG_SIZE,
			    CDR::LONG_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_double_array (const CORBA::Double* x,
				   CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::LONGLONG_SIZE,
			    CDR::LONGLONG_ALIGN,
			    length);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::write_longdouble_array (const CORBA::LongDouble* x,
				       CORBA::ULong length)
{
  return this->write_array (x,
			    CDR::LONGDOUBLE_SIZE,
			    CDR::LONGDOUBLE_ALIGN,
			    length);
}

ACE_INLINE int
TAO_OutputCDR::good_bit (void) const
{
  return this->good_bit_;
}

ACE_INLINE const ACE_Message_Block*
TAO_OutputCDR::begin (void) const
{
  return &this->start_;
}

ACE_INLINE const ACE_Message_Block*
TAO_OutputCDR::end (void) const
{
  return this->current_->cont ();
}

ACE_INLINE const char*
TAO_OutputCDR::buffer (void) const
{
  return this->start_.rd_ptr ();
}

ACE_INLINE size_t
TAO_OutputCDR::length (void) const
{
  return this->start_.length ();
}

ACE_INLINE CORBA::TypeCode::traverse_status
TAO_OutputCDR::encode (CORBA::TypeCode_ptr tc,
		       const void *data,
		       const void *data2,
		       CORBA::Environment &env)
{
  TAO_Marshal_Object *mobj =
    this->factory_->make_marshal_object (tc, env);

  if (env.exception() == 0 && mobj != 0)
    return mobj->encode (tc, data, data2, this, env);
  return CORBA::TypeCode::TRAVERSE_STOP;
}

// ****************************************************************

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_char (CORBA::Char& x)
{
  return this->read_1 (ACE_reinterpret_cast(CORBA::Octet*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_wchar (CORBA::WChar& x)
{
  return this->read_2 (ACE_reinterpret_cast(CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_octet (CORBA::Octet& x)
{
  return this->read_1 (&x);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_boolean (CORBA::Boolean& x)
{
  CORBA::Octet tmp;
  this->read_octet (tmp);
  x =  tmp ? CORBA::B_TRUE : CORBA::B_FALSE;
  return this->good_bit_;
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_short (CORBA::Short& x)
{
  return this->read_2 (ACE_reinterpret_cast(CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_ushort (CORBA::UShort& x)
{
  return this->read_2 (ACE_reinterpret_cast(CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_long (CORBA::Long& x)
{
  return this->read_4 (ACE_reinterpret_cast(CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_ulong (CORBA::ULong& x)
{
  return this->read_4 (ACE_reinterpret_cast(CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_longlong (CORBA::LongLong& x)
{
  return this->read_8 (ACE_reinterpret_cast(CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_ulonglong (CORBA::ULongLong& x)
{
  return this->read_8 (ACE_reinterpret_cast(CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_float (CORBA::Float& x)
{
  return this->read_4 (ACE_reinterpret_cast(CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_double (CORBA::Double& x)
{
  return this->read_8 (ACE_reinterpret_cast(CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_longdouble (CORBA::LongDouble& x)
{
  return this->read_16 (ACE_reinterpret_cast(CORBA::LongDouble*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_char_array (CORBA::Char* x,
			       CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::OCTET_SIZE,
			   CDR::OCTET_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_wchar_array (CORBA::WChar* x,
				CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::SHORT_SIZE,
			   CDR::SHORT_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_octet_array (CORBA::Octet* x,
				CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::OCTET_SIZE,
			   CDR::OCTET_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_short_array (CORBA::Short* x,
				CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::SHORT_SIZE,
			   CDR::SHORT_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_ushort_array (CORBA::UShort* x,
				 CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::SHORT_SIZE,
			   CDR::SHORT_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_long_array (CORBA::Long* x,
			       CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::LONG_SIZE,
			   CDR::LONG_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_ulong_array (CORBA::ULong* x,
				CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::LONG_SIZE,
			   CDR::LONG_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_longlong_array (CORBA::LongLong* x,
				   CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::LONGLONG_SIZE,
			   CDR::LONGLONG_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_ulonglong_array (CORBA::ULongLong* x,
				    CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::LONGLONG_SIZE,
			   CDR::LONGLONG_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_float_array (CORBA::Float* x,
				CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::LONG_SIZE,
			   CDR::LONG_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_double_array (CORBA::Double* x,
				 CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::LONGLONG_SIZE,
			   CDR::LONGLONG_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::read_longdouble_array (CORBA::LongDouble* x,
				     CORBA::ULong length)
{
  return this->read_array (x,
			   CDR::LONGDOUBLE_SIZE,
			   CDR::LONGDOUBLE_ALIGN,
			   length);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_char (void)
{
  CORBA::Char x;
  return this->read_1 (ACE_reinterpret_cast(CORBA::Octet*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_wchar (void)
{
  CORBA::WChar x;
  return this->read_2 (ACE_reinterpret_cast(CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_octet (void)
{
  CORBA::Octet x;
  return this->read_1 (&x);
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_boolean (void)
{
  CORBA::Octet tmp;
  this->read_octet (tmp);
  return this->good_bit_;
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_short (void)
{
  CORBA::Short x;
  return this->read_2 (ACE_reinterpret_cast(CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_ushort (void)
{
  CORBA::UShort x;
  return this->read_2 (ACE_reinterpret_cast(CORBA::UShort*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_long (void)
{
  CORBA::Long x;
  return this->read_4 (ACE_reinterpret_cast(CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_ulong (void)
{
  CORBA::ULong x;
  return this->read_4 (ACE_reinterpret_cast(CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_longlong (void)
{
  CORBA::LongLong x;
  return this->read_8 (ACE_reinterpret_cast(CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_ulonglong (void)
{
  CORBA::ULongLong x;
  return this->read_8 (ACE_reinterpret_cast(CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_float (void)
{
  CORBA::Float x;
  return this->read_4 (ACE_reinterpret_cast(CORBA::ULong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_double (void)
{
  CORBA::Double x;
  return this->read_8 (ACE_reinterpret_cast(CORBA::ULongLong*,&x));
}

ACE_INLINE CORBA_Boolean
TAO_InputCDR::skip_longdouble (void)
{
  CORBA::LongDouble x;
  return this->read_16 (ACE_reinterpret_cast(CORBA::LongDouble*,&x));
}

ACE_INLINE int
TAO_InputCDR::good_bit (void) const
{
  return this->good_bit_;
}

ACE_INLINE CORBA::TypeCode::traverse_status
TAO_InputCDR::decode (CORBA::TypeCode_ptr tc,
		       const void *data,
		       const void *data2,
		       CORBA::Environment &env)
{
  TAO_Marshal_Object *mobj =
    this->factory_->make_marshal_object (tc, env);

  if (env.exception() == 0 && mobj != 0)
    return mobj->decode (tc, data, data2, this, env);
  return CORBA::TypeCode::TRAVERSE_STOP;
}

ACE_INLINE CORBA::TypeCode::traverse_status
TAO_InputCDR::skip (CORBA::TypeCode_ptr tc,
                    CORBA::Environment &env)
{
  TAO_Marshal_Object *mobj =
    this->factory_->make_marshal_object (tc, env);

  if (env.exception() == 0 && mobj != 0)
    return mobj->skip (tc, this, env);
  return CORBA::TypeCode::TRAVERSE_STOP;
}

ACE_INLINE size_t
TAO_InputCDR::length (void) const
{
  return this->start_.length ();
}

ACE_INLINE const ACE_Message_Block*
TAO_InputCDR::start (void) const
{
  return &this->start_;
}

ACE_INLINE char*
TAO_InputCDR::rd_ptr (void)
{
  return this->start_.rd_ptr ();
}

// ****************************************************************
// TODO: Use the CORBA_* types when they become available.

#if defined (ACE_HAS_BOOL)
ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::Boolean x)
{
  if (cdr.good_bit ())
    cdr.write_boolean (x);
  return cdr;
}
#endif /* ACE_HAS_BOOL */

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::Octet x)
{
  if (cdr.good_bit ())
    cdr.write_octet (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::Short x)
{
  if (cdr.good_bit ())
    cdr.write_short (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::UShort x)
{
  if (cdr.good_bit ())
    cdr.write_short (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::Long x)
{
  if (cdr.good_bit ())
    cdr.write_long (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::ULong x)
{
  if (cdr.good_bit ())
    cdr.write_long (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::LongLong x)
{
  if (cdr.good_bit ())
    cdr.write_longlong (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::ULongLong x)
{
  if (cdr.good_bit ())
    cdr.write_ulonglong (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::Float x)
{
  if (cdr.good_bit ())
    cdr.write_float (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::Double x)
{
  if (cdr.good_bit ())
    cdr.write_double (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, CORBA::Char x)
{
  if (cdr.good_bit ())
    cdr.write_char (x);
  return cdr;
}

ACE_INLINE TAO_OutputCDR&
operator<< (TAO_OutputCDR& cdr, const CORBA::Char* x)
{
  if (cdr.good_bit ())
    cdr.write_string (x);
  return cdr;
}

#if defined (ACE_HAS_BOOL)
ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Boolean &x)
{
  if (cdr.good_bit ())
    cdr.read_boolean (x);
  return cdr;
}
#endif /* ACE_HAS_BOOL */

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Octet &x)
{
  if (cdr.good_bit ())
    cdr.read_octet (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Short &x)
{
  if (cdr.good_bit ())
    cdr.read_short (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::UShort &x)
{
  if (cdr.good_bit ())
    cdr.read_ushort (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Long &x)
{
  if (cdr.good_bit ())
    cdr.read_long (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::ULong &x)
{
  if (cdr.good_bit ())
    cdr.read_ulong (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::LongLong &x)
{
  if (cdr.good_bit ())
    cdr.read_longlong (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::ULongLong &x)
{
  if (cdr.good_bit ())
    cdr.read_ulonglong (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Float &x)
{
  if (cdr.good_bit ())
    cdr.read_float (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Double &x)
{
  if (cdr.good_bit ())
    cdr.read_double (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Char &x)
{
  if (cdr.good_bit ())
    cdr.read_char (x);
  return cdr;
}

ACE_INLINE TAO_InputCDR&
operator>> (TAO_InputCDR& cdr, CORBA::Char*&x)
{
  if (cdr.good_bit ())
    cdr.read_string (x);
  return cdr;
}

// ***************************************************************************
// We must define these methods here because they use the "read_*" inlined
// methods of the TAO_InputCDR class
// ***************************************************************************

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_boolean (TAO_InputCDR &stream)
{
  CORBA::Boolean x;
  return (stream.read_boolean (x) ? this->write_boolean (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_char (TAO_InputCDR &stream)
{
  CORBA::Char x;
  return (stream.read_char (x) ? this->write_char (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_wchar (TAO_InputCDR &stream)
{
  CORBA::WChar x;
  return (stream.read_wchar (x) ? this->write_wchar (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_octet (TAO_InputCDR &stream)
{
  CORBA::Octet x;
  return (stream.read_octet (x) ? this->write_octet (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_short (TAO_InputCDR &stream)
{
  CORBA::Short x;
  return (stream.read_short (x) ? this->write_short (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_ushort (TAO_InputCDR &stream)
{
  CORBA::UShort x;
  return (stream.read_ushort (x) ? this->write_ushort (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_long (TAO_InputCDR &stream)
{
  CORBA::Long x;
  return (stream.read_long (x) ? this->write_long (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_ulong (TAO_InputCDR &stream)
{
  CORBA::ULong x;
  return (stream.read_ulong (x) ? this->write_ulong (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_longlong (TAO_InputCDR &stream)
{
  CORBA::LongLong x;
  return (stream.read_longlong (x) ? this->write_longlong (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_ulonglong (TAO_InputCDR &stream)
{
  CORBA::ULongLong x;
  return (stream.read_ulonglong (x) ? this->write_ulonglong (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_float (TAO_InputCDR &stream)
{
  CORBA::Float x;
  return (stream.read_float (x) ? this->write_float (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_double (TAO_InputCDR &stream)
{
  CORBA::Double x;
  return (stream.read_double (x) ? this->write_double (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_longdouble (TAO_InputCDR &stream)
{
  CORBA::LongDouble x;
  return (stream.read_longdouble (x) ? this->write_longdouble (x) : 0);
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_string (TAO_InputCDR &stream)
{
  char *x;
  CORBA::Boolean flag = (stream.read_string (x) ? this->write_string (x) : 0);
  CORBA::string_free (x);
  return flag;
}

ACE_INLINE CORBA_Boolean
TAO_OutputCDR::append_wstring (TAO_InputCDR &stream)
{
  CORBA::WChar *x;
  CORBA::Boolean flag = (stream.read_wstring (x) ? this->write_wstring (x) : 0);
  CORBA::wstring_free (x);
  return flag;
}

ACE_INLINE CORBA::TypeCode::traverse_status
TAO_OutputCDR::append (CORBA::TypeCode_ptr tc,
                       TAO_InputCDR *src,
                       CORBA::Environment &env)
{
  TAO_Marshal_Object *mobj =
    this->factory_->make_marshal_object (tc, env);

  if (env.exception() == 0 && mobj != 0)
    return mobj->append (tc, src, this, env);
  return CORBA::TypeCode::TRAVERSE_STOP;
}
