// file      : CIDLC/ExecImplSourceGenerator.cpp
// author    : Jeff Parsons <j.parsons@vanderbilt.edu>
// cvs-id    : $Id$

#include "ExecImplSourceGenerator.hpp"
#include "Literals.hpp"
#include "TypeNameEmitter.hpp"

#include "CCF/CodeGenerationKit/Regex.hpp"

#include <ostream>

using namespace CCF::CIDL;
using namespace CCF::CIDL::SemanticGraph;
using namespace StringLiterals;

namespace
{
  class Context
  {
  public:
    Context (std::ostream& os,
             string export_macro)
      : os_ (os),
        export_macro_ (export_macro)
    {
    }

  std::ostream&
  os ()
  {
    return os_;
  }

  string
  export_macro ()
  {
    return export_macro_;
  }

  private:
    std::ostream& os_;
    string export_macro_;
  };

  class EmitterBase
  {
  public:
    EmitterBase (Context& c)
      : ctx (c),
        os (ctx.os ())
    {
    }

  protected:
    Context& ctx;
    std::ostream& os;
  };

  struct ModuleEmitter : Traversal::Module, EmitterBase
  {
    ModuleEmitter (Context& c)
        : EmitterBase (c)
    {
    }

    virtual void
    pre (Type& t)
    {
      os << "namespace " << t.name () << "{";
    }

    virtual void
    post (Type&)
    {
      os << "}";
    }
  };

  struct CompositionEmitter : Traversal::Composition, EmitterBase
  {
    CompositionEmitter (Context& c)
      : EmitterBase (c)
    {
    }

    virtual void
    pre (Type& t)
    {
      os << STRS[CIDL_NS] << t.name () << "{";
    }

    virtual void
    post (Type&)
    {
      os << "}";
    }
  };

  template <typename T>
  struct OperationEmitter : Traversal::Operation, EmitterBase
  {
    OperationEmitter (Context& c, T& scope)
      : EmitterBase (c),
        scope_ (scope)
    {}

    virtual void
    name (Type& o)
    {
      os << endl
         << scope_.name () << "_exec_i::" << o.name ();
    }

    virtual void
    receives_pre (Type&)
    {
      os << " (" << endl;
    }

    virtual void
    receives_none (Type&)
    {
      os << " (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl;
    }

    virtual void
    receives_post (Type&)
    {
      os << endl << STRS[ENV_SRC_NOTUSED] << ")" << endl;
    }

    virtual void
    raises_pre (Type&)
    {
      os << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl;
    }

    virtual void
    raises_none (Type&)
    {
      os << STRS[EXCP_SNGL];
    }

    virtual void
    raises_post (Type&)
    {
      os << "))";
    }

    virtual void
    post (Type& o)
    {
      os << "{"
         << STRS[YCH] << endl;

      Traversal::Operation operation_emitter;

      Traversal::Belongs returns;
      operation_emitter.edge_traverser (returns);

      NullReturnEmitter return_emitter (os);
      returns.node_traverser (return_emitter);

      operation_emitter.traverse (o);

      os << "}";
    }

    virtual void
    comma (Type&)
    {
      os << "," << endl;
    }

  protected:
    T& scope_;
  };

  // For generating parameter names.
  template <typename T>
  struct ParameterEmitter : T
  {
    ParameterEmitter (std::ostream& os_)
      : os (os_)
    {}

    virtual void
    name (typename T::Type& p)
    {
      os << " /* " << p.name () << " */";
    }

  private:
    std::ostream& os;
  };

  // Generic scoped typename emitter used by various other emitters.
  struct TypeNameEmitter : Traversal::Type
  {
    TypeNameEmitter (std::ostream& os_)
      : os (os_)
    {}

    virtual void
    traverse (SemanticGraph::Type& t)
    {
      os << t.scoped_name ();
    }

  private:
    std::ostream& os;
  };

  // Generic local typename emitter used by various other emitters.
  struct SimpleTypeNameEmitter : Traversal::Type
  {
    SimpleTypeNameEmitter (std::ostream& os_)
      : os (os_)
    {}

    virtual void
    traverse (SemanticGraph::Type& t)
    {
      os << t.name ();
    }

  private:
    std::ostream& os;
  };

  // Generate name of type's enclosing scope.
  struct EnclosingTypeNameEmitter : Traversal::Type
  {
    EnclosingTypeNameEmitter (std::ostream& os_)
      : os (os_)
    {}

    virtual void
    traverse (SemanticGraph::Type& t)
    {
      os << t.scoped_name ().scope_name ();
    }

  private:
    std::ostream& os;
  };

  // Emits typename minus the leading double colon.
  struct StrippedTypeNameEmitter : Traversal::Type
  {
    StrippedTypeNameEmitter (std::ostream& os_)
      : os (os_)
    {}

