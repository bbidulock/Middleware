// $Id$
#include "tao/corba.h"

ACE_RCSID(tao, Operation_Table, "$Id$")

// destructor
TAO_Operation_Table::~TAO_Operation_Table (void)
{
}

// Template Specialization for char*
int
ACE_Hash_Map_Manager<const char *, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>::equal (const char *const &id1,
                                                                               const char *const &id2)
{
  return ACE_OS::strcmp (id1, id2) == 0;
}

// Template Specialization for char *

u_long
ACE_Hash_Map_Manager<const char *, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>::hash (const char *const &ext_id)
{
  return ACE::hash_pjw (ext_id);
}

// constructor

TAO_Dynamic_Hash_OpTable::TAO_Dynamic_Hash_OpTable (const TAO_operation_db_entry *db,
						    CORBA::ULong dbsize,
						    CORBA::ULong hashtblsize,
                                                    ACE_Allocator *alloc)
  : hash_ (hashtblsize, alloc)
{
  // Iterate thru each entry in the database and bind the operation
  // name to its corresponding skeleton.

  for (CORBA::ULong i = 0; i < dbsize; i++)
    // @@ (ASG): what happens if bind fails ???
    if (this->bind (db[i].opname_, db[i].skel_ptr_) == -1)
      ACE_ERROR ((LM_DEBUG,
                  "(%P|%t) %p\n",
                  "bind failed"));
}

TAO_Dynamic_Hash_OpTable::~TAO_Dynamic_Hash_OpTable (void)
{
  // Initialize an iterator.  We need to go thru each entry and free
  // up storage allocated to hold the external ids.  In this case,
  // these are strings.
  OP_MAP_MANAGER::ITERATOR iterator (this->hash_);

  for (OP_MAP_MANAGER::ENTRY *entry = 0;
       iterator.next (entry) != 0;
       iterator.advance ())
    {
      // We had allocated memory and stored the string. So we free the
      // memory.
      CORBA::string_free ((char *) entry->ext_id_);
      entry->ext_id_ = 0;

      // We do not own this. So we just set it to 0.
      entry->int_id_ = 0;
    }
}

int
TAO_Dynamic_Hash_OpTable::bind (const char *opname,
                                const TAO_Skeleton skel_ptr)
{
  return this->hash_.bind (CORBA::string_dup (opname), skel_ptr);
}

int
TAO_Dynamic_Hash_OpTable::find (const char *opname,
                                TAO_Skeleton& skel_ptr)
{
  return this->hash_.find ((const char *)opname, skel_ptr);
}

// Linear search strategy

TAO_Linear_Search_OpTable::TAO_Linear_Search_OpTable (void)
{
}

TAO_Linear_Search_OpTable::~TAO_Linear_Search_OpTable (void)
{
}

int
TAO_Linear_Search_OpTable::bind (const char *opname,
                                 const TAO_Skeleton skel_ptr)
{
  ACE_UNUSED_ARG (opname);
  ACE_UNUSED_ARG (skel_ptr);
  return 0;
}

int
TAO_Linear_Search_OpTable::find (const char *opname,
                                 TAO_Skeleton& skelfunc)
{
  const TAO_operation_db_entry *entry = lookup (opname);
  if (entry == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "TAO_Linear_Search_Table:find failed\n"),
                      -1);

  // Valid entry. Figure out the skel_ptr.
  skelfunc = entry->skel_ptr_;

  return 0;
}

// Active Demux search strategy
TAO_Active_Demux_OpTable::TAO_Active_Demux_OpTable (const
						    TAO_operation_db_entry *db,
						    CORBA::ULong dbsize)
  : next_ (0),
    tablesize_ (dbsize),
    tbl_ (new TAO_Active_Demux_OpTable_Entry[dbsize])
{
  // The job of the constructor is to go thru each entry of the
  // database and bind the operation name to its corresponding
  // skeleton.
  for (CORBA::ULong i=0; i < dbsize; i++)
    // @@ (ASG): what happens if bind fails ???
    (void) this->bind (db[i].opname_, db[i].skel_ptr_);
}

TAO_Active_Demux_OpTable::~TAO_Active_Demux_OpTable (void)
{
  delete [] this->tbl_;
}

int
TAO_Active_Demux_OpTable::bind (const char *opname,
				const TAO_Skeleton skel_ptr)
{
  CORBA::ULong i = ACE_OS::atoi (opname);

  if (i < this->tablesize_)
    {
      if (this->tbl_[i].skel_ptr_ != 0)
        // overwriting previous one
        return 1;
      else
	{
	  this->tbl_[i].skel_ptr_ = skel_ptr;
	  return 0;
	}
    }
  return -1; // error
}

