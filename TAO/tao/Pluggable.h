// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     Pluggable.h
//
// = DESCRIPTION
//     Interface for the TAO pluggable protocol frameowrk.
//
// = AUTHOR
//     Fred Kuhns <fredk@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_PLUGGABLE_H
#define TAO_PLUGGABLE_H

#include "tao/corbafwd.h"
#include "tao/Typecode.h"

// Forward declarations.
class ACE_Addr;
class ACE_Reactor;
class TAO_ORB_Core;

class STUB_Object;
class TAO_Profile;
class TAO_MProfile;
class TAO_Resource_Factory;

class TAO_Export TAO_Transport
{
  // = TITLE
  //   Generic definitions for the new Transport class.
  // 
  // = DESCRIPTION
  //   The transport object is created in the Service handler
  //   constructor and deleted in the service handlers destructor!!

public:
  virtual CORBA::ULong tag (void) = 0;
  // The tag, each concrete class will have a specific tag value.

  virtual void close_connection() = 0;
  // Call the corresponding connection handler's <handle_close>
  // method.
  
  virtual void resume_connection (ACE_Reactor *reactor) = 0;
  // Calls the Reactor's <resume_handler> on behalf of the
  // corresponding connection handler.
  // @@ Fred: who does the suspend_handler thing? The transport object 
  //    itself? Can we clarify the relantionship between PP and the
  //    leader-follower protocol on the client side.

  virtual int idle (void) = 0;
  // Idles the corresponding connection handler.

  virtual int is_nil (TAO_Transport *obj) = 0;
  // returns 0 if the obj is 0.
  // @@ Fred: what are this two methods? Are they related to the
  //    IDL-generated methods of similar names? You may want to know
  //    that they added those methods for ORBs that map Foo_ptr to a
  //    class instead of Foo*, but we are not required to do that for
  //    PP, right?

  virtual TAO_Transport *_nil (void) = 0;
  // Return a NULL pointer of type TAO_Transport *.
  
  virtual ACE_HANDLE handle (void) = 0;
  // This is primarily used for error and debugging messages!
  // @@ Fred: what about connecting to the reactor?

  virtual ssize_t send (const ACE_Message_Block *mblk,
                        ACE_Time_Value *s = 0) = 0;
  // Write the contents of the Message_Block to the connection.
  // @@ Fred: I assume this writes the complete message block chain?
  //    Can you document that? Can this be written in the base class
  //    in terms of send(iovec)? Ditto for the next method?
  // @@ Fred: why do we have time values here?  Isn't the time out
  //    going to be obtained from the policies in the ORB?

  virtual ssize_t send (const u_char *buf,
                        size_t len,
                        ACE_Time_Value *s = 0) = 0;
  // Write the contents of the buffer of length len to the connection.

  virtual ssize_t send (const iovec *iov,
                        int iovcnt,
                        ACE_Time_Value *s = 0) = 0;
  // Write the contents of iovcnt iovec's to the connection.

  virtual ssize_t recv (char *buf,
                        size_t len,
                        ACE_Time_Value *s = 0) = 0;
  // Read len bytes from into buf.

  virtual ssize_t recv (char *buf,
                        size_t len,
                        int flags,
                        ACE_Time_Value *s = 0) = 0;
  // Read len bytes from into buf using flags.

  virtual ssize_t recv (iovec *iov,
                        int iovcnt,
                        ACE_Time_Value *s = 0) = 0;
  //  Read received data into the iovec buffers.

  virtual int send_request (TAO_ORB_Core *orb_core, 
                            TAO_OutputCDR &stream, 
                            int twoway) = 0;
  // Default action to be taken for send request.
  // @@ Fred: doesn't this just delegate on send(message_block)?
  //    Couldn't we implement this method on the base class?

  //  virtual int send_response (TAO_OutputCDR &response) = 0;

  virtual ~TAO_Transport (void);
};

class TAO_Export TAO_IOP_Version 
{
  // = TITLE
  //   Major and Minor version number of the Inter-ORB Protocol.
public:
  CORBA::Octet major;
  // Major version number

  CORBA::Octet minor;
  // Minor version number
  
  TAO_IOP_Version (const TAO_IOP_Version &src);
  // Copy constructor

  TAO_IOP_Version (CORBA::Octet maj = 0, 
           CORBA::Octet min = 0);
  // Default constructor.

  ~TAO_IOP_Version (void);
  // Destructor.

  void set_version (CORBA::Octet maj, CORBA::Octet min);
  // Explicitly set the major and minor version.

  TAO_IOP_Version &operator= (const TAO_IOP_Version &src);
  // Copy operator.

  int operator== (const TAO_IOP_Version &src);
  // Equality operator

  int operator== (const TAO_IOP_Version *&src);
  // Equality operator
};

// @@ Fred: we must implement the TAO_Generic_Profile class too!
class TAO_Export TAO_Profile
{
  // = TITLE
  //   Generic Profile definitions.
  //
  // = DESCRIPTION
  //   @@ Fred, please fill in here.
  //
public:
  virtual CORBA::ULong tag (void) const = 0;
  // The tag, each concrete class will have a specific tag value.
  // @@ Fred, any reason this cannot be implemented in the base class?
  //    Do you want to save the memory required to store the tag_ for
  //    the time required to call the virtual function?