    virtual void
    traverse (SemanticGraph::Type& t)
    {
      ScopedName scoped (t.scoped_name ());
      os << Name (scoped.begin () + 1, scoped.end ());
    }

  private:
    std::ostream& os;
  };

  // Generates operations associated with attributes.
  // @@@ (JP) Need to support exceptions.
  template <typename T>
  struct AttributeEmitter : Traversal::ReadWriteAttribute,
                            EmitterBase
  {
    AttributeEmitter (Context& c, T& scope)
      : EmitterBase (c),
        scope_ (scope),
        write_type_name_emitter_ (c.os ()),
        read_type_name_emitter_ (c.os ()),
        return_emitter_ (c.os ())
    {
      write_belongs_.node_traverser (write_type_name_emitter_);
      read_belongs_.node_traverser (read_type_name_emitter_);
      return_belongs_.node_traverser (return_emitter_);
    }

    virtual void traverse (SemanticGraph::ReadWriteAttribute& a)
    {
      Traversal::ReadWriteAttribute::belongs (a, read_belongs_);

      os << endl
         << scope_.name () << "_exec_i::" << a.name ()
         << " (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_SNGL] << endl
         << "{"
         << STRS[YCH] << endl;

      Traversal::ReadWriteAttribute::belongs (a, return_belongs_);

      os << "}";

      os << "void" << endl
         << scope_.name () << "_exec_i::" << a.name ()
         << " (" << endl;

      Traversal::ReadWriteAttribute::belongs (a, write_belongs_);

      os << " /* " << a.name () << " */" << endl
         << STRS[ENV_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_SNGL] << endl
         << "{"
         << STRS[YCH]
         << "}";
    }

  protected:
    T& scope_;

  private:
    INArgTypeNameEmitter write_type_name_emitter_;
    ReturnTypeNameEmitter read_type_name_emitter_;
    NullReturnEmitter return_emitter_;
    Traversal::Belongs write_belongs_;
    Traversal::Belongs read_belongs_;
    Traversal::Belongs return_belongs_;
  };

  // Generates operations associated with readonly attributes.
  // @@@ (JP) Need to support exceptions.
  template <typename T>
  struct ReadOnlyAttributeEmitter : Traversal::ReadAttribute,
                                    EmitterBase
  {
    ReadOnlyAttributeEmitter (Context& c, T& scope)
      : EmitterBase (c),
        scope_ (scope),
        read_type_name_emitter_ (c.os ()),
        return_emitter_ (c.os ())
    {
      read_belongs_.node_traverser (read_type_name_emitter_);
      return_belongs_.node_traverser (return_emitter_);
    }

    virtual void traverse (SemanticGraph::ReadAttribute& a)
    {
      Traversal::ReadAttribute::belongs (a, read_belongs_);

      os << endl
         << scope_.name () << "_exec_i::" << a.name ()
         << " (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_SNGL] << endl
         << "{"
         << STRS[YCH] << endl;

      Traversal::ReadAttribute::belongs (a, return_belongs_);

      os << "}";
    }

  protected:
    T& scope_;

  private:
    ReturnTypeNameEmitter read_type_name_emitter_;
    NullReturnEmitter return_emitter_;
    Traversal::Belongs read_belongs_;
    Traversal::Belongs return_belongs_;
  };

  struct InterfaceEmitter : Traversal::UnconstrainedInterface,
                            EmitterBase
  {
    InterfaceEmitter (Context& c)
      : EmitterBase (c)
    {}

    bool
    add (UnconstrainedInterface& i)
    {
      return interfaces_.insert (&i).second;
    }

    virtual void
    traverse (UnconstrainedInterface& i)
    {
      if (add (i))
      {
        Traversal::UnconstrainedInterface::traverse (i);
      }
    }

  private:
    std::set<UnconstrainedInterface*> interfaces_;
  };

