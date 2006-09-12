<?xml version="1.0" encoding="UTF-8"?>

<!DOCTYPE softpkg PUBLIC "-//OMG//DTD CORBA Software Descriptor 3.0//EN" "http://openccm.objectweb.org/dtd/ccm/softpkg.dtd">
<softpkg version="0,8,0,0" name="Client">
  <title>OpenCCM BandwidthBroker Client</title>
  <pkgtype version="">CORBA Component</pkgtype>
  <author>
    <name>VB</name>
    <company>Prismtech</company>
    <webpage href="http://www.prismtechnologies.com" xml:link="SIMPLE"></webpage>
  </author>
  <description>BWBroker Client Component</description>
  <license href="http://openccm.objectweb.org/license.html" xml:link="SIMPLE"></license>
  <idl homeid="IDL:/mil/darpa/arms/mlrm/BandwidthBroker/ClientHome:1.0" id="IDL:/mil/darpa/arms/mlrm/BandwidthBroker/Client:1.0">
    <link href="BandwidthBroker.idl3" xml:link="SIMPLE"></link>
  </idl>
  <implementation variation="" id="ClientImpl">
    <code type="Java Class">
      <fileinarchive name="archives/client.jar">
      </fileinarchive>
      <entrypoint>mil.darpa.arms.mlrm.BandwidthBroker.cif.ClientHomeImpl.create_home</entrypoint>
    </code>
    <compiler version="1.4.2" name="JDK"/>
    <programminglanguage version="" name="Java"/>
    <os version="" name="Windows XP"/>
    <os version="2,4,20,0" name="Linux"/>
    <processor name="x86"/>
    <runtime version="1,3,1,0" name="Java VM"/>
  </implementation>
</softpkg>
