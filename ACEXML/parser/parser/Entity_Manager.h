// -*- C++ -*-

//=============================================================================
/**
 *  @file    Entity_Manager.h
 *
 *  $Id$
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACEXML_ENTITY_MANAGER_H
#define ACEXML_ENTITY_MANAGER_H

#include "common/XML_Types.h"
#include "parser/parser/Parser_export.h"
#include "ace/Functor.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Containers_T.h"

typedef ACE_Hash_Map_Entry<ACEXML_String,
                           ACEXML_String> ACEXML_ENTITY_ENTRY;

typedef ACE_Hash_Map_Manager_Ex<ACEXML_String,
                                ACEXML_String,
                                ACE_Hash<ACEXML_String>,
                                ACE_Equal_To<ACEXML_String>,
                                ACE_Null_Mutex> ACEXML_ENTITIES_MANAGER;

typedef ACE_Hash_Map_Iterator_Ex<ACEXML_String,
                                 ACEXML_String,
                                 ACE_Hash<ACEXML_String>,
                                 ACE_Equal_To<ACEXML_String>,
                                 ACE_Null_Mutex> ACEXML_ENTITIES_MANAGER_ITER;

typedef ACE_Hash_Map_Reverse_Iterator_Ex<ACEXML_String,
                                         ACEXML_String,
                                         ACE_Hash<ACEXML_String>,
                                         ACE_Equal_To<ACEXML_String>,
                                         ACE_Null_Mutex> ACEXML_ENTITIES_MANAGER_REVERSE_ITER;

/**
 * @class ACEXML_Entity_Manager Entity_Manager.h "parser/parser/Entity_Manager.h"
 *
 * @brief Class to manage and resolve entity references.
 *
 * @todo Fill in details for this class.
 */
class ACEXML_PARSER_Export ACEXML_Entity_Manager
{
public:
  /// Default constructor.
  ACEXML_Entity_Manager (void);

  /// Destructor.
  ~ACEXML_Entity_Manager (void);

  /// Add a new entity declaration.
  int add_entity (const ACEXML_Char *ref,
                  const ACEXML_Char *value);

  /// Resolve an entity reference.
  const ACEXML_String *resolve_entity (const ACEXML_Char *ref);

private:
  ACEXML_ENTITIES_MANAGER entities_;
};

#if defined (__ACEXML_INLINE__)
# include "parser/parser/Entity_Manager.i"
#endif /* __ACEXML_INLINE__ */
#endif /* ACEXML_ENTITY_MANAGER_H */
