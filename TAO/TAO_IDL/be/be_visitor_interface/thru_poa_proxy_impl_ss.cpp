#include        "idl.h"
#include        "idl_extern.h"
#include        "be.h"

#include "be_visitor_interface.h"

ACE_RCSID (be_visitor_interface, thru_poa_proxy_broker_impl_ss, "$Id$")

be_visitor_interface_thru_poa_proxy_impl_ss::be_visitor_interface_thru_poa_proxy_impl_ss (be_visitor_context *ctx)
  : be_visitor_interface (ctx)
{
  // No-Op.
}


be_visitor_interface_thru_poa_proxy_impl_ss::~be_visitor_interface_thru_poa_proxy_impl_ss (void)
{
  // No-Op.
}

int
be_visitor_interface_thru_poa_proxy_impl_ss::visit_interface (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  os->indent ();
  *os << be_nl
      << "///////////////////////////////////////////////////////////////////////" << be_nl
      << "//                 ThruPOA Proxy  Implementation" << be_nl
      << "//" << be_nl << be_nl;

  *os << node->full_thru_poa_proxy_impl_name () << "::"
      << node->thru_poa_proxy_impl_name () << " (void)" << be_nl
      << "{}" << be_nl << be_nl;

  // Create the destructor implementation for the remote
  // proxy implementation.

  //os->indent ();
  *os << node->full_thru_poa_proxy_impl_name () << "::~"
      << node->thru_poa_proxy_impl_name () << " (void)" << be_nl
      << "{}" << be_nl << be_nl;


  // Generate the code for the ThruPOA Proxy Impl.
  // operations
  *os << "// ThruPOA Implementation of the IDL interface methods"
      << be_nl << be_nl;

  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_interface_ss::"
                         "visit_interface - "
                         "codegen for Base Proxy Broker class failed\n"),
                        -1);
    }
  *os << be_uidt << be_uidt;

  *os << be_nl
      << "//" << be_nl
      << "//           End ThruPOA Proxy Implementation" << be_nl
      << "///////////////////////////////////////////////////////////////////////"
      << be_nl << be_nl;

  return 0;

}
