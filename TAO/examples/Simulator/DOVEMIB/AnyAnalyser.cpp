// $Id$
// ============================================================================
//
// = LIBRARY
//
// = FILENAME
//    AnyAnalyser.cpp
//
// = AUTHOR
//    Michael Kircher 
//
// = DESCRIPTION
//   Accepts an CORBA::Any, traverses it, copies it into a tree structure
//   and prints out the tree.
//
// ============================================================================

#include "AnyAnalyser.h"

AnyAnalyser::AnyAnalyser (const char *file_name) 
  : printVisitor_ptr_(new PrintVisitor (file_name)) {
}

AnyAnalyser::~AnyAnalyser () { }

void 
AnyAnalyser::printAny (CORBA::Any any) {

  // Analyse the any and store the results in a tree structure
  RecurseInfo recurseInfo_ = {PARENT_IS_NO_STRUCT,// identifies parent
                              0,                  // parent typecode
                              0,                  // member count
                              0};                 // recursion level

  // analyse the any
  Node *node_ptr_ = analyse (any.type (), 
                             (unsigned char *)value_ptr, 
                             recurseInfo_);

  // print the results
  node_ptr_->Accept ((NodeVisitor *)printVisitor_ptr_);
}

Node *
AnyAnalyser::analyse (CORBA::TypeCode_ptr tc_ptr, 
		      unsigned char *&value_ptr,
          RecurseInfo ri)
{
  
  TAO_TRY {
    Node *node_ptr_ = 0;
    
    if (tc_ptr != 0) {
      
      switch (tc_ptr->kind(TAO_TRY_ENV)) {
	
      	case CORBA::tk_struct:
      	  cout << "Struct detected" << endl;
	        {	  
	          // create a new Node
	          StructNode *structNode_ptr_ = new StructNode (tc_ptr->name (TAO_TRY_ENV), 
                      								   ri.recursion_level);
	    
      	    for (unsigned int i = 0; i < tc_ptr->member_count (TAO_TRY_ENV); i++) {
	      
	            // get the TypeCode pointer to the ith parameter
	            // and analyse it recursively
              RecurseInfo recurseInfo_ = {PARENT_IS_STRUCT,   // identifies parent
                                          tc_ptr,             // parent typecode
                                          i,                  // member count
                                          ri.recursion_level+1};
	      
	            structNode_ptr_->addChild (analyse (tc_ptr->member_type (i, TAO_TRY_ENV), 
                                                  value_ptr,
						                                      recurseInfo_));
            }   
	          node_ptr_ = (Node *)structNode_ptr_;
          }
	        break;
	  
        case CORBA::tk_double:
          if (ri.kind == PARENT_IS_STRUCT) {
	          node_ptr_ = (Node *) new DoubleNode ((CORBA::Double *)*value_ptr,
 					                                       ri.parent_tc_ptr->member_name(ri.member_number,
                                                                               TAO_TRY_ENV),
					                                       ri.recursion_level);
          }
          else {
	          node_ptr_ = (Node *) new DoubleNode ((CORBA::Double *)value_ptr,
					                                       tc_ptr->name(TAO_TRY_ENV),
					                                       ri.recursion_level);
          }
	        value_ptr += 8;
	        cout << "Double detected" << endl;
	        break;	      
	  
	      case CORBA::tk_long:
          if (ri.kind == PARENT_IS_STRUCT) {
  	        node_ptr_ = (Node *) new LongNode ((CORBA::Long *)value_ptr,
					                                       ri.parent_tc_ptr->member_name(ri.member_number,
                                                                               TAO_TRY_ENV),
					                                       ri.recursion_level);
          }
          else {
	          node_ptr_ = (Node *) new LongNode ((CORBA::Long *)value_ptr,
		  			                                   tc_ptr->name(TAO_TRY_ENV),
			  		                                   ri.recursion_level);
          }
	        value_ptr += 4;
	        cout << "Long detected" << endl;
	        break;
	  
	      case CORBA::tk_ulong:
          if (ri.kind == PARENT_IS_STRUCT) {
  	        node_ptr_ = (Node *) new ULongNode ((CORBA::ULong *)value_ptr,
 					                                       ri.parent_tc_ptr->member_name(ri.member_number,
                                                                               TAO_TRY_ENV),
					                                       ri.recursion_level);
          }
          else {
	          node_ptr_ = (Node *) new ULongNode ((CORBA::ULong *)value_ptr,
					                                      tc_ptr->name(TAO_TRY_ENV),
					                                      ri.recursion_level);
          }
	        value_ptr += 4;
	        cout << "ULong detected" << endl;
	        break;
	  
	      case CORBA::tk_string:
          if (ri.kind == PARENT_IS_STRUCT) {
  	        node_ptr_ = (Node *) new StringNode (*(CORBA::String_var *)value_ptr,
					                                       ri.parent_tc_ptr->member_name(ri.member_number,
                                                                               TAO_TRY_ENV),
					                                       ri.recursion_level);
          }
          else {
  	        node_ptr_ = (Node *) new StringNode (*(CORBA::String_var *)value_ptr,
 					                                       tc_ptr->name(TAO_TRY_ENV),
					                                       ri.recursion_level);
          }
	     	  value_ptr += 4;
	        cout << "String detected" << endl;
	        break;
	  
	      default: ACE_ERROR ((LM_ERROR, "AnyAnalyser::analyse: No known kind of type detected!\n"));
	        exit (1);
	        break;						      						   	  
      }
      TAO_CHECK_ENV;
	    return node_ptr_;
    }
    else {
	    ACE_DEBUG ((LM_ERROR, "AnyAnalyser::analyse: TypeCode pointer to member was Null!\n"));
    }
  }
  TAO_CATCHANY {
    ACE_ERROR ((LM_ERROR, "(%t)AnyAnalyser::analyse: Error in analysing the any.\n"));
  }
  TAO_ENDTRY;	    
  return 0;
}


