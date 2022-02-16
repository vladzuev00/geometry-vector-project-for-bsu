#include "stdafx.h"
#include "VectorException.h"

//**************************************************************************************
VectorException::VectorException() : Exception::Exception()
{

}
//**************************************************************************************
VectorException::VectorException(const std::string &description) 
	: Exception::Exception(description)
{

}
//**************************************************************************************
VectorException::VectorException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//**************************************************************************************
VectorException::VectorException(const std::string &description, Exception * const cause) 
	: Exception::Exception(description, cause)
{

}
//**************************************************************************************
VectorException::~VectorException()
{

}
//**************************************************************************************