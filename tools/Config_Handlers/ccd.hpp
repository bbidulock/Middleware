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

#ifndef CCD_HPP
#define CCD_HPP

#include "XSC_XML_Handlers_Export.h"
// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class ComponentInterfaceDescription;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"
#include "XMLSchema/id_map.hpp"
#include "ace/Refcounted_Auto_Ptr.h"
#include "ace/Null_Mutex.h"
#include "ace/TSS_T.h"
#include "ace/Singleton.h"

#include "Basic_Deployment_Data.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export ComponentInterfaceDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      public:
      typedef ACE_Refcounted_Auto_Ptr < ComponentInterfaceDescription, ACE_Null_Mutex > _ptr;

      // label
      // 
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // UUID
      // 
      public:
      bool UUID_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& UUID () const;
      void UUID (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > UUID_;

      // specificType
      // 
      public:
      bool specificType_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& specificType () const;
      void specificType (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > specificType_;

      // supportedType
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > >::iterator supportedType_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > >::const_iterator supportedType_const_iterator;
      supportedType_iterator begin_supportedType ();
      supportedType_iterator end_supportedType ();
      supportedType_const_iterator begin_supportedType () const;
      supportedType_const_iterator end_supportedType () const;
      void add_supportedType ( ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > const& );
      size_t count_supportedType (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > > supportedType_;

      // idlFile
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > >::iterator idlFile_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > >::const_iterator idlFile_const_iterator;
      idlFile_iterator begin_idlFile ();
      idlFile_iterator end_idlFile ();
      idlFile_const_iterator begin_idlFile () const;
      idlFile_const_iterator end_idlFile () const;
      void add_idlFile ( ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > const& );
      size_t count_idlFile (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > > idlFile_;

      // configProperty
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > >::iterator configProperty_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > >::const_iterator configProperty_const_iterator;
      configProperty_iterator begin_configProperty ();
      configProperty_iterator end_configProperty ();
      configProperty_const_iterator begin_configProperty () const;
      configProperty_const_iterator end_configProperty () const;
      void add_configProperty ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > const& );
      size_t count_configProperty (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > > configProperty_;

      // port
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPortDescription, ACE_Null_Mutex > >::iterator port_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPortDescription, ACE_Null_Mutex > >::const_iterator port_const_iterator;
      port_iterator begin_port ();
      port_iterator end_port ();
      port_const_iterator begin_port () const;
      port_const_iterator end_port () const;
      void add_port ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPortDescription, ACE_Null_Mutex > const& );
      size_t count_port (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPortDescription, ACE_Null_Mutex > > port_;

      // property
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPropertyDescription, ACE_Null_Mutex > >::iterator property_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPropertyDescription, ACE_Null_Mutex > >::const_iterator property_const_iterator;
      property_iterator begin_property ();
      property_iterator end_property ();
      property_const_iterator begin_property () const;
      property_const_iterator end_property () const;
      void add_property ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPropertyDescription, ACE_Null_Mutex > const& );
      size_t count_property (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::ComponentPropertyDescription, ACE_Null_Mutex > > property_;

      // infoProperty
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > >::iterator infoProperty_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > >::const_iterator infoProperty_const_iterator;
      infoProperty_iterator begin_infoProperty ();
      infoProperty_iterator end_infoProperty ();
      infoProperty_const_iterator begin_infoProperty () const;
      infoProperty_const_iterator end_infoProperty () const;
      void add_infoProperty ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > const& );
      size_t count_infoProperty (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > > infoProperty_;

      // contentLocation
      // 
      public:
      bool contentLocation_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& contentLocation () const;
      void contentLocation (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > contentLocation_;

      // href
      // 
      public:
      bool href_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& href () const;
      ::XMLSchema::string< ACE_TCHAR >& href ();
      void href (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > href_;

      public:
      ComponentInterfaceDescription ();

      ComponentInterfaceDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ComponentInterfaceDescription (ComponentInterfaceDescription const& s);

      ComponentInterfaceDescription&
      operator= (ComponentInterfaceDescription const& s);

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
      struct XSC_XML_Handlers_Export ComponentInterfaceDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ComponentInterfaceDescription >
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
        label (Type&);

        virtual void
        label (Type const&);

        virtual void
        label_none (Type&);

        virtual void
        label_none (Type const&);

        virtual void
        UUID (Type&);

        virtual void
        UUID (Type const&);

        virtual void
        UUID_none (Type&);

        virtual void
        UUID_none (Type const&);

        virtual void
        specificType (Type&);

        virtual void
        specificType (Type const&);

        virtual void
        specificType_none (Type&);

        virtual void
        specificType_none (Type const&);

        virtual void
        supportedType (Type&);

        virtual void
        supportedType (Type const&);

        virtual void
        supportedType_pre (Type&);

        virtual void
        supportedType_pre (Type const&);

        virtual void
        supportedType_next (Type&);

        virtual void
        supportedType_next (Type const&);

        virtual void
        supportedType_post (Type&);

        virtual void
        supportedType_post (Type const&);

        virtual void
        supportedType_none (Type&);

        virtual void
        supportedType_none (Type const&);

        virtual void
        idlFile (Type&);

        virtual void
        idlFile (Type const&);

        virtual void
        idlFile_pre (Type&);

        virtual void
        idlFile_pre (Type const&);

        virtual void
        idlFile_next (Type&);

        virtual void
        idlFile_next (Type const&);

        virtual void
        idlFile_post (Type&);

        virtual void
        idlFile_post (Type const&);

        virtual void
        idlFile_none (Type&);

        virtual void
        idlFile_none (Type const&);

        virtual void
        configProperty (Type&);

        virtual void
        configProperty (Type const&);

        virtual void
        configProperty_pre (Type&);

        virtual void
        configProperty_pre (Type const&);

        virtual void
        configProperty_next (Type&);

        virtual void
        configProperty_next (Type const&);

        virtual void
        configProperty_post (Type&);

        virtual void
        configProperty_post (Type const&);

        virtual void
        configProperty_none (Type&);

        virtual void
        configProperty_none (Type const&);

        virtual void
        port (Type&);

        virtual void
        port (Type const&);

        virtual void
        port_pre (Type&);

        virtual void
        port_pre (Type const&);

        virtual void
        port_next (Type&);

        virtual void
        port_next (Type const&);

        virtual void
        port_post (Type&);

        virtual void
        port_post (Type const&);

        virtual void
        port_none (Type&);

        virtual void
        port_none (Type const&);

        virtual void
        property (Type&);

        virtual void
        property (Type const&);

        virtual void
        property_pre (Type&);

        virtual void
        property_pre (Type const&);

        virtual void
        property_next (Type&);

        virtual void
        property_next (Type const&);

        virtual void
        property_post (Type&);

        virtual void
        property_post (Type const&);

        virtual void
        property_none (Type&);

        virtual void
        property_none (Type const&);

        virtual void
        infoProperty (Type&);

        virtual void
        infoProperty (Type const&);

        virtual void
        infoProperty_pre (Type&);

        virtual void
        infoProperty_pre (Type const&);

        virtual void
        infoProperty_next (Type&);

        virtual void
        infoProperty_next (Type const&);

        virtual void
        infoProperty_post (Type&);

        virtual void
        infoProperty_post (Type const&);

        virtual void
        infoProperty_none (Type&);

        virtual void
        infoProperty_none (Type const&);

        virtual void
        contentLocation (Type&);

        virtual void
        contentLocation (Type const&);

        virtual void
        contentLocation_none (Type&);

        virtual void
        contentLocation_none (Type const&);

        virtual void
        href (Type&);

        virtual void
        href (Type const&);

        virtual void
        href_none (Type&);

        virtual void
        href_none (Type const&);

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
      struct ComponentInterfaceDescription : Traversal::ComponentInterfaceDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ComponentInterfaceDescription Type;
        ComponentInterfaceDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        virtual void 
        label (Type &o)
        {
          this->label (const_cast <Type const &> (o));
        }

        virtual void
        label (Type const&);

        virtual void 
        UUID (Type &o)
        {
          this->UUID (const_cast <Type const &> (o));
        }

        virtual void
        UUID (Type const&);

        virtual void 
        specificType (Type &o)
        {
          this->specificType (const_cast <Type const &> (o));
        }

        virtual void
        specificType (Type const&);

        virtual void 
        supportedType_pre (Type &o)
        {
          this->supportedType_pre (const_cast <Type const &> (o));
        }

        virtual void
        supportedType_pre (Type const&);

        virtual void 
        supportedType_next (Type &o)
        {
          this->supportedType_next (const_cast <Type const &> (o));
        }

        virtual void
        supportedType_next (Type const&);

        virtual void 
        supportedType_post (Type &o)
        {
          this->supportedType_post (const_cast <Type const &> (o));
        }

        virtual void
        supportedType_post (Type const&);

        virtual void 
        idlFile_pre (Type &o)
        {
          this->idlFile_pre (const_cast <Type const &> (o));
        }

        virtual void
        idlFile_pre (Type const&);

        virtual void 
        idlFile_next (Type &o)
        {
          this->idlFile_next (const_cast <Type const &> (o));
        }

        virtual void
        idlFile_next (Type const&);

        virtual void 
        idlFile_post (Type &o)
        {
          this->idlFile_post (const_cast <Type const &> (o));
        }

        virtual void
        idlFile_post (Type const&);

        virtual void 
        configProperty_pre (Type &o)
        {
          this->configProperty_pre (const_cast <Type const &> (o));
        }

        virtual void
        configProperty_pre (Type const&);

        virtual void 
        configProperty_next (Type &o)
        {
          this->configProperty_next (const_cast <Type const &> (o));
        }

        virtual void
        configProperty_next (Type const&);

        virtual void 
        configProperty_post (Type &o)
        {
          this->configProperty_post (const_cast <Type const &> (o));
        }

        virtual void
        configProperty_post (Type const&);

        virtual void 
        port_pre (Type &o)
        {
          this->port_pre (const_cast <Type const &> (o));
        }

        virtual void
        port_pre (Type const&);

        virtual void 
        port_next (Type &o)
        {
          this->port_next (const_cast <Type const &> (o));
        }

        virtual void
        port_next (Type const&);

        virtual void 
        port_post (Type &o)
        {
          this->port_post (const_cast <Type const &> (o));
        }

        virtual void
        port_post (Type const&);

        virtual void 
        property_pre (Type &o)
        {
          this->property_pre (const_cast <Type const &> (o));
        }

        virtual void
        property_pre (Type const&);

        virtual void 
        property_next (Type &o)
        {
          this->property_next (const_cast <Type const &> (o));
        }

        virtual void
        property_next (Type const&);

        virtual void 
        property_post (Type &o)
        {
          this->property_post (const_cast <Type const &> (o));
        }

        virtual void
        property_post (Type const&);

        virtual void 
        infoProperty_pre (Type &o)
        {
          this->infoProperty_pre (const_cast <Type const &> (o));
        }

        virtual void
        infoProperty_pre (Type const&);

        virtual void 
        infoProperty_next (Type &o)
        {
          this->infoProperty_next (const_cast <Type const &> (o));
        }

        virtual void
        infoProperty_next (Type const&);

        virtual void 
        infoProperty_post (Type &o)
        {
          this->infoProperty_post (const_cast <Type const &> (o));
        }

        virtual void
        infoProperty_post (Type const&);

        virtual void 
        contentLocation (Type &o)
        {
          this->contentLocation (const_cast <Type const &> (o));
        }

        virtual void
        contentLocation (Type const&);

        virtual void 
        href (Type &o)
        {
          this->href (const_cast <Type const &> (o));
        }

        virtual void
        href (Type const&);

        protected:
        ComponentInterfaceDescription ();
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

#endif // CCD_HPP
