//
// $Id$
//
/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    component_svs.h
//
// = DESCRIPTION
//    Concrete visitor for the Component node.
//    This provides for code generation in the servant source
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef _BE_COMPONENT_COMPONENT_SVS_H_
#define _BE_COMPONENT_COMPONENT_SVS_H_

class be_visitor_component_svs : public be_visitor_component
{
  //
  // = TITLE
  //   be_visitor_component_svs
  //
  // = DESCRIPTION
  //   This is a concrete visitor to generate the servant
  //   source for component.
  //
  //
public:
  be_visitor_component_svs (be_visitor_context *ctx);
  
  ~be_visitor_component_svs (void);
  
  virtual int visit_component (be_component *node);
  virtual int visit_operation (be_operation *node);
  virtual int visit_attribute (be_attribute *node);
  
private:
  int gen_facets (void);
  
  int gen_facet_ops_attrs (be_interface *node);
                           
  void gen_context_class (void);
                           
  int gen_servant_class (void);
  
  int gen_component_attrs_r (AST_Component *node);
  
  int gen_component_attrs (AST_Component *node);
                     
  void gen_provides_top (void);
  
  void gen_facet_executor_block (const char *port_name);
                  
  void gen_provides_r (AST_Component *node);
   
  void gen_provides (AST_Provides *p);
                     
  void gen_uses_context_r (AST_Component *node);
                                     
  void gen_uses_context (AST_Uses *u);
                         
  void gen_uses_context_simplex (AST_Type *obj,
                                 const char *port_name);
                
  void gen_uses_context_multiplex (AST_Type *obj,
                                   const char *port_name);
                                   
  void gen_uses_servant_top (void);
  
  void gen_connect_block (AST_Uses *u);
                          
  void gen_disconnect_block (AST_Uses *u);
                             
  void gen_uses_servant_r (AST_Component *node);
  
  void gen_uses_servant (AST_Uses *u);
                         
  void gen_receptacle_description (AST_Uses *u,
                                   ACE_CDR::ULong slot);
  
  void gen_publishes_context_r (AST_Component *node);
                
  void gen_publishes_context (AST_Publishes *p);
                              
  void gen_publishes_servant_top (void);
  
  void gen_subscribe_block (AST_Publishes *p);
                            
  void gen_unsubscribe_block (AST_Publishes *p);
                              
  void gen_event_source_description (AST_Publishes *p,
                                     ACE_CDR::ULong slot);
                                     
  void gen_publishes_servant_r (AST_Component *node);
                              
  void gen_publishes_servant (AST_Publishes *p);
                              
  void gen_consumes_r (AST_Component *node);
  
  void gen_consumes (AST_Consumes *c);
                     
  void gen_emits_context_r (AST_Component *node);
                                     
  void gen_emits_context (AST_Emits *e);
                          
  void gen_emits_servant_top (void);
  
  void gen_connect_consumer_block (AST_Emits *e);
  
  void gen_disconnect_consumer_block (AST_Emits *e);
                                      
  void gen_emitter_description (AST_Emits *e,
                                ACE_CDR::ULong slot);
  
  void gen_emits_servant_r (AST_Component *node);
  
  void gen_emits_servant (AST_Emits *e);
                          
  void gen_attr_set_r (AST_Component *node);
     
  void gen_populate_r (AST_Component *node);
  
  void gen_entrypoint (void);
  
  void gen_all_factory_registration (void);
  void gen_one_factory_registration (AST_Type *t);
  
  void gen_swapping_get_consumers_r (AST_Component *node);
  void gen_swapping_get_comsumer_block (const char *port_name);
  
  void compute_slots (AST_Component *node);
                  
private:
  be_component *node_;
  be_interface *op_scope_;
  TAO_OutStream &os_;
  ACE_CString export_macro_;
  static bool in_facets_;
  bool swapping_;
  ACE_CDR::ULong n_provides_;
  ACE_CDR::ULong n_uses_;
  ACE_CDR::ULong n_publishes_;
  ACE_CDR::ULong n_emits_;
  ACE_CDR::ULong n_consumes_;
};

/// Worker class passed to traverse_inheritance_graph(),
/// collects supported operations and attributes.
class Component_Op_Attr_Generator
  : public TAO_IDL_Inheritance_Hierarchy_Worker
{
public:
  Component_Op_Attr_Generator (be_visitor_scope * visitor);
  
  virtual int emit (be_interface * derived_interface,
                    TAO_OutStream * os,
                    be_interface * base_interface);

private:
  be_visitor_scope * visitor_;
};
                     
#endif /* _BE_COMPONENT_COMPONENT_SVS_H_ */

