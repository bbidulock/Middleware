// @(#)iioporb.cpp	1.8 95/09/19
// Copyright 1994-1995 by Sun Microsystems Inc.
// All Rights Reserved
//
// IIOP:		ORB pseudo-object
//
// This includes objref stringification/destringification for IIOP object
// references.
//

#include	<assert.h>
#include	<limits.h>
#include	<string.h>
#include	<corba/orb.hh>

#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<initguid.h>
#include	<corba/stub.hh>

#include	"runtime/cdr.hh"
#include	"bridge/iioporb.hh"
#include	"bridge/iiopobj.hh"


static const char ior_prefix [] = "IOR:";
static const char iiop_prefix [] = "iiop:";
static const char xchars [] = "0123456789abcdef";


//
// hex conversion utilities
//
static inline char
nibble2hex (unsigned n)
{
    return xchars [n & 0x0f];
}

static inline
unsigned char
hex2byte (char c)
{
    if (isdigit (c))
	return (unsigned char) (c - '0');
    else if (islower (c))
	return (unsigned char) (10 + c - 'a');
    else
	return (unsigned char) (10 + c - 'A');
}


//
// Objref stringification
//
CORBA_String
IIOP_ORB::object_to_string (
    CORBA_Object_ptr	obj,
    CORBA_Environment	&env
)
{
    env.clear ();

    //
    // Application writer controls what kind of objref strings they get,
    // maybe along with other things, by how they initialize the ORB.
    //
    if (use_omg_ior_format) {

	//
	// By default, orbs use IOR strings; these are ugly (and error
	// prone) but specified by CORBA. 
	//
	// XXX there should be a simple way to reuse this code in other
	// ORB implementations ...
	//
	unsigned char		*bytes, buf [BUFSIZ];
	CDR			cdr (buf, sizeof buf, MY_BYTE_SEX);

	bytes = buf;
	(void) memset (bytes, 0, BUFSIZ);	// support limited oref strcmp

	//
	// Marshal the objref into an encapsulation bytestream.
	//
	(void) cdr.put_char (MY_BYTE_SEX);
	if (CDR::encoder (_tc_CORBA_Object, &obj, 0, &cdr, env)
		    != CORBA_TypeCode::TRAVERSE_CONTINUE)
	    return 0;

	//
	// Now hexify the encapsulated CDR data into a string,
	// and return that string.
	//
	CORBA_String	string, cp;
	size_t		len = cdr.length - cdr.remaining;

	string = CORBA_string_alloc (sizeof ior_prefix + 2 * len);
	strcpy ((char *)string, ior_prefix);

	for (cp = (CORBA_String) strchr ((char *)string, ':') + 1,
		    bytes = cdr.buffer;
		len--; bytes++) {
	    *cp++ = nibble2hex ((*bytes) >> 4);
	    *cp++ = nibble2hex (*bytes);
	}
	*cp = 0;
	return string;
    } else {
	//
	// The "internet" ORB uses readable URL style objrefs, as
	// used in the World Wide Web.
	//
	// NOTE:  the version ID in the string is ugly but we can't
	// realistically eliminate it by any "assume 1.0" strategy...
	// Similarly with the port, because there's no single IIOP
	// port to which we could default.
	//
	static const char	digits [] = "0123456789";

	//
	// This only works for IIOP objrefs.  If we're handed an objref
	// that's not an IIOP objref, fail -- application must use an
	// ORB that's configured differently.
	//
	IIOP_Object		*obj2;

	if (obj->QueryInterface (IID_IIOP_Object, (void **)&obj2)
		!= NOERROR) {
	    env.exception (new CORBA_DATA_CONVERSION (COMPLETED_NO));
	    return 0;
	}

	if (!obj2)			// null?
	    return CORBA_string_copy ((CORBA_String) iiop_prefix);

	char			buf [BUFSIZ + 2];

	sprintf (buf, "%s%c.%c//%s:%d/", iiop_prefix,
		digits [obj2->profile.iiop_version.major],
		digits [obj2->profile.iiop_version.minor],
		obj2->profile.host, obj2->profile.port);

	char		*cp = strchr (buf, 0);
	unsigned	len;
	unsigned char	*byte;

	for (len = (unsigned) obj2->profile.object_key.length,
		    byte = obj2->profile.object_key.buffer;
		cp < &buf [BUFSIZ] && len != 0;
		len--, byte++) {
	    if (isascii (*byte) && isprint (*byte) && *byte != '\\') {
		*cp++ = (char) *byte;
		continue;
	    }

	    //
	    // NOTE: this could run two characters past &buf[BUFSIZ],
	    // which is why buf is exactly two characters bigger than
	    // that ... saves coding a test here.
	    //
	    *cp++ = '\\';
	    *cp++ = nibble2hex (*byte & 0x0f);
	    *cp++ = nibble2hex ((*byte >> 4) & 0x0f);
	}
	if (cp >= &buf [BUFSIZ]) {
	    env.exception (new CORBA_IMP_LIMIT (COMPLETED_NO));
	    return 0;
	}
	*cp = 0;
	return CORBA_string_copy ((CORBA_String) &buf[0]);
    }
}


