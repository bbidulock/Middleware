/* $Id$
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 *
 * If you find errors or feel that there are bugfixes to be made,
 * please contact the current XSC maintainer:
 *             Will Otte <wotte@dre.vanderbilt.edu>
 */

// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#ifndef CIAOEVENTS_HPP
#define CIAOEVENTS_HPP

#include "CIAO_Events_Handlers_Export.h"
// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class EventServiceType;
    class CIAOEventsDef;
    class EventServiceDescription;
    class FilterType;
    class Filter;
    class AddressServerDescription;
    class UDPSenderDescription;
    class UDPReceiverDescription;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class CIAO_Events_Handlers_Export EventServiceType : public ::XSCRT::Type
    {
      public:
      EventServiceType (::XSCRT::XML::Element< ACE_TCHAR > const&);
      EventServiceType (::XSCRT::XML::Attribute< ACE_TCHAR > const&);

      static EventServiceType const EC;
      static EventServiceType const RTEC;
      static EventServiceType const NOTIFY;
      static EventServiceType const RTNOTIFY;

      enum Value
      {
        EC_l, RTEC_l, NOTIFY_l, RTNOTIFY_l
      };


      Value
      integral () const;

      friend bool CIAO_Events_Handlers_Export 
      operator== (EventServiceType const& a, EventServiceType const& b);

      friend bool CIAO_Events_Handlers_Export 
      operator!= (EventServiceType const& a, EventServiceType const& b);

      private:
      EventServiceType (Value v);

      Value v_;
    };

    bool CIAO_Events_Handlers_Export operator== (EventServiceType const &a, EventServiceType const &b);

    bool CIAO_Events_Handlers_Export operator!= (EventServiceType const &a, EventServiceType const &b);


    class CIAO_Events_Handlers_Export CIAOEventsDef : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      // eventServiceConfiguration
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::EventServiceDescription >::iterator eventServiceConfiguration_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::EventServiceDescription >::const_iterator eventServiceConfiguration_const_iterator;
      eventServiceConfiguration_iterator begin_eventServiceConfiguration ();
      eventServiceConfiguration_iterator end_eventServiceConfiguration ();
      eventServiceConfiguration_const_iterator begin_eventServiceConfiguration () const;
      eventServiceConfiguration_const_iterator end_eventServiceConfiguration () const;
      void add_eventServiceConfiguration (::CIAO::Config_Handlers::EventServiceDescription const& );
      size_t count_eventServiceConfiguration (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::EventServiceDescription > eventServiceConfiguration_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      CIAOEventsDef ();

      CIAOEventsDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      CIAOEventsDef (CIAOEventsDef const& s);

      CIAOEventsDef&
      operator= (CIAOEventsDef const& s);

      private:
      char regulator__;
    };


    class CIAO_Events_Handlers_Export EventServiceDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // node
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& node () const;
      void node (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > node_;

      // type
      // 
      public:
      ::CIAO::Config_Handlers::EventServiceType const& type () const;
      void type (::CIAO::Config_Handlers::EventServiceType const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::EventServiceType > type_;

      // svc_cfg_file
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file () const;
      void svc_cfg_file (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > svc_cfg_file_;

      // filter
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::Filter >::iterator filter_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::Filter >::const_iterator filter_const_iterator;
      filter_iterator begin_filter ();
      filter_iterator end_filter ();
      filter_const_iterator begin_filter () const;
      filter_const_iterator end_filter () const;
      void add_filter (::CIAO::Config_Handlers::Filter const& );
      size_t count_filter (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::Filter > filter_;

      // addr_serv
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::AddressServerDescription >::iterator addr_serv_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::AddressServerDescription >::const_iterator addr_serv_const_iterator;
      addr_serv_iterator begin_addr_serv ();
      addr_serv_iterator end_addr_serv ();
      addr_serv_const_iterator begin_addr_serv () const;
      addr_serv_const_iterator end_addr_serv () const;
      void add_addr_serv (::CIAO::Config_Handlers::AddressServerDescription const& );
      size_t count_addr_serv (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::AddressServerDescription > addr_serv_;

      // udp_sender
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::UDPSenderDescription >::iterator udp_sender_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::UDPSenderDescription >::const_iterator udp_sender_const_iterator;
      udp_sender_iterator begin_udp_sender ();
      udp_sender_iterator end_udp_sender ();
      udp_sender_const_iterator begin_udp_sender () const;
      udp_sender_const_iterator end_udp_sender () const;
      void add_udp_sender (::CIAO::Config_Handlers::UDPSenderDescription const& );
      size_t count_udp_sender (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::UDPSenderDescription > udp_sender_;

      // udp_receiver
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::UDPReceiverDescription >::iterator udp_receiver_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::UDPReceiverDescription >::const_iterator udp_receiver_const_iterator;
      udp_receiver_iterator begin_udp_receiver ();
      udp_receiver_iterator end_udp_receiver ();
      udp_receiver_const_iterator begin_udp_receiver () const;
      udp_receiver_const_iterator end_udp_receiver () const;
      void add_udp_receiver (::CIAO::Config_Handlers::UDPReceiverDescription const& );
      size_t count_udp_receiver (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::UDPReceiverDescription > udp_receiver_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      EventServiceDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                               ::XMLSchema::string< ACE_TCHAR > const& node__,
                               ::CIAO::Config_Handlers::EventServiceType const& type__,
                               ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file__);

      EventServiceDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      EventServiceDescription (EventServiceDescription const& s);

      EventServiceDescription&
      operator= (EventServiceDescription const& s);

      private:
      char regulator__;
    };


    class CIAO_Events_Handlers_Export FilterType : public ::XSCRT::Type
    {
      public:
      FilterType (::XSCRT::XML::Element< ACE_TCHAR > const&);
      FilterType (::XSCRT::XML::Attribute< ACE_TCHAR > const&);

      static FilterType const CONJUNCTION;
      static FilterType const DISJUNCTION;
      static FilterType const LOGICAL_AND;
      static FilterType const NEGATE;

      enum Value
      {
        CONJUNCTION_l, DISJUNCTION_l, LOGICAL_AND_l, NEGATE_l
      };


      Value
      integral () const;

      friend bool CIAO_Events_Handlers_Export 
      operator== (FilterType const& a, FilterType const& b);

      friend bool CIAO_Events_Handlers_Export 
      operator!= (FilterType const& a, FilterType const& b);

      private:
      FilterType (Value v);

      Value v_;
    };

    bool CIAO_Events_Handlers_Export operator== (FilterType const &a, FilterType const &b);

    bool CIAO_Events_Handlers_Export operator!= (FilterType const &a, FilterType const &b);


    class CIAO_Events_Handlers_Export Filter : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // type
      // 
      public:
      ::CIAO::Config_Handlers::FilterType const& type () const;
      void type (::CIAO::Config_Handlers::FilterType const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::FilterType > type_;

      // source
      // 
      public:
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::iterator source_iterator;
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::const_iterator source_const_iterator;
      source_iterator begin_source ();
      source_iterator end_source ();
      source_const_iterator begin_source () const;
      source_const_iterator end_source () const;
      void add_source (::XMLSchema::string< ACE_TCHAR > const& );
      size_t count_source (void) const;

      protected:
      ::std::list< ::XMLSchema::string< ACE_TCHAR > > source_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      Filter (::XMLSchema::string< ACE_TCHAR > const& name__,
              ::CIAO::Config_Handlers::FilterType const& type__);

      Filter (::XSCRT::XML::Element< ACE_TCHAR > const&);
      Filter (Filter const& s);

      Filter&
      operator= (Filter const& s);

      private:
      char regulator__;
    };


    class CIAO_Events_Handlers_Export AddressServerDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // port
      // 
      public:
      ::XMLSchema::unsignedShort const& port () const;
      void port (::XMLSchema::unsignedShort const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedShort > port_;

      // address
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& address () const;
      void address (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > address_;

      public:
      AddressServerDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                                ::XMLSchema::unsignedShort const& port__,
                                ::XMLSchema::string< ACE_TCHAR > const& address__);

      AddressServerDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      AddressServerDescription (AddressServerDescription const& s);

      AddressServerDescription&
      operator= (AddressServerDescription const& s);

      private:
      char regulator__;
    };


    class CIAO_Events_Handlers_Export UDPSenderDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // addr_serv_id
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& addr_serv_id () const;
      void addr_serv_id (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > addr_serv_id_;

      public:
      UDPSenderDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                            ::XMLSchema::string< ACE_TCHAR > const& addr_serv_id__);

      UDPSenderDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      UDPSenderDescription (UDPSenderDescription const& s);

      UDPSenderDescription&
      operator= (UDPSenderDescription const& s);

      private:
      char regulator__;
    };


    class CIAO_Events_Handlers_Export UDPReceiverDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // addr_serv_id
      // 
      public:
      bool addr_serv_id_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& addr_serv_id () const;
      void addr_serv_id (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > addr_serv_id_;

      // is_multicast
      // 
      public:
      ::XMLSchema::boolean const& is_multicast () const;
      void is_multicast (::XMLSchema::boolean const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::boolean > is_multicast_;

      // listen_port
      // 
      public:
      ::XMLSchema::unsignedShort const& listen_port () const;
      void listen_port (::XMLSchema::unsignedShort const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedShort > listen_port_;

      public:
      UDPReceiverDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                              ::XMLSchema::boolean const& is_multicast__,
                              ::XMLSchema::unsignedShort const& listen_port__);

      UDPReceiverDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      UDPReceiverDescription (UDPReceiverDescription const& s);

      UDPReceiverDescription&
      operator= (UDPReceiverDescription const& s);

      private:
      char regulator__;
    };
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    CIAO_Events_Handlers_Export
    ::CIAO::Config_Handlers::CIAOEventsDef
    CIAOEvents (xercesc::DOMDocument const*);
  }
}

#include "XMLSchema/Traversal.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      typedef
      ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::EventServiceType >
      EventServiceType;

      struct CIAO_Events_Handlers_Export CIAOEventsDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::CIAOEventsDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        eventServiceConfiguration (Type&);

        virtual void
        eventServiceConfiguration (Type const&);

        virtual void
        eventServiceConfiguration_pre (Type&);

        virtual void
        eventServiceConfiguration_pre (Type const&);

        virtual void
        eventServiceConfiguration_next (Type&);

        virtual void
        eventServiceConfiguration_next (Type const&);

        virtual void
        eventServiceConfiguration_post (Type&);

        virtual void
        eventServiceConfiguration_post (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct CIAO_Events_Handlers_Export EventServiceDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::EventServiceDescription >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        name (Type&);

        virtual void
        name (Type const&);

        virtual void
        node (Type&);

        virtual void
        node (Type const&);

        virtual void
        type (Type&);

        virtual void
        type (Type const&);

        virtual void
        svc_cfg_file (Type&);

        virtual void
        svc_cfg_file (Type const&);

        virtual void
        filter (Type&);

        virtual void
        filter (Type const&);

        virtual void
        filter_pre (Type&);

        virtual void
        filter_pre (Type const&);

        virtual void
        filter_next (Type&);

        virtual void
        filter_next (Type const&);

        virtual void
        filter_post (Type&);

        virtual void
        filter_post (Type const&);

        virtual void
        filter_none (Type&);

        virtual void
        filter_none (Type const&);

        virtual void
        addr_serv (Type&);

        virtual void
        addr_serv (Type const&);

        virtual void
        addr_serv_pre (Type&);

        virtual void
        addr_serv_pre (Type const&);

        virtual void
        addr_serv_next (Type&);

        virtual void
        addr_serv_next (Type const&);

        virtual void
        addr_serv_post (Type&);

        virtual void
        addr_serv_post (Type const&);

        virtual void
        addr_serv_none (Type&);

        virtual void
        addr_serv_none (Type const&);

        virtual void
        udp_sender (Type&);

        virtual void
        udp_sender (Type const&);

        virtual void
        udp_sender_pre (Type&);

        virtual void
        udp_sender_pre (Type const&);

        virtual void
        udp_sender_next (Type&);

        virtual void
        udp_sender_next (Type const&);

        virtual void
        udp_sender_post (Type&);

        virtual void
        udp_sender_post (Type const&);

        virtual void
        udp_sender_none (Type&);

        virtual void
        udp_sender_none (Type const&);

        virtual void
        udp_receiver (Type&);

        virtual void
        udp_receiver (Type const&);

        virtual void
        udp_receiver_pre (Type&);

        virtual void
        udp_receiver_pre (Type const&);

        virtual void
        udp_receiver_next (Type&);

        virtual void
        udp_receiver_next (Type const&);

        virtual void
        udp_receiver_post (Type&);

        virtual void
        udp_receiver_post (Type const&);

        virtual void
        udp_receiver_none (Type&);

        virtual void
        udp_receiver_none (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      typedef
      ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::FilterType >
      FilterType;

      struct CIAO_Events_Handlers_Export Filter : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::Filter >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        name (Type&);

        virtual void
        name (Type const&);

        virtual void
        type (Type&);

        virtual void
        type (Type const&);

        virtual void
        source (Type&);

        virtual void
        source (Type const&);

        virtual void
        source_pre (Type&);

        virtual void
        source_pre (Type const&);

        virtual void
        source_next (Type&);

        virtual void
        source_next (Type const&);

        virtual void
        source_post (Type&);

        virtual void
        source_post (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct CIAO_Events_Handlers_Export AddressServerDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::AddressServerDescription >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        name (Type&);

        virtual void
        name (Type const&);

        virtual void
        port (Type&);

        virtual void
        port (Type const&);

        virtual void
        address (Type&);

        virtual void
        address (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct CIAO_Events_Handlers_Export UDPSenderDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::UDPSenderDescription >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        name (Type&);

        virtual void
        name (Type const&);

        virtual void
        addr_serv_id (Type&);

        virtual void
        addr_serv_id (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct CIAO_Events_Handlers_Export UDPReceiverDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::UDPReceiverDescription >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        name (Type&);

        virtual void
        name (Type const&);

        virtual void
        addr_serv_id (Type&);

        virtual void
        addr_serv_id (Type const&);

        virtual void
        addr_serv_id_none (Type&);

        virtual void
        addr_serv_id_none (Type const&);

        virtual void
        is_multicast (Type&);

        virtual void
        is_multicast (Type const&);

        virtual void
        listen_port (Type&);

        virtual void
        listen_port (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };
    }
  }
}

#include "XMLSchema/Writer.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      struct EventServiceType : Traversal::EventServiceType, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        EventServiceType (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        protected:
        EventServiceType ();
      };

      struct CIAOEventsDef : Traversal::CIAOEventsDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::CIAOEventsDef Type;
        CIAOEventsDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        eventServiceConfiguration_pre (Type &o)
        {

          this->eventServiceConfiguration_pre (const_cast <Type const &> (o));
        }


        virtual void
        eventServiceConfiguration_pre (Type const&);

        virtual void 
        eventServiceConfiguration_next (Type &o)
        {

          this->eventServiceConfiguration_next (const_cast <Type const &> (o));
        }


        virtual void
        eventServiceConfiguration_next (Type const&);

        virtual void 
        eventServiceConfiguration_post (Type &o)
        {

          this->eventServiceConfiguration_post (const_cast <Type const &> (o));
        }


        virtual void
        eventServiceConfiguration_post (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        CIAOEventsDef ();
      };

      struct EventServiceDescription : Traversal::EventServiceDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::EventServiceDescription Type;
        EventServiceDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        virtual void
        name (Type const&);

        virtual void 
        node (Type &o)
        {

          this->node (const_cast <Type const &> (o));
        }


        virtual void
        node (Type const&);

        virtual void 
        type (Type &o)
        {

          this->type (const_cast <Type const &> (o));
        }


        virtual void
        type (Type const&);

        virtual void 
        svc_cfg_file (Type &o)
        {

          this->svc_cfg_file (const_cast <Type const &> (o));
        }


        virtual void
        svc_cfg_file (Type const&);

        virtual void 
        filter_pre (Type &o)
        {

          this->filter_pre (const_cast <Type const &> (o));
        }


        virtual void
        filter_pre (Type const&);

        virtual void 
        filter_next (Type &o)
        {

          this->filter_next (const_cast <Type const &> (o));
        }


        virtual void
        filter_next (Type const&);

        virtual void 
        filter_post (Type &o)
        {

          this->filter_post (const_cast <Type const &> (o));
        }


        virtual void
        filter_post (Type const&);

        virtual void 
        addr_serv_pre (Type &o)
        {

          this->addr_serv_pre (const_cast <Type const &> (o));
        }


        virtual void
        addr_serv_pre (Type const&);

        virtual void 
        addr_serv_next (Type &o)
        {

          this->addr_serv_next (const_cast <Type const &> (o));
        }


        virtual void
        addr_serv_next (Type const&);

        virtual void 
        addr_serv_post (Type &o)
        {

          this->addr_serv_post (const_cast <Type const &> (o));
        }


        virtual void
        addr_serv_post (Type const&);

        virtual void 
        udp_sender_pre (Type &o)
        {

          this->udp_sender_pre (const_cast <Type const &> (o));
        }


        virtual void
        udp_sender_pre (Type const&);

        virtual void 
        udp_sender_next (Type &o)
        {

          this->udp_sender_next (const_cast <Type const &> (o));
        }


        virtual void
        udp_sender_next (Type const&);

        virtual void 
        udp_sender_post (Type &o)
        {

          this->udp_sender_post (const_cast <Type const &> (o));
        }


        virtual void
        udp_sender_post (Type const&);

        virtual void 
        udp_receiver_pre (Type &o)
        {

          this->udp_receiver_pre (const_cast <Type const &> (o));
        }


        virtual void
        udp_receiver_pre (Type const&);

        virtual void 
        udp_receiver_next (Type &o)
        {

          this->udp_receiver_next (const_cast <Type const &> (o));
        }


        virtual void
        udp_receiver_next (Type const&);

        virtual void 
        udp_receiver_post (Type &o)
        {

          this->udp_receiver_post (const_cast <Type const &> (o));
        }


        virtual void
        udp_receiver_post (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        EventServiceDescription ();
      };

      struct FilterType : Traversal::FilterType, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        FilterType (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        protected:
        FilterType ();
      };

      struct Filter : Traversal::Filter, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::Filter Type;
        Filter (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        virtual void
        name (Type const&);

        virtual void 
        type (Type &o)
        {

          this->type (const_cast <Type const &> (o));
        }


        virtual void
        type (Type const&);

        virtual void 
        source_pre (Type &o)
        {

          this->source_pre (const_cast <Type const &> (o));
        }


        virtual void
        source_pre (Type const&);

        virtual void 
        source_next (Type &o)
        {

          this->source_next (const_cast <Type const &> (o));
        }


        virtual void
        source_next (Type const&);

        virtual void 
        source_post (Type &o)
        {

          this->source_post (const_cast <Type const &> (o));
        }


        virtual void
        source_post (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        Filter ();
      };

      struct AddressServerDescription : Traversal::AddressServerDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::AddressServerDescription Type;
        AddressServerDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        virtual void
        name (Type const&);

        virtual void 
        port (Type &o)
        {

          this->port (const_cast <Type const &> (o));
        }


        virtual void
        port (Type const&);

        virtual void 
        address (Type &o)
        {

          this->address (const_cast <Type const &> (o));
        }


        virtual void
        address (Type const&);

        protected:
        AddressServerDescription ();
      };

      struct UDPSenderDescription : Traversal::UDPSenderDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::UDPSenderDescription Type;
        UDPSenderDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        virtual void
        name (Type const&);

        virtual void 
        addr_serv_id (Type &o)
        {

          this->addr_serv_id (const_cast <Type const &> (o));
        }


        virtual void
        addr_serv_id (Type const&);

        protected:
        UDPSenderDescription ();
      };

      struct UDPReceiverDescription : Traversal::UDPReceiverDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::UDPReceiverDescription Type;
        UDPReceiverDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        virtual void
        name (Type const&);

        virtual void 
        addr_serv_id (Type &o)
        {

          this->addr_serv_id (const_cast <Type const &> (o));
        }


        virtual void
        addr_serv_id (Type const&);

        virtual void 
        is_multicast (Type &o)
        {

          this->is_multicast (const_cast <Type const &> (o));
        }


        virtual void
        is_multicast (Type const&);

        virtual void 
        listen_port (Type &o)
        {

          this->listen_port (const_cast <Type const &> (o));
        }


        virtual void
        listen_port (Type const&);

        protected:
        UDPReceiverDescription ();
      };
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    CIAO_Events_Handlers_Export
    void
    CIAOEvents (::CIAO::Config_Handlers::CIAOEventsDef const&, xercesc::DOMDocument*);
  }
}

#endif // CIAOEVENTS_HPP
