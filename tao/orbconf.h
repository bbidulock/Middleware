// This may look like C, but it's really -*- C++ -*-
// @ (#) $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     default_server.h
//
// = DESCRIPTION
//     Build configuration file for the Inter-ORB Engine, and application
//     level code using it via <corba.hh>
//
// = AUTHOR
//     Copyright 1995 by Sun Microsystems, Inc.
//
//     TAO-specific changes by Chris Cleeland and Douglas C. Schmidt
//
// ============================================================================

#ifndef TAO_ORB_CONFIG_H
#define TAO_ORB_CONFIG_H

#include "ace/OS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (TAO_REACTOR)
#define TAO_REACTOR ACE_Select_Reactor
#endif /* TAO_REACTOR */

#if !defined (TAO_NULL_LOCK_REACTOR)
#define TAO_NULL_LOCK_REACTOR ACE_Select_Reactor_T< ACE_Select_Reactor_Token_T<ACE_Noop_Token> >
#endif /* TAO_NULL_LOCK_REACTOR */

// Users should override this stuff if they don't want to use the
// default ACE Socket wrappers.  This makes it possible to change
// TAO's transport mechanism wholesale by making a few minor changes
// to the ACE config.h file.
#if !defined (TAO_SOCK_STREAM)
#define TAO_SOCK_STREAM ACE_SOCK_STREAM
#define TAO_SOCK_Stream ACE_SOCK_Stream
#endif /* TAO_SOCK_STREAM */

#if !defined (TAO_SOCK_ACCEPTOR)
#define TAO_SOCK_ACCEPTOR ACE_SOCK_ACCEPTOR
#endif /* TAO_SOCK_ACCEPTOR */

#if !defined (TAO_LSOCK_ACCEPTOR)
#define TAO_LSOCK_ACCEPTOR ACE_LSOCK_ACCEPTOR
#endif /* TAO_SOCK_ACCEPTOR */

#if !defined (TAO_SOCK_CONNECTOR)
#define TAO_SOCK_CONNECTOR ACE_SOCK_CONNECTOR
#endif /* TAO_SOCK_CONNECTOR */

#if !defined (TAO_LSOCK_CONNECTOR)
#define TAO_LSOCK_CONNECTOR ACE_LSOCK_CONNECTOR
#endif /* TAO_SOCK_CONNECTOR */

//#define POA_NO_TIMESTAMP
//
// Define this if you don't want POA timestamps in the IOR.  Remember,
// without timestamps, transient and persistent POA cannot be
// distinguished

//#define TAO_USE_DOTTED_DECIMAL_ADDRESSES
//
// If set the ORB will use dotted decimal addresses in the IORs it
// exports, this is useful for platforms or environments that cannot
// depend on a DNS beign available.

// The default arguments of the resource factory for the fake service
// configurator
#if !defined (TAO_DEFAULT_RESOURCE_FACTORY_ARGS)
#define TAO_DEFAULT_RESOURCE_FACTORY_ARGS "static Resource_Factory \"-ORBresources tss -ORBreactorlock null\""
#endif /* TAO_DEFAULT_RESOURCE_FACTORY_ARGS */

// The default arguments of the client strategy factory for the fake service
// configurator
#if !defined (TAO_DEFAULT_CLIENT_STRATEGY_FACTORY_ARGS)
#define TAO_DEFAULT_CLIENT_STRATEGY_FACTORY_ARGS "static Client_Strategy_Factory \"\""
#endif /* TAO_DEFAULT_CLIENT_STRATEGY_FACTORY_ARGS */

// The default arguments of the server strategy factory for the fake service
// configurator
#if !defined (TAO_DEFAULT_SERVER_STRATEGY_FACTORY_ARGS)
#define TAO_DEFAULT_SERVER_STRATEGY_FACTORY_ARGS  "static Server_Strategy_Factory \"-ORBconcurrency reactive -ORBsystemidpolicydemuxstrategy dynamic -ORBtablesize 128\""
#endif /* TAO_DEFAULT_SERVER_STRATEGY_FACTORY_ARGS */

