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

#include "iad.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // NamedImplementationArtifact
    //

    NamedImplementationArtifact::
    NamedImplementationArtifact (::XMLSchema::string< ACE_TCHAR > const& name__,
                                 ::CIAO::Config_Handlers::ImplementationArtifactDescription const& referencedArtifact__)
      :
      ::XSCRT::Type (),
      name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
        referencedArtifact_ (new ::CIAO::Config_Handlers::ImplementationArtifactDescription (referencedArtifact__)),
        regulator__ ()
    {
      name_->container (this);
      referencedArtifact_->container (this);
    }

    NamedImplementationArtifact::
    NamedImplementationArtifact (::CIAO::Config_Handlers::NamedImplementationArtifact const& s)
      :
      ::XSCRT::Type (),
      name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
referencedArtifact_ (new ::CIAO::Config_Handlers::ImplementationArtifactDescription (*s.referencedArtifact_)),
regulator__ ()
{
name_->container (this);
referencedArtifact_->container (this);
}

::CIAO::Config_Handlers::NamedImplementationArtifact& NamedImplementationArtifact::
operator= (::CIAO::Config_Handlers::NamedImplementationArtifact const& s)
{
name (s.name ());

referencedArtifact (s.referencedArtifact ());

return *this;
}


// NamedImplementationArtifact
//
::XMLSchema::string< ACE_TCHAR > const& NamedImplementationArtifact::
name () const
{
return *name_;
}

void NamedImplementationArtifact::
name (::XMLSchema::string< ACE_TCHAR > const& e)
{
*name_ = e;
}

// NamedImplementationArtifact
//
::CIAO::Config_Handlers::ImplementationArtifactDescription const& NamedImplementationArtifact::
referencedArtifact () const
{
return *referencedArtifact_;
}

void NamedImplementationArtifact::
referencedArtifact (::CIAO::Config_Handlers::ImplementationArtifactDescription const& e)
{
*referencedArtifact_ = e;
}


// ImplementationArtifactDescription
//

ImplementationArtifactDescription::
ImplementationArtifactDescription ()
:
::XSCRT::Type (),
regulator__ ()
{
}

ImplementationArtifactDescription::
ImplementationArtifactDescription (::CIAO::Config_Handlers::ImplementationArtifactDescription const& s)
:
::XSCRT::Type (),
label_ (s.label_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.label_) : 0),
UUID_ (s.UUID_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.UUID_) : 0),
contentLocation_ (s.contentLocation_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.contentLocation_) : 0),
href_ (s.href_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.href_) : 0),
regulator__ ()
{
if (label_.get ()) label_->container (this);
if (UUID_.get ()) UUID_->container (this);
{
for (location_const_iterator i (s.location_.begin ());i != s.location_.end ();++i) add_location (*i);
}

{
for (dependsOn_const_iterator i (s.dependsOn_.begin ());i != s.dependsOn_.end ();++i) add_dependsOn (*i);
}

{
for (execParameter_const_iterator i (s.execParameter_.begin ());i != s.execParameter_.end ();++i) add_execParameter (*i);
}

{
for (infoProperty_const_iterator i (s.infoProperty_.begin ());i != s.infoProperty_.end ();++i) add_infoProperty (*i);
}

{
for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
}

if (contentLocation_.get ()) contentLocation_->container (this);
if (href_.get ()) href_->container (this);
}

::CIAO::Config_Handlers::ImplementationArtifactDescription& ImplementationArtifactDescription::
operator= (::CIAO::Config_Handlers::ImplementationArtifactDescription const& s)
{
if (s.label_.get ()) label (*(s.label_));
else label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

if (s.UUID_.get ()) UUID (*(s.UUID_));
else UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

location_.clear ();
{
for (location_const_iterator i (s.location_.begin ());i != s.location_.end ();++i) add_location (*i);
}

dependsOn_.clear ();
{
for (dependsOn_const_iterator i (s.dependsOn_.begin ());i != s.dependsOn_.end ();++i) add_dependsOn (*i);
}

execParameter_.clear ();
{
for (execParameter_const_iterator i (s.execParameter_.begin ());i != s.execParameter_.end ();++i) add_execParameter (*i);
}

infoProperty_.clear ();
{
for (infoProperty_const_iterator i (s.infoProperty_.begin ());i != s.infoProperty_.end ();++i) add_infoProperty (*i);
}

deployRequirement_.clear ();
{
for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
}

if (s.contentLocation_.get ()) contentLocation (*(s.contentLocation_));
else contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

if (s.href_.get ()) href (*(s.href_));
else href_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

return *this;
}


