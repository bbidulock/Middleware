// ============================================================================
//
// = LIBRARY
//    CORBA Marshal Orbix Benchmark
// 
// = FILENAME
//    orbix_marshal_server.h
//
// = AUTHOR
//    Aniruddha Gokhale
// 
// ============================================================================

#if !defined(_ORBIX_MARSHAL_SERVER_H_)
#define _ORBIX_MARSHAL_SERVER_H_

// benchmark library includes
#include "benchmark/marshal_options.h"
#include "benchmark/marshal_results.h"
#include "benchmark/marshal_proxy.h"

// implementation classes
#include "orbix_marshal_impl.h"

// include Orbix specific include files
#include "marshal.h"  // generated by IDL compiler

class Orbix_Marshal_Server_Proxy : public CORBA_Marshal_Proxy
{
public:
  Orbix_Marshal_Server_Proxy (void);
  // constructor

  ~Orbix_Marshal_Server_Proxy (void);
  // destructor

  virtual int run (CORBA_Marshal_Proxy::OPTIONS &options,
		   CORBA_Marshal_Proxy::RESULTS &results);
  // do the actual work
private:
  CORBA::ORB_ptr orb_;
  // underlying orb;

  CORBA::BOA_ptr boa_;
  // underlying boa;

  Marshal_SSI_Impl *ssi_;
  Marshal_DSI_Impl *dsi_;
  // the implementation (SSI or DSI)
};


#if defined (__ACE_INLINE__)
#include "orbix_marshal_server.i"
#endif /* __ACE_INLINE__ */

#endif
