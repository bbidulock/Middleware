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

#include "ccd.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // ComponentInterfaceDescription
    // 

    ComponentInterfaceDescription::
    ComponentInterfaceDescription ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    ComponentInterfaceDescription::
    ComponentInterfaceDescription (::CIAO::Config_Handlers::ComponentInterfaceDescription const& s)
    :
    ::XSCRT::Type (),
    label_ (s.label_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.UUID_) : 0),
    specificType_ (s.specificType_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.specificType_) : 0),
    contentLocation_ (s.contentLocation_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.contentLocation_) : 0),
    href_ (s.href_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.href_) : 0),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      if (specificType_.get ()) specificType_->container (this);
      {
        for (supportedType_const_iterator i (s.supportedType_.begin ());i != s.supportedType_.end ();++i) add_supportedType (*i);
      }

      {
        for (idlFile_const_iterator i (s.idlFile_.begin ());i != s.idlFile_.end ();++i) add_idlFile (*i);
      }

      {
        for (configProperty_const_iterator i (s.configProperty_.begin ());i != s.configProperty_.end ();++i) add_configProperty (*i);
      }

      {
        for (port_const_iterator i (s.port_.begin ());i != s.port_.end ();++i) add_port (*i);
      }

      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      {
        for (infoProperty_const_iterator i (s.infoProperty_.begin ());i != s.infoProperty_.end ();++i) add_infoProperty (*i);
      }

      if (contentLocation_.get ()) contentLocation_->container (this);
      if (href_.get ()) href_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentInterfaceDescription& ComponentInterfaceDescription::
    operator= (::CIAO::Config_Handlers::ComponentInterfaceDescription const& s)
    {
      if (s.label_.get ()) label (*(s.label_));
      else label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.UUID_.get ()) UUID (*(s.UUID_));
      else UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.specificType_.get ()) specificType (*(s.specificType_));
      else specificType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      supportedType_.clear ();
      {
        for (supportedType_const_iterator i (s.supportedType_.begin ());i != s.supportedType_.end ();++i) add_supportedType (*i);
      }

      idlFile_.clear ();
      {
        for (idlFile_const_iterator i (s.idlFile_.begin ());i != s.idlFile_.end ();++i) add_idlFile (*i);
      }

      configProperty_.clear ();
      {
        for (configProperty_const_iterator i (s.configProperty_.begin ());i != s.configProperty_.end ();++i) add_configProperty (*i);
      }

      port_.clear ();
      {
        for (port_const_iterator i (s.port_.begin ());i != s.port_.end ();++i) add_port (*i);
      }

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      infoProperty_.clear ();
      {
        for (infoProperty_const_iterator i (s.infoProperty_.begin ());i != s.infoProperty_.end ();++i) add_infoProperty (*i);
      }

      if (s.contentLocation_.get ()) contentLocation (*(s.contentLocation_));
      else contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.href_.get ()) href (*(s.href_));
      else href_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      return *this;
    }


    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentInterfaceDescription::
    label () const
    {
      return *label_;
    }

    void ComponentInterfaceDescription::
    label (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (label_.get ())
      {
        *label_ = e;
      }

      else
      {
        label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        label_->container (this);
      }
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentInterfaceDescription::
    UUID () const
    {
      return *UUID_;
    }

    void ComponentInterfaceDescription::
    UUID (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (UUID_.get ())
      {
        *UUID_ = e;
      }

      else
      {
        UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        UUID_->container (this);
      }
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    specificType_p () const
    {
      return specificType_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentInterfaceDescription::
    specificType () const
    {
      return *specificType_;
    }

    void ComponentInterfaceDescription::
    specificType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (specificType_.get ())
      {
        *specificType_ = e;
      }

      else
      {
        specificType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        specificType_->container (this);
      }
    }

    // ComponentInterfaceDescription
    // 
    ComponentInterfaceDescription::supportedType_iterator ComponentInterfaceDescription::
    begin_supportedType ()
    {
      return supportedType_.begin ();
    }

    ComponentInterfaceDescription::supportedType_iterator ComponentInterfaceDescription::
    end_supportedType ()
    {
      return supportedType_.end ();
    }

    ComponentInterfaceDescription::supportedType_const_iterator ComponentInterfaceDescription::
    begin_supportedType () const
    {
      return supportedType_.begin ();
    }

    ComponentInterfaceDescription::supportedType_const_iterator ComponentInterfaceDescription::
    end_supportedType () const
    {
      return supportedType_.end ();
    }

    void ComponentInterfaceDescription::
    add_supportedType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      supportedType_.push_back (e);
    }

    size_t ComponentInterfaceDescription::
    count_supportedType(void) const
    {
      return supportedType_.size ();
    }

    // ComponentInterfaceDescription
    // 
    ComponentInterfaceDescription::idlFile_iterator ComponentInterfaceDescription::
    begin_idlFile ()
    {
      return idlFile_.begin ();
    }

    ComponentInterfaceDescription::idlFile_iterator ComponentInterfaceDescription::
    end_idlFile ()
    {
      return idlFile_.end ();
    }

    ComponentInterfaceDescription::idlFile_const_iterator ComponentInterfaceDescription::
    begin_idlFile () const
    {
      return idlFile_.begin ();
    }

    ComponentInterfaceDescription::idlFile_const_iterator ComponentInterfaceDescription::
    end_idlFile () const
    {
      return idlFile_.end ();
    }

    void ComponentInterfaceDescription::
    add_idlFile (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      idlFile_.push_back (e);
    }

    size_t ComponentInterfaceDescription::
    count_idlFile(void) const
    {
      return idlFile_.size ();
    }

    // ComponentInterfaceDescription
    // 
    ComponentInterfaceDescription::configProperty_iterator ComponentInterfaceDescription::
    begin_configProperty ()
    {
      return configProperty_.begin ();
    }

    ComponentInterfaceDescription::configProperty_iterator ComponentInterfaceDescription::
    end_configProperty ()
    {
      return configProperty_.end ();
    }

    ComponentInterfaceDescription::configProperty_const_iterator ComponentInterfaceDescription::
    begin_configProperty () const
    {
      return configProperty_.begin ();
    }

    ComponentInterfaceDescription::configProperty_const_iterator ComponentInterfaceDescription::
    end_configProperty () const
    {
      return configProperty_.end ();
    }

    void ComponentInterfaceDescription::
    add_configProperty (::CIAO::Config_Handlers::Property const& e)
    {
      configProperty_.push_back (e);
    }

    size_t ComponentInterfaceDescription::
    count_configProperty(void) const
    {
      return configProperty_.size ();
    }

    // ComponentInterfaceDescription
    // 
    ComponentInterfaceDescription::port_iterator ComponentInterfaceDescription::
    begin_port ()
    {
      return port_.begin ();
    }

    ComponentInterfaceDescription::port_iterator ComponentInterfaceDescription::
    end_port ()
    {
      return port_.end ();
    }

    ComponentInterfaceDescription::port_const_iterator ComponentInterfaceDescription::
    begin_port () const
    {
      return port_.begin ();
    }

    ComponentInterfaceDescription::port_const_iterator ComponentInterfaceDescription::
    end_port () const
    {
      return port_.end ();
    }

    void ComponentInterfaceDescription::
    add_port (::CIAO::Config_Handlers::ComponentPortDescription const& e)
    {
      port_.push_back (e);
    }

    size_t ComponentInterfaceDescription::
    count_port(void) const
    {
      return port_.size ();
    }

    // ComponentInterfaceDescription
    // 
    ComponentInterfaceDescription::property_iterator ComponentInterfaceDescription::
    begin_property ()
    {
      return property_.begin ();
    }

    ComponentInterfaceDescription::property_iterator ComponentInterfaceDescription::
    end_property ()
    {
      return property_.end ();
    }

    ComponentInterfaceDescription::property_const_iterator ComponentInterfaceDescription::
    begin_property () const
    {
      return property_.begin ();
    }

    ComponentInterfaceDescription::property_const_iterator ComponentInterfaceDescription::
    end_property () const
    {
      return property_.end ();
    }

    void ComponentInterfaceDescription::
    add_property (::CIAO::Config_Handlers::ComponentPropertyDescription const& e)
    {
      property_.push_back (e);
    }

    size_t ComponentInterfaceDescription::
    count_property(void) const
    {
      return property_.size ();
    }

    // ComponentInterfaceDescription
    // 
    ComponentInterfaceDescription::infoProperty_iterator ComponentInterfaceDescription::
    begin_infoProperty ()
    {
      return infoProperty_.begin ();
    }

    ComponentInterfaceDescription::infoProperty_iterator ComponentInterfaceDescription::
    end_infoProperty ()
    {
      return infoProperty_.end ();
    }

    ComponentInterfaceDescription::infoProperty_const_iterator ComponentInterfaceDescription::
    begin_infoProperty () const
    {
      return infoProperty_.begin ();
    }

    ComponentInterfaceDescription::infoProperty_const_iterator ComponentInterfaceDescription::
    end_infoProperty () const
    {
      return infoProperty_.end ();
    }

    void ComponentInterfaceDescription::
    add_infoProperty (::CIAO::Config_Handlers::Property const& e)
    {
      infoProperty_.push_back (e);
    }

    size_t ComponentInterfaceDescription::
    count_infoProperty(void) const
    {
      return infoProperty_.size ();
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    contentLocation_p () const
    {
      return contentLocation_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentInterfaceDescription::
    contentLocation () const
    {
      return *contentLocation_;
    }

    void ComponentInterfaceDescription::
    contentLocation (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (contentLocation_.get ())
      {
        *contentLocation_ = e;
      }

      else
      {
        contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        contentLocation_->container (this);
      }
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    href_p () const
    {
      return href_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentInterfaceDescription::
    href () const
    {
      return *href_;
    }

    ::XMLSchema::string< ACE_TCHAR >& ComponentInterfaceDescription::
    href ()
    {
      return *href_;
    }

    void ComponentInterfaceDescription::
    href (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (href_.get ())
      {
        *href_ = e;
      }

      else
      {
        href_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        href_->container (this);
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // ComponentInterfaceDescription
    //

    ComponentInterfaceDescription::
    ComponentInterfaceDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "label")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          label (t);
        }

        else if (n == "UUID")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          UUID (t);
        }

        else if (n == "specificType")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          specificType (t);
        }

        else if (n == "supportedType")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_supportedType (t);
        }

        else if (n == "idlFile")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_idlFile (t);
        }

        else if (n == "configProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_configProperty (t);
        }

        else if (n == "port")
        {
          ::CIAO::Config_Handlers::ComponentPortDescription t (e);
          add_port (t);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::ComponentPropertyDescription t (e);
          add_property (t);
        }

        else if (n == "infoProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_infoProperty (t);
        }

        else if (n == "contentLocation")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          contentLocation (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "href")
        {
          ::XMLSchema::string< ACE_TCHAR > t (a);
          href (t);
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

#include "XMLSchema/TypeInfo.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < ACE_TCHAR > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct ComponentInterfaceDescriptionTypeInfoInitializer
      {
        ComponentInterfaceDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ComponentInterfaceDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ComponentInterfaceDescriptionTypeInfoInitializer ComponentInterfaceDescriptionTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // ComponentInterfaceDescription
      //
      //

      void ComponentInterfaceDescription::
      traverse (Type& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.specificType_p ()) specificType (o);
        else specificType_none (o);
        supportedType (o);
        idlFile (o);
        configProperty (o);
        port (o);
        property (o);
        infoProperty (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        if (o.href_p ()) href (o);
        else href_none (o);
        post (o);
      }

      void ComponentInterfaceDescription::
      traverse (Type const& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.specificType_p ()) specificType (o);
        else specificType_none (o);
        supportedType (o);
        idlFile (o);
        configProperty (o);
        port (o);
        property (o);
        infoProperty (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        if (o.href_p ()) href (o);
        else href_none (o);
        post (o);
      }

      void ComponentInterfaceDescription::
      pre (Type&)
      {
      }

      void ComponentInterfaceDescription::
      pre (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      label (Type& o)
      {
        dispatch (o.label ());
      }

      void ComponentInterfaceDescription::
      label (Type const& o)
      {
        dispatch (o.label ());
      }

      void ComponentInterfaceDescription::
      label_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      label_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      UUID (Type& o)
      {
        dispatch (o.UUID ());
      }

      void ComponentInterfaceDescription::
      UUID (Type const& o)
      {
        dispatch (o.UUID ());
      }

      void ComponentInterfaceDescription::
      UUID_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      UUID_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      specificType (Type& o)
      {
        dispatch (o.specificType ());
      }

      void ComponentInterfaceDescription::
      specificType (Type const& o)
      {
        dispatch (o.specificType ());
      }

      void ComponentInterfaceDescription::
      specificType_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      specificType_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType (Type& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::supportedType_iterator b (o.begin_supportedType()), e (o.end_supportedType());

        if (b != e)
        {
          supportedType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) supportedType_next (o);
          }

          supportedType_post (o);
        }

        else supportedType_none (o);
      }

      void ComponentInterfaceDescription::
      supportedType (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::supportedType_const_iterator b (o.begin_supportedType()), e (o.end_supportedType());

        if (b != e)
        {
          supportedType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) supportedType_next (o);
          }

          supportedType_post (o);
        }

        else supportedType_none (o);
      }

      void ComponentInterfaceDescription::
      supportedType_pre (Type&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType_pre (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType_next (Type&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType_next (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType_post (Type&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType_post (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      supportedType_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile (Type& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::idlFile_iterator b (o.begin_idlFile()), e (o.end_idlFile());

        if (b != e)
        {
          idlFile_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) idlFile_next (o);
          }

          idlFile_post (o);
        }

        else idlFile_none (o);
      }

      void ComponentInterfaceDescription::
      idlFile (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::idlFile_const_iterator b (o.begin_idlFile()), e (o.end_idlFile());

        if (b != e)
        {
          idlFile_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) idlFile_next (o);
          }

          idlFile_post (o);
        }

        else idlFile_none (o);
      }

      void ComponentInterfaceDescription::
      idlFile_pre (Type&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile_pre (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile_next (Type&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile_next (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile_post (Type&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile_post (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      idlFile_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty (Type& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::configProperty_iterator b (o.begin_configProperty()), e (o.end_configProperty());

        if (b != e)
        {
          configProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) configProperty_next (o);
          }

          configProperty_post (o);
        }

        else configProperty_none (o);
      }

      void ComponentInterfaceDescription::
      configProperty (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::configProperty_const_iterator b (o.begin_configProperty()), e (o.end_configProperty());

        if (b != e)
        {
          configProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) configProperty_next (o);
          }

          configProperty_post (o);
        }

        else configProperty_none (o);
      }

      void ComponentInterfaceDescription::
      configProperty_pre (Type&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty_pre (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty_next (Type&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty_next (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty_post (Type&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty_post (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      configProperty_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      port (Type& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::port_iterator b (o.begin_port()), e (o.end_port());

        if (b != e)
        {
          port_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) port_next (o);
          }

          port_post (o);
        }

        else port_none (o);
      }

      void ComponentInterfaceDescription::
      port (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::port_const_iterator b (o.begin_port()), e (o.end_port());

        if (b != e)
        {
          port_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) port_next (o);
          }

          port_post (o);
        }

        else port_none (o);
      }

      void ComponentInterfaceDescription::
      port_pre (Type&)
      {
      }

      void ComponentInterfaceDescription::
      port_pre (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      port_next (Type&)
      {
      }

      void ComponentInterfaceDescription::
      port_next (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      port_post (Type&)
      {
      }

      void ComponentInterfaceDescription::
      port_post (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      port_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      port_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ComponentInterfaceDescription::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ComponentInterfaceDescription::
      property_pre (Type&)
      {
      }

      void ComponentInterfaceDescription::
      property_pre (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      property_next (Type&)
      {
      }

      void ComponentInterfaceDescription::
      property_next (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      property_post (Type&)
      {
      }

      void ComponentInterfaceDescription::
      property_post (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      property_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      property_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty (Type& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::infoProperty_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

        if (b != e)
        {
          infoProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) infoProperty_next (o);
          }

          infoProperty_post (o);
        }

        else infoProperty_none (o);
      }

      void ComponentInterfaceDescription::
      infoProperty (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ComponentInterfaceDescription::Type::infoProperty_const_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

        if (b != e)
        {
          infoProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) infoProperty_next (o);
          }

          infoProperty_post (o);
        }

        else infoProperty_none (o);
      }

      void ComponentInterfaceDescription::
      infoProperty_pre (Type&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty_pre (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty_next (Type&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty_next (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty_post (Type&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty_post (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      infoProperty_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      contentLocation (Type& o)
      {
        dispatch (o.contentLocation ());
      }

      void ComponentInterfaceDescription::
      contentLocation (Type const& o)
      {
        dispatch (o.contentLocation ());
      }

      void ComponentInterfaceDescription::
      contentLocation_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      contentLocation_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      href (Type& o)
      {
        dispatch (o.href ());
      }

      void ComponentInterfaceDescription::
      href (Type const& o)
      {
        dispatch (o.href ());
      }

      void ComponentInterfaceDescription::
      href_none (Type&)
      {
      }

      void ComponentInterfaceDescription::
      href_none (Type const&)
      {
      }

      void ComponentInterfaceDescription::
      post (Type&)
      {
      }

      void ComponentInterfaceDescription::
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
      // ComponentInterfaceDescription
      //
      //

      ComponentInterfaceDescription::
      ComponentInterfaceDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ComponentInterfaceDescription::
      ComponentInterfaceDescription ()
      {
      }

      void ComponentInterfaceDescription::
      traverse (Type const& o)
      {
        Traversal::ComponentInterfaceDescription::traverse (o);
      }

      void ComponentInterfaceDescription::
      label (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("label", top_ ()));
        Traversal::ComponentInterfaceDescription::label (o);
        pop_ ();
      }

      void ComponentInterfaceDescription::
      UUID (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("UUID", top_ ()));
        Traversal::ComponentInterfaceDescription::UUID (o);
        pop_ ();
      }

      void ComponentInterfaceDescription::
      specificType (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("specificType", top_ ()));
        Traversal::ComponentInterfaceDescription::specificType (o);
        pop_ ();
      }

      void ComponentInterfaceDescription::
      supportedType_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("supportedType", top_ ()));
      }

      void ComponentInterfaceDescription::
      supportedType_next (Type const& o)
      {
        supportedType_post (o);
        supportedType_pre (o);
      }

      void ComponentInterfaceDescription::
      supportedType_post (Type const&)
      {
        pop_ ();
      }

      void ComponentInterfaceDescription::
      idlFile_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("idlFile", top_ ()));
      }

      void ComponentInterfaceDescription::
      idlFile_next (Type const& o)
      {
        idlFile_post (o);
        idlFile_pre (o);
      }

      void ComponentInterfaceDescription::
      idlFile_post (Type const&)
      {
        pop_ ();
      }

      void ComponentInterfaceDescription::
      configProperty_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("configProperty", top_ ()));
      }

      void ComponentInterfaceDescription::
      configProperty_next (Type const& o)
      {
        configProperty_post (o);
        configProperty_pre (o);
      }

      void ComponentInterfaceDescription::
      configProperty_post (Type const&)
      {
        pop_ ();
      }

      void ComponentInterfaceDescription::
      port_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("port", top_ ()));
      }

      void ComponentInterfaceDescription::
      port_next (Type const& o)
      {
        port_post (o);
        port_pre (o);
      }

      void ComponentInterfaceDescription::
      port_post (Type const&)
      {
        pop_ ();
      }

      void ComponentInterfaceDescription::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void ComponentInterfaceDescription::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void ComponentInterfaceDescription::
      property_post (Type const&)
      {
        pop_ ();
      }

      void ComponentInterfaceDescription::
      infoProperty_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("infoProperty", top_ ()));
      }

      void ComponentInterfaceDescription::
      infoProperty_next (Type const& o)
      {
        infoProperty_post (o);
        infoProperty_pre (o);
      }

      void ComponentInterfaceDescription::
      infoProperty_post (Type const&)
      {
        pop_ ();
      }

      void ComponentInterfaceDescription::
      contentLocation (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("contentLocation", top_ ()));
        Traversal::ComponentInterfaceDescription::contentLocation (o);
        pop_ ();
      }

      void ComponentInterfaceDescription::
      href (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("href", "", top_ ());
        attr_ (&a);
        Traversal::ComponentInterfaceDescription::href (o);
        attr_ (0);
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

