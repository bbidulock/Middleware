/**
 * @file repository_manager_admin.cpp
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * 
 * Simple administration program for the Repository Manager.
 */

#include "ace/Get_Opt.h"
#include "ace/Unbounded_Set.h"
#include "ace/String_Base.h"
#include "DAnCE/Logger/Log_Macros.h"

#include "repository_manager_admin.h"

struct Options
{
  Options (void)
    : rm_ior_ (""),
      domain_nc_ (""),
      list_ (false),
      shutdown_ (false)
  {
  }
  
  struct Installation
  {
    Installation (void)
    {
    }
    
    bool init (const ACE_TCHAR *inst)
    {
      ACE_CString tmp (inst);
      
      size_t begin = 0;
      size_t pos = tmp.find (',', begin);
      
      if (pos != ACE_CString::npos)
        path_ = tmp.substring (begin, pos - begin);
      else
        {
          ACE_ERROR ((LM_ERROR, DLINFO "Options::Installation::init - "
                      "Installation directive missing name and replace parameters, "
                      "must have form path,name,replace\n"));
          return false;
        }
      
      
      begin = pos + 1;
      pos = tmp.find (',', begin);
      
      if (pos != ACE_CString::npos)
        name_ = tmp.substring (begin, pos - begin);
      else 
        {
          ACE_ERROR ((LM_ERROR, DLINFO "Options::Installation::init - "
                      "Installation directive mssing replace parameter, "
                      "must have form path,name,replace\n"));
          return false;
        }
      
      begin = pos + 1;
      
      if (tmp[begin] == '0') replace_ = false;
      else if (tmp[begin] == '1') replace_ = true;
      else
        {
          ACE_ERROR ((LM_ERROR, DLINFO "Options::Installation::init - "
                      "Replace directive muse be 1 or 0.\n"));
          return false;
        }
      
      return true;
    }
    
    bool operator== (const Installation &rhs) const
    {
      return (replace_ == rhs.replace_) &&
        (path_ == rhs.path_) &&
        (name_ == rhs.name_);
    }
      
    ACE_CString path_, name_;
    bool replace_;
  };
  
  struct Creation
  {
    Creation (void)
    {
    }
    
    bool init (const ACE_TCHAR *inst)
    {
      ACE_CString tmp (inst);
      
      size_t begin = 0;
      size_t pos = tmp.find (',', begin);
      
      if (pos != ACE_CString::npos)
        path_ = tmp.substring (begin, pos - begin);
      else
        {
          ACE_ERROR ((LM_ERROR, DLINFO "Options::Creation::init - "
                      "Creation directive missing name, base location,  and replace parameters, "
                      "must have form path,name,base,replace\n"));
          return false;
        }
      
      
      begin = pos + 1;
      pos = tmp.find (',', begin);
      
      if (pos != ACE_CString::npos)
        name_ = tmp.substring (begin, pos - begin);
      else 
        {
          ACE_ERROR ((LM_ERROR, DLINFO "Options::Creation::init - "
                      "Creation directive mssing base location and replace parameter, "
                      "must have form path,name,base,replace\n"));
          return false;
        }
      
      begin = pos + 1;
      pos = tmp.find (',', begin);
      
      if (pos != ACE_CString::npos)
        base_location_ = tmp.substring (begin, pos - begin);
      else 
        {
          ACE_ERROR ((LM_ERROR, DLINFO "Options::Creation::init - "
                      "Creation directive mssing replace parameter, "
                      "must have form path,name,base,replace\n"));
          return false;
        }
      
      begin = pos + 1;
      
      if (tmp[begin] == '0') replace_ = false;
      else if (tmp[begin] == '1') replace_ = true;
      else
        {
          ACE_ERROR ((LM_ERROR, DLINFO "Options::Creation::init - "
                      "Replace directive muse be 1 or 0.\n"));
          return false;
        }
      
      return true;
    }
    
    bool operator== (const Creation &rhs) const
    {
      return (replace_ == rhs.replace_) &&
        (path_ == rhs.path_) &&
        (name_ == rhs.name_);
    }
      
    ACE_CString path_, name_, base_location_;
    bool replace_;
  };

  const ACE_TCHAR *rm_ior_;
  const ACE_TCHAR *domain_nc_;
  ACE_Unbounded_Set< Installation > install_;
  ACE_Unbounded_Set< Creation > create_;
  ACE_Unbounded_Set< ACE_CString > uninstall_;
  bool list_;
  bool shutdown_;
  
