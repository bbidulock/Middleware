// ============================================================================
//
// = LIBRARY
//    CORBA Marshal Tao Benchmark
// 
// = FILENAME
//    tao_marshal_client.h
//
// = AUTHOR
//    Aniruddha Gokhale
// 
// ============================================================================

#if !defined(_TAO_MARSHAL_CLIENT_H_)
#define _TAO_MARSHAL_CLIENT_H_

// benchmark library includes
#include "benchmark/marshal_options.h"
#include "benchmark/marshal_results.h"
#include "benchmark/marshal_proxy.h"

// include Tao specific include files
#include "marshalC.h"  // generated by IDL compiler
#include "tao/nvlist.h"

class Tao_Marshal_Client_Proxy : public CORBA_Marshal_Proxy
{
  // =TITLE
  //  Tao_Marshal_Client_Proxy
  // =DESCRIPTION
  //  Tao client size specialization of the CORBA Marshal proxy class
public:
  Tao_Marshal_Client_Proxy (void);
  // constructor

  ~Tao_Marshal_Client_Proxy (void);
  // destructor

  virtual int run (CORBA_Marshal_Proxy::OPTIONS &options,
		   CORBA_Marshal_Proxy::RESULTS &results);
  // do the actual work

  virtual int use_sii (CORBA_Marshal_Proxy::OPTIONS &options,
		       CORBA_Marshal_Proxy::RESULTS &results);
  // use the static invocation interface

  virtual int use_dii (CORBA_Marshal_Proxy::OPTIONS &options,
		       CORBA_Marshal_Proxy::RESULTS &results);
  // use the dynamic invocation interface
private:
  // =helper functions
  int sii_test_short (CORBA_Marshal_Proxy::OPTIONS &options,
		      CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_long (CORBA_Marshal_Proxy::OPTIONS &options,
		     CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_octet (CORBA_Marshal_Proxy::OPTIONS &options,
		      CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_char (CORBA_Marshal_Proxy::OPTIONS &options,
		     CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_double (CORBA_Marshal_Proxy::OPTIONS &options,
		       CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_struct (CORBA_Marshal_Proxy::OPTIONS &options,
		       CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_union (CORBA_Marshal_Proxy::OPTIONS &options,
		      CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_any (CORBA_Marshal_Proxy::OPTIONS &options,
		    CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_sequence (CORBA_Marshal_Proxy::OPTIONS &options,
			 CORBA_Marshal_Proxy::RESULTS &results);

  int sii_test_recursive (CORBA_Marshal_Proxy::OPTIONS &options,
			  CORBA_Marshal_Proxy::RESULTS &results);

  // all the DII helpers
  int dii_test_short (CORBA_Marshal_Proxy::OPTIONS &options,
		      CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_long (CORBA_Marshal_Proxy::OPTIONS &options,
		     CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_octet (CORBA_Marshal_Proxy::OPTIONS &options,
		      CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_char (CORBA_Marshal_Proxy::OPTIONS &options,
		     CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_double (CORBA_Marshal_Proxy::OPTIONS &options,
		       CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_struct (CORBA_Marshal_Proxy::OPTIONS &options,
		       CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_union (CORBA_Marshal_Proxy::OPTIONS &options,
		      CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_any (CORBA_Marshal_Proxy::OPTIONS &options,
		    CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_sequence (CORBA_Marshal_Proxy::OPTIONS &options,
			 CORBA_Marshal_Proxy::RESULTS &results);

  int dii_test_recursive (CORBA_Marshal_Proxy::OPTIONS &options,
			  CORBA_Marshal_Proxy::RESULTS &results);

  CORBA_ORB_ptr orb_;
  // handle to the underlying orb

  Marshal_ptr ref_;
  // the object reference
};

#if defined (__ACE_INLINE__)
#include "tao_marshal_client.i"
#endif /* __ACE_INLINE__ */

#endif
