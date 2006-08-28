#include "CIAOServerResources.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // ServerResourcesDef
    // 

    ServerResourcesDef::
    ServerResourcesDef (::CIAO::Config_Handlers::ORBConfigs const& orbConfigs__)
    : 
    ::XSCRT::Type (), 
    orbConfigs_ (new ::CIAO::Config_Handlers::ORBConfigs (orbConfigs__)),
    regulator__ ()
    {
      orbConfigs_->container (this);
    }

    ServerResourcesDef::
    ServerResourcesDef (::CIAO::Config_Handlers::ServerResourcesDef const& s)
    :
    ::XSCRT::Type (),
    cmdline_ (s.cmdline_.get () ? new ::CIAO::Config_Handlers::ServerCmdlineOptions (*s.cmdline_) : 0),
    svcconf_ (s.svcconf_.get () ? new ::CIAO::Config_Handlers::ACESvcConf (*s.svcconf_) : 0),
    orbConfigs_ (new ::CIAO::Config_Handlers::ORBConfigs (*s.orbConfigs_)),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      if (cmdline_.get ()) cmdline_->container (this);
      if (svcconf_.get ()) svcconf_->container (this);
      orbConfigs_->container (this);
      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::ServerResourcesDef& ServerResourcesDef::
    operator= (::CIAO::Config_Handlers::ServerResourcesDef const& s)
    {
      if (s.cmdline_.get ()) cmdline (*(s.cmdline_));
      else cmdline_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ServerCmdlineOptions > (0);

      if (s.svcconf_.get ()) svcconf (*(s.svcconf_));
      else svcconf_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ACESvcConf > (0);

      orbConfigs (s.orbConfigs ());

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // ServerResourcesDef
    // 
    bool ServerResourcesDef::
    cmdline_p () const
    {
      return cmdline_.get () != 0;
    }

    ::CIAO::Config_Handlers::ServerCmdlineOptions const& ServerResourcesDef::
    cmdline () const
    {
      return *cmdline_;
    }

    void ServerResourcesDef::
    cmdline (::CIAO::Config_Handlers::ServerCmdlineOptions const& e)
    {
      if (cmdline_.get ())
      {
        *cmdline_ = e;
      }

      else
      {
        cmdline_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ServerCmdlineOptions > (new ::CIAO::Config_Handlers::ServerCmdlineOptions (e));
        cmdline_->container (this);
      }
    }

    // ServerResourcesDef
    // 
    bool ServerResourcesDef::
    svcconf_p () const
    {
      return svcconf_.get () != 0;
    }

    ::CIAO::Config_Handlers::ACESvcConf const& ServerResourcesDef::
    svcconf () const
    {
      return *svcconf_;
    }

    void ServerResourcesDef::
    svcconf (::CIAO::Config_Handlers::ACESvcConf const& e)
    {
      if (svcconf_.get ())
      {
        *svcconf_ = e;
      }

      else
      {
        svcconf_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ACESvcConf > (new ::CIAO::Config_Handlers::ACESvcConf (e));
        svcconf_->container (this);
      }
    }

    // ServerResourcesDef
    // 
    ::CIAO::Config_Handlers::ORBConfigs const& ServerResourcesDef::
    orbConfigs () const
    {
      return *orbConfigs_;
    }

    void ServerResourcesDef::
    orbConfigs (::CIAO::Config_Handlers::ORBConfigs const& e)
    {
      *orbConfigs_ = e;
    }

    // ServerResourcesDef
    // 
    bool ServerResourcesDef::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& ServerResourcesDef::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& ServerResourcesDef::
    id ()
    {
      return *id_;
    }

    void ServerResourcesDef::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // ServerCmdlineOptions
    // 

    ServerCmdlineOptions::
    ServerCmdlineOptions ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    ServerCmdlineOptions::
    ServerCmdlineOptions (::CIAO::Config_Handlers::ServerCmdlineOptions const& s)
    :
    ::XSCRT::Type (),
    regulator__ ()
    {
      {
        for (arg_const_iterator i (s.arg_.begin ());i != s.arg_.end ();++i) add_arg (*i);
      }
    }

    ::CIAO::Config_Handlers::ServerCmdlineOptions& ServerCmdlineOptions::
    operator= (::CIAO::Config_Handlers::ServerCmdlineOptions const& s)
    {
      arg_.clear ();
      {
        for (arg_const_iterator i (s.arg_.begin ());i != s.arg_.end ();++i) add_arg (*i);
      }

      return *this;
    }


    // ServerCmdlineOptions
    // 
    ServerCmdlineOptions::arg_iterator ServerCmdlineOptions::
    begin_arg ()
    {
      return arg_.begin ();
    }

    ServerCmdlineOptions::arg_iterator ServerCmdlineOptions::
    end_arg ()
    {
      return arg_.end ();
    }

    ServerCmdlineOptions::arg_const_iterator ServerCmdlineOptions::
    begin_arg () const
    {
      return arg_.begin ();
    }

    ServerCmdlineOptions::arg_const_iterator ServerCmdlineOptions::
    end_arg () const
    {
      return arg_.end ();
    }

    void ServerCmdlineOptions::
    add_arg (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      arg_.push_back (e);
    }

    size_t ServerCmdlineOptions::
    count_arg(void) const
    {
      return arg_.size ();
    }


    // ACESvcConf
    // 

    ACESvcConf::
    ACESvcConf ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    ACESvcConf::
    ACESvcConf (::CIAO::Config_Handlers::ACESvcConf const& s)
    :
    ::XSCRT::Type (),
    uri_ (s.uri_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.uri_) : 0),
    regulator__ ()
    {
      if (uri_.get ()) uri_->container (this);
    }

    ::CIAO::Config_Handlers::ACESvcConf& ACESvcConf::
    operator= (::CIAO::Config_Handlers::ACESvcConf const& s)
    {
      if (s.uri_.get ()) uri (*(s.uri_));
      else uri_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      return *this;
    }


    // ACESvcConf
    // 
    bool ACESvcConf::
    uri_p () const
    {
      return uri_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ACESvcConf::
    uri () const
    {
      return *uri_;
    }

    void ACESvcConf::
    uri (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (uri_.get ())
      {
        *uri_ = e;
      }

      else
      {
        uri_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        uri_->container (this);
      }
    }


    // ORBConfigs
    // 

    ORBConfigs::
    ORBConfigs ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    ORBConfigs::
    ORBConfigs (::CIAO::Config_Handlers::ORBConfigs const& s)
    :
    ::XSCRT::Type (),
    resources_ (s.resources_.get () ? new ::CIAO::Config_Handlers::ORBResources (*s.resources_) : 0),
    regulator__ ()
    {
      if (resources_.get ()) resources_->container (this);
      {
        for (policySet_const_iterator i (s.policySet_.begin ());i != s.policySet_.end ();++i) add_policySet (*i);
      }
    }

    ::CIAO::Config_Handlers::ORBConfigs& ORBConfigs::
    operator= (::CIAO::Config_Handlers::ORBConfigs const& s)
    {
      if (s.resources_.get ()) resources (*(s.resources_));
      else resources_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ORBResources > (0);

      policySet_.clear ();
      {
        for (policySet_const_iterator i (s.policySet_.begin ());i != s.policySet_.end ();++i) add_policySet (*i);
      }

      return *this;
    }


    // ORBConfigs
    // 
    bool ORBConfigs::
    resources_p () const
    {
      return resources_.get () != 0;
    }

    ::CIAO::Config_Handlers::ORBResources const& ORBConfigs::
    resources () const
    {
      return *resources_;
    }

    void ORBConfigs::
    resources (::CIAO::Config_Handlers::ORBResources const& e)
    {
      if (resources_.get ())
      {
        *resources_ = e;
      }

      else
      {
        resources_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ORBResources > (new ::CIAO::Config_Handlers::ORBResources (e));
        resources_->container (this);
      }
    }

    // ORBConfigs
    // 
    ORBConfigs::policySet_iterator ORBConfigs::
    begin_policySet ()
    {
      return policySet_.begin ();
    }

    ORBConfigs::policySet_iterator ORBConfigs::
    end_policySet ()
    {
      return policySet_.end ();
    }

    ORBConfigs::policySet_const_iterator ORBConfigs::
    begin_policySet () const
    {
      return policySet_.begin ();
    }

    ORBConfigs::policySet_const_iterator ORBConfigs::
    end_policySet () const
    {
      return policySet_.end ();
    }

    void ORBConfigs::
    add_policySet (::CIAO::Config_Handlers::PolicySet const& e)
    {
      policySet_.push_back (e);
    }

    size_t ORBConfigs::
    count_policySet(void) const
    {
      return policySet_.size ();
    }


    // ORBResources
    // 

    ORBResources::
    ORBResources ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    ORBResources::
    ORBResources (::CIAO::Config_Handlers::ORBResources const& s)
    :
    ::XSCRT::Type (),
    regulator__ ()
    {
      {
        for (threadpool_const_iterator i (s.threadpool_.begin ());i != s.threadpool_.end ();++i) add_threadpool (*i);
      }

      {
        for (threadpoolWithLanes_const_iterator i (s.threadpoolWithLanes_.begin ());i != s.threadpoolWithLanes_.end ();++i) add_threadpoolWithLanes (*i);
      }

      {
        for (connectionBands_const_iterator i (s.connectionBands_.begin ());i != s.connectionBands_.end ();++i) add_connectionBands (*i);
      }
    }

    ::CIAO::Config_Handlers::ORBResources& ORBResources::
    operator= (::CIAO::Config_Handlers::ORBResources const& s)
    {
      threadpool_.clear ();
      {
        for (threadpool_const_iterator i (s.threadpool_.begin ());i != s.threadpool_.end ();++i) add_threadpool (*i);
      }

      threadpoolWithLanes_.clear ();
      {
        for (threadpoolWithLanes_const_iterator i (s.threadpoolWithLanes_.begin ());i != s.threadpoolWithLanes_.end ();++i) add_threadpoolWithLanes (*i);
      }

      connectionBands_.clear ();
      {
        for (connectionBands_const_iterator i (s.connectionBands_.begin ());i != s.connectionBands_.end ();++i) add_connectionBands (*i);
      }

      return *this;
    }


    // ORBResources
    // 
    ORBResources::threadpool_iterator ORBResources::
    begin_threadpool ()
    {
      return threadpool_.begin ();
    }

    ORBResources::threadpool_iterator ORBResources::
    end_threadpool ()
    {
      return threadpool_.end ();
    }

    ORBResources::threadpool_const_iterator ORBResources::
    begin_threadpool () const
    {
      return threadpool_.begin ();
    }

    ORBResources::threadpool_const_iterator ORBResources::
    end_threadpool () const
    {
      return threadpool_.end ();
    }

    void ORBResources::
    add_threadpool (::CIAO::Config_Handlers::ThreadpoolDef const& e)
    {
      threadpool_.push_back (e);
    }

    size_t ORBResources::
    count_threadpool(void) const
    {
      return threadpool_.size ();
    }

    // ORBResources
    // 
    ORBResources::threadpoolWithLanes_iterator ORBResources::
    begin_threadpoolWithLanes ()
    {
      return threadpoolWithLanes_.begin ();
    }

    ORBResources::threadpoolWithLanes_iterator ORBResources::
    end_threadpoolWithLanes ()
    {
      return threadpoolWithLanes_.end ();
    }

    ORBResources::threadpoolWithLanes_const_iterator ORBResources::
    begin_threadpoolWithLanes () const
    {
      return threadpoolWithLanes_.begin ();
    }

    ORBResources::threadpoolWithLanes_const_iterator ORBResources::
    end_threadpoolWithLanes () const
    {
      return threadpoolWithLanes_.end ();
    }

    void ORBResources::
    add_threadpoolWithLanes (::CIAO::Config_Handlers::ThreadpoolWithLanesDef const& e)
    {
      threadpoolWithLanes_.push_back (e);
    }

    size_t ORBResources::
    count_threadpoolWithLanes(void) const
    {
      return threadpoolWithLanes_.size ();
    }

    // ORBResources
    // 
    ORBResources::connectionBands_iterator ORBResources::
    begin_connectionBands ()
    {
      return connectionBands_.begin ();
    }

    ORBResources::connectionBands_iterator ORBResources::
    end_connectionBands ()
    {
      return connectionBands_.end ();
    }

    ORBResources::connectionBands_const_iterator ORBResources::
    begin_connectionBands () const
    {
      return connectionBands_.begin ();
    }

    ORBResources::connectionBands_const_iterator ORBResources::
    end_connectionBands () const
    {
      return connectionBands_.end ();
    }

    void ORBResources::
    add_connectionBands (::CIAO::Config_Handlers::ConnectionBandsDef const& e)
    {
      connectionBands_.push_back (e);
    }

    size_t ORBResources::
    count_connectionBands(void) const
    {
      return connectionBands_.size ();
    }


    // Priority
    // 

    Priority::
    Priority (::XMLSchema::int_ const& b__)
    : 
    Base__ (b__),
    regulator__ ()
    {
    }

    Priority::
    Priority (::CIAO::Config_Handlers::Priority const& s)
    :
    Base__ (s),
    regulator__ ()
    {
    }

    ::CIAO::Config_Handlers::Priority& Priority::
    operator= (::CIAO::Config_Handlers::Priority const& s)
    {
      static_cast< Base__& > (*this) = static_cast< Base__ const& > (s);

      return *this;
    }



    // ThreadpoolDef
    // 

    ThreadpoolDef::
    ThreadpoolDef (::XMLSchema::unsignedLong const& stacksize__,
                   ::XMLSchema::unsignedLong const& static_threads__,
                   ::XMLSchema::unsignedLong const& dynamic_threads__,
                   ::CIAO::Config_Handlers::Priority const& default_priority__,
                   ::XMLSchema::boolean const& allow_request_buffering__,
                   ::XMLSchema::unsignedLong const& max_buffered_requests__,
                   ::XMLSchema::unsignedLong const& max_request_buffered_size__)
    : 
    ::XSCRT::Type (), 
    stacksize_ (new ::XMLSchema::unsignedLong (stacksize__)),
    static_threads_ (new ::XMLSchema::unsignedLong (static_threads__)),
    dynamic_threads_ (new ::XMLSchema::unsignedLong (dynamic_threads__)),
    default_priority_ (new ::CIAO::Config_Handlers::Priority (default_priority__)),
    allow_request_buffering_ (new ::XMLSchema::boolean (allow_request_buffering__)),
    max_buffered_requests_ (new ::XMLSchema::unsignedLong (max_buffered_requests__)),
    max_request_buffered_size_ (new ::XMLSchema::unsignedLong (max_request_buffered_size__)),
    regulator__ ()
    {
      stacksize_->container (this);
      static_threads_->container (this);
      dynamic_threads_->container (this);
      default_priority_->container (this);
      allow_request_buffering_->container (this);
      max_buffered_requests_->container (this);
      max_request_buffered_size_->container (this);
    }

    ThreadpoolDef::
    ThreadpoolDef (::CIAO::Config_Handlers::ThreadpoolDef const& s)
    :
    ::XSCRT::Type (),
    stacksize_ (new ::XMLSchema::unsignedLong (*s.stacksize_)),
    static_threads_ (new ::XMLSchema::unsignedLong (*s.static_threads_)),
    dynamic_threads_ (new ::XMLSchema::unsignedLong (*s.dynamic_threads_)),
    default_priority_ (new ::CIAO::Config_Handlers::Priority (*s.default_priority_)),
    allow_request_buffering_ (new ::XMLSchema::boolean (*s.allow_request_buffering_)),
    max_buffered_requests_ (new ::XMLSchema::unsignedLong (*s.max_buffered_requests_)),
    max_request_buffered_size_ (new ::XMLSchema::unsignedLong (*s.max_request_buffered_size_)),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      stacksize_->container (this);
      static_threads_->container (this);
      dynamic_threads_->container (this);
      default_priority_->container (this);
      allow_request_buffering_->container (this);
      max_buffered_requests_->container (this);
      max_request_buffered_size_->container (this);
      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::ThreadpoolDef& ThreadpoolDef::
    operator= (::CIAO::Config_Handlers::ThreadpoolDef const& s)
    {
      stacksize (s.stacksize ());

      static_threads (s.static_threads ());

      dynamic_threads (s.dynamic_threads ());

      default_priority (s.default_priority ());

      allow_request_buffering (s.allow_request_buffering ());

      max_buffered_requests (s.max_buffered_requests ());

      max_request_buffered_size (s.max_request_buffered_size ());

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // ThreadpoolDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolDef::
    stacksize () const
    {
      return *stacksize_;
    }

    void ThreadpoolDef::
    stacksize (::XMLSchema::unsignedLong const& e)
    {
      *stacksize_ = e;
    }

    // ThreadpoolDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolDef::
    static_threads () const
    {
      return *static_threads_;
    }

    void ThreadpoolDef::
    static_threads (::XMLSchema::unsignedLong const& e)
    {
      *static_threads_ = e;
    }

    // ThreadpoolDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolDef::
    dynamic_threads () const
    {
      return *dynamic_threads_;
    }

    void ThreadpoolDef::
    dynamic_threads (::XMLSchema::unsignedLong const& e)
    {
      *dynamic_threads_ = e;
    }

    // ThreadpoolDef
    // 
    ::CIAO::Config_Handlers::Priority const& ThreadpoolDef::
    default_priority () const
    {
      return *default_priority_;
    }

    void ThreadpoolDef::
    default_priority (::CIAO::Config_Handlers::Priority const& e)
    {
      *default_priority_ = e;
    }

    // ThreadpoolDef
    // 
    ::XMLSchema::boolean const& ThreadpoolDef::
    allow_request_buffering () const
    {
      return *allow_request_buffering_;
    }

    void ThreadpoolDef::
    allow_request_buffering (::XMLSchema::boolean const& e)
    {
      *allow_request_buffering_ = e;
    }

    // ThreadpoolDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolDef::
    max_buffered_requests () const
    {
      return *max_buffered_requests_;
    }

    void ThreadpoolDef::
    max_buffered_requests (::XMLSchema::unsignedLong const& e)
    {
      *max_buffered_requests_ = e;
    }

    // ThreadpoolDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolDef::
    max_request_buffered_size () const
    {
      return *max_request_buffered_size_;
    }

    void ThreadpoolDef::
    max_request_buffered_size (::XMLSchema::unsignedLong const& e)
    {
      *max_request_buffered_size_ = e;
    }

    // ThreadpoolDef
    // 
    bool ThreadpoolDef::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& ThreadpoolDef::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& ThreadpoolDef::
    id ()
    {
      return *id_;
    }

    void ThreadpoolDef::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // ThreadpoolWithLanesDef
    // 

    ThreadpoolWithLanesDef::
    ThreadpoolWithLanesDef (::XMLSchema::unsignedLong const& stacksize__,
                            ::XMLSchema::boolean const& allow_borrowing__,
                            ::XMLSchema::boolean const& allow_request_buffering__,
                            ::XMLSchema::unsignedLong const& max_buffered_requests__,
                            ::XMLSchema::unsignedLong const& max_request_buffered_size__)
    : 
    ::XSCRT::Type (), 
    stacksize_ (new ::XMLSchema::unsignedLong (stacksize__)),
    allow_borrowing_ (new ::XMLSchema::boolean (allow_borrowing__)),
    allow_request_buffering_ (new ::XMLSchema::boolean (allow_request_buffering__)),
    max_buffered_requests_ (new ::XMLSchema::unsignedLong (max_buffered_requests__)),
    max_request_buffered_size_ (new ::XMLSchema::unsignedLong (max_request_buffered_size__)),
    regulator__ ()
    {
      stacksize_->container (this);
      allow_borrowing_->container (this);
      allow_request_buffering_->container (this);
      max_buffered_requests_->container (this);
      max_request_buffered_size_->container (this);
    }

    ThreadpoolWithLanesDef::
    ThreadpoolWithLanesDef (::CIAO::Config_Handlers::ThreadpoolWithLanesDef const& s)
    :
    ::XSCRT::Type (),
    stacksize_ (new ::XMLSchema::unsignedLong (*s.stacksize_)),
    allow_borrowing_ (new ::XMLSchema::boolean (*s.allow_borrowing_)),
    allow_request_buffering_ (new ::XMLSchema::boolean (*s.allow_request_buffering_)),
    max_buffered_requests_ (new ::XMLSchema::unsignedLong (*s.max_buffered_requests_)),
    max_request_buffered_size_ (new ::XMLSchema::unsignedLong (*s.max_request_buffered_size_)),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      {
        for (threadpoolLane_const_iterator i (s.threadpoolLane_.begin ());i != s.threadpoolLane_.end ();++i) add_threadpoolLane (*i);
      }

      stacksize_->container (this);
      allow_borrowing_->container (this);
      allow_request_buffering_->container (this);
      max_buffered_requests_->container (this);
      max_request_buffered_size_->container (this);
      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::ThreadpoolWithLanesDef& ThreadpoolWithLanesDef::
    operator= (::CIAO::Config_Handlers::ThreadpoolWithLanesDef const& s)
    {
      threadpoolLane_.clear ();
      {
        for (threadpoolLane_const_iterator i (s.threadpoolLane_.begin ());i != s.threadpoolLane_.end ();++i) add_threadpoolLane (*i);
      }

      stacksize (s.stacksize ());

      allow_borrowing (s.allow_borrowing ());

      allow_request_buffering (s.allow_request_buffering ());

      max_buffered_requests (s.max_buffered_requests ());

      max_request_buffered_size (s.max_request_buffered_size ());

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // ThreadpoolWithLanesDef
    // 
    ThreadpoolWithLanesDef::threadpoolLane_iterator ThreadpoolWithLanesDef::
    begin_threadpoolLane ()
    {
      return threadpoolLane_.begin ();
    }

    ThreadpoolWithLanesDef::threadpoolLane_iterator ThreadpoolWithLanesDef::
    end_threadpoolLane ()
    {
      return threadpoolLane_.end ();
    }

    ThreadpoolWithLanesDef::threadpoolLane_const_iterator ThreadpoolWithLanesDef::
    begin_threadpoolLane () const
    {
      return threadpoolLane_.begin ();
    }

    ThreadpoolWithLanesDef::threadpoolLane_const_iterator ThreadpoolWithLanesDef::
    end_threadpoolLane () const
    {
      return threadpoolLane_.end ();
    }

    void ThreadpoolWithLanesDef::
    add_threadpoolLane (::CIAO::Config_Handlers::ThreadpoolLaneDef const& e)
    {
      threadpoolLane_.push_back (e);
    }

    size_t ThreadpoolWithLanesDef::
    count_threadpoolLane(void) const
    {
      return threadpoolLane_.size ();
    }

    // ThreadpoolWithLanesDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolWithLanesDef::
    stacksize () const
    {
      return *stacksize_;
    }

    void ThreadpoolWithLanesDef::
    stacksize (::XMLSchema::unsignedLong const& e)
    {
      *stacksize_ = e;
    }

    // ThreadpoolWithLanesDef
    // 
    ::XMLSchema::boolean const& ThreadpoolWithLanesDef::
    allow_borrowing () const
    {
      return *allow_borrowing_;
    }

    void ThreadpoolWithLanesDef::
    allow_borrowing (::XMLSchema::boolean const& e)
    {
      *allow_borrowing_ = e;
    }

    // ThreadpoolWithLanesDef
    // 
    ::XMLSchema::boolean const& ThreadpoolWithLanesDef::
    allow_request_buffering () const
    {
      return *allow_request_buffering_;
    }

    void ThreadpoolWithLanesDef::
    allow_request_buffering (::XMLSchema::boolean const& e)
    {
      *allow_request_buffering_ = e;
    }

    // ThreadpoolWithLanesDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolWithLanesDef::
    max_buffered_requests () const
    {
      return *max_buffered_requests_;
    }

    void ThreadpoolWithLanesDef::
    max_buffered_requests (::XMLSchema::unsignedLong const& e)
    {
      *max_buffered_requests_ = e;
    }

    // ThreadpoolWithLanesDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolWithLanesDef::
    max_request_buffered_size () const
    {
      return *max_request_buffered_size_;
    }

    void ThreadpoolWithLanesDef::
    max_request_buffered_size (::XMLSchema::unsignedLong const& e)
    {
      *max_request_buffered_size_ = e;
    }

    // ThreadpoolWithLanesDef
    // 
    bool ThreadpoolWithLanesDef::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& ThreadpoolWithLanesDef::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& ThreadpoolWithLanesDef::
    id ()
    {
      return *id_;
    }

    void ThreadpoolWithLanesDef::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // ThreadpoolLaneDef
    // 

    ThreadpoolLaneDef::
    ThreadpoolLaneDef (::XMLSchema::unsignedLong const& static_threads__,
                       ::XMLSchema::unsignedLong const& dynamic_threads__,
                       ::CIAO::Config_Handlers::Priority const& priority__)
    : 
    ::XSCRT::Type (), 
    static_threads_ (new ::XMLSchema::unsignedLong (static_threads__)),
    dynamic_threads_ (new ::XMLSchema::unsignedLong (dynamic_threads__)),
    priority_ (new ::CIAO::Config_Handlers::Priority (priority__)),
    regulator__ ()
    {
      static_threads_->container (this);
      dynamic_threads_->container (this);
      priority_->container (this);
    }

    ThreadpoolLaneDef::
    ThreadpoolLaneDef (::CIAO::Config_Handlers::ThreadpoolLaneDef const& s)
    :
    ::XSCRT::Type (),
    static_threads_ (new ::XMLSchema::unsignedLong (*s.static_threads_)),
    dynamic_threads_ (new ::XMLSchema::unsignedLong (*s.dynamic_threads_)),
    priority_ (new ::CIAO::Config_Handlers::Priority (*s.priority_)),
    regulator__ ()
    {
      static_threads_->container (this);
      dynamic_threads_->container (this);
      priority_->container (this);
    }

    ::CIAO::Config_Handlers::ThreadpoolLaneDef& ThreadpoolLaneDef::
    operator= (::CIAO::Config_Handlers::ThreadpoolLaneDef const& s)
    {
      static_threads (s.static_threads ());

      dynamic_threads (s.dynamic_threads ());

      priority (s.priority ());

      return *this;
    }


    // ThreadpoolLaneDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolLaneDef::
    static_threads () const
    {
      return *static_threads_;
    }

    void ThreadpoolLaneDef::
    static_threads (::XMLSchema::unsignedLong const& e)
    {
      *static_threads_ = e;
    }

    // ThreadpoolLaneDef
    // 
    ::XMLSchema::unsignedLong const& ThreadpoolLaneDef::
    dynamic_threads () const
    {
      return *dynamic_threads_;
    }

    void ThreadpoolLaneDef::
    dynamic_threads (::XMLSchema::unsignedLong const& e)
    {
      *dynamic_threads_ = e;
    }

    // ThreadpoolLaneDef
    // 
    ::CIAO::Config_Handlers::Priority const& ThreadpoolLaneDef::
    priority () const
    {
      return *priority_;
    }

    void ThreadpoolLaneDef::
    priority (::CIAO::Config_Handlers::Priority const& e)
    {
      *priority_ = e;
    }


    // ConnectionBandsDef
    // 

    ConnectionBandsDef::
    ConnectionBandsDef ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    ConnectionBandsDef::
    ConnectionBandsDef (::CIAO::Config_Handlers::ConnectionBandsDef const& s)
    :
    ::XSCRT::Type (),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      {
        for (band_const_iterator i (s.band_.begin ());i != s.band_.end ();++i) add_band (*i);
      }

      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::ConnectionBandsDef& ConnectionBandsDef::
    operator= (::CIAO::Config_Handlers::ConnectionBandsDef const& s)
    {
      band_.clear ();
      {
        for (band_const_iterator i (s.band_.begin ());i != s.band_.end ();++i) add_band (*i);
      }

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // ConnectionBandsDef
    // 
    ConnectionBandsDef::band_iterator ConnectionBandsDef::
    begin_band ()
    {
      return band_.begin ();
    }

    ConnectionBandsDef::band_iterator ConnectionBandsDef::
    end_band ()
    {
      return band_.end ();
    }

    ConnectionBandsDef::band_const_iterator ConnectionBandsDef::
    begin_band () const
    {
      return band_.begin ();
    }

    ConnectionBandsDef::band_const_iterator ConnectionBandsDef::
    end_band () const
    {
      return band_.end ();
    }

    void ConnectionBandsDef::
    add_band (::CIAO::Config_Handlers::PriorityBandDef const& e)
    {
      band_.push_back (e);
    }

    size_t ConnectionBandsDef::
    count_band(void) const
    {
      return band_.size ();
    }

    // ConnectionBandsDef
    // 
    bool ConnectionBandsDef::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& ConnectionBandsDef::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& ConnectionBandsDef::
    id ()
    {
      return *id_;
    }

    void ConnectionBandsDef::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // PriorityBandDef
    // 

    PriorityBandDef::
    PriorityBandDef (::XMLSchema::int_ const& low__,
                     ::XMLSchema::int_ const& high__)
    : 
    ::XSCRT::Type (), 
    low_ (new ::XMLSchema::int_ (low__)),
    high_ (new ::XMLSchema::int_ (high__)),
    regulator__ ()
    {
      low_->container (this);
      high_->container (this);
    }

    PriorityBandDef::
    PriorityBandDef (::CIAO::Config_Handlers::PriorityBandDef const& s)
    :
    ::XSCRT::Type (),
    low_ (new ::XMLSchema::int_ (*s.low_)),
    high_ (new ::XMLSchema::int_ (*s.high_)),
    regulator__ ()
    {
      low_->container (this);
      high_->container (this);
    }

    ::CIAO::Config_Handlers::PriorityBandDef& PriorityBandDef::
    operator= (::CIAO::Config_Handlers::PriorityBandDef const& s)
    {
      low (s.low ());

      high (s.high ());

      return *this;
    }


    // PriorityBandDef
    // 
    ::XMLSchema::int_ const& PriorityBandDef::
    low () const
    {
      return *low_;
    }

    void PriorityBandDef::
    low (::XMLSchema::int_ const& e)
    {
      *low_ = e;
    }

    // PriorityBandDef
    // 
    ::XMLSchema::int_ const& PriorityBandDef::
    high () const
    {
      return *high_;
    }

    void PriorityBandDef::
    high (::XMLSchema::int_ const& e)
    {
      *high_ = e;
    }


    // PolicySet
    // 

    PolicySet::
    PolicySet ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    PolicySet::
    PolicySet (::CIAO::Config_Handlers::PolicySet const& s)
    :
    ::XSCRT::Type (),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      {
        for (priorityModel_const_iterator i (s.priorityModel_.begin ());i != s.priorityModel_.end ();++i) add_priorityModel (*i);
      }

      {
        for (nwpriorityModel_const_iterator i (s.nwpriorityModel_.begin ());i != s.nwpriorityModel_.end ();++i) add_nwpriorityModel (*i);
      }

      {
        for (cnwpriorityModel_const_iterator i (s.cnwpriorityModel_.begin ());i != s.cnwpriorityModel_.end ();++i) add_cnwpriorityModel (*i);
      }

      {
        for (threadpool_const_iterator i (s.threadpool_.begin ());i != s.threadpool_.end ();++i) add_threadpool (*i);
      }

      {
        for (priorityBandedConnection_const_iterator i (s.priorityBandedConnection_.begin ());i != s.priorityBandedConnection_.end ();++i) add_priorityBandedConnection (*i);
      }

      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::PolicySet& PolicySet::
    operator= (::CIAO::Config_Handlers::PolicySet const& s)
    {
      priorityModel_.clear ();
      {
        for (priorityModel_const_iterator i (s.priorityModel_.begin ());i != s.priorityModel_.end ();++i) add_priorityModel (*i);
      }

      nwpriorityModel_.clear ();
      {
        for (nwpriorityModel_const_iterator i (s.nwpriorityModel_.begin ());i != s.nwpriorityModel_.end ();++i) add_nwpriorityModel (*i);
      }

      cnwpriorityModel_.clear ();
      {
        for (cnwpriorityModel_const_iterator i (s.cnwpriorityModel_.begin ());i != s.cnwpriorityModel_.end ();++i) add_cnwpriorityModel (*i);
      }

      threadpool_.clear ();
      {
        for (threadpool_const_iterator i (s.threadpool_.begin ());i != s.threadpool_.end ();++i) add_threadpool (*i);
      }

      priorityBandedConnection_.clear ();
      {
        for (priorityBandedConnection_const_iterator i (s.priorityBandedConnection_.begin ());i != s.priorityBandedConnection_.end ();++i) add_priorityBandedConnection (*i);
      }

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // PolicySet
    // 
    PolicySet::priorityModel_iterator PolicySet::
    begin_priorityModel ()
    {
      return priorityModel_.begin ();
    }

    PolicySet::priorityModel_iterator PolicySet::
    end_priorityModel ()
    {
      return priorityModel_.end ();
    }

    PolicySet::priorityModel_const_iterator PolicySet::
    begin_priorityModel () const
    {
      return priorityModel_.begin ();
    }

    PolicySet::priorityModel_const_iterator PolicySet::
    end_priorityModel () const
    {
      return priorityModel_.end ();
    }

    void PolicySet::
    add_priorityModel (::CIAO::Config_Handlers::PriorityModelPolicyDef const& e)
    {
      priorityModel_.push_back (e);
    }

    size_t PolicySet::
    count_priorityModel(void) const
    {
      return priorityModel_.size ();
    }

    // PolicySet
    // 
    PolicySet::nwpriorityModel_iterator PolicySet::
    begin_nwpriorityModel ()
    {
      return nwpriorityModel_.begin ();
    }

    PolicySet::nwpriorityModel_iterator PolicySet::
    end_nwpriorityModel ()
    {
      return nwpriorityModel_.end ();
    }

    PolicySet::nwpriorityModel_const_iterator PolicySet::
    begin_nwpriorityModel () const
    {
      return nwpriorityModel_.begin ();
    }

    PolicySet::nwpriorityModel_const_iterator PolicySet::
    end_nwpriorityModel () const
    {
      return nwpriorityModel_.end ();
    }

    void PolicySet::
    add_nwpriorityModel (::CIAO::Config_Handlers::NWPriorityModelPolicyDef const& e)
    {
      nwpriorityModel_.push_back (e);
    }

    size_t PolicySet::
    count_nwpriorityModel(void) const
    {
      return nwpriorityModel_.size ();
    }

    // PolicySet
    // 
    PolicySet::cnwpriorityModel_iterator PolicySet::
    begin_cnwpriorityModel ()
    {
      return cnwpriorityModel_.begin ();
    }

    PolicySet::cnwpriorityModel_iterator PolicySet::
    end_cnwpriorityModel ()
    {
      return cnwpriorityModel_.end ();
    }

    PolicySet::cnwpriorityModel_const_iterator PolicySet::
    begin_cnwpriorityModel () const
    {
      return cnwpriorityModel_.begin ();
    }

    PolicySet::cnwpriorityModel_const_iterator PolicySet::
    end_cnwpriorityModel () const
    {
      return cnwpriorityModel_.end ();
    }

    void PolicySet::
    add_cnwpriorityModel (::CIAO::Config_Handlers::CNWPriorityModelPolicyDef const& e)
    {
      cnwpriorityModel_.push_back (e);
    }

    size_t PolicySet::
    count_cnwpriorityModel(void) const
    {
      return cnwpriorityModel_.size ();
    }

    // PolicySet
    // 
    PolicySet::threadpool_iterator PolicySet::
    begin_threadpool ()
    {
      return threadpool_.begin ();
    }

    PolicySet::threadpool_iterator PolicySet::
    end_threadpool ()
    {
      return threadpool_.end ();
    }

    PolicySet::threadpool_const_iterator PolicySet::
    begin_threadpool () const
    {
      return threadpool_.begin ();
    }

    PolicySet::threadpool_const_iterator PolicySet::
    end_threadpool () const
    {
      return threadpool_.end ();
    }

    void PolicySet::
    add_threadpool (::XMLSchema::IDREF< ACE_TCHAR > const& e)
    {
      threadpool_.push_back (e);
    }

    size_t PolicySet::
    count_threadpool(void) const
    {
      return threadpool_.size ();
    }

    // PolicySet
    // 
    PolicySet::priorityBandedConnection_iterator PolicySet::
    begin_priorityBandedConnection ()
    {
      return priorityBandedConnection_.begin ();
    }

    PolicySet::priorityBandedConnection_iterator PolicySet::
    end_priorityBandedConnection ()
    {
      return priorityBandedConnection_.end ();
    }

    PolicySet::priorityBandedConnection_const_iterator PolicySet::
    begin_priorityBandedConnection () const
    {
      return priorityBandedConnection_.begin ();
    }

    PolicySet::priorityBandedConnection_const_iterator PolicySet::
    end_priorityBandedConnection () const
    {
      return priorityBandedConnection_.end ();
    }

    void PolicySet::
    add_priorityBandedConnection (::XMLSchema::IDREF< ACE_TCHAR > const& e)
    {
      priorityBandedConnection_.push_back (e);
    }

    size_t PolicySet::
    count_priorityBandedConnection(void) const
    {
      return priorityBandedConnection_.size ();
    }

    // PolicySet
    // 
    bool PolicySet::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& PolicySet::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& PolicySet::
    id ()
    {
      return *id_;
    }

    void PolicySet::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // PriorityModel
    // 

    PriorityModel::Value PriorityModel::
    integral () const
    {
      return v_;
    }

    bool
    operator== (::CIAO::Config_Handlers::PriorityModel const& a, ::CIAO::Config_Handlers::PriorityModel const& b)
    {
      return a.v_ == b.v_;
    }

    bool
    operator!= (::CIAO::Config_Handlers::PriorityModel const& a, ::CIAO::Config_Handlers::PriorityModel const& b)
    {
      return a.v_ != b.v_;
    }

    PriorityModel::
    PriorityModel (PriorityModel::Value v)
    : v_ (v)
    {
    }

    // NWPriorityModel
    // 

    NWPriorityModel::Value NWPriorityModel::
    integral () const
    {
      return v_;
    }

    bool
    operator== (::CIAO::Config_Handlers::NWPriorityModel const& a, ::CIAO::Config_Handlers::NWPriorityModel const& b)
    {
      return a.v_ == b.v_;
    }

    bool
    operator!= (::CIAO::Config_Handlers::NWPriorityModel const& a, ::CIAO::Config_Handlers::NWPriorityModel const& b)
    {
      return a.v_ != b.v_;
    }

    NWPriorityModel::
    NWPriorityModel (NWPriorityModel::Value v)
    : v_ (v)
    {
    }

    // PriorityModelPolicyDef
    // 

    PriorityModelPolicyDef::
    PriorityModelPolicyDef (::CIAO::Config_Handlers::PriorityModel const& priority_model__)
    : 
    ::XSCRT::Type (), 
    priority_model_ (new ::CIAO::Config_Handlers::PriorityModel (priority_model__)),
    regulator__ ()
    {
      priority_model_->container (this);
    }

    PriorityModelPolicyDef::
    PriorityModelPolicyDef (::CIAO::Config_Handlers::PriorityModelPolicyDef const& s)
    :
    ::XSCRT::Type (),
    priority_model_ (new ::CIAO::Config_Handlers::PriorityModel (*s.priority_model_)),
    server_priority_ (s.server_priority_.get () ? new ::CIAO::Config_Handlers::Priority (*s.server_priority_) : 0),
    regulator__ ()
    {
      priority_model_->container (this);
      if (server_priority_.get ()) server_priority_->container (this);
    }

    ::CIAO::Config_Handlers::PriorityModelPolicyDef& PriorityModelPolicyDef::
    operator= (::CIAO::Config_Handlers::PriorityModelPolicyDef const& s)
    {
      priority_model (s.priority_model ());

      if (s.server_priority_.get ()) server_priority (*(s.server_priority_));
      else server_priority_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Priority > (0);

      return *this;
    }


    // PriorityModelPolicyDef
    // 
    ::CIAO::Config_Handlers::PriorityModel const& PriorityModelPolicyDef::
    priority_model () const
    {
      return *priority_model_;
    }

    void PriorityModelPolicyDef::
    priority_model (::CIAO::Config_Handlers::PriorityModel const& e)
    {
      *priority_model_ = e;
    }

    // PriorityModelPolicyDef
    // 
    bool PriorityModelPolicyDef::
    server_priority_p () const
    {
      return server_priority_.get () != 0;
    }

    ::CIAO::Config_Handlers::Priority const& PriorityModelPolicyDef::
    server_priority () const
    {
      return *server_priority_;
    }

    ::CIAO::Config_Handlers::Priority& PriorityModelPolicyDef::
    server_priority ()
    {
      return *server_priority_;
    }

    void PriorityModelPolicyDef::
    server_priority (::CIAO::Config_Handlers::Priority const& e)
    {
      if (server_priority_.get ())
      {
        *server_priority_ = e;
      }

      else
      {
        server_priority_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Priority > (new ::CIAO::Config_Handlers::Priority (e));
        server_priority_->container (this);
      }
    }


    // NWPriorityModelPolicyDef
    // 

    NWPriorityModelPolicyDef::
    NWPriorityModelPolicyDef (::CIAO::Config_Handlers::NWPriorityModel const& nw_priority_model__,
                              ::XMLSchema::long_ const& request_dscp__,
                              ::XMLSchema::long_ const& reply_dscp__)
    : 
    ::XSCRT::Type (), 
    nw_priority_model_ (new ::CIAO::Config_Handlers::NWPriorityModel (nw_priority_model__)),
    request_dscp_ (new ::XMLSchema::long_ (request_dscp__)),
    reply_dscp_ (new ::XMLSchema::long_ (reply_dscp__)),
    regulator__ ()
    {
      nw_priority_model_->container (this);
      request_dscp_->container (this);
      reply_dscp_->container (this);
    }

    NWPriorityModelPolicyDef::
    NWPriorityModelPolicyDef (::CIAO::Config_Handlers::NWPriorityModelPolicyDef const& s)
    :
    ::XSCRT::Type (),
    nw_priority_model_ (new ::CIAO::Config_Handlers::NWPriorityModel (*s.nw_priority_model_)),
    request_dscp_ (new ::XMLSchema::long_ (*s.request_dscp_)),
    reply_dscp_ (new ::XMLSchema::long_ (*s.reply_dscp_)),
    regulator__ ()
    {
      nw_priority_model_->container (this);
      request_dscp_->container (this);
      reply_dscp_->container (this);
    }

    ::CIAO::Config_Handlers::NWPriorityModelPolicyDef& NWPriorityModelPolicyDef::
    operator= (::CIAO::Config_Handlers::NWPriorityModelPolicyDef const& s)
    {
      nw_priority_model (s.nw_priority_model ());

      request_dscp (s.request_dscp ());

      reply_dscp (s.reply_dscp ());

      return *this;
    }


    // NWPriorityModelPolicyDef
    // 
    ::CIAO::Config_Handlers::NWPriorityModel const& NWPriorityModelPolicyDef::
    nw_priority_model () const
    {
      return *nw_priority_model_;
    }

    void NWPriorityModelPolicyDef::
    nw_priority_model (::CIAO::Config_Handlers::NWPriorityModel const& e)
    {
      *nw_priority_model_ = e;
    }

    // NWPriorityModelPolicyDef
    // 
    ::XMLSchema::long_ const& NWPriorityModelPolicyDef::
    request_dscp () const
    {
      return *request_dscp_;
    }

    void NWPriorityModelPolicyDef::
    request_dscp (::XMLSchema::long_ const& e)
    {
      *request_dscp_ = e;
    }

    // NWPriorityModelPolicyDef
    // 
    ::XMLSchema::long_ const& NWPriorityModelPolicyDef::
    reply_dscp () const
    {
      return *reply_dscp_;
    }

    void NWPriorityModelPolicyDef::
    reply_dscp (::XMLSchema::long_ const& e)
    {
      *reply_dscp_ = e;
    }


    // CNWPriorityModelPolicyDef
    // 

    CNWPriorityModelPolicyDef::
    CNWPriorityModelPolicyDef (::XMLSchema::long_ const& request_dscp__,
                               ::XMLSchema::long_ const& reply_dscp__)
    : 
    ::XSCRT::Type (), 
    request_dscp_ (new ::XMLSchema::long_ (request_dscp__)),
    reply_dscp_ (new ::XMLSchema::long_ (reply_dscp__)),
    regulator__ ()
    {
      request_dscp_->container (this);
      reply_dscp_->container (this);
    }

    CNWPriorityModelPolicyDef::
    CNWPriorityModelPolicyDef (::CIAO::Config_Handlers::CNWPriorityModelPolicyDef const& s)
    :
    ::XSCRT::Type (),
    request_dscp_ (new ::XMLSchema::long_ (*s.request_dscp_)),
    reply_dscp_ (new ::XMLSchema::long_ (*s.reply_dscp_)),
    regulator__ ()
    {
      request_dscp_->container (this);
      reply_dscp_->container (this);
    }

    ::CIAO::Config_Handlers::CNWPriorityModelPolicyDef& CNWPriorityModelPolicyDef::
    operator= (::CIAO::Config_Handlers::CNWPriorityModelPolicyDef const& s)
    {
      request_dscp (s.request_dscp ());

      reply_dscp (s.reply_dscp ());

      return *this;
    }


    // CNWPriorityModelPolicyDef
    // 
    ::XMLSchema::long_ const& CNWPriorityModelPolicyDef::
    request_dscp () const
    {
      return *request_dscp_;
    }

    void CNWPriorityModelPolicyDef::
    request_dscp (::XMLSchema::long_ const& e)
    {
      *request_dscp_ = e;
    }

    // CNWPriorityModelPolicyDef
    // 
    ::XMLSchema::long_ const& CNWPriorityModelPolicyDef::
    reply_dscp () const
    {
      return *reply_dscp_;
    }

    void CNWPriorityModelPolicyDef::
    reply_dscp (::XMLSchema::long_ const& e)
    {
      *reply_dscp_ = e;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // ServerResourcesDef
    //

    ServerResourcesDef::
    ServerResourcesDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "cmdline")
        {
          ::CIAO::Config_Handlers::ServerCmdlineOptions t (e);
          cmdline (t);
        }

        else if (n == "svcconf")
        {
          ::CIAO::Config_Handlers::ACESvcConf t (e);
          svcconf (t);
        }

        else if (n == "orbConfigs")
        {
          orbConfigs_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ORBConfigs > (new ::CIAO::Config_Handlers::ORBConfigs (e));
          orbConfigs_->container (this);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // ServerCmdlineOptions
    //

    ServerCmdlineOptions::
    ServerCmdlineOptions (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "arg")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_arg (t);
        }

        else 
        {
        }
      }
    }

    // ACESvcConf
    //

    ACESvcConf::
    ACESvcConf (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "uri")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          uri (t);
        }

        else 
        {
        }
      }
    }

    // ORBConfigs
    //

    ORBConfigs::
    ORBConfigs (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "resources")
        {
          ::CIAO::Config_Handlers::ORBResources t (e);
          resources (t);
        }

        else if (n == "policySet")
        {
          ::CIAO::Config_Handlers::PolicySet t (e);
          add_policySet (t);
        }

        else 
        {
        }
      }
    }

    // ORBResources
    //

    ORBResources::
    ORBResources (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "threadpool")
        {
          ::CIAO::Config_Handlers::ThreadpoolDef t (e);
          add_threadpool (t);
        }

        else if (n == "threadpoolWithLanes")
        {
          ::CIAO::Config_Handlers::ThreadpoolWithLanesDef t (e);
          add_threadpoolWithLanes (t);
        }

        else if (n == "connectionBands")
        {
          ::CIAO::Config_Handlers::ConnectionBandsDef t (e);
          add_connectionBands (t);
        }

        else 
        {
        }
      }
    }

    // Priority
    //

    Priority::
    Priority (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {
    }

    Priority::
    Priority (::XSCRT::XML::Attribute< ACE_TCHAR > const& a)
    :
    Base__ (a),
    regulator__ ()
    {
    }

    // ThreadpoolDef
    //

    ThreadpoolDef::
    ThreadpoolDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "stacksize")
        {
          stacksize_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          stacksize_->container (this);
        }

        else if (n == "static_threads")
        {
          static_threads_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          static_threads_->container (this);
        }

        else if (n == "dynamic_threads")
        {
          dynamic_threads_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          dynamic_threads_->container (this);
        }

        else if (n == "default_priority")
        {
          default_priority_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Priority > (new ::CIAO::Config_Handlers::Priority (e));
          default_priority_->container (this);
        }

        else if (n == "allow_request_buffering")
        {
          allow_request_buffering_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          allow_request_buffering_->container (this);
        }

        else if (n == "max_buffered_requests")
        {
          max_buffered_requests_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          max_buffered_requests_->container (this);
        }

        else if (n == "max_request_buffered_size")
        {
          max_request_buffered_size_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          max_request_buffered_size_->container (this);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // ThreadpoolWithLanesDef
    //

    ThreadpoolWithLanesDef::
    ThreadpoolWithLanesDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "threadpoolLane")
        {
          ::CIAO::Config_Handlers::ThreadpoolLaneDef t (e);
          add_threadpoolLane (t);
        }

        else if (n == "stacksize")
        {
          stacksize_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          stacksize_->container (this);
        }

        else if (n == "allow_borrowing")
        {
          allow_borrowing_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          allow_borrowing_->container (this);
        }

        else if (n == "allow_request_buffering")
        {
          allow_request_buffering_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          allow_request_buffering_->container (this);
        }

        else if (n == "max_buffered_requests")
        {
          max_buffered_requests_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          max_buffered_requests_->container (this);
        }

        else if (n == "max_request_buffered_size")
        {
          max_request_buffered_size_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          max_request_buffered_size_->container (this);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // ThreadpoolLaneDef
    //

    ThreadpoolLaneDef::
    ThreadpoolLaneDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "static_threads")
        {
          static_threads_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          static_threads_->container (this);
        }

        else if (n == "dynamic_threads")
        {
          dynamic_threads_ = ::std::auto_ptr< ::XMLSchema::unsignedLong > (new ::XMLSchema::unsignedLong (e));
          dynamic_threads_->container (this);
        }

        else if (n == "priority")
        {
          priority_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Priority > (new ::CIAO::Config_Handlers::Priority (e));
          priority_->container (this);
        }

        else 
        {
        }
      }
    }

    // ConnectionBandsDef
    //

    ConnectionBandsDef::
    ConnectionBandsDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "band")
        {
          ::CIAO::Config_Handlers::PriorityBandDef t (e);
          add_band (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // PriorityBandDef
    //

    PriorityBandDef::
    PriorityBandDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "low")
        {
          low_ = ::std::auto_ptr< ::XMLSchema::int_ > (new ::XMLSchema::int_ (e));
          low_->container (this);
        }

        else if (n == "high")
        {
          high_ = ::std::auto_ptr< ::XMLSchema::int_ > (new ::XMLSchema::int_ (e));
          high_->container (this);
        }

        else 
        {
        }
      }
    }

    // PolicySet
    //

    PolicySet::
    PolicySet (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "priorityModel")
        {
          ::CIAO::Config_Handlers::PriorityModelPolicyDef t (e);
          add_priorityModel (t);
        }

        else if (n == "nwpriorityModel")
        {
          ::CIAO::Config_Handlers::NWPriorityModelPolicyDef t (e);
          add_nwpriorityModel (t);
        }

        else if (n == "cnwpriorityModel")
        {
          ::CIAO::Config_Handlers::CNWPriorityModelPolicyDef t (e);
          add_cnwpriorityModel (t);
        }

        else if (n == "threadpool")
        {
          ::XMLSchema::IDREF< ACE_TCHAR > t (e);
          add_threadpool (t);
        }

        else if (n == "priorityBandedConnection")
        {
          ::XMLSchema::IDREF< ACE_TCHAR > t (e);
          add_priorityBandedConnection (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // PriorityModel
    //

    PriorityModel::
    PriorityModel (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    : ::XSCRT::Type (e)
    {
      ::std::basic_string< ACE_TCHAR > v (e.value ());

      if (v == "SERVER_DECLARED") v_ = SERVER_DECLARED_l;
      else if (v == "CLIENT_PROPAGATED") v_ = CLIENT_PROPAGATED_l;
      else 
      {
      }
    }

    PriorityModel::
    PriorityModel (::XSCRT::XML::Attribute< ACE_TCHAR > const& a)
    : ::XSCRT::Type (a)
    {
      ::std::basic_string< ACE_TCHAR > v (a.value ());

      if (v == "SERVER_DECLARED") v_ = SERVER_DECLARED_l;
      else if (v == "CLIENT_PROPAGATED") v_ = CLIENT_PROPAGATED_l;
      else 
      {
      }
    }

    PriorityModel const PriorityModel::SERVER_DECLARED (PriorityModel::SERVER_DECLARED_l);
    PriorityModel const PriorityModel::CLIENT_PROPAGATED (PriorityModel::CLIENT_PROPAGATED_l);

    // NWPriorityModel
    //

    NWPriorityModel::
    NWPriorityModel (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    : ::XSCRT::Type (e)
    {
      ::std::basic_string< ACE_TCHAR > v (e.value ());

      if (v == "SERVER_DECLARED_NWPRIORITY") v_ = SERVER_DECLARED_NWPRIORITY_l;
      else if (v == "CLIENT_PROPAGATED_NWPRIORITY") v_ = CLIENT_PROPAGATED_NWPRIORITY_l;
      else 
      {
      }
    }

    NWPriorityModel::
    NWPriorityModel (::XSCRT::XML::Attribute< ACE_TCHAR > const& a)
    : ::XSCRT::Type (a)
    {
      ::std::basic_string< ACE_TCHAR > v (a.value ());

      if (v == "SERVER_DECLARED_NWPRIORITY") v_ = SERVER_DECLARED_NWPRIORITY_l;
      else if (v == "CLIENT_PROPAGATED_NWPRIORITY") v_ = CLIENT_PROPAGATED_NWPRIORITY_l;
      else 
      {
      }
    }

    NWPriorityModel const NWPriorityModel::SERVER_DECLARED_NWPRIORITY (NWPriorityModel::SERVER_DECLARED_NWPRIORITY_l);
    NWPriorityModel const NWPriorityModel::CLIENT_PROPAGATED_NWPRIORITY (NWPriorityModel::CLIENT_PROPAGATED_NWPRIORITY_l);

    // PriorityModelPolicyDef
    //

    PriorityModelPolicyDef::
    PriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "priority_model")
        {
          priority_model_ = ::std::auto_ptr< ::CIAO::Config_Handlers::PriorityModel > (new ::CIAO::Config_Handlers::PriorityModel (e));
          priority_model_->container (this);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "server_priority")
        {
          ::CIAO::Config_Handlers::Priority t (a);
          server_priority (t);
        }

        else 
        {
        }
      }
    }

    // NWPriorityModelPolicyDef
    //

    NWPriorityModelPolicyDef::
    NWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "nw_priority_model")
        {
          nw_priority_model_ = ::std::auto_ptr< ::CIAO::Config_Handlers::NWPriorityModel > (new ::CIAO::Config_Handlers::NWPriorityModel (e));
          nw_priority_model_->container (this);
        }

        else if (n == "request_dscp")
        {
          request_dscp_ = ::std::auto_ptr< ::XMLSchema::long_ > (new ::XMLSchema::long_ (e));
          request_dscp_->container (this);
        }

        else if (n == "reply_dscp")
        {
          reply_dscp_ = ::std::auto_ptr< ::XMLSchema::long_ > (new ::XMLSchema::long_ (e));
          reply_dscp_->container (this);
        }

        else 
        {
        }
      }
    }

    // CNWPriorityModelPolicyDef
    //

    CNWPriorityModelPolicyDef::
    CNWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "request_dscp")
        {
          request_dscp_ = ::std::auto_ptr< ::XMLSchema::long_ > (new ::XMLSchema::long_ (e));
          request_dscp_->container (this);
        }

        else if (n == "reply_dscp")
        {
          reply_dscp_ = ::std::auto_ptr< ::XMLSchema::long_ > (new ::XMLSchema::long_ (e));
          reply_dscp_->container (this);
        }

        else 
        {
        }
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    ::CIAO::Config_Handlers::ServerResourcesDef
    ServerResources (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
      if (e.name () == "ServerResources")
      {
        ::CIAO::Config_Handlers::ServerResourcesDef r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }
  }
}

