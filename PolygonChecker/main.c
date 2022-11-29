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
    printWelcome();
    double sideLengths[MAX_SIDES] = { 0 };
    int numSides = 0;

    do 
    {
        printMainMenu();
    } while (inputAndHandleMenuResponse(&numSides, sideLengths));

	return 0;
}
