// $Id$

#include "SSLIOP_Factory.h"
#include "SSLIOP_Acceptor.h"
#include "SSLIOP_Connector.h"
#include "ace/Dynamic_Service.h"

ACE_RCSID(tao, SSLIOP_Factory, "$Id$")

static const char prefix_[] = "iiop";

// @@ Very temporary hack that allows us to specify if the client
//    should use SSLIOP with SSL or SSLIOP without SSL.
//    This is set in the TAO_SSLIOP_Protocol_Factory::init().
//         -Ossama
int using_ssl = 0;

TAO_SSLIOP_Protocol_Factory::TAO_SSLIOP_Protocol_Factory (void)
  :  major_ (TAO_DEF_GIOP_MAJOR),
     minor_ (TAO_DEF_GIOP_MINOR)
{
}

TAO_SSLIOP_Protocol_Factory::~TAO_SSLIOP_Protocol_Factory (void)
{
}

int
TAO_SSLIOP_Protocol_Factory::match_prefix (const ACE_CString &prefix)
{
  // Check for the proper prefix for this protocol.
  return (ACE_OS::strcasecmp (prefix.c_str (), ::prefix_) == 0);
}

const char *
TAO_SSLIOP_Protocol_Factory::prefix (void) const
{
  return ::prefix_;
}

char
TAO_SSLIOP_Protocol_Factory::options_delimiter (void) const
{
  return '/';
}

TAO_Acceptor *
TAO_SSLIOP_Protocol_Factory::make_acceptor (void)
{
  TAO_Acceptor *acceptor = 0;

  ACE_NEW_RETURN (acceptor,
                  TAO_SSLIOP_Acceptor,
                  0);

  return acceptor;
}

int
TAO_SSLIOP_Protocol_Factory::init (int argc,
                                   char* argv[])
{
// @@ Very temporary hack that allows us to specify if the client
//    should use SSLIOP with SSL or SSLIOP without SSL.
  if (argc > 0)
    {
      if (ACE_OS::strcasecmp (argv[0], "-UseSSL") == 0)
        {
          ::using_ssl = 1;

          ACE_OS::printf ("********************************************\n"
                          "Using SSL in SSLIOP protocol\n"
                          "********************************************\n");
        }
    }

  return 0;
}

TAO_Connector *
TAO_SSLIOP_Protocol_Factory::make_connector (void)
{
  TAO_Connector *connector = 0;

  ACE_NEW_RETURN (connector,
                  TAO_SSLIOP_Connector,
                  0);
  return connector;
}

int
TAO_SSLIOP_Protocol_Factory::requires_explicit_endpoint (void) const
{
  return 0;
}

ACE_STATIC_SVC_DEFINE (TAO_SSLIOP_Protocol_Factory,
                       ASYS_TEXT ("SSLIOP_Factory"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_SSLIOP_Protocol_Factory),
                       ACE_Service_Type::DELETE_THIS |
                                  ACE_Service_Type::DELETE_OBJ,
                       0)

ACE_FACTORY_DEFINE (TAO, TAO_SSLIOP_Protocol_Factory)
