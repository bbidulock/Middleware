// $Id$

#include "Peer.h"

#if ! defined (__ACE_INLINE__)
#include "Peer.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(lib, TAO_Peer, "$id$")

#include "ace/Arg_Shifter.h"
#include "Name.h"
#include "LookupManager.h"
#include "Options_Parser.h"
#include "orbsvcs/NotifyExtC.h"

TAO_NS_Peer::TAO_NS_Peer (void)
  : poa_name_ (TAO_NS_Name::root_poa)
  , ifgop_ (CosNotifyChannelAdmin::OR_OP)
{
}

TAO_NS_Peer::~TAO_NS_Peer ()
{
}

void
TAO_NS_Peer::init (PortableServer::POA_ptr poa  ACE_ENV_ARG_DECL_NOT_USED)
{
  this->default_POA_ = PortableServer::POA::_duplicate (poa);
}

int
TAO_NS_Peer::init_state (ACE_Arg_Shifter& arg_shifter)
{
  while (arg_shifter.is_anything_left ())
    {
      if (arg_shifter.cur_arg_strncasecmp ("-Admin") == 0)
        {
          arg_shifter.consume_arg ();

          this->admin_name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();
        }
      else if (arg_shifter.cur_arg_strncasecmp ("-Proxy") == 0)
        {
          arg_shifter.consume_arg ();

          this->proxy_name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();
        }
      // Is a POA name specified?
      else if (arg_shifter.cur_arg_strncasecmp ("-POA") == 0)
        {
          arg_shifter.consume_arg ();

          this->poa_name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();
        }
      else if (arg_shifter.cur_arg_strncasecmp ("-Set_QoS") == 0) // -Set_QoS [Qos Options]
        {
          arg_shifter.consume_arg ();

          TAO_NS_Options_Parser qos_parser;
          qos_parser.execute (this->qos_, arg_shifter);
        }
      else
        {
          break;
        }
    } /* while */

  return 0;
}

void
TAO_NS_Peer::set_name (ACE_CString& name)
{
  this->name_ = name;
}

const ACE_CString&
TAO_NS_Peer::get_name (void)
{
  return this->name_;
}

void
TAO_NS_Peer::set_poa (PortableServer::POA_ptr poa  ACE_ENV_ARG_DECL_NOT_USED)
{
  this->default_POA_ = PortableServer::POA::_duplicate (poa);
}

