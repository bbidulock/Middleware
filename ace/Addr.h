/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Addr.h
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

#if !defined (ACE_ADDR_H)
#define ACE_ADDR_H

#include "ace/ACE.h"

class ACE_Export ACE_Addr 
  //  = TITLE
  //     Defines the base class for the "address family independent"
  //     address format.
{
public:
  // = Initialization method.

  ACE_Addr (int type = -1, int size = -1);
  // Initializes instance variables. 

  // = Get/set the size of the address. 

  int get_size (void) const;
  // Return the size of the address.

  void set_size (int size);
  // Sets the size of the address. 

  // = Get/set the type of the address. 

  int get_type (void) const;
  // Get the type of the address. 

  void set_type (int type);
  // Set the type of the address. 

  virtual void *get_addr (void) const;
  // Return a pointer to the address.

  virtual void set_addr (void *, int len);
  // Set a pointer to the address.

  // = Equality/inequality tests
  int operator == (const ACE_Addr &sap) const;
  // Check for address equality.

  int operator != (const ACE_Addr &sap) const;
  // Check for address inequality.

  void base_set (int type, int size);
  // Initializes instance variables.

#if defined (ACE_HAS_BROKEN_SAP_ANY)
  static const ACE_Addr sap_any (void);
  // Wild-card address.

  // This #define works around broken C++ compilers...
#define sap_any sap_any()
#else
  static const ACE_Addr sap_any;
  // Wild-card address.
#endif /* ACE_HAS_BROKEN_SAP_ANY */

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  int addr_type_; 
  // e.g., AF_UNIX, AF_INET, AF_SPIPE, etc.

  int addr_size_; 
  // Number of bytes in the address.
};

#if defined (__ACE_INLINE__)
#include "ace/Addr.i"
#endif /* __ACE_INLINE__ */

#endif /* ACE_ADDR_H */
