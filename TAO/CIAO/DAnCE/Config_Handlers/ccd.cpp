// $Id$
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
    regulator__ ()
    {
    }

    ComponentInterfaceDescription::
    ComponentInterfaceDescription (::CIAO::Config_Handlers::ComponentInterfaceDescription const& s)
    :
    label_ (s.label_.get () ? new ::XMLSchema::string< char > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< char > (*s.UUID_) : 0),
    specificType_ (s.specificType_.get () ? new ::XMLSchema::string< char > (*s.specificType_) : 0),
    idlFile_ (s.idlFile_.get () ? new ::XMLSchema::string< char > (*s.idlFile_) : 0),
    property_ (s.property_.get () ? new ::CIAO::Config_Handlers::ComponentPropertyDescription (*s.property_) : 0),
    infoProperty_ (s.infoProperty_.get () ? new ::CIAO::Config_Handlers::Property (*s.infoProperty_) : 0),
    contentLocation_ (s.contentLocation_.get () ? new ::XMLSchema::string< char > (*s.contentLocation_) : 0),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      if (specificType_.get ()) specificType_->container (this);
      supportedType_.reserve (s.supportedType_.size ());
      {
        for (supportedType_const_iterator i (s.supportedType_.begin ());
        i != s.supportedType_.end ();
        ++i) add_supportedType (*i);
      }

      if (idlFile_.get ()) idlFile_->container (this);
      configProperty_.reserve (s.configProperty_.size ());
      {
        for (configProperty_const_iterator i (s.configProperty_.begin ());
        i != s.configProperty_.end ();
        ++i) add_configProperty (*i);
      }

      port_.reserve (s.port_.size ());
      {
        for (port_const_iterator i (s.port_.begin ());
        i != s.port_.end ();
        ++i) add_port (*i);
      }

      if (property_.get ()) property_->container (this);
      if (infoProperty_.get ()) infoProperty_->container (this);
      if (contentLocation_.get ()) contentLocation_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentInterfaceDescription& ComponentInterfaceDescription::
    operator= (::CIAO::Config_Handlers::ComponentInterfaceDescription const& s)
    {
      if (s.label_.get ()) label (*(s.label_));
      else label_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      if (s.UUID_.get ()) UUID (*(s.UUID_));
      else UUID_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      if (s.specificType_.get ()) specificType (*(s.specificType_));
      else specificType_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      supportedType_.clear ();
      supportedType_.reserve (s.supportedType_.size ());
      {
        for (supportedType_const_iterator i (s.supportedType_.begin ());
        i != s.supportedType_.end ();
        ++i) add_supportedType (*i);
      }

      if (s.idlFile_.get ()) idlFile (*(s.idlFile_));
      else idlFile_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      configProperty_.clear ();
      configProperty_.reserve (s.configProperty_.size ());
      {
        for (configProperty_const_iterator i (s.configProperty_.begin ());
        i != s.configProperty_.end ();
        ++i) add_configProperty (*i);
      }

      port_.clear ();
      port_.reserve (s.port_.size ());
      {
        for (port_const_iterator i (s.port_.begin ());
        i != s.port_.end ();
        ++i) add_port (*i);
      }

      if (s.property_.get ()) property (*(s.property_));
      else property_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPropertyDescription > (0);

      if (s.infoProperty_.get ()) infoProperty (*(s.infoProperty_));
      else infoProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      if (s.contentLocation_.get ()) contentLocation (*(s.contentLocation_));
      else contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      return *this;
    }


    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentInterfaceDescription::
    label () const
    {
      return *label_;
    }

    ::XMLSchema::string< char >& ComponentInterfaceDescription::
    label ()
    {
      return *label_;
    }

    void ComponentInterfaceDescription::
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

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentInterfaceDescription::
    UUID () const
    {
      return *UUID_;
    }

    ::XMLSchema::string< char >& ComponentInterfaceDescription::
    UUID ()
    {
      return *UUID_;
    }

    void ComponentInterfaceDescription::
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

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    specificType_p () const
    {
      return specificType_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentInterfaceDescription::
    specificType () const
    {
      return *specificType_;
    }

    ::XMLSchema::string< char >& ComponentInterfaceDescription::
    specificType ()
    {
      return *specificType_;
    }

    void ComponentInterfaceDescription::
    specificType (::XMLSchema::string< char > const& e)
    {
      if (specificType_.get ())
      {
        *specificType_ = e;
      }

      else
      {
        specificType_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
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
    add_supportedType (::XMLSchema::string< char > const& e)
    {
      if (supportedType_.capacity () < supportedType_.size () + 1)
      {
        ::std::vector< ::XMLSchema::string< char > > v;
        v.reserve (supportedType_.size () + 1);

        while (supportedType_.size ())
        {
          //@@ VC6
          ::XMLSchema::string< char >& t = supportedType_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          supportedType_.pop_back ();
        }

        supportedType_.swap (v);
      }

      supportedType_.push_back (e);
      supportedType_.back ().container (this);
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    idlFile_p () const
    {
      return idlFile_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentInterfaceDescription::
    idlFile () const
    {
      return *idlFile_;
    }

    ::XMLSchema::string< char >& ComponentInterfaceDescription::
    idlFile ()
    {
      return *idlFile_;
    }

    void ComponentInterfaceDescription::
    idlFile (::XMLSchema::string< char > const& e)
    {
      if (idlFile_.get ())
      {
        *idlFile_ = e;
      }

      else
      {
        idlFile_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        idlFile_->container (this);
      }
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
      if (configProperty_.capacity () < configProperty_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::Property > v;
        v.reserve (configProperty_.size () + 1);

        while (configProperty_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::Property& t = configProperty_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          configProperty_.pop_back ();
        }

        configProperty_.swap (v);
      }

      configProperty_.push_back (e);
      configProperty_.back ().container (this);
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
      if (port_.capacity () < port_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::ComponentPortDescription > v;
        v.reserve (port_.size () + 1);

        while (port_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::ComponentPortDescription& t = port_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          port_.pop_back ();
        }

        port_.swap (v);
      }

      port_.push_back (e);
      port_.back ().container (this);
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    property_p () const
    {
      return property_.get () != 0;
    }

    ::CIAO::Config_Handlers::ComponentPropertyDescription const& ComponentInterfaceDescription::
    property () const
    {
      return *property_;
    }

    ::CIAO::Config_Handlers::ComponentPropertyDescription& ComponentInterfaceDescription::
    property ()
    {
      return *property_;
    }

    void ComponentInterfaceDescription::
    property (::CIAO::Config_Handlers::ComponentPropertyDescription const& e)
    {
      if (property_.get ())
      {
        *property_ = e;
      }

      else
      {
        property_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPropertyDescription > (new ::CIAO::Config_Handlers::ComponentPropertyDescription (e));
        property_->container (this);
      }
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    infoProperty_p () const
    {
      return infoProperty_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& ComponentInterfaceDescription::
    infoProperty () const
    {
      return *infoProperty_;
    }

    ::CIAO::Config_Handlers::Property& ComponentInterfaceDescription::
    infoProperty ()
    {
      return *infoProperty_;
    }

    void ComponentInterfaceDescription::
    infoProperty (::CIAO::Config_Handlers::Property const& e)
    {
      if (infoProperty_.get ())
      {
        *infoProperty_ = e;
      }

      else
      {
        infoProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        infoProperty_->container (this);
      }
    }

    // ComponentInterfaceDescription
    // 
    bool ComponentInterfaceDescription::
    contentLocation_p () const
    {
      return contentLocation_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentInterfaceDescription::
    contentLocation () const
    {
      return *contentLocation_;
    }

    ::XMLSchema::string< char >& ComponentInterfaceDescription::
    contentLocation ()
    {
      return *contentLocation_;
    }

    void ComponentInterfaceDescription::
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
    // ComponentInterfaceDescription
    //

    ComponentInterfaceDescription::
    ComponentInterfaceDescription (::XSCRT::XML::Element< char > const& e)
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

        else if (n == "specificType")
        {
          ::XMLSchema::string< char > t (e);
          specificType (t);
        }

        else if (n == "supportedType")
        {
          ::XMLSchema::string< char > t (e);
          add_supportedType (t);
        }

        else if (n == "idlFile")
        {
          ::XMLSchema::string< char > t (e);
          idlFile (t);
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
          property (t);
        }

        else if (n == "infoProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          infoProperty (t);
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