// ImplementationArtifactDescription
//
bool ImplementationArtifactDescription::
label_p () const
{
return label_.get () != 0;
}

::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
label () const
{
return *label_;
}

void ImplementationArtifactDescription::
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

// ImplementationArtifactDescription
//
bool ImplementationArtifactDescription::
UUID_p () const
{
return UUID_.get () != 0;
}

::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
UUID () const
{
return *UUID_;
}

void ImplementationArtifactDescription::
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

// ImplementationArtifactDescription
//
ImplementationArtifactDescription::location_iterator ImplementationArtifactDescription::
begin_location ()
{
return location_.begin ();
}

ImplementationArtifactDescription::location_iterator ImplementationArtifactDescription::
end_location ()
{
return location_.end ();
}

ImplementationArtifactDescription::location_const_iterator ImplementationArtifactDescription::
begin_location () const
{
return location_.begin ();
}

ImplementationArtifactDescription::location_const_iterator ImplementationArtifactDescription::
end_location () const
{
return location_.end ();
}

void ImplementationArtifactDescription::
add_location (::XMLSchema::string< ACE_TCHAR > const& e)
{
location_.push_back (e);
}

size_t ImplementationArtifactDescription::
count_location(void) const
{
return location_.size ();
}

// ImplementationArtifactDescription
//
ImplementationArtifactDescription::dependsOn_iterator ImplementationArtifactDescription::
begin_dependsOn ()
{
return dependsOn_.begin ();
}

ImplementationArtifactDescription::dependsOn_iterator ImplementationArtifactDescription::
end_dependsOn ()
{
return dependsOn_.end ();
}

ImplementationArtifactDescription::dependsOn_const_iterator ImplementationArtifactDescription::
begin_dependsOn () const
{
return dependsOn_.begin ();
}

ImplementationArtifactDescription::dependsOn_const_iterator ImplementationArtifactDescription::
end_dependsOn () const
{
return dependsOn_.end ();
}

void ImplementationArtifactDescription::
add_dependsOn (::CIAO::Config_Handlers::NamedImplementationArtifact const& e)
{
dependsOn_.push_back (e);
}

size_t ImplementationArtifactDescription::
count_dependsOn(void) const
{
return dependsOn_.size ();
}

// ImplementationArtifactDescription
//
ImplementationArtifactDescription::execParameter_iterator ImplementationArtifactDescription::
begin_execParameter ()
{
return execParameter_.begin ();
}

ImplementationArtifactDescription::execParameter_iterator ImplementationArtifactDescription::
end_execParameter ()
{
return execParameter_.end ();
}

ImplementationArtifactDescription::execParameter_const_iterator ImplementationArtifactDescription::
begin_execParameter () const
{
return execParameter_.begin ();
}

ImplementationArtifactDescription::execParameter_const_iterator ImplementationArtifactDescription::
end_execParameter () const
{
return execParameter_.end ();
}

void ImplementationArtifactDescription::
add_execParameter (::CIAO::Config_Handlers::Property const& e)
{
execParameter_.push_back (e);
}

size_t ImplementationArtifactDescription::
count_execParameter(void) const
{
return execParameter_.size ();
}

// ImplementationArtifactDescription
//
ImplementationArtifactDescription::infoProperty_iterator ImplementationArtifactDescription::
begin_infoProperty ()
{
return infoProperty_.begin ();
}

ImplementationArtifactDescription::infoProperty_iterator ImplementationArtifactDescription::
end_infoProperty ()
{
return infoProperty_.end ();
}

ImplementationArtifactDescription::infoProperty_const_iterator ImplementationArtifactDescription::
begin_infoProperty () const
{
return infoProperty_.begin ();
}

ImplementationArtifactDescription::infoProperty_const_iterator ImplementationArtifactDescription::
end_infoProperty () const
{
return infoProperty_.end ();
}

