// $Id$

#include "Assembly_Handlers.h"

#if !defined (__ACE_INLINE__)
# include "Assembly_Handlers.inl"
#endif /* __ACE_INLINE__ */

void
CIAO::Assembly_Handler::characters (const ACEXML_Char *cdata,
                                   int start,
                                   int len
                                   ACEXML_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
}

void
CIAO::Assembly_Handler::startElement (const ACEXML_Char *namespaceURI,
                                      const ACEXML_Char *localName,
                                      const ACEXML_Char *qName,
                                      ACEXML_Attributes *alist
                                      ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  switch (this->state_)
    {
    case START:
      if (ACE_OS::strcmp (qName, "componentfiles") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Start componentfiles\n"));
          CIAO::XMLHelpers::Cascadable_DocHandler *new_handler;

          ACE_NEW (new_handler,
                   CIAO::Comp_File_Handler (this->context_,
                                            this->parser_,
                                            this,
                                            namespaceURI,
                                            localName,
                                            qName,
                                            alist
                                            ACEXML_ENV_ARG_PARAMETER));
          ACEXML_CHECK;

          this->push_handler (new_handler,
                              alist
                              ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;
        }
      return;

    case COMPONENTFILES_DONE:
      if (ACE_OS::strcmp (qName, "partitioning") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Start partitioning\n"));
          CIAO::XMLHelpers::Cascadable_DocHandler *new_handler;

          ACE_NEW (new_handler,
                   CIAO::Partitioning_Handler (this->context_,
                                               this->parser_,
                                               this,
                                               namespaceURI,
                                               localName,
                                               qName,
                                               alist
                                               ACEXML_ENV_ARG_PARAMETER));
          ACEXML_CHECK;

          this->push_handler (new_handler,
                              alist
                              ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;
        }
      return;


    case PLACEMENT_DONE:
      if (ACE_OS::strcmp (qName, "connections") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Start connections\n"));
          CIAO::XMLHelpers::Cascadable_DocHandler *new_handler;

          ACE_NEW (new_handler,
                   CIAO::Connections_Handler (this->context_,
                                              this->parser_,
                                              this,
                                              namespaceURI,
                                              localName,
                                              qName,
                                              alist
                                              ACEXML_ENV_ARG_PARAMETER));
          ACEXML_CHECK;

          this->push_handler (new_handler,
                              alist
                              ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;
        }
      return;

    case CONNECTION_DONE:
      if (ACE_OS::strcmp (qName, "extension") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Start skipping extension\n"));
          CIAO::XMLHelpers::Cascadable_DocHandler *new_handler;

          ACE_NEW (new_handler,
                   CIAO::XMLHelpers::Skip_DocHandler (this->parser_,
                                                      this,
                                                      namespaceURI,
                                                      localName,
                                                      qName,
                                                      alist
                                                      ACEXML_ENV_ARG_PARAMETER));
          ACEXML_CHECK;

          this->push_handler (new_handler,
                              alist
                              ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;
        }
      return;


    default:
      ACEXML_THROW (ACEXML_SAXException
                    (ACE_TEXT ("Assembly handler internal error")));
      break;
    }
  ACEXML_THROW (ACEXML_SAXException
                (ACE_TEXT ("Assembly handler internal error")));
}

void
CIAO::Assembly_Handler::endElement (const ACEXML_Char *,
                                    const ACEXML_Char *,
                                    const ACEXML_Char *qName
                                    ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  switch (this->state_)
    {
    case START:
      if (ACE_OS::strcmp (qName, "componentfiles") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "End componentfiles\n"));
          this->state_ = COMPONENTFILES_DONE;
        }
      return;

    case COMPONENTFILES_DONE:
      if (ACE_OS::strcmp (qName, "partitioning") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "End partitioning\n"));
          this->state_ = PLACEMENT_DONE;
        }
      return;

    case PLACEMENT_DONE:
      if (ACE_OS::strcmp (qName, "connections") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "End connections\n"));
          this->state_ = CONNECTION_DONE;
        }
      return;

    case CONNECTION_DONE:
      if (ACE_OS::strcmp (qName, "extension") == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "End skipping extension\n"));
          this->state_ = DONE;
        }
      return;

    default:
      ACEXML_THROW (ACEXML_SAXException
                    (ACE_TEXT ("Assembly handler internal error")));
      break;
    }
  ACEXML_THROW (ACEXML_SAXException
                (ACE_TEXT ("Assembly handler internal error")));
}

