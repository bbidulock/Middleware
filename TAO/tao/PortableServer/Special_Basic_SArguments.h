// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    Special_Basic_SArguments.h
 *
 *  $Id$
 *
 *  @authors Jeff Parsons and Carlos O'Ryan
 */
//=============================================================================


#ifndef TAO_SPECIAL_BASIC_SARGUMENTS_H
#define TAO_SPECIAL_BASIC_SARGUMENTS_H

#include /**/ "ace/pre.h"

#include "tao/PortableServer/portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/Special_Basic_SArgument_T.h"
#include "tao/Arg_Traits_T.h"

#include "ace/CDR_Stream.h"


namespace TAO
{
  /**
   *
   * @brief Specializations for (w)char, octet and boolean.
   *
   */

  template<>
  class TAO_PortableServer_Export SArg_Traits<ACE_InputCDR::to_char>
    : public Special_Basic_SArg_Traits_T<CORBA::Char,
                                         ACE_InputCDR::to_char,
                                         ACE_OutputCDR::from_char>
  {
  };

  template<>
  class TAO_PortableServer_Export SArg_Traits<ACE_InputCDR::to_wchar>
    : public Special_Basic_SArg_Traits_T<CORBA::WChar,
                                         ACE_InputCDR::to_wchar,
                                         ACE_OutputCDR::from_wchar>
  {
  };

  template<>
  class TAO_PortableServer_Export SArg_Traits<ACE_InputCDR::to_octet>
    : public Special_Basic_SArg_Traits_T<CORBA::Octet,
                                         ACE_InputCDR::to_octet,
                                         ACE_OutputCDR::from_octet>
  {
  };

  template<>
  class TAO_PortableServer_Export SArg_Traits<ACE_InputCDR::to_boolean>
    : public Special_Basic_SArg_Traits_T<CORBA::Boolean,
                                         ACE_InputCDR::to_boolean,
                                         ACE_OutputCDR::from_boolean>
  {
  };
};

#include /**/ "ace/post.h"

#endif /* TAO_SPECIAL_BASIC_SARGUMENTS_H */
