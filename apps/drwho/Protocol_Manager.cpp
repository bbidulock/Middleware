// $Id$
#include "Options.h"
#include "new.h"
#include "Protocol_Manager.h"

#if 0
/* Static initializers. */
int	      Protocol_Manager::total_users   = 0;
Search_Struct *Protocol_Manager::ss	    = 0;
#endif 

/* Functions shared between client and server. */

/* Returns a pointer to the Drwho_Node associated with HOST_NAME (if
   it exists, otherwise a new node is created.  Note that if a
   Drwho_Node is found it is moved to the front of the list so that
   subsequent finds are faster (i.e., self-organizing!) */ 
     
Drwho_Node *
Protocol_Manager::get_drwho_node (char *key_name, Drwho_Node *&head)
{
  for (Drwho_Node **temp = &head; *temp != 0; temp = &(*temp)->next)
    if (strcmp (key_name, (*temp)->get_login_name ()) == 0)
      break;
  
  if (*temp == 0)
    return head = new (PRIVATE_POOL) Drwho_Node (key_name, head);
  else
    {
      Drwho_Node *t = *temp;
      
      *temp = (*temp)->next;
      t->next = head;
      return head = t;
    }
}

#ifndef __OPTIMIZE__
Protocol_Manager::Protocol_Manager (void): total_users (0)
{}

Protocol_Manager::~Protocol_Manager (void)
{
  if (Options::get_opt (Options::DEBUG))
    fprintf (stderr, "disposing Protocol_Manager\n");
}

/* Returns the next friend in the sequence of sorted friends. */

Protocol_Record *
Protocol_Manager::get_next_friend (void)
{
  return this->ss->get_next_entry ();
}

Protocol_Record *
Protocol_Manager::get_each_friend (void)
{
  return this->ss->get_each_entry ();
}

/* Returns the number of friends. */

int
Protocol_Manager::friend_count (void)
{
  return this->ss->n_elems ();
}

/* Returns total number of users logged in throughout the system. */

int 
Protocol_Manager::get_total_users (void)
{
  return Protocol_Manager::total_users;
}

void			
Protocol_Manager::increment_total_users (int remote_users)
{
  Protocol_Manager::total_users += remote_users;
}
#endif /* __OPTIMIZE__ */
