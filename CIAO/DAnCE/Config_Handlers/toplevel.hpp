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

#ifndef TOPLEVEL_HPP
#define TOPLEVEL_HPP

#include "XSC_XML_Handlers_Export.h"
// Forward declarations.
//
namespace DAnCE
{
  namespace Config_Handlers
  {
    class TopLevelPackageDescription;
  }
}

#include <memory>
#include <string>
#include <list>
#include "XMLSchema/Types.hpp"
#include "XMLSchema/id_map.hpp"
#include "ace/Refcounted_Auto_Ptr.h"
#include "ace/Null_Mutex.h"
#include "ace/TSS_T.h"
#include "ace/ace_wchar.h"
#include "ace/Singleton.h"

#include "pcd.hpp"

namespace DAnCE
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export TopLevelPackageDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      public:
      typedef ACE_Refcounted_Auto_Ptr < TopLevelPackageDescription, ACE_Null_Mutex > _ptr;

      // package
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > >::iterator package_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > >::const_iterator package_const_iterator;
      package_iterator begin_package ();
      package_iterator end_package ();
      package_const_iterator begin_package () const;
      package_const_iterator end_package () const;
      void add_package ( ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > const& );
      XSCRT::Type* package_ptr ( std::basic_string<ACE_TCHAR> idref );
      size_t count_package (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > > package_;

      public:
      TopLevelPackageDescription ();

      TopLevelPackageDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      TopLevelPackageDescription (TopLevelPackageDescription const& s);

      TopLevelPackageDescription&
      operator= (TopLevelPackageDescription const& s);

      private:
      char regulator__;
    };
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/Traversal.hpp"

namespace DAnCE
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      struct XSC_XML_Handlers_Export TopLevelPackageDescription : ::XMLSchema::Traversal::Traverser< ::DAnCE::Config_Handlers::TopLevelPackageDescription >
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
        package (Type&);

        virtual void
        package (Type const&);

        virtual void
        package_pre (Type&);

        virtual void
        package_pre (Type const&);

        virtual void
        package_next (Type&);

        virtual void
        package_next (Type const&);

        virtual void
        package_post (Type&);

        virtual void
        package_post (Type const&);

        virtual void
        package_none (Type&);

        virtual void
        package_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };
    }
  }
}

#include "XMLSchema/Writer.hpp"

namespace DAnCE
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      struct TopLevelPackageDescription : Traversal::TopLevelPackageDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::DAnCE::Config_Handlers::TopLevelPackageDescription Type;
        TopLevelPackageDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        virtual void 
        package_pre (Type &o)
        {
          this->package_pre (const_cast <Type const &> (o));
        }

        virtual void
        package_pre (Type const&);

        virtual void 
        package_next (Type &o)
        {
          this->package_next (const_cast <Type const &> (o));
        }

        virtual void
        package_next (Type const&);

        virtual void 
        package_post (Type &o)
        {
          this->package_post (const_cast <Type const &> (o));
        }

        virtual void
        package_post (Type const&);

        protected:
        TopLevelPackageDescription ();
      };
    }
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
  }
}

#endif // TOPLEVEL_HPP
