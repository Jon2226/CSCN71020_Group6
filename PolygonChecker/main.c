// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// main function for polygon checker program, which will take side lengths or 
// (x,y) coordinates from a user, and use them to determine whether the given 
// values can form a polygon, and other information about the polygon formed

#include "polygon.h"
#include "interface.h"
#include "input.h"

#define SIDES_PER_TRIANGLE  3    // no magic values!

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
			puts("\nInvalid value entered.\n");
			break;
		}
	}
	return 0;
}
