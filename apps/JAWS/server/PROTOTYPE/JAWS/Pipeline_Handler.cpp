// $Id$

#if !defined (JAWS_PIPELINE_HANDLER_CPP)
#define JAWS_PIPELINE_HANDLER_CPP

#include "JAWS/Pipeline_Handler.h"

template <class TYPE>
JAWS_Pipeline_Handler<TYPE>::JAWS_Pipeline_Handler (void)
{
}

template <class TYPE> int
JAWS_Pipeline_Handler<TYPE>::put (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  TYPE *data = ACE_dynamic_cast (TYPE *, 
                                 mb->data_block ());

  status = this->handle_input (data, tv);

  return (status != -1) ? this->put_next (mb, tv) : -1;
}

#endif /* !defined (JAWS_PIPELINE_HANDLER_CPP) */
