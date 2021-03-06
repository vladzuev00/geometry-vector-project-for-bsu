#ifndef ELEMENTSGENERATORUPDATINGEXCEPTION_H
#define ELEMENTSGENERATORUPDATINGEXCEPTION_H

#include "ElementsGeneratorException.h"
#include "UpdatingException.h"

//***********************************************************************
class ElementsGeneratorUpdatingException : public ElementsGeneratorException,
	public UpdatingException
{
public:
	ElementsGeneratorUpdatingException();
	ElementsGeneratorUpdatingException(const std::string &description);
	ElementsGeneratorUpdatingException(Exception * const cause);
	ElementsGeneratorUpdatingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~ElementsGeneratorUpdatingException() override;
};
//***********************************************************************

#endif ELEMENTSGENERATORUPDATINGEXCEPTION_H
