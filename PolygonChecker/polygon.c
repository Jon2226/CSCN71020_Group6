// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// implementation of calculation functions for polygon checker

#include "polygon.h"
#include <stdio.h>
#include <math.h>

char* analyzeTriangle(double* sides)
{
	char* result = "";
	if (!isTriangle(sides))     // single function to check this
	{
		result = "Not a triangle";
	}
	else if (sides[0] == sides[1] && sides[0] == sides[2])
	{
		result = "Equilateral triangle";
	}
	else if ((sides[0] == sides[1] && sides[0] != sides[2]) || 
		(sides[0] == sides[2] && sides[0] != sides[1]) || 
		(sides[1] == sides[2] && sides[1] != sides[0]))
	{
		result = "Isosceles triangle";
	}
	else
	{
		result = "Scalene triangle";
	}
	return result;
}

bool isTriangle(double* sides)
{
    // checking for <= 0 should be handled by input validation, but 
    // we will still include this check here... just in case
    if (sides[0] <= 0 || sides[1] <= 0 || sides[2] <= 0)
        return false;

    else if (((sides[0] + sides[1]) > sides[2]) &&
        ((sides[0] + sides[2]) > sides[1]) &&
        ((sides[1] + sides[2]) > sides[0]))
        return true;

    else
        return false;
}

// determine angles based on side lengths
void findAngles(double* sides, double* angles)
{
    // drasti


}

// determine side lengths based on coordinates of points
void findSideLengths(double* xValues, double* yValues, double* sides)
{
    // komal
    // using pythagorean theorem

}

double calculatePerimeter(double* sideLenths, int numSides)
{
    double perimeter = 0;
    for (int i = 0; i < numSides; i++)
        perimeter += sideLenths[i];

    return perimeter;
}
