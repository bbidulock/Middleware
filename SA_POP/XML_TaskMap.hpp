#ifndef XML_TASKMAP_HPP
#define XML_TASKMAP_HPP

// Forward declarations.
//
namespace SA_POP
{
  namespace XML
  {
    class TaskID;
    class TaskImplID;
    class ResourceID;
    class ResourceKind;
    class ResourceValue;
    class ImplParamID;
    class ImplParamKind;
    class ImplParamValue;
    class TimeValue;
    class Resource;
    class ImplParam;
    class TaskImpl;
    class TaskToImpl;
    class ImplToResource;
    class TaskMap;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

namespace SA_POP
{
  namespace XML
  {
    class TaskID : public ::XMLSchema::int_
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::int_ Base__;

      public:
      TaskID (::XMLSchema::int_ const& b__);

      TaskID (::XSCRT::XML::Element< wchar_t > const&);
      TaskID (::XSCRT::XML::Attribute< wchar_t > const&);
      TaskID (TaskID const& s);

      TaskID&
      operator= (TaskID const& s);

      private:
      char regulator__;
    };

    class TaskImplID : public ::XMLSchema::string< wchar_t >
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::string< wchar_t > Base__;

      public:
      TaskImplID (::XMLSchema::string< wchar_t > const& b__);

      TaskImplID (::XSCRT::XML::Element< wchar_t > const&);
      TaskImplID (::XSCRT::XML::Attribute< wchar_t > const&);
      TaskImplID (TaskImplID const& s);

      TaskImplID&
      operator= (TaskImplID const& s);

      private:
      char regulator__;
    };

    class ResourceID : public ::XMLSchema::string< wchar_t >
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::string< wchar_t > Base__;

      public:
      ResourceID (::XMLSchema::string< wchar_t > const& b__);

      ResourceID (::XSCRT::XML::Element< wchar_t > const&);
      ResourceID (::XSCRT::XML::Attribute< wchar_t > const&);
      ResourceID (ResourceID const& s);

      ResourceID&
      operator= (ResourceID const& s);

      private:
      char regulator__;
    };

    class ResourceKind : public ::XSCRT::Type
    {
      public:
      ResourceKind (::XSCRT::XML::Element< wchar_t > const&);
      ResourceKind (::XSCRT::XML::Attribute< wchar_t > const&);

      static ResourceKind const UNARY;
      static ResourceKind const DISCRETE;
      static ResourceKind const RESERVOIR;

      enum Value
      {
        UNARY_l,DISCRETE_l,RESERVOIR_l,
      };


      Value
      integral () const;

      friend bool 
      operator== (ResourceKind const& a, ResourceKind const& b);

      friend bool 
      operator!= (ResourceKind const& a, ResourceKind const& b);

      private:
      ResourceKind (Value v);

      Value v_;
    };

    bool operator== (ResourceKind const &a, ResourceKind const &b);

    bool operator!= (ResourceKind const &a, ResourceKind const &b);


    class ResourceValue : public ::XMLSchema::int_
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::int_ Base__;

      public:
      ResourceValue (::XMLSchema::int_ const& b__);

      ResourceValue (::XSCRT::XML::Element< wchar_t > const&);
      ResourceValue (::XSCRT::XML::Attribute< wchar_t > const&);
      ResourceValue (ResourceValue const& s);

      ResourceValue&
      operator= (ResourceValue const& s);

