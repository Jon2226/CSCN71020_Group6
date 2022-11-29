// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// user interface implementation for polygon checker

#include "polygon.h"
#include "interface.h"
#include "input.h"

#define SIDES_PER_TRIANGLE  3    // no magic values!
#define MAX_BUF             30   // max input length for fgets()

void printWelcome(void)
{
    puts(" **********************\n");
    puts("**     Welcome to     **\n");
    puts("**   Polygon Checker  **\n");
    puts(" **********************\n");
}

void printMainMenu(void)
{
    puts("\nPlease enter a number from the menu below.");
    puts("1. Enter up to 20 side lengths, each separated by a newline.");
    puts("2. Enter up to 20 (x,y) coordinate pairs, each separated by a newline.");
    //puts("3. Enter up to 20 angles (in degrees), each separated by a newline.");
    puts("0. Exit program.\n");
}

bool inputAndHandleMenuResponse(int* numSides, double* sideLengths)
{
    int choice = 0;
    while (!promptAndGetIntegerInput("Please enter a number: ", &choice))
        puts("Invalid menu choice.  Please try again.");

    switch (choice)
    {
    case 0:
        return false;

    case 1:
        *numSides = inputSideLengths(sideLengths);
        // if user cancels, reset side lengths in case they input some
        if (*numSides == 0)
        {
            for (int i = 0; i < MAX_SIDES; i++)
                sideLengths[i] = 0;
            
            break;
        }
        else
            // analyze polygon and display results
            ;

        // parrot the user's input for testing purposes
        puts("\n\nReading the side lengths as follows:");
        for (int i = 0; i < *numSides; i++)
            printf("Side %d: %g\n", i + 1, sideLengths[i]);
        printf("There are %d sides.\n", *numSides);

        puts("\n");
        break;

    case 2:


    case 3:


    default:
        puts("Invalid menu choice.  Please try again");
        break;
    }
    return true;
}

int inputSideLengths(double* sideLengths)
{
    int numSides = 0;
    puts("Please enter up to 20 side lengths.  Enter 0 when done, or -1 to cancel.");
    while (numSides < MAX_SIDES)
    {
        if (!promptAndGetDoubleInput("", &sideLengths[numSides]))
        {
            printf("Invalid side length.  Please try again.");
            numSides--;
        }

        if (sideLengths[numSides] == -1)
            return 0;
        else if (sideLengths[numSides] == 0)
            return numSides;

        numSides++;
    }
    return 0;
}

// take x and y points from user
bool inputPoints(double* xValues, double* yValues)
{

}
