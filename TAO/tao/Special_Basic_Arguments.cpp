// $Id$

#include "tao/Special_Basic_Arguments.h"

ACE_RCSID (tao,
           Special_Basic_Arguments,
           "$Id$")

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO::Traits<CORBA::Char>;
template class TAO::Traits<CORBA::WChar>;
template class TAO::Traits<CORBA::Octet>;
template class TAO::Traits<ACE_InputCDR::to_boolean>;

template class TAO::Special_Basic_Arg_Traits_T<CORBA::Char,
                                               ACE_InputCDR::to_char,
                                               ACE_OutputCDR::from_char>;

template class TAO::Special_Basic_Arg_Traits_T<CORBA::WChar,
                                               ACE_InputCDR::to_wchar,
                                               ACE_OutputCDR::from_wchar>;

template class TAO::Special_Basic_Arg_Traits_T<CORBA::Octet,
                                               ACE_InputCDR::to_octet,
                                               ACE_OutputCDR::from_octet>;

template class TAO::Special_Basic_Arg_Traits_T<CORBA::Boolean,
                                               ACE_InputCDR::to_boolean,
                                               ACE_OutputCDR::from_boolean>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate TAO::Traits<CORBA::Char>
# pragma instantiate TAO::Traits<CORBA::WChar>
# pragma instantiate TAO::Traits<CORBA::Octet>
# pragma instantiate TAO::Traits<ACE_InputCDR::to_boolean>

# pragma instantiate TAO::Special_Basic_Arg_Traits_T< \
                              CORBA::Char, \
                              ACE_InputCDR::to_char, \
                              ACE_OutputCDR::from_char \
                            >

# pragma instantiate TAO::Special_Basic_Arg_Traits_T< \
                              CORBA::WChar, \
                              ACE_InputCDR::to_wchar, \
                              ACE_OutputCDR::from_wchar \
                            >

# pragma instantiate TAO::Special_Basic_Arg_Traits_T< \
                              CORBA::Octet, \
                              ACE_InputCDR::to_octet, \
                              ACE_OutputCDR::from_octet \
                            >

# pragma instantiate TAO::Special_Basic_Arg_Traits_T< \
                              CORBA::Boolean, \
                              ACE_InputCDR::to_boolean, \
                              ACE_OutputCDR::from_boolean \
                            >

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
