// $Id$

#ifndef _cubitC_h
#define _cubitC_h

/************************************************************************/
/*                                                                      */
/* This file is automatically generated by ORBeline IDL compiler        */
/* Do not modify this file.                                             */
/*                                                                      */
/* ORBeline (c) is copyrighted by PostModern Computing, Inc.            */
/*                                                                      */
/* The generated code conforms to OMG's IDL C++ mapping as              */
/* specified in OMG Document Number: 94-9-14.                           */
/*                                                                      */
/************************************************************************/

#include "corba.h"



class Cubit;
typedef Cubit *Cubit_ptr;
typedef Cubit_ptr CubitRef;

#ifndef _Cubit_var_
#define _Cubit_var_
class Cubit_var
{
    public:
	Cubit_var();
	Cubit_var(Cubit_ptr);
	Cubit_var(const Cubit_var&);
	~Cubit_var();
	Cubit_var& operator=(Cubit_ptr);
	operator Cubit_ptr() const { return _ptr; }
#if defined(_HPCC_BUG)
	operator Cubit *&() { return _ptr; }
#else
	operator Cubit_ptr&() { return _ptr; }
#endif
	Cubit_ptr operator->() const { return _ptr;}
	friend NCistream& operator>>(NCistream&, Cubit_var&);
	friend NCostream& operator<<(NCostream&, const Cubit_var&);
	friend istream& operator>>(istream&, Cubit_var&);
	friend ostream& operator<<(ostream&, const Cubit_var&);
    private:
	Cubit_ptr	_ptr;
	void operator=(const Cubit_var&) {}
};
#endif
class Cubit: public virtual CORBA_Object
{
    private:
	static const CORBA::TypeInfo _class_info;
	Cubit(const Cubit&) {}
	void operator=(const Cubit&){}
    public:
	static const CORBA::TypeInfo *_desc();
	virtual const CORBA::TypeInfo *_type_info() const;
	virtual void *_safe_narrow(const CORBA::TypeInfo& ) const;
	static CORBA::Object *_factory();
    protected:
	Cubit(const char *obj_name = NULL) :CORBA_Object(obj_name, 1) {}
	Cubit(NCistream& strm) :CORBA_Object(strm) {}
	virtual ~Cubit() {}
    public:
	static Cubit_ptr _duplicate(Cubit_ptr obj) {
		if (obj ) obj->_ref();
		return obj;
	}
	static Cubit_ptr _nil() { return (Cubit_ptr)NULL;}
	static Cubit_ptr _narrow(CORBA::Object *obj);
	static Cubit_ptr _clone(Cubit_ptr obj) {
		CORBA::Object_var obj_var(__clone(obj));

#if defined(_HPCC_BUG)
		return _narrow(obj_var.operator CORBA::Object_ptr());
#else
		return _narrow(obj_var);
#endif
	}
	static Cubit_ptr _bind(const char *object_name = NULL,
		const char *host_name = NULL,
		const CORBA::BindOptions* opt = NULL); 

	virtual CORBA::Octet cube_octet(CORBA::Octet o);
	
	virtual CORBA::Short cube_short(CORBA::Short s);
	
	virtual CORBA::Long cube_long(CORBA::Long l);
	
	struct Many {
		CORBA::Octet	o;
		CORBA::Long	l;
		CORBA::Short	s;
	};
	friend NCostream& operator<<(NCostream&, const Many& );
	friend NCistream& operator>>(NCistream&, Many& );
	
	friend ostream& operator<<(ostream&, const Many& );
	inline friend istream& operator>>(istream& _strm, Many& _obj) {
		NCistream _istrm(_strm);
		_istrm >> _obj;
		return _strm;
	}
	
	
	typedef Many *Many_ptr;
	class Many_var
	{
	    public:
		Many_var() { _ptr = (Many*)NULL;}
		Many_var(Many *ptr) {
			_ptr = ptr;
		}
		Many_var(const Many_var& var) {
			if (var._ptr)
				_ptr = new Many(*var._ptr);
			else
				_ptr = (Many *)NULL;
		}
		~Many_var() {
			if (_ptr != (Many *)NULL) delete _ptr;
		}
		Many_var& operator=(Many *ptr) {
			if (_ptr != (Many *)NULL) delete _ptr;
			_ptr = ptr;
			return *this;
		}
		Many_var& operator=(const Many_var& var) {
			if (_ptr != (Many *)NULL) delete _ptr;
			if (var._ptr)
				_ptr = new Many(*var._ptr);
			else
				_ptr = (Many *)NULL;
			return *this;
		}
		Many *operator->() { return _ptr; }
		operator Many () const { return *_ptr; }
		operator Many& () { return *_ptr; }
		inline friend NCostream& operator<<(NCostream& strm,
				const Many_var& var) {
			if (var._ptr == (Many *)NULL) {
				throw CORBA::BAD_PARAM();
			}
			else
				strm << *var._ptr;
			return strm;
		}
		inline friend NCistream& operator>>(NCistream& strm,
				Many_var& var) {
			if ( ! var._ptr)
				var._ptr = new Many;
			strm >> *var._ptr;
			return strm;
		}
	    private:
		Many *_ptr;
	};
	
	
	virtual Cubit::Many cube_struct(const Cubit::Many& values);
	
