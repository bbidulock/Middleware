/* -*- C++ -*- */
// $Id$

#ifndef TAO_AV_FTP_H
#define TAO_AV_FTP_H

#include "ace/Get_Opt.h"
#include "orbsvcs/Naming/Naming_Utils.h"
#include "orbsvcs/AV/AVStreams_i.h"
#include "orbsvcs/AV/Endpoint_Strategy.h"
#include "orbsvcs/AV/FlowSpec_Entry.h"
#include "orbsvcs/AV/sfp.h"
#include "orbsvcs/AV/MCast.h"
#include "ace/High_Res_Timer.h"

class FTP_Client_Callback  : public TAO_AV_Callback
{
public:
  FTP_Client_Callback (void);
  virtual int handle_timeout (void *arg);
  virtual int handle_destroy (void);
  virtual void get_timeout (ACE_Time_Value *&tv,
                            void *&arg);
  void set_protocol_object (TAO_AV_Protocol_Object *protocol_object) {this->protocol_object_ = protocol_object;}
protected:
  int count_;
  TAO_AV_Protocol_Object *protocol_object_;
};

class FTP_Client_StreamEndPoint  : public TAO_Client_StreamEndPoint
{
public:
  FTP_Client_StreamEndPoint (void);

  virtual int get_callback (const char *flowname,
                            TAO_AV_Callback *&callback);

  virtual int set_protocol_object (const char *flowname,
                                   TAO_AV_Protocol_Object *object);
protected:
  FTP_Client_Callback *callback_;
};

typedef TAO_AV_Endpoint_Reactive_Strategy_A<FTP_Client_StreamEndPoint,TAO_VDev,AV_Null_MediaCtrl> ENDPOINT_STRATEGY;

class Client;
class Endpoint_Reactive_Strategy  : public ENDPOINT_STRATEGY
{
public:
  Endpoint_Reactive_Strategy (Client *client_ptr);
  // constructor . The orb manager is needed for the TAO_AV_Endpoint_Reactive_Strategy_A.

  virtual int make_stream_endpoint (FTP_Client_StreamEndPoint *& endpoint);
  // hook to make our streamendpoint taking a Client pointer
private:
  Client *client_;
  // pointer to command handler object
};


class Client
{
public:
  Client (void);
  int init (int argc, char **argv);
  int run (void);
  FILE *file (void);
  char *flowname (void);
  TAO_StreamCtrl* streamctrl (void);
private:
  int parse_args (int argc, char **argv);
  int bind_to_server (void);
  Endpoint_Reactive_Strategy endpoint_strategy_;
  AVStreams::MMDevice_var server_mmdevice_;
  TAO_MMDevice client_mmdevice_;
  TAO_StreamCtrl streamctrl_;
  // Video stream controller

  int argc_;
  char **argv_;
  const char *filename_;
  const char *address_;

  TAO_Naming_Client my_naming_client_;
  FILE *fp_;
  char *protocol_;
  char *flowname_;
  int use_sfp_;
  int test_;
};

typedef ACE_Singleton<Client,ACE_Null_Mutex> CLIENT;

#endif /* TAO_AV_FTP_H */