// The default size of TAO's server active object map.
#if !defined (TAO_DEFAULT_SERVER_ACTIVE_OBJECT_MAP_SIZE)
# if defined (TAO_DEFAULT_SERVER_OBJECT_TABLE_SIZE)
//
// TAO_DEFAULT_SERVER_OBJECT_TABLE_SIZE is deprecated. Please use
// TAO_DEFAULT_SERVER_ACTIVE_OBJECT_MAP_SIZE.
//
#  define TAO_DEFAULT_SERVER_ACTIVE_OBJECT_MAP_SIZE TAO_DEFAULT_SERVER_OBJECT_TABLE_SIZE
# else
#  define TAO_DEFAULT_SERVER_ACTIVE_OBJECT_MAP_SIZE 64
# endif /* TAO_DEFAULT_SERVER_OBJECT_TABLE_SIZE */
#endif /* ! TAO_DEFAULT_SERVER_ACTIVE_OBJECT_MAP_SIZE */

// The default size of TAO's server poa map.
#if !defined (TAO_DEFAULT_SERVER_POA_MAP_SIZE)
#  define TAO_DEFAULT_SERVER_POA_MAP_SIZE 24
#endif /* ! TAO_DEFAULT_SERVER_POA_MAP_SIZE */

// The default UDP multicast port number for locating the TAO Naming
// Service.
#if !defined (TAO_DEFAULT_NAME_SERVER_REQUEST_PORT)
#define TAO_DEFAULT_NAME_SERVER_REQUEST_PORT 10013
#endif /* TAO_DEFAULT_NAME_SERVER_REQUEST_PORT */

// The default UDP port number for replying to a location request to
// the TAO Naming Service.
#if !defined (TAO_DEFAULT_NAME_SERVER_REPLY_PORT)
#define TAO_DEFAULT_NAME_SERVER_REPLY_PORT 10014
#endif /* TAO_DEFAULT_NAME_SERVER_REPLY_PORT */

// The default UDP multicast port number for locating the TAO Trading
// Service.
#if !defined (TAO_DEFAULT_TRADING_SERVER_REQUEST_PORT)
#define TAO_DEFAULT_TRADING_SERVER_REQUEST_PORT 10016
#endif /* TAO_DEFAULT_TRADING_SERVER_REQUEST_PORT */

// The default UDP port number for replying to a location request to
// the TAO Trading Service.
#if !defined (TAO_DEFAULT_TRADING_SERVER_REPLY_PORT)
#define TAO_DEFAULT_TRADING_SERVER_REPLY_PORT 10017
#endif /* TAO_DEFAULT_TRADING_SERVER_REPLY_PORT */

// The default UDP multicast port number for locating the TAO
// Implementation Repository Service.
#if !defined (TAO_DEFAULT_IMPLREPO_SERVER_REQUEST_PORT)
#define TAO_DEFAULT_IMPLREPO_SERVER_REQUEST_PORT 10018
#endif /* TAO_DEFAULT_IMPLREPO_SERVER_REQUEST_PORT */

// The default UDP port number for replying to a location request to
// the TAO Implementation Repository Service.
#if !defined (TAO_DEFAULT_IMPLREPO_SERVER_REPLY_PORT)
#define TAO_DEFAULT_IMPLREPO_SERVER_REPLY_PORT 10019
#endif /* TAO_DEFAULT_IMPLREPO_SERVER_REPLY_PORT */


// The default timeout receiving the location request to the TAO
// Naming, Trading and other servicesService.
#if !defined (TAO_DEFAULT_SERVICE_RESOLUTION_TIMEOUT)
#define TAO_DEFAULT_SERVICE_RESOLUTION_TIMEOUT 4
#endif /* TAO_DEFAULT_SERVICE_RESOLUTION_TIMEOUT */

// The default starting port number for TAO servers.
// @@ This assumes we are using one or more protocols that will all
// @@ 1) know what to do with a port number and
// @@ 2) use the same default port number.
// @@ This shou8ld go away!
#if !defined (TAO_DEFAULT_SERVER_PORT)
#define TAO_DEFAULT_SERVER_PORT 0
#endif /* TAO_DEFAULT_SERVER_PORT */

