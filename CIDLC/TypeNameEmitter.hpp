// file      : CIDLC/TypeNameEmitter.hpp
// author    : Jeff Parsons <j.parsons@vanderbilt.edu>
// cvs-id    : $Id$

#ifndef TYPENAME_EMITTER_HPP
#define TYPENAME_EMITTER_HPP

#include "CCF/CIDL/SemanticGraph.hpp"
#include "CCF/CIDL/Traversal.hpp"

using namespace CCF::CIDL;
using namespace CCF::CIDL::SemanticGraph;

// Base class that holds the ostream member
// common to every other class in this file,
// and collects the ancestors in one place.
//
class TypeNameEmitter : public Traversal::Void,
                        public Traversal::Boolean,
                        public Traversal::Octet,
                        public Traversal::Char,
                        public Traversal::Wchar,
                        public Traversal::Short,
                        public Traversal::UnsignedShort,
                        public Traversal::Long,
                        public Traversal::UnsignedLong,
                        public Traversal::LongLong,
                        public Traversal::UnsignedLongLong,
                        public Traversal::Float,
                        public Traversal::Double,
                        public Traversal::String,
                        public Traversal::Wstring,
                        public Traversal::Object,
                        public Traversal::ValueBase,
                        public Traversal::Any,
                        public Traversal::Struct,
                        public Traversal::UnboundedSequence,
                        public Traversal::Interface,
                        public Traversal::ValueType,
                        public Traversal::EventType,
                        public Traversal::Component
{
protected:
  TypeNameEmitter (std::ostream&);

  std::ostream& os;
};

// Generates the name of an operation's return type.
//
//
class ReturnTypeNameEmitter : public TypeNameEmitter
{
public:
  ReturnTypeNameEmitter (std::ostream&);

  virtual void traverse (Void&);
  virtual void traverse (Boolean&);
  virtual void traverse (Octet&);
  virtual void traverse (Char&);
  virtual void traverse (Wchar&);
  virtual void traverse (Short&);
  virtual void traverse (UnsignedShort&);
  virtual void traverse (Long&);
  virtual void traverse (UnsignedLong&);
  virtual void traverse (LongLong&);
  virtual void traverse (UnsignedLongLong&);
  virtual void traverse (Float&);
  virtual void traverse (Double&);
  virtual void traverse (String&);
  virtual void traverse (Wstring&);
  virtual void traverse (Object&);
  virtual void traverse (ValueBase&);
  virtual void traverse (Any&);
  virtual void traverse (SemanticGraph::Struct&);
  virtual void traverse (SemanticGraph::UnboundedSequence&);
  virtual void traverse (SemanticGraph::Interface&);
  virtual void traverse (SemanticGraph::ValueType&);
  virtual void traverse (SemanticGraph::EventType&);
  virtual void traverse (SemanticGraph::Component&);
};

// Generates the typename of an IN argument.
//
//
class INArgTypeNameEmitter : public TypeNameEmitter
{
public:
  INArgTypeNameEmitter (std::ostream&);

  virtual void traverse (Void&);
  virtual void traverse (Boolean&);
  virtual void traverse (Octet&);
  virtual void traverse (Char&);
  virtual void traverse (Wchar&);
  virtual void traverse (Short&);
  virtual void traverse (UnsignedShort&);
  virtual void traverse (Long&);
  virtual void traverse (UnsignedLong&);
  virtual void traverse (LongLong&);
  virtual void traverse (UnsignedLongLong&);
  virtual void traverse (Float&);
  virtual void traverse (Double&);
  virtual void traverse (String&);
  virtual void traverse (Wstring&);
  virtual void traverse (Object&);
  virtual void traverse (ValueBase&);
  virtual void traverse (Any&);
  virtual void traverse (SemanticGraph::Struct&);
  virtual void traverse (SemanticGraph::UnboundedSequence&);
  virtual void traverse (SemanticGraph::Interface&);
  virtual void traverse (SemanticGraph::ValueType&);
  virtual void traverse (SemanticGraph::EventType&);
  virtual void traverse (SemanticGraph::Component&);
};

// Generates the typename of an INOUT argument.
//
//
class INOUTArgTypeNameEmitter : public TypeNameEmitter
{
public:
  INOUTArgTypeNameEmitter (std::ostream&);

  virtual void traverse (Void&);
  virtual void traverse (Boolean&);
  virtual void traverse (Octet&);
  virtual void traverse (Char&);
  virtual void traverse (Wchar&);
  virtual void traverse (Short&);
  virtual void traverse (UnsignedShort&);
  virtual void traverse (Long&);
  virtual void traverse (UnsignedLong&);
  virtual void traverse (LongLong&);
  virtual void traverse (UnsignedLongLong&);
  virtual void traverse (Float&);
  virtual void traverse (Double&);
  virtual void traverse (String&);
  virtual void traverse (Wstring&);
  virtual void traverse (Object&);
  virtual void traverse (ValueBase&);
  virtual void traverse (Any&);
  virtual void traverse (SemanticGraph::Struct&);
  virtual void traverse (SemanticGraph::UnboundedSequence&);
  virtual void traverse (SemanticGraph::Interface&);
  virtual void traverse (SemanticGraph::ValueType&);
  virtual void traverse (SemanticGraph::EventType&);
  virtual void traverse (SemanticGraph::Component&);
};

// Generates the typename of an OUT argument.
//
//
class OUTArgTypeNameEmitter : public TypeNameEmitter
{
public:
  OUTArgTypeNameEmitter (std::ostream&);

  virtual void traverse (Void&);
  virtual void traverse (Boolean&);
  virtual void traverse (Octet&);
  virtual void traverse (Char&);
  virtual void traverse (Wchar&);
  virtual void traverse (Short&);
  virtual void traverse (UnsignedShort&);
  virtual void traverse (Long&);
  virtual void traverse (UnsignedLong&);
  virtual void traverse (LongLong&);
  virtual void traverse (UnsignedLongLong&);
  virtual void traverse (Float&);
  virtual void traverse (Double&);
  virtual void traverse (String&);
  virtual void traverse (Wstring&);
  virtual void traverse (Object&);
  virtual void traverse (ValueBase&);
  virtual void traverse (Any&);
  virtual void traverse (SemanticGraph::Struct&);
  virtual void traverse (SemanticGraph::UnboundedSequence&);
  virtual void traverse (SemanticGraph::Interface&);
  virtual void traverse (SemanticGraph::ValueType&);
  virtual void traverse (SemanticGraph::EventType&);
  virtual void traverse (SemanticGraph::Component&);
};

#endif /* TYPENAME_EMITTER_HPP */
