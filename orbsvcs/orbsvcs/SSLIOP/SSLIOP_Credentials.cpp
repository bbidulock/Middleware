// -*- C++ -*-

#include "SSLIOP_Credentials.h"

ACE_RCSID (TAO_SSLIOP,
           SSLIOP_Credentials,
           "$Id$")


#if !defined (__ACE_INLINE__)
# include "SSLIOP_Credentials.inl"
#endif /* __ACE_INLINE__ */


// SSLIOP does not support delegation, nor does it support detection
// of replayed or misordered GIOP messages.
const Security::AssociationOptions TAO_SSLIOP_DISALLOWED_ASSOCIATIONS =
  Security::DetectReplay
  | Security::DetectMisordering
  | Security::SimpleDelegation
  | Security::CompositeDelegation;

TAO_SSLIOP_Credentials::TAO_SSLIOP_Credentials (X509 *cert, EVP_PKEY *evp)
  : accepting_options_supported_ (Security::Integrity
                                  | Security::Confidentiality
                                  | Security::EstablishTrustInTarget
                                  | Security::NoDelegation),
    accepting_options_required_ (Security::Integrity
                                 | Security::Confidentiality
                                 | Security::NoDelegation),
    invocation_options_supported_ (accepting_options_supported_),
    invocation_options_required_ (Security::NoDelegation),
    x509_ (TAO_SSLIOP_X509::_duplicate (cert)),
    evp_ (TAO_SSLIOP_EVP_PKEY::_duplicate (evp))
{
}

TAO_SSLIOP_Credentials::~TAO_SSLIOP_Credentials (void)
{
}

SecurityLevel2::Credentials_ptr
TAO_SSLIOP_Credentials::copy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_SSLIOP_Credentials *c = 0;
  ACE_NEW_THROW_EX (c,
                    TAO_SSLIOP_Credentials (this->x509_.in (),
                                            this->evp_.in ()),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (SecurityLevel2::Credentials::_nil ());

  return c;
}