  struct FacetEmitter : Traversal::UnconstrainedInterface,
                        EmitterBase
  {
    FacetEmitter (Context& c)
      : EmitterBase (c)
    {
    }

    virtual void
    traverse (UnconstrainedInterface& i)
    {
      if (i.context ().count ("facet_impl_src_gen")) return;

      os << STRS[SEP] << endl
         << "// Facet Executor Implementation Class:   "
         << i.name () << "_exec_i" << endl
         << STRS[SEP] << endl << endl;

      os << i.name () << "_exec_i::"
         << i.name () << "_exec_i (void)" << endl
         << "{"
         << "}"
         << i.name () << "_exec_i::~"
         << i.name () << "_exec_i (void)" << endl
         << "{"
         << "}"
         << "// Operations from " << i.scoped_name () << endl << endl;

      {
        InterfaceEmitter interface_emitter (ctx);

        Traversal::Defines defines_;
        Traversal::Inherits inherits_;
        interface_emitter.edge_traverser (defines_);
        interface_emitter.edge_traverser (inherits_);

        AttributeEmitter<UnconstrainedInterface> attribute_emitter (ctx, i);
        ReadOnlyAttributeEmitter<UnconstrainedInterface> read_only_attribute_emitter (ctx, i);
        defines_.node_traverser (attribute_emitter);
        defines_.node_traverser (read_only_attribute_emitter);

        OperationEmitter<UnconstrainedInterface> operation_emitter (ctx, i);
        defines_.node_traverser (operation_emitter);
        inherits_.node_traverser (interface_emitter);

        Traversal::Receives receives;
        Traversal::Belongs returns;
        Traversal::Raises raises;
        operation_emitter.edge_traverser (receives);
        operation_emitter.edge_traverser (returns);
        operation_emitter.edge_traverser (raises);

        ParameterEmitter<Traversal::InParameter> in_param (os);
        ParameterEmitter<Traversal::InOutParameter> inout_param (os);
        ParameterEmitter<Traversal::OutParameter> out_param (os);
        receives.node_traverser (in_param);
        receives.node_traverser (inout_param);
        receives.node_traverser (out_param);

        ReturnTypeNameEmitter return_type_emitter (os);
        TypeNameEmitter type_name_emitter (os);
        returns.node_traverser (return_type_emitter);
        raises.node_traverser (type_name_emitter);

        Traversal::Belongs in_belongs, inout_belongs, out_belongs;
        in_param.edge_traverser (in_belongs);
        inout_param.edge_traverser (inout_belongs);
        out_param.edge_traverser (out_belongs);

        INArgTypeNameEmitter in_arg_emitter (os);
        INOUTArgTypeNameEmitter inout_arg_emitter (os);
        OUTArgTypeNameEmitter out_arg_emitter (os);
        in_belongs.node_traverser (in_arg_emitter);
        inout_belongs.node_traverser (inout_arg_emitter);
        out_belongs.node_traverser (out_arg_emitter);

        inherits (i, inherits_);
        names (i, defines_);
      }

      i.context ().set ("facet_impl_src_gen", true);
    }
  };

  struct ExecPortsEmitter : Traversal::ConsumerData,
                            Traversal::ProviderData,
                            EmitterBase
  {
    ExecPortsEmitter (Context& c, SemanticGraph::Component& scope)
      : EmitterBase (c),
        enclosing_type_name_emitter_ (c.os ()),
        simple_type_name_emitter_ (c.os ()),
        type_name_emitter_ (c.os ()),
        scope_ (scope)
    {
      enclosing_belongs_.node_traverser (enclosing_type_name_emitter_);
      simple_belongs_.node_traverser (simple_type_name_emitter_);
      belongs_.node_traverser (type_name_emitter_);
    }

    virtual void
    traverse (SemanticGraph::Provider& p)
    {
      Traversal::ProviderData::belongs (p, enclosing_belongs_);

      os << "::CCM_";

      Traversal::ProviderData::belongs (p, simple_belongs_);

      os << "_ptr" << endl
         << scope_.name () << "_exec_i::get_"
         << p.name () << " (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_SNGL] << endl
         << "{"
         << STRS[YCH] << endl
         << "return ";

      Traversal::ProviderData::belongs (p, enclosing_belongs_);

      os << "::CCM_";

      Traversal::ProviderData::belongs (p, simple_belongs_);

      os << "::_nil ();" << endl
         << "}";
    }

    virtual void
    traverse (SemanticGraph::Consumer& c)
    {
      // @@@ (JP) May need to generate this for the eventtype's ancestors
      // as well (the spec is vague on this point). If so, we need the
      // CIDL compiler to support valuetype/eventtype inheritance.
      os << "void" << endl
         << scope_.name () << "_exec_i::push_"
         << c.name () << " (" << endl;

      Traversal::ConsumerData::belongs (c, belongs_);

      os << " * /* ev */" << endl
         << STRS[ENV_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_SNGL] << endl
         << "{"
         << STRS[YCH] << endl
         << "}";
   }

  private:
    EnclosingTypeNameEmitter enclosing_type_name_emitter_;
    SimpleTypeNameEmitter simple_type_name_emitter_;
    TypeNameEmitter type_name_emitter_;
    Traversal::Belongs enclosing_belongs_;
    Traversal::Belongs simple_belongs_;
    Traversal::Belongs belongs_;
    SemanticGraph::Component& scope_;
  };

  struct ComponentExecImplEmitter : Traversal::Component, EmitterBase
  {
    ComponentExecImplEmitter (Context& c)
      : EmitterBase (c)
    {
    }

