/* -*- C++ -*- */

/*-
 * Copyright (c) 1993-1994 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and the Network Research Group at
 *      Lawrence Berkeley Laboratory.
 * 4. Neither the name of the University nor of the Laboratory may be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

// $Id$

// ============================================================================
//
// = LIBRARY
//   ORBSVCS AVStreams
//
// = FILENAME
//   RTP.h
//
// = AUTHOR
//    Nagarajan Surendran <naga@cs.wustl.edu>
//
//
// ============================================================================

#ifndef TAO_AV_RTP_H
#define TAO_AV_RTP_H
#include "ace/pre.h"

#include "Protocol_Factory.h"

#define RTP_PT_BVC              22      /* Berkeley video codec */

/* RTP standard content encodings for video */
#define RTP_PT_RGB8             23      /* 8-bit dithered RGB */
#define RTP_PT_HDCC             24      /* SGI proprietary */
#define RTP_PT_CELLB            25      /* Sun CellB */
#define RTP_PT_JPEG             26      /* JPEG */
#define RTP_PT_CUSEEME          27      /* Cornell CU-SeeMe */
#define RTP_PT_NV               28      /* Xerox PARC nv */
#define RTP_PT_PICW             29      /* BB&N PictureWindow */
#define RTP_PT_CPV              30      /* Concept/Bolter/Viewpoint codec */
#define RTP_PT_H261             31      /* ITU H.261 */
#define RTP_PT_MPEG             32      /* MPEG-I & MPEG-II */
#define RTP_PT_MP2T             33      /* MPEG-II either audio or video */

/* backward compat hack for decoding RTPv1 ivs streams */
#define RTP_PT_H261_COMPAT 127

/* RTP standard content encodings for audio */
#define RTP_PT_PCMU             0
#define RTP_PT_CELP             1
#define RTP_PT_GSM              3
#define RTP_PT_DVI              5
#define RTP_PT_LPC              7


/* Offset from UNIX's epoch to the NTP epoch in seconds (NTP's JAN_1970) */
#define RTP_EPOCH_OFFSET        2208988800UL
#define RTP_VERSION 2

#define RTP_M   0x0080  /* Marker: significant event <e.g. frame boundary> */
#define RTP_P   0x2000  /* Padding is present */
#define RTP_X   0x1000  /* Extension Header is present */


#define RTCP_PT_SR      200     /* sender report */
#define RTCP_PT_RR      201     /* receiver report */
#define RTCP_PT_SDES    202     /* source description */
#define RTCP_SDES_CNAME 1       /* official name (mandatory) */
#define RTCP_SDES_NAME  2       /* personal name (optional) */
#define RTCP_SDES_EMAIL 3       /* e-mail addr (optional) */
#define RTCP_SDES_PHONE 4       /* telephone # (optional) */
#define RTCP_SDES_LOC   5       /* geographical location */
#define RTCP_SDES_TOOL  6       /* name/(vers) of app */
#define RTCP_SDES_NOTE  7       /* transient messages */
#define RTCP_SDES_PRIV  8       /* private SDES extensions */
#define RTCP_PT_BYE     203     /* end of participation */
#define RTCP_PT_APP     204     /* application specific functions */

#define RTCP_SDES_MIN   1


/*
 * Parameters controling the RTCP report rate timer.
 */
#define RTCP_SESSION_BW_FRACTION (0.05)
#define RTCP_MIN_RPT_TIME (5.)
#define RTCP_SENDER_BW_FRACTION (0.25)
#define RTCP_RECEIVER_BW_FRACTION (1. - RTCP_SENDER_BW_FRACTION)
#define RTCP_SIZE_GAIN (1./8.)

/*
 * Largest (user-level) packet size generated by our rtp applications.
 * Individual video formats may use smaller mtu's.
 */
#define RTP_MTU 1024

#define MAXHDR 24

#include "Policy.h"
#include "FlowSpec_Entry.h"
#include "MCast.h"
//------------------------------------------------------------
// TAO_AV_RTP_UDP
//------------------------------------------------------------


class TAO_AV_SourceManager;
class TAO_AV_RTCP_UDP_Flow_Handler;
class TAO_AV_RTP_State;

//------------------------------------------------------------
// TAO_AV_RTP
//------------------------------------------------------------


class TAO_AV_RTP
{
public:
  /* Basic RTP header */
  struct rtphdr
  {
    ACE_UINT16 rh_flags;        /* T:2 P:1 X:1 CC:4 M:1 PT:7 */
    ACE_UINT16 rh_seqno;        /* sequence number */
    ACE_UINT32 rh_ts;   /* media-specific time stamp */
    ACE_UINT32 rh_ssrc; /* synchronization src id */
    /* data sources follow per cc */
  };

