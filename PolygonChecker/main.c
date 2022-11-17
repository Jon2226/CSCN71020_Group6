// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

#include "main.h"
#include "triangleSolver.h"
#include <stdio.h>
#include <stdbool.h>

#define SIDES_PER_TRIANGLE 3    // no magic values!

// int side = 0;		// not sure what this was for...
int main()
{
	bool continueProgram = true;
	while (continueProgram)
	{
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			puts("Triangle selected.\n");
			double triangleSides[SIDES_PER_TRIANGLE] = { 0, 0, 0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);

            puts("Reading the side lengths as follows:\n");
            for (int i = 0; i < SIDES_PER_TRIANGLE; i++)
			    printf("! %g\n", triangleSidesPtr[i]);

			char* result = analyzeTriangle(triangleSidesPtr);
			
			puts(result);
            puts("\n");
			break;

		case 0:
			continueProgram = false;
			break;

		default:
			puts("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome()
{
	puts("\n");
	puts(" **********************\n");
	puts("**     Welcome to     **\n");
	puts("**   Polygon Checker  **\n");
	puts(" **********************\n\n");
}

int printShapeMenu()
{
	puts("1. Triangle\n");
	puts("0. Exit\n");

	int shapeChoice;
	puts("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

double* getTriangleSides(double* triangleSides)
{
	puts("Enter the three side lengths of the triangle: ");
	for (int i = 0; i < SIDES_PER_TRIANGLE; i++)
	{
		scanf_s("%lf", &triangleSides[i]);
	}
	return triangleSides;
}
