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

#ifndef _UTL_LIST_UTL_LIST_HH
#define _UTL_LIST_UTL_LIST_HH

// utl_list.hh
//
// General single-linked lists

/*
** DEPENDENCIES: NONE
**
** USE: Included from util.hh
*/

// NOTE: This list class only works correctly because we use single public
//       inheritance, as opposed to multiple inheritance or public virtual.
//       It relies on a type-unsafe cast from UTL_List to subclasses, which
//       will cease to operate correctly if you use either multiple or
//       public virtual inheritance.

// Forward declare active iterator for UTL_List
class   UTL_ListActiveIterator;

class TAO_IDL_FE_Export UTL_List
{
public:
  // Operations

  // Constructor
  UTL_List (UTL_List *c);

  // Destructor
  virtual ~UTL_List (void);

  // Smash last cdr pointer in "this" with l
  void nconc (UTL_List *l);

  // Copy the list starting at "this"
  virtual UTL_List *copy ();

  // Get next list
  UTL_List *tail ();

  // Set next list
  void set_tail (UTL_List *l);

  // How long is this list?
  long length ();

private:
  // Data
  UTL_List *pd_cdr_data;   // The next list

  // Operations
  long list_length (long n); // How long is it?

  // Friend class
  friend class UTL_ListActiveIterator; // Friend class
};

// Active iterator for lists
class TAO_IDL_FE_Export UTL_ListActiveIterator
{
public:
  // Operations

  // Constructor(s)
  UTL_ListActiveIterator (UTL_List *s);

  // Get next list
  virtual void next ();

  // Are we at the end of this list?
  virtual long is_done ();

protected:
  // Data
  UTL_List *source;                // On what to iterate?
};

#endif           // _UTL_LIST_UTL_LIST_HH