// =================================================================

void
CIAO::Comp_File_Handler::endElement (const ACEXML_Char *namespaceURI,
                                     const ACEXML_Char *localName,
                                     const ACEXML_Char *qName
                                     ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACE_TRACE ("CIAO::Comp_File_Handler::endElement");

  --this->element_count_;
  if (this->element_count_ == 0)
    {
      this->parent_->pop_handler (namespaceURI,
                                  localName,
                                  qName
                                  ACEXML_ENV_ARG_PARAMETER);
      ACEXML_CHECK;
      return;
    }

  if (ACE_OS::strcmp (qName, "componentfile") == 0)
    {
      // @@ We can only handle fileinarchive for now.
      if (this->id_.length () == 0 || this->fileinarchive_.length () == 0)
        ACEXML_THROW
          (ACEXML_SAXException
           ("No valid id or component implementation in element \"componentfile\""));

      if (this->context_->componentfiles_.bind (this->id_,
                                                this->fileinarchive_) != 0)
        ACEXML_THROW
          (ACEXML_SAXException
           ("File to bind component implementation with id in element \"componentfile\""));

      this->id_.clear ();
      this->fileinarchive_.clear ();
    }

}

/*
<!ENTITY % simple-link-attributes "
         xml:link CDATA #FIXED 'SIMPLE'
         href CDATA #REQUIRED
" >

<!ELEMENT fileinarchive
    ( link? ) >
<!ATTLIST fileinarchive
    name CDATA #REQUIRED >

<!ELEMENT codebase EMPTY >
<!ATTLIST codebase
    filename CDATA #IMPLIED
    %simple-link-attributes; >

<!ELEMENT link ( #PCDATA ) >
<!ATTLIST link
    %simple-link-attributes; >
*/

void
CIAO::Comp_File_Handler::startElement (const ACEXML_Char *namespaceURI,
                                       const ACEXML_Char *localName,
                                       const ACEXML_Char *qName,
                                       ACEXML_Attributes *atts
                                       ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACE_TRACE ("CIAO::Comp_File_Handler::startElement");
  ++this->element_count_;

  if (ACE_OS::strcmp (qName, "componentfile") == 0)
    {
      for (size_t i = 0; i < atts->getLength (); ++i)
        {
          if (ACE_OS_String::strcmp (atts->getQName (i), ACE_TEXT ("id")) == 0)
            {
              this->id_ = atts->getValue (i);
            }
          else if (ACE_OS_String::strcmp (atts->getQName (i), ACE_TEXT ("type")) == 0)
            {
              // @@ Discard the value for now.  CIAO doesn't support
              // things other than CORBA component.
            }
          else
            {
              ACEXML_THROW
                (ACEXML_SAXException
                 ("Invalid attribute encountered in element \"componentfile\""));
            }
        }
    }
  else if (ACE_OS::strcmp (qName, "fileinarchive") == 0)
    {
      for (size_t i = 0; i < atts->getLength (); ++i)
        {
          if (ACE_OS_String::strcmp (atts->getQName (i), "name") == 0)
            {
              this->fileinarchive_ = atts->getValue (i);
            }
          else
            {
              ACEXML_THROW
                (ACEXML_SAXException
                 ("Invalid attribute encountered in element \"fileinarchive\""));
            }
        }
    }
  else if (ACE_OS::strcmp (qName, "link") == 0)
    {
    }
  else if (ACE_OS::strcmp (qName, "codebase") == 0)
    {
    }
  else if (ACE_OS::strcmp (qName, "componentfiles") == 0)
    {
      // Do nothing
    }
  else
    {
      ACE_DEBUG ((LM_DEBUG, "tag is: %s\n", qName));
      ACEXML_THROW (ACEXML_SAXException
                    (ACE_TEXT ("Invalid tag encounter while parsing \"componentfiles\"")));
    }
}

// =================================================================