    virtual void
    pre (Type& t)
    {
      // Generate the facet executor class(es) first.
      {
        Traversal::Component component_emitter;

        Traversal::Inherits component_inherits;
        component_inherits.node_traverser (component_emitter);

        Traversal::Defines defines;
        component_emitter.edge_traverser (defines);
        component_emitter.edge_traverser (component_inherits);

        Traversal::Provider provider;
        defines.node_traverser (provider);

        Traversal::Belongs belongs;
        provider.edge_traverser (belongs);

        FacetEmitter facet_emitter (ctx);
        belongs.node_traverser (facet_emitter);

        component_emitter.traverse (t);
      }

      os << STRS[SEP] << endl
         << "// Component Executor Implementation Class:   "
         << t.name () << "_exec_i" << endl
         << STRS[SEP] << endl << endl;

      os << t.name () << "_exec_i::"
         << t.name () << "_exec_i (void)" << endl
         << "{"
         << "}"
         << t.name () << "_exec_i::~"
         << t.name () << "_exec_i (void)" << endl
         << "{"
         << "}";

      os << "// Supported or inherited operations." << endl << endl;

      {
        Traversal::Component component_emitter;

        Traversal::Inherits component_inherits;
        component_inherits.node_traverser (component_emitter);

        Traversal::Supports supports_;
        component_emitter.edge_traverser (component_inherits);
        component_emitter.edge_traverser (supports_);
        InterfaceEmitter interface_emitter (ctx);
        supports_.node_traverser (interface_emitter);

        Traversal::Defines defines;
        Traversal::Inherits interface_inherits;
        interface_emitter.edge_traverser (defines);
        interface_emitter.edge_traverser (interface_inherits);

        AttributeEmitter<SemanticGraph::Component> attribute_emitter (ctx, t);
        ReadOnlyAttributeEmitter<SemanticGraph::Component> read_only_attribute_emitter (ctx, t);
        defines.node_traverser (attribute_emitter);
        defines.node_traverser (read_only_attribute_emitter);

        OperationEmitter<SemanticGraph::Component> operation_emitter (ctx, t);
        defines.node_traverser (operation_emitter);
        interface_inherits.node_traverser (interface_emitter);

        Traversal::Receives receives;
        Traversal::Belongs returns;
        Traversal::Raises raises;
        operation_emitter.edge_traverser (receives);
        operation_emitter.edge_traverser (returns);
        operation_emitter.edge_traverser (raises);

        ParameterEmitter<Traversal::InParameter> in_param (os);
        ParameterEmitter<Traversal::InOutParameter> inout_param (os);
        ParameterEmitter<Traversal::OutParameter> out_param (os);
        receives.node_traverser (in_param);
        receives.node_traverser (inout_param);
        receives.node_traverser (out_param);

        ReturnTypeNameEmitter return_type_emitter (os);
        TypeNameEmitter type_name_emitter (os);
        returns.node_traverser (return_type_emitter);
        raises.node_traverser (type_name_emitter);

        Traversal::Belongs in_belongs, inout_belongs, out_belongs;
        in_param.edge_traverser (in_belongs);
        inout_param.edge_traverser (inout_belongs);
        out_param.edge_traverser (out_belongs);

        INArgTypeNameEmitter in_arg_emitter (os);
        INOUTArgTypeNameEmitter inout_arg_emitter (os);
        OUTArgTypeNameEmitter out_arg_emitter (os);
        in_belongs.node_traverser (in_arg_emitter);
        inout_belongs.node_traverser (inout_arg_emitter);
        out_belongs.node_traverser (out_arg_emitter);

        component_emitter.traverse (t);
      }

      os << "// Attribute operations." << endl << endl;

      {
        Traversal::Component component_emitter;

        Traversal::Inherits component_inherits;
        component_inherits.node_traverser (component_emitter);

        component_emitter.edge_traverser (component_inherits);

        Traversal::Defines defines;
        component_emitter.edge_traverser (defines);

        AttributeEmitter<SemanticGraph::Component> attribute_emitter (ctx, t);
        ReadOnlyAttributeEmitter<SemanticGraph::Component> read_only_attribute_emitter (ctx, t);
        defines.node_traverser (attribute_emitter);
        defines.node_traverser (read_only_attribute_emitter);

        component_emitter.traverse (t);
      }

      os << "// Port operations." << endl << endl;

      {
        Traversal::Component component_emitter;

        Traversal::Inherits component_inherits;
        component_inherits.node_traverser (component_emitter);

        component_emitter.edge_traverser (component_inherits);

        Traversal::Defines defines;
        component_emitter.edge_traverser (defines);

        ExecPortsEmitter exec_ports_emitter (ctx, t);
        defines.node_traverser (exec_ports_emitter);

        component_emitter.traverse (t);
      }

      os << "// Operations from Components::SessionComponent" << endl << endl;

      os << "void" << endl
         << t.name () << "_exec_i::set_session_context (" << endl
         << STRS[COMP_SC] << "_ptr ctx" << endl
         << STRS[ENV_SRC] << ")" << endl
         << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl
         << STRS[EXCP_CE] << "))" << endl
         << "{"
         << "this->context_ =" << endl
         << t.name () << "_Context::_narrow (" << endl
         << "ctx" << endl
         << STRS[ENV_ARG] <<");"
         << "ACE_CHECK;" << endl;

      os << "if (this->context_ == 0)" << endl
         << "{"
         << "ACE_THROW (CORBA::INTERNAL ());"
         << "}"
         << "}";

      os << "void" << endl
         << t.name () << "_exec_i::ciao_preactivate (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl
         << STRS[EXCP_CE] << "))" << endl
         << "{"
         << STRS[YCH]
         << "}";

      os << "void" << endl
         << t.name () << "_exec_i::ciao_postactivate (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl
         << STRS[EXCP_CE] << "))" << endl
         << "{"
         << STRS[YCH]
         << "}";

      os << "void" << endl
         << t.name () << "_exec_i::ccm_activate (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl
         << STRS[EXCP_CE] << "))" << endl
         << "{"
         << STRS[YCH]
         << "}";

      os << "void" << endl
         << t.name () << "_exec_i::ccm_passivate (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl
         << STRS[EXCP_CE] << "))" << endl
         << "{"
         << STRS[YCH]
         << "}";

      os << "void" << endl
         << t.name () << "_exec_i::ccm_remove (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl
         << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl
         << STRS[EXCP_CE] << "))" << endl
         << "{"
         << STRS[YCH]
         << "}";
    }