  virtual int parse (TAO_InputCDR& cdr, 
                     CORBA::Boolean& continue_decoding, 
                     CORBA::Environment &env) = 0;
  // Initialize this object using the given CDR octet string.

  virtual int parse_string (const char *string,
                            CORBA::Environment &env) = 0;
  // Initialize this object using the given input string.
  // @@ Fred: is this function (and the next) to support URL style
  //    object references? I'm not sure we want to support them for
  //    all protocols, it was just a convinience for IIOP, mostly for
  //    ease of debugging.  The utils/catior program should help with
  //    that though.
  //    Having said that: this sounds like an interesting way to
  //    support an extensible framework for the interoperable naming
  //    service bootstrapping procotol.

  virtual CORBA::String to_string (CORBA::Environment &env) = 0;
  // Return a string representation for this profile.  client must
  // deallocate memory.

  virtual const TAO_opaque &body (void) const = 0;
  // The body, an octet sequence that represent the marshaled
  // profile.
  // @@ Fred: We have to think about this method: it basically
  //          requires the profile to keep both the <body> and the
  //          interpreted representation (as host/port/etc.)
  //          This is good for performance reasons, but it may consume 
  //          too much memory, maybe a method like this:
  //
  //          void body (TAO_opaque& return_body) const = 0;
  //
  //          will work better.

  virtual int encode (TAO_OutputCDR &stream) const = 0;
  // Encode this profile in a stream, i.e. marshal it.
  // @@ Fred: notice the correct use of const and references in this
  //    method ;-)

  virtual const TAO_ObjectKey &object_key (void) const = 0;
  // @@ deprecated. return a reference to the Object Key.
  // @@ Fred: if it is deprecated why don't we just remove it?

  TAO_ObjectKey &object_key (TAO_ObjectKey& objkey);
  // @@ deprecated. set the Object Key.
  // @@ Fred: does it make sense to have a method to modify the object 
  //    key?

  virtual TAO_ObjectKey *_key (CORBA::Environment &env) = 0;
  // Obtain the object key, return 0 if the profile cannot be parsed.
  // The memory is owned by this object (not given to the caller).
  
  virtual void forward_to (TAO_MProfile *mprofiles) = 0;
  // object will assume ownership for this object!!
  // @@ Fred: this is a bit counterintuitive, the usual rules CORBA
  //    are: 
  //    1) Memory passed to an operations is owned by the caller.
  //    2) Memory returned from a call is owned by the caller.
  //
  //    C++ is more flexible about this but the common rule is:
  //    1) Pointers returned are owned by the callee.
  //    2) Pointers passed are owned by the caller.
  //
  //    One good thing about references it that it leaves on ambiguity 
  //    about this.
  //    The principle of least surprize will recommend that you use
  //    any of the approaches above, but not the protocol that you propose.

  virtual TAO_MProfile *forward_to (void) = 0;
  // copy of MProfile, user must delete.

  virtual CORBA::Boolean is_equivalent (TAO_Profile* other_profile,
                                        CORBA::Environment &env) = 0;
  // Return true if this profile is equivalent to other_profile.  Two
  // profiles are equivalent iff their key, port, host, object_key and
  // version are the same.

  virtual CORBA::ULong hash (CORBA::ULong max,
                             CORBA::Environment &env) = 0;
  // Return a hash value for this object.

  virtual ASYS_TCHAR *addr_to_string(void) = 0;
  // Return a string representation for the address.
  // @@ Fred: who owns the string returned?

  virtual void reset_hint (void) = 0;
  // This method is used with a connection has been reset requiring
  // the hint to be cleaned up and reset to NULL.

  virtual TAO_Profile *_nil (void) = 0;
  // Return a null object pointer.
  // @@ Fred: what is this method used for? Is this similar to the
  //    *static* methods generated for IDL objects?

  virtual CORBA::ULong _incr_refcnt (void) = 0;
  // Increase the reference count by one on this object.

  virtual CORBA::ULong _decr_refcnt (void) = 0;
  // Decrement the object's reference count.  When this count goes to
  // 0 this object will be deleted.
  // @@ Fred: reference counting can be implemented in the base class!

protected:
  virtual TAO_MProfile *forward_to_i (void) = 0;
  // this object keeps ownership of this object

  virtual ~TAO_Profile (void);
  // If you have a virtual method you need a virtual dtor.
};

class TAO_Export TAO_Acceptor
{
  // = TITLE
  //   Abstract Acceptor class used for pluggable protocols.
  //
  // = DESCRIPTION
  //   @@ Fred, please fill in here.
public:

  virtual TAO_Profile *create_profile (TAO_ObjectKey &object_key) = 0;
  // Create the corresponding profile for this endpoint.
  // @@ Fred: that <object_key> should be const.
  // @@ Fred: we haven't thought about acceptors that service more
  //    than one endpoint (for example: listening on sap_any). Maybe a 
  //    better interface is:
  //    virtual int add_profiles (const TAO_ObjectKey& key,
  //                              TAO_MProfile& mprofile) const = 0;
  //    // Add the profiles serviced by this acceptor to the
  //    // <mprofile> list. Use <key> to fill in the profiles.