void
CIAO::Partitioning_Handler::endElement (const ACEXML_Char *namespaceURI,
                                        const ACEXML_Char *localName,
                                        const ACEXML_Char *qName
                                        ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACE_TRACE ("CIAO::Partitioning_Handler::endElement");

  --this->element_count_;
  if (this->element_count_ == 0)
    {
      this->parent_->pop_handler (namespaceURI,
                                  localName,
                                  qName
                                  ACEXML_ENV_ARG_PARAMETER);
      ACEXML_CHECK;
      return;
    }

  switch (this->state_)
    {
    case START:
      if (ACE_OS::strcmp (qName, "hostcollocation") == 0)
        {
          this->context_->partitioning_.insert_tail (this->host_collocation_);
          this->host_collocation_ = 0;
        }
      else if (ACE_OS::strcmp (qName, "processcollocation") == 0)
        {
          if (this->host_collocation_ != 0)
            this->host_collocation_->insert_tail (this->process_collocation_);
          else
            this->context_->partitioning_.insert_tail (this->process_collocation_);
          this->process_collocation_ = 0;
        }
      else if (ACE_OS::strcmp (qName, "partitioning") == 0)
        {
        }
      else if (ACE_OS::strcmp (qName, "extension") == 0)
        {
          // Do nothing for now.
        }
      else if (ACE_OS::strcmp (qName, "destination") == 0)
        {
          if (this->process_collocation_ != 0)
            this->process_collocation_->destination (this->characters_.c_str ());
          else
            this->host_collocation_->destination (this->characters_.c_str ());
        }
      else if (ACE_OS::strcmp (qName, "usagename") == 0)
        {
          if (this->process_collocation_ != 0)
            this->process_collocation_->usagename (this->characters_.c_str ());
          else
            this->host_collocation_->usagename (this->characters_.c_str ());
        }
      break;

    case HOMEPLACEMENT:
      if (ACE_OS::strcmp (qName, "homeplacement") == 0)
        {
          this->state_ = START;
          if (this->process_collocation_ != 0)
            this->process_collocation_->insert_tail (this->home_placement_);
          else if (this->host_collocation_ != 0)
            this->host_collocation_->insert_tail (this->home_placement_);
          else
            this->context_->partitioning_.insert_tail (this->home_placement_);
          this->home_placement_ = 0;
        }
      else if (ACE_OS::strcmp (qName, "homeplacement") == 0)
        {
          this->home_placement_->destination (this->characters_.c_str ());
        }
      else if (ACE_OS::strcmp (qName, "usagename") == 0)
        {
          this->home_placement_->usagename (this->characters_.c_str ());
        }
      break;

    case COMPONENT_INSTANTIATION:
      if (ACE_OS::strcmp (qName, "componentinstantiation") == 0)
        {
          this->state_ = HOMEPLACEMENT;
          this->home_placement_->insert_tail (this->comp_instance_);
          this->comp_instance_ = 0;
        }
      break;

    default:
      break;
    }
}

void
CIAO::Partitioning_Handler::characters (const ACEXML_Char *ch,
                                        int start,
                                        int length
                                        ACEXML_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  this->characters_.set (ch + start, length);
}

