// file      : CCF/IDL3/SemanticAction/Impl/EventType.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CCF_IDL3_SEMANTIC_ACTION_IMPL_EVENT_TYPE_HPP
#define CCF_IDL3_SEMANTIC_ACTION_IMPL_EVENT_TYPE_HPP

#include "CCF/IDL3/SemanticGraph/EventType.hpp"
#include "CCF/IDL3/SemanticAction/EventType.hpp"
#include "CCF/IDL3/SemanticAction/Impl/Elements.hpp"

namespace CCF
{
  namespace IDL3
  {
    namespace SemanticAction
    {
      namespace Impl
      {
        //
        //
        //
        class EventType : public virtual SemanticAction::EventType,
                          public virtual ScopeBase<SemanticGraph::EventType>
        {
        public:
          virtual
          ~EventType () throw ();

          EventType (Context& c);

          virtual void
          begin_concrete_def (SimpleIdentifierPtr const& id);

          virtual void
          begin_concrete_fwd (SimpleIdentifierPtr const& id);

          virtual void
          inherits (IdentifierPtr const& id);

          virtual void
          open_scope ();

          virtual void
          close_scope ();

          virtual void
          end ();
        };
      }
    }
  }
}

#endif  // CCF_IDL3_SEMANTIC_ACTION_IMPL_EVENT_TYPE_HPP
