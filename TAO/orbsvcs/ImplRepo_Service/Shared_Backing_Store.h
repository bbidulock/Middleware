/* -*- C++ -*- */

//=============================================================================
/**
*  @file Shared_Backing_Store.h
*
*  $Id$
*
*  This class defines an implementation of the backing store as multiple XML files
*  shared between multiple Locators.
*
*  @author Darrell Brunsch <brunsch@cs.wustl.edu>
*  @author Priyanka Gontla <gontla_p@ociweb.com>
*/
//=============================================================================

#ifndef SHARED_BACKING_STORE_H
#define SHARED_BACKING_STORE_H

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "XML_Backing_Store.h"

#include "ImR_LocatorS.h"
#include "ace/Bound_Ptr.h"
#include "ace/Vector_T.h"
#include "ACEXML/common/DefaultHandler.h"

class ACE_Configuration;
class ACEXML_FileCharStream;
class LocatorListings_XMLHandler;

/**
* @class Shared_Backing_Store
*
* @brief XML backing store containing all ImR persistent information in
* multiple files shared between multiple Locators
*
*/
class Shared_Backing_Store
  : public XML_Backing_Store,
    public virtual POA_ImplementationRepository::UpdatePushNotification
{
public:
  typedef ImplementationRepository::UpdatePushNotification_var Replica_var;
  typedef ImplementationRepository::UpdatePushNotification_ptr Replica_ptr;
  Shared_Backing_Store(const Options& opts,
                       CORBA::ORB_ptr orb);

  virtual ~Shared_Backing_Store();

  virtual const char* repo_mode() const;

  virtual void notify_updated_server(
    const ImplementationRepository::ServerUpdate& server);
  virtual void notify_updated_activator(
    const ImplementationRepository::ActivatorUpdate& activator);
  virtual void register_replica(
    ImplementationRepository::UpdatePushNotification_ptr replica,
    char*& ft_imr_ior,
    ImplementationRepository::SequenceNum_out seq_num);

protected:
  virtual int init_repo(PortableServer::POA_ptr imr_poa);

  virtual int persistent_update(const Server_Info_Ptr& info, bool add);

  virtual int persistent_update(const Activator_Info_Ptr& info, bool add);

  virtual int persistent_remove(const ACE_CString& name, bool activator);

  virtual int sync_load (const ACE_CString& name, SyncOp sync_op,
                         bool activator);

  virtual int report_ior(PortableServer::POA_ptr root_poa,
                         PortableServer::POA_ptr imr_poa);

  char* locator_service_ior(const char* peer_ior) const;

private:
  class LocatorListings_XMLHandler : public ACEXML_DefaultHandler
  {
  public:
    LocatorListings_XMLHandler(const ACE_CString& dir);
    LocatorListings_XMLHandler(const ACE_CString& dir,
                               const Locator_Repository::SIMap& servers,
                               const Locator_Repository::AIMap& activators);

    virtual void startElement (const ACEXML_Char* namespaceURI,
                               const ACEXML_Char* localName,
                               const ACEXML_Char* qName,
                               ACEXML_Attributes* attrs);

    virtual void endElement (const ACEXML_Char* namespaceURI,
                             const ACEXML_Char* localName,
                             const ACEXML_Char* qName);

    void remove_unmatched(Locator_Repository::SIMap& servers,
                          Locator_Repository::AIMap& activators);

    const ACE_Vector<ACE_CString>& filenames() const;

  private:
    const ACE_CString& dir_;
    ACE_Vector<ACE_CString> filenames_;
    Locator_Repository::SIMap unmatched_servers_;
    Locator_Repository::AIMap unmatched_activators_;
    const bool only_changes_;
  };
  typedef ACE_Strong_Bound_Ptr
    <LocatorListings_XMLHandler, ACE_Null_Mutex> XMLHandler_Ptr;

  ACE_CString make_filename(const ACE_CString& name,
                            bool activator,
                            bool relative = false) const;
  ACE_CString replica_ior_filename(bool peer_ior_file) const;
  XMLHandler_Ptr get_listings(bool only_changes) const;
  int persistent_load(bool only_changes);
  int persist_listings() const;
  int connect_replicas(Replica_ptr this_replica);

  /// sync up this repository with the replica_, returns true if the
  /// caller needs to perform an incremental sync
  bool sync_repo(ImplementationRepository::SequenceNum new_seq_num,
                 const ImplementationRepository::UpdateType& update_type);

  const ACE_TString listing_file_;
  Replica_var replica_;

  ImplementationRepository::SequenceNum seq_num_;
  ImplementationRepository::SequenceNum replica_seq_num_;
  const Options::ImrType imr_type_;
  CORBA::String_var non_ft_imr_ior_;
  const char* IMR_REPLICA[3];
};

#endif /* SHARED_BACKING_STORE_H */
