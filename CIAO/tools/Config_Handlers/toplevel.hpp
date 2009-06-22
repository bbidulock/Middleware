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
namespace CIAO
{
  namespace Config_Handlers
  {
    class TopLevelPackageDescription;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

#include "ace/Refcounted_Auto_Ptr.h"
#include "ace/Null_Mutex.h"

#include "pcd.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export TopLevelPackageDescription : public ::XSCRT::Type
    {
      typedef ::XSCRT::Type Base;

      public:
      typedef ACE_Refcounted_Auto_Ptr < TopLevelPackageDescription, ACE_Null_Mutex > _ptr;

      // basePackage
      // 
      public:
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > >::iterator basePackage_iterator;
      typedef ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > >::const_iterator basePackage_const_iterator;
      basePackage_iterator begin_basePackage ();
      basePackage_iterator end_basePackage ();
      basePackage_const_iterator begin_basePackage () const;
      basePackage_const_iterator end_basePackage () const;
      void add_basePackage ( ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > const& );
      size_t count_basePackage (void) const;

      protected:
      ::std::list< ACE_Refcounted_Auto_Ptr < ::CIAO::Config_Handlers::PackageConfiguration, ACE_Null_Mutex > > basePackage_;

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
      struct XSC_XML_Handlers_Export TopLevelPackageDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::TopLevelPackageDescription >
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
        basePackage (Type&);

        virtual void
        basePackage (Type const&);

        virtual void
        basePackage_pre (Type&);

        virtual void
        basePackage_pre (Type const&);

        virtual void
        basePackage_next (Type&);

        virtual void
        basePackage_next (Type const&);

        virtual void
        basePackage_post (Type&);

        virtual void
        basePackage_post (Type const&);

        virtual void
        basePackage_none (Type&);

        virtual void
        basePackage_none (Type const&);

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
      struct TopLevelPackageDescription : Traversal::TopLevelPackageDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::TopLevelPackageDescription Type;
        TopLevelPackageDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        virtual void 
        basePackage_pre (Type &o)
        {
          this->basePackage_pre (const_cast <Type const &> (o));
        }

        virtual void
        basePackage_pre (Type const&);

        virtual void 
        basePackage_next (Type &o)
        {
          this->basePackage_next (const_cast <Type const &> (o));
        }

        virtual void
        basePackage_next (Type const&);

        virtual void 
        basePackage_post (Type &o)
        {
          this->basePackage_post (const_cast <Type const &> (o));
        }

        virtual void
        basePackage_post (Type const&);

        protected:
        TopLevelPackageDescription ();
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

#endif // TOPLEVEL_HPP
