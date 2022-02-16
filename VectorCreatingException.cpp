#include "stdafx.h"
#include "VectorCreatingException.h"

//***********************************************************************************
VectorCreatingException::VectorCreatingException() 
	: VectorException::VectorException(),
	  CreatingException::CreatingException()
{

}
//***********************************************************************************
VectorCreatingException::VectorCreatingException(const std::string &description)
	: VectorException::VectorException(description),
	  CreatingException::CreatingException(description)
{

}
//***********************************************************************************
VectorCreatingException::VectorCreatingException(Exception * const cause)
	: VectorException::VectorException(cause),
	  CreatingException::CreatingException(cause)
{

}
//***********************************************************************************
VectorCreatingException::VectorCreatingException(
	const std::string &description, Exception * const cause)
	: VectorException::VectorException(description, cause),
	  CreatingException::CreatingException(description, cause)
{

}
//***********************************************************************************
VectorCreatingException::~VectorCreatingException()
{

}
//***********************************************************************************