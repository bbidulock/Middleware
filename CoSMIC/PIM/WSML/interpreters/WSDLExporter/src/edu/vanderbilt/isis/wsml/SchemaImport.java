/* Generated on Sat Jul 29 22:41:36 2006 */

/* This is a generalt file, do not modify its content.
 * Copyright (c) Vanderbilt University, 2000-2005
 * ALL RIGHTS RESERVED
 * Vanderbilt University disclaims all warranties with regard to this 
 * software, including all implied warranties of merchantability and 
 * fitness.  In no event shall Vanderbilt University be liable for any 
 * special, indirect or consequential damages or any damages whatsoever
 * resulting from loss of use, data or profits, whether in an action of
 * contract, negligence or other tortious action, arising out of or in 
 * connection with the use or performance of this software.	
 */

package edu.vanderbilt.isis.wsml;

import edu.vanderbilt.isis.udm.*;

/**
 * Domain specific class of <code>SchemaImport</code>.
 */ 
public class SchemaImport extends SchemaReference
{
	// meta information
	public static final String META_TYPE = "SchemaImport";
	public static final String META_TYPE_NS = "";
	private static UdmPseudoObject metaClass;

	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance 
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	protected SchemaImport(UdmPseudoObject upo, Diagram metaDiagram) 
		throws UdmException
	{
		super(upo, metaDiagram);
	}

	/**
	 * Returns the meta class.
	 * @return  The meta class
	 */ 
	UdmPseudoObject getMetaClass()
	{
		return metaClass;
	}

	/* Construction */

	/**
	 * Creates an instance of the class in the container specified by the parameter. 
	 * @param  parent The parent container
	 * @return  An instance of the class <code>SchemaReference</code>
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public static SchemaReference create(Schema parent) 
		throws UdmException 
	{
		Diagram metaDiagram = parent.getDiagram();
		return new SchemaImport(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/* Accessing children */

	/* Attribute setters, getters */

	/**
	 * Attribute for <code>namespace</code>.
	 */
	public static final String namespace = "namespace";

	/**
	 * Sets the value of the attribute <code>namespace</code> to a value specified by the parameter.
	 * @param _v The new value of the attribute
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public void setnamespace(String _v)
		throws UdmException 
	{
		setStringVal(namespace, _v);
	}

	/**
	 * Returns the value of the attribute <code>namespace</code>.
	 * @return  The value
	 * @throws  UdmException If any Udm related exception occured
	 */ 
	public String getnamespace()
		throws UdmException 
	{
		return getStringVal(namespace);
	}

	/* Associations */

}