#include "XMLSchema/TypeInfo.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < ACE_TCHAR > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct ServerResourcesDefTypeInfoInitializer
      {
        ServerResourcesDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ServerResourcesDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ServerResourcesDefTypeInfoInitializer ServerResourcesDefTypeInfoInitializer_;

      struct ServerCmdlineOptionsTypeInfoInitializer
      {
        ServerCmdlineOptionsTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ServerCmdlineOptions));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ServerCmdlineOptionsTypeInfoInitializer ServerCmdlineOptionsTypeInfoInitializer_;

      struct ACESvcConfTypeInfoInitializer
      {
        ACESvcConfTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ACESvcConf));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ACESvcConfTypeInfoInitializer ACESvcConfTypeInfoInitializer_;

      struct ORBConfigsTypeInfoInitializer
      {
        ORBConfigsTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ORBConfigs));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ORBConfigsTypeInfoInitializer ORBConfigsTypeInfoInitializer_;

      struct ORBResourcesTypeInfoInitializer
      {
        ORBResourcesTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ORBResources));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ORBResourcesTypeInfoInitializer ORBResourcesTypeInfoInitializer_;

      struct PriorityTypeInfoInitializer
      {
        PriorityTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (Priority));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XMLSchema::int_));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PriorityTypeInfoInitializer PriorityTypeInfoInitializer_;

      struct ThreadpoolDefTypeInfoInitializer
      {
        ThreadpoolDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ThreadpoolDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ThreadpoolDefTypeInfoInitializer ThreadpoolDefTypeInfoInitializer_;

      struct ThreadpoolWithLanesDefTypeInfoInitializer
      {
        ThreadpoolWithLanesDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ThreadpoolWithLanesDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ThreadpoolWithLanesDefTypeInfoInitializer ThreadpoolWithLanesDefTypeInfoInitializer_;

      struct ThreadpoolLaneDefTypeInfoInitializer
      {
        ThreadpoolLaneDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ThreadpoolLaneDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ThreadpoolLaneDefTypeInfoInitializer ThreadpoolLaneDefTypeInfoInitializer_;

      struct ConnectionBandsDefTypeInfoInitializer
      {
        ConnectionBandsDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ConnectionBandsDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ConnectionBandsDefTypeInfoInitializer ConnectionBandsDefTypeInfoInitializer_;

      struct PriorityBandDefTypeInfoInitializer
      {
        PriorityBandDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (PriorityBandDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PriorityBandDefTypeInfoInitializer PriorityBandDefTypeInfoInitializer_;

      struct PolicySetTypeInfoInitializer
      {
        PolicySetTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (PolicySet));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PolicySetTypeInfoInitializer PolicySetTypeInfoInitializer_;

      struct PriorityModelTypeInfoInitializer
      {
        PriorityModelTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (PriorityModel));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));

          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PriorityModelTypeInfoInitializer PriorityModelTypeInfoInitializer_;

      struct NWPriorityModelTypeInfoInitializer
      {
        NWPriorityModelTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (NWPriorityModel));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));

          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      NWPriorityModelTypeInfoInitializer NWPriorityModelTypeInfoInitializer_;

      struct PriorityModelPolicyDefTypeInfoInitializer
      {
        PriorityModelPolicyDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (PriorityModelPolicyDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PriorityModelPolicyDefTypeInfoInitializer PriorityModelPolicyDefTypeInfoInitializer_;

      struct NWPriorityModelPolicyDefTypeInfoInitializer
      {
        NWPriorityModelPolicyDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (NWPriorityModelPolicyDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      NWPriorityModelPolicyDefTypeInfoInitializer NWPriorityModelPolicyDefTypeInfoInitializer_;

      struct CNWPriorityModelPolicyDefTypeInfoInitializer
      {
        CNWPriorityModelPolicyDefTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (CNWPriorityModelPolicyDef));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      CNWPriorityModelPolicyDefTypeInfoInitializer CNWPriorityModelPolicyDefTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // ServerResourcesDef
      //
      //

      void ServerResourcesDef::
      traverse (Type& o)
      {
        pre (o);
        if (o.cmdline_p ()) cmdline (o);
        else cmdline_none (o);
        if (o.svcconf_p ()) svcconf (o);
        else svcconf_none (o);
        orbConfigs (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ServerResourcesDef::
      traverse (Type const& o)
      {
        pre (o);
        if (o.cmdline_p ()) cmdline (o);
        else cmdline_none (o);
        if (o.svcconf_p ()) svcconf (o);
        else svcconf_none (o);
        orbConfigs (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ServerResourcesDef::
      pre (Type&)
      {
      }

      void ServerResourcesDef::
      pre (Type const&)
      {
      }

      void ServerResourcesDef::
      cmdline (Type& o)
      {
        dispatch (o.cmdline ());
      }

      void ServerResourcesDef::
      cmdline (Type const& o)
      {
        dispatch (o.cmdline ());
      }

      void ServerResourcesDef::
      cmdline_none (Type&)
      {
      }

      void ServerResourcesDef::
      cmdline_none (Type const&)
      {
      }

      void ServerResourcesDef::
      svcconf (Type& o)
      {
        dispatch (o.svcconf ());
      }

      void ServerResourcesDef::
      svcconf (Type const& o)
      {
        dispatch (o.svcconf ());
      }

      void ServerResourcesDef::
      svcconf_none (Type&)
      {
      }

      void ServerResourcesDef::
      svcconf_none (Type const&)
      {
      }

      void ServerResourcesDef::
      orbConfigs (Type& o)
      {
        dispatch (o.orbConfigs ());
      }

      void ServerResourcesDef::
      orbConfigs (Type const& o)
      {
        dispatch (o.orbConfigs ());
      }

      void ServerResourcesDef::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void ServerResourcesDef::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void ServerResourcesDef::
      id_none (Type&)
      {
      }

      void ServerResourcesDef::
      id_none (Type const&)
      {
      }

      void ServerResourcesDef::
      post (Type&)
      {
      }

      void ServerResourcesDef::
      post (Type const&)
      {
      }

      // ServerCmdlineOptions
      //
      //

      void ServerCmdlineOptions::
      traverse (Type& o)
      {
        pre (o);
        arg (o);
        post (o);
      }

      void ServerCmdlineOptions::
      traverse (Type const& o)
      {
        pre (o);
        arg (o);
        post (o);
      }

      void ServerCmdlineOptions::
      pre (Type&)
      {
      }

      void ServerCmdlineOptions::
      pre (Type const&)
      {
      }

      void ServerCmdlineOptions::
      arg (Type& o)
      {
        // VC6 anathema strikes again
        //
        ServerCmdlineOptions::Type::arg_iterator b (o.begin_arg()), e (o.end_arg());

        if (b != e)
        {
          arg_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) arg_next (o);
          }

          arg_post (o);
        }
      }

      void ServerCmdlineOptions::
      arg (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ServerCmdlineOptions::Type::arg_const_iterator b (o.begin_arg()), e (o.end_arg());

        if (b != e)
        {
          arg_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) arg_next (o);
          }

          arg_post (o);
        }
      }

      void ServerCmdlineOptions::
      arg_pre (Type&)
      {
      }

      void ServerCmdlineOptions::
      arg_pre (Type const&)
      {
      }

      void ServerCmdlineOptions::
      arg_next (Type&)
      {
      }

      void ServerCmdlineOptions::
      arg_next (Type const&)
      {
      }

      void ServerCmdlineOptions::
      arg_post (Type&)
      {
      }

      void ServerCmdlineOptions::
      arg_post (Type const&)
      {
      }

      void ServerCmdlineOptions::
      post (Type&)
      {
      }

      void ServerCmdlineOptions::
      post (Type const&)
      {
      }

      // ACESvcConf
      //
      //

      void ACESvcConf::
      traverse (Type& o)
      {
        pre (o);
        if (o.uri_p ()) uri (o);
        else uri_none (o);
        post (o);
      }

      void ACESvcConf::
      traverse (Type const& o)
      {
        pre (o);
        if (o.uri_p ()) uri (o);
        else uri_none (o);
        post (o);
      }

      void ACESvcConf::
      pre (Type&)
      {
      }

      void ACESvcConf::
      pre (Type const&)
      {
      }

      void ACESvcConf::
      uri (Type& o)
      {
        dispatch (o.uri ());
      }

      void ACESvcConf::
      uri (Type const& o)
      {
        dispatch (o.uri ());
      }

      void ACESvcConf::
      uri_none (Type&)
      {
      }

      void ACESvcConf::
      uri_none (Type const&)
      {
      }

      void ACESvcConf::
      post (Type&)
      {
      }

      void ACESvcConf::
      post (Type const&)
      {
      }

      // ORBConfigs
      //
      //

      void ORBConfigs::
      traverse (Type& o)
      {
        pre (o);
        if (o.resources_p ()) resources (o);
        else resources_none (o);
        policySet (o);
        post (o);
      }

      void ORBConfigs::
      traverse (Type const& o)
      {
        pre (o);
        if (o.resources_p ()) resources (o);
        else resources_none (o);
        policySet (o);
        post (o);
      }

      void ORBConfigs::
      pre (Type&)
      {
      }

      void ORBConfigs::
      pre (Type const&)
      {
      }

      void ORBConfigs::
      resources (Type& o)
      {
        dispatch (o.resources ());
      }

      void ORBConfigs::
      resources (Type const& o)
      {
        dispatch (o.resources ());
      }

      void ORBConfigs::
      resources_none (Type&)
      {
      }

      void ORBConfigs::
      resources_none (Type const&)
      {
      }

      void ORBConfigs::
      policySet (Type& o)
      {
        // VC6 anathema strikes again
        //
        ORBConfigs::Type::policySet_iterator b (o.begin_policySet()), e (o.end_policySet());

        if (b != e)
        {
          policySet_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) policySet_next (o);
          }

          policySet_post (o);
        }
      }

      void ORBConfigs::
      policySet (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ORBConfigs::Type::policySet_const_iterator b (o.begin_policySet()), e (o.end_policySet());

        if (b != e)
        {
          policySet_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) policySet_next (o);
          }

          policySet_post (o);
        }
      }

      void ORBConfigs::
      policySet_pre (Type&)
      {
      }

      void ORBConfigs::
      policySet_pre (Type const&)
      {
      }

      void ORBConfigs::
      policySet_next (Type&)
      {
      }

      void ORBConfigs::
      policySet_next (Type const&)
      {
      }

      void ORBConfigs::
      policySet_post (Type&)
      {
      }

      void ORBConfigs::
      policySet_post (Type const&)
      {
      }

      void ORBConfigs::
      post (Type&)
      {
      }

      void ORBConfigs::
      post (Type const&)
      {
      }

      // ORBResources
      //
      //

      void ORBResources::
      traverse (Type& o)
      {
        pre (o);
        threadpool (o);
        threadpoolWithLanes (o);
        connectionBands (o);
        post (o);
      }

      void ORBResources::
      traverse (Type const& o)
      {
        pre (o);
        threadpool (o);
        threadpoolWithLanes (o);
        connectionBands (o);
        post (o);
      }

      void ORBResources::
      pre (Type&)
      {
      }

      void ORBResources::
      pre (Type const&)
      {
      }

      void ORBResources::
      threadpool (Type& o)
      {
        // VC6 anathema strikes again
        //
        ORBResources::Type::threadpool_iterator b (o.begin_threadpool()), e (o.end_threadpool());

        if (b != e)
        {
          threadpool_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpool_next (o);
          }

          threadpool_post (o);
        }

        else threadpool_none (o);
      }

      void ORBResources::
      threadpool (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ORBResources::Type::threadpool_const_iterator b (o.begin_threadpool()), e (o.end_threadpool());

        if (b != e)
        {
          threadpool_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpool_next (o);
          }

          threadpool_post (o);
        }

        else threadpool_none (o);
      }

      void ORBResources::
      threadpool_pre (Type&)
      {
      }

      void ORBResources::
      threadpool_pre (Type const&)
      {
      }

      void ORBResources::
      threadpool_next (Type&)
      {
      }

      void ORBResources::
      threadpool_next (Type const&)
      {
      }

      void ORBResources::
      threadpool_post (Type&)
      {
      }

      void ORBResources::
      threadpool_post (Type const&)
      {
      }

      void ORBResources::
      threadpool_none (Type&)
      {
      }

      void ORBResources::
      threadpool_none (Type const&)
      {
      }

      void ORBResources::
      threadpoolWithLanes (Type& o)
      {
        // VC6 anathema strikes again
        //
        ORBResources::Type::threadpoolWithLanes_iterator b (o.begin_threadpoolWithLanes()), e (o.end_threadpoolWithLanes());

        if (b != e)
        {
          threadpoolWithLanes_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpoolWithLanes_next (o);
          }

          threadpoolWithLanes_post (o);
        }

        else threadpoolWithLanes_none (o);
      }

      void ORBResources::
      threadpoolWithLanes (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ORBResources::Type::threadpoolWithLanes_const_iterator b (o.begin_threadpoolWithLanes()), e (o.end_threadpoolWithLanes());

        if (b != e)
        {
          threadpoolWithLanes_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpoolWithLanes_next (o);
          }

          threadpoolWithLanes_post (o);
        }

        else threadpoolWithLanes_none (o);
      }

      void ORBResources::
      threadpoolWithLanes_pre (Type&)
      {
      }

      void ORBResources::
      threadpoolWithLanes_pre (Type const&)
      {
      }

      void ORBResources::
      threadpoolWithLanes_next (Type&)
      {
      }

      void ORBResources::
      threadpoolWithLanes_next (Type const&)
      {
      }

      void ORBResources::
      threadpoolWithLanes_post (Type&)
      {
      }

      void ORBResources::
      threadpoolWithLanes_post (Type const&)
      {
      }

      void ORBResources::
      threadpoolWithLanes_none (Type&)
      {
      }

      void ORBResources::
      threadpoolWithLanes_none (Type const&)
      {
      }

      void ORBResources::
      connectionBands (Type& o)
      {
        // VC6 anathema strikes again
        //
        ORBResources::Type::connectionBands_iterator b (o.begin_connectionBands()), e (o.end_connectionBands());

        if (b != e)
        {
          connectionBands_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) connectionBands_next (o);
          }

          connectionBands_post (o);
        }

        else connectionBands_none (o);
      }

      void ORBResources::
      connectionBands (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ORBResources::Type::connectionBands_const_iterator b (o.begin_connectionBands()), e (o.end_connectionBands());

        if (b != e)
        {
          connectionBands_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) connectionBands_next (o);
          }

          connectionBands_post (o);
        }

        else connectionBands_none (o);
      }

      void ORBResources::
      connectionBands_pre (Type&)
      {
      }

      void ORBResources::
      connectionBands_pre (Type const&)
      {
      }

      void ORBResources::
      connectionBands_next (Type&)
      {
      }

      void ORBResources::
      connectionBands_next (Type const&)
      {
      }

      void ORBResources::
      connectionBands_post (Type&)
      {
      }

      void ORBResources::
      connectionBands_post (Type const&)
      {
      }

      void ORBResources::
      connectionBands_none (Type&)
      {
      }

      void ORBResources::
      connectionBands_none (Type const&)
      {
      }

      void ORBResources::
      post (Type&)
      {
      }

      void ORBResources::
      post (Type const&)
      {
      }

      // Priority
      //
      //

      void Priority::
      traverse (Type& o)
      {
        pre (o);
        post (o);
      }

      void Priority::
      traverse (Type const& o)
      {
        pre (o);
        post (o);
      }

      void Priority::
      pre (Type&)
      {
      }

      void Priority::
      pre (Type const&)
      {
      }

      void Priority::
      post (Type&)
      {
      }

      void Priority::
      post (Type const&)
      {
      }

      // ThreadpoolDef
      //
      //

      void ThreadpoolDef::
      traverse (Type& o)
      {
        pre (o);
        stacksize (o);
        static_threads (o);
        dynamic_threads (o);
        default_priority (o);
        allow_request_buffering (o);
        max_buffered_requests (o);
        max_request_buffered_size (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ThreadpoolDef::
      traverse (Type const& o)
      {
        pre (o);
        stacksize (o);
        static_threads (o);
        dynamic_threads (o);
        default_priority (o);
        allow_request_buffering (o);
        max_buffered_requests (o);
        max_request_buffered_size (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ThreadpoolDef::
      pre (Type&)
      {
      }

      void ThreadpoolDef::
      pre (Type const&)
      {
      }

      void ThreadpoolDef::
      stacksize (Type& o)
      {
        dispatch (o.stacksize ());
      }

      void ThreadpoolDef::
      stacksize (Type const& o)
      {
        dispatch (o.stacksize ());
      }

      void ThreadpoolDef::
      static_threads (Type& o)
      {
        dispatch (o.static_threads ());
      }

      void ThreadpoolDef::
      static_threads (Type const& o)
      {
        dispatch (o.static_threads ());
      }

      void ThreadpoolDef::
      dynamic_threads (Type& o)
      {
        dispatch (o.dynamic_threads ());
      }

      void ThreadpoolDef::
      dynamic_threads (Type const& o)
      {
        dispatch (o.dynamic_threads ());
      }

      void ThreadpoolDef::
      default_priority (Type& o)
      {
        dispatch (o.default_priority ());
      }

      void ThreadpoolDef::
      default_priority (Type const& o)
      {
        dispatch (o.default_priority ());
      }

      void ThreadpoolDef::
      allow_request_buffering (Type& o)
      {
        dispatch (o.allow_request_buffering ());
      }

      void ThreadpoolDef::
      allow_request_buffering (Type const& o)
      {
        dispatch (o.allow_request_buffering ());
      }

      void ThreadpoolDef::
      max_buffered_requests (Type& o)
      {
        dispatch (o.max_buffered_requests ());
      }

      void ThreadpoolDef::
      max_buffered_requests (Type const& o)
      {
        dispatch (o.max_buffered_requests ());
      }

      void ThreadpoolDef::
      max_request_buffered_size (Type& o)
      {
        dispatch (o.max_request_buffered_size ());
      }

      void ThreadpoolDef::
      max_request_buffered_size (Type const& o)
      {
        dispatch (o.max_request_buffered_size ());
      }

      void ThreadpoolDef::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void ThreadpoolDef::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void ThreadpoolDef::
      id_none (Type&)
      {
      }

      void ThreadpoolDef::
      id_none (Type const&)
      {
      }

      void ThreadpoolDef::
      post (Type&)
      {
      }

      void ThreadpoolDef::
      post (Type const&)
      {
      }

      // ThreadpoolWithLanesDef
      //
      //

      void ThreadpoolWithLanesDef::
      traverse (Type& o)
      {
        pre (o);
        threadpoolLane (o);
        stacksize (o);
        allow_borrowing (o);
        allow_request_buffering (o);
        max_buffered_requests (o);
        max_request_buffered_size (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ThreadpoolWithLanesDef::
      traverse (Type const& o)
      {
        pre (o);
        threadpoolLane (o);
        stacksize (o);
        allow_borrowing (o);
        allow_request_buffering (o);
        max_buffered_requests (o);
        max_request_buffered_size (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ThreadpoolWithLanesDef::
      pre (Type&)
      {
      }

      void ThreadpoolWithLanesDef::
      pre (Type const&)
      {
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane (Type& o)
      {
        // VC6 anathema strikes again
        //
        ThreadpoolWithLanesDef::Type::threadpoolLane_iterator b (o.begin_threadpoolLane()), e (o.end_threadpoolLane());

        if (b != e)
        {
          threadpoolLane_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpoolLane_next (o);
          }

          threadpoolLane_post (o);
        }
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ThreadpoolWithLanesDef::Type::threadpoolLane_const_iterator b (o.begin_threadpoolLane()), e (o.end_threadpoolLane());

        if (b != e)
        {
          threadpoolLane_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpoolLane_next (o);
          }

          threadpoolLane_post (o);
        }
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_pre (Type&)
      {
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_pre (Type const&)
      {
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_next (Type&)
      {
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_next (Type const&)
      {
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_post (Type&)
      {
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_post (Type const&)
      {
      }

      void ThreadpoolWithLanesDef::
      stacksize (Type& o)
      {
        dispatch (o.stacksize ());
      }

      void ThreadpoolWithLanesDef::
      stacksize (Type const& o)
      {
        dispatch (o.stacksize ());
      }

      void ThreadpoolWithLanesDef::
      allow_borrowing (Type& o)
      {
        dispatch (o.allow_borrowing ());
      }

      void ThreadpoolWithLanesDef::
      allow_borrowing (Type const& o)
      {
        dispatch (o.allow_borrowing ());
      }

      void ThreadpoolWithLanesDef::
      allow_request_buffering (Type& o)
      {
        dispatch (o.allow_request_buffering ());
      }

      void ThreadpoolWithLanesDef::
      allow_request_buffering (Type const& o)
      {
        dispatch (o.allow_request_buffering ());
      }

      void ThreadpoolWithLanesDef::
      max_buffered_requests (Type& o)
      {
        dispatch (o.max_buffered_requests ());
      }

      void ThreadpoolWithLanesDef::
      max_buffered_requests (Type const& o)
      {
        dispatch (o.max_buffered_requests ());
      }

      void ThreadpoolWithLanesDef::
      max_request_buffered_size (Type& o)
      {
        dispatch (o.max_request_buffered_size ());
      }

      void ThreadpoolWithLanesDef::
      max_request_buffered_size (Type const& o)
      {
        dispatch (o.max_request_buffered_size ());
      }

      void ThreadpoolWithLanesDef::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void ThreadpoolWithLanesDef::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void ThreadpoolWithLanesDef::
      id_none (Type&)
      {
      }

      void ThreadpoolWithLanesDef::
      id_none (Type const&)
      {
      }

      void ThreadpoolWithLanesDef::
      post (Type&)
      {
      }

      void ThreadpoolWithLanesDef::
      post (Type const&)
      {
      }

      // ThreadpoolLaneDef
      //
      //

      void ThreadpoolLaneDef::
      traverse (Type& o)
      {
        pre (o);
        static_threads (o);
        dynamic_threads (o);
        priority (o);
        post (o);
      }

      void ThreadpoolLaneDef::
      traverse (Type const& o)
      {
        pre (o);
        static_threads (o);
        dynamic_threads (o);
        priority (o);
        post (o);
      }

      void ThreadpoolLaneDef::
      pre (Type&)
      {
      }

      void ThreadpoolLaneDef::
      pre (Type const&)
      {
      }

      void ThreadpoolLaneDef::
      static_threads (Type& o)
      {
        dispatch (o.static_threads ());
      }

      void ThreadpoolLaneDef::
      static_threads (Type const& o)
      {
        dispatch (o.static_threads ());
      }

      void ThreadpoolLaneDef::
      dynamic_threads (Type& o)
      {
        dispatch (o.dynamic_threads ());
      }

      void ThreadpoolLaneDef::
      dynamic_threads (Type const& o)
      {
        dispatch (o.dynamic_threads ());
      }

      void ThreadpoolLaneDef::
      priority (Type& o)
      {
        dispatch (o.priority ());
      }

      void ThreadpoolLaneDef::
      priority (Type const& o)
      {
        dispatch (o.priority ());
      }

      void ThreadpoolLaneDef::
      post (Type&)
      {
      }

      void ThreadpoolLaneDef::
      post (Type const&)
      {
      }

      // ConnectionBandsDef
      //
      //

      void ConnectionBandsDef::
      traverse (Type& o)
      {
        pre (o);
        band (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ConnectionBandsDef::
      traverse (Type const& o)
      {
        pre (o);
        band (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ConnectionBandsDef::
      pre (Type&)
      {
      }

      void ConnectionBandsDef::
      pre (Type const&)
      {
      }

      void ConnectionBandsDef::
      band (Type& o)
      {
        // VC6 anathema strikes again
        //
        ConnectionBandsDef::Type::band_iterator b (o.begin_band()), e (o.end_band());

        if (b != e)
        {
          band_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) band_next (o);
          }

          band_post (o);
        }
      }

      void ConnectionBandsDef::
      band (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ConnectionBandsDef::Type::band_const_iterator b (o.begin_band()), e (o.end_band());

        if (b != e)
        {
          band_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) band_next (o);
          }

          band_post (o);
        }
      }

      void ConnectionBandsDef::
      band_pre (Type&)
      {
      }

      void ConnectionBandsDef::
      band_pre (Type const&)
      {
      }

      void ConnectionBandsDef::
      band_next (Type&)
      {
      }

      void ConnectionBandsDef::
      band_next (Type const&)
      {
      }

      void ConnectionBandsDef::
      band_post (Type&)
      {
      }

      void ConnectionBandsDef::
      band_post (Type const&)
      {
      }

      void ConnectionBandsDef::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void ConnectionBandsDef::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void ConnectionBandsDef::
      id_none (Type&)
      {
      }

      void ConnectionBandsDef::
      id_none (Type const&)
      {
      }

      void ConnectionBandsDef::
      post (Type&)
      {
      }

      void ConnectionBandsDef::
      post (Type const&)
      {
      }

      // PriorityBandDef
      //
      //

      void PriorityBandDef::
      traverse (Type& o)
      {
        pre (o);
        low (o);
        high (o);
        post (o);
      }

      void PriorityBandDef::
      traverse (Type const& o)
      {
        pre (o);
        low (o);
        high (o);
        post (o);
      }

      void PriorityBandDef::
      pre (Type&)
      {
      }

      void PriorityBandDef::
      pre (Type const&)
      {
      }

      void PriorityBandDef::
      low (Type& o)
      {
        dispatch (o.low ());
      }

      void PriorityBandDef::
      low (Type const& o)
      {
        dispatch (o.low ());
      }

      void PriorityBandDef::
      high (Type& o)
      {
        dispatch (o.high ());
      }

      void PriorityBandDef::
      high (Type const& o)
      {
        dispatch (o.high ());
      }

      void PriorityBandDef::
      post (Type&)
      {
      }

      void PriorityBandDef::
      post (Type const&)
      {
      }

      // PolicySet
      //
      //

      void PolicySet::
      traverse (Type& o)
      {
        pre (o);
        priorityModel (o);
        nwpriorityModel (o);
        cnwpriorityModel (o);
        threadpool (o);
        priorityBandedConnection (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void PolicySet::
      traverse (Type const& o)
      {
        pre (o);
        priorityModel (o);
        nwpriorityModel (o);
        cnwpriorityModel (o);
        threadpool (o);
        priorityBandedConnection (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void PolicySet::
      pre (Type&)
      {
      }

      void PolicySet::
      pre (Type const&)
      {
      }

      void PolicySet::
      priorityModel (Type& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::priorityModel_iterator b (o.begin_priorityModel()), e (o.end_priorityModel());

        if (b != e)
        {
          priorityModel_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) priorityModel_next (o);
          }

          priorityModel_post (o);
        }

        else priorityModel_none (o);
      }

      void PolicySet::
      priorityModel (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::priorityModel_const_iterator b (o.begin_priorityModel()), e (o.end_priorityModel());

        if (b != e)
        {
          priorityModel_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) priorityModel_next (o);
          }

          priorityModel_post (o);
        }

        else priorityModel_none (o);
      }

      void PolicySet::
      priorityModel_pre (Type&)
      {
      }

      void PolicySet::
      priorityModel_pre (Type const&)
      {
      }

      void PolicySet::
      priorityModel_next (Type&)
      {
      }

      void PolicySet::
      priorityModel_next (Type const&)
      {
      }

      void PolicySet::
      priorityModel_post (Type&)
      {
      }

      void PolicySet::
      priorityModel_post (Type const&)
      {
      }

      void PolicySet::
      priorityModel_none (Type&)
      {
      }

      void PolicySet::
      priorityModel_none (Type const&)
      {
      }

      void PolicySet::
      nwpriorityModel (Type& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::nwpriorityModel_iterator b (o.begin_nwpriorityModel()), e (o.end_nwpriorityModel());

        if (b != e)
        {
          nwpriorityModel_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) nwpriorityModel_next (o);
          }

          nwpriorityModel_post (o);
        }

        else nwpriorityModel_none (o);
      }

      void PolicySet::
      nwpriorityModel (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::nwpriorityModel_const_iterator b (o.begin_nwpriorityModel()), e (o.end_nwpriorityModel());

        if (b != e)
        {
          nwpriorityModel_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) nwpriorityModel_next (o);
          }

          nwpriorityModel_post (o);
        }

        else nwpriorityModel_none (o);
      }

      void PolicySet::
      nwpriorityModel_pre (Type&)
      {
      }

      void PolicySet::
      nwpriorityModel_pre (Type const&)
      {
      }

      void PolicySet::
      nwpriorityModel_next (Type&)
      {
      }

      void PolicySet::
      nwpriorityModel_next (Type const&)
      {
      }

      void PolicySet::
      nwpriorityModel_post (Type&)
      {
      }

      void PolicySet::
      nwpriorityModel_post (Type const&)
      {
      }

      void PolicySet::
      nwpriorityModel_none (Type&)
      {
      }

      void PolicySet::
      nwpriorityModel_none (Type const&)
      {
      }

      void PolicySet::
      cnwpriorityModel (Type& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::cnwpriorityModel_iterator b (o.begin_cnwpriorityModel()), e (o.end_cnwpriorityModel());

        if (b != e)
        {
          cnwpriorityModel_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) cnwpriorityModel_next (o);
          }

          cnwpriorityModel_post (o);
        }

        else cnwpriorityModel_none (o);
      }

      void PolicySet::
      cnwpriorityModel (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::cnwpriorityModel_const_iterator b (o.begin_cnwpriorityModel()), e (o.end_cnwpriorityModel());

        if (b != e)
        {
          cnwpriorityModel_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) cnwpriorityModel_next (o);
          }

          cnwpriorityModel_post (o);
        }

        else cnwpriorityModel_none (o);
      }

      void PolicySet::
      cnwpriorityModel_pre (Type&)
      {
      }

      void PolicySet::
      cnwpriorityModel_pre (Type const&)
      {
      }

      void PolicySet::
      cnwpriorityModel_next (Type&)
      {
      }

      void PolicySet::
      cnwpriorityModel_next (Type const&)
      {
      }

      void PolicySet::
      cnwpriorityModel_post (Type&)
      {
      }

      void PolicySet::
      cnwpriorityModel_post (Type const&)
      {
      }

      void PolicySet::
      cnwpriorityModel_none (Type&)
      {
      }

      void PolicySet::
      cnwpriorityModel_none (Type const&)
      {
      }

      void PolicySet::
      threadpool (Type& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::threadpool_iterator b (o.begin_threadpool()), e (o.end_threadpool());

        if (b != e)
        {
          threadpool_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpool_next (o);
          }

          threadpool_post (o);
        }

        else threadpool_none (o);
      }

      void PolicySet::
      threadpool (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::threadpool_const_iterator b (o.begin_threadpool()), e (o.end_threadpool());

        if (b != e)
        {
          threadpool_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) threadpool_next (o);
          }

          threadpool_post (o);
        }

        else threadpool_none (o);
      }

      void PolicySet::
      threadpool_pre (Type&)
      {
      }

      void PolicySet::
      threadpool_pre (Type const&)
      {
      }

      void PolicySet::
      threadpool_next (Type&)
      {
      }

      void PolicySet::
      threadpool_next (Type const&)
      {
      }

      void PolicySet::
      threadpool_post (Type&)
      {
      }

      void PolicySet::
      threadpool_post (Type const&)
      {
      }

      void PolicySet::
      threadpool_none (Type&)
      {
      }

      void PolicySet::
      threadpool_none (Type const&)
      {
      }

      void PolicySet::
      priorityBandedConnection (Type& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::priorityBandedConnection_iterator b (o.begin_priorityBandedConnection()), e (o.end_priorityBandedConnection());

        if (b != e)
        {
          priorityBandedConnection_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) priorityBandedConnection_next (o);
          }

          priorityBandedConnection_post (o);
        }

        else priorityBandedConnection_none (o);
      }

      void PolicySet::
      priorityBandedConnection (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PolicySet::Type::priorityBandedConnection_const_iterator b (o.begin_priorityBandedConnection()), e (o.end_priorityBandedConnection());

        if (b != e)
        {
          priorityBandedConnection_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) priorityBandedConnection_next (o);
          }

          priorityBandedConnection_post (o);
        }

        else priorityBandedConnection_none (o);
      }

      void PolicySet::
      priorityBandedConnection_pre (Type&)
      {
      }

      void PolicySet::
      priorityBandedConnection_pre (Type const&)
      {
      }

      void PolicySet::
      priorityBandedConnection_next (Type&)
      {
      }

      void PolicySet::
      priorityBandedConnection_next (Type const&)
      {
      }

      void PolicySet::
      priorityBandedConnection_post (Type&)
      {
      }

      void PolicySet::
      priorityBandedConnection_post (Type const&)
      {
      }

      void PolicySet::
      priorityBandedConnection_none (Type&)
      {
      }

      void PolicySet::
      priorityBandedConnection_none (Type const&)
      {
      }

      void PolicySet::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void PolicySet::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void PolicySet::
      id_none (Type&)
      {
      }

      void PolicySet::
      id_none (Type const&)
      {
      }

      void PolicySet::
      post (Type&)
      {
      }

      void PolicySet::
      post (Type const&)
      {
      }

      // PriorityModelPolicyDef
      //
      //

      void PriorityModelPolicyDef::
      traverse (Type& o)
      {
        pre (o);
        priority_model (o);
        if (o.server_priority_p ()) server_priority (o);
        else server_priority_none (o);
        post (o);
      }

      void PriorityModelPolicyDef::
      traverse (Type const& o)
      {
        pre (o);
        priority_model (o);
        if (o.server_priority_p ()) server_priority (o);
        else server_priority_none (o);
        post (o);
      }

      void PriorityModelPolicyDef::
      pre (Type&)
      {
      }

      void PriorityModelPolicyDef::
      pre (Type const&)
      {
      }

      void PriorityModelPolicyDef::
      priority_model (Type& o)
      {
        dispatch (o.priority_model ());
      }

      void PriorityModelPolicyDef::
      priority_model (Type const& o)
      {
        dispatch (o.priority_model ());
      }

      void PriorityModelPolicyDef::
      server_priority (Type& o)
      {
        dispatch (o.server_priority ());
      }

      void PriorityModelPolicyDef::
      server_priority (Type const& o)
      {
        dispatch (o.server_priority ());
      }

      void PriorityModelPolicyDef::
      server_priority_none (Type&)
      {
      }

      void PriorityModelPolicyDef::
      server_priority_none (Type const&)
      {
      }

      void PriorityModelPolicyDef::
      post (Type&)
      {
      }

      void PriorityModelPolicyDef::
      post (Type const&)
      {
      }

      // NWPriorityModelPolicyDef
      //
      //

      void NWPriorityModelPolicyDef::
      traverse (Type& o)
      {
        pre (o);
        nw_priority_model (o);
        request_dscp (o);
        reply_dscp (o);
        post (o);
      }

      void NWPriorityModelPolicyDef::
      traverse (Type const& o)
      {
        pre (o);
        nw_priority_model (o);
        request_dscp (o);
        reply_dscp (o);
        post (o);
      }

      void NWPriorityModelPolicyDef::
      pre (Type&)
      {
      }

      void NWPriorityModelPolicyDef::
      pre (Type const&)
      {
      }

      void NWPriorityModelPolicyDef::
      nw_priority_model (Type& o)
      {
        dispatch (o.nw_priority_model ());
      }

      void NWPriorityModelPolicyDef::
      nw_priority_model (Type const& o)
      {
        dispatch (o.nw_priority_model ());
      }

      void NWPriorityModelPolicyDef::
      request_dscp (Type& o)
      {
        dispatch (o.request_dscp ());
      }

      void NWPriorityModelPolicyDef::
      request_dscp (Type const& o)
      {
        dispatch (o.request_dscp ());
      }

      void NWPriorityModelPolicyDef::
      reply_dscp (Type& o)
      {
        dispatch (o.reply_dscp ());
      }

      void NWPriorityModelPolicyDef::
      reply_dscp (Type const& o)
      {
        dispatch (o.reply_dscp ());
      }

      void NWPriorityModelPolicyDef::
      post (Type&)
      {
      }

      void NWPriorityModelPolicyDef::
      post (Type const&)
      {
      }

      // CNWPriorityModelPolicyDef
      //
      //

      void CNWPriorityModelPolicyDef::
      traverse (Type& o)
      {
        pre (o);
        request_dscp (o);
        reply_dscp (o);
        post (o);
      }

      void CNWPriorityModelPolicyDef::
      traverse (Type const& o)
      {
        pre (o);
        request_dscp (o);
        reply_dscp (o);
        post (o);
      }

      void CNWPriorityModelPolicyDef::
      pre (Type&)
      {
      }

      void CNWPriorityModelPolicyDef::
      pre (Type const&)
      {
      }

      void CNWPriorityModelPolicyDef::
      request_dscp (Type& o)
      {
        dispatch (o.request_dscp ());
      }

      void CNWPriorityModelPolicyDef::
      request_dscp (Type const& o)
      {
        dispatch (o.request_dscp ());
      }

      void CNWPriorityModelPolicyDef::
      reply_dscp (Type& o)
      {
        dispatch (o.reply_dscp ());
      }

      void CNWPriorityModelPolicyDef::
      reply_dscp (Type const& o)
      {
        dispatch (o.reply_dscp ());
      }

      void CNWPriorityModelPolicyDef::
      post (Type&)
      {
      }

      void CNWPriorityModelPolicyDef::
      post (Type const&)
      {
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      // ServerResourcesDef
      //
      //

      ServerResourcesDef::
      ServerResourcesDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ServerResourcesDef::
      ServerResourcesDef ()
      {
      }

      void ServerResourcesDef::
      traverse (Type const& o)
      {
        Traversal::ServerResourcesDef::traverse (o);
      }

      void ServerResourcesDef::
      cmdline (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("cmdline", top_ ()));
        Traversal::ServerResourcesDef::cmdline (o);
        pop_ ();
      }

      void ServerResourcesDef::
      svcconf (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("svcconf", top_ ()));
        Traversal::ServerResourcesDef::svcconf (o);
        pop_ ();
      }

      void ServerResourcesDef::
      orbConfigs (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("orbConfigs", top_ ()));
        Traversal::ServerResourcesDef::orbConfigs (o);
        pop_ ();
      }

      void ServerResourcesDef::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::ServerResourcesDef::id (o);
        attr_ (0);
      }

      // ServerCmdlineOptions
      //
      //

      ServerCmdlineOptions::
      ServerCmdlineOptions (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ServerCmdlineOptions::
      ServerCmdlineOptions ()
      {
      }

      void ServerCmdlineOptions::
      traverse (Type const& o)
      {
        Traversal::ServerCmdlineOptions::traverse (o);
      }

      void ServerCmdlineOptions::
      arg_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("arg", top_ ()));
      }

      void ServerCmdlineOptions::
      arg_next (Type const& o)
      {
        arg_post (o);
        arg_pre (o);
      }

      void ServerCmdlineOptions::
      arg_post (Type const&)
      {
        pop_ ();
      }

      // ACESvcConf
      //
      //

      ACESvcConf::
      ACESvcConf (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ACESvcConf::
      ACESvcConf ()
      {
      }

      void ACESvcConf::
      traverse (Type const& o)
      {
        Traversal::ACESvcConf::traverse (o);
      }

      void ACESvcConf::
      uri (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("uri", top_ ()));
        Traversal::ACESvcConf::uri (o);
        pop_ ();
      }

      // ORBConfigs
      //
      //

      ORBConfigs::
      ORBConfigs (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ORBConfigs::
      ORBConfigs ()
      {
      }

      void ORBConfigs::
      traverse (Type const& o)
      {
        Traversal::ORBConfigs::traverse (o);
      }

      void ORBConfigs::
      resources (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resources", top_ ()));
        Traversal::ORBConfigs::resources (o);
        pop_ ();
      }

      void ORBConfigs::
      policySet_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("policySet", top_ ()));
      }

      void ORBConfigs::
      policySet_next (Type const& o)
      {
        policySet_post (o);
        policySet_pre (o);
      }

      void ORBConfigs::
      policySet_post (Type const&)
      {
        pop_ ();
      }

      // ORBResources
      //
      //

      ORBResources::
      ORBResources (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ORBResources::
      ORBResources ()
      {
      }

      void ORBResources::
      traverse (Type const& o)
      {
        Traversal::ORBResources::traverse (o);
      }

      void ORBResources::
      threadpool_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("threadpool", top_ ()));
      }

      void ORBResources::
      threadpool_next (Type const& o)
      {
        threadpool_post (o);
        threadpool_pre (o);
      }

      void ORBResources::
      threadpool_post (Type const&)
      {
        pop_ ();
      }

      void ORBResources::
      threadpoolWithLanes_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("threadpoolWithLanes", top_ ()));
      }

      void ORBResources::
      threadpoolWithLanes_next (Type const& o)
      {
        threadpoolWithLanes_post (o);
        threadpoolWithLanes_pre (o);
      }

      void ORBResources::
      threadpoolWithLanes_post (Type const&)
      {
        pop_ ();
      }

      void ORBResources::
      connectionBands_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("connectionBands", top_ ()));
      }

      void ORBResources::
      connectionBands_next (Type const& o)
      {
        connectionBands_post (o);
        connectionBands_pre (o);
      }

      void ORBResources::
      connectionBands_post (Type const&)
      {
        pop_ ();
      }

      // Priority
      //
      //

      Priority::
      Priority (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      Priority::
      Priority ()
      {
      }

      void Priority::
      traverse (Type const& o)
      {
        ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >::traverse (o);
        Traversal::Priority::traverse (o);
      }

      // ThreadpoolDef
      //
      //

      ThreadpoolDef::
      ThreadpoolDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ThreadpoolDef::
      ThreadpoolDef ()
      {
      }

      void ThreadpoolDef::
      traverse (Type const& o)
      {
        Traversal::ThreadpoolDef::traverse (o);
      }

      void ThreadpoolDef::
      stacksize (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("stacksize", top_ ()));
        Traversal::ThreadpoolDef::stacksize (o);
        pop_ ();
      }

      void ThreadpoolDef::
      static_threads (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("static_threads", top_ ()));
        Traversal::ThreadpoolDef::static_threads (o);
        pop_ ();
      }

      void ThreadpoolDef::
      dynamic_threads (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("dynamic_threads", top_ ()));
        Traversal::ThreadpoolDef::dynamic_threads (o);
        pop_ ();
      }

      void ThreadpoolDef::
      default_priority (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("default_priority", top_ ()));
        Traversal::ThreadpoolDef::default_priority (o);
        pop_ ();
      }

      void ThreadpoolDef::
      allow_request_buffering (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("allow_request_buffering", top_ ()));
        Traversal::ThreadpoolDef::allow_request_buffering (o);
        pop_ ();
      }

      void ThreadpoolDef::
      max_buffered_requests (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("max_buffered_requests", top_ ()));
        Traversal::ThreadpoolDef::max_buffered_requests (o);
        pop_ ();
      }

      void ThreadpoolDef::
      max_request_buffered_size (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("max_request_buffered_size", top_ ()));
        Traversal::ThreadpoolDef::max_request_buffered_size (o);
        pop_ ();
      }

      void ThreadpoolDef::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::ThreadpoolDef::id (o);
        attr_ (0);
      }

      // ThreadpoolWithLanesDef
      //
      //

      ThreadpoolWithLanesDef::
      ThreadpoolWithLanesDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ThreadpoolWithLanesDef::
      ThreadpoolWithLanesDef ()
      {
      }

      void ThreadpoolWithLanesDef::
      traverse (Type const& o)
      {
        Traversal::ThreadpoolWithLanesDef::traverse (o);
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("threadpoolLane", top_ ()));
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_next (Type const& o)
      {
        threadpoolLane_post (o);
        threadpoolLane_pre (o);
      }

      void ThreadpoolWithLanesDef::
      threadpoolLane_post (Type const&)
      {
        pop_ ();
      }

      void ThreadpoolWithLanesDef::
      stacksize (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("stacksize", top_ ()));
        Traversal::ThreadpoolWithLanesDef::stacksize (o);
        pop_ ();
      }

      void ThreadpoolWithLanesDef::
      allow_borrowing (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("allow_borrowing", top_ ()));
        Traversal::ThreadpoolWithLanesDef::allow_borrowing (o);
        pop_ ();
      }

      void ThreadpoolWithLanesDef::
      allow_request_buffering (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("allow_request_buffering", top_ ()));
        Traversal::ThreadpoolWithLanesDef::allow_request_buffering (o);
        pop_ ();
      }

      void ThreadpoolWithLanesDef::
      max_buffered_requests (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("max_buffered_requests", top_ ()));
        Traversal::ThreadpoolWithLanesDef::max_buffered_requests (o);
        pop_ ();
      }

      void ThreadpoolWithLanesDef::
      max_request_buffered_size (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("max_request_buffered_size", top_ ()));
        Traversal::ThreadpoolWithLanesDef::max_request_buffered_size (o);
        pop_ ();
      }

      void ThreadpoolWithLanesDef::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::ThreadpoolWithLanesDef::id (o);
        attr_ (0);
      }

      // ThreadpoolLaneDef
      //
      //

      ThreadpoolLaneDef::
      ThreadpoolLaneDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ThreadpoolLaneDef::
      ThreadpoolLaneDef ()
      {
      }

      void ThreadpoolLaneDef::
      traverse (Type const& o)
      {
        Traversal::ThreadpoolLaneDef::traverse (o);
      }

      void ThreadpoolLaneDef::
      static_threads (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("static_threads", top_ ()));
        Traversal::ThreadpoolLaneDef::static_threads (o);
        pop_ ();
      }

      void ThreadpoolLaneDef::
      dynamic_threads (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("dynamic_threads", top_ ()));
        Traversal::ThreadpoolLaneDef::dynamic_threads (o);
        pop_ ();
      }

      void ThreadpoolLaneDef::
      priority (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("priority", top_ ()));
        Traversal::ThreadpoolLaneDef::priority (o);
        pop_ ();
      }

      // ConnectionBandsDef
      //
      //

      ConnectionBandsDef::
      ConnectionBandsDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ConnectionBandsDef::
      ConnectionBandsDef ()
      {
      }

      void ConnectionBandsDef::
      traverse (Type const& o)
      {
        Traversal::ConnectionBandsDef::traverse (o);
      }

      void ConnectionBandsDef::
      band_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("band", top_ ()));
      }

      void ConnectionBandsDef::
      band_next (Type const& o)
      {
        band_post (o);
        band_pre (o);
      }

      void ConnectionBandsDef::
      band_post (Type const&)
      {
        pop_ ();
      }

      void ConnectionBandsDef::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::ConnectionBandsDef::id (o);
        attr_ (0);
      }

      // PriorityBandDef
      //
      //

      PriorityBandDef::
      PriorityBandDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      PriorityBandDef::
      PriorityBandDef ()
      {
      }

      void PriorityBandDef::
      traverse (Type const& o)
      {
        Traversal::PriorityBandDef::traverse (o);
      }

      void PriorityBandDef::
      low (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("low", top_ ()));
        Traversal::PriorityBandDef::low (o);
        pop_ ();
      }

      void PriorityBandDef::
      high (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("high", top_ ()));
        Traversal::PriorityBandDef::high (o);
        pop_ ();
      }

      // PolicySet
      //
      //

      PolicySet::
      PolicySet (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      PolicySet::
      PolicySet ()
      {
      }

      void PolicySet::
      traverse (Type const& o)
      {
        Traversal::PolicySet::traverse (o);
      }

      void PolicySet::
      priorityModel_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("priorityModel", top_ ()));
      }

      void PolicySet::
      priorityModel_next (Type const& o)
      {
        priorityModel_post (o);
        priorityModel_pre (o);
      }

      void PolicySet::
      priorityModel_post (Type const&)
      {
        pop_ ();
      }

      void PolicySet::
      nwpriorityModel_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("nwpriorityModel", top_ ()));
      }

      void PolicySet::
      nwpriorityModel_next (Type const& o)
      {
        nwpriorityModel_post (o);
        nwpriorityModel_pre (o);
      }

      void PolicySet::
      nwpriorityModel_post (Type const&)
      {
        pop_ ();
      }

      void PolicySet::
      cnwpriorityModel_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("cnwpriorityModel", top_ ()));
      }

      void PolicySet::
      cnwpriorityModel_next (Type const& o)
      {
        cnwpriorityModel_post (o);
        cnwpriorityModel_pre (o);
      }

      void PolicySet::
      cnwpriorityModel_post (Type const&)
      {
        pop_ ();
      }

      void PolicySet::
      threadpool_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("threadpool", top_ ()));
      }

      void PolicySet::
      threadpool_next (Type const& o)
      {
        threadpool_post (o);
        threadpool_pre (o);
      }

      void PolicySet::
      threadpool_post (Type const&)
      {
        pop_ ();
      }

      void PolicySet::
      priorityBandedConnection_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("priorityBandedConnection", top_ ()));
      }

      void PolicySet::
      priorityBandedConnection_next (Type const& o)
      {
        priorityBandedConnection_post (o);
        priorityBandedConnection_pre (o);
      }

      void PolicySet::
      priorityBandedConnection_post (Type const&)
      {
        pop_ ();
      }

      void PolicySet::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::PolicySet::id (o);
        attr_ (0);
      }

      // PriorityModel
      //
      //

      PriorityModel::
      PriorityModel (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      PriorityModel::
      PriorityModel ()
      {
      }

      void PriorityModel::
      traverse (Type const& o)
      {
        ::std::basic_string< ACE_TCHAR > s;

        if (o == ::CIAO::Config_Handlers::PriorityModel::SERVER_DECLARED) s = "SERVER_DECLARED";
        else if (o == ::CIAO::Config_Handlers::PriorityModel::CLIENT_PROPAGATED) s = "CLIENT_PROPAGATED";
        else 
        {
        }

        if (::XSCRT::XML::Attribute< ACE_TCHAR >* a = attr_ ())
        {
          a->value (s);
        }

        else
        {
          top_().value (s);
        }
      }

      // NWPriorityModel
      //
      //

      NWPriorityModel::
      NWPriorityModel (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      NWPriorityModel::
      NWPriorityModel ()
      {
      }

      void NWPriorityModel::
      traverse (Type const& o)
      {
        ::std::basic_string< ACE_TCHAR > s;

        if (o == ::CIAO::Config_Handlers::NWPriorityModel::SERVER_DECLARED_NWPRIORITY) s = "SERVER_DECLARED_NWPRIORITY";
        else if (o == ::CIAO::Config_Handlers::NWPriorityModel::CLIENT_PROPAGATED_NWPRIORITY) s = "CLIENT_PROPAGATED_NWPRIORITY";
        else 
        {
        }

        if (::XSCRT::XML::Attribute< ACE_TCHAR >* a = attr_ ())
        {
          a->value (s);
        }

        else
        {
          top_().value (s);
        }
      }

      // PriorityModelPolicyDef
      //
      //

      PriorityModelPolicyDef::
      PriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      PriorityModelPolicyDef::
      PriorityModelPolicyDef ()
      {
      }

      void PriorityModelPolicyDef::
      traverse (Type const& o)
      {
        Traversal::PriorityModelPolicyDef::traverse (o);
      }

      void PriorityModelPolicyDef::
      priority_model (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("priority_model", top_ ()));
        Traversal::PriorityModelPolicyDef::priority_model (o);
        pop_ ();
      }

      void PriorityModelPolicyDef::
      server_priority (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("server_priority", "", top_ ());
        attr_ (&a);
        Traversal::PriorityModelPolicyDef::server_priority (o);
        attr_ (0);
      }

      // NWPriorityModelPolicyDef
      //
      //

      NWPriorityModelPolicyDef::
      NWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      NWPriorityModelPolicyDef::
      NWPriorityModelPolicyDef ()
      {
      }

      void NWPriorityModelPolicyDef::
      traverse (Type const& o)
      {
        Traversal::NWPriorityModelPolicyDef::traverse (o);
      }

      void NWPriorityModelPolicyDef::
      nw_priority_model (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("nw_priority_model", top_ ()));
        Traversal::NWPriorityModelPolicyDef::nw_priority_model (o);
        pop_ ();
      }

      void NWPriorityModelPolicyDef::
      request_dscp (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("request_dscp", top_ ()));
        Traversal::NWPriorityModelPolicyDef::request_dscp (o);
        pop_ ();
      }

      void NWPriorityModelPolicyDef::
      reply_dscp (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("reply_dscp", top_ ()));
        Traversal::NWPriorityModelPolicyDef::reply_dscp (o);
        pop_ ();
      }

      // CNWPriorityModelPolicyDef
      //
      //

      CNWPriorityModelPolicyDef::
      CNWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      CNWPriorityModelPolicyDef::
      CNWPriorityModelPolicyDef ()
      {
      }

      void CNWPriorityModelPolicyDef::
      traverse (Type const& o)
      {
        Traversal::CNWPriorityModelPolicyDef::traverse (o);
      }

      void CNWPriorityModelPolicyDef::
      request_dscp (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("request_dscp", top_ ()));
        Traversal::CNWPriorityModelPolicyDef::request_dscp (o);
        pop_ ();
      }

      void CNWPriorityModelPolicyDef::
      reply_dscp (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("reply_dscp", top_ ()));
        Traversal::CNWPriorityModelPolicyDef::reply_dscp (o);
        pop_ ();
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    void
    ServerResources (::CIAO::Config_Handlers::ServerResourcesDef const& s, xercesc::DOMDocument* d)
    {
      ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
      if (e.name () != "ServerResources")
      {
        throw 1;
      }

      struct W : virtual ::CIAO::Config_Handlers::Writer::ServerResourcesDef,
      virtual ::CIAO::Config_Handlers::Writer::ServerCmdlineOptions,
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
      virtual ::CIAO::Config_Handlers::Writer::ACESvcConf,
      virtual ::CIAO::Config_Handlers::Writer::ORBConfigs,
      virtual ::CIAO::Config_Handlers::Writer::ORBResources,
      virtual ::CIAO::Config_Handlers::Writer::ThreadpoolDef,
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
      virtual ::CIAO::Config_Handlers::Writer::Priority,
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
      virtual ::CIAO::Config_Handlers::Writer::ThreadpoolWithLanesDef,
      virtual ::CIAO::Config_Handlers::Writer::ThreadpoolLaneDef,
      virtual ::CIAO::Config_Handlers::Writer::ConnectionBandsDef,
      virtual ::CIAO::Config_Handlers::Writer::PriorityBandDef,
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
      virtual ::CIAO::Config_Handlers::Writer::PolicySet,
      virtual ::CIAO::Config_Handlers::Writer::PriorityModelPolicyDef,
      virtual ::CIAO::Config_Handlers::Writer::PriorityModel,
      virtual ::CIAO::Config_Handlers::Writer::NWPriorityModelPolicyDef,
      virtual ::CIAO::Config_Handlers::Writer::NWPriorityModel,
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
      virtual ::CIAO::Config_Handlers::Writer::CNWPriorityModelPolicyDef,
      virtual ::XMLSchema::Writer::IDREF< ACE_TCHAR >, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        W (::XSCRT::XML::Element< ACE_TCHAR >& e)
        : ::XSCRT::Writer< ACE_TCHAR > (e)
        {
        }
      };

      W w (e);
      w.dispatch (s);
    }
  }
}

