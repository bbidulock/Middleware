// file      : CIDLC/RepositoryIdGenerator.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CIDLC_REPOSITORY_ID_GENERATOR_HPP
#define CIDLC_REPOSITORY_ID_GENERATOR_HPP


//@@ Don't really need this. just forward declaration of
//   TranslationUnit would be enough.
//
#include "CCF/CIDL/SyntaxTree.hpp"

class RepositoryIdGenerator
{
public:
  void
  generate (CCF::CIDL::SyntaxTree::TranslationUnitPtr const&);
};

#endif  // CIDLC_REPOSITORY_ID_GENERATOR_HPP
