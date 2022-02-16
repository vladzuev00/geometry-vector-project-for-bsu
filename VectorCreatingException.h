#ifndef VECTORCREATINGEXCEPTION_H
#define VECTORCREATINGEXCEPTION_H

#include "VectorException.h"
#include "CreatingException.h"

//***********************************************************************************
class VectorCreatingException : public VectorException, public CreatingException
{
public:
	VectorCreatingException();
	VectorCreatingException(const std::string &description);
	VectorCreatingException(Exception * const cause);
	VectorCreatingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~VectorCreatingException() override;
};
//***********************************************************************************

#endif VECTORCREATINGEXCEPTION_H