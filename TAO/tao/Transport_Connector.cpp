#include "Transport_Connector.h"
#include "Transport.h"
#include "ORB_Core.h"
#include "MProfile.h"
#include "Profile.h"
#include "Environment.h"
#include "Thread_Lane_Resources.h"
#include "debug.h"
#include "Connect_Strategy.h"
#include "Client_Strategy_Factory.h"
#include "Connection_Handler.h"
#include "Profile_Transport_Resolver.h"

#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
# include "Transport_Connector.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (tao,
           Connector,
           "$Id$")

// Connector
TAO_Connector::TAO_Connector (CORBA::ULong tag)
  : active_connect_strategy_ (0),
    tag_(tag),
    orb_core_ (0)
{
}

TAO_Connector::~TAO_Connector (void)
{
  delete this->active_connect_strategy_;
}

int
TAO_Connector::make_mprofile (const char *string,
                              TAO_MProfile &mprofile
                              ACE_ENV_ARG_DECL)
{
  // This method utilizes the "Template Method" design pattern to
  // parse the given URL style IOR for the protocol being used
  // and create an mprofile from it.
  //
  // The methods that must be defined by all Connector sub-classes are:
  //      make_profile
  //      check_prefix

  // Check for a valid string
  if (!string || !*string)
    {
      ACE_THROW_RETURN (CORBA::INV_OBJREF (
                          CORBA::SystemException::_tao_minor_code (
                            TAO_DEFAULT_MINOR_CODE,
                            EINVAL),
                          CORBA::COMPLETED_NO),
                        -1);
    }

  // Check for the proper prefix in the IOR.  If the proper prefix isn't
  // in the IOR then it is not an IOR we can use.
  if (this->check_prefix (string) != 0)
    {
      return 1;
      // Failure: not the correct IOR for this protocol.
      // DO NOT throw an exception here since the Connector_Registry
      // should be allowed the opportunity to continue looking for
      // an appropriate connector.
    }

  if (TAO_debug_level > 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) - TAO_Connector::make_mprofile ")
                  ACE_TEXT ("<%s>\n"),
                  ACE_TEXT_CHAR_TO_TCHAR (string)));
    }

  ACE_CString ior;

  ior.set (string, ACE_OS::strlen (string), 1);

  // Find out where the protocol ends
  int ior_index = ior.find ("://");

  if (ior_index == ACE_CString::npos)
    {
      ACE_THROW_RETURN (CORBA::INV_OBJREF (), -1);
      // No colon ':' in the IOR!
    }
  else
    {
      ior_index += 3;
      // Add the length of the colon and the two forward slashes `://'
      // to the IOR string index (i.e. 3)
    }

  // Find the object key
  const int objkey_index =
    ior.find (this->object_key_delimiter (), ior_index);

  if (objkey_index == 0 || objkey_index == ACE_CString::npos)
    {
      ACE_THROW_RETURN (CORBA::INV_OBJREF (), -1);
      // Failure: No endpoints specified or no object key specified.
    }

  const char endpoint_delimiter = ',';
  // The delimiter used to seperate inidividual addresses.

  // Count the number of endpoints in the IOR.  This will be the number
  // of entries in the MProfile.

  CORBA::ULong profile_count = 1;
  // Number of endpoints in the IOR  (initialized to 1).

  // Only check for endpoints after the protocol specification and
  // before the object key.
  for (int i = ior_index; i < objkey_index; ++i)
    {
      if (ior[i] == endpoint_delimiter)
        ++profile_count;
    }

  // Tell the MProfile object how many Profiles it should hold.
  // MProfile::set(size) returns the number profiles it can hold.
  if (mprofile.set (profile_count) != static_cast<int> (profile_count))
    {
      ACE_THROW_RETURN (CORBA::INV_OBJREF (
                          CORBA::SystemException::_tao_minor_code (
                            TAO_MPROFILE_CREATION_ERROR,
                            0),
                          CORBA::COMPLETED_NO),
                        -1);
      // Error while setting the MProfile size!
    }

  // The idea behind the following loop is to split the IOR into several
  // strings that can be parsed by each profile.
  // For example,
  //    `1.3@moo,shu,1.1@chicken/arf'
  // will be parsed into:
  //    `1.3@moo/arf'
  //    `shu/arf'
  //    `1.1@chicken/arf'

  int begin = 0;
  int end = ior_index - 1;
  // Initialize the end of the endpoint index

  for (CORBA::ULong j = 0; j < profile_count; ++j)
    {
      begin = end + 1;

      if (j < profile_count - 1)
        {
          end = ior.find (endpoint_delimiter, begin);
        }
      else
        {
          end = objkey_index;  // Handle last endpoint differently
        }

      if (end < static_cast<int> (ior.length ()) && end != ior.npos)
        {
          ACE_CString endpoint = ior.substring (begin, end - begin);

          // Add the object key to the string.
          endpoint += ior.substring (objkey_index);

          // The endpoint should now be of the form:
          //    `N.n@endpoint/object_key'
          // or
          //    `endpoint/object_key'

          TAO_Profile *profile =
            this->make_profile (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_CHECK_RETURN (-1);
          // Failure:  Problem during profile creation

          // Initialize a Profile using the individual endpoint
          // string.
          // @@ Not exception safe!  We need a TAO_Profile_var!
          profile->parse_string (endpoint.c_str ()
                                 ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (-1);

          // Give up ownership of the profile.
          if (mprofile.give_profile (profile) == -1)
            {
              profile->_decr_refcnt ();

              ACE_THROW_RETURN (CORBA::INV_OBJREF (
                                  CORBA::SystemException::_tao_minor_code (
                                     TAO_MPROFILE_CREATION_ERROR,
                                     0),
                                  CORBA::COMPLETED_NO),
                                -1);
              // Failure presumably only occurs when MProfile is full!
              // This should never happen.
            }
        }
      else
        {
          ACE_THROW_RETURN (CORBA::INV_OBJREF (), -1);
          // Unable to seperate endpoints
        }
    }

  return 0;  // Success
}


TAO_Transport*
TAO_Connector::connect (TAO::Profile_Transport_Resolver *r,
                        TAO_Transport_Descriptor_Interface *desc,
                        ACE_Time_Value *timeout
                        ACE_ENV_ARG_DECL_NOT_USED)
{
  if ((this->set_validate_endpoint (
         desc->endpoint ()) == -1) || desc == 0)
    {
      return 0;
    }

  TAO_Transport *base_transport = 0;

  TAO_Transport_Cache_Manager &tcm =
    this->orb_core ()->lane_resources ().transport_cache ();

  // Check the Cache first for connections
  // If transport found, reference count is incremented on assignment
  // @@todo: We need to send the timeout value to the cache registry
  // too. That should be the next step!
  if (tcm.find_transport (desc,
                          base_transport) != 0)
    {
      // @@TODO: This is not the right place for this!
      // Purge connections (if necessary)
      tcm.purge ();

      return this->make_connection (r,
                                    *desc,
                                    timeout);
    }

  // When we get a connected transport from the cache, than things are easy,
  // return that, in case it is not connected we have to do several extra
  // things
  if (base_transport->is_connected())
      return base_transport;

  if (TAO_debug_level > 4)
    ACE_DEBUG ((LM_DEBUG,
                "TAO (%P|%t) - Transport_Connector::connect, "
                "got an existing %s Transport[%d]\n",
                base_transport->is_connected() ? "connected" : "unconnected",
                base_transport->id ()));

  // Now if we are not completely connected...
  if (r->blocked ())
    {
      // Wait until the connection is ready
      int result =
        this->active_connect_strategy_->wait (
            base_transport,
            timeout);

      if (TAO_debug_level > 2)
        ACE_DEBUG ((LM_DEBUG,
                    "TAO (%P|%t) - Transport_Connector::connect, "
                    "wait done result = %d\n",
                    result));

      // There are three possibilities when wait() returns: (a)
      // connection succeeded; (b) connection failed; (c) wait()
      // failed because of some other error.  It is easy to deal with
      // (a) and (b).  (c) is tricky since the connection is still
      // pending and may get completed by some other thread.  The
      // following method deals with (c).
      result =
         this->check_connection_closure (base_transport->connection_handler(),
                                         result);

      // In case of errors.
      if (result == -1)
        {
          // Give users a clue to the problem.
          if (TAO_debug_level > 3)
            {
              ACE_ERROR ((LM_ERROR,
                          "TAO (%P|%t) - Transport_Connector::connect, "
                          "connection failed (%p)\n",
                          ACE_TEXT("errno")));
            }

          return 0;
        }

      return base_transport;
    }

  // Now, if we are supossed to be non-blocking, drive the reactor
  // event loop for a 0 timeout
  ACE_Time_Value zero (ACE_Time_Value::zero);
  int result =
    this->active_connect_strategy_->wait (base_transport,
                                          &zero);

// @@bala, check error?

  // Connection not ready yet, just use this base_transport, if
  // we need a connected one we will block later to make sure
  // it is connected
  return base_transport;
}

int
TAO_Connector::create_connect_strategy (void)
{
  if (this->active_connect_strategy_ == 0)
    {
      this->active_connect_strategy_ =
        this->orb_core_->client_factory ()->create_connect_strategy (
          this->orb_core_);
    }

  if (this->active_connect_strategy_ == 0)
    {
      return -1;
    }

  return 0;
}

int
TAO_Connector::check_connection_closure (
  TAO_Connection_Handler *svc_handler,
  int result)
{
  int local_result = result;

  // Check if the handler has been closed.
  int closed =
    svc_handler->is_closed ();

  // In case of failures and close() has not be called.
  if (local_result == -1 && !closed)
    {
      // First, cancel from connector.
      if (this->cancel_svc_handler (svc_handler) == -1)
        return -1;

      // Double check to make sure the handler has not been closed
      // yet.  This double check is required to ensure that the
      // connection handler was not closed yet by some other
      // thread since it was still registered with the connector.
      // Once connector.cancel() has been processed, we are
      // assured that the connector will no longer open/close this
      // handler.
      closed = svc_handler->is_closed ();

      // If closed, there is nothing to do here.  If not closed,
      // it was either opened or is still pending.
      if (!closed)
        {
          // Check if the handler has been opened.
          const int open = svc_handler->is_open ();

          // Some other thread was able to open the handler even
          // though wait failed for this thread.
          if (open)
            {
              // Overwrite the local result.
              local_result = 0;
            }
          else
            {
              // Assert that it is still connecting.
              ACE_ASSERT (svc_handler->is_connecting ());

              // Force close the handler now.
              svc_handler->close_handler ();
            }
        }
    }

  return local_result;
}