  void usage (void) 
  {
    ACE_ERROR ((LM_EMERGENCY, "usage:\n"
                "\t-h,--help\t\t\tThis message.\n"
                "\t-r,--rm-ior <ior>\t\tIOR where the RM instance may be found\n"
                "\t-i,--install <path>,<name>,<1|0>\t\tInstall package found at <path> into the RM, with <name>, <1> replacing or <0> not replacing an existing package. *\n"
                "\t-c,--create <path>,<name>,<base location>,<1|0>\t\tInstall package found at <path> into the RM, with <name>, <base location>, <1> replacing or <0> not replacing an existing package. *\n"
                "\t-u,--uninstall <uuid>\t\tUninstall package identified by UUID. *\n"
                "\t-l,--list\t\t\tList all packages installed in the RM\n"
                "\t-s,--shutdown\t\t\tShutdown the RM.\n"
                "\t-d,--domain-nc <ior>\t\tProvide a reference to the domain naming context\n"
                
                "\n\n\tArguments with a * may be specified multiple times.\n"));
  }
                
                
  bool parse_args (int argc, ACE_TCHAR *argv[])
  {
    ACE_Get_Opt get_opt (argc, argv,
                         ACE_TEXT ("hr:i:c:u:lsd:"),
                         0, 0, 
                         ACE_Get_Opt::RETURN_IN_ORDER,
                         1);
    
    get_opt.long_option (ACE_TEXT("help"), 'h', ACE_Get_Opt::NO_ARG);
    get_opt.long_option (ACE_TEXT("rm-ior"), 'r', ACE_Get_Opt::ARG_REQUIRED);
    get_opt.long_option (ACE_TEXT("install"), 'i', ACE_Get_Opt::ARG_REQUIRED);
    get_opt.long_option (ACE_TEXT("create"), 'c', ACE_Get_Opt::ARG_REQUIRED);
    get_opt.long_option (ACE_TEXT("uninstall"), 'u', ACE_Get_Opt::ARG_REQUIRED);
    get_opt.long_option (ACE_TEXT("list"), 'l', ACE_Get_Opt::NO_ARG);
    get_opt.long_option (ACE_TEXT("shutdown"), 's', ACE_Get_Opt::NO_ARG);
    get_opt.long_option (ACE_TEXT("domain-nc"), 'd', ACE_Get_Opt::ARG_REQUIRED);
    
    char c;
    Installation inst;
    Creation create;
    
    while ((c = get_opt ()) != -1)
      {
        switch (c)
          {
          case 'h':
            this->usage ();
            return false;
            break;
            
          case 'r':
            DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                          "Using provided RM IOR: %C\n",
                          get_opt.opt_arg ()));
            rm_ior_ = get_opt.opt_arg ();
            break;
            
          case 'i':
            if (!inst.init (get_opt.opt_arg ()))
              {
                this->usage ();
                return false;
              }
            
            if (inst.replace_)
              DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                            "Replacing installed package from path %C with name %C.\n", inst.path_.c_str (),
                            inst.name_.c_str ()));
            else
              DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                            "Installing package from path %C with name %C.\n", inst.path_.c_str (),
                            inst.name_.c_str ()));
            
            this->install_.insert (inst);
            break;

          case 'c':
            if (!create.init (get_opt.opt_arg ()))
              {
                this->usage ();
                return false;
              }
            
            if (create.replace_)
              DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                            "Replacing installed package from path %C with name %C and base location %C.\n", create.path_.c_str (),
                            create.name_.c_str (),
                            create.base_location_.c_str ()));
            else
              DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                            "Installing new package from path %C with name %C and base location %C.\n", create.path_.c_str (),
                            create.name_.c_str (),
                            create.base_location_.c_str ()));
            
            this->create_.insert (create);
            break;
            
          case 'u':
            DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                         "Removing package with UUID %C\n", get_opt.opt_arg ()));
            this->uninstall_.insert (get_opt.opt_arg ());
            break;

          case 'l':
            DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                          "Listing all packages.\n"));
            this->list_ = true;
            break;

          case 's':
            DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                          "Shutting down the RM instance.\n"));
            this->shutdown_ = true;
            break;
            
          case 'd':
            DANCE_DEBUG ((LM_DEBUG, DLINFO "Options::parse_args - "
                          "Using provided Domain NC: %C\n",
                          get_opt.opt_arg ()));
            domain_nc_ = get_opt.opt_arg ();

          case 0:
            if (ACE_OS::strcmp (get_opt.long_option (), ACE_TEXT ("domain-nc")) == 0)
              {
              }
            else 
              {
                DANCE_ERROR ((LM_ERROR, DLINFO "Options::parse_args - "
                              "Unknown long option: %C\n",
                              get_opt.long_option ()));
                this->usage ();
                return false;
              }
          }
      }
    return true;
  }
};

int ACE_TMAIN (int argc, ACE_TCHAR **argv)
{
  Options options;
  
  options.parse_args (argc, argv);
  
  return 0;
}
