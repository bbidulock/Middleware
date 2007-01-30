divert(-1)

# file      : CCF/IDL2/SemanticGraph/Fundamental.cpp.m4
# author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
# cvs-id    : $Id$

include(`Fundamental.m4')

define(`fundamental_type',
  `fundamental_type_impl(`make_class_name(`$1')', `make_var_name(`$1')')')


define(`fundamental_type_impl', `

      // $1
      //
      //
      namespace
      {
        TypeInfo
        $2_init_ ()
        {
          TypeInfo ti (typeid ($1));
          ti.add_base (
            Access::PUBLIC, true, FundamentalType::static_type_info ());
          return ti;
        }

        TypeInfo $2_ ($2_init_ ());
      }

      TypeInfo const& $1::
      static_type_info () { return $2_; }')

divert(0)dnl
dnl
dnl
dnl
// file      : CCF/IDL2/SemanticGraph/Fundamental.cpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

// Note, that this file is automatically generated!
//

#include "CCF/IDL2/SemanticGraph/Fundamental.hpp"

namespace CCF
{
  namespace IDL2
  {
    namespace SemanticGraph
    {
      using Introspection::TypeInfo;
      using Introspection::Access;

      // FundamentalType
      //
      //
      namespace
      {
        TypeInfo
        fundamental_type_init_ ()
        {
          TypeInfo ti (typeid (FundamentalType));
          ti.add_base (Access::PUBLIC, true, Type::static_type_info ());
          return ti;
        }

        TypeInfo fundamental_type_ (fundamental_type_init_ ());
      }

      TypeInfo const& FundamentalType::
      static_type_info () { return fundamental_type_; }

      FundamentalType::
      ~FundamentalType ()
      {
      }
dnl
fundamental_type(`object')
fundamental_type(`value base')
fundamental_type(`any')
fundamental_type(`boolean')
fundamental_type(`char')
fundamental_type(`double')
fundamental_type(`float')
fundamental_type(`long')
fundamental_type(`long double')
fundamental_type(`long long')
fundamental_type(`octet')
fundamental_type(`short')
fundamental_type(`string')
fundamental_type(`unsigned long')
fundamental_type(`unsigned long long')
fundamental_type(`unsigned short')
fundamental_type(`void')
fundamental_type(`wchar')
fundamental_type(`wstring')
dnl
    }
  }
}