void
TAO_SSLIOP_Credentials::destroy (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

Security::InvocationCredentialsType
TAO_SSLIOP_Credentials::credentials_type (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return Security::SecOwnCredentials;
}

Security::AuthenticationStatus
TAO_SSLIOP_Credentials::authentication_state (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Is the following statement correct?

  // No "continued authentication" occurs in SSL.  Authentication is
  // done in one step during SSL session establishment.

  return Security::SecAuthSuccess;
}

char *
TAO_SSLIOP_Credentials::mechanism (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @todo Is the following correct?

  // Mechanism ID is the same as the stringified component ID.  For
  // example, SSLIOP's IOP:ComponentId is 20
  // (SSLIOP::TAG_SSL_SEC_TRANS) meaning that its mechanism ID is
  // "20."
  return CORBA::string_dup ("20");
}

Security::AssociationOptions
TAO_SSLIOP_Credentials::accepting_options_supported (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->accepting_options_supported_;
}

void
TAO_SSLIOP_Credentials::accepting_options_supported (
    Security::AssociationOptions accepting_options_supported
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @todo Verify that the given accepting options are valid

  // SSLIOP does not support delegation, nor does it support detection
  // of replayed or misordered GIOP messages.

  // "accepting_options_supported" should not have "less" capability
  // then "accepting_options_required."

  if ((accepting_options_supported & ::TAO_SSLIOP_DISALLOWED_ASSOCIATIONS)
      || (accepting_options_supported ^ this->accepting_options_required_))
    ACE_THROW (CORBA::BAD_PARAM (
                 CORBA::SystemException::_tao_minor_code (
                   TAO_DEFAULT_MINOR_CODE,
                   EINVAL),
                 CORBA::COMPLETED_NO));

  this->accepting_options_supported_ = accepting_options_supported;
}

Security::AssociationOptions
TAO_SSLIOP_Credentials::accepting_options_required (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->accepting_options_required_;
}

void
TAO_SSLIOP_Credentials::accepting_options_required (
    Security::AssociationOptions accepting_options_required
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // "accepting_options_required" should not have "more" capability
  // then "accepting_options_supported."

  if ((accepting_options_required & ::TAO_SSLIOP_DISALLOWED_ASSOCIATIONS)
      || (accepting_options_required ^ this->accepting_options_supported_))
    ACE_THROW (CORBA::BAD_PARAM (
                 CORBA::SystemException::_tao_minor_code (
                   TAO_DEFAULT_MINOR_CODE,
                   EINVAL),
                 CORBA::COMPLETED_NO));

  this->accepting_options_required_ = accepting_options_required;
}

Security::AssociationOptions
TAO_SSLIOP_Credentials::invocation_options_supported (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->invocation_options_supported_;
}

void
TAO_SSLIOP_Credentials::invocation_options_supported (
    Security::AssociationOptions invocation_options_supported
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if ((invocation_options_supported & ::TAO_SSLIOP_DISALLOWED_ASSOCIATIONS)
      || (invocation_options_supported ^ this->invocation_options_required_))
    ACE_THROW (CORBA::BAD_PARAM (
                 CORBA::SystemException::_tao_minor_code (
                   TAO_DEFAULT_MINOR_CODE,
                   EINVAL),
                 CORBA::COMPLETED_NO));

  this->invocation_options_supported_ = invocation_options_supported;
}

Security::AssociationOptions
TAO_SSLIOP_Credentials::invocation_options_required (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->invocation_options_required_;
}

void
TAO_SSLIOP_Credentials::invocation_options_required (
    Security::AssociationOptions invocation_options_required
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if ((invocation_options_required & ::TAO_SSLIOP_DISALLOWED_ASSOCIATIONS)
      || (invocation_options_required ^ this->invocation_options_supported_))
    ACE_THROW (CORBA::BAD_PARAM (
                 CORBA::SystemException::_tao_minor_code (
                   TAO_DEFAULT_MINOR_CODE,
                   EINVAL),
                 CORBA::COMPLETED_NO));

  this->invocation_options_required_ = invocation_options_required;
}

CORBA::Boolean
TAO_SSLIOP_Credentials::get_security_feature (
    Security::CommunicationDirection /* direction */,
    Security::SecurityFeature /* feature */
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);
}

CORBA::Boolean
TAO_SSLIOP_Credentials::set_attributes (
    const Security::AttributeList & /* requested_attributes */,
    Security::AttributeList_out /* actual_attributes */
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);
}

Security::AttributeList *
TAO_SSLIOP_Credentials::get_attributes (
    const Security::AttributeTypeList & /* attributes */
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);
}

CORBA::Boolean
TAO_SSLIOP_Credentials::is_valid (
    Security::UtcT_out expiry_time
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  X509 *x = this->x509_.in ();

  // The pointer to the underlying X509 structure should only be zero
  // if destroy() was called on this Credentials object.
  if (x == 0)
    ACE_THROW_RETURN (CORBA::BAD_OPERATION (), 0);

  int before_status = ::X509_cmp_current_time (X509_get_notBefore (x));
  int after_status  = ::X509_cmp_current_time (X509_get_notAfter (x));

  if (before_status == 0 || after_status == 0)
    {
      // Error in certificate's "not before" or "not after" field.
      ACE_THROW_RETURN (CORBA::BAD_PARAM (),  // @@ Correct exception?
                        0);
    }

  ASN1_TIME *exp = X509_get_notAfter (x);

  if (exp->length > ACE_SIZEOF_LONG_LONG)
    {
      // @@ Will this ever happen?

      // Overflow!
      expiry_time.time = ACE_UINT64_LITERAL (0xffffffffffffffff);
    }
  else
    {
      expiry_time.time = 0;
      for (int i = 0; i < exp->length; ++i)
        {
          expiry_time.time <<= 8;
          expiry_time.time |= (unsigned char) exp->data[i];
        }
    }

  if (before_status > 0     // Certificate is not yet valid.
      || after_status < 0)  // Certificate is expired.
    return 0;

  return 1;
}

