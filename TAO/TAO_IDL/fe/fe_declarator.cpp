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

#include	"idl.h"
#include	"idl_extern.h"
#include	"fe_private.h"

ACE_RCSID(fe, fe_declarator, "$Id$")

// Constructor(s) and destructor

FE_Declarator::FE_Declarator (UTL_ScopedName *n, 
                              DeclaratorType dt,
			                        AST_Decl *cp)
 : pd_complex_part (cp),
	 pd_name (n),
	 pd_decl_type (dt)
{
}

// Public operations.

// Compose the type of the complex declarator (if any) with the base
// type supplied in ct.
AST_Type *
FE_Declarator::compose (AST_Decl *d)
{
  AST_Array	*arr = 0;
  AST_Type *ct = 0;

  ct = AST_Type::narrow_from_decl (d);

  // All uses of forward declared interfaces, structs and unions must
  // not have a different prefix from the place of declaration.
  if (!ct->is_defined ())
    {
      char *current_prefix = 0;
      idl_global->pragma_prefixes ().top (current_prefix);

      if (ACE_OS::strcmp (current_prefix, d->prefix ()) != 0)
        {
          idl_global->err ()->error1 (UTL_Error::EIDL_PREFIX_CONFLICT,
                                      d);

          return 0;
        }
    }

  if (ct == 0) 
    {
      idl_global->err ()->not_a_type (d);
      return 0;
    }

  if (ct->node_type () == AST_Decl::NT_except) 
    {
      idl_global->err ()->not_a_type (d);
      return 0;
    }

  if (this->pd_decl_type == FD_simple || this->pd_complex_part == 0) 
    {
      return ct;
    }

  if (this->pd_complex_part->node_type () == AST_Decl::NT_array) 
    {
      arr = AST_Array::narrow_from_decl (this->pd_complex_part);
      arr->set_base_type (ct);

      // Add the new array to the types defined in the global scope
      idl_global->root ()->fe_add_array (arr);

      return arr;
    }

  // We shouldn't get here.
  return 0;
}

// Data accessors.

AST_Decl *
FE_Declarator::complex_part (void)
{
  return this->pd_complex_part;
}

UTL_ScopedName *
FE_Declarator::name (void)
{
  return this->pd_name;
}

FE_Declarator::DeclaratorType
FE_Declarator::decl_type (void)
{
  return this->pd_decl_type;
}
