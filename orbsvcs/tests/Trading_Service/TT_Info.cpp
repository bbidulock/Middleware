// $Id$
#include "TT_Info.h"
#include "orbsvcs/Trader/Property_Evaluator.h"

const char* TT_Info::INTERFACE_NAMES[] = 
{
  "Remote_IO",
  "Plotter",
  "Printer",
  "File_System",
  "PostScript_Printer"
};

const char* TT_Info::REMOTE_IO_NAME = "Remote_IO";

const char* TT_Info::REMOTE_IO_PROPERTY_NAMES[] = 
{
  "Name",
  "Location",
  "Description"
};

CORBA::TypeCode_ptr TT_Info::REMOTE_IO_PROPERTY_TYPES[] =
{
  CORBA::_tc_string,
  CORBA::_tc_string,
  CORBA::_tc_string
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::REMOTE_IO_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
};

const char* TT_Info::PLOTTER_NAME = "Plotter";

const char* TT_Info::PLOTTER_PROPERTY_NAMES[] = 
{
  "Num_Colors",
  "Auto_Loading",
  "Cost_Per_Page",
  "Model_Number",
  "User_Queue",
  "File_Sizes_Pending"
};

CORBA::TypeCode_ptr TT_Info::PLOTTER_PROPERTY_TYPES[] =
{
  CORBA::_tc_long,
  CORBA::_tc_boolean,
  CORBA::_tc_float,
  CORBA::_tc_string,
  TAO_Sequences::_tc_StringSeq,
  TAO_Sequences::_tc_ULongSeq
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::PLOTTER_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL
};

const char* TT_Info::PRINTER_NAME = "Printer";

const char* TT_Info::PRINTER_PROPERTY_NAMES[] = 
{
  "Color",
  "Double_Sided",
  "Cost_Per_Page",
  "Model_Number",
  "Pages_Per_Sec",
  "User_Queue",
  "File_Sizes_Pending"
};

CORBA::TypeCode_ptr TT_Info::PRINTER_PROPERTY_TYPES[] =
{
  CORBA::_tc_boolean,
  CORBA::_tc_boolean,
  CORBA::_tc_float,
  CORBA::_tc_string,
  CORBA::_tc_ushort,
  TAO_Sequences::_tc_StringSeq,
  TAO_Sequences::_tc_ULongSeq
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::PRINTER_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL
};

const char* TT_Info::FILESYSTEM_NAME = "File_System";

const char* TT_Info::FILESYSTEM_PROPERTY_NAMES[] =
{
  "Disk_Space",
  "Space_Remaining",
  "Permission_Level"
};

CORBA::TypeCode_ptr TT_Info::FILESYSTEM_PROPERTY_TYPES[] =
{
  CORBA::_tc_ulong,
  CORBA::_tc_ulong,
  CORBA::_tc_ushort
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::FILESYSTEM_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL
};

const char* TT_Info::PS_PRINTER_PROPERTY_NAMES[] = 
{
  "Version"
};


const char* TT_Info::PS_PRINTER_NAME = "PostScript_Printer";

CORBA::TypeCode_ptr TT_Info::PS_PRINTER_PROPERTY_TYPES[] =
{
  CORBA::_tc_ushort
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::PS_PRINTER_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY
};

const char* TT_Info::LOCATIONS[] =
{
  "Bryan 509",
  "Bryan 503",
  "Dunker 102",
  "Jolley 408",
  "Lopata 401",
  "January 110",
  "Cupples I 30",
  "Cupples II 201",
  "Urbauer 321",
  "Umrath 302",
  "Wilson 110",
  "Olin 239",
  "Simon 238",
  "Rebstock 232",
  "McMillan 123"
};

const char* TT_Info::USERS[] = 
{
  "sbw1",
  "schmidt",
  "naga",
  "alex",
  "mk1",
  "marina",
  "sumedh",
  "sergio",
  "coryan",
  "cdgill",
  "levine",
  "jxh",
  "irfan",
  "nanbor",
  "eea1",
  "brunsch"
};

