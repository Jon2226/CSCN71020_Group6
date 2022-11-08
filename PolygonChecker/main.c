// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

#include "main.h"
#include "triangleSolver.h"
#include <stdio.h>
#include <stdbool.h>

#define SIDES_PER_TRIANGLE 3

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
			printf_s("Triangle selected.\n");
			int triangleSides[SIDES_PER_TRIANGLE] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);

			char* result = 
				analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome()
{
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n\n");
}

int printShapeMenu()
{
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides)
{
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < SIDES_PER_TRIANGLE; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}