  /*
 * Motion JPEG encapsulation.
 *
 * 0                   1                   2                   3
 * 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |      MBZ      |                frag offset                    |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |      Type     |       Q       |     Width     |     Height    |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 * Type = Index into a table of predefined JPEG parameters
 * Width = Width of input in 8-pixel blocks
 * Height = Height of input in 8-pixel blocks
 * Q = Quality factor (0-100 = std, >100 = custom)
 * Frag offset = The byte offset into the frame for the data in
 * this packet
 */
  struct jpeghdr
  {
    ACE_UINT32 off;             /* fragment offset */
    unsigned char type;         /* id of jpeg decoder params */
    unsigned char q;            /* quantization factor (or table id) */
    unsigned char width;                /* 1/8 frame width */
    unsigned char height;       /* 1/8 frame height */
  };

  /*
 * NV encapsulation.
 */
  struct nvhdr
  {
    ACE_UINT16 width;
    ACE_UINT16 height;
    /* nv data */
  };

  /*
 * CellB encapsulation.
 */
  struct cellbhdr
  {
    ACE_UINT16 x;
    ACE_UINT16 y;
    ACE_UINT16 width;
    ACE_UINT16 height;
    /* cells */
  };

  /*
 * H.261 encapsulation.
 * See Internet draft.
 *
 *  0                   1                   2                   3
 *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |SBIT |EBIT |I|V| GOBN  |  MBAP   |  QUANT  |  HMVD   |  VMVD   |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */
#ifdef notdef
  struct h261hdr
  {
    ACE_UINT16  flags;
    ACE_UINT16 off;
  };
#endif

  struct bvchdr
  {
    unsigned char version;
    unsigned char pad;
    unsigned char width;
    unsigned char height;
    ACE_UINT32 quant;
    unsigned char sbit;
    unsigned char ebit;
    ACE_UINT16 blkno;
  };

  static int handle_input (ACE_Message_Block *&data,
                           TAO_AV_frame_info *&frame_info);

  static  int write_header (rtphdr &header,
                            int format,
                            ACE_UINT16 &sequence_num,
                            ACE_UINT32 ts,
                            ACE_UINT32 ssrc,
                            CORBA::Boolean boundary_marker);

};


class TAO_AV_RTP_Object : public TAO_AV_Protocol_Object
{
public:
  TAO_AV_RTP_Object (TAO_AV_Callback *callback,
                     TAO_AV_Transport *transport);

  virtual ~TAO_AV_RTP_Object (void);

  virtual int start (void);
  virtual int stop (void);
  virtual int handle_input (void);
  virtual int send_frame (ACE_Message_Block *frame,
                          TAO_AV_frame_info *frame_info = 0);

  virtual int send_frame (const iovec *iov,
                          int iovcnt,
                          TAO_AV_frame_info *frame_info = 0);

  virtual int send_frame (const char*buf,
                          size_t len);

  virtual int destroy (void);
  virtual int set_policies (const TAO_AV_PolicyList &policy_list);
  virtual void control_object (TAO_AV_Protocol_Object *object);

protected:
  ACE_UINT16 sequence_num_;
  int format_;
  CORBA::ULong ssrc_;
  TAO_AV_Protocol_Object *control_object_;

  ACE_Message_Block frame_;
  // Pre-allocated memory to receive the data...
};

class TAO_AV_Export TAO_AV_RTP_Flow_Factory : public TAO_AV_Flow_Protocol_Factory
{
public:
  TAO_AV_RTP_Flow_Factory (void);
  virtual ~TAO_AV_RTP_Flow_Factory (void);
  virtual int init (int argc, char *argv[]);
  // Initialization hook.
  virtual int match_protocol (const char *flow_string);
  virtual TAO_AV_Protocol_Object* make_protocol_object (TAO_FlowSpec_Entry *entry,
                                                        TAO_Base_StreamEndPoint *endpoint,
                                                        TAO_AV_Flow_Handler *handler,
                                                        TAO_AV_Transport *transport);
  virtual const char*control_flow_factory (void);
};

ACE_STATIC_SVC_DECLARE (TAO_AV_RTP_Flow_Factory)
ACE_FACTORY_DECLARE (TAO_AV, TAO_AV_RTP_Flow_Factory)

#include "ace/post.h"
#endif /* TAO_AV_RTP_H */