  virtual ACE_Event_Handler *acceptor (void) = 0;
  // Return the ACE acceptor...
  // @@ Fred: could this method be const?

  virtual CORBA::ULong tag (void) = 0;
  // The tag, each concrete class will have a specific tag value.

  virtual ~TAO_Acceptor (void);
  // Destructor
};

class TAO_Export TAO_Connector
{
  // = TITLE
  //   Connector Registry and Generic Connector interface definitions.
  //
  // = DESCRIPTION
  //   @@ Fred, please fill in here.
public:

  // @@ Fred: the more I think about it the more the Connectors seem
  //    to be the entry point to a complete protocol, for example:
  //    this looks like the correct spot to add a method like:
  //    virtual TAO_Acceptor* acceptor (const char* endpoint) = 0;
  //    // Create a new acceptor from an endpoint specification, if
  //    // the specification is not recognized then we return 0.
  //    // Each protocol will be characterized by a prefix, so
  //    // endpoints will be specified as:
  //    // "iiop:macarena:0" - IIOP on macarena, port <any>
  //    // "uiop:/foo/bar"   - GIOP over unix domain, file /foo/bar
  //    // "iiop:localhost:0" - IIOP, sap_any [any better idea?]
  //    // "aal5giop:......"   - GIOP over AAL5, how to specify the
  //    //                       end point?
  //    //
  //    // this format is extensible, for example:
  //    // "rtiiop:macarena:0,15" - real-time IIOP, host, port, prio.
  //
  //    Anyway, maybe the method does not belong here, but it belongs
  //    somewhere.
  //    Note: On second thought: Connectors should be per-ORB objects,
  //          but the set of PP is more like a per-process thing.
  //          Maybe there should be a ProtocolRegistry as you
  //          suggested, that acts as a factory of both connectors and 
  //          acceptors.
  //
  
  virtual int preconnect (char *preconnections) = 0;
  // Initial set of connections to be established.
  // @@ Fred: Any better way to express the connections? Should they
  //          include the protocol prefix shown above?

  virtual int open (TAO_Resource_Factory *trf,
                    ACE_Reactor *reactor) = 0;
  //  Initialize object and register with reactor.

  virtual int close (void) = 0;
  // Shutdown Connector bridge and concreate Connector. 

  virtual CORBA::ULong tag (void) = 0;
  // The tag identifying the specific ORB transport layer protocol.
  // For example TAO_IOP_TAG_INTERNET_IOP = 0.  The tag is used in the
  // IOR to identify the type of profile included. IOR -> {{tag0,
  // profile0} {tag1, profole1} ...}  GIOP.h defines typedef
  // CORBA::ULong TAO_IOP_Profile_ID;

  virtual TAO_Transport *connect(TAO_Profile *profile,
                                 CORBA::Environment &env) = 0;
  // To support pluggable we need to abstract away the connect()
  // method so it can be called from the GIOP code independant of the
  // actual transport protocol in use.
  // @@ Fred: notice the change in interface: it takes a profile,
  //    stores the hint on it but returns the transport, that makes
  //    this method thread safe. We don't care if other threads change 
  //    the hint, we will receive the right transport anyway.

  virtual ~TAO_Connector (void);
  // the destructor.
}; 

class TAO_Export TAO_Connector_Registry
{
  // = TITLE
  //   All loaded ESIOP or GIOP connector bridges must register with
  //   this object.
  // 
  // = DESCRIPTION
  //   @@ Fred, please fill in here.
  //   @@ Fred: this class should be able to dynamically load a set of 
  //            connectors using the service configurator.
  //   @@ Fred: We have to start working on the acceptor registry.
public:
  TAO_Connector_Registry (void);
  //  Default constructor.

  ~TAO_Connector_Registry (void);
  //  Default destructor. 

  TAO_Connector *get_connector (CORBA::ULong tag);
  // Return the connector bridge corresponding to tag (IOP).

  CORBA::Boolean add_connector (TAO_Connector *connector);
  // All TAO_Connectors will have a tag() member which will be used
  // for registering object, as well as type checking.

  int open (TAO_Resource_Factory *trf,
            ACE_Reactor *reactor);
  // Initialize all registered connectors.

  int close_all (void);
  // Close all open connectors.

  int preconnect (const char *the_preconnections);
  // For this list of preconnections call the connector specific
  // preconnect method for each preconnection.

  TAO_Transport *connect (STUB_Object *&obj,
                          CORBA::Environment &env);
  // This is where the transport protocol is selected based on some
  // policy.  This member will call the connect member of the
  // TAO_Connector class which in turn will call the concrete
  // connector.

private:
  TAO_Connector *iiop_connector_;
  // @@ for now this is all we support!  This next iteration will be a
  // bit more generic.  Something like a key, value pair with key
  // equil to the IOP_TYPE and value a pointer to the Connector.
};

#endif  /* TAO_PLUGGABLE_H */
