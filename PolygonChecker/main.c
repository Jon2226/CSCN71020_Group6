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
    printWelcome();
	bool continueProgram = true;
	while (continueProgram)
	{
        int shapeChoice = printShapeMenu();
		switch (shapeChoice)
		{
        case 0:
            continueProgram = false;
            break;

		case 1:
			puts("Triangle selected.\n");
			double triangleSides[SIDES_PER_TRIANGLE] = { 0, 0, 0 };
			getTriangleSides(triangleSides);        // fix this

            puts("Reading the side lengths as follows:\n");
            for (int i = 0; i < SIDES_PER_TRIANGLE; i++)
			    printf("Side %d: %g\n", i, triangleSides[i]);

			char* result = analyzeTriangle(triangleSides);
			
			puts(result);
            puts("\n");
			break;

		default:
			puts("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}
