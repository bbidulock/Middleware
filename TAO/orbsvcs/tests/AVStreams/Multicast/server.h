/* -*- C++ -*- */
// $Id$

#include "ace/Get_Opt.h"
#include "tao/Strategies/advanced_resource.h"
#include "orbsvcs/orbsvcs/CosNamingC.h"
#include "orbsvcs/orbsvcs/Naming/Naming_Utils.h"
#include "orbsvcs/orbsvcs/AV/AVStreams_i.h"
#include "orbsvcs/orbsvcs/AV/Endpoint_Strategy.h"
#include "orbsvcs/orbsvcs/AV/Transport.h"
#include "orbsvcs/orbsvcs/AV/sfp.h"
#include "orbsvcs/orbsvcs/AV/MCast.h"
#include "orbsvcs/orbsvcs/AV/Policy.h"

class FTP_Server_StreamEndPoint
  :public TAO_Server_StreamEndPoint
{
public:
  FTP_Server_StreamEndPoint (void);
  virtual int get_callback (const char *flowname,
                            TAO_AV_Callback *&callback);
};

class FTP_Server_Callback
  :public TAO_AV_Callback
{
public:
  virtual int handle_stop (void);
  virtual int receive_frame (ACE_Message_Block *frame,
                             TAO_AV_frame_info *,
                             const ACE_Addr &);
  virtual int handle_end_stream (void);
};

class Server
{
public:
  Server (void);
  int init (int argc,
            char **argv);
  int run (void);
  FILE *file (void);
protected:
  int parse_args (int argc,char **argv);
  TAO_Naming_Client my_naming_client_;
  TAO_AV_Endpoint_Reactive_Strategy_B <FTP_Server_StreamEndPoint,TAO_VDev,AV_Null_MediaCtrl> reactive_strategy_;
  TAO_MMDevice *mmdevice_;
  FILE *fp_;
  char *protocol_;
};

typedef ACE_Singleton<Server,ACE_Null_Mutex> FTP_SERVER;
