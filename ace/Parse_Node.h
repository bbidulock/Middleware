/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Parse_Node.h
 *
 *  $Id$
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_PARSE_NODE_H
#define ACE_PARSE_NODE_H
#include "ace/pre.h"

#include "ace/Service_Types.h"
#include "ace/DLL.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_LEGACY_SERVICE_CONFIG)
/**
 * @class ACE_Parse_Node
 *
 * @brief Provide the base of the object hierarchy that defines the parse
 * tree of Service Nodes.
 */
class ACE_Export ACE_Parse_Node
{
public:
  ACE_Parse_Node (void);
  ACE_EXPLICIT ACE_Parse_Node (const ACE_TCHAR *name);
  virtual ~ACE_Parse_Node (void);

  ACE_Parse_Node *link (void) const;
  void link (ACE_Parse_Node *);
  virtual void apply (void) = 0;

  const ACE_TCHAR *name (void) const;
  void print (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  const ACE_TCHAR *name_;
  ACE_Parse_Node *next_;
};

/**
 * @class ACE_Suspend_Node
 *
 * @brief Suspend a Service Node.
 */
class ACE_Export ACE_Suspend_Node : public ACE_Parse_Node
{
public:
  ACE_Suspend_Node (const ACE_TCHAR *name);
  ~ACE_Suspend_Node (void);

  virtual void apply (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Resume_Node
 *
 * @brief Resume a Service Node.
 */
class ACE_Export ACE_Resume_Node : public ACE_Parse_Node
{
public:
  ACE_Resume_Node (const ACE_TCHAR *name);
  ~ACE_Resume_Node (void);

  virtual void apply (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Remove_Node
 *
 * @brief Remove a Service Node.
 */
class ACE_Export ACE_Remove_Node : public ACE_Parse_Node
{
public:
  ACE_Remove_Node (const ACE_TCHAR *name);
  ~ACE_Remove_Node (void);

  virtual void apply (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Static_Node
 *
 * @brief Handle a statically linked node.
 */
class ACE_Export ACE_Static_Node : public ACE_Parse_Node
{
public:
  ACE_Static_Node (const ACE_TCHAR *name, ACE_TCHAR *params = 0);
  virtual ~ACE_Static_Node (void);

  virtual void apply (void);
  virtual const ACE_Service_Type *record (void) const;
  ACE_TCHAR *parameters (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// "Command-line" parameters.
  ACE_TCHAR *parameters_;
};

/**
 * @class ACE_Dynamic_Node
 *
 * @brief Handle a dynamically linked node.
 */
class ACE_Export ACE_Dynamic_Node : public ACE_Static_Node
{
public:
  ACE_Dynamic_Node (const ACE_Service_Type *, ACE_TCHAR *params);
  virtual ~ACE_Dynamic_Node (void);

  virtual const ACE_Service_Type *record (void) const;
  virtual void apply (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to a descriptor that describes this node.
  const ACE_Service_Type *record_;
};

/**
 * @class ACE_Stream_Node
 *
 * @brief Handle a Stream.
 */
class ACE_Export ACE_Stream_Node : public ACE_Parse_Node
{
public:
  ACE_Stream_Node (const ACE_Static_Node *, const ACE_Parse_Node *);
  virtual ~ACE_Stream_Node (void);

  virtual void apply (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Linked list of modules that are part of the stream.
  const ACE_Static_Node *node_;
  const ACE_Parse_Node *mods_;
};

/**
 * @class ACE_Location_Node
 *
 * @brief Keep track of where a shared library is located.
 */
class ACE_Export ACE_Location_Node
{
public:
  ACE_Location_Node (void);
  virtual void *symbol (ACE_Service_Object_Exterminator * = 0) = 0;
  virtual void set_symbol (void *h);
  ACE_SHLIB_HANDLE handle (void);
  const ACE_TCHAR *pathname (void) const;
  void pathname (const ACE_TCHAR *h);
  int dispose (void) const;

  virtual ~ACE_Location_Node (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  int open_dll (void);

  /// Pathname to the shared library we are working on.
  const ACE_TCHAR *pathname_;

  /**
   * Flag indicating whether the Service_Object generated by this
   * Location Node should be deleted or not
   * (ACE_Service_Type::DELETE_OBJ.)
   */
  int must_delete_;

  /// The open shared library.
  ACE_DLL dll_;

  /// Symbol that we've obtained from the shared library.
  void *symbol_;
};

/**
 * @class ACE_Object_Node
 *
 * @brief Keeps track of the symbol name for a shared object.
 */
class ACE_Export ACE_Object_Node : public ACE_Location_Node
{
public:
  ACE_Object_Node (const ACE_TCHAR *pathname, const ACE_TCHAR *obj_name);
  virtual void *symbol (ACE_Service_Object_Exterminator * = 0);
  virtual ~ACE_Object_Node (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Name of the object that we're parsing.
  const ACE_TCHAR *object_name_;
};

/**
 * @class ACE_Function_Node
 *
 * @brief Keeps track of the symbol name of for a shared function.
 */
class ACE_Export ACE_Function_Node : public ACE_Location_Node
{
public:
  ACE_Function_Node (const ACE_TCHAR *pathname, const ACE_TCHAR *func_name);
  virtual void *symbol (ACE_Service_Object_Exterminator *gobbler = 0);
  virtual ~ACE_Function_Node (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Name of the function that we're parsing.
  const ACE_TCHAR *function_name_;
};

/**
 * @class ACE_Dummy_Node
 *
 * @brief I forget why this is here... ;-)
 */
class ACE_Export ACE_Dummy_Node : public ACE_Parse_Node
{
public:
  ACE_Dummy_Node (const ACE_Static_Node *, const ACE_Parse_Node *);
  ~ACE_Dummy_Node (void);
  virtual void apply (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Linked list of modules that we're dealing with.
  const ACE_Static_Node *node_;
  const ACE_Parse_Node *mods_;
};

/**
 * @class ACE_Static_Function_Node
 *
 * @brief Keeps track of the symbol name for a function that is not
 * linked in from a DLL, but is statically linked with the
 * application.
 */
class ACE_Export ACE_Static_Function_Node : public ACE_Location_Node
{
public:
  ACE_EXPLICIT ACE_Static_Function_Node (const ACE_TCHAR *func_name);
  virtual void *symbol (ACE_Service_Object_Exterminator * = 0);
  virtual ~ACE_Static_Function_Node (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Name of the function that we're parsing.
  const ACE_TCHAR *function_name_;
};

#if defined (__ACE_INLINE__)
#include "ace/Parse_Node.i"
#endif /* __ACE_INLINE__ */

// Keeps track of the number of errors encountered so far.
extern int ace_yyerrno;

// Global variable used to communicate between the parser and the main
// program.
extern ACE_Service_Config *ace_this_svc;
#endif /* ACE_HAS_LEGACY_SERVICE_CONFIG */

#include "ace/post.h"
#endif /* ACE_PARSE_NODE_H */