const char* TT_Info::MODEL_NUMBERS[] =
{
  "HP238293892bn2398",
  "PK92839nkse092309",
  "8328323n293kljs98",
  "29309sjdkq34jksd2",
  "09q834efjhqw834q3",
  "q9834fdkjwq0934kf",
  "q834jfda09q834djk",
  "kajsd09q384kjda90",
  "9p83q4jklsdj098q3",
  "09a834ojfda09wu3r",
  "09234kejdfq934jed",
  "0q83kjefd09384jda",
  "asdfj0283jkdf0923",
  "kladfp72wu34j230f",
  "9q834jidlj234ujof"
};

const int TT_Info::NUM_QUERIES = 1;
const char* TT_Info::QUERIES[][3] =
{
  {INTERFACE_NAMES[REMOTE_IO], "", ""}
};


void
TT_Info::dump_properties (const CosTrading::PropertySeq& prop_seq)
{
  CORBA::Environment env;
  TAO_Property_Evaluator prop_eval (prop_seq);
  
  for (int length = prop_seq.length (), k = 0; k < length; k++)
    {
      CORBA::Any* value = 0;
      CORBA::TypeCode_ptr tc = 0;
      ACE_DEBUG ((LM_DEBUG, "%-15s: ", prop_seq[k].name.in ()));
      TAO_TRY
	{
	  value = prop_eval.property_value(k, env);
	  TAO_CHECK_ENV;

	  tc = value->type ();
	}
      TAO_CATCHANY
	{
	  ACE_DEBUG ((LM_DEBUG, "Error retrieving property value.\n"));	  
	}
      TAO_ENDTRY;

      if (tc == 0)
	continue;
      else if (tc->equal (CORBA::_tc_float, env))
	{
	  CORBA::Float f;
	  (*value) >>= f;
	  ACE_DEBUG ((LM_DEBUG, "%f\n", f));
	}
      else if (tc->equal (CORBA::_tc_double, env))
	{
	  CORBA::Double d;
	  (*value) >>= d;
	  ACE_DEBUG ((LM_DEBUG, "%f\n", d));
	}
      else if (tc->equal (CORBA::_tc_boolean, env))
	{
	  CORBA::Boolean b = 0;
	  (*value) >>= CORBA::Any::to_boolean(b);
	  ACE_DEBUG ((LM_DEBUG, "%s\n", b ? "TRUE" : "FALSE"));
	}
      else if (tc->equal (CORBA::_tc_short, env))
	{
	  CORBA::Short s;
	  (*value) >>= s;
	  ACE_DEBUG ((LM_DEBUG, "%d\n", s));
	}
      else if (tc->equal (CORBA::_tc_ushort, env))
	{
	  CORBA::UShort u;
	  (*value) >>= u;
	  ACE_DEBUG ((LM_DEBUG, "%d\n", u));
	}
      else if (tc->equal (CORBA::_tc_ulong, env))
	{
	  CORBA::ULong ulong;
	  (*value) >>= ulong;
	  ACE_DEBUG ((LM_DEBUG, "%d\n", ulong));
	}
      else if (tc->equal (CORBA::_tc_long, env))
	{
	  CORBA::Long clong;
	  (*value) >>= clong;
	  ACE_DEBUG ((LM_DEBUG, "%d\n", clong));
	}      
      else if (tc->equal (CORBA::_tc_string, env))
	{
	  CORBA::String_var s;
	  (*value) >>= s.out ();
	  ACE_DEBUG ((LM_DEBUG, "%s\n", s.in ()));
	}      
      else if (tc->equal (TAO_Sequences::_tc_StringSeq, env))
	{
	  TAO_Sequences::StringSeq str_seq;
	  //(*value) >>= str_seq;

	  for (int length = str_seq.length (), i = 0; i < length; i++)
	    ACE_DEBUG ((LM_DEBUG, "%s ", (const char *) str_seq[i]));

	  ACE_DEBUG ((LM_DEBUG, "\n"));
	}
      else if (tc->equal (TAO_Sequences::_tc_ULongSeq, env))
	{
	  TAO_Sequences::ULongSeq ulong_seq;
	  //	  (*value) >>= ulong_seq;

	  for (int length = ulong_seq.length (), i = 0; i < length; i++)
	    ACE_DEBUG ((LM_DEBUG, "%d ", ulong_seq[i]));

	  ACE_DEBUG ((LM_DEBUG, "\n"));
	}
    }
}

