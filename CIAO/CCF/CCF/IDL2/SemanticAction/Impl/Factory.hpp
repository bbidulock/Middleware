// file      : CCF/IDL2/SemanticAction/Impl/Factory.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CCF_IDL2_SEMANTIC_ACTION_IMPL_FACTORY_HPP
#define CCF_IDL2_SEMANTIC_ACTION_IMPL_FACTORY_HPP

#include "CCF/IDL2/SemanticAction/Factory.hpp"

#include "CCF/IDL2/SemanticAction/Impl/Include.hpp"
#include "CCF/IDL2/SemanticAction/Impl/TypeId.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Module.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Interface.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Attribute.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Operation.hpp"

namespace CCF
{
  namespace IDL2
  {
    namespace SemanticAction
    {
      namespace Impl
      {
        //
        //
        //
        class Factory : public virtual IDL2::SemanticAction::Factory
        {
        public:
          virtual
          ~Factory () throw () {}


          Factory (CompilerElements::Context& context,
                   Diagnostic::Stream& dout,
                   SyntaxTree::TranslationRegionPtr const& r)
              : trace_ (context.get ("idl2::semantic-action::trace", false)),

                scope_ (r->scope ()),

                include_ (trace_, *this, r, scope_),
                type_id_ (trace_, scope_),
                type_prefix_ (trace_, scope_),
                module_ (trace_, scope_),
                interface_ (trace_, scope_),
                attribute_ (trace_, scope_),
                operation_ (trace_, scope_)
          {
          }

          virtual SemanticAction::Include&
          include ()
          {
            return include_;
          }

          virtual SemanticAction::TypeId&
          type_id ()
          {
            return type_id_;
          }

          virtual SemanticAction::TypePrefix&
          type_prefix ()
          {
            return type_prefix_;
          }

          virtual SemanticAction::Module&
          module ()
          {
            return module_;
          }

          virtual SemanticAction::Interface&
          interface ()
          {
            return interface_;
          }

          virtual SemanticAction::Attribute&
          attribute ()
          {
            return attribute_;
          }

          virtual SemanticAction::Operation&
          operation ()
          {
            return operation_;
          }

        protected:
          bool trace_;

          SyntaxTree::ScopePtr scope_;
          SyntaxTree::TranslationRegionPtr region_;

          Include include_;
          TypeId type_id_;
          TypePrefix type_prefix_;
          Module module_;
          Interface interface_;
          Attribute attribute_;
          Operation operation_;
        };
      }
    }
  }
}

#endif  // CCF_IDL2_SEMANTIC_ACTION_IMPL_FACTORY_HPP
