/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    receiver.h
 *
 *  $Id$
 *
 *  This application receives data from a AV sender and writes it to
 *  a file.
 *
 *
 *  @author Yamuna Krishnamurthy <yamuna@cs.wustl.edu>
 */
//=============================================================================


#include "Connection_Manager.h"
#include "orbsvcs/AV/AVStreams_i.h"
#include "orbsvcs/AV/Endpoint_Strategy.h"
#include "orbsvcs/AV/Policy.h"

/**
 * @class Receiver_Callback
 *
 * @brief Application defined callback object.
 *
 * AVStreams calls this class when data shows up from a sender.
 */
class Receiver_Callback : public TAO_AV_Callback
{
public:

  /// Constructor.
  Receiver_Callback (void);

  // Method that is called when there is data to be received from a
  // sender.
  int receive_frame (ACE_Message_Block *frame,
                     TAO_AV_frame_info *frame_info,
                     const ACE_Addr &peer_address);

  // Called when the sender is done sending data and wants to close
  // down the connection.
  int handle_destroy (void);

private:
  /// Keeping a count of the incoming frames.
  int frame_count_;
};

/**
 * @class Receiver_StreamEndPoint
 *
 * @brief Application defined stream endpoint object.
 *
 * AVStreams calls this class during connection setup.
 */
class Receiver_StreamEndPoint : public TAO_Server_StreamEndPoint
{
public:
  // Create a receiver application callback.
  int get_callback (const char *flowname,
                    TAO_AV_Callback *&callback);

private:
  /// Receiver application callback.
  Receiver_Callback callback_;
};

/**
 * @class Receiver
 *
 * @brief Receiver application class.
 *
 * This class receives data from a AV sender and writes it to
 * a file.
 */
class Receiver
{
public:
  /// Constructor
  Receiver (void);

  /// Destructor.
  ~Receiver (void);

  /// Initialize data components.
  int init (int argc, ACE_TCHAR *argv[]);

  /// Parse args.
  int parse_args (int argc, ACE_TCHAR *argv[]);

  /// Name of the output file.
  ACE_TString output_file_name (void);

protected:
  /// Connection manager.
  Connection_Manager connection_manager_;

  /// The endpoint reactive strategy.
  TAO_AV_Endpoint_Reactive_Strategy_B
  <Receiver_StreamEndPoint,TAO_VDev,AV_Null_MediaCtrl> reactive_strategy_;

  /// The receiver MMDevice.
  AVStreams::MMDevice_var mmdevice_obj_;

  /// Receiver MMDevice.
  TAO_MMDevice *mmdevice_;

  /// The sender MMDevice
  AVStreams::MMDevice_var sender_mmdevice_;

  /// File name of the file into which received data is written.
  ACE_TString output_file_name_;

  ACE_TString addr_file_;

  /// Sender name.
  ACE_CString sender_name_;

  /// Receiver name.
  ACE_CString receiver_name_;
};
