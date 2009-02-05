#include "tao/ZIOP/ZIOP_ORBInitializer.h"
#include "tao/ZIOP/ZIOP_Policy_Validator.h"
#include "tao/ZIOP/ZIOP.h"
#include "tao/ORB_Core.h"
#include "tao/debug.h"
#include "tao/ORBInitializer_Registry.h"
#include "tao/operation_details.h"
#include "tao/Stub.h"

ACE_RCSID (ZIOP,
           ZIOP,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Set the flag to zero to start with
bool TAO_ZIOP_Loader::is_activated_ = false;

TAO_ZIOP_Loader::TAO_ZIOP_Loader (void)
{
}

TAO_ZIOP_Loader::~TAO_ZIOP_Loader (void)
{
}

int
TAO_ZIOP_Loader::init (int, ACE_TCHAR* [])
{
#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0
  if (TAO_ZIOP_Loader::is_activated_ == false && TAO_DEF_GIOP_MINOR >= 2)
    {
      PortableInterceptor::ORBInitializer_ptr tmp_orb_initializer =
        PortableInterceptor::ORBInitializer::_nil ();
      PortableInterceptor::ORBInitializer_var ziop_orb_initializer;

      try
        {
          /// Register the BiDir ORBInitializer.
          ACE_NEW_THROW_EX (tmp_orb_initializer,
                            TAO_ZIOP_ORBInitializer (this),
                            CORBA::NO_MEMORY (
                                CORBA::SystemException::_tao_minor_code (
                                    TAO::VMCID,
                                    ENOMEM),
                                CORBA::COMPLETED_NO));

          ziop_orb_initializer = tmp_orb_initializer;

          PortableInterceptor::register_orb_initializer (
            ziop_orb_initializer.in ());

          TAO_ZIOP_Loader::is_activated_ = true;
        }
      catch (const ::CORBA::Exception& ex)
        {
          if (TAO_debug_level > 0)
            {
              ex._tao_print_exception ("Caught exception:");
            }
          return -1;
        }
    }
#endif
  return 0;
}

void
TAO_ZIOP_Loader::load_policy_validators (TAO_Policy_Validator &val)
{
#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0
  // Is this true? Does the GIOP protocol version matter here?
  if (TAO_DEF_GIOP_MINOR < 2)
    return;

  TAO_ZIOPPolicy_Validator *validator = 0;
  ACE_NEW_THROW_EX (validator,
                    TAO_ZIOPPolicy_Validator (val.orb_core ()),
                    CORBA::NO_MEMORY (
                        CORBA::SystemException::_tao_minor_code (
                            TAO::VMCID,
                            ENOMEM),
                        CORBA::COMPLETED_NO));

  // We may be adding another TAO_BiDirPolicy_Validator instance for
  // the same ORB (different POA). In cases where huge numbers of
  // bi-directional POA instances are created, having a validator
  // instance per POA may introduce additional delays in policy
  // validation and hence, the overal policy creation time. Since this
  // is out of the critical invocation processing path, I plan to keep
  // the design simple and not try to avoid an ineficiency of such
  // small proportions.
  val.add_validator (validator);
#else
  ACE_UNUSED_ARG (val);
#endif
}

int
TAO_ZIOP_Loader::Initializer (void)
{
  return ACE_Service_Config::process_directive (ace_svc_desc_TAO_ZIOP_Loader);
}

bool
TAO_ZIOP_Loader::decompress (TAO_InputCDR& cdr)
{
  CORBA::Object_var compression_manager =
    cdr.orb_core()->resolve_compression_manager();

  Compression::CompressionManager_var manager =
    Compression::CompressionManager::_narrow (compression_manager.in ());

  if (!CORBA::is_nil(manager.in ()))
    {
      ZIOP::CompressedData data;
      //first set the read pointer after the header
      char * my_old_read = cdr.rd_ptr ();
      if (!(cdr >> data))
        return false;
      
      Compression::Compressor_var compressor = manager->get_compressor (data.compressorid, 6);
      CORBA::OctetSeq myout;
      myout.length (data.original_length);

      compressor->decompress (data.data, myout);
      
      //now copy the decompressed data to the stream...
      ACE_Message_Block *mb = (ACE_Message_Block *)cdr.start ();
      mb->rd_ptr (my_old_read);
      mb->wr_ptr(mb->rd_ptr());
      mb->copy((char*)myout.get_buffer(true), 
              (size_t)data.original_length + TAO_GIOP_MESSAGE_HEADER_LEN);
      cdr.start ()->data_block ()->base ()[0] = 0x47;
      cdr.start ()->data_block ()->base ()[TAO_GIOP_MESSAGE_SIZE_OFFSET] = 
        mb->length();
    }
  else
    {
      return false;
    }

  return true;
}

CORBA::ULong
TAO_ZIOP_Loader::compression_low_value (TAO::Profile_Transport_Resolver &resolver) const
{
  CORBA::ULong result = 0;
#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0
  CORBA::Policy_var policy = CORBA::Policy::_nil ();

  if (resolver.stub () == 0)
    {
      policy =
        resolver.stub()->orb_core()->get_cached_policy_including_current (TAO_CACHED_COMPRESSION_LOW_VALUE_POLICY);
    }
  else
    {
      policy = resolver.stub ()->get_cached_policy (TAO_CACHED_COMPRESSION_LOW_VALUE_POLICY);
    }

  if (!CORBA::is_nil (policy.in ()))
    {
      ZIOP::CompressionLowValuePolicy_var srp =
        ZIOP::CompressionLowValuePolicy::_narrow (policy.in ());

      if (!CORBA::is_nil (srp.in ()))
        {
          result = srp->low_value ();
        }
    }
#else
  ACE_UNUSED_ARG (resolver);
#endif
  return result;
}

bool
TAO_ZIOP_Loader::compress (Compression::Compressor_ptr compressor,
                           const ::Compression::Buffer &source,
                           ::Compression::Buffer &target)
{
  try
    {
      compressor->compress (source, target);
    }
  catch (...)
    {
      return false;
    }

  return true;
}

bool
TAO_ZIOP_Loader::check_min_ratio (CORBA::ULong /* original_data_length */, CORBA::ULong /*compressed_length*/) const
{
/*  ::Compression::CompressionRatio ratio = 100 - (compressed_length /original_length) * 100;
  if (resolver.stub () == 0)
    {
      policy =
        resolver.stub()->orb_core()->get_cached_policy_including_current (TAO_CACHED_COMPRESSION_ENABLING_POLICY);
    }
  else
    {
      policy = resolver.stub ()->get_cached_policy (TAO_CACHED_COMPRESSION_ENABLING_POLICY);
    }*/
  return true;
}
// JW compress without details, just stream after 12 bytes
bool
TAO_ZIOP_Loader::marshal_data (TAO_Operation_Details &details, TAO_OutputCDR &stream, TAO::Profile_Transport_Resolver &resolver)
{
#if defined (TAO_HAS_ZIOP) && TAO_HAS_ZIOP == 0
  ACE_UNUSED_ARG (details);
  ACE_UNUSED_ARG (stream);
  ACE_UNUSED_ARG (resolver);
#else
  CORBA::Boolean use_ziop = false;
  Compression::CompressorId compressor_id = Compression::COMPRESSORID_ZLIB;
  Compression::CompressionLevel compression_level = 0;

  CORBA::Policy_var policy = resolver.stub ()->get_cached_policy (TAO_CACHED_COMPRESSION_ENABLING_POLICY);

  if (!CORBA::is_nil (policy.in ()))
    {
      ZIOP::CompressionEnablingPolicy_var srp =
        ZIOP::CompressionEnablingPolicy::_narrow (policy.in ());

      if (!CORBA::is_nil (srp.in ()))
        {
          use_ziop = srp->compression_enabled ();
        }
    }
  
  if (use_ziop)
    {
      policy = resolver.stub ()->get_cached_policy (TAO_CACHED_COMPRESSION_ID_LEVEL_LIST_POLICY);

      if (!CORBA::is_nil (policy.in ()))
        {
          ZIOP::CompressorIdLevelListPolicy_var srp =
            ZIOP::CompressorIdLevelListPolicy::_narrow (policy.in ());

          if (!CORBA::is_nil (srp.in ()))
            {
// JW really check for a compatible compressor between client and server
              ::Compression::CompressorIdLevelList* list = srp->compressor_ids ();
              if (list)
                {
                  compressor_id = (*list)[0].compressor_id; // 0 is not ok, make a test with bzip2/zlib on server and zlib/bzip2 on client
                  compression_level = (*list)[0].compression_level;
                }
              else
                {
                  // No compatible compressor found
                  use_ziop = false;
                }
            }
        }
    }

  ACE_Message_Block* current = const_cast <ACE_Message_Block*> (stream.current ());

  if (use_ziop)
    {
       // Set the read pointer to the point where the application data starts
       current->rd_ptr (TAO_GIOP_MESSAGE_HEADER_LEN);
    }

  current = const_cast <ACE_Message_Block*> (stream.current());
  CORBA::ULong const original_data_length =(CORBA::ULong)(current->wr_ptr() - current->rd_ptr());

  if (use_ziop && original_data_length > 0)
    {
      CORBA::Object_var compression_manager =
        resolver.stub()->orb_core()->resolve_compression_manager();

      Compression::CompressionManager_var manager =
        Compression::CompressionManager::_narrow (compression_manager.in ());

      if (!CORBA::is_nil(manager.in ()))
        {
          Compression::Compressor_var compressor = manager->get_compressor (compressor_id, compression_level);

          if (original_data_length > this->compression_low_value (resolver))
            {
              CORBA::OctetSeq myout;
              CORBA::OctetSeq input (original_data_length, current);
              myout.length (original_data_length);

              bool compressed = this->compress (compressor.in (), input, myout);

              if (compressed && (myout.length () < original_data_length) && (this->check_min_ratio (original_data_length, myout.length())))
                { 
                  stream.compressed (true);
                  current->wr_ptr (current->rd_ptr ());
                  stream.current_alignment (current->wr_ptr() - current->base ());
                  ZIOP::CompressedData data;
                  data.compressorid = compressor_id;
                  data.original_length = input.length();
                  stream.current ()->data_block ()->base ()[0] = 0x5A; 
                  //adjust the size of the message 
                  stream.current ()->data_block ()->base ()[TAO_GIOP_MESSAGE_SIZE_OFFSET] = stream.length ();
                  data.data = myout;
                  stream << data;
                }
            }
        }
    }

  // Set the read pointer back to the starting point
  current->rd_ptr (current->base ());
#endif

  return true;
}

bool
TAO_ZIOP_Loader::marshal_reply_data (TAO_OutputCDR& cdr, TAO_ORB_Core* orb_core)
{
#if defined (TAO_HAS_ZIOP) && TAO_HAS_ZIOP == 0
  ACE_UNUSED_ARG (server_request);
  ACE_UNUSED_ARG (args);
  ACE_UNUSED_ARG (nargs);
#else
  CORBA::Boolean use_ziop = false;
  Compression::CompressorId compressor_id = Compression::COMPRESSORID_ZLIB;
  Compression::CompressionLevel compression_level = 0;

  CORBA::Policy_var policy = orb_core->get_cached_policy_including_current (TAO_CACHED_COMPRESSION_ENABLING_POLICY);

  if (!CORBA::is_nil (policy.in ()))
    {
      ZIOP::CompressionEnablingPolicy_var srp =
        ZIOP::CompressionEnablingPolicy::_narrow (policy.in ());

      if (!CORBA::is_nil (srp.in ()))
        {
          use_ziop = srp->compression_enabled ();
        }
    }

  if (use_ziop)
    {
      policy = orb_core->get_cached_policy_including_current (TAO_CACHED_COMPRESSION_ID_LEVEL_LIST_POLICY);

      if (!CORBA::is_nil (policy.in ()))
        {
          ZIOP::CompressorIdLevelListPolicy_var srp =
            ZIOP::CompressorIdLevelListPolicy::_narrow (policy.in ());

          if (!CORBA::is_nil (srp.in ()))
            {
              ::Compression::CompressorIdLevelList* list = srp->compressor_ids ();
              if (list)
                {
                  compressor_id = (*list)[0].compressor_id;
                  compression_level = (*list)[0].compression_level;
                }
              else
                {
                  // No compatible compressor found
                  use_ziop = false;
                }
            }
        }
    }

  ACE_Message_Block* current = const_cast <ACE_Message_Block*> (cdr.current ());

  char* old_rd_ptr = current->rd_ptr();

  if (use_ziop)
    {
       // Set the read pointer to the point where the data starts
       current->rd_ptr (TAO_GIOP_MESSAGE_HEADER_LEN);
    }
  current = const_cast <ACE_Message_Block*> (cdr.current());
  CORBA::ULong const original_data_length =(CORBA::ULong)(current->wr_ptr() - current->rd_ptr());

  if (use_ziop && original_data_length > 0)
    {
      CORBA::Object_var compression_manager =
        orb_core->resolve_compression_manager();

      Compression::CompressionManager_var manager =
        Compression::CompressionManager::_narrow (compression_manager.in ());

      if (!CORBA::is_nil(manager.in ()))
        {
          Compression::Compressor_var compressor = manager->get_compressor (compressor_id, compression_level);

//          if (original_data_length > this->compression_low_value (resolver)
          if (1)
            {
              CORBA::OctetSeq myout;
              CORBA::OctetSeq input (original_data_length, current);
              myout.length (original_data_length);

              bool compressed = this->compress (compressor.in (), input, myout);

              if (compressed && (myout.length () < original_data_length)) // && (this->check_min_ratio (original_data_length, myout.length())))
                {
                  
                  cdr.compressed (true);
                  current->wr_ptr (current->rd_ptr ());
                  cdr.current_alignment (current->wr_ptr() - current->base ());
                  ZIOP::CompressedData data;
                  data.compressorid = compressor_id;
                  data.original_length = input.length();
                  data.data = myout;
                  cdr << data;
                  current->rd_ptr(old_rd_ptr);
                  int begin = (current->rd_ptr() - current->base ());
                  current->data_block ()->base ()[0 + begin] = 0x5A; 
                  current->data_block ()->base ()[TAO_GIOP_MESSAGE_SIZE_OFFSET + begin] = 
                    cdr.length() - TAO_GIOP_MESSAGE_HEADER_LEN;
                }
            }
        }
    }

  // Set the read pointer back to the starting point
#endif

  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DEFINE (TAO_ZIOP_Loader,
                       ACE_TEXT ("ZIOP_Loader"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_ZIOP_Loader),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)

ACE_FACTORY_DEFINE (TAO_ZIOP, TAO_ZIOP_Loader)

