// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi       

// implementation of calculation functions for polygon checker

#include "polygon.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

POLYGON createPolygon(int numSides, double* sides, double* angles,
    bool regular, char* name, char* description)
{
    POLYGON p;
    p.numSides = numSides;
    // pass arrays

    p.regular = regular;
    p.name = name;
    p.description = description;
    return p;
}

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

char* analyzeQuadrilateral(double* sides, double* angles)
{
    int numEquivalentSides = 0;
    int numEquivalentAngles = 0;

    return "";
}

// redundant legacy function
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


double radiansToDegrees(double rad)
{
    return rad * (180.0 / acos(-1));
}

// determine angles based on side lengths
void findAngles(double* sides, double* angles)
{
    angles[0] = radiansToDegrees(acos((pow(sides[1], 2) + pow(sides[2], 2) - pow(sides[0], 2)) / (2 * sides[1] * sides[2])));

    angles[1] = radiansToDegrees(acos((pow(sides[0], 2) + pow(sides[2], 2) - pow(sides[1], 2)) / (2 * sides[0] * sides[2])));

    angles[2] = radiansToDegrees(acos((pow(sides[0], 2) + pow(sides[1], 2) - pow(sides[2], 2)) / (2 * sides[0] * sides[1])));

    printf("Angles: %lf  %lf  %lf \n\n\n", angles[0], angles[1], angles[2]);
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
    double side0 = side[0];
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

    return "";
}

double findRegularAngles(int numSides)
{
    double numberOfSides = numSides;
    return ((double)180 * (numberOfSides - (double)2) / numberOfSides);
}

bool pointsMatch(double* xValues, double* yValues, int numSides)
{
    for (int i = 0; i < numSides; i++)
        for (int j = i + 1; j < numSides; j++)
            if (xValues[i] == xValues[j])
                if (yValues[i] == yValues[j])
                    return true;

    return false;
}

void printPolygonInfo(POLYGON* p)
{
    // if pointsMatch, do not print coordinates because it likely means that
    // they are still zeroed because they have not been given by the user
    if (!pointsMatch(p->xValues, p->yValues, p->numSides))
        ;// print coordinates
}
