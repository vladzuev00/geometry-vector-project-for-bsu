// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Vector.h"
#include "ElementsGenerator.h"

using namespace std;

int main()
{
	const double minimalValueOfCoordinateOfVectors = -100;
	const double maximalValueOfCoordinateOfVectors = 100;
	ElementsGenerator<double> *generatorOfValuesOfCoordinatesOfVector 
		= new ElementsGenerator<double>(minimalValueOfCoordinateOfVectors,
			maximalValueOfCoordinateOfVectors);
	const unsigned int dimensionsOfVectors = 5;
	const unsigned int amountOfVectors = 20;
	Vector<double> **vectors = new Vector<double>*[amountOfVectors];
	double *coordinatesOfVector;
	for (int i = 0; i < amountOfVectors; i++) 
	{
		coordinatesOfVector = generatorOfValuesOfCoordinatesOfVector
			->generateElements(dimensionsOfVectors);
		*(vectors + i) = new Vector<double>(coordinatesOfVector, dimensionsOfVectors);
		delete[] coordinatesOfVector;
	}
	delete generatorOfValuesOfCoordinatesOfVector;


	for (int i = 0; i < amountOfVectors - 1; i++) 
	{
		for (int j = 0; j < amountOfVectors; j++)
		{
			cout << (*(vectors + i))->toString() << " and " << (*(vectors + j))->toString()
				<< " are colinear, that statement is " 
				<< (*(vectors + i))->isColinear(*(*(vectors + j))) << endl;
			cout << (*(vectors + i))->toString() << " and " << (*(vectors + j))->toString()
				<< " are orthogonal, that statement is "
				<< (*(vectors + i))->isOrthogonal(*(*(vectors + j))) << endl;
		}
	}

	for (int i = 0; i < amountOfVectors; i++) 
	{
		delete *(vectors + i);
	}
	delete[] vectors;

	system("PAUSE");
    return EXIT_SUCCESS;
}

