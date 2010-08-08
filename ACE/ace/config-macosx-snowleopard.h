// $Id$
#ifndef ACE_CONFIG_MACOSX_SNOWLEOPARD_H
#define ACE_CONFIG_MACOSX_SNOWLEOPARD_H


#include "ace/config-macosx-leopard.h"

#ifdef __clang__
#ifdef ACE_HAS_GCC_ATOMIC_BUILTINS
#undef ACE_HAS_GCC_ATOMIC_BUILTINS
#endif

#define ACE_ANY_OPS_USE_NAMESPACE

#endif

// This header has been deprecated in Snow Leopard.
#define ACE_LACKS_UCONTEXT_H

#endif // ACE_CONFIG_MACOSX_SNOWLEOPARD_H
