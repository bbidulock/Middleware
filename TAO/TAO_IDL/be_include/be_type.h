// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_type.h
//
// = DESCRIPTION
//    Extension of class AST_Type that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#if !defined (BE_TYPE_H)
#define BE_TYPE_H

/*
 * BE_Type
 */
class be_type : public virtual AST_Type,
                public virtual be_decl
{
public:
  // =Operations

  be_type (void);
  // default constructor

  be_type (AST_Decl::NodeType nt, UTL_ScopedName *n, UTL_StrList *p);
  // constructor

  virtual int gen_client_header (void) = 0;
  // Generates the client-side header information for the type

  virtual int gen_client_stubs (void) = 0;
  // Generates the client-side stubs for the type

  virtual int gen_server_header (void) = 0;
  // Generates the server-side header information for the type

  virtual int gen_server_skeletons (void) = 0;
  // Generates the server-side skeletons for the type

  virtual int gen_client_inline (void)  = 0;
  // Generates the client-side inline for the type

  virtual int gen_server_inline (void) = 0;
  // Generates the server-side inlines for the type

  virtual int gen_var_defn (void);
  // generate the _var class definition

  virtual int gen_var_impl (void);
  // generate the implementation for the _var class

  virtual int gen_out_defn (void);
  // generate the _out class definition

  virtual int gen_out_impl (void);
  // generate the _out implementation

  virtual int gen_typecode (void) = 0;
  // generate the typecode description

  virtual long tc_size (void) = 0;
  // return typecode size

  UTL_ScopedName *tc_name (void);
  // return the typecode name

  virtual char *nested_type_name (be_decl *d, char *suffix = 0);
  // type name of a node used when generating declarations

  virtual AST_Decl::NodeType base_node_type (void) const;
  // Typedefs are tricky to handle, in many points their mapping
  // depend on base type they are aliasing.  Since typedefs can be
  // recursive simply using "base_type->node_type()" will not work, so
  // the most "unaliased" type is needed.

  // Visiting
  virtual int accept (be_visitor* visitor);

  // Narrowing
  DEF_NARROW_METHODS2 (be_type, AST_Type, be_decl);
  DEF_NARROW_FROM_DECL (be_type);

protected:
  virtual void compute_tc_name (void);
  // computes the fully scoped typecode name

  UTL_ScopedName *tc_name_;
  // typecode name

  char *type_name_;
  // type name (this uses the ACE NESTED macro)
};

#endif // end of if !defined