//
// Destringify OMG-specified "IOR" string.
//
// XXX there should be a simple way to reuse this code in other
// ORB implementations ...
//
static CORBA_Object_ptr
ior_string_to_object (
    CORBA_String	str,
    CORBA_Environment	&env
)
{
    //
    // Unhex the bytes, and make a CDR deencapsulation stream
    // from the resulting data.
    //
    unsigned char	*buffer = new
			    unsigned char [1 + strlen ((char *) str) / 2];
    char		*tmp = (char *)str;
    size_t		len = 0;
    
    while (tmp [0] && tmp [1]) {
	unsigned char	byte;

	if (!(isxdigit (tmp [0]) && isxdigit (tmp [1])))
	    break;

	byte = (unsigned char) (hex2byte (tmp [0]) << 4);
	byte |= hex2byte (tmp [1]);

	buffer [len++] = byte;
	tmp += 2;
    }
    if (tmp [0] && !isspace (tmp [0])) {
	delete buffer;
	env.exception (new CORBA_BAD_PARAM (COMPLETED_NO));
	return 0;
    }

    //
    // Create deencapsulation stream ... then unmarshal objref
    // from that stream.
    //
    CDR			stream;
    CORBA_Object_ptr	objref;
    
    stream.setup_encapsulation (buffer, len);
    if (CDR::decoder (_tc_CORBA_Object, &objref, 0, &stream, env)
	    != CORBA_TypeCode::TRAVERSE_CONTINUE) {
	objref = 0;
    }

    delete buffer;
    return objref;
}


