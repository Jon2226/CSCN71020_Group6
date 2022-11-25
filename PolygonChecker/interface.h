// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// user interface declarations for polygon checker

#pragma once
#include <stdbool.h>

void printWelcome();

int printShapeMenu();

bool getTriangleSides(double* triangleSides);

bool getPoints(double* xValues, double* yValues);