void ImplementationArtifactDescription::
add_infoProperty (::CIAO::Config_Handlers::Property const& e)
{
infoProperty_.push_back (e);
}

size_t ImplementationArtifactDescription::
count_infoProperty(void) const
{
return infoProperty_.size ();
}

// ImplementationArtifactDescription
//
ImplementationArtifactDescription::deployRequirement_iterator ImplementationArtifactDescription::
begin_deployRequirement ()
{
return deployRequirement_.begin ();
}

ImplementationArtifactDescription::deployRequirement_iterator ImplementationArtifactDescription::
end_deployRequirement ()
{
return deployRequirement_.end ();
}

ImplementationArtifactDescription::deployRequirement_const_iterator ImplementationArtifactDescription::
begin_deployRequirement () const
{
return deployRequirement_.begin ();
}

ImplementationArtifactDescription::deployRequirement_const_iterator ImplementationArtifactDescription::
end_deployRequirement () const
{
return deployRequirement_.end ();
}

void ImplementationArtifactDescription::
add_deployRequirement (::CIAO::Config_Handlers::Requirement const& e)
{
deployRequirement_.push_back (e);
}

size_t ImplementationArtifactDescription::
count_deployRequirement(void) const
{
return deployRequirement_.size ();
}

// ImplementationArtifactDescription
//
bool ImplementationArtifactDescription::
contentLocation_p () const
{
return contentLocation_.get () != 0;
}

::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
contentLocation () const
{
return *contentLocation_;
}

void ImplementationArtifactDescription::
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

// ImplementationArtifactDescription
//
bool ImplementationArtifactDescription::
href_p () const
{
return href_.get () != 0;
}

::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
href () const
{
return *href_;
}

::XMLSchema::string< ACE_TCHAR >& ImplementationArtifactDescription::
href ()
{
return *href_;
}

void ImplementationArtifactDescription::
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
// NamedImplementationArtifact
//

NamedImplementationArtifact::
NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR > const& e)
:Base__ (e), regulator__ ()
{

::XSCRT::Parser< ACE_TCHAR > p (e);

while (p.more_elements ())
{
::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

if (n == "name")
{
name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
name_->container (this);
}

else if (n == "referencedArtifact")
{
referencedArtifact_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationArtifactDescription > (new ::CIAO::Config_Handlers::ImplementationArtifactDescription (e));
referencedArtifact_->container (this);
}

else
{
}
}
}

// ImplementationArtifactDescription
//

ImplementationArtifactDescription::
ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
:Base__ (e), regulator__ ()
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

else if (n == "location")
{
::XMLSchema::string< ACE_TCHAR > t (e);
add_location (t);
}

else if (n == "dependsOn")
{
::CIAO::Config_Handlers::NamedImplementationArtifact t (e);
add_dependsOn (t);
}

else if (n == "execParameter")
{
::CIAO::Config_Handlers::Property t (e);
add_execParameter (t);
}

else if (n == "infoProperty")
{
::CIAO::Config_Handlers::Property t (e);
add_infoProperty (t);
}

else if (n == "deployRequirement")
{
::CIAO::Config_Handlers::Requirement t (e);
add_deployRequirement (t);
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

struct NamedImplementationArtifactTypeInfoInitializer
{
NamedImplementationArtifactTypeInfoInitializer ()
{
::XSCRT::TypeId id (typeid (NamedImplementationArtifact));
::XSCRT::ExtendedTypeInfo nf (id);

nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
}
};

NamedImplementationArtifactTypeInfoInitializer NamedImplementationArtifactTypeInfoInitializer_;

struct ImplementationArtifactDescriptionTypeInfoInitializer
{
ImplementationArtifactDescriptionTypeInfoInitializer ()
{
::XSCRT::TypeId id (typeid (ImplementationArtifactDescription));
::XSCRT::ExtendedTypeInfo nf (id);

nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
}
};

ImplementationArtifactDescriptionTypeInfoInitializer ImplementationArtifactDescriptionTypeInfoInitializer_;
}
}
}

