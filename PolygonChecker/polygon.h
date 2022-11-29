// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// calculation function declarations for polygon checker

#pragma once
#include <stdbool.h>

#define MAX_SIDES                  20
#define SIDES_PER_TRIANGLE          3    // no magic values!
#define SIDES_PER_QUADRILATERAL     4

typedef struct polygon
{
    int numSides;
    double sides[MAX_SIDES];
    // Note: angle 0 will be the angle between sides 0 and 1, 
    // so the final angle N will be between side N and side 0
    double angles[MAX_SIDES];
    double xValues[MAX_SIDES];
    double yValues[MAX_SIDES];
    bool regular;
    char* name;           // e.g. triangle, quadrilateral...
    char* description;    // e.g. isosceles, square, trapezoid...
} POLYGON;

// bool analyzePolygon(int numSides, double* sideLengths);

char* analyzeTriangle(double* sides);

char* analyzeQuadrilateral(double* sides, double* angles);

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
POLYGON createPolygon(int numSides, double* sides, double* angles,
    bool regular, char* name, char* description);

void printPolygonInfo(POLYGON*);     // display all known data

double calculateAreaOfRegularPolygon(double* sideLenths, int numSides);
double calculateAreaOfTriangle(double* sideLenths, int numSides);

// access struct members
void getSides(POLYGON*, double*);
void getAngles(POLYGON*, double*);
void getNumSides(POLYGON*, int*);
void getRegular(POLYGON*, bool*);
void getPolygonName(POLYGON*, char*);
void getPolygonDesc(POLYGON*, char*);

void drawPolygon(POLYGON*);          // this will require a graphics library

bool pointsMatch(double* xValues, double* yValues, int numSides);
