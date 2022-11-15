// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

#include "triangleSolver.h"
#include <stdio.h>
#include <stdbool.h>

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

bool findAngles(double* sides, double* angles)
{


    return true;
}