    virtual void
    post (Type&)
    {
    }
  };

  // HomeFactory and HomeFinder are tied to Operation in
  // the front end. Since we want to treat them differently
  // than regular operations in a home (we want to generate
  // base class factory operations returning the base component,
  // for example), we use this class for regular home operations
  // that overrides HomeFactory and HomeFinder traversals
  // to do nothing.
  struct HomeOperationEmitter : OperationEmitter<SemanticGraph::Home>,
                                Traversal::HomeFactory,
                                Traversal::HomeFinder
  {
    HomeOperationEmitter (Context& c, SemanticGraph::Home& scope)
      : OperationEmitter<SemanticGraph::Home> (c, scope)
    {}

    virtual void
    traverse (SemanticGraph::HomeFactory&)
    {
    }

    virtual void
    traverse (SemanticGraph::HomeFinder&)
    {
    }
  };

  struct FactoryOperationEmitter : Traversal::HomeFactory,
                                   EmitterBase
  {
    FactoryOperationEmitter (Context& c, SemanticGraph::Home& scope)
      : EmitterBase (c),
        enclosing_type_name_emitter_ (c.os ()),
        simple_type_name_emitter_ (c.os ()),
        scope_ (scope)
    {
      enclosing_returns_.node_traverser (enclosing_type_name_emitter_);
      simple_returns_.node_traverser (simple_type_name_emitter_);
    }

    virtual void
    returns (SemanticGraph::HomeFactory&)
    {
      os << STRS[COMP_EC] << "_ptr" << endl;
    }

    virtual void
    name (SemanticGraph::HomeFactory& hf)
    {
      os << scope_.name () << "_exec_i::" << hf.name ();
    }

    virtual void
    receives_none (SemanticGraph::HomeFactory&)
    {
      os << " (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl;
    }

    virtual void
    receives_pre (SemanticGraph::HomeFactory&)
    {
      os << " (" << endl;
    }

    virtual void
    receives_post (SemanticGraph::HomeFactory&)
    {
      os << endl << STRS[ENV_SRC_NOTUSED] << ")" << endl;
    }

    virtual void
    raises_none (SemanticGraph::HomeFactory&)
    {
      os << STRS[EXCP_SNGL];
    }

    virtual void
    raises_pre (SemanticGraph::HomeFactory&)
    {
      os << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl;
    }

    virtual void
    raises_post (SemanticGraph::HomeFactory&)
    {
      os << "))";
    }

    virtual void
    post (SemanticGraph::HomeFactory& hf)
    {
      os << "{"
         << STRS[YCH] << endl
         << "return ";

      Traversal::HomeFactory::returns (hf, enclosing_returns_);

      os << "::CCM_";

      Traversal::HomeFactory::returns (hf, simple_returns_);

      os << "::_nil ();"
         << "}";
    }

    virtual void
    comma (SemanticGraph::HomeFactory&)
    {
      os << "," << endl;
    }

  private:
    EnclosingTypeNameEmitter enclosing_type_name_emitter_;
    SimpleTypeNameEmitter simple_type_name_emitter_;
    Traversal::Returns enclosing_returns_;
    Traversal::Returns simple_returns_;
    SemanticGraph::Home& scope_;
  };

