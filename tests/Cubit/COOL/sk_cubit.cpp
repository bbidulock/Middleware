/*
 * File generated by CHIC (CHIC-COMMON-970407)
 *        from: cubit.idl
*/

//=========================================================
// Binding upcall class between Cubit_Impl and Cubit
//=========================================================
class _COOL_Bind_Cubit_Cubit_Impl {
public:
        static int
    dispatch(void*, _COOL_ServerRequest&, CORBA_Environment&);
        static int
    loadLocalVtbl(const void*, const _InterfaceId);
};
static const _COOL_UpCall  _u_Bind_Cubit_Cubit_Impl = {
    Cubit::coInterfaceDef,
    _COOL_Bind_Cubit_Cubit_Impl::dispatch,
    _COOL_Bind_Cubit_Cubit_Impl::loadLocalVtbl,
    1
};

#ifndef _COOL_localCubit_Cubit_Impl
#define _COOL_localCubit_Cubit_Impl

    //=========================================================
    // Local Invocation class between Cubit and Cubit_Impl
    //=========================================================
class _localCubit_Cubit_Impl : public virtual CORBA_Object {

public:
        virtual CORBA_Octet
    cube_octet(CORBA_Octet o,
               CORBA_Environment& _env = _environment);
            virtual CORBA_Short
    cube_short(CORBA_Short s,
               CORBA_Environment& _env = _environment);
            virtual CORBA_Long
    cube_long(CORBA_Long l,
              CORBA_Environment& _env = _environment);
            virtual Cubit::Many
    cube_struct(const Cubit::Many& values,
                CORBA_Environment& _env = _environment);
            virtual Cubit::oneof
    cube_union(const Cubit::oneof& values,
               CORBA_Environment& _env = _environment);
            virtual void
    please_exit(CORBA_Environment& _env = _environment);
    
    _localCubit_Cubit_Impl() : CORBA_Object(_emptyCtor)
    {}
protected:
        virtual int
    _shiftVtbl() const;
        virtual
    ~_localCubit_Cubit_Impl();

};

#endif

    int
_localCubit_Cubit_Impl::_shiftVtbl() const
{
    return C_OK;
}

_localCubit_Cubit_Impl::~_localCubit_Cubit_Impl()
{
}

    void
COOL_bind(const Cubit_Impl& server, Cubit_ptr& inter,
          const COOL_BindingData& bindingData,
          CORBA_Environment& _env)
{
    inter = new Cubit;
    int result = CORBA_Object::bindObject(&server, inter,
                                          _u_Bind_Cubit_Cubit_Impl,
                                          bindingData, _env);
    if (result != C_OK) {
        inter = Cubit::_nil();
    }
}

    int
_COOL_Bind_Cubit_Cubit_Impl::dispatch(void* _impl,
                                      _COOL_ServerRequest& _req,
                                      CORBA_Environment& _env)
{

    switch (_req.operation()) {

        // Cubit::cube_octet
    case 0: {
        CORBA_Octet o;
        o = _req.get_Octet();
        CORBA_Octet _returnValue = 
        ((Cubit_Impl*)_impl)->cube_octet(o, _env);
        if (_req.initialize(1, _env) != C_OK) {
            return C_ENOMEM;
        }
        _req.put_Octet(_returnValue);
        return C_OK;
    }

        // Cubit::cube_short
    case 1: {
        CORBA_Short s;
        s = _req.get_Short();
        CORBA_Short _returnValue = 
        ((Cubit_Impl*)_impl)->cube_short(s, _env);
        if (_req.initialize(2, _env) != C_OK) {
            return C_ENOMEM;
        }
        _req.put_Short(_returnValue);
        return C_OK;
    }

        // Cubit::cube_long
    case 2: {
        CORBA_Long l;
        l = _req.get_Long();
        CORBA_Long _returnValue = 
        ((Cubit_Impl*)_impl)->cube_long(l, _env);
        if (_req.initialize(4, _env) != C_OK) {
            return C_ENOMEM;
        }
        _req.put_Long(_returnValue);
        return C_OK;
    }

        // Cubit::cube_struct
    case 3: {
        Cubit::Many values;
        Cubit::ManyMarshaler::get(_req, values);
        Cubit::Many _returnValue = 
        ((Cubit_Impl*)_impl)->cube_struct(values, _env);
        if (_req.initialize(10, _env) != C_OK) {
            return C_ENOMEM;
        }
        Cubit::ManyMarshaler::put(_req, _returnValue);
        return C_OK;
    }

        // Cubit::cube_union
    case 4: {
        Cubit::oneof values;
        Cubit::oneofMarshaler::get(_req, values);
        Cubit::oneof _returnValue = 
        ((Cubit_Impl*)_impl)->cube_union(values, _env);
        if (_req.initialize(14, _env) != C_OK) {
            return C_ENOMEM;
        }
        Cubit::oneofMarshaler::put(_req, _returnValue);
        return C_OK;
    }

        // Cubit::please_exit
    case 5: {
        ((Cubit_Impl*)_impl)->please_exit(_env);
        return C_EPOSTPONED;
    }
    default:
        return C_EBADOPERATION;
    }
}

