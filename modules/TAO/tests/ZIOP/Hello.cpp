//
// $Id$
//
#include "Hello.h"

ACE_RCSID(Hello, Hello, "$Id$")

Hello::Hello (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
  length_ = 4000000;
}

char *
Hello::get_string (const char * mystring)
{
  ACE_DEBUG ((LM_DEBUG, "Received <%s>\n", mystring));
  return CORBA::string_dup ("Hello there!Hello there!Hello there!Hello there!Hello there!Hello there!Hello there!Hello there!Hello there!\n");
}

Test::Octet_Seq *
Hello::get_big_reply ()
{
  Test::Octet_Seq_var reply_mesg =
    new Test::Octet_Seq (this->length_);

  reply_mesg->length (this->length_);

  return reply_mesg._retn ();
}


void
Hello::shutdown (void)
{
  this->orb_->shutdown (0);
}