void
CIAO::Partitioning_Handler::startElement (const ACEXML_Char *namespaceURI,
                                          const ACEXML_Char *localName,
                                          const ACEXML_Char *qName,
                                          ACEXML_Attributes *atts
                                          ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  // We are assuming we have a working ACEXML validator.

  ACE_TRACE ("CIAO::Partitioning_Handler::startElement");
  ++this->element_count_;

  switch (this->state_)
    {
    case START:
      if (ACE_OS::strcmp (qName, "homeplacement") == 0)
        {
          this->state_ = HOMEPLACEMENT;
          const char *id = 0;
          long cardinality =
            CIAO::XML_Utils::get_id_and_cardinality (id,
                                                     atts
                                                     ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;

          ACEXML_NEW_THROW_EX (this->home_placement_,
                               CIAO::Assembly_Placement::homeplacement (id,
                                                                        cardinality),
                               ACEXML_SAXException
                               ("Internal error, no memory."));
          ACEXML_CHECK;
        }
      else if (ACE_OS::strcmp (qName, "processcollocation") == 0)
        {
          const char *id = 0;
          long cardinality =
            CIAO::XML_Utils::get_id_and_cardinality (id,
                                                     atts
                                                     ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;

          ACEXML_NEW_THROW_EX (this->process_collocation_,
                               CIAO::Assembly_Placement::processcollocation (id,
                                                                             cardinality),
                               ACEXML_SAXException
                               ("Internal error, no memory."));
          ACEXML_CHECK;
        }
      else if (ACE_OS::strcmp (qName, "hostcollocation") == 0)
        {
          const char *id = 0;
          long cardinality =
            CIAO::XML_Utils::get_id_and_cardinality (id,
                                                     atts
                                                     ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;

          ACEXML_NEW_THROW_EX (this->host_collocation_,
                               CIAO::Assembly_Placement::hostcollocation (id,
                                                                          cardinality),
                               ACEXML_SAXException
                               ("Internal error, no memory."));
          ACEXML_CHECK;
        }
      else if (ACE_OS::strcmp (qName, "executableplacement") == 0)
        {
          ACEXML_THROW (ACEXML_SAXException
                        (ACE_TEXT ("\"executableplacement\" is not yet supported.")));
        }
      else if (ACE_OS::strcmp (qName, "extension") == 0)
        {
          ACEXML_THROW (ACEXML_SAXException
                        (ACE_TEXT ("\"extension\" is not yet supported.")));
        }
      else if (ACE_OS::strcmp (qName, "partitioning") == 0)
        {
          // do nothing
        }
      else
        {
          ACEXML_THROW
            (ACEXML_SAXException
             ("Invalid tag encounter while parsing \"partitioning\""));
        }
      break;

    case HOMEPLACEMENT:
      if (ACE_OS::strcmp (qName, "componentfileref") == 0)
        {
          const char *id;
          CIAO::XML_Utils::get_single_attribute ("idref",
                                                 id,
                                                 atts
                                                 ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;

          this->home_placement_->componentfileref (id);
        }
      else if (ACE_OS::strcmp (qName, "componentinstantiation") == 0)
        {
          const char *id;
          CIAO::XML_Utils::get_id_and_cardinality (id,
                                                   atts
                                                   ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;

          ACEXML_NEW_THROW_EX (this->comp_instance_,
                               CIAO::Assembly_Placement::componentinstantiation (id),
                               ACEXML_SAXException
                               ("Internal error, no memory."));
          ACEXML_CHECK;

        }
      // @@ Ignore the rest of element in home placement for now.
      break;

    case COMPONENT_INSTANTIATION:

      break;

    default:
      ACEXML_THROW
        (ACEXML_SAXException
         ("Invalid tag encounter while parsing \"partitioning\""));
    }

}

// =================================================================

void
CIAO::Connections_Handler::characters (const ACEXML_Char *ch,
                                       int start,
                                       int length
                                       ACEXML_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  this->characters_.set (ch + start, length);
}

void
CIAO::Connections_Handler::endElement (const ACEXML_Char *namespaceURI,
                                       const ACEXML_Char *localName,
                                       const ACEXML_Char *qName
                                       ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACE_TRACE ("CIAO::Connections_Handler::endElement");

  --this->element_count_;
  if (this->element_count_ == 0)
    {
      this->parent_->pop_handler (namespaceURI,
                                  localName,
                                  qName
                                  ACEXML_ENV_ARG_PARAMETER);
      ACEXML_CHECK;
      return;
    }

  if (ACE_OS::strcmp (qName, "stringifiedobjectref") == 0)
    {
        ACEXML_NEW_THROW_EX (this->resolver_,
                           CIAO::Assembly_Connection::IF_Resolver_Info
                           (CIAO::Assembly_Connection::STRINGIFIEDOBJECTREF,
                            this->characters_.c_str ()),
                           ACEXML_SAXException ("No memory left"));
      ACEXML_CHECK;
      return;
    }

  switch (this->state_)
    {
    case START:
      if (ACE_OS::strcmp (qName, "consumesidentifier") == 0 ||
          ACE_OS::strcmp (qName, "usesidentifier") == 0)
        {
          this->info_->name_ = this->characters_.c_str ();
        }
      if (ACE_OS::strcmp (qName, "consumesport") == 0 ||
          ACE_OS::strcmp (qName, "usesport") == 0 ||
          ACE_OS::strcmp (qName, "proxyhome") == 0)
        {
          if (this->resolver_ == 0)
            ACEXML_THROW (ACEXML_SAXException ("No valide IF resolver available"));
          this->info_->component_ = this->resolver_;
          this->resolver_ = 0;
          this->state_ = SOURCE;
        }
      else if (ACE_OS::strcmp (qName, "extension") == 0)
        {
          // @@ Not supported yet.
        }
      break;

    case SOURCE:
      if (ACE_OS::strcmp (qName, "destinationhome") == 0)
        {
          if (this->resolver_ == 0)
            ACEXML_THROW (ACEXML_SAXException ("No valide IF resolver available"));
          this->info_->interface_ = this->resolver_;
          this->resolver_ = 0;
        }
      else if (ACE_OS::strcmp (qName, "providesidentifier") == 0 ||
               ACE_OS::strcmp (qName, "emitsidentifier") == 0 ||
               ACE_OS::strcmp (qName, "publishesidentifier") == 0)
        {
          this->resolver_info_ = this->characters_.c_str ();
        }
      else if (ACE_OS::strcmp (qName, "providesport") == 0)
        {
          if (this->resolver_ == 0)
            ACEXML_THROW (ACEXML_SAXException
                          ("No valide nested IF resolver available"));
          CIAO::Assembly_Connection::IF_Resolver_Info *nested = this->resolver_;

          ACEXML_NEW_THROW_EX (this->resolver_,
                               CIAO::Assembly_Connection::IF_Resolver_Info
                               (CIAO::Assembly_Connection::PROVIDER,
                                this->resolver_info_.c_str (),
                                nested),
                               ACEXML_SAXException ("No memory left"));
          ACEXML_CHECK;
          this->info_->interface_ = this->resolver_;
          this->resolver_ = 0;
        }
      else if (ACE_OS::strcmp (qName, "emitsport") == 0 ||
               ACE_OS::strcmp (qName, "publishesport") == 0)
        {
          if (this->resolver_ == 0)
            ACEXML_THROW (ACEXML_SAXException
                          ("No valide nested IF resolver available"));
          CIAO::Assembly_Connection::IF_Resolver_Info *nested = this->resolver_;

          ACEXML_NEW_THROW_EX (this->resolver_,
                               CIAO::Assembly_Connection::IF_Resolver_Info
                               (CIAO::Assembly_Connection::CONSUMER,
                                this->resolver_info_.c_str (),
                                nested),
                               ACEXML_SAXException ("No memory left"));
          ACEXML_CHECK;
          this->info_->interface_ = this->resolver_;
          this->resolver_ = 0;
        }
      else if (ACE_OS::strcmp (qName, "connectinterface") == 0 ||
               ACE_OS::strcmp (qName, "connectevent") == 0 ||
               ACE_OS::strcmp (qName, "connecthomes") == 0)
        {
          this->context_->connections_.enqueue_tail (this->info_);
          this->info_ = 0;
          this->state_ = START;
        }
      break;

    default:
      ACEXML_THROW
        (ACEXML_SAXException
         ("Invalid state encounter while parsing \"connections\""));
      break;
    }
}

void
CIAO::Connections_Handler::startElement (const ACEXML_Char *namespaceURI,
                                         const ACEXML_Char *localName,
                                         const ACEXML_Char *qName,
                                         ACEXML_Attributes *atts
                                         ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACE_TRACE ("CIAO::Connections_Handler::startElement");
  ++this->element_count_;

  if (ACE_OS::strcmp (qName, "componentinstantiationref") == 0)
    {
      const char *idref;
      CIAO::XML_Utils::get_single_attribute ("idref",
                                             idref,
                                             atts
                                             ACEXML_ENV_ARG_PARAMETER);
      ACEXML_CHECK;

      ACEXML_NEW_THROW_EX (this->resolver_,
                           CIAO::Assembly_Connection::IF_Resolver_Info
                           (CIAO::Assembly_Connection::COMP_IDREF,
                            idref),
                           ACEXML_SAXException ("No memory left"));
      ACEXML_CHECK;
      return;
    }
  else if (ACE_OS::strcmp (qName, "homeplacementref") == 0)
    {
      const char *idref;
      CIAO::XML_Utils::get_single_attribute ("idref",
                                             idref,
                                             atts
                                             ACEXML_ENV_ARG_PARAMETER);
      ACEXML_CHECK;

      ACEXML_NEW_THROW_EX (this->resolver_,
                           CIAO::Assembly_Connection::IF_Resolver_Info
                           (CIAO::Assembly_Connection::HOME_IDREF,
                            idref),
                           ACEXML_SAXException ("No memory left"));
      ACEXML_CHECK;
      return;
    }
  else if (ACE_OS::strcmp (qName, "namingservice") == 0)
    {
      const char *name;
      CIAO::XML_Utils::get_single_attribute ("name",
                                             name,
                                             atts
                                             ACEXML_ENV_ARG_PARAMETER);
      ACEXML_CHECK;

      ACEXML_NEW_THROW_EX (this->resolver_,
                           CIAO::Assembly_Connection::IF_Resolver_Info
                           (CIAO::Assembly_Connection::NAMINGSERVICE,
                            name),
                           ACEXML_SAXException ("No memory left"));
      ACEXML_CHECK;
      return;
    }
  else if (ACE_OS::strcmp (qName, "homefinder") == 0)
    {
      const char *name;
      CIAO::XML_Utils::get_single_attribute ("name",
                                             name,
                                             atts
                                             ACEXML_ENV_ARG_PARAMETER);
      ACEXML_CHECK;

      ACEXML_NEW_THROW_EX (this->resolver_,
                           CIAO::Assembly_Connection::IF_Resolver_Info
                           (CIAO::Assembly_Connection::HOMEFINDER,
                            name),
                           ACEXML_SAXException ("No memory left"));
      ACEXML_CHECK;
      return;
    }
  else if (ACE_OS::strcmp (qName, "traderquery") == 0)
    ACEXML_THROW (ACEXML_SAXException ("\'traderquery\' is not supported yet."));

  switch (this->state_)
    {
    case START:
      if (ACE_OS::strcmp (qName, "connectinterface") == 0)
        {
          this->create_info (atts
                             ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;

          this->info_->type_ = CIAO::Assembly_Connection::INTERFACE;
        }
      else if (ACE_OS::strcmp (qName, "connectevent") == 0)
        {
          this->create_info (atts
                             ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;

        }
      else if (ACE_OS::strcmp (qName, "connecthomes") == 0)
        {
          this->create_info (atts
                             ACEXML_ENV_ARG_PARAMETER);
          ACEXML_CHECK;
          this->info_->type_ = CIAO::Assembly_Connection::HOME;
        }
      else if (ACE_OS::strcmp (qName, "extension") == 0)
        {
          // @@ Not supported yet.
        }
      break;

    case SOURCE:
      if (ACE_OS::strcmp (qName, "emitsport") == 0)
        {
          this->info_->type_ = CIAO::Assembly_Connection::EMITTER_CONSUMER;
        }
      else if (ACE_OS::strcmp (qName, "publishesport") == 0)
        {
          this->info_->type_ = CIAO::Assembly_Connection::PUBLISHER_CONSUMER;
        }
      break;

    default:
      ACEXML_THROW
        (ACEXML_SAXException
         ("Invalid state encounter while parsing \"connections\""));
      break;
    }
}

void
CIAO::Connections_Handler::create_info (ACEXML_Attributes *atts
                                        ACEXML_ENV_ARG_DECL)
  ACE_THROW_SPEC ((ACEXML_SAXException))
{
  ACEXML_NEW_THROW_EX (this->info_,
                       CIAO::Assembly_Connection::Connect_Info (),
                       ACEXML_SAXException
                       ("Internal error, no memory."));
  ACEXML_CHECK;

  for (size_t i = 0; i < atts->getLength (); ++i)
    {
      if (ACE_OS_String::strcmp (atts->getQName (i), ACE_TEXT ("id")) == 0)
        {
          this->info_->id_ = atts->getValue (i);
        }
      else
        ACEXML_THROW
          (ACEXML_SAXException
           ("Invalid tag encounter while parsing \"componentfiles\""));
    }
}