// TAO's max buffer size
#if !defined (TAO_MAXBUFSIZE)
#define TAO_MAXBUFSIZE 1024
#endif /* TAO_MAXBUFSIZE */

// This controls the alignment for TAO structs.  It supports built-in
// types up to and including 16 bytes (128 bits) in size.
#if !defined (TAO_MAXIMUM_NATIVE_TYPE_SIZE)
# define TAO_MAXIMUM_NATIVE_TYPE_SIZE 128
#endif /* TAO_MAXIMUM_NATIVE_TYPE_SIZE */

// This deals with platforms that support namespaces vs platforms that
// don't.  @@ MSVC's namespace implementation is somehow broken.
// The following macros are required to deal with the most bizarre and insane
// behavior of the MSVC++ compiler
#if defined (ACE_HAS_USING_KEYWORD)
#define TAO_NAMESPACE namespace
#define TAO_NAMESPACE_STORAGE_CLASS extern TAO_EXPORT_MACRO
#define TAO_NAMESPACE_BEGIN(NS)  namespace NS {
#define TAO_NAMESPACE_END  };
#define TAO_NAMESPACE_TYPE(TYPE)
#define TAO_NAMESPACE_DEFINE(TYPE,NAME,RHS) TYPE NAME = RHS;
#else
#define TAO_NAMESPACE struct TAO_EXPORT_MACRO
#define TAO_NAMESPACE_STORAGE_CLASS static
#define TAO_NAMESPACE_BEGIN(NS)  NS##::
#define TAO_NAMESPACE_END
#define TAO_NAMESPACE_TYPE(TYPE) TYPE
#define TAO_NAMESPACE_DEFINE(TYPE,NAME,RHS) NAME = RHS;
#endif /* ACE_HAS_USING_KEYWORD */

# if defined (_MSC_VER) && defined (__ACE_INLINE__)
#   define TAO_NAMESPACE_INLINE_FUNCTION inline
# else
#   define TAO_NAMESPACE_INLINE_FUNCTION TAO_NAMESPACE_STORAGE_CLASS
# endif

// Instead of replacing this with the ACE macro
// in 20+ files, define it conditionally.
// The TAO_OutputCDR class uses the ACE macro, which
// is defined by default.
//#if defined (ACE_NO_COPY_OCTET_SEQUENCES)
#define TAO_NO_COPY_OCTET_SEQUENCES
//#endif /* ACE_NO_COPY_OCTET_SEQUENCES */

#if defined (ACE_HAS_EXCEPTIONS)
# define TAO_HAS_EXCEPTIONS
// TAO_USE_EXCEPTIONS is only here for backwards compatibility and
// will go away shortly so don't use it...
# define TAO_USE_EXCEPTIONS
#elif (defined (TAO_HAS_EXCEPTIONS) || defined (TAO_USE_EXCEPTIONS)) && !defined (ACE_HAS_EXCEPTIONS)
# error "tao/orbconf.h: You can only use exceptions in TAO if ACE supports them"
#endif /* TAO_HAS_EXCEPTIONS */

// BC++ seems to have a different convention for detecting Win32 than
// VC++.

#if defined (__WIN32__)
# if !defined(_WIN32)
#   define _WIN32
# endif /* !defined(_WIN32) */
#endif /* __WIN32__ */

// Define to `int' if <sys/types.h> doesn't define.
/* #undef pid_t */

// Define if your processor does not store words with the most significant
// byte first.
#if defined (ACE_LITTLE_ENDIAN)
#  define TAO_ENCAP_BYTE_ORDER 1  /* little endian encapsulation byte order has
                                     the value = 1 */
#else  /* ! ACE_LITTLE_ENDIAN */
#  define TAO_ENCAP_BYTE_ORDER 0  /* big endian encapsulation byte order has
                                     the value = 0 */
#endif /* ! ACE_LITTLE_ENDIAN */

// Define as the return type of signal handlers (int or void).
#define RETSIGTYPE void

// Define if you don't have vprintf but do have _doprnt.
/* #undef HAVE_DOPRNT */

// Define if you have the vprintf function.
#define HAVE_VPRINTF 1