	enum discrim {
		e_0th,
		e_1st,
		e_2nd,
		e_3rd,
		e_4th,
		e_5th
	};
	inline friend NCostream& operator<<(NCostream& _strm, discrim _enum_type) {
		_strm << (CORBA::ULong)_enum_type;
		return _strm;
	}
	inline friend NCistream& operator>>(NCistream& _strm, discrim& _enum_type) {
		CORBA::ULong _temp;
		_strm >> _temp;
		if (_temp >= 6)
			throw CORBA::BAD_PARAM();
		_enum_type = discrim(_temp);
		return _strm;
	}
	inline friend ostream& operator<<(ostream& _strm, discrim _enum_type) {
		if( &_strm == &cout || &_strm == &cerr || &_strm == &clog) {
			_strm << "discrim:";
			switch(_enum_type) {
				case e_0th:
					_strm << "e_0th" << endl;
					break;
				case e_1st:
					_strm << "e_1st" << endl;
					break;
				case e_2nd:
					_strm << "e_2nd" << endl;
					break;
				case e_3rd:
					_strm << "e_3rd" << endl;
					break;
				case e_4th:
					_strm << "e_4th" << endl;
					break;
				case e_5th:
					_strm << "e_5th" << endl;
					break;
			}
		}
		else 
			_strm << (CORBA::ULong)_enum_type;
		return _strm;
	}
	inline friend istream& operator>>(istream& _strm, discrim& _enum_type) {
		CORBA::ULong _temp;
		_strm >> _temp;
		_enum_type = discrim(_temp);
		return _strm;
	}
	
	
	class oneof
	{
	    public:
	    private:
		discrim	_disc;
		CORBA::Octet	__o;
		CORBA::Short	__s;
		CORBA::Long	__l;
		Cubit::Many	__cm;
	    public:
		oneof() : _disc(discrim(0)) {}
		~oneof() {}
		oneof(const oneof& obj);
		oneof& operator=(const oneof& obj);
	
		void _d(discrim val) { _disc = val; }
		discrim _d() const { return _disc; }
	
		void o(CORBA::Octet val) {
			__o = val;
			_disc = Cubit::e_0th;
		}
		CORBA::Octet o() const { return __o; }
	
		void s(CORBA::Short val) {
			__s = val;
			_disc = Cubit::e_1st;
		}
		CORBA::Short s() const { return __s; }
	
		void l(CORBA::Long val) {
			__l = val;
			_disc = Cubit::e_2nd;
		}
		CORBA::Long l() const { return __l; }
	
		void cm(const Cubit::Many& val) {
			__cm = val;
			_disc = Cubit::e_3rd;
		}
		const Cubit::Many& cm() const { return __cm; }
		Cubit::Many& cm() { return __cm; }
	
		friend NCostream& operator<<(NCostream&, const oneof& );
		friend NCistream& operator>>(NCistream&, oneof& );
		friend ostream& operator<<(ostream&, const oneof&);
		inline friend istream& operator>>(istream& strm, oneof& obj) {
			NCistream istrm(strm);
			strm >> obj;
			return strm;
		}
	};
	
	typedef oneof *oneof_ptr;
	class oneof_var
	{
	    public:
		oneof_var() { _ptr = (oneof*)NULL;}
		oneof_var(oneof *ptr) {
			_ptr = ptr;
		}
		oneof_var(const oneof_var& var) {
			_ptr = new oneof(*var._ptr);
		}
		~oneof_var() {
			if (_ptr != (oneof *)NULL) delete _ptr;
		}
		oneof_var& operator=(oneof *ptr) {
			if (_ptr != (oneof *)NULL) delete _ptr;
			_ptr = ptr;
			return *this;
		}
		oneof_var& operator=(const oneof_var& var) {
			if (_ptr != (oneof *)NULL) delete _ptr;
			_ptr = new oneof(*var._ptr);
			return *this;
		}
		oneof *operator->() { return _ptr; }
		operator oneof () const { return *_ptr; }
		operator oneof& () { return *_ptr; }
		inline friend NCostream& operator<<(NCostream& strm,
				const oneof_var& var) {
			if (var._ptr == (oneof *)NULL) {
				throw CORBA::BAD_PARAM();
			}
			else
				strm << *var._ptr;
			return strm;
		}
		inline friend NCistream& operator>>(NCistream& strm,
				oneof_var& var) {
			if ( ! var._ptr)
				var._ptr = new oneof;
			strm >> *var._ptr;
			return strm;
		}
	    private:
		oneof *_ptr;
	};
	
	
	virtual Cubit::oneof cube_union(const Cubit::oneof& values);
	
	virtual void please_exit();
	
	inline friend NCistream& operator>>(NCistream& strm, Cubit_ptr& obj) {
		CORBA::Object_var _obj(obj);
		_obj = CORBA::Object::_read(strm, Cubit::_desc());
		obj = Cubit::_narrow(_obj);
		return strm;
	}
	inline friend ostream& operator<<(ostream& strm, const Cubit_ptr obj) {
		strm << (CORBA::Object_ptr)obj;
		return strm;
	}
	inline friend istream& operator>>(istream& strm, Cubit_ptr& obj) {
		NCistream istrm(strm);
		istrm >> obj;
		return strm;
	}
};


#endif

