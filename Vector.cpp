#include "stdafx.h"
#include "Vector.h"
#include <climits>
#include "VectorCreatingException.h"
#include "UnsupportedOperationException.h"
#include <iostream>       //TODO: delete

//*****************************************Vector**********************************************
template class Vector<double>;       //убрать кастыль
//***************************************************************************************
template<class CoordinateType>
Vector<CoordinateType>::Vector(const unsigned int dimensions)
{
	if (!Vector<CoordinateType>::VECTOR_VALIDATOR.isValidDimensions(dimensions)) 
	{
		throw new VectorCreatingException("Impossible to create vector "
			"with given 'dimensions'. Given 'dimensions' = " + std::to_string(dimensions));
	}
	this->dimensions = dimensions;
	this->coordinates = new CoordinateType[dimensions];
	this->initializeCoordinates(Vector<CoordinateType>::DEFAULT_VALUE_OF_COORDINATE);
}
//***************************************************************************************
template<class CoordinateType>
const VectorValidator Vector<CoordinateType>::VECTOR_VALIDATOR = VectorValidator();
//***************************************************************************************
template<class CoordinateType>
const CoordinateType Vector<CoordinateType>::DEFAULT_VALUE_OF_COORDINATE = 0.0;
//***************************************************************************************
template<class CoordinateType>
void Vector<CoordinateType>::initializeCoordinates(const CoordinateType &valueOfCoordinates) 
{
	for (int i = 0; i < this->dimensions; i++) 
	{
		*(this->coordinates + i) = valueOfCoordinates;
	}
}
//***************************************************************************************
template<class CoordinateType>
Vector<CoordinateType>::Vector(const CoordinateType * const coordinates,
	const unsigned int dimensions) 
{
	if (!Vector<CoordinateType>::VECTOR_VALIDATOR.
		isValidCoordinates<CoordinateType>(coordinates))
	{
		throw new VectorCreatingException("Impossible to create vector"
			" with given 'coordinates'.");  //как-нибудь представить пользователю невалидные координаты
	}
	if (!Vector<CoordinateType>::VECTOR_VALIDATOR.isValidDimensions(dimensions))
	{
		throw new VectorCreatingException("Impossible to create vector "
			"with given 'dimensions'. Given 'dimensions' = " 
			+ std::to_string(dimensions));
	}
	this->dimensions = dimensions;
	this->coordinates = new CoordinateType[dimensions];
	this->initializeCoordinates(coordinates);
}
//***************************************************************************************
template<class CoordinateType>
void Vector<CoordinateType>::initializeCoordinates(
	const CoordinateType * const valuesOfCoordinates)
{
	for (int i = 0; i < this->dimensions; i++)
	{
		*(this->coordinates + i) = *(valuesOfCoordinates + i);
	}
}
//***************************************************************************************
template<class CoordinateType>
Vector<CoordinateType>::Vector(const Vector<CoordinateType> &other)
{
	this->dimensions = other.dimensions;
	this->coordinates = new CoordinateType[other.dimensions];
	this->initializeCoordinates(other.coordinates);
}
//***************************************************************************************
template<class CoordinateType>
unsigned int Vector<CoordinateType>::getDimensions() const
{
	return this->dimensions;
}
//***************************************************************************************
template<class CoordinateType>
bool Vector<CoordinateType>::isColinear(const Vector<CoordinateType> &other) const
{
	if (this->dimensions != other.dimensions)
	{
		throw new UnsupportedOperationException("Impossible to check two vectors "
			"with different 'dimensions' are colinear or not. "
			"\n\tFirst given vector: " + this->toString() 
			+ ",\n\tSecond given vector: " + other.toString());
	}
	if (this->dimensions == 1) 
	{
		return true;
	}
	double cosinusOfAngleBetweenVectors 
		= this->findCosinusOfAngleBetweenVectors(other);
	std::cout << "cosinusOfAngleBetweenVectors = " << cosinusOfAngleBetweenVectors << std::endl;  //TODO: delete
	return cosinusOfAngleBetweenVectors == -1 
		&& cosinusOfAngleBetweenVectors == 1;
}
//***************************************************************************************
template<class CoordinateType>
bool Vector<CoordinateType>::isOrthogonal(const Vector<CoordinateType> &other) const
{
	if (this->dimensions != other.dimensions)
	{
		throw new UnsupportedOperationException("Impossible to check two vectors "
			"with different 'dimensions' are orthogonal or not. "
			"\n\tFirst given vector: " + this->toString()
			+ ",\n\tSecond given vector: " + other.toString());
	}
	if (this->dimensions == 1) 
	{
		return false;
	}
	return this->findScalarMultiply(other) == 0;
}
//***************************************************************************************
template<class CoordinateType>
std::string Vector<CoordinateType>::toString() const
{
	std::string vectorDescription = "(";
	const std::string separatorOfElements = ", ";
	for (int i = 0; i < this->dimensions; i++)
	{
		vectorDescription.append(std::to_string(*(this->coordinates + i)));
		vectorDescription.append(i != this->dimensions - 1
			? separatorOfElements : ")");
	}
	return vectorDescription;
}
//***************************************************************************************
template<class CoordinateType>
CoordinateType Vector<CoordinateType>::findScalarMultiply(
	const Vector<CoordinateType> &other) const
{
	if (this->dimensions != other.dimensions)
	{
		throw new UnsupportedOperationException("Impossible to find scalar "
			"multiply of two vectors with different 'dimensions'. "
			"\n\tFirst given vector: " + this->toString()
			+ ",\n\tSecond given vector: " + other.toString());
	}
	CoordinateType scalarMultiply = 0.0;
	for (int i = 0; i < this->dimensions; i++) 
	{
		scalarMultiply += *(this->coordinates + i) * *(other.coordinates + i);
	}
	return scalarMultiply;
}
//***************************************************************************************
template<class CoordinateType>
double Vector<CoordinateType>::findCosinusOfAngleBetweenVectors(
	const Vector<CoordinateType> &other) const
{
	if (this->dimensions != other.dimensions) 
	{
		throw new UnsupportedOperationException("Impossible to find scalar "
			"multiply of two vectors with different 'dimensions'. "
			"\n\tFirst given vector: " + this->toString()
			+ ",\n\tSecond given vector: " + other.toString());
	}
	if (this->isNullVector())
	{
		throw new UnsupportedOperationException(
			"Impossible to find cosinus of angle between two vectors, "
			"because length of one of them is 0. \n\tGiven null vector: " 
			+ this->toString());
	}
	else if(other.isNullVector())
	{
		throw new UnsupportedOperationException(
			"Impossible to find cosinus of angle between two vectors, "
			"because length of one of them is 0. \n\tGiven null vector: "
			+ other.toString());
	}
	std::cout << "scalar multiply = " << this->findScalarMultiply(other) << std::endl;  //TODO: delete
	std::cout << "length a = " << this->findLength() << std::endl;     //TODO: delete
	std::cout << "length b = " << other.findLength() << std::endl;      //TODO: delete
	double cosinusOfAngleBetweenVectors
		= this->findScalarMultiply(other) 
		/ (this->findLength() * other.findLength()); 
	return cosinusOfAngleBetweenVectors;
}
//***************************************************************************************
template<class CoordinateType>
double Vector<CoordinateType>::findLength() const 
{
	if (this->dimensions == 1) 
	{
		return *this->coordinates;
	}
	std::cout << "std::sqrt(findSumOfSquaredCoordinates()) = " 
		<< std::sqrt(findSumOfSquaredCoordinates()) << std::endl;  //TODO: delete
	double a = std::sqrt(findSumOfSquaredCoordinates());    //TODO: delete
	return std::sqrt(findSumOfSquaredCoordinates());
}
//***************************************************************************************
template<class CoordinateType>
double Vector<CoordinateType>::findSumOfSquaredCoordinates() const
{
	double sumOfSquaredCoordinates = 0;
	for (int i = 0; i < this->dimensions; i++)
	{
		sumOfSquaredCoordinates += *(this->coordinates + i)
			* *(this->coordinates + i);
	}
	return sumOfSquaredCoordinates;
}
//***************************************************************************************
template<class CoordinateType>
bool Vector<CoordinateType>::isNullVector() const 
{
	return !this->findLength();
}
//***************************************************************************************
template<class CoordinateType>
bool Vector<CoordinateType>::operator==(const Vector<CoordinateType> &other) const
{
	if (this == &other) 
	{
		return true;
	}
	if (this->dimensions != other.dimensions) 
	{
		return false;
	}
	for (int i = 0; i < this->dimensions; i++) 
	{
		if (*(this->coordinates + i) != *(other.coordinates + i))
		{
			return false;
		}
	}
	return true;
}
//***************************************************************************************
template<class CoordinateType>
const Vector<CoordinateType>& Vector<CoordinateType>::operator=(
	const Vector<CoordinateType> &other)
{
	if (this == &other) 
	{
		return *this;
	}
	delete[] this->coordinates;
	this->dimensions = other.dimensions;
	this->coordinates = new CoordinateType[other.dimensions];
	this->initializeCoordinates(other.coordinates);
	return *this;
}
//***************************************************************************************
template
std::ostream& operator<<(std::ostream &outputStream,
	const Vector<double> &vector);    //TODO: убрать кастыль
