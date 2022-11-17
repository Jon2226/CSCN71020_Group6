// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// user interface implementation for polygon checker

#include "interface.h"
#include "input.h"

#define SIDES_PER_TRIANGLE  3    // no magic values!
#define MAX_BUF             30   // max input length for fgets()

void printWelcome()
{
    puts(" **********************\n");
    puts("**     Welcome to     **\n");
    puts("**   Polygon Checker  **\n");
    puts(" **********************\n\n");
}

int printShapeMenu()
{
    puts("1. Triangle\n");
    puts("0. Exit\n");

    double shapeChoice = 0;
    puts("Enter number: ");
    scanf_s("%lf", &shapeChoice);       // scanf bad

    // harrison
    // promptAndGetDoubleInput(char* prompt, double* userInput)

    return (int)shapeChoice;
}

double* getTriangleSides(double* triangleSides)
{
    puts("Enter the three side lengths of the triangle: ");
    for (int i = 0; i < SIDES_PER_TRIANGLE; i++)
    {
        scanf_s("%lf", &triangleSides[i]);    // very unsafe input
        // better input

    // harrison
        // promptAndGetDoubleInput(char* prompt, double* userInput)
    }
    return triangleSides;
}

// take x and y points from user
bool getPoints(double* xValues, double* yValues)
{

}
