// file      : CCF/IDL3/SemanticAction/HomeFactory.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CCF_IDL3_SEMANTIC_ACTION_HOME_FACTORY_HPP
#define CCF_IDL3_SEMANTIC_ACTION_HOME_FACTORY_HPP

#include "CCF/IDL3/SemanticAction/Elements.hpp"

namespace CCF
{
  namespace IDL3
  {
    namespace SemanticAction
    {
      //
      //
      //
      class HomeFactory
      {
      public:

        virtual void
        begin (SimpleIdentifierPtr const& id) = 0;

        virtual void
        parameter (IdentifierPtr const& type,
                   SimpleIdentifierPtr const& name) = 0;

        virtual void
        end () = 0;
      };
    }
  }
}

#endif  // CCF_IDL3_SEMANTIC_ACTION_HOME_FACTORY_HPP