//
// Destringify URL style IIOP objref.
//
static CORBA_Object_ptr
iiop_string_to_object (
    CORBA_String	string,
    CORBA_Environment	&env
)
{
    //
    // NIL objref encodes as just "iiop:" ... which has already been
    // removed, so we see it as an empty string.
    //
    if (!string || !*string)
	return 0;
	
    //
    // type ID not encoded in this string ... makes narrowing rather
    // expensive, though it does ensure that type-safe narrowing code
    // gets thoroughly excercised/debugged!
    //
    IIOP_Object		*data = new IIOP_Object (0);	// null type ID

    //
    // Remove the "N.N//" prefix, and verify the version's one
    // that we accept
    //
    if (isdigit (string [0]) && isdigit (string [2]) && string [1] == '.'
		&& string [3] == '/' && string [4] == '/') {
	data->profile.iiop_version.major = (char) (string [0] - '0');
	data->profile.iiop_version.minor = (char) (string [2] - '0');
	string += 5;
    } else {
	env.exception (new CORBA_DATA_CONVERSION (COMPLETED_NO));
	data->Release ();
	return 0;
    }
    if (data->profile.iiop_version.major != IIOP::MY_MAJOR
		|| data->profile.iiop_version.minor > IIOP::MY_MINOR) {
	env.exception (new CORBA_DATA_CONVERSION (COMPLETED_NO));
	data->Release ();
	return 0;
    }

    //
    // Pull off the "hostname:port/" part of the objref
    //
    char		*cp;

    if ((cp = strchr (string, ':'))== 0) {
	env.exception (new CORBA_DATA_CONVERSION (COMPLETED_NO));
	data->Release ();
	return 0;
    }

    data->profile.host = CORBA_string_alloc (1 + cp - string);
    for (cp = data->profile.host; *string != ':'; *cp++ = *string++)
	continue;
    *cp = 0;
    string++;

    if ((cp = strchr ((char *)string, '/')) == 0) {
	env.exception (new CORBA_DATA_CONVERSION (COMPLETED_NO));
	CORBA_string_free (data->profile.host);
	data->Release ();
	return 0;
    }

    data->profile.port = (short) atoi ((char *)string);
    string = ++cp;

    //
    // Parse the key ... it's ASCII plus hex escapes for everything
    // nonprintable.  This assumes that printable ASCII is the common
    // case ... but since stringification is uncommon, no big deal.
    //
    data->profile.object_key.buffer
	    = (unsigned char *) CORBA_string_copy (string);

    //
    // Strip out whitespace and adjust length accordingly.
    //
    for (cp = (char *) data->profile.object_key.buffer; *cp; cp++) {
	if (!isprint (*cp)) {
	    *cp = '\0';
	    break;
	}
    }
    string = (char *) data->profile.object_key.buffer;
    data->profile.object_key.length = strlen (string);
    data->profile.object_key.maximum = data->profile.object_key.length;

    //
    // Strip out hex escapes and adjust the key's length appropriately.
    //
    while ((cp = 
	    strchr ((char *)data->profile.object_key.buffer, '\\')) != 0) {
	*cp = (CORBA_Char) (hex2byte ((char) cp [1]) << 4);
	*cp |= (CORBA_Char) hex2byte ((char) cp [2]);
	cp++;

	size_t		len = strlen (cp);

	memcpy (cp, cp+2, len - 2);
	data->profile.object_key.length -= 2;
    }

    //
    // Return the objref.
    //
    CORBA_Object_ptr	obj;

    (void) data->QueryInterface (IID_CORBA_Object, (void **)&obj);
    data->Release ();
    return obj;
}


//
// Destringify arbitrary objrefs.
//
CORBA_Object_ptr
IIOP_ORB::string_to_object (
    CORBA_String	str,
    CORBA_Environment	&env
)
{
    env.clear ();

    //
    // Use the prefix code to choose which destringify algorithm to use.
    //
    if (strncmp ((char *)str, iiop_prefix, sizeof iiop_prefix - 1) == 0)
	return iiop_string_to_object (str + sizeof iiop_prefix - 1, env);

    if (strncmp ((char *)str, ior_prefix, sizeof ior_prefix - 1) == 0)
	return ior_string_to_object (str + sizeof ior_prefix - 1, env);

    env.exception (new CORBA_BAD_PARAM (COMPLETED_NO));
    return 0;
}

//
// COM IUnknown support
//

// {A201E4C4-F258-11ce-9598-0000C07CA898}
DEFINE_GUID (IID_IIOP_ORB,
0xa201e4c4, 0xf258, 0x11ce, 0x95, 0x98, 0x0, 0x0, 0xc0, 0x7c, 0xa8, 0x98);


HRESULT
__stdcall
IIOP_ORB::QueryInterface (
    REFIID	riid,
    void	**ppv
)
{
    *ppv = 0;

    if (IID_CORBA_ORB == riid
	    || IID_IIOP_ORB == riid
	    || IID_IUnknown == riid)
	*ppv = this;

    //
    // XXX gotta aggregate ...
    //

    if (*ppv == 0)
	return ResultFromScode (E_NOINTERFACE);

    (void) AddRef ();
    return NOERROR;
}
