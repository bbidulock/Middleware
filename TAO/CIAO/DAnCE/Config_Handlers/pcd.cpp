// $Id$
#include "pcd.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // PackageConfiguration
    // 

    PackageConfiguration::
    PackageConfiguration ()
    :
    regulator__ ()
    {
    }

    PackageConfiguration::
    PackageConfiguration (::CIAO::Config_Handlers::PackageConfiguration const& s)
    :
    label_ (s.label_.get () ? new ::XMLSchema::string< char > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< char > (*s.UUID_) : 0),
    basePackage_ (s.basePackage_.get () ? new ::CIAO::Config_Handlers::ComponentPackageDescription (*s.basePackage_) : 0),
    reference_ (s.reference_.get () ? new ::CIAO::Config_Handlers::ComponentPackageReference (*s.reference_) : 0),
    selectRequirement_ (s.selectRequirement_.get () ? new ::CIAO::Config_Handlers::Requirement (*s.selectRequirement_) : 0),
    configProperty_ (s.configProperty_.get () ? new ::CIAO::Config_Handlers::Property (*s.configProperty_) : 0),
    contentLocation_ (s.contentLocation_.get () ? new ::XMLSchema::string< char > (*s.contentLocation_) : 0),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      if (basePackage_.get ()) basePackage_->container (this);
      if (reference_.get ()) reference_->container (this);
      if (selectRequirement_.get ()) selectRequirement_->container (this);
      if (configProperty_.get ()) configProperty_->container (this);
      if (contentLocation_.get ()) contentLocation_->container (this);
    }

    ::CIAO::Config_Handlers::PackageConfiguration& PackageConfiguration::
    operator= (::CIAO::Config_Handlers::PackageConfiguration const& s)
    {
      if (s.label_.get ()) label (*(s.label_));
      else label_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      if (s.UUID_.get ()) UUID (*(s.UUID_));
      else UUID_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      if (s.basePackage_.get ()) basePackage (*(s.basePackage_));
      else basePackage_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageDescription > (0);

      if (s.reference_.get ()) reference (*(s.reference_));
      else reference_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageReference > (0);

      if (s.selectRequirement_.get ()) selectRequirement (*(s.selectRequirement_));
      else selectRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > (0);

      if (s.configProperty_.get ()) configProperty (*(s.configProperty_));
      else configProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      if (s.contentLocation_.get ()) contentLocation (*(s.contentLocation_));
      else contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      return *this;
    }


    // PackageConfiguration
    // 
    bool PackageConfiguration::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< char > const& PackageConfiguration::
    label () const
    {
      return *label_;
    }

    ::XMLSchema::string< char >& PackageConfiguration::
    label ()
    {
      return *label_;
    }

    void PackageConfiguration::
    label (::XMLSchema::string< char > const& e)
    {
      if (label_.get ())
      {
        *label_ = e;
      }

      else
      {
        label_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        label_->container (this);
      }
    }

    // PackageConfiguration
    // 
    bool PackageConfiguration::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< char > const& PackageConfiguration::
    UUID () const
    {
      return *UUID_;
    }

    ::XMLSchema::string< char >& PackageConfiguration::
    UUID ()
    {
      return *UUID_;
    }

    void PackageConfiguration::
    UUID (::XMLSchema::string< char > const& e)
    {
      if (UUID_.get ())
      {
        *UUID_ = e;
      }

      else
      {
        UUID_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        UUID_->container (this);
      }
    }

    // PackageConfiguration
    // 
    bool PackageConfiguration::
    basePackage_p () const
    {
      return basePackage_.get () != 0;
    }

    ::CIAO::Config_Handlers::ComponentPackageDescription const& PackageConfiguration::
    basePackage () const
    {
      return *basePackage_;
    }

    ::CIAO::Config_Handlers::ComponentPackageDescription& PackageConfiguration::
    basePackage ()
    {
      return *basePackage_;
    }

    void PackageConfiguration::
    basePackage (::CIAO::Config_Handlers::ComponentPackageDescription const& e)
    {
      if (basePackage_.get ())
      {
        *basePackage_ = e;
      }

      else
      {
        basePackage_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageDescription > (new ::CIAO::Config_Handlers::ComponentPackageDescription (e));
        basePackage_->container (this);
      }
    }

    // PackageConfiguration
    // 
    bool PackageConfiguration::
    reference_p () const
    {
      return reference_.get () != 0;
    }

    ::CIAO::Config_Handlers::ComponentPackageReference const& PackageConfiguration::
    reference () const
    {
      return *reference_;
    }

    ::CIAO::Config_Handlers::ComponentPackageReference& PackageConfiguration::
    reference ()
    {
      return *reference_;
    }

    void PackageConfiguration::
    reference (::CIAO::Config_Handlers::ComponentPackageReference const& e)
    {
      if (reference_.get ())
      {
        *reference_ = e;
      }

      else
      {
        reference_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageReference > (new ::CIAO::Config_Handlers::ComponentPackageReference (e));
        reference_->container (this);
      }
    }

    // PackageConfiguration
    // 
    bool PackageConfiguration::
    selectRequirement_p () const
    {
      return selectRequirement_.get () != 0;
    }

    ::CIAO::Config_Handlers::Requirement const& PackageConfiguration::
    selectRequirement () const
    {
      return *selectRequirement_;
    }

    ::CIAO::Config_Handlers::Requirement& PackageConfiguration::
    selectRequirement ()
    {
      return *selectRequirement_;
    }

    void PackageConfiguration::
    selectRequirement (::CIAO::Config_Handlers::Requirement const& e)
    {
      if (selectRequirement_.get ())
      {
        *selectRequirement_ = e;
      }

      else
      {
        selectRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > (new ::CIAO::Config_Handlers::Requirement (e));
        selectRequirement_->container (this);
      }
    }

    // PackageConfiguration
    // 
    bool PackageConfiguration::
    configProperty_p () const
    {
      return configProperty_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& PackageConfiguration::
    configProperty () const
    {
      return *configProperty_;
    }

    ::CIAO::Config_Handlers::Property& PackageConfiguration::
    configProperty ()
    {
      return *configProperty_;
    }

    void PackageConfiguration::
    configProperty (::CIAO::Config_Handlers::Property const& e)
    {
      if (configProperty_.get ())
      {
        *configProperty_ = e;
      }

      else
      {
        configProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        configProperty_->container (this);
      }
    }

    // PackageConfiguration
    // 
    bool PackageConfiguration::
    contentLocation_p () const
    {
      return contentLocation_.get () != 0;
    }

    ::XMLSchema::string< char > const& PackageConfiguration::
    contentLocation () const
    {
      return *contentLocation_;
    }

    ::XMLSchema::string< char >& PackageConfiguration::
    contentLocation ()
    {
      return *contentLocation_;
    }

    void PackageConfiguration::
    contentLocation (::XMLSchema::string< char > const& e)
    {
      if (contentLocation_.get ())
      {
        *contentLocation_ = e;
      }

      else
      {
        contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        contentLocation_->container (this);
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // PackageConfiguration
    //

    PackageConfiguration::
    PackageConfiguration (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "label")
        {
          ::XMLSchema::string< char > t (e);
          label (t);
        }

        else if (n == "UUID")
        {
          ::XMLSchema::string< char > t (e);
          UUID (t);
        }

        else if (n == "basePackage")
        {
          ::CIAO::Config_Handlers::ComponentPackageDescription t (e);
          basePackage (t);
        }

        else if (n == "reference")
        {
          ::CIAO::Config_Handlers::ComponentPackageReference t (e);
          reference (t);
        }

        else if (n == "selectRequirement")
        {
          ::CIAO::Config_Handlers::Requirement t (e);
          selectRequirement (t);
        }

        else if (n == "configProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          configProperty (t);
        }

        else if (n == "contentLocation")
        {
          ::XMLSchema::string< char > t (e);
          contentLocation (t);
        }

        else 
        {
        }
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include <XMLSchema/TypeInfo.hpp>

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < char > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct PackageConfigurationTypeInfoInitializer
      {
        PackageConfigurationTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (PackageConfiguration));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PackageConfigurationTypeInfoInitializer PackageConfigurationTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // PackageConfiguration
      //
      //

      void PackageConfiguration::
      traverse (Type& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.basePackage_p ()) basePackage (o);
        else basePackage_none (o);
        if (o.reference_p ()) reference (o);
        else reference_none (o);
        if (o.selectRequirement_p ()) selectRequirement (o);
        else selectRequirement_none (o);
        if (o.configProperty_p ()) configProperty (o);
        else configProperty_none (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        post (o);
      }

      void PackageConfiguration::
      traverse (Type const& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.basePackage_p ()) basePackage (o);
        else basePackage_none (o);
        if (o.reference_p ()) reference (o);
        else reference_none (o);
        if (o.selectRequirement_p ()) selectRequirement (o);
        else selectRequirement_none (o);
        if (o.configProperty_p ()) configProperty (o);
        else configProperty_none (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        post (o);
      }

      void PackageConfiguration::
      pre (Type&)
      {
      }

      void PackageConfiguration::
      pre (Type const&)
      {
      }

      void PackageConfiguration::
      label (Type& o)
      {
        dispatch (o.label ());
      }

      void PackageConfiguration::
      label (Type const& o)
      {
        dispatch (o.label ());
      }

      void PackageConfiguration::
      label_none (Type&)
      {
      }

      void PackageConfiguration::
      label_none (Type const&)
      {
      }

      void PackageConfiguration::
      UUID (Type& o)
      {
        dispatch (o.UUID ());
      }

      void PackageConfiguration::
      UUID (Type const& o)
      {
        dispatch (o.UUID ());
      }

      void PackageConfiguration::
      UUID_none (Type&)
      {
      }

      void PackageConfiguration::
      UUID_none (Type const&)
      {
      }

      void PackageConfiguration::
      basePackage (Type& o)
      {
        dispatch (o.basePackage ());
      }

      void PackageConfiguration::
      basePackage (Type const& o)
      {
        dispatch (o.basePackage ());
      }

      void PackageConfiguration::
      basePackage_none (Type&)
      {
      }

      void PackageConfiguration::
      basePackage_none (Type const&)
      {
      }

      void PackageConfiguration::
      reference (Type& o)
      {
        dispatch (o.reference ());
      }

      void PackageConfiguration::
      reference (Type const& o)
      {
        dispatch (o.reference ());
      }

      void PackageConfiguration::
      reference_none (Type&)
      {
      }

      void PackageConfiguration::
      reference_none (Type const&)
      {
      }

      void PackageConfiguration::
      selectRequirement (Type& o)
      {
        dispatch (o.selectRequirement ());
      }

      void PackageConfiguration::
      selectRequirement (Type const& o)
      {
        dispatch (o.selectRequirement ());
      }

      void PackageConfiguration::
      selectRequirement_none (Type&)
      {
      }

      void PackageConfiguration::
      selectRequirement_none (Type const&)
      {
      }

      void PackageConfiguration::
      configProperty (Type& o)
      {
        dispatch (o.configProperty ());
      }

      void PackageConfiguration::
      configProperty (Type const& o)
      {
        dispatch (o.configProperty ());
      }

      void PackageConfiguration::
      configProperty_none (Type&)
      {
      }

      void PackageConfiguration::
      configProperty_none (Type const&)
      {
      }

      void PackageConfiguration::
      contentLocation (Type& o)
      {
        dispatch (o.contentLocation ());
      }

      void PackageConfiguration::
      contentLocation (Type const& o)
      {
        dispatch (o.contentLocation ());
      }

      void PackageConfiguration::
      contentLocation_none (Type&)
      {
      }

      void PackageConfiguration::
      contentLocation_none (Type const&)
      {
      }

      void PackageConfiguration::
      post (Type&)
      {
      }

      void PackageConfiguration::
      post (Type const&)
      {
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      // PackageConfiguration
      //
      //

      PackageConfiguration::
      PackageConfiguration (::XSCRT::XML::Element< char >& e)
      : ::XSCRT::Writer< char > (e)
      {
      }

      PackageConfiguration::
      PackageConfiguration ()
      {
      }

      void PackageConfiguration::
      traverse (Type const& o)
      {
        Traversal::PackageConfiguration::traverse (o);
      }

      void PackageConfiguration::
      label (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("label", top_ ()));
        Traversal::PackageConfiguration::label (o);
        pop_ ();
      }

      void PackageConfiguration::
      UUID (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("UUID", top_ ()));
        Traversal::PackageConfiguration::UUID (o);
        pop_ ();
      }

      void PackageConfiguration::
      basePackage (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("basePackage", top_ ()));
        Traversal::PackageConfiguration::basePackage (o);
        pop_ ();
      }

      void PackageConfiguration::
      reference (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("reference", top_ ()));
        Traversal::PackageConfiguration::reference (o);
        pop_ ();
      }

      void PackageConfiguration::
      selectRequirement (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("selectRequirement", top_ ()));
        Traversal::PackageConfiguration::selectRequirement (o);
        pop_ ();
      }

      void PackageConfiguration::
      configProperty (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("configProperty", top_ ()));
        Traversal::PackageConfiguration::configProperty (o);
        pop_ ();
      }

      void PackageConfiguration::
      contentLocation (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("contentLocation", top_ ()));
        Traversal::PackageConfiguration::contentLocation (o);
        pop_ ();
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

