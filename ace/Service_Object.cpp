// $Id$

#include "ace/config-all.h"

#include "ace/Service_Object.h"

#if !defined (__ACE_INLINE__)
#include "ace/Service_Object.inl"
#endif /* __ACE_INLINE__ */

#include "ace/OS_NS_stdio.h"
#include "ace/Service_Types.h"
#include "ace/DLL.h"
#include "ace/ACE.h"
#if defined (ACE_OPENVMS)
# include "ace/Lib_Find.h"
#endif

ACE_RCSID (ace,
           Service_Object,
           "$Id$")

  ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Service_Object)
  ACE_ALLOC_HOOK_DEFINE(ACE_Service_Type)

  void
ACE_Service_Type::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Type::dump");
#endif /* ACE_HAS_DUMP */


}

ACE_Service_Type::ACE_Service_Type (const ACE_TCHAR *n,
                                    ACE_Service_Type_Impl *t,
                                    const ACE_DLL &dll,
                                    int active)
  : name_ (0),
    type_ (t),
    dll_ (dll),
    active_ (active),
    fini_already_called_ (0)
{
  ACE_TRACE ("ACE_Service_Type::ACE_Service_Type");
  this->name (n);
}

ACE_Service_Type::ACE_Service_Type (const ACE_TCHAR *n,
                                    ACE_Service_Type_Impl *t,
                                    ACE_SHLIB_HANDLE handle,
                                    int active)
  : name_ (0),
    type_ (t),
    active_ (active),
    fini_already_called_ (0)
{
  ACE_TRACE ("ACE_Service_Type::ACE_Service_Type");
  ACE_DLL &dll = const_cast<ACE_DLL &> (this->dll_);
  dll.set_handle (handle);
  this->name (n);
}

ACE_Service_Type::~ACE_Service_Type (void)
{
  ACE_TRACE ("ACE_Service_Type::~ACE_Service_Type");
  this->fini ();

  delete [] const_cast <ACE_TCHAR *> (this->name_);
}

int
ACE_Service_Type::fini (void)
{
  if (!this->fini_already_called_)
    {
      this->fini_already_called_ = 1;
      if (this->type_ != 0)
        return this->type_->fini ();
      else
        return 1; // No implementation was found.
                  // Currently only makes sense for dummy ST, used to "reserve"
                  // a spot (kind of like forward-declarations) for a dynamic
                  // service. This is necessary to help enforce the correct
                  // finalization order, when such service also has any
                  // (dependent) static services
    }
  return 0;
}

int
ACE_Service_Type::suspend (void) const
{
  ACE_TRACE ("ACE_Service_Type::suspend");
  (const_cast<ACE_Service_Type *> (this))->active_ = 0;
  return this->type_->suspend ();
}

int
ACE_Service_Type::resume (void) const
{
  ACE_TRACE ("ACE_Service_Type::resume");
  (const_cast<ACE_Service_Type *> (this))->active_ = 1;
  return this->type_->resume ();
}

/// Replace with a specific dll. Will only succeed (return 0) if the
/// instance is not associated with a DLL already. Primary use of
/// this method is to associate static service object with the DLL
/// that contains their destruction/finalization code.
void
ACE_Service_Type::relocate (const ACE_DLL & adll)
{
  this->dll_ = adll;
}


ACE_Service_Object::ACE_Service_Object (ACE_Reactor *r)
  : ACE_Event_Handler (r)
{
  ACE_TRACE ("ACE_Service_Object::ACE_Service_Object");
}

ACE_Service_Object::~ACE_Service_Object (void)
{
  ACE_TRACE ("ACE_Service_Object::~ACE_Service_Object");
}

int
ACE_Service_Object::suspend (void)
{
  ACE_TRACE ("ACE_Service_Object::suspend");
  return 0;
}

int
ACE_Service_Object::resume (void)
{
  ACE_TRACE ("ACE_Service_Object::resume");
  return 0;
}

void
ACE_Service_Type::name (const ACE_TCHAR *n)
{
  ACE_TRACE ("ACE_Service_Type::name");

  delete [] const_cast <ACE_TCHAR *> (this->name_);
  this->name_ = ACE::strnew (n);
}

#if defined (ACE_OPENVMS)
ACE_Dynamic_Svc_Registrar::ACE_Dynamic_Svc_Registrar (const ACE_TCHAR* alloc_name,
                                                      void* svc_allocator)
{
  // register service allocator function by full name in ACE singleton registry
  ACE::ldregister (alloc_name, svc_allocator);
}
#endif

ACE_END_VERSIONED_NAMESPACE_DECL