namespace CIAO
{
namespace Config_Handlers
{
namespace Traversal
{
// NamedImplementationArtifact
//
//

void NamedImplementationArtifact::
traverse (Type& o)
{
pre (o);
name (o);
referencedArtifact (o);
post (o);
}

void NamedImplementationArtifact::
traverse (Type const& o)
{
pre (o);
name (o);
referencedArtifact (o);
post (o);
}

void NamedImplementationArtifact::
pre (Type&)
{
}

void NamedImplementationArtifact::
pre (Type const&)
{
}

void NamedImplementationArtifact::
name (Type& o)
{
dispatch (o.name ());
}

void NamedImplementationArtifact::
name (Type const& o)
{
dispatch (o.name ());
}

void NamedImplementationArtifact::
referencedArtifact (Type& o)
{
dispatch (o.referencedArtifact ());
}

void NamedImplementationArtifact::
referencedArtifact (Type const& o)
{
dispatch (o.referencedArtifact ());
}

void NamedImplementationArtifact::
post (Type&)
{
}

void NamedImplementationArtifact::
post (Type const&)
{
}

// ImplementationArtifactDescription
//
//

void ImplementationArtifactDescription::
traverse (Type& o)
{
pre (o);
if (o.label_p ()) label (o);
else label_none (o);
if (o.UUID_p ()) UUID (o);
else UUID_none (o);
location (o);
dependsOn (o);
execParameter (o);
infoProperty (o);
deployRequirement (o);
if (o.contentLocation_p ()) contentLocation (o);
else contentLocation_none (o);
if (o.href_p ()) href (o);
else href_none (o);
post (o);
}

void ImplementationArtifactDescription::
traverse (Type const& o)
{
pre (o);
if (o.label_p ()) label (o);
else label_none (o);
if (o.UUID_p ()) UUID (o);
else UUID_none (o);
location (o);
dependsOn (o);
execParameter (o);
infoProperty (o);
deployRequirement (o);
if (o.contentLocation_p ()) contentLocation (o);
else contentLocation_none (o);
if (o.href_p ()) href (o);
else href_none (o);
post (o);
}

void ImplementationArtifactDescription::
pre (Type&)
{
}

void ImplementationArtifactDescription::
pre (Type const&)
{
}

void ImplementationArtifactDescription::
label (Type& o)
{
dispatch (o.label ());
}

void ImplementationArtifactDescription::
label (Type const& o)
{
dispatch (o.label ());
}

void ImplementationArtifactDescription::
label_none (Type&)
{
}

void ImplementationArtifactDescription::
label_none (Type const&)
{
}

void ImplementationArtifactDescription::
UUID (Type& o)
{
dispatch (o.UUID ());
}

void ImplementationArtifactDescription::
UUID (Type const& o)
{
dispatch (o.UUID ());
}

void ImplementationArtifactDescription::
UUID_none (Type&)
{
}

void ImplementationArtifactDescription::
UUID_none (Type const&)
{
}

void ImplementationArtifactDescription::
location (Type& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::location_iterator b (o.begin_location()), e (o.end_location());

if (b != e)
{
location_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) location_next (o);
}

location_post (o);
}

else location_none (o);
}

void ImplementationArtifactDescription::
location (Type const& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::location_const_iterator b (o.begin_location()), e (o.end_location());

if (b != e)
{
location_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) location_next (o);
}

location_post (o);
}

else location_none (o);
}

void ImplementationArtifactDescription::
location_pre (Type&)
{
}

void ImplementationArtifactDescription::
location_pre (Type const&)
{
}

void ImplementationArtifactDescription::
location_next (Type&)
{
}

void ImplementationArtifactDescription::
location_next (Type const&)
{
}

void ImplementationArtifactDescription::
location_post (Type&)
{
}

void ImplementationArtifactDescription::
location_post (Type const&)
{
}

void ImplementationArtifactDescription::
location_none (Type&)
{
}

void ImplementationArtifactDescription::
location_none (Type const&)
{
}

void ImplementationArtifactDescription::
dependsOn (Type& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::dependsOn_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

if (b != e)
{
dependsOn_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) dependsOn_next (o);
}

dependsOn_post (o);
}

else dependsOn_none (o);
}

void ImplementationArtifactDescription::
dependsOn (Type const& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::dependsOn_const_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

if (b != e)
{
dependsOn_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) dependsOn_next (o);
}

dependsOn_post (o);
}

else dependsOn_none (o);
}

void ImplementationArtifactDescription::
dependsOn_pre (Type&)
{
}

