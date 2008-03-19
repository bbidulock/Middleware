// -*- C++ -*-

//=============================================================================
/**
 * @file Constraint_Visitor.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef CONSTRAINT_VISITOR_H
#define CONSTRAINT_VISITOR_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/CDR_Base.h"
#include "ace/MonitorControl_Types.h"

#include "ETCL/ETCL_Constraint.h"
#include "ETCL/ETCL_Constraint_Visitor.h"

#include "MonitorControl/MonitorControl_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ETCL_Literal_Constraint;
class ETCL_Identifier;
class ETCL_Union_Value;
class ETCL_Union_Pos;
class ETCL_Component_Pos;
class ETCL_Component_Assoc;
class ETCL_Component_Array;
class ETCL_Special;
class ETCL_Component;
class ETCL_Dot;
class ETCL_Eval;
class ETCL_Default;
class ETCL_Exist;
class ETCL_Unary_Expr;
class ETCL_Binary_Expr;
class ETCL_Preference;
class ETCL_Constraint;

namespace ACE
{
  namespace MonitorControl
  {
    /**
     * @class Constraint_Visitor
     *
     * @brief Backend for the non-CORBA ETCL frontend, specific to
     *        MonitorControl
     */
    class MONITORCONTROL_Export Constraint_Visitor
      : public ETCL_Constraint_Visitor
    {
    public:
      Constraint_Visitor (const MonitorControl_Types::Data& data);
      virtual ~Constraint_Visitor (void);
      
      ACE_CDR::Boolean evaluate_constraint (ETCL_Constraint *root);

      virtual int visit_literal (ETCL_Literal_Constraint *);
      virtual int visit_identifier (ETCL_Identifier *);
      virtual int visit_unary_expr (ETCL_Unary_Expr *);
      virtual int visit_binary_expr (ETCL_Binary_Expr *);
      
    private:
      /// Sub-methods for visit_binary_expr().
      int visit_or (ETCL_Binary_Expr *);
      int visit_and (ETCL_Binary_Expr *);
      int visit_binary_op (ETCL_Binary_Expr *binary_expr,
                           int op_type);      
      
    private:
      const MonitorControl_Types::Data& data_;
      ACE_Unbounded_Queue<ETCL_Literal_Constraint> queue_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // CONSTRAINT_VISITOR_H
    
