#!/bin/csh


#!/bin/sh
set bb_cp=${JAVA_HOME}/bin:.:$ARMS_ROOT/lib/TelcordiaBB.jar:$DRM_ROOT/Middleware/JacORB2.1/lib/jacorb.jar:$DRM_ROOT/Middleware/JacORB2.1/lib/logkit-1.2.jar:$DRM_ROOT/Middleware/JacORB2.1/lib/avalon-framework-4.1.5.jar:$DRM_ROOT/Middleware/JacORB2.1/lib/concurrent-1.3.2.jar:$DRM_ROOT/Middleware/JacORB2.1/lib/antlr-2.7.2.jar:$DRM_ROOT/Middleware/JacORB2.1/lib/idl.jar:$DRM_ROOT/Middleware/MySQL/lib/mysql-connector-java-3.0.8-stable-bin.jar:$DRM_ROOT/Middleware/MySQL/lib/mm.mysql-2.0.14-bin.jar:$DRM_ROOT/Middleware/log4j/lib/log4j-1.2.8.jar:$DRM_ROOT/Middleware/JacORB2.1/lib/wrapper-3.0.3.jar:$DRM_ROOT/Middleware/Telcordia/lib/telcordia-jIOS.jar:$DRM_ROOT/Middleware/JWSDP1.5/lib/jaxb-api.jar:$DRM_ROOT/Middleware/JWSDP1.5/lib/jaxb-impl.jar:$DRM_ROOT/Middleware/JWSDP1.5/lib/jaxb-libs.jar:$DRM_ROOT/Middleware/JWSDP1.5/lib/jaxb-xjc.jar:$DRM_ROOT/Middleware/JWSDP1.5/lib/jax-qname.jar:$DRM_ROOT/Middleware/JWSDP1.5/lib/relaxngDatatype.jar:$DRM_ROOT/Middleware/JWSDP1.5/lib/namespace.jar:$DRM_ROOT/Middleware/snmp/lib/AdventNetSnmpStudioApi.jar:$DRM_ROOT/Middleware/snmp/lib/AdventNetSnmp.jar:$DRM_ROOT/Middleware/snmp/lib/AdventNetLogging.jar:$DRM_ROOT/Middleware/Hsqldb1.7.3/lib/hsqldb.jar:$DRM_ROOT/Middleware/jdom/lib/jdom.jar:$DRM_ROOT/Middleware/jimi/lib/JimiProClasses.zip:$DRM_ROOT/Middleware/armond/lib/armond.jar:$DRM_ROOT/Middleware/cli/lib/pnuts.jar:$DRM_ROOT/Middleware/cli/lib/CLI.jar:$DRM_ROOT/Middleware/cli/lib/bsf.jar:$DRM_ROOT/Middleware/Telcordia/lib/telcordia-imp.jar:$CLASSPATH
export CLASSPATH

if ( $?CLASSPATH ) then
    setenv CLASSPATH ${bb_cp}:$CLASSPATH
else
    setenv CLASSPATH $bb_cp
endif

