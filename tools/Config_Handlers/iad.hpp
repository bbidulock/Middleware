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

#ifndef IAD_HPP
#define IAD_HPP

#include "XSC_XML_Handlers_Export.h"
// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class NamedImplementationArtifact;
    class ImplementationArtifactDescription;
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
    class XSC_XML_Handlers_Export NamedImplementationArtifact : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      public:
      typedef ACE_Refcounted_Auto_Ptr < NamedImplementationArtifact, ACE_Null_Mutex > _ptr;

      // name
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // referencedArtifact
      // 
      public:
      ::CIAO::Config_Handlers::ImplementationArtifactDescription const& referencedArtifact () const;
      void referencedArtifact (::CIAO::Config_Handlers::ImplementationArtifactDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationArtifactDescription > referencedArtifact_;

      public:
      NamedImplementationArtifact (::XMLSchema::string< ACE_TCHAR > const& name__,
                                   ::CIAO::Config_Handlers::ImplementationArtifactDescription const& referencedArtifact__);

      NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR > const&);
      NamedImplementationArtifact (NamedImplementationArtifact const& s);

      NamedImplementationArtifact&
      operator= (NamedImplementationArtifact const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export ImplementationArtifactDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      public:
      typedef ACE_Refcounted_Auto_Ptr < ImplementationArtifactDescription, ACE_Null_Mutex > _ptr;

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

      // dependsOn
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::NamedImplementationArtifact, ACE_Null_Mutex > >::iterator dependsOn_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::NamedImplementationArtifact, ACE_Null_Mutex > >::const_iterator dependsOn_const_iterator;
      dependsOn_iterator begin_dependsOn ();
      dependsOn_iterator end_dependsOn ();
      dependsOn_const_iterator begin_dependsOn () const;
      dependsOn_const_iterator end_dependsOn () const;
      void add_dependsOn ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::NamedImplementationArtifact, ACE_Null_Mutex > const& );
      size_t count_dependsOn (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::NamedImplementationArtifact, ACE_Null_Mutex > > dependsOn_;

      // execParameter
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > >::iterator execParameter_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > >::const_iterator execParameter_const_iterator;
      execParameter_iterator begin_execParameter ();
      execParameter_iterator end_execParameter ();
      execParameter_const_iterator begin_execParameter () const;
      execParameter_const_iterator end_execParameter () const;
      void add_execParameter ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > const& );
      size_t count_execParameter (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Property, ACE_Null_Mutex > > execParameter_;

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

      // deployRequirement
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > >::iterator deployRequirement_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > >::const_iterator deployRequirement_const_iterator;
      deployRequirement_iterator begin_deployRequirement ();
      deployRequirement_iterator end_deployRequirement ();
      deployRequirement_const_iterator begin_deployRequirement () const;
      deployRequirement_const_iterator end_deployRequirement () const;
      void add_deployRequirement ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > const& );
      size_t count_deployRequirement (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::Requirement, ACE_Null_Mutex > > deployRequirement_;

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
      ImplementationArtifactDescription ();

      ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ImplementationArtifactDescription (ImplementationArtifactDescription const& s);

      ImplementationArtifactDescription&
      operator= (ImplementationArtifactDescription const& s);

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
      struct XSC_XML_Handlers_Export NamedImplementationArtifact : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::NamedImplementationArtifact >
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
        referencedArtifact (Type&);

        virtual void
        referencedArtifact (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export ImplementationArtifactDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ImplementationArtifactDescription >
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
        dependsOn (Type&);

        virtual void
        dependsOn (Type const&);

        virtual void
        dependsOn_pre (Type&);

        virtual void
        dependsOn_pre (Type const&);

        virtual void
        dependsOn_next (Type&);

        virtual void
        dependsOn_next (Type const&);

        virtual void
        dependsOn_post (Type&);

        virtual void
        dependsOn_post (Type const&);

        virtual void
        dependsOn_none (Type&);

        virtual void
        dependsOn_none (Type const&);

        virtual void
        execParameter (Type&);

        virtual void
        execParameter (Type const&);

        virtual void
        execParameter_pre (Type&);

        virtual void
        execParameter_pre (Type const&);

        virtual void
        execParameter_next (Type&);

        virtual void
        execParameter_next (Type const&);

        virtual void
        execParameter_post (Type&);

        virtual void
        execParameter_post (Type const&);

        virtual void
        execParameter_none (Type&);

        virtual void
        execParameter_none (Type const&);

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
        deployRequirement (Type&);

        virtual void
        deployRequirement (Type const&);

        virtual void
        deployRequirement_pre (Type&);

        virtual void
        deployRequirement_pre (Type const&);

        virtual void
        deployRequirement_next (Type&);

        virtual void
        deployRequirement_next (Type const&);

        virtual void
        deployRequirement_post (Type&);

        virtual void
        deployRequirement_post (Type const&);

        virtual void
        deployRequirement_none (Type&);

        virtual void
        deployRequirement_none (Type const&);

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
      struct NamedImplementationArtifact : Traversal::NamedImplementationArtifact, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::NamedImplementationArtifact Type;
        NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        referencedArtifact (Type &o)
        {
          this->referencedArtifact (const_cast <Type const &> (o));
        }

        virtual void
        referencedArtifact (Type const&);

        protected:
        NamedImplementationArtifact ();
      };

      struct ImplementationArtifactDescription : Traversal::ImplementationArtifactDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ImplementationArtifactDescription Type;
        ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

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

        virtual void 
        dependsOn_pre (Type &o)
        {
          this->dependsOn_pre (const_cast <Type const &> (o));
        }

        virtual void
        dependsOn_pre (Type const&);

        virtual void 
        dependsOn_next (Type &o)
        {
          this->dependsOn_next (const_cast <Type const &> (o));
        }

        virtual void
        dependsOn_next (Type const&);

        virtual void 
        dependsOn_post (Type &o)
        {
          this->dependsOn_post (const_cast <Type const &> (o));
        }

        virtual void
        dependsOn_post (Type const&);

        virtual void 
        execParameter_pre (Type &o)
        {
          this->execParameter_pre (const_cast <Type const &> (o));
        }

        virtual void
        execParameter_pre (Type const&);

        virtual void 
        execParameter_next (Type &o)
        {
          this->execParameter_next (const_cast <Type const &> (o));
        }

        virtual void
        execParameter_next (Type const&);

        virtual void 
        execParameter_post (Type &o)
        {
          this->execParameter_post (const_cast <Type const &> (o));
        }

        virtual void
        execParameter_post (Type const&);

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
        deployRequirement_pre (Type &o)
        {
          this->deployRequirement_pre (const_cast <Type const &> (o));
        }

        virtual void
        deployRequirement_pre (Type const&);

        virtual void 
        deployRequirement_next (Type &o)
        {
          this->deployRequirement_next (const_cast <Type const &> (o));
        }

        virtual void
        deployRequirement_next (Type const&);

        virtual void 
        deployRequirement_post (Type &o)
        {
          this->deployRequirement_post (const_cast <Type const &> (o));
        }

        virtual void
        deployRequirement_post (Type const&);

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
        ImplementationArtifactDescription ();
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

#endif // IAD_HPP
