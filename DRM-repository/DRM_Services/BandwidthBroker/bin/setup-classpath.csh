#!/bin/csh
set bb_cp=${JAVA_HOME}/bin:.:../../../Middleware/JacORB2.1/lib/jacorb.jar:../../../Middleware/JacORB2.1/lib/logkit-1.2.jar:../../../Middleware/JacORB2.1/lib/avalon-framework-4.1.5.jar:../../../Middleware/JacORB2.1/lib/concurrent-1.3.2.jar:../../../Middleware/JacORB2.1/lib/antlr-2.7.2.jar:../../../Middleware/JacORB2.1/lib/idl.jar:../../../Middleware/MySQL/lib/mm.mysql-2.0.14-bin.jar:../../../Middleware/log4j/lib/log4j-1.2.8.jar:../../../Middleware/JacORB2.1/lib/wrapper-3.0.3.jar:../../../Middleware/Telcordia/lib/telcordia-jIOS.jar:../classes:../../../Middleware/JWSDP1.3/lib/activation.jar:../../../Middleware/JWSDP1.3/lib/commons-beanutils.jar:../../../Middleware/JWSDP1.3/lib/commons-collections.jar:../../../Middleware/JWSDP1.3/lib/commons-digester.jar:../../../Middleware/JWSDP1.3/lib/commons-logging.jar:../../../Middleware/JWSDP1.3/lib/dom.jar:../../../Middleware/JWSDP1.3/lib/jaas.jar:../../../Middleware/JWSDP1.3/lib/jax-qname.jar:../../../Middleware/JWSDP1.3/lib/jaxb-api.jar:../../../Middleware/JWSDP1.3/lib/jaxb-impl.jar:../../../Middleware/JWSDP1.3/lib/jaxb-libs.jar:../../../Middleware/JWSDP1.3/lib/jaxb-xjc.jar:../../../Middleware/JWSDP1.3/lib/jaxp-api.jar:../../../Middleware/JWSDP1.3/lib/jta-spec1_0_1.jar:../../../Middleware/JWSDP1.3/lib/mail.jar:../../../Middleware/JWSDP1.3/lib/namespace.jar:../../../Middleware/JWSDP1.3/lib/relaxngDatatype.jar:../../../Middleware/JWSDP1.3/lib/sax.jar:../../../Middleware/JWSDP1.3/lib/xalan.jar:../../../Middleware/JWSDP1.3/lib/xercesImpl.jar:../../../Middleware/JWSDP1.3/lib/xsdlib.jar:../../../Middleware/JWSDP1.3/lib/xsltc.jar:../../../Middleware/snmp/lib/AdventNetSnmpStudioApi.jar:../../../Middleware/snmp/lib/AdventNetSnmp.jar:../../../Middleware/snmp/lib/AdventNetLogging.jar:../../../Middleware/OpenCCM/OpenCCM_Runtime.jar


if ( $?CLASSPATH ) then
    setenv CLASSPATH ${bb_cp}:$CLASSPATH
else
    setenv CLASSPATH $bb_cp
endif

