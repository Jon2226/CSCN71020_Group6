// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// user interface declarations for polygon checker

#pragma once
#include <stdbool.h>

void printWelcome(void);

void printMainMenu(void);

bool inputAndHandleMenuResponse(int* numSides, double* sideLengths);

int inputSideLengths(double* sideLengths);

bool inputPoints(double* xValues, double* yValues);
