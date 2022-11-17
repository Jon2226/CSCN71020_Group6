// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// calculation function declarations for polygon checker

#pragma once
#include <stdbool.h>

char* analyzeTriangle(double* sides);

bool isTriangle(double* sides);

void findAngles(double* sides, double* angles);

void findSideLengths(double* xValues, double* yValues, double* sides);

double calculatePerimeter(double* sideLenths, int numSides);