// Avoid namespace pollution that's common on older UNIXes...
#if defined (minor)
#undef minor
#endif /* minor */

#if defined (major)
#undef major
#endif /* major*/

#if !defined (TAO_EXPORT_NESTED_CLASSES) \
    && defined (ACE_EXPORT_NESTED_CLASSES)
#define TAO_EXPORT_NESTED_CLASSES
#endif /* !defined TAO_EXPORT_NESTED_CLASSES */

#if !defined (TAO_EXPORT_NESTED_MACRO)
#define TAO_EXPORT_NESTED_MACRO
#endif /* !defined (TAO_EXPORT_NESTED_MACRO) */

// Assume DOS/Windows if "configure" didn't get run.

#if defined (_WIN32)
// "C4355: 'this' : used in base member initializer list"
#  pragma warning (disable:4355) /* disable C4355 warning */
#endif /* defined (_WIN32) */

// The IDL compiler can generate the classes corresponding to IDL
// sequences in two ways:
// + Use the TAO templates for sequences,
//   i.e. TAO_{Unb,B}ounded_Sequence<>
// + Explicitly generate code for the sequence.
//
// The first approach can (potentially) produce smaller code, because
// the code for a sequence over a particular type (say sequence<long>)
// can be shared across multiple IDL files.
// Unfortunately it is hard to manage the template instantiations on
// platforms that do not automatically generate them, mainly because
// it is hard to decide on which generated file are the templates
// instantiated.  Thus the second approach is more convenient for most
// applications.
//
// On platforms that support automatic template instantiation we use
// the first approach.
// On platforms that require explicit template instantiations we use
// explicitly generated code for sequences if the platform does not.
// If the application requires it (such as embedded systems) the
// default can be changed, but then the application developer is
// responsible for instantiating the templates.
//
#if !defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) && \
    (defined (ACE_HAS_TEMPLATE_SPECIALIZATION) || \
     (defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA) && defined (_UNICOS)))
#define TAO_USE_SEQUENCE_TEMPLATES
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// ObjectIds recognized by CORBA_ORB::resolve_initial_references ()...
// of course, no guarantees are made that the call will return
// something useful.
#define TAO_OBJID_NAMESERVICE      "NameService"
#define TAO_OBJID_TRADINGSERVICE   "TradingService"
#define TAO_OBJID_IMPLREPOSERVICE  "ImplRepoService"
#define TAO_OBJID_ROOTPOA          "RootPOA"
#define TAO_OBJID_POACURRENT       "POACurrent"
#define TAO_OBJID_INTERFACEREP     "InterfaceRepository"
#define TAO_OBJID_POLICYMANAGER    "ORBPolicyManager"
#define TAO_OBJID_POLICYCURRENT    "PolicyCurrent"
#define TAO_OBJID_IORMANIPULATION  "IORManipulation"

// TAO Naming Service.

// Poa id of the root Naming Context in a Naming server.
#if !defined (TAO_ROOT_NAMING_CONTEXT)
#  define TAO_ROOT_NAMING_CONTEXT "NameService"
#endif /* ! TAO_ROOT_NAMING_CONTEXT */

// The name under which the index of naming contexts is stored in
// persistent naming service.
#if !defined (TAO_NAMING_CONTEXT_INDEX)
#  define TAO_NAMING_CONTEXT_INDEX "Naming_Context_Index"
#endif /* ! TAO_NAMING_CONTEXT_INDEX */

// The Root POA default name.
#define TAO_DEFAULT_ROOTPOA_NAME   ""

// OBV is in experimental stage
#define TAO_HAS_VALUETYPE

// Minimum CORBA
// #define TAO_HAS_MINIMUM_CORBA

// Without Minimum CORBA, the user will get regular (no locality
// constraints) policies by default.  With Minimum CORBA, the user
// will get locality constraint policies by default.
//
// If #define TAO_HAS_REMOTE_POLICIES 0, then the user will always get
// locality constraint policies (regardless of Minimum CORBA).
//
// If #define TAO_HAS_REMOTE_POLICIES 1, then the user will always get
// regular policies (regardless of Minimum CORBA).

