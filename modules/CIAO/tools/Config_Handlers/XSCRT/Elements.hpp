// file      : XSCRT/Elements.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef XSCRT_ELEMENTS_HPP
#define XSCRT_ELEMENTS_HPP

#include <map>
#include <string>
#include <sstream>
#include <memory>
// #include <iostream> //@@ tmp

#include "XSCRT/Parser.hpp"
#include "ace/Refcounted_Auto_Ptr.h"

namespace XSCRT
{
  struct IdentityProvider
  {
    virtual ~IdentityProvider (void) {}

    virtual bool before (IdentityProvider const&) const = 0;
  };

  class Type
  {
  public:
    virtual ~Type ()
    {
    }

  protected:
    Type ()
      : container_ (0)
    {
    }

    template <typename C>
    Type (XML::Element<C> const&)
        : container_ (0)
    {
    }

    template <typename C>
    Type (XML::Attribute<C> const&)
        : container_ (0)
    {
    }

    Type (Type const&)
        : container_ (0)
    {
    }

    Type&
    operator= (Type const&)
    {
      //@@ I don't need this.
      //if (map_.get ()) map_->clear (); // Flush the map.
      return *this;
    }

  public:
    Type const*
    container () const
    {
      return container_ ? container_ : this;
    }

    Type*
    container ()
    {
      return container_ ? container_ : this;
    }


    Type const*
    root () const
    {
      Type const* r = container ();

      //@@ VC6 can't handle this inside the loop.
      //
      Type const* c = r->container ();

      for (; c != r; c = c->container ()) r = c;

      return r;
    }

    Type*
    root ()
    {
      Type* r = container ();

      for (Type* c = r->container (); c != r; c = c->container ()) r = c;

      return r;
    }

    //@@
    //protected:

  public:
    virtual void
    container (Type* c)
    {
      if (container_ == c) return;

      // Revoke registrations from our old container.
      //
      if (container_ != 0 && map_.get ())
      {
        for (Map_::iterator i (map_->begin ()); i != map_->end (); ++i)
        {
          //std::wcerr << "revoking " << i->second
          //           << " to " << container_ << std::endl;

          container_->unregister_id (*(i->first));
        }
      }

      // Copy registrations to our new container.
      //
      if (c != 0 && map_.get ())
      {
        for (Map_::iterator i (map_->begin ()); i != map_->end (); ++i)
        {
          //std::wcerr << "copying " << i->second
          //           << " to " << c << std::endl;

          c->register_id (*(i->first), i->second);
        }
      }

      container_  = c;
    }

    //@@
    //protected:

  public:
    void
    register_id (IdentityProvider const& id, Type* t)
    {
      if (map_.get () == 0)
      {
        map_ = std::auto_ptr<Map_> (new Map_);
      }

      if (!map_->insert (
            std::pair<IdentityProvider const*, Type*> (&id, t)).second)
      {
        throw 1;
      }

      if (container () != this) container ()->register_id (id, t);
    }

    void
    unregister_id (IdentityProvider const& id)
    {
      if (map_.get ())
      {
        Map_::iterator it (map_->find (&id));

        if (it != map_->end ())
        {
          map_->erase (it);

          if (container () != this) container ()->unregister_id (id);

          return;
        }
      }

      throw 1;
    }

    Type*
    lookup_id (IdentityProvider const& id) const
    {
      if (map_.get ())
      {
        Map_::const_iterator it (map_->find (&id));

        if (it != map_->end ())
        {
          return it->second;
        }
      }

      return 0;
    }


  private:
    Type* container_;

    struct IdentityComparator
    {
      bool operator () (IdentityProvider const* x,
                        IdentityProvider const* y) const
      {
        return x->before (*y);
      }
    };

    typedef
    std::map<IdentityProvider const*, Type*, IdentityComparator>
    Map_;

    std::auto_ptr<Map_> map_;
  };

  // Fundamental types template.
  //
  //
  template <typename X>
  class FundamentalType : public Type
  {
  public:
    //    typedef ACE_Refcounted_Auto_Ptr < FundamentalType, ACE_Null_Mutex > _ptr;
    
    FundamentalType ()
    {
    }

    template<typename C>
    FundamentalType (XML::Element<C> const& e)
    {
      std::basic_stringstream<C> s;
      s << e.value ();
      s >> x_;
    }

    template<typename C>
    FundamentalType (XML::Attribute<C> const& a)
    {
      std::basic_stringstream<C> s;
      s << a.value ();
      s >> x_;
    }

    FundamentalType (X const& x)
        : x_ (x)
    {
    }

    FundamentalType&
    operator= (X const& x)
    {
      x_ = x;
      return *this;
    }

  public:

    operator X const& () const
    {
      return x_;
    }
    /*
    operator X& ()
    {
      return x_;
    }
    */
  protected:
    X x_;
  };

#if ((defined (__GNUC__) && (__GNUC__ == 3 && (__GNUC_MINOR__ < 3))) || \
    (defined (__BORLANDC__) && (__BORLANDC__ == 0x610)) || \
    (defined (__SUNPRO_CC) && (__SUNPRO_CC <= 0x570)))

  // Stuff for broken gcc < 3.3. Don't like what you see - use better
  // compiler!
  //

  // Specialization for signed char.
  //
  template <>
  class FundamentalType<signed char> : public Type
  {
  public:
    FundamentalType ()
    {
    }

    template<typename C>
    FundamentalType (XML::Element<C> const& e)
    {
      std::basic_stringstream<C> s;
      s << e.value ();

      short t;
      s >> t;

      x_ = static_cast<signed char> (t);
    }

    template<typename C>
    FundamentalType (XML::Attribute<C> const& a)
    {
      std::basic_stringstream<C> s;
      s << a.value ();

      short t;
      s >> t;

      x_ = static_cast<signed char> (t);
    }

    FundamentalType (signed char const& x)
        : x_ (x)
    {
    }

    FundamentalType&
    operator= (signed char const& x)
    {
      x_ = x;
      return *this;
    }

  public:
    operator signed char const& () const
    {
      return x_;
    }

    operator signed char& ()
    {
      return x_;
    }

  protected:
    signed char x_;
  };

  // Specialization for unsigned char.
  //
  template <>
  class FundamentalType<unsigned char> : public Type
  {
  public:
    FundamentalType ()
    {
    }

    template<typename C>
    FundamentalType (XML::Element<C> const& e)
    {
      std::basic_stringstream<C> s;
      s << e.value ();

      unsigned short t;
      s >> t;

      x_ = static_cast<unsigned char> (t);
    }

    template<typename C>
    FundamentalType (XML::Attribute<C> const& a)
    {
      std::basic_stringstream<C> s;
      s << a.value ();

      unsigned short t;
      s >> t;

      x_ = static_cast<unsigned char> (t);
    }

    FundamentalType (unsigned char const& x)
        : x_ (x)
    {
    }

    FundamentalType&
    operator= (unsigned char const& x)
    {
      x_ = x;
      return *this;
    }

  public:
    operator unsigned char const& () const
    {
      return x_;
    }

    operator unsigned char& ()
    {
      return x_;
    }

  protected:
    unsigned char x_;
  };

#else

  // Stuff for normal compilers.
  //

  // Specialization for `signed char'
  //
  //
  template<>
  template<typename C>
  inline
  FundamentalType<signed char>::
  FundamentalType (XML::Element<C> const& e)
  {
    std::basic_stringstream<C> s;
    s << e.value ();

    short t;
    s >> t;

    x_ = static_cast<signed char> (t);
  }

  template<>
  template<typename C>
  inline
  FundamentalType<signed char>::
  FundamentalType (XML::Attribute<C> const& a)
  {
    std::basic_stringstream<C> s;
    s << a.value ();

    short t;
    s >> t;

    x_ = static_cast<signed char> (t);
  }

  // Specialization for `unsigned char'
  //
  //
  template<>
  template<typename C>
  inline
  FundamentalType<unsigned char>::
  FundamentalType (XML::Element<C> const& e)
  {
    std::basic_stringstream<C> s;
    s << e.value ();

    unsigned short t;
    s >> t;

    x_ = static_cast<unsigned char> (t);
  }

  template<>
  template<typename C>
  inline
  FundamentalType<unsigned char>::
  FundamentalType (XML::Attribute<C> const& a)
  {
    std::basic_stringstream<C> s;
    s << a.value ();

    unsigned short t;
    s >> t;

    x_ = static_cast<unsigned char> (t);
  }

#endif


  // Specialization for bool.
  //
  //

  template<>
  template<>
  inline
  FundamentalType<bool>::
  FundamentalType (XML::Element<char> const& e)
  {
    x_ = (e.value () == "true") || (e.value () == "1");
  }

  template<>
  template<>
  inline
  FundamentalType<bool>::
  FundamentalType (XML::Element<wchar_t> const& e)
  {
    x_ = (e.value () == L"true") || (e.value () == L"1");
  }

  template<>
  template<>
  inline
  FundamentalType<bool>::
  FundamentalType (XML::Attribute<char> const& a)
  {
    x_ = (a.value () == "true") || (a.value () == "1");
  }

  template<>
  template<>
  inline
  FundamentalType<bool>::
  FundamentalType (XML::Attribute<wchar_t> const& a)
  {
    x_ = (a.value () == L"true") || (a.value () == L"1");
  }
}

#include "XSCRT/Elements.ipp"
#include "XSCRT/Elements.tpp"

#endif  // XSCRT_ELEMENTS_HPP
