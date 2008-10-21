#ifndef MESSENGERI_H_
#define MESSENGERI_H_

#include "MessengerS.h"

class  Messenger_i : public virtual POA_Messenger
{
public:
  virtual CORBA::Boolean send_message (
    const char * user_name,
    const char * subject,
    char *& message
  );
};

#endif
