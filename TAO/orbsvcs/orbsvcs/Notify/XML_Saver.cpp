// $Id$

#include "XML_Saver.h"

#include "ace/High_Res_Timer.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"

namespace TAO_NOTIFY
{
  XML_Saver::XML_Saver(bool timestamp)
    : output_ (0)
    , close_out_ (false)
    , backup_count_ (1)
    , timestamp_ (timestamp)
  {
  }

  XML_Saver::~XML_Saver()
  {
    if (this->output_ != 0)
    {
      ACE_ERROR ((LM_ERROR,
        ACE_TEXT ("(%P|%t) XML_Saver warning close not called or failed\n")
        ));
    }
  }

  void
  XML_Saver::backup_file_name (char * file_path, int nfile)
  {
    ACE_OS::snprintf(file_path, MAXPATHLEN, "%s.%3.3d",
      this->base_name_.c_str (),
      nfile);
  }

  void
  XML_Saver::close (ACE_ENV_SINGLE_ARG_DECL)
  {
    if (this->close_out_ && this->output_ != 0)
    {
      this->end_object(0, "notification_service" ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      delete this->output_;
      this->output_ = 0;

      // delete the oldest backup file (if it exists)
      size_t nfile = this->backup_count_ - 1;
      char old_path [MAXPATHLEN + 1];
      backup_file_name (old_path, nfile);
      ACE_OS::unlink (old_path);

      while (nfile != 0)
      {
        char new_path [MAXPATHLEN + 1];
        nfile -= 1;
        backup_file_name (new_path, nfile);
        // this may fail, we don't care
        ACE_OS::rename (new_path, old_path);
        ACE_OS::strcpy (old_path, new_path);
      }
      // old_path now contains the name of the backup file
      ACE_CString xml_name = this->base_name_;
      xml_name += ".xml";

      ACE_OS::rename (xml_name.c_str (), old_path);

      ACE_CString new_name = this->base_name_;
      new_name += ".new";
      ACE_OS::rename (new_name.c_str (), xml_name.c_str ());
    }
    this->output_ = 0;
  }

  bool
  XML_Saver::open(const ACE_CString & base_name, size_t backup_count)
  {
    this->base_name_ = base_name;
    this->backup_count_ = backup_count;
    if (base_name ==  "cout")
    {
      this->output_ = & cout;
      this->close_out_ = false;
    }
    else if (base_name ==  "cerr")
    {
      this->output_ = & cerr;
      this->close_out_ = false;
    }
    else
    {
      ACE_CString file_name = base_name;
      file_name += ".new";

      ofstream * fs = 0;
      ACE_NEW_RETURN (fs, ofstream , false);
      fs-> open (file_name.c_str());
      if (fs->is_open ())
      {
        this->output_ = fs;
        this->close_out_ = true;
      }
      else
      {
        delete fs;
        ACE_ASSERT(this->output_ == 0);
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("(%P|%t) XML_Saver unable to open %s\n"),
            base_name.c_str()));
      }
    }
    if (this->output_ != 0)
    {
      ostream& out = * this->output_;

      out << "<?xml version=\"1.0\"?>\n";
      ACE_DECLARE_NEW_CORBA_ENV;
      ACE_TRY
      {
        bool changed = true;
        NVPList attrs;

        ACE_Time_Value now = ACE_High_Res_Timer::gettimeofday();

        ACE_UINT64 nowus = now.usec();
        static const ACE_UINT64 USECSPERSEC = 1000 * 1000;
        ACE_UINT64 tmpus = now.sec();
        nowus += tmpus * USECSPERSEC;

        char nowusstr[128];
#ifdef ACE_LACKS_LONGLONG_T
        nowus.as_string(nowusstr);
#else
        ACE_OS::sprintf(nowusstr, ACE_UINT64_FORMAT_SPECIFIER, nowus);
#endif /* ACE_LACKS_LONGLONG_T */

        attrs.push_back(NVP("version", "1.0"));
        if (this->timestamp_)
        {
          attrs.push_back(NVP("timestamp", nowusstr));
        }
        this->begin_object(0, "notification_service", attrs, changed ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }
      ACE_CATCHANY
      {
        ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
          ACE_TEXT ("(%P|%t) XML_Saver Unknown exception\n"));
        delete this->output_;
        this->output_ = 0;
      }
      ACE_ENDTRY;
    }
    return this->output_ != 0;
  }

  bool XML_Saver::begin_object(CORBA::Long id,
    const ACE_CString& type,
    const NVPList& attrs,
    bool /* changed */
    ACE_ENV_ARG_DECL_NOT_USED)
  {
    ACE_ASSERT(this->output_ != 0);
    ostream& out = * this->output_;

    out << indent_ << "<" << type;
    if (id != 0)
    {
      // not all ostreams know what to do with a CORBA::Long
      long lid = id;
      out << " " << TOPOLOGY_ID_NAME << "=\"" << lid << "\"";
    }

    char * buffer = 0;
    size_t buffer_size = 0;
    for (size_t idx = 0; idx < attrs.size(); idx++)
    {
      out << " "
        << attrs[idx].name.c_str ()
        << "=\""
        << escape_string(buffer, buffer_size, attrs[idx].value.c_str ())
        << "\"";
    }
    delete [] buffer;
    out << ">\n";
    this->indent_ += "  ";
    return true;
  }

  void XML_Saver::end_object (CORBA::Long id,
    const ACE_CString& type ACE_ENV_ARG_DECL_NOT_USED)
  {
    ACE_ASSERT(this->output_ != 0);
    ACE_UNUSED_ARG (id);
    ostream& out = * this->output_;
    if (this->indent_.length() >= 2)
    {
      this->indent_ = this->indent_.substr(2);
    }
    // Note : We avoid flushing after every object by using \n instead of << endl;
    out << indent_ << "</" << type << ">\n";
  }

  static const char escaped_amp[] = "&amp;";
  static const char escaped_less[] = "&lt;";
  static const char escaped_greater[] = "&gt;";
  static const char escaped_apos[] = "&apos;";
  static const char escaped_quote[] = "&quot;";

  char *
  XML_Saver::escape_string(char *& buffer, size_t & size, const ACE_CString & str)
  {
    size_t len = str.length ();
    size_t needed = len * (sizeof(escaped_quote)-1) + 1;
    if (needed > size)
    {
      delete [] buffer;
      buffer = new char [needed];
      size = needed;
    }
    size_t pos = 0; // position in output buffer
    for (size_t stridx = 0; stridx < len; stridx++)
    {
      char curchar = str[stridx];
      if (curchar == '&')
      {
        strcpy (&buffer[pos], escaped_amp);
        pos += sizeof (escaped_amp) -1;
      }
      else if (curchar == '<')
      {
        strcpy (&buffer[pos], escaped_less);
        pos += sizeof (escaped_less) -1;
      }
      else if (curchar == '>')
      {
        strcpy (&buffer[pos], escaped_greater);
        pos += sizeof (escaped_greater) -1;
      }
      else if (curchar == '\'')
      {
        strcpy (&buffer[pos], escaped_apos);
        pos += sizeof (escaped_apos) -1;
      }
      else if (curchar == '\"')
      {
        strcpy (&buffer[pos], escaped_quote);
        pos += sizeof (escaped_quote) -1;
      }
      else
      {
        buffer[pos++] = curchar;
      }
    }
    buffer[pos++] = '\0';
    return buffer;
  }

} /* namespace TAO_NOTIFY */