void ImplementationArtifactDescription::
dependsOn_pre (Type const&)
{
}

void ImplementationArtifactDescription::
dependsOn_next (Type&)
{
}

void ImplementationArtifactDescription::
dependsOn_next (Type const&)
{
}

void ImplementationArtifactDescription::
dependsOn_post (Type&)
{
}

void ImplementationArtifactDescription::
dependsOn_post (Type const&)
{
}

void ImplementationArtifactDescription::
dependsOn_none (Type&)
{
}

void ImplementationArtifactDescription::
dependsOn_none (Type const&)
{
}

void ImplementationArtifactDescription::
execParameter (Type& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::execParameter_iterator b (o.begin_execParameter()), e (o.end_execParameter());

if (b != e)
{
execParameter_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) execParameter_next (o);
}

execParameter_post (o);
}

else execParameter_none (o);
}

void ImplementationArtifactDescription::
execParameter (Type const& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::execParameter_const_iterator b (o.begin_execParameter()), e (o.end_execParameter());

if (b != e)
{
execParameter_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) execParameter_next (o);
}

execParameter_post (o);
}

else execParameter_none (o);
}

void ImplementationArtifactDescription::
execParameter_pre (Type&)
{
}

void ImplementationArtifactDescription::
execParameter_pre (Type const&)
{
}

void ImplementationArtifactDescription::
execParameter_next (Type&)
{
}

void ImplementationArtifactDescription::
execParameter_next (Type const&)
{
}

void ImplementationArtifactDescription::
execParameter_post (Type&)
{
}

void ImplementationArtifactDescription::
execParameter_post (Type const&)
{
}

void ImplementationArtifactDescription::
execParameter_none (Type&)
{
}

void ImplementationArtifactDescription::
execParameter_none (Type const&)
{
}

void ImplementationArtifactDescription::
infoProperty (Type& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::infoProperty_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

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

void ImplementationArtifactDescription::
infoProperty (Type const& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::infoProperty_const_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

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

void ImplementationArtifactDescription::
infoProperty_pre (Type&)
{
}

void ImplementationArtifactDescription::
infoProperty_pre (Type const&)
{
}

void ImplementationArtifactDescription::
infoProperty_next (Type&)
{
}

void ImplementationArtifactDescription::
infoProperty_next (Type const&)
{
}

void ImplementationArtifactDescription::
infoProperty_post (Type&)
{
}

void ImplementationArtifactDescription::
infoProperty_post (Type const&)
{
}

void ImplementationArtifactDescription::
infoProperty_none (Type&)
{
}

void ImplementationArtifactDescription::
infoProperty_none (Type const&)
{
}

void ImplementationArtifactDescription::
deployRequirement (Type& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::deployRequirement_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

if (b != e)
{
deployRequirement_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) deployRequirement_next (o);
}

deployRequirement_post (o);
}

else deployRequirement_none (o);
}

void ImplementationArtifactDescription::
deployRequirement (Type const& o)
{
// VC6 anathema strikes again
//
ImplementationArtifactDescription::Type::deployRequirement_const_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

if (b != e)
{
deployRequirement_pre (o);
for (; b != e;)
{
dispatch (*b);
if (++b != e) deployRequirement_next (o);
}

deployRequirement_post (o);
}

else deployRequirement_none (o);
}

void ImplementationArtifactDescription::
deployRequirement_pre (Type&)
{
}

void ImplementationArtifactDescription::
deployRequirement_pre (Type const&)
{
}

void ImplementationArtifactDescription::
deployRequirement_next (Type&)
{
}

void ImplementationArtifactDescription::
deployRequirement_next (Type const&)
{
}

void ImplementationArtifactDescription::
deployRequirement_post (Type&)
{
}

void ImplementationArtifactDescription::
deployRequirement_post (Type const&)
{
}

void ImplementationArtifactDescription::
deployRequirement_none (Type&)
{
}

void ImplementationArtifactDescription::
deployRequirement_none (Type const&)
{
}

void ImplementationArtifactDescription::
contentLocation (Type& o)
{
dispatch (o.contentLocation ());
}

void ImplementationArtifactDescription::
contentLocation (Type const& o)
{
dispatch (o.contentLocation ());
}

void ImplementationArtifactDescription::
contentLocation_none (Type&)
{
}

