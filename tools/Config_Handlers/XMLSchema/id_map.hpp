// -*- C++ -*-

//=============================================================================
/**
 * @file    id_map.hpp
 *
 * This file contains the ID_Map class which has the responsibility of linking
 * XML IDREF objects to their XML ID counterparts.  In the output files, this 
 * means that a <IDREF name>_ptr() will return a pointer to the identified 
 * object.
 * 
 * Exception NULL_PTR_Entry is thrown when a program attempts to add a NULL_PTR
 * to either the id_map or idref_map.  
 * 
 * Exception Unresolved_IDREF is thrown if an element in an XML document attempts
 * to reference an ID that does not exist.
 * 
 * @author Jason R. Cody <jason.r.cody@vanderbilt.edu; jason.r.cody@gmail.com>
 */
//=============================================================================

#ifndef _ID_MAP_H
#define _ID_MAP_H

//ID_Map makes use of the Types::idref_ data member to set it to the appropriate
//object created during parsing
#include "XMLSchema/Types.hpp"

//The ID_Map is a Thread Specific Storage element.
#include "ace/TSS_T.h"


 /**
 * @class ID_Map
 *
 * @brief A class that handles the mapping of IDREF objects to objects with the
 *  respective ID.
 */
  class ID_Map
  {
    public:

    //Trait to allow for ease of thread specific storage.
    typedef ACE_TSS<ID_Map> TSS_ID_Map;
    typedef std::multimap<XMLSchema::NCName<ACE_TCHAR>, XSCRT::Type*>::iterator idref_iterator;
    typedef std::map<XMLSchema::ID<ACE_TCHAR>, XSCRT::Type*>::iterator id_iterator;

    //Exception Classes
    //NULL_PTR_Entry thrown when a NULL PTR is added to the
    //ID_Map
    class NULL_PTR_Entry {};
 
    //Unresolved_IDREF thrown when there are IDREF's in the 
    //XML document.
    class Unresolved_IDREF {};

    //Only a default constructor and destructor are needed
    //Constructor
    ID_Map ()
    {
    }

    //Destructor
    ~ID_Map ()
    {
    }

    //Add an ID to the ID map
    void add_id (XMLSchema::ID<ACE_TCHAR> id, XSCRT::Type *obj_ref)
    {
      if (obj_ref)
      {
        this->id_map_[id] = obj_ref;
      }
      else
      {
        throw NULL_PTR_Entry();
      }
        return;
    }

    //Add an IDREF to the IDREF map
    void add_idref (XMLSchema::NCName<ACE_TCHAR> idref, XSCRT::Type *obj_ref)
    {
      if (obj_ref)
      {
        //this->idref_map_[idref] = obj_ref;
        this->idref_map_.insert(std::pair<XMLSchema::NCName<ACE_TCHAR>, XSCRT::Type*>(idref, obj_ref));
      }
      else 
      {
        throw NULL_PTR_Entry();
      }
      return;
    }


    //Sets the referencing elements XSCRT::Type::idref_ to point to the 
    //referenced element.
    //Note: The pointer is of type "XSCRT::Type*"
    void resolve_idref ( void )
    {
      //Declare iterators to navigate the maps
      ID_Map::id_iterator id_iterator;
      ID_Map::idref_iterator idref_iterator;

      for (idref_iterator = this->idref_map_.begin(); 
           idref_iterator != this->idref_map_.end();
           ++idref_iterator)
      {
        id_iterator = this->id_map_.find(idref_iterator->first);
        if (id_iterator != this->id_map_.end())
        {
          //Author Types::idref_ is set to the book.
          idref_iterator->second->set_idref(id_iterator->second);
        }
        else
        {
          throw Unresolved_IDREF();
        }
      }
    }

    private:
    //id_map_: maps the ID string to the element with the
    //         ID attribute
    //idref_map_: multimap that maps the IDREF string to the 
    //            element with the IDREF attribute
    std::map<XMLSchema::ID<ACE_TCHAR>, XSCRT::Type*> id_map_;
    std::multimap<XMLSchema::NCName<ACE_TCHAR>, XSCRT::Type*> idref_map_;
  };

#endif /* _ID_MAP_HPP */
