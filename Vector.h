#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>
#include <string>

//***************************************************************************************
class VectorValidator;
//***************************************************************************************
template<class CoordinateType>
class Vector 
{
private:
	CoordinateType *coordinates;
	unsigned int dimensions;
private:
	void initializeCoordinates(const CoordinateType &valueOfCoordinates);
	void initializeCoordinates(const CoordinateType * const valuesOfCoordinates);
	double findSumOfSquaredCoordinates() const;
private:
	static const CoordinateType DEFAULT_VALUE_OF_COORDINATE;
	static const VectorValidator VECTOR_VALIDATOR;
public:
	Vector(const unsigned int dimensions);
	Vector(const CoordinateType * const coordinates, 
		const unsigned int dimensions);
	Vector(const Vector<CoordinateType> &other);
public:
	unsigned int getDimensions() const;
	bool isColinear(const Vector<CoordinateType> &other) const;
	bool isOrthogonal(const Vector<CoordinateType> &other) const;
	std::string toString() const;
	CoordinateType findScalarMultiply(const Vector<CoordinateType> &other) const;
	double findCosinusOfAngleBetweenVectors(const Vector<CoordinateType> &other) const;
	double findLength() const;
	bool isNullVector() const;
public:
	bool operator==(const Vector<CoordinateType> &other) const;
	const Vector<CoordinateType>& operator=(const Vector<CoordinateType> &other);
	friend std::ostream& operator<<(std::ostream &outputStream,
		const Vector<CoordinateType> &vector);
public:
	~Vector();
};
//***************************************************************************************
class VectorValidator 
{
private:
	static const unsigned int MINIMAL_ALLOWABLE_DIMENSIONS_OF_VECTOR;    //Using interval is better
	static const unsigned int MAXIMAL_ALLOWABLE_DIMENSIONS_OF_VECTOR;
public:
	bool isValidDimensions(const unsigned int researchDimensions) const;
	template<class CoordinateType>
	bool isValidCoordinates(const CoordinateType * const researchCoordinates) const;
};
//***************************************************************************************

#endif VECTOR_H