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

#include "Config_Handlers_Export.h"
#ifndef CDD_HPP
#define CDD_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class Domain;
  }
}

#include <memory>
#include <vector>
#include "XMLSchema/Types.hpp"

#include "Basic_Deployment_Data.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class Config_Handlers_Export Domain : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // label
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      ::XMLSchema::string< ACE_TCHAR >& label ();
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // UUID
      // 
      public:
      ::XMLSchema::string< ACE_TCHAR > const& UUID () const;
      ::XMLSchema::string< ACE_TCHAR >& UUID ();
      void UUID (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > UUID_;

      // sharedResource
      // 
      public:
      bool sharedResource_p () const;
      ::CIAO::Config_Handlers::SharedResource const& sharedResource () const;
      ::CIAO::Config_Handlers::SharedResource& sharedResource ();
      void sharedResource (::CIAO::Config_Handlers::SharedResource const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::SharedResource > sharedResource_;

      // node
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Node >::iterator node_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Node >::const_iterator node_const_iterator;
      node_iterator begin_node ();
      node_iterator end_node ();
      node_const_iterator begin_node () const;
      node_const_iterator end_node () const;
      void add_node (::CIAO::Config_Handlers::Node const& );

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Node > node_;

      // infoProperty
      // 
      public:
      bool infoProperty_p () const;
      ::CIAO::Config_Handlers::Property const& infoProperty () const;
      ::CIAO::Config_Handlers::Property& infoProperty ();
      void infoProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > infoProperty_;

      public:
      Domain (::XMLSchema::string< ACE_TCHAR > const& label__,
      ::XMLSchema::string< ACE_TCHAR > const& UUID__);

      Domain (::XSCRT::XML::Element< ACE_TCHAR > const&);
      Domain (Domain const& s);

      Domain&
      operator= (Domain const& s);

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

#endif // CDD_HPP