#ifdef _COOL_WINDOWS_NEW
#  undef new
#endif
    int
_COOL_Bind_Cubit_Cubit_Impl::loadLocalVtbl(const void* obj,
                                           const _InterfaceId interfaceId)
{
    switch (interfaceId) {
    case 0x00750aa6:    // Cubit
        ::new ((void*)obj,_new_placement) _localCubit_Cubit_Impl;
        break;
    default:
        return C_EFAIL;
    }
    return C_OK;
}
#ifdef _COOL_WINDOWS_NEW
#  define new _COOL_WINDOWS_NEW
#endif

    CORBA_Octet
_localCubit_Cubit_Impl::cube_octet(CORBA_Octet o,
                                   CORBA_Environment& _env)
{
    _COOL_ImplLock _implLock;
    if (lockImplementation(_implLock, _env) != C_OK) {
        return 0;
    }
    CORBA_Octet _returnValue = ((Cubit_Impl*)_implLock.implAddr())->cube_octet(o, _env);
    unlockImplementation(_implLock, _env);
    return _returnValue;
}

    CORBA_Short
_localCubit_Cubit_Impl::cube_short(CORBA_Short s,
                                   CORBA_Environment& _env)
{
    _COOL_ImplLock _implLock;
    if (lockImplementation(_implLock, _env) != C_OK) {
        return 0;
    }
    CORBA_Short _returnValue = ((Cubit_Impl*)_implLock.implAddr())->cube_short(s, _env);
    unlockImplementation(_implLock, _env);
    return _returnValue;
}

    CORBA_Long
_localCubit_Cubit_Impl::cube_long(CORBA_Long l,
                                  CORBA_Environment& _env)
{
    _COOL_ImplLock _implLock;
    if (lockImplementation(_implLock, _env) != C_OK) {
        return 0;
    }
    CORBA_Long _returnValue = ((Cubit_Impl*)_implLock.implAddr())->cube_long(l, _env);
    unlockImplementation(_implLock, _env);
    return _returnValue;
}

    Cubit::Many
_localCubit_Cubit_Impl::cube_struct(const Cubit::Many& values,
                                    CORBA_Environment& _env)
{
    _COOL_ImplLock _implLock;
    if (lockImplementation(_implLock, _env) != C_OK) {
        Cubit::Many _returnValue;
        return _returnValue;
    }
    Cubit::Many _returnValue = ((Cubit_Impl*)_implLock.implAddr())->cube_struct(values, _env);
    unlockImplementation(_implLock, _env);
    return _returnValue;
}

    Cubit::oneof
_localCubit_Cubit_Impl::cube_union(const Cubit::oneof& values,
                                   CORBA_Environment& _env)
{
    _COOL_ImplLock _implLock;
    if (lockImplementation(_implLock, _env) != C_OK) {
        Cubit::oneof _returnValue;
        return _returnValue;
    }
    Cubit::oneof _returnValue = ((Cubit_Impl*)_implLock.implAddr())->cube_union(values, _env);
    unlockImplementation(_implLock, _env);
    return _returnValue;
}

    void
_localCubit_Cubit_Impl::please_exit(CORBA_Environment& _env)
{
    _COOL_ImplLock _implLock;
    if (lockImplementation(_implLock, _env) != C_OK) {
        return;
    }
    ((Cubit_Impl*)_implLock.implAddr())->please_exit(_env);
    unlockImplementation(_implLock, _env);
}