      private:
      char regulator__;
    };

    class ImplParamID : public ::XMLSchema::string< wchar_t >
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::string< wchar_t > Base__;

      public:
      ImplParamID (::XMLSchema::string< wchar_t > const& b__);

      ImplParamID (::XSCRT::XML::Element< wchar_t > const&);
      ImplParamID (::XSCRT::XML::Attribute< wchar_t > const&);
      ImplParamID (ImplParamID const& s);

      ImplParamID&
      operator= (ImplParamID const& s);

      private:
      char regulator__;
    };

    class ImplParamKind : public ::XMLSchema::string< wchar_t >
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::string< wchar_t > Base__;

      public:
      ImplParamKind (::XMLSchema::string< wchar_t > const& b__);

      ImplParamKind (::XSCRT::XML::Element< wchar_t > const&);
      ImplParamKind (::XSCRT::XML::Attribute< wchar_t > const&);
      ImplParamKind (ImplParamKind const& s);

      ImplParamKind&
      operator= (ImplParamKind const& s);

      private:
      char regulator__;
    };

    class ImplParamValue : public ::XMLSchema::string< wchar_t >
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::string< wchar_t > Base__;

      public:
      ImplParamValue (::XMLSchema::string< wchar_t > const& b__);

      ImplParamValue (::XSCRT::XML::Element< wchar_t > const&);
      ImplParamValue (::XSCRT::XML::Attribute< wchar_t > const&);
      ImplParamValue (ImplParamValue const& s);

      ImplParamValue&
      operator= (ImplParamValue const& s);

      private:
      char regulator__;
    };

    class TimeValue : public ::XMLSchema::int_
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::int_ Base__;

      public:
      TimeValue (::XMLSchema::int_ const& b__);

      TimeValue (::XSCRT::XML::Element< wchar_t > const&);
      TimeValue (::XSCRT::XML::Attribute< wchar_t > const&);
      TimeValue (TimeValue const& s);

      TimeValue&
      operator= (TimeValue const& s);

      private:
      char regulator__;
    };

    class Resource : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // resourceID
      // 
      public:
      ::SA_POP::XML::ResourceID const& resourceID () const;
      void resourceID (::SA_POP::XML::ResourceID const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ResourceID > resourceID_;

      // kind
      // 
      public:
      ::SA_POP::XML::ResourceKind const& kind () const;
      void kind (::SA_POP::XML::ResourceKind const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ResourceKind > kind_;

      // capacity
      // 
      public:
      ::SA_POP::XML::ResourceValue const& capacity () const;
      void capacity (::SA_POP::XML::ResourceValue const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ResourceValue > capacity_;

      public:
      Resource (::SA_POP::XML::ResourceID const& resourceID__,
                ::SA_POP::XML::ResourceKind const& kind__,
                ::SA_POP::XML::ResourceValue const& capacity__);

      Resource (::XSCRT::XML::Element< wchar_t > const&);
      Resource (Resource const& s);

      Resource&
      operator= (Resource const& s);

      private:
      char regulator__;
    };


    class ImplParam : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // paramID
      // 
      public:
      ::SA_POP::XML::ImplParamID const& paramID () const;
      void paramID (::SA_POP::XML::ImplParamID const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ImplParamID > paramID_;

      // kind
      // 
      public:
      ::SA_POP::XML::ImplParamKind const& kind () const;
      void kind (::SA_POP::XML::ImplParamKind const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ImplParamKind > kind_;

      // value
      // 
      public:
      ::SA_POP::XML::ImplParamValue const& value () const;
      void value (::SA_POP::XML::ImplParamValue const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ImplParamValue > value_;

      public:
      ImplParam (::SA_POP::XML::ImplParamID const& paramID__,
                 ::SA_POP::XML::ImplParamKind const& kind__,
                 ::SA_POP::XML::ImplParamValue const& value__);

      ImplParam (::XSCRT::XML::Element< wchar_t > const&);
      ImplParam (ImplParam const& s);

      ImplParam&
      operator= (ImplParam const& s);

      private:
      char regulator__;
    };


    class TaskImpl : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // implID
      // 
      public:
      ::SA_POP::XML::TaskImplID const& implID () const;
      void implID (::SA_POP::XML::TaskImplID const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::TaskImplID > implID_;

      // param
      // 
      public:
      typedef ::std::list< ::SA_POP::XML::ImplParam >::iterator param_iterator;
      typedef ::std::list< ::SA_POP::XML::ImplParam >::const_iterator param_const_iterator;
      param_iterator begin_param ();
      param_iterator end_param ();
      param_const_iterator begin_param () const;
      param_const_iterator end_param () const;
      void add_param (::SA_POP::XML::ImplParam const& );
      size_t count_param (void) const;

      protected:
      ::std::list< ::SA_POP::XML::ImplParam > param_;

      public:
      TaskImpl (::SA_POP::XML::TaskImplID const& implID__);

      TaskImpl (::XSCRT::XML::Element< wchar_t > const&);
      TaskImpl (TaskImpl const& s);

      TaskImpl&
      operator= (TaskImpl const& s);

      private:
      char regulator__;
    };


    class TaskToImpl : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // taskID
      // 
      public:
      ::SA_POP::XML::TaskID const& taskID () const;
      void taskID (::SA_POP::XML::TaskID const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::TaskID > taskID_;

      // implID
      // 
      public:
      ::SA_POP::XML::TaskImplID const& implID () const;
      void implID (::SA_POP::XML::TaskImplID const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::TaskImplID > implID_;

      // duration
      // 
      public:
      ::SA_POP::XML::TimeValue const& duration () const;
      void duration (::SA_POP::XML::TimeValue const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::TimeValue > duration_;

      public:
      TaskToImpl (::SA_POP::XML::TaskID const& taskID__,
                  ::SA_POP::XML::TaskImplID const& implID__,
                  ::SA_POP::XML::TimeValue const& duration__);

      TaskToImpl (::XSCRT::XML::Element< wchar_t > const&);
      TaskToImpl (TaskToImpl const& s);

      TaskToImpl&
      operator= (TaskToImpl const& s);

      private:
      char regulator__;
    };


    class ImplToResource : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // implID
      // 
      public:
      ::SA_POP::XML::TaskImplID const& implID () const;
      void implID (::SA_POP::XML::TaskImplID const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::TaskImplID > implID_;

      // resourceID
      // 
      public:
      ::SA_POP::XML::ResourceID const& resourceID () const;
      void resourceID (::SA_POP::XML::ResourceID const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ResourceID > resourceID_;

      // utilization
      // 
      public:
      ::SA_POP::XML::ResourceValue const& utilization () const;
      void utilization (::SA_POP::XML::ResourceValue const& );

      protected:
      ::std::auto_ptr< ::SA_POP::XML::ResourceValue > utilization_;

      public:
      ImplToResource (::SA_POP::XML::TaskImplID const& implID__,
                      ::SA_POP::XML::ResourceID const& resourceID__,
                      ::SA_POP::XML::ResourceValue const& utilization__);

      ImplToResource (::XSCRT::XML::Element< wchar_t > const&);
      ImplToResource (ImplToResource const& s);

      ImplToResource&
      operator= (ImplToResource const& s);

      private:
      char regulator__;
    };


    class TaskMap : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // taskImpl
      // 
      public:
      typedef ::std::list< ::SA_POP::XML::TaskImpl >::iterator taskImpl_iterator;
      typedef ::std::list< ::SA_POP::XML::TaskImpl >::const_iterator taskImpl_const_iterator;
      taskImpl_iterator begin_taskImpl ();
      taskImpl_iterator end_taskImpl ();
      taskImpl_const_iterator begin_taskImpl () const;
      taskImpl_const_iterator end_taskImpl () const;
      void add_taskImpl (::SA_POP::XML::TaskImpl const& );
      size_t count_taskImpl (void) const;

      protected:
      ::std::list< ::SA_POP::XML::TaskImpl > taskImpl_;

      // resource
      // 
      public:
      typedef ::std::list< ::SA_POP::XML::Resource >::iterator resource_iterator;
      typedef ::std::list< ::SA_POP::XML::Resource >::const_iterator resource_const_iterator;
      resource_iterator begin_resource ();
      resource_iterator end_resource ();
      resource_const_iterator begin_resource () const;
      resource_const_iterator end_resource () const;
      void add_resource (::SA_POP::XML::Resource const& );
      size_t count_resource (void) const;

      protected:
      ::std::list< ::SA_POP::XML::Resource > resource_;

      // taskToImpl
      // 
      public:
      typedef ::std::list< ::SA_POP::XML::TaskToImpl >::iterator taskToImpl_iterator;
      typedef ::std::list< ::SA_POP::XML::TaskToImpl >::const_iterator taskToImpl_const_iterator;
      taskToImpl_iterator begin_taskToImpl ();
      taskToImpl_iterator end_taskToImpl ();
      taskToImpl_const_iterator begin_taskToImpl () const;
      taskToImpl_const_iterator end_taskToImpl () const;
      void add_taskToImpl (::SA_POP::XML::TaskToImpl const& );
      size_t count_taskToImpl (void) const;

      protected:
      ::std::list< ::SA_POP::XML::TaskToImpl > taskToImpl_;

      // implToResource
      // 
      public:
      typedef ::std::list< ::SA_POP::XML::ImplToResource >::iterator implToResource_iterator;
      typedef ::std::list< ::SA_POP::XML::ImplToResource >::const_iterator implToResource_const_iterator;
      implToResource_iterator begin_implToResource ();
      implToResource_iterator end_implToResource ();
      implToResource_const_iterator begin_implToResource () const;
      implToResource_const_iterator end_implToResource () const;
      void add_implToResource (::SA_POP::XML::ImplToResource const& );
      size_t count_implToResource (void) const;

      protected:
      ::std::list< ::SA_POP::XML::ImplToResource > implToResource_;

      public:
      TaskMap ();

      TaskMap (::XSCRT::XML::Element< wchar_t > const&);
      TaskMap (TaskMap const& s);

      TaskMap&
      operator= (TaskMap const& s);

      private:
      char regulator__;
    };
  }
}

namespace SA_POP
{
  namespace XML
  {
    ::SA_POP::XML::TaskMap
    taskMap (xercesc::DOMDocument const*);
  }
}

#include "XMLSchema/Traversal.hpp"

namespace SA_POP
{
  namespace XML
  {
    namespace Traversal
    {
      struct TaskID : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::TaskID >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct TaskImplID : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::TaskImplID >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct ResourceID : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ResourceID >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      typedef
      ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ResourceKind >
      ResourceKind;

      struct ResourceValue : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ResourceValue >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct ImplParamID : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ImplParamID >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct ImplParamKind : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ImplParamKind >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct ImplParamValue : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ImplParamValue >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct TimeValue : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::TimeValue >
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
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct Resource : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::Resource >
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
        resourceID (Type&);

        virtual void
        resourceID (Type const&);

        virtual void
        kind (Type&);

        virtual void
        kind (Type const&);

        virtual void
        capacity (Type&);

        virtual void
        capacity (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct ImplParam : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ImplParam >
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
        paramID (Type&);

        virtual void
        paramID (Type const&);

        virtual void
        kind (Type&);

        virtual void
        kind (Type const&);

        virtual void
        value (Type&);

        virtual void
        value (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct TaskImpl : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::TaskImpl >
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
        implID (Type&);

        virtual void
        implID (Type const&);

        virtual void
        param (Type&);

        virtual void
        param (Type const&);

        virtual void
        param_pre (Type&);

        virtual void
        param_pre (Type const&);

        virtual void
        param_next (Type&);

        virtual void
        param_next (Type const&);

        virtual void
        param_post (Type&);

        virtual void
        param_post (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct TaskToImpl : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::TaskToImpl >
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
        taskID (Type&);

        virtual void
        taskID (Type const&);

        virtual void
        implID (Type&);

        virtual void
        implID (Type const&);

        virtual void
        duration (Type&);

        virtual void
        duration (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct ImplToResource : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::ImplToResource >
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
        implID (Type&);

        virtual void
        implID (Type const&);

        virtual void
        resourceID (Type&);

        virtual void
        resourceID (Type const&);

        virtual void
        utilization (Type&);

        virtual void
        utilization (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct TaskMap : ::XMLSchema::Traversal::Traverser< ::SA_POP::XML::TaskMap >
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
        taskImpl (Type&);

        virtual void
        taskImpl (Type const&);

        virtual void
        taskImpl_pre (Type&);

        virtual void
        taskImpl_pre (Type const&);

        virtual void
        taskImpl_next (Type&);

        virtual void
        taskImpl_next (Type const&);

        virtual void
        taskImpl_post (Type&);

        virtual void
        taskImpl_post (Type const&);

        virtual void
        resource (Type&);

        virtual void
        resource (Type const&);

        virtual void
        resource_pre (Type&);

        virtual void
        resource_pre (Type const&);

        virtual void
        resource_next (Type&);

        virtual void
        resource_next (Type const&);

        virtual void
        resource_post (Type&);

        virtual void
        resource_post (Type const&);

        virtual void
        taskToImpl (Type&);

        virtual void
        taskToImpl (Type const&);

        virtual void
        taskToImpl_pre (Type&);

        virtual void
        taskToImpl_pre (Type const&);

        virtual void
        taskToImpl_next (Type&);

        virtual void
        taskToImpl_next (Type const&);

        virtual void
        taskToImpl_post (Type&);

        virtual void
        taskToImpl_post (Type const&);

        virtual void
        implToResource (Type&);

        virtual void
        implToResource (Type const&);

        virtual void
        implToResource_pre (Type&);

        virtual void
        implToResource_pre (Type const&);

        virtual void
        implToResource_next (Type&);

        virtual void
        implToResource_next (Type const&);

        virtual void
        implToResource_post (Type&);

        virtual void
        implToResource_post (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };
    }
  }
}

#include "XMLSchema/Writer.hpp"

namespace SA_POP
{
  namespace XML
  {
    namespace Writer
    {
      struct TaskID : Traversal::TaskID, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::TaskID Type;
        TaskID (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        TaskID ();
      };

      struct TaskImplID : Traversal::TaskImplID, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< wchar_t >, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::TaskImplID Type;
        TaskImplID (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        TaskImplID ();
      };

      struct ResourceID : Traversal::ResourceID, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< wchar_t >, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::ResourceID Type;
        ResourceID (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        ResourceID ();
      };

      struct ResourceKind : Traversal::ResourceKind, 
      virtual ::XSCRT::Writer< wchar_t >
      {
        ResourceKind (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        protected:
        ResourceKind ();
      };

      struct ResourceValue : Traversal::ResourceValue, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::ResourceValue Type;
        ResourceValue (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        ResourceValue ();
      };

      struct ImplParamID : Traversal::ImplParamID, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< wchar_t >, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::ImplParamID Type;
        ImplParamID (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        ImplParamID ();
      };

      struct ImplParamKind : Traversal::ImplParamKind, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< wchar_t >, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::ImplParamKind Type;
        ImplParamKind (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        ImplParamKind ();
      };

      struct ImplParamValue : Traversal::ImplParamValue, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< wchar_t >, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::ImplParamValue Type;
        ImplParamValue (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        ImplParamValue ();
      };

      struct TimeValue : Traversal::TimeValue, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, wchar_t >,
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::TimeValue Type;
        TimeValue (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        TimeValue ();
      };

      struct Resource : Traversal::Resource, 
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::Resource Type;
        Resource (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        resourceID (Type &o)
        {

          this->resourceID (const_cast <Type const &> (o));
        }


        virtual void
        resourceID (Type const&);

        virtual void 
        kind (Type &o)
        {

          this->kind (const_cast <Type const &> (o));
        }


        virtual void
        kind (Type const&);

        virtual void 
        capacity (Type &o)
        {

          this->capacity (const_cast <Type const &> (o));
        }


        virtual void
        capacity (Type const&);

        protected:
        Resource ();
      };

      struct ImplParam : Traversal::ImplParam, 
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::ImplParam Type;
        ImplParam (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        paramID (Type &o)
        {

          this->paramID (const_cast <Type const &> (o));
        }


        virtual void
        paramID (Type const&);

        virtual void 
        kind (Type &o)
        {

          this->kind (const_cast <Type const &> (o));
        }


        virtual void
        kind (Type const&);

        virtual void 
        value (Type &o)
        {

          this->value (const_cast <Type const &> (o));
        }


        virtual void
        value (Type const&);

        protected:
        ImplParam ();
      };

      struct TaskImpl : Traversal::TaskImpl, 
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::TaskImpl Type;
        TaskImpl (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        implID (Type &o)
        {

          this->implID (const_cast <Type const &> (o));
        }


        virtual void
        implID (Type const&);

        virtual void 
        param_pre (Type &o)
        {

          this->param_pre (const_cast <Type const &> (o));
        }


        virtual void
        param_pre (Type const&);

        virtual void 
        param_next (Type &o)
        {

          this->param_next (const_cast <Type const &> (o));
        }


        virtual void
        param_next (Type const&);

        virtual void 
        param_post (Type &o)
        {

          this->param_post (const_cast <Type const &> (o));
        }


        virtual void
        param_post (Type const&);

        protected:
        TaskImpl ();
      };

      struct TaskToImpl : Traversal::TaskToImpl, 
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::TaskToImpl Type;
        TaskToImpl (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        taskID (Type &o)
        {

          this->taskID (const_cast <Type const &> (o));
        }


        virtual void
        taskID (Type const&);

        virtual void 
        implID (Type &o)
        {

          this->implID (const_cast <Type const &> (o));
        }


        virtual void
        implID (Type const&);

        virtual void 
        duration (Type &o)
        {

          this->duration (const_cast <Type const &> (o));
        }


        virtual void
        duration (Type const&);

        protected:
        TaskToImpl ();
      };

      struct ImplToResource : Traversal::ImplToResource, 
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::ImplToResource Type;
        ImplToResource (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        implID (Type &o)
        {

          this->implID (const_cast <Type const &> (o));
        }


        virtual void
        implID (Type const&);

        virtual void 
        resourceID (Type &o)
        {

          this->resourceID (const_cast <Type const &> (o));
        }


        virtual void
        resourceID (Type const&);

        virtual void 
        utilization (Type &o)
        {

          this->utilization (const_cast <Type const &> (o));
        }


        virtual void
        utilization (Type const&);

        protected:
        ImplToResource ();
      };

      struct TaskMap : Traversal::TaskMap, 
      virtual ::XSCRT::Writer< wchar_t >
      {
        typedef ::SA_POP::XML::TaskMap Type;
        TaskMap (::XSCRT::XML::Element< wchar_t >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        taskImpl_pre (Type &o)
        {

          this->taskImpl_pre (const_cast <Type const &> (o));
        }


        virtual void
        taskImpl_pre (Type const&);

        virtual void 
        taskImpl_next (Type &o)
        {

          this->taskImpl_next (const_cast <Type const &> (o));
        }


        virtual void
        taskImpl_next (Type const&);

        virtual void 
        taskImpl_post (Type &o)
        {

          this->taskImpl_post (const_cast <Type const &> (o));
        }


        virtual void
        taskImpl_post (Type const&);

        virtual void 
        resource_pre (Type &o)
        {

          this->resource_pre (const_cast <Type const &> (o));
        }


        virtual void
        resource_pre (Type const&);

        virtual void 
        resource_next (Type &o)
        {

          this->resource_next (const_cast <Type const &> (o));
        }


        virtual void
        resource_next (Type const&);

        virtual void 
        resource_post (Type &o)
        {

          this->resource_post (const_cast <Type const &> (o));
        }


        virtual void
        resource_post (Type const&);

        virtual void 
        taskToImpl_pre (Type &o)
        {

          this->taskToImpl_pre (const_cast <Type const &> (o));
        }


        virtual void
        taskToImpl_pre (Type const&);

        virtual void 
        taskToImpl_next (Type &o)
        {

          this->taskToImpl_next (const_cast <Type const &> (o));
        }


        virtual void
        taskToImpl_next (Type const&);

        virtual void 
        taskToImpl_post (Type &o)
        {

          this->taskToImpl_post (const_cast <Type const &> (o));
        }


        virtual void
        taskToImpl_post (Type const&);

        virtual void 
        implToResource_pre (Type &o)
        {

          this->implToResource_pre (const_cast <Type const &> (o));
        }


        virtual void
        implToResource_pre (Type const&);

        virtual void 
        implToResource_next (Type &o)
        {

          this->implToResource_next (const_cast <Type const &> (o));
        }


        virtual void
        implToResource_next (Type const&);

        virtual void 
        implToResource_post (Type &o)
        {

          this->implToResource_post (const_cast <Type const &> (o));
        }


        virtual void
        implToResource_post (Type const&);

        protected:
        TaskMap ();
      };
    }
  }
}

namespace SA_POP
{
  namespace XML
  {
    void
    taskMap (::SA_POP::XML::TaskMap const&, xercesc::DOMDocument*);
  }
}

#endif // XML_TASKMAP_HPP
