// $Id$

//================================================================================
//
// = LIBRARY
//     TAO/tests/POA/On_Demand_Loading
//
// = FILENAME
//     Servant_Locator.h
//
// = DESCRIPTION
//     Defines a ServantLocator_i class , used with a POA having
//     a NON_RETAIN policy. 
//
// = AUTHOR
//     Kirthika Parameswaran <kirthika@cs.wustl.edu>
//
//==================================================================================

#ifndef SERVANT_LOCATOR_H
#define SERVANT_LOCATOR_H

#include "tao/corba.h"
#include "ace/DLL.h"
#include "Servant_Manager.h"

class ServantLocator_i : public POA_PortableServer::ServantLocator
{
  // = TITLE
  //   This class is used by a POA with USE_SERVANT_MANAGER and
  //   NON_RETAIN policy.
  // 
  // = DESCRIPTION
  //   This class defines the Servant Locator interface of the Servant
  //   Manager. It is invoked when the POA has an USE_SERVANT_MANAGER
  //   policy and a servant_retention policy of NON_RETAIN type.

  //   @@ *done*Kirthika, please explain what this class DOES.
public:
  ServantLocator_i (CORBA::ORB_ptr orb);
  // Constructor.

  virtual PortableServer::Servant preinvoke (const PortableServer::ObjectId &oid,
                                             PortableServer::POA_ptr adapter,
                                             const char *operation,
                                             PortableServer::ServantLocator::Cookie &the_cookie,
                                             CORBA::Environment &env);
  // This method is invoked by a POA whenever it receives a request
  // for MyFoo object that is not currently active.
  // When the POA is created using the NON_RETAIN policy the Active
  // Object Map is not maintained, in other words, an association
  // between the ObjectId and the servant is not maintained. Hence every
  // client request the servant has to be loaded. Note the operation
  // argument. This argument specifies the operation to be invoked on
  // the servant. The cookie helps in  marking the servant. This marking
  // is useful while destroying the servant.

  // @@ *done*Kirthika, please explain briefly what THIS method does
  // whenever it is invoked, i.e., explain the use of the
  // ServantManager stuff...

  virtual void postinvoke (const PortableServer::ObjectId &oid,
                           PortableServer::POA_ptr adapter,
                           const char *operation,
                           PortableServer::ServantLocator::Cookie the_cookie,
                           PortableServer::Servant the_servant,
                           CORBA::Environment &env);
  // This method is invoked whenever a MyFooServant completes a
  // request. As the Servant Loactor interface is used when the POA
  // doesnt maintain the Active Object Map, its necessary to get rid
  // of the servant after the client request has been processed. The
  // appropriate servant is destroyed by verifying the cookie.Again
  // this method is invoked per client request.

  // @@ *done*Kirthika, please explain briefly what THIS method does
  // whenever it is invoked, i.e., explain the use of the
  // ServantManager stuff...

  PortableServer::ObjectId_var create_dll_object_id (const char *dllname, 
                                                     const char *factory_function);
  // Returns an ObjectId when given an dll name and the factory method
  // to be invoked in the dll.
private:
  ServantManager_i servant_manager_;
  // The <ServantManager_i> object that provides utility methods.
  // The methods include obtaining the servant using an ACE_DLL
  // object, destroying the servant and extracting the dllname and
  // factory function from the ObjectId.

  // @@ *done*Kirthika, briefly summarize what these methods accomplish (in
  // general).
  
};

#endif /* SERVANT_LOCATOR_H */
