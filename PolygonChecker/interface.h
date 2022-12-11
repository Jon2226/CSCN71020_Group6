// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// user interface declarations for polygon checker

#pragma once
#include <stdbool.h>

void printWelcome(void);
void printMainMenu(void);
bool runMainMenu(int* numSides, double* sideLengths, double* angles, 
    point* coordinates);

int inputSideLengths(double* sideLengths);
int inputPoints(point* coordinates);
