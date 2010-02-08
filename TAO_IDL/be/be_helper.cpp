
//=============================================================================
/**
 *  @file    be_helper.cpp
 *
 *  $Id$
 *
 * Provides helper classes to print generated code to the output
 *
 *
 *  @author Aniruddha Gokhale Improvements by Carlos O'Ryan
 */
//=============================================================================


#include "be_helper.h"
#include "be_codegen.h"
#include "be_extern.h"
#include "ast_expression.h"
#include "idl_defines.h"
#include "utl_identifier.h"
#include "utl_idlist.h"
#include "utl_string.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_ctype.h"
#include "../../tao/Version.h"

static const char copyright[] =
"// -*- C++ -*-\n"
"// $I" "d$\n\n"
"/**\n"
" * Code generated by the The ACE ORB (TAO) IDL Compiler v" TAO_VERSION "\n"
" * TAO and the TAO IDL Compiler have been developed by:\n"
" *       Center for Distributed Object Computing\n"
" *       Washington University\n"
" *       St. Louis, MO\n"
" *       USA\n"
" *       http://www.cs.wustl.edu/~schmidt/doc-center.html\n"
" * and\n"
" *       Distributed Object Computing Laboratory\n"
" *       University of California at Irvine\n"
" *       Irvine, CA\n"
" *       USA\n"
" * and\n"
" *       Institute for Software Integrated Systems\n"
" *       Vanderbilt University\n"
" *       Nashville, TN\n"
" *       USA\n"
" *       http://www.isis.vanderbilt.edu/\n"
" *\n"
" * Information about TAO is available at:\n"
" *     http://www.cs.wustl.edu/~schmidt/TAO.html\n"
" **/";

TAO_NL::TAO_NL (void)
{
  ACE_UNUSED_ARG (copyright);
}

TAO_INDENT::TAO_INDENT (int do_now)
  :  do_now_ (do_now)
{
}

TAO_UNINDENT::TAO_UNINDENT (int do_now)
  :  do_now_ (do_now)
{
}

const TAO_NL be_nl;
const TAO_INDENT be_idt;
const TAO_INDENT be_idt_nl (1);
const TAO_UNINDENT be_uidt;
const TAO_UNINDENT be_uidt_nl (1);

// Methods of the TAO_OutStream class.

TAO_OutStream::TAO_OutStream (void)
  : fp_ (0),
    indent_level_ (0)
{
}

TAO_OutStream::~TAO_OutStream (void)
{
  // Close the underlying I/O handle only if it exists.
  if (this->fp_ != 0)
    {
      ACE_OS::fclose (this->fp_);
      this->fp_ = 0;
    }

  indent_level_ = 0;
}

int
TAO_OutStream::open (const char *fname,
                     TAO_OutStream::STREAM_TYPE st)
{
  if (fname != 0)
    {
      // File name exists, open an I/O file handle.
      this->fp_ = ACE_OS::fopen (fname, "w");

      if (this->fp_ != 0)
        {
          this->st_ = st;
          // Put the copyright notice.  Not for the gperf's temp input
          // file.
          if (st != TAO_OutStream::TAO_GPERF_INPUT)
            {
              ACE_OS::fprintf (this->fp_,
                               "%s\n",
                               copyright);
            }

          return 0;
        }
      else
        {
          return -1;
        }
    }
  else
    {
      return -1;
    }
}

// Set and get the stream type.
void
TAO_OutStream::stream_type (TAO_OutStream::STREAM_TYPE st)
{
  this->st_ = st;
}

TAO_OutStream::STREAM_TYPE
TAO_OutStream::stream_type (void)
{
  return this->st_;
}

// Return the underlying lowlevel file pointer.
// indentation.
FILE *&
TAO_OutStream::file (void)
{
  return this->fp_;
}

int
TAO_OutStream::incr_indent (unsigned short flag)
{
  ++indent_level_;

  if (flag != 0)
    {
      return this->indent ();
    }
  else
    {
      // Do not indent output.
      return 0;
    }
}

// Indentation
int
TAO_OutStream::decr_indent (unsigned short flag)
{
  --this->indent_level_;
  // Just in case somebody gets "unindent happy".
  if (this->indent_level_ < 0)
    {
      // ACE_DEBUG ((LM_DEBUG, "negative indentation?\n"));
      this->indent_level_ = 0;
    }
  if (flag != 0)
    {
      return this->indent ();
    }
  else
    {
      // Do not indent output.
      return 0;
    }
}

int
TAO_OutStream::reset (void)
{
  this->indent_level_ = 0;
  return 0;
}

// Indented print.
int
TAO_OutStream::indent (void)
{
  // Based on the current indentation level, leave appropriate number of blank
  // spaces in the output.
  if (this->indent_level_ > 0)
    {
      for (int i = 0; i < this->indent_level_; i++)
        {
          ACE_OS::fprintf (this->fp_, "  ");
        }
    }

  return 0;
}