int
TAO_Active_Demux_OpTable::find (const char *opname,
                                TAO_Skeleton& skel_ptr)
{
  CORBA::ULong i = ACE_OS::atoi (opname);

  ACE_ASSERT (i < this->tablesize_);
  skel_ptr = this->tbl_[i].skel_ptr_;
  return 0; //success
}

TAO_Active_Demux_OpTable_Entry::TAO_Active_Demux_OpTable_Entry (void)
{
  this->skel_ptr_ = 0;
}

TAO_Active_Demux_OpTable_Entry::~TAO_Active_Demux_OpTable_Entry (void)
{
  this->skel_ptr_ = 0;  // cannot delete this as we do not own it
}

// Do nothing constructor.
TAO_Perfect_Hash_OpTable::TAO_Perfect_Hash_OpTable (void)
{
}

// Do nothing destrctor.
TAO_Perfect_Hash_OpTable::~TAO_Perfect_Hash_OpTable (void)
{
}


// Uses <{opname}> to look up the skeleton function and pass it back
// in <{skelfunc}>.  Returns non-negative integer on success, or -1
// on failure.
int
TAO_Perfect_Hash_OpTable::find (const char *opname,
                                TAO_Skeleton &skelfunc)
{
  const TAO_operation_db_entry *entry = lookup (opname,
                                                ACE_OS::strlen (opname));
  if (entry == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "TAO_Perfect_Hash_Table:find failed\n"),
                      -1);

  // Valid entry. Figure out the skel_ptr.
  skelfunc = entry->skel_ptr_;

  return 0;
}

int
TAO_Perfect_Hash_OpTable::bind (const char *opname,
                                const TAO_Skeleton skel_ptr)
{
  ACE_UNUSED_ARG (opname);
  ACE_UNUSED_ARG (skel_ptr);
  return 0;
}

// Do nothing constructor.
TAO_Binary_Search_OpTable::TAO_Binary_Search_OpTable (void)
{
}

// Do nothing destrctor.
TAO_Binary_Search_OpTable::~TAO_Binary_Search_OpTable (void)
{
}


// Uses <{opname}> to look up the skeleton function and pass it back
// in <{skelfunc}>.  Returns non-negative integer on success, or -1
// on failure.
int
TAO_Binary_Search_OpTable::find (const char *opname,
                                TAO_Skeleton &skelfunc)
{
  const TAO_operation_db_entry *entry = lookup (opname);
  if (entry == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "TAO_Binary_Search_Table:find failed\n"),
                      -1);

  // Valid entry. Figure out the skel_ptr.
  skelfunc = entry->skel_ptr_;

  return 0;
}

int
TAO_Binary_Search_OpTable::bind (const char *opname,
                                const TAO_Skeleton skel_ptr)
{
  ACE_UNUSED_ARG (opname);
  ACE_UNUSED_ARG (skel_ptr);
  return 0;
}

// constructor
TAO_Operation_Table_Parameters::TAO_Operation_Table_Parameters (void)
  : strategy_ (0),
    type_ (TAO_Operation_Table_Parameters::TAO_DYNAMIC_HASH) // default
{
}

TAO_Operation_Table_Parameters::~TAO_Operation_Table_Parameters (void)
{
}

void
TAO_Operation_Table_Parameters::lookup_strategy (TAO_Operation_Table_Parameters::DEMUX_STRATEGY s)
{
  this->type_ = s;
}

// get the lookup type
TAO_Operation_Table_Parameters::DEMUX_STRATEGY
TAO_Operation_Table_Parameters::lookup_strategy (void) const
{
  return this->type_;
}

// set the concrete strategy
void
TAO_Operation_Table_Parameters::concrete_strategy (TAO_Operation_Table *ot)
{
  this->strategy_ = ot;
}

// return the concrete strategy
TAO_Operation_Table* TAO_Operation_Table_Parameters::concrete_strategy (void)
{
  return this->strategy_;
}

TAO_Operation_Table_Factory::TAO_Operation_Table_Factory (void)
{
}

TAO_Operation_Table_Factory::~TAO_Operation_Table_Factory (void)
{
}

TAO_Operation_Table *
TAO_Operation_Table_Factory::opname_lookup_strategy (void)
{
  TAO_Operation_Table_Parameters *p = TAO_OP_TABLE_PARAMETERS::instance ();

  return p->concrete_strategy ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Hash_Map_Iterator_Base<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Iterator<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Reverse_Iterator<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Manager<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Entry<const char*, TAO_Skeleton>;
template class ACE_Singleton<TAO_Operation_Table_Parameters, ACE_SYNCH_RECURSIVE_MUTEX>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Hash_Map_Iterator_Base<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Manager<const char*, TAO_Skeleton, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Entry<const char*, TAO_Skeleton>
#pragma instantiate ACE_Singleton<TAO_Operation_Table_Parameters, ACE_SYNCH_RECURSIVE_MUTEX>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
