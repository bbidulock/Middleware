// This may look like C, but it's really -*- C++ -*-
// $Id$
/*

COPYRIGHT

Copyright 1992, 1993, 1994 Sun Microsystems, Inc.  Printed in the United
States of America.  All Rights Reserved.

This product is protected by copyright and distributed under the following
license restricting its use.

The Interface Definition Language Compiler Front End (CFE) is made
available for your use provided that you include this license and copyright
notice on all media and documentation and the software program in which
this product is incorporated in whole or part. You may copy and extend
functionality (but may not remove functionality) of the Interface
Definition Language CFE without charge, but you are not authorized to
license or distribute it to anyone else except as part of a product or
program developed by you or with the express written consent of Sun
Microsystems, Inc. ("Sun").

The names of Sun Microsystems, Inc. and any of its subsidiaries or
affiliates may not be used in advertising or publicity pertaining to
distribution of Interface Definition Language CFE as permitted herein.

This license is effective until terminated by Sun for failure to comply
with this license.  Upon termination, you shall destroy or return all code
and documentation for the Interface Definition Language CFE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED AS IS WITH NO WARRANTIES OF
ANY KIND INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS
FOR A PARTICULAR PURPOSE, NONINFRINGEMENT, OR ARISING FROM A COURSE OF
DEALING, USAGE OR TRADE PRACTICE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED WITH NO SUPPORT AND WITHOUT
ANY OBLIGATION ON THE PART OF Sun OR ANY OF ITS SUBSIDIARIES OR AFFILIATES
TO ASSIST IN ITS USE, CORRECTION, MODIFICATION OR ENHANCEMENT.

SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES SHALL HAVE NO LIABILITY WITH
RESPECT TO THE INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY
INTERFACE DEFINITION LANGUAGE CFE OR ANY PART THEREOF.

IN NO EVENT WILL SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES BE LIABLE FOR
ANY LOST REVENUE OR PROFITS OR OTHER SPECIAL, INDIRECT AND CONSEQUENTIAL
DAMAGES, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

Use, duplication, or disclosure by the government is subject to
restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
Technical Data and Computer Software clause at DFARS 252.227-7013 and FAR
52.227-19.

Sun, Sun Microsystems and the Sun logo are trademarks or registered
trademarks of Sun Microsystems, Inc.

SunSoft, Inc.
2550 Garcia Avenue
Mountain View, California  94043

NOTE:

SunOS, SunSoft, Sun, Solaris, Sun Microsystems or the Sun logo are
trademarks or registered trademarks of Sun Microsystems, Inc.

 */

#ifndef _AST_ENUM_AST_ENUM_HH
#define _AST_ENUM_AST_ENUM_HH

// Representation of enum:

/*
** DEPENDENCIES: ast_concrete_type.hh, utl_scope.hh, ast_enum_val.hh,
**               utl_scoped_name.hh, utl_strlist.hh, ast_expression.hh,
**
** USE: Included from ast.hh
*/

class TAO_IDL_FE_Export AST_Enum : public virtual AST_ConcreteType, 
                                   public virtual UTL_Scope
{
public:
  // Operations

  // Constructor(s)
  AST_Enum ();
  AST_Enum (UTL_ScopedName *n,
            UTL_StrList *p,
            idl_bool local,
            idl_bool abstract);

  virtual ~AST_Enum (void);

  // Narrowing
  DEF_NARROW_METHODS2(AST_Enum, AST_ConcreteType, UTL_Scope);
  DEF_NARROW_FROM_DECL(AST_Enum);
  DEF_NARROW_FROM_SCOPE(AST_Enum);

  // AST Dumping
  virtual void                  dump(ostream &);

  // Other operations

  // Look up an AST_EnumVal by value
  virtual AST_EnumVal           *lookup_by_value(const AST_Expression *v);

  // Get value to be assigned to next enumerator
  virtual unsigned long         next_enum_val();

  // Cleanup function.
  virtual void destroy (void);

private:
  // Data
  unsigned long                 pd_enum_counter;        // Value for next
                                                        // enumerator
  // Scope management
  friend int tao_yyparse();
  virtual AST_EnumVal           *fe_add_enum_val(AST_EnumVal    *v);

};

#endif           // _AST_ENUM_AST_ENUM_HH
