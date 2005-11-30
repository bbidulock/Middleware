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
 
#include "toplevel.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // TopLevelPackageDescription
    // 

    TopLevelPackageDescription::
    TopLevelPackageDescription ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    TopLevelPackageDescription::
    TopLevelPackageDescription (::CIAO::Config_Handlers::TopLevelPackageDescription const& s)
    :
    ::XSCRT::Type (),
    regulator__ ()
    {
      {
        for (package_const_iterator i (s.package_.begin ());i != s.package_.end ();++i) add_package (*i);
      }
    }

    ::CIAO::Config_Handlers::TopLevelPackageDescription& TopLevelPackageDescription::
    operator= (::CIAO::Config_Handlers::TopLevelPackageDescription const& s)
    {
      package_.clear ();
      {
        for (package_const_iterator i (s.package_.begin ());i != s.package_.end ();++i) add_package (*i);
      }

      return *this;
    }


    // TopLevelPackageDescription
    // 
    TopLevelPackageDescription::package_iterator TopLevelPackageDescription::
    begin_package ()
    {
      return package_.begin ();
    }

    TopLevelPackageDescription::package_iterator TopLevelPackageDescription::
    end_package ()
    {
      return package_.end ();
    }

    TopLevelPackageDescription::package_const_iterator TopLevelPackageDescription::
    begin_package () const
    {
      return package_.begin ();
    }

    TopLevelPackageDescription::package_const_iterator TopLevelPackageDescription::
    end_package () const
    {
      return package_.end ();
    }

    void TopLevelPackageDescription::
    add_package (::CIAO::Config_Handlers::PackageConfiguration const& e)
    {
      package_.push_back (e);
    }

    size_t TopLevelPackageDescription::
    count_package(void) const
    {
      return package_.size ();
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // TopLevelPackageDescription
    //

    TopLevelPackageDescription::
    TopLevelPackageDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "package")
        {
          ::CIAO::Config_Handlers::PackageConfiguration t (e);
          add_package (t);
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

      struct TopLevelPackageDescriptionTypeInfoInitializer
      {
        TopLevelPackageDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (TopLevelPackageDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      TopLevelPackageDescriptionTypeInfoInitializer TopLevelPackageDescriptionTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // TopLevelPackageDescription
      //
      //

      void TopLevelPackageDescription::
      traverse (Type& o)
      {
        pre (o);
        package (o);
        post (o);
      }

      void TopLevelPackageDescription::
      traverse (Type const& o)
      {
        pre (o);
        package (o);
        post (o);
      }

      void TopLevelPackageDescription::
      pre (Type&)
      {
      }

      void TopLevelPackageDescription::
      pre (Type const&)
      {
      }

      void TopLevelPackageDescription::
      package (Type& o)
      {
        // VC6 anathema strikes again
        //
        TopLevelPackageDescription::Type::package_iterator b (o.begin_package()), e (o.end_package());

        if (b != e)
        {
          package_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) package_next (o);
          }

          package_post (o);
        }
      }

      void TopLevelPackageDescription::
      package (Type const& o)
      {
        // VC6 anathema strikes again
        //
        TopLevelPackageDescription::Type::package_const_iterator b (o.begin_package()), e (o.end_package());

        if (b != e)
        {
          package_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) package_next (o);
          }

          package_post (o);
        }
      }

      void TopLevelPackageDescription::
      package_pre (Type&)
      {
      }

      void TopLevelPackageDescription::
      package_pre (Type const&)
      {
      }

      void TopLevelPackageDescription::
      package_next (Type&)
      {
      }

      void TopLevelPackageDescription::
      package_next (Type const&)
      {
      }

      void TopLevelPackageDescription::
      package_post (Type&)
      {
      }

      void TopLevelPackageDescription::
      package_post (Type const&)
      {
      }

      void TopLevelPackageDescription::
      post (Type&)
      {
      }

      void TopLevelPackageDescription::
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
      // TopLevelPackageDescription
      //
      //

      TopLevelPackageDescription::
      TopLevelPackageDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      TopLevelPackageDescription::
      TopLevelPackageDescription ()
      {
      }

      void TopLevelPackageDescription::
      traverse (Type const& o)
      {
        Traversal::TopLevelPackageDescription::traverse (o);
      }

      void TopLevelPackageDescription::
      package_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("package", top_ ()));
      }

      void TopLevelPackageDescription::
      package_next (Type const& o)
      {
        package_post (o);
        package_pre (o);
      }

      void TopLevelPackageDescription::
      package_post (Type const&)
      {
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

