// $Id$

#define ACE_BUILD_DLL
#include "ace/TTY_IO.h"

ACE_RCSID(ace, TTY_IO, "TTY_IO.cpp,v 4.18 1999/06/02 21:20:14 nanbor Exp")

// Interface for reading/writing serial device parameters

int
ACE_TTY_IO::control (Control_Mode cmd,
                     Serial_Params *arg) const
{
#if defined (ACE_HAS_TERM_IOCTLS)
#if defined(TCGETS)
  struct termios devpar;
#elif defined(TCGETA)
  struct termio devpar;
#else
  errno = ENOSYS;
  return -1;
#endif
  u_long c_iflag;
  u_long c_oflag;
  u_long c_cflag;
  u_long c_lflag;
  // u_long c_line;
  u_char ivmin_cc4;
  u_char ivtime_cc5;

  c_iflag=0;
  c_oflag=0;
  c_cflag=0;
  c_lflag=0;
  // c_line=0;

  // Get default device parameters.

#if defined (TCGETS)
    if (this->ACE_IO_SAP::control (TCGETS, (void *) &devpar) == -1)
#elif defined (TCGETA)
    if (this->ACE_IO_SAP::control (TCGETA, (void *) &devpar) == -1)
#else
    errno = ENOSYS;
#endif /* TCGETS */
      return -1;

  u_int newbaudrate = 0;

  switch (cmd)
    {
    case SETPARAMS:
      switch (arg->baudrate)
        {
        case 300:
          newbaudrate = B300;
          break;
        case 600:
          newbaudrate = B600;
          break;
        case 1200:
          newbaudrate = B1200;
          break;
        case 2400:
          newbaudrate = B2400;
          break;
        case 4800:
          newbaudrate = B4800;
          break;
        case 9600:
          newbaudrate = B9600;
          break;
        case 19200:
          newbaudrate = B19200;
          break;
        case 38400:
          newbaudrate = B38400;
          break;
#if defined (ACE_USES_HIGH_BAUD_RATES)
//          case 56000:
//            newbaudrate = B56000;
//            break;
        case 57600:
          newbaudrate = B57600;
          break;
        case 115200:
          newbaudrate = B115200;
          break;
//          case 128000:
//            newbaudrate = B128000;
//            break;
//          case 256000:
//            newbaudrate = B256000;
//            break;
#endif /* ACE_USES_HIGH_BAUD_RATES */
        default:
          return -1;
        }

#if defined(ACE_USES_OLD_TERMIOS_STRUCT)
      // @@ Can you really have different input and output baud
      // rates?!
      devpar.c_ispeed = newbaudrate;
      devpar.c_ospeed = newbaudrate;
#else
      c_cflag |= newbaudrate;
#endif /* ACE_USES_OLD_TERMIOS_STRUCT */

      switch (arg->databits)
        {
        case   5:
          c_cflag |= CS5;
          break;
        case   6:
          c_cflag |= CS6;
          break;
        case   7:
          c_cflag |= CS7;
          break;
        case   8:
          c_cflag |= CS8;
          break;
        default:
          return -1;
        }
      switch (arg->stopbits)
        {
        case   1:
          break;
        case   2:
          c_cflag |= CSTOPB;
          break;
        default:
          return -1;
        }
      if (arg->parityenb)
        {
          c_cflag |= PARENB;
          if (ACE_OS::strcmp (arg->paritymode, "ODD") == 0
              || ACE_OS::strcmp (arg->paritymode, "odd") == 0)
            c_cflag |= PARODD;
        }
#if defined (CRTSCTS)
  	  // 6/22/00 MLS add rtsenb to if statement 
      if ((arg->ctsenb)||(arg->rtsenb)) /* enable CTS/RTS protocoll */
        c_cflag |= CRTSCTS;
#endif /* CRTSCTS */
#if defined (CREAD)
      if (arg->rcvenb) /* enable receiver */
        c_cflag |= CREAD;
#endif /* CREAD */

	  // 6/22/00 MLS add enable xon/xoff 
#if defined (IXON)
      if (arg->xinenb) /* enable XON/XOFF output*/
        c_cflag |= IXON;
#endif /* IXON */
#if defined (IXOFF)
      if (arg->xoutenb) /* enable XON/XOFF input*/
        c_cflag |= IXOFF;
#endif /* IXOFF */

      c_oflag = 0;
      c_iflag = IGNPAR | INPCK;
      if (arg->databits < 8)
        c_iflag |= ISTRIP;
      c_lflag = 0;

      ivmin_cc4 = (u_char) 0;
      ivtime_cc5= (u_char) (arg->readtimeoutmsec / 100);
      devpar.c_iflag = c_iflag;
      devpar.c_oflag = c_oflag;
      devpar.c_cflag = c_cflag;
      devpar.c_lflag = c_lflag;
      devpar.c_cc[4] = ivmin_cc4;
      devpar.c_cc[5] = ivtime_cc5;

#if defined(TCSETS)
      return this->ACE_IO_SAP::control (TCSETS,
                                        (void *) &devpar);
#elif defined(TCSETA)
      return this->ACE_IO_SAP::control (TCSETA,
                                        (void *) &devpar);
#else
      errno = ENOSYS;
      return -1;
#endif
    case GETPARAMS:
      return -1; // Not yet implemented.
    default:
      return -1; // Wrong cmd.
    }
#elif defined (ACE_WIN32)
  switch (cmd)
    {
    case SETPARAMS:
      DCB dcb;
      dcb.DCBlength = sizeof dcb;
      ::GetCommState (this->get_handle (), &dcb);

      switch (arg->baudrate)
        {
        case   300: dcb.BaudRate = CBR_300; break;
        case   600: dcb.BaudRate = CBR_600; break;
        case  1200: dcb.BaudRate = CBR_1200; break;
        case  2400: dcb.BaudRate = CBR_2400; break;
        case  4800: dcb.BaudRate = CBR_4800; break;
        case  9600: dcb.BaudRate = CBR_9600; break;
        case  19200: dcb.BaudRate = CBR_19200; break;
        case  38400: dcb.BaudRate = CBR_38400; break;
//          case  56000: dcb.BaudRate = CBR_56000; break;
        case  57600: dcb.BaudRate = CBR_57600; break;
        case  115200: dcb.BaudRate = CBR_115200; break;
//          case  128000: dcb.BaudRate = CBR_128000; break;
//          case  256000: dcb.BaudRate = CBR_256000; break;
        default:  return -1;
        }

      switch (arg->databits)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
          dcb.ByteSize = u_char (arg->databits);
          break;
        default:
          return -1;
        }

      switch (arg->stopbits)
        {
        case 1:
	  dcb.StopBits = ONESTOPBIT;
	  break;
        case 2:
	  dcb.StopBits = TWOSTOPBITS;
	  break;
        default:
          return -1;
        }


      // 6/22/00 MLS enabled extra paths for win32 parity checking.
      if (arg->parityenb)
        {
          dcb.fParity = TRUE;
          if (ACE_OS::strcmp (arg->paritymode, "ODD") == 0
              || ACE_OS::strcmp (arg->paritymode, "odd") == 0)
            dcb.Parity = ODDPARITY;
          else if (ACE_OS::strcmp (arg->paritymode, "EVEN") == 0
                   || ACE_OS::strcmp (arg->paritymode, "even") == 0)
            dcb.Parity = EVENPARITY;
          else if (ACE_OS::strcmp (arg->paritymode, "MARK") == 0
                   || ACE_OS::strcmp (arg->paritymode, "mark") == 0)
            dcb.Parity = MARKPARITY;
          else if (ACE_OS::strcmp (arg->paritymode, "SPACE") == 0
                   || ACE_OS::strcmp (arg->paritymode, "space") == 0)
            dcb.Parity = SPACEPARITY;
          else
            dcb.Parity = NOPARITY;
        }
      else
        {
          dcb.fParity = FALSE;
          dcb.Parity = NOPARITY;
        }

      if (arg->ctsenb) // enable CTS protocol.
        dcb.fOutxCtsFlow = TRUE;
      else
        dcb.fOutxCtsFlow = FALSE;

      // 6/22/00 MLS add  great flexibility for win32 
      //		     pulled rts out of ctsenb
      switch (arg->rtsenb) // enable RTS protocol.
        {
        case 1:
          dcb.fRtsControl = RTS_CONTROL_ENABLE;
          break;
        case 2:
          dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
          break;
        case 3:
          dcb.fRtsControl = RTS_CONTROL_TOGGLE;
          break;
        default:
          dcb.fRtsControl = RTS_CONTROL_DISABLE;
        }	  

      // 6/22/00 MLS add enable xon/xoff 
      if (arg->xinenb) // enable XON/XOFF for reception
        dcb.fOutX = TRUE;
      else
        dcb.fOutX = FALSE;

      if (arg->xoutenb) // enable XON/XOFF for transmission
        dcb.fOutX = TRUE;
      else
        dcb.fOutX = FALSE;

      // always set limits unless set to -1 to use default
      // 6/22/00 MLS add xon/xoff limits
      if (arg->xonlim != -1)
        dcb.XonLim  = arg->xonlim;
      if (arg->xofflim != -1)
        dcb.XoffLim  = arg->xofflim;

      dcb.fDtrControl = DTR_CONTROL_ENABLE;
      dcb.fBinary = TRUE;
      ::SetCommState (this->get_handle (), &dcb);
  
      // 2/13/97 BWF added drop out timer
      COMMTIMEOUTS timeouts;
      ::GetCommTimeouts (this->get_handle (), &timeouts);
      timeouts.ReadIntervalTimeout = arg->readtimeoutmsec;
      return ::SetCommTimeouts (this->get_handle (), &timeouts);

    case GETPARAMS:
      ACE_NOTSUP_RETURN (-1); // Not yet implemented.
    default:
      return -1; // Wrong cmd.

    } // arg switch
#else
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_TERM_IOCTLS */
}

#if defined (ACE_NEEDS_DEV_IO_CONVERSION)
ACE_TTY_IO::operator ACE_DEV_IO &()
{
  return (ACE_DEV_IO &) *this;
}
#endif /* ACE_NEEDS_DEV_IO_CONVERSION */
