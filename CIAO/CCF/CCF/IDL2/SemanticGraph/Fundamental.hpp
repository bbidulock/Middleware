// file      : CCF/IDL2/SemanticGraph/Fundamental.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

// Note, that this file is automatically generated!
//

#ifndef CCF_IDL2_SEMANTIC_GRAPH_FUNDAMENTAL_HPP
#define CCF_IDL2_SEMANTIC_GRAPH_FUNDAMENTAL_HPP

#include "CCF/IDL2/SemanticGraph/Elements.hpp"

namespace CCF
{
  namespace IDL2
  {
    namespace SemanticGraph
    {
      // @@ Object & ValueBase should be of interface & valuetype types?
      //
      //
      class FundamentalType : public virtual Type
      {
      public:
        virtual bool
        complete () const
        {
          return true;
        }

        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        FundamentalType ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Object : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Object ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class ValueBase : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        ValueBase ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Any : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Any ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Boolean : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Boolean ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Char : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Char ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Double : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Double ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Float : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Float ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Long : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Long ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class LongDouble : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        LongDouble ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class LongLong : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        LongLong ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Octet : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Octet ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Short : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Short ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class String : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        String ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class UnsignedLong : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        UnsignedLong ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class UnsignedLongLong : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        UnsignedLongLong ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class UnsignedShort : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        UnsignedShort ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Void : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Void ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Wchar : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Wchar ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class Wstring : public virtual FundamentalType
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Wstring ()
        {
          type_info (static_type_info ());
        }
      };
    }
  }
}

#endif  // CCF_IDL2_SEMANTIC_GRAPH_FUNDAMENTAL_HPP