CORBA::Boolean
TAO_SSLIOP_Credentials::refresh (const CORBA::Any & /* refresh_data */
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Until it is clear the code below is correct, throw a
  // CORBA::NO_IMPLEMENT exception.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);

  // @@ I "if zeroed" out the following code since I'm not sure if the
  //    code below is correct, or if it possible to to refresh the
  //    X.509 certificates for the given SSL session by renegotiating
  //    the that session.

#if 0
  // @@ What about the private key?  Do we need to refresh it as well?

  SSLIOP::ASN_1_Cert *der_cert = 0;
  char *cert_filename = 0;

  // Attempt to extract a certificate in DER format from the Any.
  if (refresh_data >>= der_cert)
    {
      if (::SSL_use_certificate_ASN1 (this->ssl_,
                                      der_cert->get_buffer (),
                                      der_cert->length ()) <= 0)
        {
          if (TAO_debug_level > 0)
            ACE_ERROR ((LM_ERROR,
                        "(%P|%t) ERROR: Unable to refresh SSLIOP "
                        "credentials using certificate in ASN.1 "
                        "format.\n"));

          ACE_THROW_RETURN (CORBA::BAD_OPERATION (), 0);
        }
    }

  // Attempt to extract a filename that contains the certificate from
  // the Any.
  else if (refresh_data >>= cert_filename)
    {
      // @@ Should we do this sort of thing, i.e. first try to open a
      //    PEM file, and then an ASN.1 file?

      // Try extracting a PEM formatted certificate from the given
      // file.
      if (::SSL_use_certificate_file (this->ssl_,
                                      cert_filename,
                                      SSL_FILETYPE_PEM) <= 0)
        {
          if (TAO_debug_level > 0)
            ACE_DEBUG ((LM_WARNING,
                        "(%P|%t) WARNING: Unable to refresh SSLIOP "
                        "credentials using PEM certificate in file \"%s\"\n",
                        cert_filename));
        }

      // Try extracted an ASN.1 formatted certificate from the given
      // file.
      else if (::SSL_use_certificate_file (this->ssl_,
                                           cert_filename,
                                           SSL_FILETYPE_ASN1) <= 0)
        {
          if (TAO_debug_level > 0)
            ACE_DEBUG ((LM_WARNING,
                        "(%P|%t) WARNING: Unable to refresh SSLIOP "
                        "credentials using ASN.1 certificate in file \"%s\"\n",
                        cert_filename));
        }

      else
        ACE_THROW_RETURN (CORBA::BAD_OPERATION (), 0);
    }
  else
    ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);

  // Renegotiate the SSL session to force the new settings to be used.
  if (::SSL_renegotiate (this->ssl_) <= 0)
    ACE_THROW_RETURN (CORBA::BAD_OPERATION (), 0);

  return 1;
#endif  /* 0 */
}

CORBA::Boolean
TAO_SSLIOP_Credentials::operator== (const TAO_SSLIOP_Credentials &rhs)
{
  X509 *xa = this->x509_.in ();
  X509 *xb = rhs.x509_.in ();
  // EVP_PKEY *ea = this->evp_.in ();
  // EVP_PKEY *eb = rhs.evp_.in ();

  return
    this->accepting_options_supported_ == rhs.accepting_options_supported_
    && this->accepting_options_required_ == rhs.accepting_options_required_
    && this->invocation_options_supported_ == rhs.invocation_options_supported_
    && this->invocation_options_required_ == rhs.invocation_options_required_
    && ((xa == xb) || (xa != 0 && xb != 0 && ::X509_cmp (xa, xb) == 0))
    // && ((ea == eb) || (ea != 0 && eb != 0 && ::EVP_PKEY_cmp (ea, eb) == 0))
    ;
}

