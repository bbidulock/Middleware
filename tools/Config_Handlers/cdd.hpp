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


// Fixes the VC6 warning 4786.
#include "vc6-4786.h"
 
// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#include "XSC_XML_Handlers_Export.h"
#ifndef CDD_HPP
#define CDD_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class Domain;
    class Bridge;
    class Interconnect;
    class Node;
    class SharedResource;
  }
}

#include <memory>
#include <vector>
#include "XMLSchema/Types.hpp"

#include "Basic_Deployment_Data.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export Domain : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // UUID
      // 
      public:
      bool UUID_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& UUID () const;
      void UUID (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > UUID_;

      // label
      // 
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // node
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Node >::iterator node_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Node >::const_iterator node_const_iterator;
      node_iterator begin_node ();
      node_iterator end_node ();
      node_const_iterator begin_node () const;
      node_const_iterator end_node () const;
      void add_node (::CIAO::Config_Handlers::Node const& );
      size_t count_node (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Node > node_;

      // interconnect
      // 
      public:
      ::CIAO::Config_Handlers::Interconnect const& interconnect () const;
      void interconnect (::CIAO::Config_Handlers::Interconnect const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Interconnect > interconnect_;

      // bridge
      // 
      public:
      ::CIAO::Config_Handlers::Bridge const& bridge () const;
      void bridge (::CIAO::Config_Handlers::Bridge const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Bridge > bridge_;

      // sharedResource
      // 
      public:
      bool sharedResource_p () const;
      ::CIAO::Config_Handlers::SharedResource const& sharedResource () const;
      void sharedResource (::CIAO::Config_Handlers::SharedResource const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::SharedResource > sharedResource_;

      // infoProperty
      // 
      public:
      bool infoProperty_p () const;
      ::CIAO::Config_Handlers::Property const& infoProperty () const;
      void infoProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > infoProperty_;

      public:
      Domain (::CIAO::Config_Handlers::Interconnect const& interconnect__,
      ::CIAO::Config_Handlers::Bridge const& bridge__);

      Domain (::XSCRT::XML::Element< ACE_TCHAR > const&);
      Domain (Domain const& s);

      Domain&
      operator= (Domain const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export Bridge : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // label
      // 
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // connect
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Interconnect >::iterator connect_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Interconnect >::const_iterator connect_const_iterator;
      connect_iterator begin_connect ();
      connect_iterator end_connect ();
      connect_const_iterator begin_connect () const;
      connect_const_iterator end_connect () const;
      void add_connect (::CIAO::Config_Handlers::Interconnect const& );
      size_t count_connect (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Interconnect > connect_;

      // resource
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Resource >::iterator resource_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Resource >::const_iterator resource_const_iterator;
      resource_iterator begin_resource ();
      resource_iterator end_resource ();
      resource_const_iterator begin_resource () const;
      resource_const_iterator end_resource () const;
      void add_resource (::CIAO::Config_Handlers::Resource const& );
      size_t count_resource (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Resource > resource_;

      public:
      Bridge (::XMLSchema::string< ACE_TCHAR > const& name__);

      Bridge (::XSCRT::XML::Element< ACE_TCHAR > const&);
      Bridge (Bridge const& s);

      Bridge&
      operator= (Bridge const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export Interconnect : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // label
      // 
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // connection
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Bridge >::iterator connection_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Bridge >::const_iterator connection_const_iterator;
      connection_iterator begin_connection ();
      connection_iterator end_connection ();
      connection_const_iterator begin_connection () const;
      connection_const_iterator end_connection () const;
      void add_connection (::CIAO::Config_Handlers::Bridge const& );
      size_t count_connection (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Bridge > connection_;

      // connect
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Node >::iterator connect_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Node >::const_iterator connect_const_iterator;
      connect_iterator begin_connect ();
      connect_iterator end_connect ();
      connect_const_iterator begin_connect () const;
      connect_const_iterator end_connect () const;
      void add_connect (::CIAO::Config_Handlers::Node const& );
      size_t count_connect (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Node > connect_;

      // resource
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Resource >::iterator resource_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Resource >::const_iterator resource_const_iterator;
      resource_iterator begin_resource ();
      resource_iterator end_resource ();
      resource_const_iterator begin_resource () const;
      resource_const_iterator end_resource () const;
      void add_resource (::CIAO::Config_Handlers::Resource const& );
      size_t count_resource (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Resource > resource_;

      public:
      Interconnect (::XMLSchema::string< ACE_TCHAR > const& name__);

      Interconnect (::XSCRT::XML::Element< ACE_TCHAR > const&);
      Interconnect (Interconnect const& s);

      Interconnect&
      operator= (Interconnect const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export Node : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // label
      // 
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // connection
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Interconnect >::iterator connection_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Interconnect >::const_iterator connection_const_iterator;
      connection_iterator begin_connection ();
      connection_iterator end_connection ();
      connection_const_iterator begin_connection () const;
      connection_const_iterator end_connection () const;
      void add_connection (::CIAO::Config_Handlers::Interconnect const& );
      size_t count_connection (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Interconnect > connection_;

      // sharedResource
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::SharedResource >::iterator sharedResource_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::SharedResource >::const_iterator sharedResource_const_iterator;
      sharedResource_iterator begin_sharedResource ();
      sharedResource_iterator end_sharedResource ();
      sharedResource_const_iterator begin_sharedResource () const;
      sharedResource_const_iterator end_sharedResource () const;
      void add_sharedResource (::CIAO::Config_Handlers::SharedResource const& );
      size_t count_sharedResource (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::SharedResource > sharedResource_;

      // resource
      // 
      public:
      ::CIAO::Config_Handlers::Resource const& resource () const;
      void resource (::CIAO::Config_Handlers::Resource const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Resource > resource_;

      public:
      Node (::XMLSchema::string< ACE_TCHAR > const& name__,
      ::CIAO::Config_Handlers::Resource const& resource__);

      Node (::XSCRT::XML::Element< ACE_TCHAR > const&);
      Node (Node const& s);

      Node&
      operator= (Node const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export SharedResource : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // resourceType
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& resourceType () const;
      void resourceType (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > resourceType_;

      // node
      // 
      public:
      ::CIAO::Config_Handlers::Node const& node () const;
      void node (::CIAO::Config_Handlers::Node const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Node > node_;

      // property
      // 
      public:
      ::CIAO::Config_Handlers::SatisfierProperty const& property () const;
      void property (::CIAO::Config_Handlers::SatisfierProperty const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::SatisfierProperty > property_;

      public:
      SharedResource (::XMLSchema::string< ACE_TCHAR > const& name__,
      ::XMLSchema::string< ACE_TCHAR > const& resourceType__,
      ::CIAO::Config_Handlers::Node const& node__,
      ::CIAO::Config_Handlers::SatisfierProperty const& property__);

      SharedResource (::XSCRT::XML::Element< ACE_TCHAR > const&);
      SharedResource (SharedResource const& s);

      SharedResource&
      operator= (SharedResource const& s);

      private:
      char regulator__;
    };
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/Traversal.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      struct XSC_XML_Handlers_Export Domain : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::Domain >
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
        UUID (Type&);

        virtual void
        UUID (Type const&);

        virtual void
        UUID_none (Type&);

        virtual void
        UUID_none (Type const&);

        virtual void
        label (Type&);

        virtual void
        label (Type const&);

        virtual void
        label_none (Type&);

        virtual void
        label_none (Type const&);

        virtual void
        node (Type&);

        virtual void
        node (Type const&);

        virtual void
        node_pre (Type&);

        virtual void
        node_pre (Type const&);

        virtual void
        node_next (Type&);

        virtual void
        node_next (Type const&);

        virtual void
        node_post (Type&);

        virtual void
        node_post (Type const&);

        virtual void
        interconnect (Type&);

        virtual void
        interconnect (Type const&);

        virtual void
        bridge (Type&);

        virtual void
        bridge (Type const&);

        virtual void
        sharedResource (Type&);

        virtual void
        sharedResource (Type const&);

        virtual void
        sharedResource_none (Type&);

        virtual void
        sharedResource_none (Type const&);

        virtual void
        infoProperty (Type&);

        virtual void
        infoProperty (Type const&);

        virtual void
        infoProperty_none (Type&);

        virtual void
        infoProperty_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export Bridge : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::Bridge >
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
        label (Type&);

        virtual void
        label (Type const&);

        virtual void
        label_none (Type&);

        virtual void
        label_none (Type const&);

        virtual void
        connect (Type&);

        virtual void
        connect (Type const&);

        virtual void
        connect_pre (Type&);

        virtual void
        connect_pre (Type const&);

        virtual void
        connect_next (Type&);

        virtual void
        connect_next (Type const&);

        virtual void
        connect_post (Type&);

        virtual void
        connect_post (Type const&);

        virtual void
        resource (Type&);

        virtual void
        resource (Type const&);

        virtual void
        resource_pre (Type&);

        virtual void
        resource_pre (Type const&);

        virtual void
        resource_next (Type&);

        virtual void
        resource_next (Type const&);

        virtual void
        resource_post (Type&);

        virtual void
        resource_post (Type const&);

        virtual void
        resource_none (Type&);

        virtual void
        resource_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export Interconnect : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::Interconnect >
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
        label (Type&);

        virtual void
        label (Type const&);

        virtual void
        label_none (Type&);

        virtual void
        label_none (Type const&);

        virtual void
        connection (Type&);

        virtual void
        connection (Type const&);

        virtual void
        connection_pre (Type&);

        virtual void
        connection_pre (Type const&);

        virtual void
        connection_next (Type&);

        virtual void
        connection_next (Type const&);

        virtual void
        connection_post (Type&);

        virtual void
        connection_post (Type const&);

        virtual void
        connection_none (Type&);

        virtual void
        connection_none (Type const&);

        virtual void
        connect (Type&);

        virtual void
        connect (Type const&);

        virtual void
        connect_pre (Type&);

        virtual void
        connect_pre (Type const&);

        virtual void
        connect_next (Type&);

        virtual void
        connect_next (Type const&);

        virtual void
        connect_post (Type&);

        virtual void
        connect_post (Type const&);

        virtual void
        resource (Type&);

        virtual void
        resource (Type const&);

        virtual void
        resource_pre (Type&);

        virtual void
        resource_pre (Type const&);

        virtual void
        resource_next (Type&);

        virtual void
        resource_next (Type const&);

        virtual void
        resource_post (Type&);

        virtual void
        resource_post (Type const&);

        virtual void
        resource_none (Type&);

        virtual void
        resource_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export Node : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::Node >
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
        label (Type&);

        virtual void
        label (Type const&);

        virtual void
        label_none (Type&);

        virtual void
        label_none (Type const&);

        virtual void
        connection (Type&);

        virtual void
        connection (Type const&);

        virtual void
        connection_pre (Type&);

        virtual void
        connection_pre (Type const&);

        virtual void
        connection_next (Type&);

        virtual void
        connection_next (Type const&);

        virtual void
        connection_post (Type&);

        virtual void
        connection_post (Type const&);

        virtual void
        connection_none (Type&);

        virtual void
        connection_none (Type const&);

        virtual void
        sharedResource (Type&);

        virtual void
        sharedResource (Type const&);

        virtual void
        sharedResource_pre (Type&);

        virtual void
        sharedResource_pre (Type const&);

        virtual void
        sharedResource_next (Type&);

        virtual void
        sharedResource_next (Type const&);

        virtual void
        sharedResource_post (Type&);

        virtual void
        sharedResource_post (Type const&);

        virtual void
        sharedResource_none (Type&);

        virtual void
        sharedResource_none (Type const&);

        virtual void
        resource (Type&);

        virtual void
        resource (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export SharedResource : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::SharedResource >
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
        resourceType (Type&);

        virtual void
        resourceType (Type const&);

        virtual void
        node (Type&);

        virtual void
        node (Type const&);

        virtual void
        property (Type&);

        virtual void
        property (Type const&);

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
      struct Domain : Traversal::Domain, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::Domain Type;
        Domain (::XSCRT::XML::Element< ACE_TCHAR >&);

        #ifdef __BORLANDC__
        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        traverse (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        UUID (Type &o)
        {

          this->UUID (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        UUID (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        label (Type &o)
        {

          this->label (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        label (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        node_pre (Type &o)
        {

          this->node_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        node_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        node_next (Type &o)
        {

          this->node_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        node_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        node_post (Type &o)
        {

          this->node_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        node_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        interconnect (Type &o)
        {

          this->interconnect (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        interconnect (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        bridge (Type &o)
        {

          this->bridge (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        bridge (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        sharedResource (Type &o)
        {

          this->sharedResource (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        sharedResource (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        infoProperty (Type &o)
        {

          this->infoProperty (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        infoProperty (Type const&);

        protected:
        Domain ();
      };

      struct Bridge : Traversal::Bridge, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::Bridge Type;
        Bridge (::XSCRT::XML::Element< ACE_TCHAR >&);

        #ifdef __BORLANDC__
        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        traverse (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        name (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        label (Type &o)
        {

          this->label (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        label (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connect_pre (Type &o)
        {

          this->connect_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connect_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connect_next (Type &o)
        {

          this->connect_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connect_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connect_post (Type &o)
        {

          this->connect_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connect_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resource_pre (Type &o)
        {

          this->resource_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resource_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resource_next (Type &o)
        {

          this->resource_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resource_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resource_post (Type &o)
        {

          this->resource_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resource_post (Type const&);

        protected:
        Bridge ();
      };

      struct Interconnect : Traversal::Interconnect, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::Interconnect Type;
        Interconnect (::XSCRT::XML::Element< ACE_TCHAR >&);

        #ifdef __BORLANDC__
        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        traverse (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        name (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        label (Type &o)
        {

          this->label (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        label (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connection_pre (Type &o)
        {

          this->connection_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connection_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connection_next (Type &o)
        {

          this->connection_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connection_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connection_post (Type &o)
        {

          this->connection_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connection_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connect_pre (Type &o)
        {

          this->connect_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connect_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connect_next (Type &o)
        {

          this->connect_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connect_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connect_post (Type &o)
        {

          this->connect_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connect_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resource_pre (Type &o)
        {

          this->resource_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resource_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resource_next (Type &o)
        {

          this->resource_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resource_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resource_post (Type &o)
        {

          this->resource_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resource_post (Type const&);

        protected:
        Interconnect ();
      };

      struct Node : Traversal::Node, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::Node Type;
        Node (::XSCRT::XML::Element< ACE_TCHAR >&);

        #ifdef __BORLANDC__
        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        traverse (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        name (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        label (Type &o)
        {

          this->label (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        label (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connection_pre (Type &o)
        {

          this->connection_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connection_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connection_next (Type &o)
        {

          this->connection_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connection_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        connection_post (Type &o)
        {

          this->connection_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        connection_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        sharedResource_pre (Type &o)
        {

          this->sharedResource_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        sharedResource_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        sharedResource_next (Type &o)
        {

          this->sharedResource_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        sharedResource_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        sharedResource_post (Type &o)
        {

          this->sharedResource_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        sharedResource_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resource (Type &o)
        {

          this->resource (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resource (Type const&);

        protected:
        Node ();
      };

      struct SharedResource : Traversal::SharedResource, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::SharedResource Type;
        SharedResource (::XSCRT::XML::Element< ACE_TCHAR >&);

        #ifdef __BORLANDC__
        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        traverse (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        name (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        resourceType (Type &o)
        {

          this->resourceType (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        resourceType (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        node (Type &o)
        {

          this->node (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        node (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        property (Type &o)
        {

          this->property (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        property (Type const&);

        protected:
        SharedResource ();
      };
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#endif // CDD_HPP
