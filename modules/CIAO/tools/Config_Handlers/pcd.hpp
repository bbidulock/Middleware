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

#ifndef PCD_HPP
#define PCD_HPP

#include "XSC_XML_Handlers_Export.h"
// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class ComponentPackageImport;
    class PackageConfiguration;
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

#include "cpd.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export ComponentPackageImport : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      public:
      typedef ACE_Refcounted_Auto_Ptr < ComponentPackageImport, ACE_Null_Mutex > _ptr;

      // location
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > >::iterator location_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > >::const_iterator location_const_iterator;
      location_iterator begin_location ();
      location_iterator end_location ();
      location_const_iterator begin_location () const;
      location_const_iterator end_location () const;
      void add_location ( ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > const& );
      size_t count_location (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex > > location_;

      public:
      ComponentPackageImport ();

      ComponentPackageImport (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ComponentPackageImport (ComponentPackageImport const& s);

      ComponentPackageImport&
      operator= (ComponentPackageImport const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export PackageConfiguration : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      public:
      typedef ACE_Refcounted_Auto_Ptr < PackageConfiguration, ACE_Null_Mutex > _ptr;

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

      // basePackage
      // 
      public:
      bool basePackage_p () const;
      ::CIAO::Config_Handlers::ComponentPackageDescription const& basePackage () const;
      void basePackage (::CIAO::Config_Handlers::ComponentPackageDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageDescription > basePackage_;

      // specializedConfig
      // 
      public:
      bool specializedConfig_p () const;
      ::CIAO::Config_Handlers::PackageConfiguration const& specializedConfig () const;
      void specializedConfig (::CIAO::Config_Handlers::PackageConfiguration const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::PackageConfiguration > specializedConfig_;

      // importedPackage
      // 
      public:
      bool importedPackage_p () const;
      ::CIAO::Config_Handlers::ComponentPackageImport const& importedPackage () const;
      void importedPackage (::CIAO::Config_Handlers::ComponentPackageImport const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageImport > importedPackage_;

      // referencedPackage
      // 
      public:
      bool referencedPackage_p () const;
      ::CIAO::Config_Handlers::ComponentPackageReference const& referencedPackage () const;
      void referencedPackage (::CIAO::Config_Handlers::ComponentPackageReference const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageReference > referencedPackage_;

      // selectRequirement
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > >::iterator selectRequirement_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > >::const_iterator selectRequirement_const_iterator;
      selectRequirement_iterator begin_selectRequirement ();
      selectRequirement_iterator end_selectRequirement ();
      selectRequirement_const_iterator begin_selectRequirement () const;
      selectRequirement_const_iterator end_selectRequirement () const;
      void add_selectRequirement ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > const& );
      size_t count_selectRequirement (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > > selectRequirement_;

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

      // contentLocation
      // 
      public:
      bool contentLocation_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& contentLocation () const;
      void contentLocation (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > contentLocation_;

      public:
      PackageConfiguration ();

      PackageConfiguration (::XSCRT::XML::Element< ACE_TCHAR > const&);
      PackageConfiguration (PackageConfiguration const& s);

      PackageConfiguration&
      operator= (PackageConfiguration const& s);

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
      struct XSC_XML_Handlers_Export ComponentPackageImport : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ComponentPackageImport >
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
        location (Type&);

        virtual void
        location (Type const&);

        virtual void
        location_pre (Type&);

        virtual void
        location_pre (Type const&);

        virtual void
        location_next (Type&);

        virtual void
        location_next (Type const&);

        virtual void
        location_post (Type&);

        virtual void
        location_post (Type const&);

        virtual void
        location_none (Type&);

        virtual void
        location_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export PackageConfiguration : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::PackageConfiguration >
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
        basePackage (Type&);

        virtual void
        basePackage (Type const&);

        virtual void
        basePackage_none (Type&);

        virtual void
        basePackage_none (Type const&);

        virtual void
        specializedConfig (Type&);

        virtual void
        specializedConfig (Type const&);

        virtual void
        specializedConfig_none (Type&);

        virtual void
        specializedConfig_none (Type const&);

        virtual void
        importedPackage (Type&);

        virtual void
        importedPackage (Type const&);

        virtual void
        importedPackage_none (Type&);

        virtual void
        importedPackage_none (Type const&);

        virtual void
        referencedPackage (Type&);

        virtual void
        referencedPackage (Type const&);

        virtual void
        referencedPackage_none (Type&);

        virtual void
        referencedPackage_none (Type const&);

        virtual void
        selectRequirement (Type&);

        virtual void
        selectRequirement (Type const&);

        virtual void
        selectRequirement_pre (Type&);

        virtual void
        selectRequirement_pre (Type const&);

        virtual void
        selectRequirement_next (Type&);

        virtual void
        selectRequirement_next (Type const&);

        virtual void
        selectRequirement_post (Type&);

        virtual void
        selectRequirement_post (Type const&);

        virtual void
        selectRequirement_none (Type&);

        virtual void
        selectRequirement_none (Type const&);

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
        contentLocation (Type&);

        virtual void
        contentLocation (Type const&);

        virtual void
        contentLocation_none (Type&);

        virtual void
        contentLocation_none (Type const&);

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
      struct ComponentPackageImport : Traversal::ComponentPackageImport, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ComponentPackageImport Type;
        ComponentPackageImport (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        virtual void 
        location_pre (Type &o)
        {
          this->location_pre (const_cast <Type const &> (o));
        }

        virtual void
        location_pre (Type const&);

        virtual void 
        location_next (Type &o)
        {
          this->location_next (const_cast <Type const &> (o));
        }

        virtual void
        location_next (Type const&);

        virtual void 
        location_post (Type &o)
        {
          this->location_post (const_cast <Type const &> (o));
        }

        virtual void
        location_post (Type const&);

        protected:
        ComponentPackageImport ();
      };

      struct PackageConfiguration : Traversal::PackageConfiguration, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::PackageConfiguration Type;
        PackageConfiguration (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        basePackage (Type &o)
        {
          this->basePackage (const_cast <Type const &> (o));
        }

        virtual void
        basePackage (Type const&);

        virtual void 
        specializedConfig (Type &o)
        {
          this->specializedConfig (const_cast <Type const &> (o));
        }

        virtual void
        specializedConfig (Type const&);

        virtual void 
        importedPackage (Type &o)
        {
          this->importedPackage (const_cast <Type const &> (o));
        }

        virtual void
        importedPackage (Type const&);

        virtual void 
        referencedPackage (Type &o)
        {
          this->referencedPackage (const_cast <Type const &> (o));
        }

        virtual void
        referencedPackage (Type const&);

        virtual void 
        selectRequirement_pre (Type &o)
        {
          this->selectRequirement_pre (const_cast <Type const &> (o));
        }

        virtual void
        selectRequirement_pre (Type const&);

        virtual void 
        selectRequirement_next (Type &o)
        {
          this->selectRequirement_next (const_cast <Type const &> (o));
        }

        virtual void
        selectRequirement_next (Type const&);

        virtual void 
        selectRequirement_post (Type &o)
        {
          this->selectRequirement_post (const_cast <Type const &> (o));
        }

        virtual void
        selectRequirement_post (Type const&);

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
        contentLocation (Type &o)
        {
          this->contentLocation (const_cast <Type const &> (o));
        }

        virtual void
        contentLocation (Type const&);

        protected:
        PackageConfiguration ();
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

#endif // PCD_HPP
