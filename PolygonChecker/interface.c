// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// user interface implementation for polygon checker

#include "polygon.h"
#include "interface.h"
#include "input.h"

#define SIDES_PER_TRIANGLE       3    // no magic values!
#define MAX_BUF                 30    // max input length for fgets()

void printWelcome(void)
{
    puts(" **********************\n");
    puts("**     Welcome to     **\n");
    puts("**   Polygon Checker  **\n");
    puts(" **********************\n");
}

void printMainMenu(void)
{
    puts("________________________________________________________________________________");
    puts("\nPlease enter a number from the menu below.");
    puts("1. Enter up to 20 side lengths, each separated by a newline.");
    puts("2. Enter up to 20 (x,y) coordinate pairs, each separated by a newline.");
    //puts("3. Enter up to 20 angles (in degrees), each separated by a newline.");
    puts("0. Exit program.\n");
}

bool runMainMenu(int* numSides, double* sideLengths, double* angles, 
    point* coordinates)
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
            for (size_t i = 0; i < MAX_SIDES; i++)
                sideLengths[i] = 0;

            break;
        }
        // parrot the user's input for testing purposes
        puts("\n\nReading the side lengths as follows:");
        for (size_t i = 0; i < *numSides; i++)
            printf("Side %d: %g\n", (int)i + 1, sideLengths[i]);
        puts("\n");
        
        printf("There are %d sides.\n", *numSides);
        // analyze polygon and display results
        analyzePolygon(numSides, sideLengths, angles, coordinates);

        break;

    case 2:
        *numSides = inputPoints(coordinates);
        // if user cancels, reset points in case they input some
        if (*numSides == 0)
        {
            for (size_t i = 0; i < MAX_SIDES; i++)
            {
                coordinates[i].x = 0;
                coordinates[i].y = 0;
            }
            break;
        }

        // parrot the user's input for testing purposes
        puts("\n\nReading the coordinates as follows:");
        for (size_t i = 0; i < *numSides; i++)
            printf("Point %d: (%g, %g)\n", (int)i + 1, coordinates[i].x, 
                coordinates[i].y);
        puts("\n");
        
        printf("There are %d points.\n", *numSides);
        // analyze polygon and display results
        analyzePolygon(numSides, sideLengths, angles, coordinates);

    //case 3:
        // nothing yet

    default:
        puts("Invalid menu choice.  Please try again");
        break;
    }
    return true;
}

int inputSideLengths(double* sideLengths)
{
    int numSides = 0;
    int status = -1;
    puts("Please enter up to 20 side lengths.  Enter F when finished, or C to cancel.");
    while (numSides < MAX_SIDES)
    {
        status = promptAndGetDoubleInputWithEscape("", &sideLengths[numSides], 'f', 'c');
        if (status == 0)
            numSides++;
        else if (status == 1)
            return numSides;
        else if (status == 2)
            return 0;
        else
            puts("Invalid side length.  Please try again.");
    }
    return numSides;
}

// take x and y points from user
int inputPoints(point* coordinates)
{
    int numPoints = 0;
    int status = -1;
    puts("Please enter up to 20 (x,y) coordinates.  Enter F when finished, or C to cancel.");
    while (numPoints < MAX_SIDES)
    {
        status = promptAndGetDoubleInputWithEscape("X: ", &coordinates[numPoints].x, 'f', 'c');
        if (status == 0)
        {
            status = promptAndGetDoubleInputWithEscape("Y: ", &coordinates[numPoints].y, 'f', 'c');
            if (status == 0)
                numPoints++;
            else if (status == 1)
                puts("You must input both X and Y values for the last coordinate before finishing.");
            else if (status == 2)
                return 0;
            else
                puts("Invalid Y-value.  The preceding X-value will be ignored.  Please try again.");
        }
        else if (status == 1)
            return numPoints;
        else if (status == 2)
            return 0;
        else
            puts("Invalid X-value.  Please try again.");
    }
    return numPoints;
}
