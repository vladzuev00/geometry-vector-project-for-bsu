#ifndef VECTOREXCEPTION_H
#define VECTOREXCEPTION_H

#include "Exception.h"

//**************************************************************************************
class VectorException : virtual public Exception
{
public:
	VectorException();
	VectorException(const std::string &description);
	VectorException(Exception * const cause);
	VectorException(const std::string &description, Exception * const cause);
public:
	virtual ~VectorException() override;
};
//**************************************************************************************

#endif VECTOREXCEPTION_H