void ImplementationArtifactDescription::
contentLocation_none (Type const&)
{
}

void ImplementationArtifactDescription::
href (Type& o)
{
dispatch (o.href ());
}

void ImplementationArtifactDescription::
href (Type const& o)
{
dispatch (o.href ());
}

void ImplementationArtifactDescription::
href_none (Type&)
{
}

void ImplementationArtifactDescription::
href_none (Type const&)
{
}

void ImplementationArtifactDescription::
post (Type&)
{
}

void ImplementationArtifactDescription::
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
// NamedImplementationArtifact
//
//

NamedImplementationArtifact::
NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR >& e)
: ::XSCRT::Writer< ACE_TCHAR > (e)
{
}

NamedImplementationArtifact::
NamedImplementationArtifact ()
{
}

void NamedImplementationArtifact::
traverse (Type const& o)
{
Traversal::NamedImplementationArtifact::traverse (o);
}

void NamedImplementationArtifact::
name (Type const& o)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
Traversal::NamedImplementationArtifact::name (o);
pop_ ();
}

void NamedImplementationArtifact::
referencedArtifact (Type const& o)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("referencedArtifact", top_ ()));
Traversal::NamedImplementationArtifact::referencedArtifact (o);
pop_ ();
}

// ImplementationArtifactDescription
//
//

ImplementationArtifactDescription::
ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
: ::XSCRT::Writer< ACE_TCHAR > (e)
{
}

ImplementationArtifactDescription::
ImplementationArtifactDescription ()
{
}

void ImplementationArtifactDescription::
traverse (Type const& o)
{
Traversal::ImplementationArtifactDescription::traverse (o);
}

void ImplementationArtifactDescription::
label (Type const& o)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("label", top_ ()));
Traversal::ImplementationArtifactDescription::label (o);
pop_ ();
}

void ImplementationArtifactDescription::
UUID (Type const& o)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("UUID", top_ ()));
Traversal::ImplementationArtifactDescription::UUID (o);
pop_ ();
}

void ImplementationArtifactDescription::
location_pre (Type const&)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("location", top_ ()));
}

void ImplementationArtifactDescription::
location_next (Type const& o)
{
location_post (o);
location_pre (o);
}

void ImplementationArtifactDescription::
location_post (Type const&)
{
pop_ ();
}

void ImplementationArtifactDescription::
dependsOn_pre (Type const&)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("dependsOn", top_ ()));
}

void ImplementationArtifactDescription::
dependsOn_next (Type const& o)
{
dependsOn_post (o);
dependsOn_pre (o);
}

void ImplementationArtifactDescription::
dependsOn_post (Type const&)
{
pop_ ();
}

void ImplementationArtifactDescription::
execParameter_pre (Type const&)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("execParameter", top_ ()));
}

void ImplementationArtifactDescription::
execParameter_next (Type const& o)
{
execParameter_post (o);
execParameter_pre (o);
}

void ImplementationArtifactDescription::
execParameter_post (Type const&)
{
pop_ ();
}

void ImplementationArtifactDescription::
infoProperty_pre (Type const&)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("infoProperty", top_ ()));
}

void ImplementationArtifactDescription::
infoProperty_next (Type const& o)
{
infoProperty_post (o);
infoProperty_pre (o);
}

void ImplementationArtifactDescription::
infoProperty_post (Type const&)
{
pop_ ();
}

void ImplementationArtifactDescription::
deployRequirement_pre (Type const&)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployRequirement", top_ ()));
}

void ImplementationArtifactDescription::
deployRequirement_next (Type const& o)
{
deployRequirement_post (o);
deployRequirement_pre (o);
}

void ImplementationArtifactDescription::
deployRequirement_post (Type const&)
{
pop_ ();
}

void ImplementationArtifactDescription::
contentLocation (Type const& o)
{
push_ (::XSCRT::XML::Element< ACE_TCHAR > ("contentLocation", top_ ()));
Traversal::ImplementationArtifactDescription::contentLocation (o);
pop_ ();
}

void ImplementationArtifactDescription::
href (Type const& o)
{
::XSCRT::XML::Attribute< ACE_TCHAR > a ("href", "", top_ ());
attr_ (&a);
Traversal::ImplementationArtifactDescription::href (o);
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