int
TAO_OutStream::nl (void)
{
  ACE_OS::fprintf (this->fp_, "\n");
  this->indent ();
  return 0;
}

// Macro generation.
int
TAO_OutStream::gen_ifdef_macro (const char *flat_name,
                                const char *suffix,
                                bool add_stream_type_suffix)
{
  static char macro [NAMEBUFSIZE];

  ACE_OS::memset (macro,
                  '\0',
                  NAMEBUFSIZE);

  ACE_OS::sprintf (macro,
                   "_%s_",
                   tao_cg->upcase (flat_name));

  if (suffix != 0)
    {
      ACE_OS::strcat (macro, "_");
      ACE_OS::strcat (macro, tao_cg->upcase (suffix));
      ACE_OS::strcat (macro, "_");
    }

  // Append a suffix representing the stream type.
  if (add_stream_type_suffix)
    {
      switch (this->st_)
        {
          case TAO_OutStream::TAO_CLI_HDR:
            ACE_OS::strcat (macro, "CH_");
            break;
          case TAO_OutStream::TAO_CLI_INL:
            ACE_OS::strcat (macro, "CI_");
            break;
          case TAO_OutStream::TAO_CLI_IMPL:
            ACE_OS::strcat (macro, "CS_");
            break;
          case TAO_OutStream::TAO_SVR_HDR:
            ACE_OS::strcat (macro, "SH_");
            break;
          case TAO_OutStream::TAO_IMPL_HDR:
            ACE_OS::strcat (macro, "IH_");
            break;
          case TAO_OutStream::TAO_IMPL_SKEL:
            ACE_OS::strcat (macro, "IS_");
            break;
          case TAO_OutStream::TAO_SVR_INL:
            ACE_OS::strcat (macro, "SI_");
            break;
          case TAO_OutStream::TAO_SVR_IMPL:
            ACE_OS::strcat (macro, "SS_");
            break;
          default:
            return -1;
        }
    }

  *this << "\n\n#if !defined (" << macro << ")\n";
  *this << "#define " << macro;

  return 0;
}

int
TAO_OutStream::gen_endif (void)
{
  *this << "\n\n#endif /* end #if !defined */";

  return 0;
}

// Printf style variable argument print.
int
TAO_OutStream::print (const char *format, ...)
{
  int result = 0;
  va_list ap;
  va_start (ap, format);
  ACE_OSCALL (::vfprintf (this->fp_,
                          format,
                          ap),
              int,
              -1,
              result);
  va_end (ap);

  return result;
}

