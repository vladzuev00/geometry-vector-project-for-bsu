#ifndef ELEMENTSGENERATORCREATINGEXCEPTION_H
#define ELEMENTSGENERATORCREATINGEXCEPTION_H

#include "ElementsGeneratorException.h"
#include "CreatingException.h"

//************************************************************************
class ElementsGeneratorCreatingException : public ElementsGeneratorException,
	public CreatingException
{
public:
	ElementsGeneratorCreatingException();
	ElementsGeneratorCreatingException(const std::string &description);
	ElementsGeneratorCreatingException(Exception * const cause);
	ElementsGeneratorCreatingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~ElementsGeneratorCreatingException() override;
};
//************************************************************************

#endif ELEMENTSGENERATORCREATINGEXCEPTION_H