/* -*- C++ -*- */
// $Id$

// Wrappers for methods that have been moved to ACE_OS.

ASYS_INLINE ssize_t
ACE::read_n (ACE_HANDLE handle,
             void *buf,
             size_t len,
             int error_on_eof)
{
  return ACE_OS::read_n (handle, buf, len, error_on_eof);
}

ASYS_INLINE ssize_t
ACE::write_n (ACE_HANDLE handle,
              const void *buf,
              size_t len,
              int error_on_eof)
{
  return ACE_OS::write_n (handle, buf, len, error_on_eof);
}

ASYS_INLINE ssize_t
ACE::recv_n (ACE_HANDLE handle,
             void *buf,
             size_t len,
             int flags,
             const ACE_Time_Value *timeout,
             int error_on_eof)
{
  if (timeout == 0)
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          flags,
                          error_on_eof);
  else
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          flags,
                          timeout,
                          error_on_eof);
}

#if defined (ACE_HAS_TLI)

ASYS_INLINE ssize_t
ACE::t_rcv_n (ACE_HANDLE handle,
              void *buf,
              size_t len,
              int *flags,
              const ACE_Time_Value *timeout,
              int error_on_eof)
{
  if (timeout == 0)
    return ACE::t_rcv_n_i (handle,
                           buf,
                           len,
                           flags,
                           error_on_eof);
  else
    return ACE::t_rcv_n_i (handle,
                           buf,
                           len,
                           flags,
                           timeout,
                           error_on_eof);
}

#endif /* ACE_HAS_TLI */

ASYS_INLINE ssize_t
ACE::recv_n (ACE_HANDLE handle,
             void *buf,
             size_t len,
             const ACE_Time_Value *timeout,
             int error_on_eof)
{
  if (timeout == 0)
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          error_on_eof);
  else
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          timeout,
                          error_on_eof);
}

ASYS_INLINE ssize_t
ACE::recvv_n (ACE_HANDLE handle,
              iovec *iov,
              int iovcnt,
              const ACE_Time_Value *timeout,
              int error_on_eof)
{
  if (timeout == 0)
    return ACE::recvv_n_i (handle,
                           iov,
                           iovcnt,
                           error_on_eof);
  else
    return ACE::recvv_n_i (handle,
                           iov,
                           iovcnt,
                           timeout,
                           error_on_eof);
}

ASYS_INLINE ssize_t
ACE::send_n (ACE_HANDLE handle,
             const void *buf,
             size_t len,
             int flags,
             const ACE_Time_Value *timeout,
             int error_on_eof)
{
  if (timeout == 0)
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          flags,
                          error_on_eof);
  else
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          flags,
                          timeout,
                          error_on_eof);
}

#if defined (ACE_HAS_TLI)

ASYS_INLINE ssize_t
ACE::t_snd_n (ACE_HANDLE handle,
              const void *buf,
              size_t len,
              int flags,
              const ACE_Time_Value *timeout,
              int error_on_eof)
{
  if (timeout == 0)
    return ACE::t_snd_n_i (handle,
                           buf,
                           len,
                           flags,
                           error_on_eof);
  else
    return ACE::t_snd_n_i (handle,
                           buf,
                           len,
                           flags,
                           timeout,
                           error_on_eof);
}

#endif /* ACE_HAS_TLI */

ASYS_INLINE ssize_t
ACE::send_n (ACE_HANDLE handle,
             const void *buf,
             size_t len,
             const ACE_Time_Value *timeout,
             int error_on_eof)
{
  if (timeout == 0)
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          error_on_eof);
  else
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          timeout,
                          error_on_eof);
}

ASYS_INLINE ssize_t
ACE::sendv_n (ACE_HANDLE handle,
              const iovec *iov,
              int iovcnt,
              const ACE_Time_Value *timeout,
              int error_on_eof)
{
  if (timeout == 0)
    return ACE::sendv_n_i (handle,
                           iov,
                           iovcnt,
                           error_on_eof);
  else
    return ACE::sendv_n_i (handle,
                           iov,
                           iovcnt,
                           timeout,
                           error_on_eof);
}

