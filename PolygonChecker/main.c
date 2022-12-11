// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// main function for polygon checker program, which will take side lengths or 
// (x,y) coordinates from a user, and use them to determine whether the given 
// values can form a polygon, and other information about any polygon formed

#include "polygon.h"
#include "interface.h"
#include "input.h"

int main()
{
    // in future we might switch to a POLYGON struct to hold all this data,
    // and pass around a pointer/array for that instead of all these
    double sideLengths[MAX_SIDES] = { 0 };
    double angles[MAX_SIDES] = { 0 };
    point vertices[MAX_SIDES] = { 0 };
    int numSides = 0;

    printWelcome();
    do
    {
        printMainMenu();
    } while (runMainMenu(&numSides, sideLengths, vertices));

    return 0;
}