TAO_OutStream &
TAO_OutStream::operator<< (const char *str)
{
  ACE_OS::fprintf (this->fp_, "%s", str);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::UShort num)
{
  ACE_OS::fprintf (this->fp_,
                   "%hu",
                   num);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Short num)
{
  ACE_OS::fprintf (this->fp_,
                   "%hd",
                   num);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::ULong num)
{
  ACE_OS::fprintf (this->fp_,
                   "%lu",
                   (unsigned long) num);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Long num)
{
  ACE_OS::fprintf (this->fp_,
                   "%ld",
                   (long) num);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::ULongLong num)
{
  ACE_OS::fprintf (this->fp_,
                   ACE_TEXT_ALWAYS_CHAR (ACE_UINT64_FORMAT_SPECIFIER),
                   num);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::LongLong num)
{
  ACE_OS::fprintf (this->fp_,
                   ACE_TEXT_ALWAYS_CHAR (ACE_INT64_FORMAT_SPECIFIER),
                   num);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_NL&)
{
  ACE_OS::fprintf (this->fp_ ,
                   "\n");
  this->indent ();

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_INDENT& i)
{
  this->incr_indent (0);

  if (i.do_now_)
    {
      this->nl ();
    }

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_UNINDENT& i)
{
  this->decr_indent (0);

  if (i.do_now_)
    {
      this->nl ();
    }

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (Identifier *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (UTL_IdList *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (AST_Expression *expr)
{
  return this->print (expr);
}

TAO_OutStream &
TAO_OutStream::print (Identifier *id)
{
  ACE_OS::fprintf (this->fp_,
                   id->get_string ());

  return *this;
}

TAO_OutStream &
TAO_OutStream::print (UTL_IdList *idl)
{
  long first = true;
  long second = false;
  Identifier *id = 0;

  for (UTL_IdListActiveIterator i (idl); !i.is_done (); i.next ())
    {
      if (!first)
        {
          *this << "::";
        }
      else if (second)
        {
          first = second = false;
        }

      // Print the identifier.
      id = i.item ();
      *this << id;

      if (first)
        {
          if (ACE_OS::strcmp (id->get_string (), "") != 0)
            {
              // Does not start with a "".
              first = false;
            }
          else
            {
              second = true;
            }
        }
    }

  return *this;
}

TAO_OutStream&
TAO_OutStream::print (AST_Expression *expr)
{
  AST_Expression::AST_ExprValue *ev = expr->ev ();

  if (ev)
    {
      switch (ev->et)
        {
        case AST_Expression::EV_short:
          this->TAO_OutStream::print (ACE_INT32_FORMAT_SPECIFIER_ASCII, ev->u.sval);
          break;
        case AST_Expression::EV_ushort:
          this->TAO_OutStream::print (ACE_INT32_FORMAT_SPECIFIER_ASCII "%c", ev->u.usval, 'U');
          break;
        case AST_Expression::EV_long:
          this->TAO_OutStream::print (ACE_INT32_FORMAT_SPECIFIER_ASCII, ev->u.lval);
          break;
        case AST_Expression::EV_ulong:
          this->TAO_OutStream::print (ACE_UINT32_FORMAT_SPECIFIER_ASCII "%c", ev->u.ulval, 'U');
          break;
        // The ACE_LACKS_LONGLONG_T guards have been removed around
        // the next 2 cases since the macros now used should work
        // whether native 64-bit integers are defined or not.
        case AST_Expression::EV_longlong:
          this->TAO_OutStream::print ("ACE_INT64_LITERAL (");
          this->TAO_OutStream::print (ACE_INT64_FORMAT_SPECIFIER_ASCII,
                                      ev->u.llval);
          this->TAO_OutStream::print (")");
          break;
        case AST_Expression::EV_ulonglong:
          this->TAO_OutStream::print ("ACE_UINT64_LITERAL (");
          this->TAO_OutStream::print (ACE_UINT64_FORMAT_SPECIFIER_ASCII,
                                      ev->u.ullval);
          this->TAO_OutStream::print (")");
          break;
        case AST_Expression::EV_float:
          this->TAO_OutStream::print ("%f%c", ev->u.fval, 'F');
          break;
        case AST_Expression::EV_double:
          this->TAO_OutStream::print ("%24.16G", ev->u.dval);
          break;
        case AST_Expression::EV_longdouble:
          break;
        case AST_Expression::EV_char:
          // isprint() sees \ and ' as printable characters
          // so we have to test for them first.
          if (ev->u.cval == '\\')
            this->TAO_OutStream::print ("'\\\\'");
          else if (ev->u.cval == '\'')
            this->TAO_OutStream::print ("'\\''");

          // This handles hex and octal escape sequences
          // that would print out either as weird characters
          // or as an unsigned number too large for a char.
          else if ((unsigned char) ev->u.cval > ACE_CHAR_MAX)
            this->TAO_OutStream::print ("%hd", ev->u.cval);
          else if (ACE_OS::ace_isprint (ev->u.cval))
            this->TAO_OutStream::print ("'%c'", ev->u.cval);
          else if (ACE_OS::ace_iscntrl (ev->u.cval))
            switch (ev->u.cval)
              {
                case '\n':
                  this->TAO_OutStream::print ("'\\n'");
                  break;
                case '\t':
                  this->TAO_OutStream::print ("'\\t'");
                  break;
                case '\r':
                  this->TAO_OutStream::print ("'\\r'");
                  break;
                case '\v':
                  this->TAO_OutStream::print ("'\\v'");
                  break;
                case '\f':
                  this->TAO_OutStream::print ("'\\f'");
                  break;
                case '\b':
                  this->TAO_OutStream::print ("'\\b'");
                  break;
                case '\a':
                  this->TAO_OutStream::print ("'\\a'");
                  break;
                case '\?':
                  this->TAO_OutStream::print ("'?'");
                  break;
              default:
                this->TAO_OutStream::print ("'\\x%x'", ev->u.cval);
              }
           else
            this->TAO_OutStream::print ("'\\x%x'", ev->u.cval);
          break;
        case AST_Expression::EV_wchar:
          this->TAO_OutStream::print ("L'%lc'", ev->u.wcval);
          break;
        case AST_Expression::EV_octet:
          this->TAO_OutStream::print ("%d", ev->u.oval);
          break;
        case AST_Expression::EV_bool:
          this->TAO_OutStream::print ("%s", ev->u.bval ? "true" : "false");
          break;
        case AST_Expression::EV_string:
          this->TAO_OutStream::print ("\"%s\"", ev->u.strval->get_string ());
          break;
        case AST_Expression::EV_wstring:
          this->TAO_OutStream::print ("L\"%s\"", ev->u.wstrval);
          break;
        case AST_Expression::EV_enum:
          this->print (expr->n ());
          break;
        default:
          break;
        }
    }
  else
    {
      // XXXASG: need to add code here
    }

  return *this;
}
