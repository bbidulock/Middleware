//$Id$

#ifndef CLEANUP_STRATEGIES_T_C
#define CLEANUP_STRATEGIES_T_C

#define ACE_BUILD_DLL

#include "ace/Cleanup_Strategies_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#define ACE_LACKS_PRAGMA_ONCE
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/Cleanup_Strategies_T.i"
#endif /* ACE_LACKS_INLINE_FUNCTIONS */

ACE_RCSID(ace, Cleanup_Strategies_T, "$Id$")

////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (CONTAINER &container,
                                                      KEY *key,
                                                      VALUE *value)
{
  ACE_UNUSED_ARG (value);

  return container.unbind (*key);
}

////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Recyclable_Handler_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (CONTAINER &container,
                                                          KEY *key,
                                                          VALUE *value)
{
  value->first ()->recycler (0, 0);

  value->first ()->close ();

  if (container.unbind (*key) == -1)
    return -1;

  return 0;
}

/////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Handler_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (CONTAINER &container,
                                                              KEY *key,
                                                              VALUE *value)
{
  // Remove the item from cache only if the handler isnt in use.
  if ((*value)->active () == 0)
    {
      (*value)->close ();

      if (container.unbind (*key) == -1)
        return -1;

    }

  return 0;
}

////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Null_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (CONTAINER &container,
                                                           KEY *key,
                                                           VALUE *value)
{
  ACE_UNUSED_ARG (container);
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (value);

  return 0;
}

#endif /* CLEANUP_STRATEGIES_T_C */