// TAO_HAS_LOCALITY_CONSTRAINT_POLICIES is an internal macro and
// should not be set by the user.
#if defined (TAO_HAS_LOCALITY_CONSTRAINT_POLICIES)
# undef TAO_HAS_LOCALITY_CONSTRAINT_POLICIES
# warning TAO_HAS_LOCALITY_CONSTRAINT_POLICIES is an internal macro \
and should not be set by the user. Please use TAO_HAS_REMOTE_POLICIES instead.
#endif /* TAO_HAS_LOCALITY_CONSTRAINT_POLICIES */

#if defined (TAO_HAS_MINIMUM_CORBA)

// With minimum CORBA, we don't have the ForwardRequest exception.
// Therefore, we can't support the INS forwarding agent.
# if !defined (TAO_NO_IOR_TABLE)
#  define TAO_NO_IOR_TABLE
# endif /* TAO_NO_IOR_TABLE */

# if !defined (TAO_HAS_REMOTE_POLICIES)
#  define TAO_HAS_REMOTE_POLICIES 0
# endif /* TAO_HAS_REMOTE_POLICIES */

#endif /* TAO_HAS_MINIMUM_CORBA */

// Policies are not locality constraint by default.
#if !defined (TAO_HAS_REMOTE_POLICIES)
# define TAO_HAS_REMOTE_POLICIES 1
#endif /* TAO_HAS_REMOTE_POLICIES */

#if (TAO_HAS_REMOTE_POLICIES == 0)
# define TAO_HAS_LOCALITY_CONSTRAINT_POLICIES
#endif /* TAO_HAS_REMOTE_POLICIES */

// CORBA Messaging
#define TAO_HAS_CORBA_MESSAGING

// Define the policy types as literals, so they can be used in switch
// statements
#define TAO_MESSAGING_REBIND_POLICY_TYPE 23
#define TAO_MESSAGING_SYNC_SCOPE_POLICY_TYPE 24
#define TAO_MESSAGING_REQUEST_PRIORITY_POLICY_TYPE 25
#define TAO_MESSAGING_REPLY_PRIORITY_POLICY_TYPE 26
#define TAO_MESSAGING_REQUEST_START_TIME_POLICY_TYPE 27
#define TAO_MESSAGING_REQUEST_END_TIME_POLICY_TYPE 28
#define TAO_MESSAGING_REPLY_START_TIME_POLICY_TYPE 29
#define TAO_MESSAGING_REPLY_END_TIME_POLICY_TYPE 30
#define TAO_MESSAGING_RELATIVE_REQ_TIMEOUT_POLICY_TYPE 31
#define TAO_MESSAGING_RELATIVE_RT_TIMEOUT_POLICY_TYPE 32
#define TAO_MESSAGING_ROUTING_POLICY_TYPE 33
#define TAO_MESSAGING_MAX_HOPS_POLICY_TYPE 34
#define TAO_MESSAGING_QUEUE_ORDER_POLICY_TYPE 35

// Control the default version of GIOP used by TAO.
// The ORB is always able to communicate with 1.0 and 1.1 servers, and
// it creates 1.1 endpoints (and profiles).  If you need to talk to
// old clients that only understand 1.0 (and do not attempt to use 1.0
// with 1.1 servers), then change the values below.
#if !defined (TAO_DEF_GIOP_MAJOR)
#define TAO_DEF_GIOP_MAJOR 1
#endif /* TAO_DEF_GIOP_MAJOR */
#if !defined (TAO_DEF_GIOP_MINOR)
#define TAO_DEF_GIOP_MINOR 1
#endif /* TAO_DEF_GIOP_MINOR */

// By default TAO generate the OMG standard profile components
// (ORB_TYPE and CODE_SETS)
#define TAO_STD_PROFILE_COMPONENTS

#if !defined (TAO_DEFAULT_IOR_SIZE)
// This is the default size of the buffer used for processing IORs.
#define TAO_DEFAULT_IOR_SIZE 1024
#endif /* TAO_DEFAULT_IOR_SIZE */

#endif  /* TAO_ORB_CONFIG_H */
