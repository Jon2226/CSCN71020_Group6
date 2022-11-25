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

bool isPolygon(double* side, int numSides)
{
    // check that all side lengths are more than zero
    for (int i = 0; i < numSides; i++)
        if (side[i] <= 0)
            return false;

    // find sum of all side lengths, and length of longest side
    double sum = 0;
    double longest = 0;
    for (int i = 0; i < numSides; i++)
    {
        sum += side[i];
        // longest = longest < side[i] ? side[i] : longest;
        if (longest < side[i])
            longest = side[i];
    }

    // check that longest side is less than the sum of the others.  
    // if so, they can form a polygon.
    if (longest < (sum - longest))
        return true;

    return false;
}

bool isRegular(double* side, int numSides)
{
    // return true if all side lengths are the same
    int side0 = side[0];
    for (int i = 1; i < numSides; i++)
        if (side[i] != side[0])
            return false;

    return true;
}

char* findPolygonName(int numSides)
{
    switch (numSides)
    {
    case 3:
        return "triangle";
    case 4:
        return "quadrilateral";
    case 5:
        return "pentagon";
    case 6:
        return "hexagon";
    case 7:
        return "septagon";
    case 8:
        return "octagon";
    case 9:
        return "nonagon";
    case 10:
        return "decagon";
    case 11:
        return "hendecagon";
    case 12:
        return "dodecagon";
    case 13:
        return "tridecagon";
    case 14:
        return "tetradecagon";
    case 15:
        return "pentadecagon";
    case 16:
        return "hexadecagon";
    case 17:
        return "heptadecagon";
    case 18:
        return "octadecagon";
    case 19:
        return "enneadecagon";
    case 20:
        return "icosagon";
    default:
        return "";
    }
}

char* findPolygonDescription()
{
    // by calling analyzeTriangle and analyzeQuadrilateral
}

double findRegularAngles(int numSides)
{
    double numberOfSides = numSides;
    return ((double)180 * (numberOfSides - (double)2) / numberOfSides);
}