  struct FinderOperationEmitter : Traversal::HomeFinder,
                                  EmitterBase
  {
    FinderOperationEmitter (Context& c, SemanticGraph::Home& scope)
      : EmitterBase (c),
        enclosing_type_name_emitter_ (c.os ()),
        simple_type_name_emitter_ (c.os ()),
        scope_ (scope)
    {
      enclosing_returns_.node_traverser (enclosing_type_name_emitter_);
      simple_returns_.node_traverser (simple_type_name_emitter_);
    }

    virtual void
    returns (SemanticGraph::HomeFinder&)
    {
      os << STRS[COMP_EC] << "_ptr" << endl;
    }

    virtual void
    name (SemanticGraph::HomeFinder& hf)
    {
      os << scope_.name () << "_exec_i::" << hf.name ();
    }

    virtual void
    receives_none (SemanticGraph::HomeFinder&)
    {
      os << " (" << endl
         << STRS[ENV_SNGL_SRC_NOTUSED] << ")" << endl;
    }

    virtual void
    receives_pre (SemanticGraph::HomeFinder&)
    {
      os << " (" << endl;
    }

    virtual void
    receives_post (SemanticGraph::HomeFinder&)
    {
      os << endl << STRS[ENV_SRC_NOTUSED] << ")" << endl;
    }

    virtual void
    raises_none (SemanticGraph::HomeFinder&)
    {
      os << STRS[EXCP_SNGL];
    }

    virtual void
    raises_pre (SemanticGraph::HomeFinder&)
    {
      os << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl;
    }

    virtual void
    raises_post (SemanticGraph::HomeFinder&)
    {
      os << "))";
    }

    virtual void
    post (SemanticGraph::HomeFinder& hf)
    {
      os << "{"
         << STRS[YCH] << endl
         << "return ";

      Traversal::HomeFinder::returns (hf, enclosing_returns_);

      os << "::CCM_";

      Traversal::HomeFinder::returns (hf, simple_returns_);

      os << "::_nil ();"
         << "}";
    }

    virtual void
    comma (SemanticGraph::HomeFinder&)
    {
      os << "," << endl;
    }

  private:
    EnclosingTypeNameEmitter enclosing_type_name_emitter_;
    SimpleTypeNameEmitter simple_type_name_emitter_;
    Traversal::Returns enclosing_returns_;
    Traversal::Returns simple_returns_;
    SemanticGraph::Home& scope_;
  };

  struct HomeExecImplEmitter : Traversal::Home, EmitterBase
  {
    HomeExecImplEmitter (Context& c)
      : EmitterBase (c)
    {
    }

