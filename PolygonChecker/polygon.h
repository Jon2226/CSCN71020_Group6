// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// calculation function declarations for polygon checker

#pragma once
#include <stdbool.h>

#define MAX_SIDES   20

typedef struct polygon
{
    int numSides;
    double sides[MAX_SIDES];
    double angles[MAX_SIDES];
    // Note: angle 0 will be the angle between sides 0 and 1, 
    // so the final angle N will be between side N and side 0

    bool regular;
    char* name;	// e.g. triangle, quadrilateral...
    char* description;  // e.g. isosceles, square, trapezoid...
} POLYGON;

char* analyzeTriangle(double* sides);

bool isTriangle(double* sides);

void findAngles(double* sides, double* angles);

void findSideLengths(double* xValues, double* yValues, double* sides);

double calculatePerimeter(double* sideLenths, int numSides);

// new stuff... needs to be sorted later
bool isPolygon(double* side, int numSides);

bool isRegular(double* side, int numSides);

char* findPolygonName(int numSides);

char* findPolygonDescription();

double findRegularAngles(int numSides);

/* the following are not implemented... yet */

double calculateAreaOfRegularPolygon(double* sideLenths, int numSides);
double calculateAreaOfTriangle(double* sideLenths, int numSides);
POLYGON createPolygon();
void printPolygonInfo(POLYGON*);     // display all known data

// access struct members
void getSides(POLYGON*, double*);
void getAngles(POLYGON*, double*);
void getNumSides(POLYGON*, int*);
void getRegular(POLYGON*, bool*);
void getPolygonName(POLYGON*, char*);
void getPolygonDesc(POLYGON*, char*);

void drawPolygon(POLYGON*);          // this will require a graphics library
