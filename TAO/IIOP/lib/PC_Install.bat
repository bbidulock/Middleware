echo on
mkdir ..\proto\lib
copy TAO_Baseline.lib ..\proto\lib
rem copy %ACE_WRAPPERS%\ace.lib %TAO_ROOT%\proto\lib
copy \OFP\Workspace\libfiles\ace.lib ..\proto\lib

mkdir ..\proto\include
copy align.h    ..\proto\include
copy thread.h   ..\proto\include
copy cdr.h      ..\proto\include
copy connmgr.h  ..\proto\include
copy giop.h     ..\proto\include
copy iiopobj.h  ..\proto\include
copy iioporb.h  ..\proto\include
copy roa.h      ..\proto\include
copy roa.i       ..\proto\include
copy params.h    ..\proto\include
copy connect.h   ..\proto\include
copy xdr.h      ..\proto\include

mkdir ..\proto\include\corba
copy  any.h      ..\proto\include\corba
copy  boa.h      ..\proto\include
copy  corbacom.h ..\proto\include\corba
copy  except.h   ..\proto\include\corba
copy  nvlist.h   ..\proto\include\corba
copy  object.h   ..\proto\include\corba
copy  orbobj.h   ..\proto\include\corba
copy  principa.h ..\proto\include\corba
copy  request.h  ..\proto\include\corba
copy  svrrqst.h  ..\proto\include\corba
copy  typecode.h ..\proto\include\corba
copy  orb.h      ..\proto\include\corba
copy  sequence.h ..\proto\include\corba
copy  stub.h     ..\proto\include\corba
copy  orbconf.h  ..\proto\include\corba
copy  debug.h    ..\proto\include\corba
