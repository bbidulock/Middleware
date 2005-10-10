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
#ifndef CID_HPP
#define CID_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class SubcomponentInstantiationDescription;
    class SubcomponentPropertyReference;
    class AssemblyPropertyMapping;
    class ComponentAssemblyDescription;
    class MonolithicImplementationDescription;
    class ComponentImplementationDescription;
  }
}

#include <memory>
#include <vector>
#include "XMLSchema/Types.hpp"

#include "Basic_Deployment_Data.hpp"

#include "cpd.hpp"

#include "iad.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export SubcomponentInstantiationDescription : public ::XSCRT::Type
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

      // package
      // 
      public:
      ::CIAO::Config_Handlers::ComponentPackageDescription const& package () const;
      void package (::CIAO::Config_Handlers::ComponentPackageDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageDescription > package_;

      // configProperty
      // 
      public:
      bool configProperty_p () const;
      ::CIAO::Config_Handlers::Property const& configProperty () const;
      void configProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > configProperty_;

      // selectRequirement
      // 
      public:
      bool selectRequirement_p () const;
      ::CIAO::Config_Handlers::Requirement const& selectRequirement () const;
      void selectRequirement (::CIAO::Config_Handlers::Requirement const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > selectRequirement_;

      // reference
      // 
      public:
      bool reference_p () const;
      ::CIAO::Config_Handlers::ComponentPackageReference const& reference () const;
      void reference (::CIAO::Config_Handlers::ComponentPackageReference const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageReference > reference_;

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
      SubcomponentInstantiationDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
      ::CIAO::Config_Handlers::ComponentPackageDescription const& package__);

      SubcomponentInstantiationDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      SubcomponentInstantiationDescription (SubcomponentInstantiationDescription const& s);

      SubcomponentInstantiationDescription&
      operator= (SubcomponentInstantiationDescription const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export SubcomponentPropertyReference : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // propertyName
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& propertyName () const;
      void propertyName (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > propertyName_;

      // instance
      // 
      public:
      ::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& instance () const;
      void instance (::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::SubcomponentInstantiationDescription > instance_;

      public:
      SubcomponentPropertyReference (::XMLSchema::string< ACE_TCHAR > const& propertyName__,
      ::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& instance__);

      SubcomponentPropertyReference (::XSCRT::XML::Element< ACE_TCHAR > const&);
      SubcomponentPropertyReference (SubcomponentPropertyReference const& s);

      SubcomponentPropertyReference&
      operator= (SubcomponentPropertyReference const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export AssemblyPropertyMapping : public ::XSCRT::Type
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

      // externalName
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& externalName () const;
      void externalName (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > externalName_;

      // delegatesTo
      // 
      public:
      ::CIAO::Config_Handlers::SubcomponentPropertyReference const& delegatesTo () const;
      void delegatesTo (::CIAO::Config_Handlers::SubcomponentPropertyReference const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::SubcomponentPropertyReference > delegatesTo_;

      public:
      AssemblyPropertyMapping (::XMLSchema::string< ACE_TCHAR > const& name__,
      ::XMLSchema::string< ACE_TCHAR > const& externalName__,
      ::CIAO::Config_Handlers::SubcomponentPropertyReference const& delegatesTo__);

      AssemblyPropertyMapping (::XSCRT::XML::Element< ACE_TCHAR > const&);
      AssemblyPropertyMapping (AssemblyPropertyMapping const& s);

      AssemblyPropertyMapping&
      operator= (AssemblyPropertyMapping const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export ComponentAssemblyDescription : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // instance
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::SubcomponentInstantiationDescription >::iterator instance_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::SubcomponentInstantiationDescription >::const_iterator instance_const_iterator;
      instance_iterator begin_instance ();
      instance_iterator end_instance ();
      instance_const_iterator begin_instance () const;
      instance_const_iterator end_instance () const;
      void add_instance (::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& );
      size_t count_instance (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::SubcomponentInstantiationDescription > instance_;

      // connection
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::AssemblyConnectionDescription >::iterator connection_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::AssemblyConnectionDescription >::const_iterator connection_const_iterator;
      connection_iterator begin_connection ();
      connection_iterator end_connection ();
      connection_const_iterator begin_connection () const;
      connection_const_iterator end_connection () const;
      void add_connection (::CIAO::Config_Handlers::AssemblyConnectionDescription const& );
      size_t count_connection (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::AssemblyConnectionDescription > connection_;

      // externalProperty
      // 
      public:
      bool externalProperty_p () const;
      ::CIAO::Config_Handlers::AssemblyPropertyMapping const& externalProperty () const;
      void externalProperty (::CIAO::Config_Handlers::AssemblyPropertyMapping const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::AssemblyPropertyMapping > externalProperty_;

      public:
      ComponentAssemblyDescription ();

      ComponentAssemblyDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ComponentAssemblyDescription (ComponentAssemblyDescription const& s);

      ComponentAssemblyDescription&
      operator= (ComponentAssemblyDescription const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export MonolithicImplementationDescription : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // execParameter
      // 
      public:
      bool execParameter_p () const;
      ::CIAO::Config_Handlers::Property const& execParameter () const;
      void execParameter (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > execParameter_;

      // primaryArtifact
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::NamedImplementationArtifact >::iterator primaryArtifact_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::NamedImplementationArtifact >::const_iterator primaryArtifact_const_iterator;
      primaryArtifact_iterator begin_primaryArtifact ();
      primaryArtifact_iterator end_primaryArtifact ();
      primaryArtifact_const_iterator begin_primaryArtifact () const;
      primaryArtifact_const_iterator end_primaryArtifact () const;
      void add_primaryArtifact (::CIAO::Config_Handlers::NamedImplementationArtifact const& );
      size_t count_primaryArtifact (void) const;

      protected:
      ::std::vector< ::CIAO::Config_Handlers::NamedImplementationArtifact > primaryArtifact_;

      // deployRequirement
      // 
      public:
      bool deployRequirement_p () const;
      ::CIAO::Config_Handlers::ImplementationRequirement const& deployRequirement () const;
      void deployRequirement (::CIAO::Config_Handlers::ImplementationRequirement const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationRequirement > deployRequirement_;

      public:
      MonolithicImplementationDescription ();

      MonolithicImplementationDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      MonolithicImplementationDescription (MonolithicImplementationDescription const& s);

      MonolithicImplementationDescription&
      operator= (MonolithicImplementationDescription const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export ComponentImplementationDescription : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

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

      // implements
      // 
      public:
      bool implements_p () const;
      ::CIAO::Config_Handlers::ComponentInterfaceDescription const& implements () const;
      void implements (::CIAO::Config_Handlers::ComponentInterfaceDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > implements_;

      // assemblyImpl
      // 
      public:
      bool assemblyImpl_p () const;
      ::CIAO::Config_Handlers::ComponentAssemblyDescription const& assemblyImpl () const;
      void assemblyImpl (::CIAO::Config_Handlers::ComponentAssemblyDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentAssemblyDescription > assemblyImpl_;

      // monolithicImpl
      // 
      public:
      bool monolithicImpl_p () const;
      ::CIAO::Config_Handlers::MonolithicImplementationDescription const& monolithicImpl () const;
      void monolithicImpl (::CIAO::Config_Handlers::MonolithicImplementationDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::MonolithicImplementationDescription > monolithicImpl_;

      // configProperty
      // 
      public:
      bool configProperty_p () const;
      ::CIAO::Config_Handlers::Property const& configProperty () const;
      void configProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > configProperty_;

      // capability
      // 
      public:
      bool capability_p () const;
      ::CIAO::Config_Handlers::Capability const& capability () const;
      void capability (::CIAO::Config_Handlers::Capability const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Capability > capability_;

      // dependsOn
      // 
      public:
      bool dependsOn_p () const;
      ::CIAO::Config_Handlers::ImplementationDependency const& dependsOn () const;
      void dependsOn (::CIAO::Config_Handlers::ImplementationDependency const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationDependency > dependsOn_;

      // infoProperty
      // 
      public:
      bool infoProperty_p () const;
      ::CIAO::Config_Handlers::Property const& infoProperty () const;
      void infoProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > infoProperty_;

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
      ComponentImplementationDescription ();

      ComponentImplementationDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ComponentImplementationDescription (ComponentImplementationDescription const& s);

      ComponentImplementationDescription&
      operator= (ComponentImplementationDescription const& s);

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
      struct XSC_XML_Handlers_Export SubcomponentInstantiationDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::SubcomponentInstantiationDescription >
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
        package (Type&);

        virtual void
        package (Type const&);

        virtual void
        configProperty (Type&);

        virtual void
        configProperty (Type const&);

        virtual void
        configProperty_none (Type&);

        virtual void
        configProperty_none (Type const&);

        virtual void
        selectRequirement (Type&);

        virtual void
        selectRequirement (Type const&);

        virtual void
        selectRequirement_none (Type&);

        virtual void
        selectRequirement_none (Type const&);

        virtual void
        reference (Type&);

        virtual void
        reference (Type const&);

        virtual void
        reference_none (Type&);

        virtual void
        reference_none (Type const&);

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

      struct XSC_XML_Handlers_Export SubcomponentPropertyReference : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::SubcomponentPropertyReference >
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
        propertyName (Type&);

        virtual void
        propertyName (Type const&);

        virtual void
        instance (Type&);

        virtual void
        instance (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export AssemblyPropertyMapping : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::AssemblyPropertyMapping >
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
        externalName (Type&);

        virtual void
        externalName (Type const&);

        virtual void
        delegatesTo (Type&);

        virtual void
        delegatesTo (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export ComponentAssemblyDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ComponentAssemblyDescription >
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
        instance (Type&);

        virtual void
        instance (Type const&);

        virtual void
        instance_pre (Type&);

        virtual void
        instance_pre (Type const&);

        virtual void
        instance_next (Type&);

        virtual void
        instance_next (Type const&);

        virtual void
        instance_post (Type&);

        virtual void
        instance_post (Type const&);

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
        externalProperty (Type&);

        virtual void
        externalProperty (Type const&);

        virtual void
        externalProperty_none (Type&);

        virtual void
        externalProperty_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export MonolithicImplementationDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::MonolithicImplementationDescription >
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
        execParameter (Type&);

        virtual void
        execParameter (Type const&);

        virtual void
        execParameter_none (Type&);

        virtual void
        execParameter_none (Type const&);

        virtual void
        primaryArtifact (Type&);

        virtual void
        primaryArtifact (Type const&);

        virtual void
        primaryArtifact_pre (Type&);

        virtual void
        primaryArtifact_pre (Type const&);

        virtual void
        primaryArtifact_next (Type&);

        virtual void
        primaryArtifact_next (Type const&);

        virtual void
        primaryArtifact_post (Type&);

        virtual void
        primaryArtifact_post (Type const&);

        virtual void
        deployRequirement (Type&);

        virtual void
        deployRequirement (Type const&);

        virtual void
        deployRequirement_none (Type&);

        virtual void
        deployRequirement_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export ComponentImplementationDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ComponentImplementationDescription >
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
        implements (Type&);

        virtual void
        implements (Type const&);

        virtual void
        implements_none (Type&);

        virtual void
        implements_none (Type const&);

        virtual void
        assemblyImpl (Type&);

        virtual void
        assemblyImpl (Type const&);

        virtual void
        assemblyImpl_none (Type&);

        virtual void
        assemblyImpl_none (Type const&);

        virtual void
        monolithicImpl (Type&);

        virtual void
        monolithicImpl (Type const&);

        virtual void
        monolithicImpl_none (Type&);

        virtual void
        monolithicImpl_none (Type const&);

        virtual void
        configProperty (Type&);

        virtual void
        configProperty (Type const&);

        virtual void
        configProperty_none (Type&);

        virtual void
        configProperty_none (Type const&);

        virtual void
        capability (Type&);

        virtual void
        capability (Type const&);

        virtual void
        capability_none (Type&);

        virtual void
        capability_none (Type const&);

        virtual void
        dependsOn (Type&);

        virtual void
        dependsOn (Type const&);

        virtual void
        dependsOn_none (Type&);

        virtual void
        dependsOn_none (Type const&);

        virtual void
        infoProperty (Type&);

        virtual void
        infoProperty (Type const&);

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
      struct XSC_XML_Handlers_Export SubcomponentInstantiationDescription : Traversal::SubcomponentInstantiationDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::SubcomponentInstantiationDescription Type;
        SubcomponentInstantiationDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        package (Type &o)
        {

          this->package (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        package (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        configProperty (Type &o)
        {

          this->configProperty (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        configProperty (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        selectRequirement (Type &o)
        {

          this->selectRequirement (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        selectRequirement (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        reference (Type &o)
        {

          this->reference (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        reference (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        id (Type const&);

        protected:
        SubcomponentInstantiationDescription ();
      };

      struct XSC_XML_Handlers_Export SubcomponentPropertyReference : Traversal::SubcomponentPropertyReference, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::SubcomponentPropertyReference Type;
        SubcomponentPropertyReference (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        propertyName (Type &o)
        {

          this->propertyName (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        propertyName (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        instance (Type &o)
        {

          this->instance (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        instance (Type const&);

        protected:
        SubcomponentPropertyReference ();
      };

      struct XSC_XML_Handlers_Export AssemblyPropertyMapping : Traversal::AssemblyPropertyMapping, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::AssemblyPropertyMapping Type;
        AssemblyPropertyMapping (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        externalName (Type &o)
        {

          this->externalName (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        externalName (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        delegatesTo (Type &o)
        {

          this->delegatesTo (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        delegatesTo (Type const&);

        protected:
        AssemblyPropertyMapping ();
      };

      struct XSC_XML_Handlers_Export ComponentAssemblyDescription : Traversal::ComponentAssemblyDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ComponentAssemblyDescription Type;
        ComponentAssemblyDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        instance_pre (Type &o)
        {

          this->instance_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        instance_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        instance_next (Type &o)
        {

          this->instance_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        instance_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        instance_post (Type &o)
        {

          this->instance_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        instance_post (Type const&);

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
        externalProperty (Type &o)
        {

          this->externalProperty (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        externalProperty (Type const&);

        protected:
        ComponentAssemblyDescription ();
      };

      struct XSC_XML_Handlers_Export MonolithicImplementationDescription : Traversal::MonolithicImplementationDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::MonolithicImplementationDescription Type;
        MonolithicImplementationDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        execParameter (Type &o)
        {

          this->execParameter (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        execParameter (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        primaryArtifact_pre (Type &o)
        {

          this->primaryArtifact_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        primaryArtifact_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        primaryArtifact_next (Type &o)
        {

          this->primaryArtifact_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        primaryArtifact_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        primaryArtifact_post (Type &o)
        {

          this->primaryArtifact_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        primaryArtifact_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        deployRequirement (Type &o)
        {

          this->deployRequirement (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        deployRequirement (Type const&);

        protected:
        MonolithicImplementationDescription ();
      };

      struct XSC_XML_Handlers_Export ComponentImplementationDescription : Traversal::ComponentImplementationDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ComponentImplementationDescription Type;
        ComponentImplementationDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        implements (Type &o)
        {

          this->implements (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        implements (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        assemblyImpl (Type &o)
        {

          this->assemblyImpl (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        assemblyImpl (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        monolithicImpl (Type &o)
        {

          this->monolithicImpl (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        monolithicImpl (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        configProperty (Type &o)
        {

          this->configProperty (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        configProperty (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        capability (Type &o)
        {

          this->capability (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        capability (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        dependsOn (Type &o)
        {

          this->dependsOn (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        dependsOn (Type const&);

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

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        contentLocation (Type &o)
        {

          this->contentLocation (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        contentLocation (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        href (Type &o)
        {

          this->href (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        href (Type const&);

        protected:
        ComponentImplementationDescription ();
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

#endif // CID_HPP
