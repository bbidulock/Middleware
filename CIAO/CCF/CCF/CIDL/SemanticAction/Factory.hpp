// file      : CCF/CIDL/SemanticAction/Factory.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $id$

#ifndef CCF_CIDL_SEMANTIC_ACTION_FACTORY_HPP
#define CCF_CIDL_SEMANTIC_ACTION_FACTORY_HPP

#include "CCF/IDL3/SemanticAction/Factory.hpp"

namespace CCF
{
  namespace CIDL
  {
    namespace SemanticAction
    {
      //
      //
      //
      class Factory : public virtual IDL3::SemanticAction::Factory
      {
      public:
        virtual Composition&
        composition () = 0;

        virtual HomeExecutor&
        home_executor () = 0;
      };
    }
  }
}

#endif  // CCF_CIDL_SEMANTIC_ACTION_FACTORY_HPP
