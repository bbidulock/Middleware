// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_IMPLREPOS_T_H_
#define _TAO_IDL_ORIG_IMPLREPOS_T_H_

#include "ace/pre.h"
#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (ACE_HAS_USING_KEYWORD)
TAO_NAMESPACE  POA_ImplementationRepository
{
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_PortableServer_Export ServerObject_tie : public ServerObject
  {
  public:
    ServerObject_tie (T &t);
    // the T& ctor
    ServerObject_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    ServerObject_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    ServerObject_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~ServerObject_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    void ping (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

        void shutdown (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

      private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    ServerObject_tie (const ServerObject_tie &);
    void operator= (const ServerObject_tie &);
  };

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_PortableServer_Export Administration_tie : public Administration
  {
  public:
    Administration_tie (T &t);
    // the T& ctor
    Administration_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    Administration_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    Administration_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~Administration_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    void activate_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ImplementationRepository::Administration::NotFound,
        ImplementationRepository::Administration::CannotActivate
      ));

        void register_server (
        const char * server,
        const ImplementationRepository::StartupOptions & options
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ImplementationRepository::Administration::AlreadyRegistered
      ));

        void reregister_server (
        const char * server,
        const ImplementationRepository::StartupOptions & options
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

        void remove_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ImplementationRepository::Administration::NotFound
      ));

        void shutdown_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ImplementationRepository::Administration::NotFound
      ));

        char * server_is_running (
        const char * server,
        const char * addr,
        ImplementationRepository::ServerObject_ptr server_object
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ImplementationRepository::Administration::NotFound
      ));

        void server_is_shutting_down (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ImplementationRepository::Administration::NotFound
      ));

        void find (
        const char * server,
        ImplementationRepository::ServerInformation_out info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ImplementationRepository::Administration::NotFound
      ));

        void list (
        CORBA::ULong how_many,
        ImplementationRepository::ServerInformationList_out server_list,
        ImplementationRepository::ServerInformationIterator_out server_iterator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

      private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    Administration_tie (const Administration_tie &);
    void operator= (const Administration_tie &);
  };

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_PortableServer_Export ServerInformationIterator_tie : public ServerInformationIterator
  {
  public:
    ServerInformationIterator_tie (T &t);
    // the T& ctor
    ServerInformationIterator_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    ServerInformationIterator_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    ServerInformationIterator_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~ServerInformationIterator_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    CORBA::Boolean next_n (
        CORBA::ULong how_many,
        ImplementationRepository::ServerInformationList_out server_list
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

        void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

      private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    ServerInformationIterator_tie (const ServerInformationIterator_tie &);
    void operator= (const ServerInformationIterator_tie &);
  };

}
TAO_NAMESPACE_CLOSE // module ImplementationRepository
#endif /* ACE_HAS_USING_KEYWORD */

#if defined (__ACE_INLINE__)
#include "ImplRepoS_T.i"
#endif /* defined INLINE */


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ImplRepoS_T.cpp"
#endif /* defined REQUIRED SOURCE */


#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("ImplRepoS_T.cpp")
#endif /* defined REQUIRED PRAGMA */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* ifndef */
