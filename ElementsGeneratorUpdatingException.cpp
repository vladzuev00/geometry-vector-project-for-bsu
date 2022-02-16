#include "stdafx.h"
#include "ElementsGeneratorUpdatingException.h"

//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException() 
	: ElementsGeneratorException::ElementsGeneratorException(),
	  UpdatingException::UpdatingException()
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException(const std::string &description)
	: ElementsGeneratorException::ElementsGeneratorException(description),
	  UpdatingException::UpdatingException(description)
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException(Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(cause),
	  UpdatingException::UpdatingException(cause)
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException(
	const std::string &description, Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(description, cause),
	  UpdatingException::UpdatingException(description, cause)
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::~ElementsGeneratorUpdatingException()
{

}
//***********************************************************************