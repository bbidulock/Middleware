// file      : CCF/IDL3/SemanticAction/Impl/Publishes.cpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#include "CCF/IDL3/SemanticGraph/Component.hpp"
#include "CCF/IDL3/SemanticAction/Impl/Publishes.hpp"

#include <iostream>

using std::cerr;
using std::endl;

namespace CCF
{
  namespace IDL3
  {
    namespace SemanticAction
    {
      namespace Impl
      {
        using namespace SemanticGraph;

        Publishes::
        ~Publishes () throw ()
        {
        }

        Publishes::
        Publishes (Context& c)
            : Base (c)
        {
        }

        void Publishes::
        type (IdentifierPtr const& id)
        {
          if (ctx.trace ()) cerr << "publishes " << id;

          type_ = 0;

          Name name (id->lexeme ());
          ScopedName from (ctx.scope ().scoped_name ());

          try
          {
            try
            {
              type_ = &resolve<EventType> (from, name);
            }
            catch (Resolve const&)
            {
              cerr << "error: invalid publishes declaration" << endl;
              throw;
            }
          }
          catch (NotFound const&)
          {
            cerr << "no eventtype with name \'" << name
                 << "\' visible from scope \'" << from << "\'" << endl;
          }
          catch (WrongType const&)
          {
            cerr << "declaration with name \'" << name
                 << "\' visible from scope \'" << from
                 << "\' is not an eventtype declaration" << endl;
            cerr << "using non-eventtype in publishes declaration is illegal"
                 << endl;
          }
        }

        void Publishes::
        name (SimpleIdentifierPtr const& id)
        {
          if (ctx.trace ()) cerr << " " << id << endl;

          if (type_)
          {
            Publisher& p (ctx.tu ().new_node<Publisher> ());
            
            ctx.tu ().new_edge<Belongs> (p, *type_);
            ctx.tu ().new_edge<Defines> (ctx.scope (), p, id->lexeme ());
          }
        }
      }
    }
  }
}