ASYS_INLINE ssize_t
ACE::send_i (ACE_HANDLE handle, const void *buf, size_t len)
{
#if defined (ACE_WIN32) || defined (ACE_PSOS)
  return ACE_OS::send (handle, (const char *) buf, len);
#else
  return ACE_OS::write (handle, (const char *) buf, len);
#endif /* ACE_WIN32 */
}

ASYS_INLINE ssize_t
ACE::recv_i (ACE_HANDLE handle, void *buf, size_t len)
{
#if defined (ACE_WIN32) || defined (ACE_PSOS)
  return ACE_OS::recv (handle, (char *) buf, len);
#else
  return ACE_OS::read (handle, (char *) buf, len);
#endif /* ACE_WIN32 */
}

ASYS_INLINE int
ACE::handle_read_ready (ACE_HANDLE handle,
                        const ACE_Time_Value *timeout)
{
  return ACE::handle_ready (handle,
                            timeout,
                            1,
                            0,
                            0);
}

ASYS_INLINE int
ACE::handle_write_ready (ACE_HANDLE handle,
                         const ACE_Time_Value *timeout)
{
  return ACE::handle_ready (handle,
                            timeout,
                            0,
                            1,
                            0);
}

ASYS_INLINE int
ACE::handle_exception_ready (ACE_HANDLE handle,
                             const ACE_Time_Value *timeout)
{
  return ACE::handle_ready (handle,
                            timeout,
                            0,
                            0,
                            1);
}

ASYS_INLINE char *
ACE::strecpy (char *s, const char *t)
{
  return ACE_OS::strecpy (s, t);
}

#if defined (ACE_HAS_UNICODE)
ASYS_INLINE wchar_t *
ACE::strecpy (wchar_t *s, const wchar_t *t)
{
  return ACE_OS::strecpy (s, t);
}
#endif /* ACE_HAS_UNICODE */

ASYS_INLINE void
ACE::unique_name (const void *object,
                  LPTSTR name,
                  size_t length)
{
  ACE_OS::unique_name (object, name, length);
}

// Return flags currently associated with handle.

ASYS_INLINE int
ACE::get_flags (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE::get_flags");

#if defined (ACE_LACKS_FCNTL)
  // ACE_OS::fcntl is not supported, e.g., on VxWorks.  It
  // would be better to store ACE's notion of the flags
  // associated with the handle, but this works for now.
  ACE_UNUSED_ARG (handle);
  return 0;
#else
  return ACE_OS::fcntl (handle, F_GETFL, 0);
#endif /* ACE_LACKS_FCNTL */
}

ASYS_INLINE u_long
ACE::log2 (u_long num)
{
  u_long log = 0;

  for (;
       num > 0;
       log++)
    num >>= 1;

  return log;
}

ASYS_INLINE char
ACE::nibble2hex (u_int n)
{
  return ACE::hex_chars_[n & 0x0f];
}

ASYS_INLINE u_char
ACE::hex2byte (char c)
{
  if (isdigit (c))
    return (u_char) (c - '0');
  else if (islower (c))
    return (u_char) (10 + c - 'a');
  else
    return (u_char) (10 + c - 'A');
}

ASYS_INLINE char
ACE::debug (void)
{
  return ACE::debug_;
}

ASYS_INLINE void
ACE::debug (char c)
{
  ACE::debug_ = c;
}

ASYS_INLINE char *
ACE::strnew (const char *s)
{
  // ACE_TRACE ("ACE::strnew");
  char *t = new char [::strlen(s) + 1];
  if (t == 0)
    return 0;
  else
    return ACE_OS::strcpy (t, s);
}

#if defined (ACE_WIN32) && defined (ACE_HAS_UNICODE)
ASYS_INLINE wchar_t *
ACE::strnew (const wchar_t *s)
{
  // ACE_TRACE ("ACE_OS::strnew");
  wchar_t *t = new wchar_t[::wcslen (s) + 1];
  if (t == 0)
    return 0;
  else
    return ACE_OS::strcpy (t, s);
}
#endif /* ACE_WIN32 && ACE_HAS_UNICODE */
