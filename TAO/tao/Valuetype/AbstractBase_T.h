// -*- C++ -*-

//=============================================================================
/**
 *  @file     AbstractBase_T.h
 *
 *  $Id$
 *
 *  @author  Balachandran Natarajan <bala@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_ABSTRACTBASE_T_H
#define TAO_ABSTRACTBASE_T_H
#include /**/ "ace/pre.h"

#include "tao/Object_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace CORBA
{
  class AbstractBase;
  typedef AbstractBase *AbstractBase_ptr;
}

namespace TAO
{
  template<typename T>
  class AbstractBase_Narrow_Utils
  {
  public:
    typedef T *T_ptr;

    static T_ptr narrow (CORBA::AbstractBase_ptr,
                         const char *repo_id,
                         Proxy_Broker_Factory
                         ACE_ENV_ARG_DECL);

    static T_ptr unchecked_narrow (CORBA::AbstractBase_ptr,
                                   Proxy_Broker_Factory);

    static T_ptr unchecked_narrow (CORBA::AbstractBase_ptr,
                                   const char *repo_id,
                                   Proxy_Broker_Factory
                                   ACE_ENV_ARG_DECL);
  };
}

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "AbstractBase_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("AbstractBase_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /*TAO_ABSTRACTBASE_T_H*/
