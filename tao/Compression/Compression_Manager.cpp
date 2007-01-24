#include "tao/Compression/Compression_Manager.h"

ACE_RCSID (Compression,
           Compression_Manager,
           "$Id$")

#include "tao/ORB_Constants.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{

void CompressionManager::register_factory (
  ::Compression::CompressorFactory_ptr compressor_factory)
          ACE_THROW_SPEC ((
            ::CORBA::SystemException,
            ::Compression::FactoryAlreadyRegistered))
{
  if (!::CORBA::is_nil (compressor_factory))
    {
      ACE_Guard <ACE_SYNCH_MUTEX> guard (mutex_);

      CORBA::ULong const length = this->factories_.length ();

      for (CORBA::ULong i = 0; i < length; ++i)
        {
          ::Compression::CompressorId const current =
            this->factories_[i]->compressor_id ();

          if (compressor_factory->compressor_id () == current)
            {
              throw (::Compression::FactoryAlreadyRegistered ());
            }
        }
      factories_.length (length + 1);
      factories_[length] = ::Compression::CompressorFactory::_duplicate (compressor_factory);
    }
  else
    {
      // @todo Standardize this minor code
      throw ( ::CORBA::BAD_PARAM (CORBA::OMGVMCID | 44,
                                   CORBA::COMPLETED_YES));
    }
}

void
CompressionManager::unregister_factory (
  ::Compression::CompressorId compressor_id)
          ACE_THROW_SPEC ((
            ::CORBA::SystemException,
            ::Compression::UnknownCompressorId
          ))
{
  ACE_Guard <ACE_SYNCH_MUTEX> guard (mutex_);

  CORBA::ULong const length = this->factories_.length ();

  for (CORBA::ULong i = 0; i < length; ++i)
    {
      ::Compression::CompressorId const current =
        this->factories_[i]->compressor_id ();

      if (current != compressor_id)
        {
          continue;
        }

      this->factories_[i] = ::Compression::CompressorFactory::_nil ();
      // make sequence smaller

      return;
    }

  // todo exception
  throw (::Compression::UnknownCompressorId ());
}

::Compression::CompressorFactory_ptr
CompressionManager::get_factory (
  ::Compression::CompressorId compressor_id)
          ACE_THROW_SPEC ((
            ::CORBA::SystemException,
            ::Compression::UnknownCompressorId
          ))
{
  ACE_Guard <ACE_SYNCH_MUTEX> guard (mutex_);

  CORBA::ULong const length = this->factories_.length ();

  for (CORBA::ULong i = 0; i < length; ++i)
    {
      ::Compression::CompressorId const current =
        this->factories_[i]->compressor_id ();

      if (current != compressor_id)
        {
          continue;
        }

      return ::Compression::CompressorFactory::_duplicate (this->factories_[i]);
    }

  throw (::Compression::UnknownCompressorId ());

  ACE_NOTREACHED (return ::Compression::CompressorFactory::_nil ());
}

::Compression::Compressor_ptr
CompressionManager::get_compressor (
            ::Compression::CompressorId compressor_id,
            ::Compression::CompressionLevel compression_level
          )
          ACE_THROW_SPEC ((
            ::CORBA::SystemException,
            ::Compression::UnknownCompressorId
          ))
{
  ::Compression::CompressorFactory_var factory = this->get_factory (compressor_id);

  return factory->get_compressor (compression_level);
}

::Compression::CompressorFactorySeq *
CompressionManager::get_factories (
          )
          ACE_THROW_SPEC ((
            ::CORBA::SystemException
          ))
{
  // todo
  return 0;
}

}

TAO_END_VERSIONED_NAMESPACE_DECL
