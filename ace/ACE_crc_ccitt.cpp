// $Id$

#include "ace/ACE.h"

ACE_RCSID (ace,
           ACE_crc_ccitt,
           "$Id$")

namespace 
{
  /*****************************************************************/
  /*                                                               */
  /* CRC LOOKUP TABLE                                              */
  /* ================                                              */
  /* The following CRC lookup table was generated automagically    */
  /* by the Rocksoft^tm Model CRC Algorithm Table Generation       */
  /* Program V1.0 using the following model parameters:            */
  /*                                                               */
  /*    Width   : 2 bytes.                                         */
  /*    Poly    : 0x1021                                           */
  /*    Reverse : TRUE.                                            */
  /*                                                               */
  /* For more information on the Rocksoft^tm Model CRC Algorithm,  */
  /* see the document titled "A Painless Guide to CRC Error        */
  /* Detection Algorithms" by Ross Williams                        */
  /* (ross@guest.adelaide.edu.au.). This document is likely to be  */
  /* in the FTP archive "ftp.adelaide.edu.au/pub/rocksoft".        */
  /*                                                               */
  /*****************************************************************/

  const ACE_UINT16 crc_table[] =
    {
     0x0000, 0x1189, 0x2312, 0x329B, 0x4624, 0x57AD, 0x6536, 0x74BF,
     0x8C48, 0x9DC1, 0xAF5A, 0xBED3, 0xCA6C, 0xDBE5, 0xE97E, 0xF8F7,
     0x1081, 0x0108, 0x3393, 0x221A, 0x56A5, 0x472C, 0x75B7, 0x643E,
     0x9CC9, 0x8D40, 0xBFDB, 0xAE52, 0xDAED, 0xCB64, 0xF9FF, 0xE876,
     0x2102, 0x308B, 0x0210, 0x1399, 0x6726, 0x76AF, 0x4434, 0x55BD,
     0xAD4A, 0xBCC3, 0x8E58, 0x9FD1, 0xEB6E, 0xFAE7, 0xC87C, 0xD9F5,
     0x3183, 0x200A, 0x1291, 0x0318, 0x77A7, 0x662E, 0x54B5, 0x453C,
     0xBDCB, 0xAC42, 0x9ED9, 0x8F50, 0xFBEF, 0xEA66, 0xD8FD, 0xC974,
     0x4204, 0x538D, 0x6116, 0x709F, 0x0420, 0x15A9, 0x2732, 0x36BB,
     0xCE4C, 0xDFC5, 0xED5E, 0xFCD7, 0x8868, 0x99E1, 0xAB7A, 0xBAF3,
     0x5285, 0x430C, 0x7197, 0x601E, 0x14A1, 0x0528, 0x37B3, 0x263A,
     0xDECD, 0xCF44, 0xFDDF, 0xEC56, 0x98E9, 0x8960, 0xBBFB, 0xAA72,
     0x6306, 0x728F, 0x4014, 0x519D, 0x2522, 0x34AB, 0x0630, 0x17B9,
     0xEF4E, 0xFEC7, 0xCC5C, 0xDDD5, 0xA96A, 0xB8E3, 0x8A78, 0x9BF1,
     0x7387, 0x620E, 0x5095, 0x411C, 0x35A3, 0x242A, 0x16B1, 0x0738,
     0xFFCF, 0xEE46, 0xDCDD, 0xCD54, 0xB9EB, 0xA862, 0x9AF9, 0x8B70,
     0x8408, 0x9581, 0xA71A, 0xB693, 0xC22C, 0xD3A5, 0xE13E, 0xF0B7,
     0x0840, 0x19C9, 0x2B52, 0x3ADB, 0x4E64, 0x5FED, 0x6D76, 0x7CFF,
     0x9489, 0x8500, 0xB79B, 0xA612, 0xD2AD, 0xC324, 0xF1BF, 0xE036,
     0x18C1, 0x0948, 0x3BD3, 0x2A5A, 0x5EE5, 0x4F6C, 0x7DF7, 0x6C7E,
     0xA50A, 0xB483, 0x8618, 0x9791, 0xE32E, 0xF2A7, 0xC03C, 0xD1B5,
     0x2942, 0x38CB, 0x0A50, 0x1BD9, 0x6F66, 0x7EEF, 0x4C74, 0x5DFD,
     0xB58B, 0xA402, 0x9699, 0x8710, 0xF3AF, 0xE226, 0xD0BD, 0xC134,
     0x39C3, 0x284A, 0x1AD1, 0x0B58, 0x7FE7, 0x6E6E, 0x5CF5, 0x4D7C,
     0xC60C, 0xD785, 0xE51E, 0xF497, 0x8028, 0x91A1, 0xA33A, 0xB2B3,
     0x4A44, 0x5BCD, 0x6956, 0x78DF, 0x0C60, 0x1DE9, 0x2F72, 0x3EFB,
     0xD68D, 0xC704, 0xF59F, 0xE416, 0x90A9, 0x8120, 0xB3BB, 0xA232,
     0x5AC5, 0x4B4C, 0x79D7, 0x685E, 0x1CE1, 0x0D68, 0x3FF3, 0x2E7A,
     0xE70E, 0xF687, 0xC41C, 0xD595, 0xA12A, 0xB0A3, 0x8238, 0x93B1,
     0x6B46, 0x7ACF, 0x4854, 0x59DD, 0x2D62, 0x3CEB, 0x0E70, 0x1FF9,
     0xF78F, 0xE606, 0xD49D, 0xC514, 0xB1AB, 0xA022, 0x92B9, 0x8330,
     0x7BC7, 0x6A4E, 0x58D5, 0x495C, 0x3DE3, 0x2C6A, 0x1EF1, 0x0F78
    };

  /*****************************************************************/
  /*                   End of CRC Lookup Table                     */
  /*****************************************************************/
};

#define COMPUTE(var, ch) (var) = (crc_table[(var ^ ch) & 0xFF] ^ (var >> 8))

ACE_UINT16
ACE::crc_ccitt (const char *string)
{
  ACE_UINT16 crc = 0xFFFF;

  for (const char *p = string;
       *p != 0;
       ++p)
    {
      COMPUTE (crc, *p);
    }

  return ~crc;
}

ACE_UINT16
ACE::crc_ccitt (const void *buffer, size_t len)
{
  ACE_UINT16 crc = 0xFFFF;

  for (const char *p = (const char *) buffer,
                  *e = (const char *) buffer + len;
       p != e;
       ++p)
    {
      COMPUTE (crc, *p);
    }
  
  return ~crc;
}

ACE_UINT16
ACE::crc_ccitt (const iovec *iov, int len)
{
  ACE_UINT16 crc = 0xFFFF;

  for (int i = 0; i < len; ++i)
    {
      for (const char *p = (const char *) iov[i].iov_base,
	              *e = (const char *) iov[i].iov_base + iov[i].iov_len;
           p != e;
           ++p)
        COMPUTE (crc, *p);
    }

  return ~crc;
}

#undef COMPUTE