CORBA::ULong
TAO_SSLIOP_Credentials::hash (void) const
{
  X509 *x509 = this->x509_.in ();

  return (x509 == 0 ? 0 : ::X509_issuer_name_hash (x509));
}

TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials::_narrow (CORBA::Object_ptr obj
                                 ACE_ENV_ARG_DECL)
{
  return TAO_SSLIOP_Credentials::_unchecked_narrow (obj
                                                    ACE_ENV_ARG_PARAMETER);
}

TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials::_unchecked_narrow (CORBA::Object_ptr obj
                                           ACE_ENV_ARG_DECL_NOT_USED)
{
  if (CORBA::is_nil (obj))
    return TAO_SSLIOP_Credentials::_nil ();
  return
        ACE_reinterpret_cast
          (
            TAO_SSLIOP_Credentials_ptr,
              obj->_tao_QueryInterface
                (
                  ACE_reinterpret_cast
                    (
                      ptrdiff_t,
                      &TAO_SSLIOP_Credentials::_tao_class_id
                    )
                )
          );
}

TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials::_duplicate (TAO_SSLIOP_Credentials_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();

  return obj;
}

void *
TAO_SSLIOP_Credentials::_tao_QueryInterface (ptrdiff_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptrdiff_t,
      &TAO_SSLIOP_Credentials::_tao_class_id))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast
    (ptrdiff_t,
      &::SecurityLevel2::Credentials::_tao_class_id))
    retv = ACE_reinterpret_cast
      (
        void *,
        ACE_static_cast
          (
            SecurityLevel2::Credentials_ptr,
            this
          )
      );
  else if (type == ACE_reinterpret_cast (ptrdiff_t, &CORBA::Object::_tao_class_id))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

// -----------------------------------------------------------

int TAO_SSLIOP_Credentials::_tao_class_id = 0;

TAO_SSLIOP_Credentials_ptr
tao_TAO_SSLIOP_Credentials_duplicate (
    TAO_SSLIOP_Credentials_ptr p
  )
{
  return TAO_SSLIOP_Credentials::_duplicate (p);
}

void
tao_TAO_SSLIOP_Credentials_release (
    TAO_SSLIOP_Credentials_ptr p
  )
{
  CORBA::release (p);
}

TAO_SSLIOP_Credentials_ptr
tao_TAO_SSLIOP_Credentials_nil (
    void
  )
{
  return TAO_SSLIOP_Credentials::_nil ();
}

TAO_SSLIOP_Credentials_ptr
tao_TAO_SSLIOP_Credentials_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return TAO_SSLIOP_Credentials::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
tao_TAO_SSLIOP_Credentials_upcast (
    void *src
  )
{
  TAO_SSLIOP_Credentials **tmp =
    ACE_static_cast (TAO_SSLIOP_Credentials **, src);
  return *tmp;
}

// *************************************************************
// Operations for class TAO_SSLIOP_Credentials_var
// *************************************************************

TAO_SSLIOP_Credentials_var::TAO_SSLIOP_Credentials_var (void) // default constructor
  : ptr_ (TAO_SSLIOP_Credentials::_nil ())
{}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_var::ptr (void) const
{
  return this->ptr_;
}