//***************************************************************************************
template<class CoordinateType>
std::ostream& operator<<(std::ostream &outputStream,
	const Vector<CoordinateType> &vector) 
{
	outputStream << vector.toString() << "\n";
	return outputStream;
}
//***************************************************************************************
template<class CoordinateType>
Vector<CoordinateType>::~Vector() 
{
	delete[] this->coordinates;
}
//************************************VectorValidator***************************************************
bool VectorValidator::isValidDimensions(const unsigned int researchDimensions) const
{
	return VectorValidator::MINIMAL_ALLOWABLE_DIMENSIONS_OF_VECTOR <= researchDimensions
		&& researchDimensions <= VectorValidator::MAXIMAL_ALLOWABLE_DIMENSIONS_OF_VECTOR;
}
//***************************************************************************************
const unsigned int VectorValidator::MINIMAL_ALLOWABLE_DIMENSIONS_OF_VECTOR = 1;
//***************************************************************************************
const unsigned int VectorValidator::MAXIMAL_ALLOWABLE_DIMENSIONS_OF_VECTOR = UINT_MAX;
//***************************************************************************************
template<class CoordinateType>
bool VectorValidator::isValidCoordinates(
	const CoordinateType * const researchCoordinates) const 
{
	return researchCoordinates;
}
//***************************************************************************************