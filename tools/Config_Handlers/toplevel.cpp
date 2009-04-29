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
    TopLevelPackageDescription (TopLevelPackageDescription const& s)
    :
    ::XSCRT::Type (),
    basePackage_ (s.basePackage_),
    regulator__ ()
    {
    }

    TopLevelPackageDescription& TopLevelPackageDescription::
    operator= (TopLevelPackageDescription const& s)
    {
      basePackage_ = s.basePackage_;

      return *this;
    }


    // TopLevelPackageDescription
    // 
    TopLevelPackageDescription::basePackage_iterator TopLevelPackageDescription::
    begin_basePackage ()
    {
      return basePackage_.begin ();
    }

    TopLevelPackageDescription::basePackage_iterator TopLevelPackageDescription::
    end_basePackage ()
    {
      return basePackage_.end ();
    }

    TopLevelPackageDescription::basePackage_const_iterator TopLevelPackageDescription::
    begin_basePackage () const
    {
      return basePackage_.begin ();
    }

    TopLevelPackageDescription::basePackage_const_iterator TopLevelPackageDescription::
    end_basePackage () const
    {
      return basePackage_.end ();
    }

    void TopLevelPackageDescription::
    add_basePackage (::CIAO::Config_Handlers::PackageConfiguration const& e)
    {
      basePackage_.push_back (e);
    }

    size_t TopLevelPackageDescription::
    count_basePackage(void) const
    {
      return basePackage_.size ();
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
    :Base (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "basePackage")
        {
          ::CIAO::Config_Handlers::PackageConfiguration t (e);
          add_basePackage (t);
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
          ::XSCRT::TypeId id (typeid (::CIAO::Config_Handlers::TopLevelPackageDescription));
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
        basePackage (o);
        post (o);
      }

      void TopLevelPackageDescription::
      traverse (Type const& o)
      {
        pre (o);
        basePackage (o);
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
      basePackage (Type& o)
      {
        // VC6 anathema strikes again
        //
        ::CIAO::Config_Handlers::TopLevelPackageDescription::basePackage_iterator b (o.begin_basePackage()), e (o.end_basePackage());

        if (b != e)
        {
          basePackage_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) basePackage_next (o);
          }

          basePackage_post (o);
        }

        else basePackage_none (o);
      }

      void TopLevelPackageDescription::
      basePackage (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ::CIAO::Config_Handlers::TopLevelPackageDescription::basePackage_const_iterator b (o.begin_basePackage()), e (o.end_basePackage());

        if (b != e)
        {
          basePackage_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) basePackage_next (o);
          }

          basePackage_post (o);
        }

        else basePackage_none (o);
      }

      void TopLevelPackageDescription::
      basePackage_pre (Type&)
      {
      }

      void TopLevelPackageDescription::
      basePackage_pre (Type const&)
      {
      }

      void TopLevelPackageDescription::
      basePackage_next (Type&)
      {
      }

      void TopLevelPackageDescription::
      basePackage_next (Type const&)
      {
      }

      void TopLevelPackageDescription::
      basePackage_post (Type&)
      {
      }

      void TopLevelPackageDescription::
      basePackage_post (Type const&)
      {
      }

      void TopLevelPackageDescription::
      basePackage_none (Type&)
      {
      }

      void TopLevelPackageDescription::
      basePackage_none (Type const&)
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
      basePackage_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("basePackage", top_ ()));
      }

      void TopLevelPackageDescription::
      basePackage_next (Type const& o)
      {
        basePackage_post (o);
        basePackage_pre (o);
      }

      void TopLevelPackageDescription::
      basePackage_post (Type const&)
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