    virtual void
    pre (Type& t)
    {
      os << STRS[SEP] << endl
         << "// Home Executor Implementation Class:   "
         << t.name () << "_exec_i" << endl
         << STRS[SEP] << endl << endl;

      os << t.name () << "_exec_i::"
         << t.name () << "_exec_i (void)" << endl
         << "{"
         << "}"
         << t.name () << "_exec_i::~"
         << t.name () << "_exec_i (void)" << endl
         << "{"
         << "}";

      os << "// Supported or inherited operations." << endl << endl;

      {
        Traversal::Home home_emitter;

        Traversal::Inherits home_inherits;
        home_inherits.node_traverser (home_emitter);

        Traversal::Supports supports_;
        home_emitter.edge_traverser (home_inherits);
        home_emitter.edge_traverser (supports_);
        InterfaceEmitter interface_emitter (ctx);
        supports_.node_traverser (interface_emitter);

        Traversal::Defines defines;
        Traversal::Inherits interface_inherits;
        interface_emitter.edge_traverser (defines);
        interface_emitter.edge_traverser (interface_inherits);

        AttributeEmitter<SemanticGraph::Home> attribute_emitter (ctx, t);
        ReadOnlyAttributeEmitter<SemanticGraph::Home> read_only_attribute_emitter (ctx, t);
        defines.node_traverser (attribute_emitter);
        defines.node_traverser (read_only_attribute_emitter);

        OperationEmitter<SemanticGraph::Home> operation_emitter (ctx, t);
        defines.node_traverser (operation_emitter);
        interface_inherits.node_traverser (interface_emitter);

        Traversal::Receives receives;
        Traversal::Belongs returns;
        Traversal::Raises raises;
        operation_emitter.edge_traverser (receives);
        operation_emitter.edge_traverser (returns);
        operation_emitter.edge_traverser (raises);

        ParameterEmitter<Traversal::InParameter> in_param (os);
        ParameterEmitter<Traversal::InOutParameter> inout_param (os);
        ParameterEmitter<Traversal::OutParameter> out_param (os);
        receives.node_traverser (in_param);
        receives.node_traverser (inout_param);
        receives.node_traverser (out_param);

        ReturnTypeNameEmitter return_type_emitter (os);
        TypeNameEmitter type_name_emitter (os);
        returns.node_traverser (return_type_emitter);
        raises.node_traverser (type_name_emitter);

        Traversal::Belongs in_belongs, inout_belongs, out_belongs;
        in_param.edge_traverser (in_belongs);
        inout_param.edge_traverser (inout_belongs);
        out_param.edge_traverser (out_belongs);

        INArgTypeNameEmitter in_arg_emitter (os);
        INOUTArgTypeNameEmitter inout_arg_emitter (os);
        OUTArgTypeNameEmitter out_arg_emitter (os);
        in_belongs.node_traverser (in_arg_emitter);
        inout_belongs.node_traverser (inout_arg_emitter);
        out_belongs.node_traverser (out_arg_emitter);

        home_emitter.traverse (t);
      }

      os << "// Home operations." << endl << endl;

      {
        Traversal::Home home_emitter;

        Traversal::Inherits home_inherits;
        home_inherits.node_traverser (home_emitter);

        Traversal::Defines defines;
        home_emitter.edge_traverser (defines);
        home_emitter.edge_traverser (home_inherits);

        HomeOperationEmitter home_operation_emitter (ctx, t);
        defines.node_traverser (home_operation_emitter);

        Traversal::Receives receives;
        Traversal::Belongs returns;
        Traversal::Raises raises;
        home_operation_emitter.edge_traverser (receives);
        home_operation_emitter.edge_traverser (returns);
        home_operation_emitter.edge_traverser (raises);

        ParameterEmitter<Traversal::InParameter> in_param (os);
        ParameterEmitter<Traversal::InOutParameter> inout_param (os);
        ParameterEmitter<Traversal::OutParameter> out_param (os);
        receives.node_traverser (in_param);
        receives.node_traverser (inout_param);
        receives.node_traverser (out_param);

        ReturnTypeNameEmitter return_type_emitter (os);
        TypeNameEmitter type_name_emitter (os);
        returns.node_traverser (return_type_emitter);
        raises.node_traverser (type_name_emitter);

        Traversal::Belongs in_belongs, inout_belongs, out_belongs;
        in_param.edge_traverser (in_belongs);
        inout_param.edge_traverser (inout_belongs);
        out_param.edge_traverser (out_belongs);

        INArgTypeNameEmitter in_arg_emitter (os);
        INOUTArgTypeNameEmitter inout_arg_emitter (os);
        OUTArgTypeNameEmitter out_arg_emitter (os);
        in_belongs.node_traverser (in_arg_emitter);
        inout_belongs.node_traverser (inout_arg_emitter);
        out_belongs.node_traverser (out_arg_emitter);

        home_emitter.traverse (t);
      }

      // Generate home factory operations. This is a separate traversal
      // stack because we want to generate the factory operations
      // of ancestors with the return type of the base component.
      os << "// Factory and finder operations." << endl << endl;

      {
        Traversal::Home home_emitter;

        Traversal::Inherits inherits;
        home_emitter.edge_traverser (inherits);
        inherits.node_traverser (home_emitter);

        Traversal::Defines defines;
        home_emitter.edge_traverser (defines);

        FactoryOperationEmitter factory_operation_emitter (ctx, t);
        FinderOperationEmitter finder_operation_emitter (ctx, t);
        defines.node_traverser (factory_operation_emitter);
        defines.node_traverser (finder_operation_emitter);

        Traversal::Receives receives;
        Traversal::Belongs returns;
        Traversal::Raises raises;
        factory_operation_emitter.edge_traverser (receives);
        factory_operation_emitter.edge_traverser (returns);
        factory_operation_emitter.edge_traverser (raises);
        finder_operation_emitter.edge_traverser (receives);
        finder_operation_emitter.edge_traverser (returns);
        finder_operation_emitter.edge_traverser (raises);

        ParameterEmitter<Traversal::InParameter> in_param (os);
        ParameterEmitter<Traversal::InOutParameter> inout_param (os);
        ParameterEmitter<Traversal::OutParameter> out_param (os);
        receives.node_traverser (in_param);
        receives.node_traverser (inout_param);
        receives.node_traverser (out_param);

        ReturnTypeNameEmitter return_type_emitter (os);
        TypeNameEmitter type_name_emitter (os);
        returns.node_traverser (return_type_emitter);
        raises.node_traverser (type_name_emitter);

        Traversal::Belongs in_belongs, inout_belongs, out_belongs;
        in_param.edge_traverser (in_belongs);
        inout_param.edge_traverser (inout_belongs);
        out_param.edge_traverser (out_belongs);

        INArgTypeNameEmitter in_arg_emitter (os);
        INOUTArgTypeNameEmitter inout_arg_emitter (os);
        OUTArgTypeNameEmitter out_arg_emitter (os);
        in_belongs.node_traverser (in_arg_emitter);
        inout_belongs.node_traverser (inout_arg_emitter);
        out_belongs.node_traverser (out_arg_emitter);

        home_emitter.traverse (t);
      }

      os << "// Attribute operations." << endl << endl;

      {
        Traversal::Home home_emitter;

        Traversal::Inherits home_inherits;
        home_inherits.node_traverser (home_emitter);

        home_emitter.edge_traverser (home_inherits);

        Traversal::Defines defines;
        home_emitter.edge_traverser (defines);

        AttributeEmitter<SemanticGraph::Home> attribute_emitter (ctx, t);
        ReadOnlyAttributeEmitter<SemanticGraph::Home> read_only_attribute_emitter (ctx, t);
        defines.node_traverser (attribute_emitter);
        defines.node_traverser (read_only_attribute_emitter);

        home_emitter.traverse (t);
      }

      os << "// Implicit operations." << endl << endl
         << STRS[COMP_EC] << "_ptr" << endl
         << t.name () << "_exec_i::create (" << endl
         << STRS[ENV_SNGL_SRC] << ")" << endl
         << STRS[EXCP_START] << endl
         << STRS[EXCP_SYS] << "," << endl
         << STRS[EXCP_CE] << "))" << endl
         << "{"
         << STRS[COMP_EC] << "_ptr retval =" << endl
         << STRS[COMP_EC] << "::_nil ();" << endl
         << "ACE_NEW_THROW_EX (" << endl
         << "retval," << endl;

       Traversal::Home home_emitter;

       Traversal::Manages manages_;
       home_emitter.edge_traverser (manages_);

       SimpleTypeNameEmitter manages_emitter (os);
       manages_.node_traverser (manages_emitter);

       home_emitter.traverse (t);

       os << "_exec_i," << endl
          << "CORBA::NO_MEMORY ());"
          << STRS[ACE_CR] << " (" << STRS[COMP_EC]
          << "::_nil ());" << endl
          << "return retval;"
          << "}";
    }