TAO_SSLIOP_Credentials_var::TAO_SSLIOP_Credentials_var (const ::TAO_SSLIOP_Credentials_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (TAO_SSLIOP_Credentials::_duplicate (p.ptr ()))
{}

TAO_SSLIOP_Credentials_var::~TAO_SSLIOP_Credentials_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

TAO_SSLIOP_Credentials_var &
TAO_SSLIOP_Credentials_var::operator= (TAO_SSLIOP_Credentials_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

TAO_SSLIOP_Credentials_var &
TAO_SSLIOP_Credentials_var::operator= (const ::TAO_SSLIOP_Credentials_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::TAO_SSLIOP_Credentials::_duplicate (p.ptr ());
  }
  return *this;
}

TAO_SSLIOP_Credentials_var::operator const ::TAO_SSLIOP_Credentials_ptr &() const // cast
{
  return this->ptr_;
}

TAO_SSLIOP_Credentials_var::operator ::TAO_SSLIOP_Credentials_ptr &() // cast
{
  return this->ptr_;
}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_var::operator-> (void) const
{
  return this->ptr_;
}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_var::in (void) const
{
  return this->ptr_;
}

::TAO_SSLIOP_Credentials_ptr &
TAO_SSLIOP_Credentials_var::inout (void)
{
  return this->ptr_;
}

::TAO_SSLIOP_Credentials_ptr &
TAO_SSLIOP_Credentials_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO_SSLIOP_Credentials::_nil ();
  return this->ptr_;
}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::TAO_SSLIOP_Credentials_ptr val = this->ptr_;
  this->ptr_ = ::TAO_SSLIOP_Credentials::_nil ();
  return val;
}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_var::tao_duplicate (TAO_SSLIOP_Credentials_ptr p)
{
  return ::TAO_SSLIOP_Credentials::_duplicate (p);
}

void
TAO_SSLIOP_Credentials_var::tao_release (TAO_SSLIOP_Credentials_ptr p)
{
  CORBA::release (p);
}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_var::tao_nil (void)
{
  return ::TAO_SSLIOP_Credentials::_nil ();
}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_var::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return ::TAO_SSLIOP_Credentials::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
TAO_SSLIOP_Credentials_var::tao_upcast (void *src)
{
  TAO_SSLIOP_Credentials **tmp =
    ACE_static_cast (TAO_SSLIOP_Credentials **, src);
  return *tmp;
}

// *************************************************************
// Operations for class TAO_SSLIOP_Credentials_out
// *************************************************************

TAO_SSLIOP_Credentials_out::TAO_SSLIOP_Credentials_out (TAO_SSLIOP_Credentials_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::TAO_SSLIOP_Credentials::_nil ();
}

TAO_SSLIOP_Credentials_out::TAO_SSLIOP_Credentials_out (TAO_SSLIOP_Credentials_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO_SSLIOP_Credentials::_nil ();
}

TAO_SSLIOP_Credentials_out::TAO_SSLIOP_Credentials_out (const ::TAO_SSLIOP_Credentials_out &p) // copy constructor
  : ptr_ (ACE_const_cast (TAO_SSLIOP_Credentials_out &, p).ptr_)
{}

::TAO_SSLIOP_Credentials_out &
TAO_SSLIOP_Credentials_out::operator= (const ::TAO_SSLIOP_Credentials_out &p)
{
  this->ptr_ = ACE_const_cast (TAO_SSLIOP_Credentials_out&, p).ptr_;
  return *this;
}

TAO_SSLIOP_Credentials_out &
TAO_SSLIOP_Credentials_out::operator= (const ::TAO_SSLIOP_Credentials_var &p)
{
  this->ptr_ = ::TAO_SSLIOP_Credentials::_duplicate (p.ptr ());
  return *this;
}

TAO_SSLIOP_Credentials_out &
TAO_SSLIOP_Credentials_out::operator= (TAO_SSLIOP_Credentials_ptr p)
{
  this->ptr_ = p;
  return *this;
}

TAO_SSLIOP_Credentials_out::operator ::TAO_SSLIOP_Credentials_ptr &() // cast
{
  return this->ptr_;
}

::TAO_SSLIOP_Credentials_ptr &
TAO_SSLIOP_Credentials_out::ptr (void) // ptr
{
  return this->ptr_;
}

::TAO_SSLIOP_Credentials_ptr
TAO_SSLIOP_Credentials_out::operator-> (void)
{
  return this->ptr_;
}
