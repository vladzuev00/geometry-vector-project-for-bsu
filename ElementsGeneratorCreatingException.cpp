#include "stdafx.h"
#include "ElementsGeneratorCreatingException.h"

//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException() 
	: ElementsGeneratorException::ElementsGeneratorException(),
	  CreatingException::CreatingException()
{

}
//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException(
	const std::string &description)
	: ElementsGeneratorException::ElementsGeneratorException(description),
	  CreatingException::CreatingException(description)
{

}
//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException(
	Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(cause),
	  CreatingException::CreatingException(cause)
{

}
//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException(
	const std::string &description, Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(description, cause),
	  CreatingException::CreatingException(description, cause)
{

}
//************************************************************************
ElementsGeneratorCreatingException::~ElementsGeneratorCreatingException()
{

}
//************************************************************************