    virtual void
    post (Type& t)
    {
      os << "extern \"C\" " << ctx.export_macro ()
         << " ::Components::HomeExecutorBase_ptr" << endl
         << "create" << t.name () << "_Impl (void)" << endl
         << "{"
         << "::Components::HomeExecutorBase_ptr retval =" << endl
         << "::Components::HomeExecutorBase::_nil ();" << endl
         << "ACE_NEW_RETURN (" << endl
         << "retval," << endl
         << t.name () << "_exec_i," << endl
         << "::Components::HomeExecutorBase::_nil ());" << endl
         << "return retval;"
         << "}";
    }
  };
}

ExecImplSourceEmitter::ExecImplSourceEmitter (std::ostream& os_,
                                              CommandLine const& cl,
                                              string export_macro,
                                              fs::path const& file)
  : os (os_),
    cl_ (cl),
    export_macro_ (export_macro),
    file_ (file)
{}

void
ExecImplSourceEmitter::pre (TranslationUnit&)
{
  os << COPYRIGHT;

  string file_name ("");

  if (! file_.empty ())
  {
    file_name = file_.leaf ();
  }

  string file_suffix = cl_.get_value ("exec-hdr-file-suffix",
                                      "_exec.h");

  file_name = regex::perl_s (file_name,
                             "/^(.+?)(\\.(idl|cidl|cdl))?$/$1"
                             + file_suffix
                             + "/");

  os << "#include \"" << file_name << "\"" << endl
     << "#include \"ciao/CIAO_common.h\"" << endl << endl;
}

void
ExecImplSourceEmitter::generate (TranslationUnit& u)
{
  pre (u);

  Context c (os, export_macro_);

  Traversal::TranslationUnit unit;

  // Layer 1
  //
  Traversal::ContainsPrincipal contains_principal;
  unit.edge_traverser (contains_principal);

  //--
  Traversal::TranslationRegion principal_region;
  contains_principal.node_traverser (principal_region);

  // Layer 2
  //
  Traversal::ContainsRoot contains_root;
  principal_region.edge_traverser (contains_root);

  //--
  Traversal::Root root;
  contains_root.node_traverser (root);

  // Layer 3
  //
  Traversal::Defines defines;
  root.edge_traverser (defines);

  //--
  ModuleEmitter module (c);
  CompositionEmitter composition (c);
  defines.node_traverser (module);
  defines.node_traverser (composition);

  // Layer 4
  //
  composition.edge_traverser (defines);
  module.edge_traverser (defines);

  //--
  Traversal::ComponentExecutor component_executor;
  Traversal::HomeExecutor home_executor;
  defines.node_traverser (component_executor);
  defines.node_traverser (home_executor);

  // Layer 5
  //
  Traversal::Implements implements;
  component_executor.edge_traverser (implements);
  home_executor.edge_traverser (implements);

  //--
  ComponentExecImplEmitter component_exec_impl_emitter (c);
  HomeExecImplEmitter home_exec_impl_emitter (c);
  implements.node_traverser (component_exec_impl_emitter);
  implements.node_traverser (home_exec_impl_emitter);

  unit.traverse (u);

  post (u);
}

void
ExecImplSourceEmitter::post (TranslationUnit&)
{
}

