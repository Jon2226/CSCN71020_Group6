// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi

// calculation function declarations for polygon checker

#pragma once
#include <stdbool.h>

#define MAX_SIDES                  20
#define SIDES_PER_TRIANGLE          3    // no magic values!
#define SIDES_PER_QUADRILATERAL     4
#define MAX_STRING_LEN             20

typedef struct point
{
    double x, y;
} point;

// not used yet
typedef struct polygon
{
    // Note: angle 0 will be the angle between sides 0 and 1, 
    // so the final angle N will be between side N and side 0
    int numSides;
    double sides[MAX_SIDES];
    double angles[MAX_SIDES];
    point vertices[MAX_SIDES];
    bool regular;
    char name[MAX_STRING_LEN];           // e.g. triangle, quadrilateral, pentagon...
    char description[MAX_STRING_LEN];    // e.g. isosceles, square, trapezoid...
} POLYGON;

point createPoint(double xValue, double yValue);
//point copyPoint(point* pointToCopy);
//void disposePoint(point* pointToDispose);

POLYGON createPolygon(int numSides, double* sideLengths, double* angles, 
    point* coordinates, bool regular, char* name, char* description);
//POLYGON copyPolygon(POLYGON* polygonToCopy);
//void disposePolygon(POLYGON* polygonToDispose);

// functions to analyze polygons (should be refactored to use polygon struct)
bool analyzePolygon(int numSides, double* sideLengths, double* angles,
    point* coordinates);
bool isPolygon(double* sides, int numSides);
void findSideLengths(point* vertices, double* sides, int numSides);
double findPerimeter(double* sideLenths, int numSides);
char* findPolygonName(int numSides);
//char* findPolygonDescription(int numSides, double* sides, double* angles);
bool isRegular(double* sides, int numSides);
double findRegularPolygonAngles(double* sides, int numSides);
double findRegularPolygonArea(double* sides, int numSides);
bool pointsMatch(point* coordinates, int numSides);

void printPolygonInfo(double* sides, point* vertices, int numSides);     // display all known data

// triangle functions
bool isTriangle(double* sides);        // redundant
void findTriangleAngles(double* sides, double* angles);
double findTriangleArea(double* sides);
char* analyzeTriangle(double* sides);

double radiansToDegrees(double rad);

// quadrilateral functions
char* analyzeQuadrilateral(double* sides, double* angles, point* vertices);
double getDistance(point a, point b);
bool orthogonal(point a, point b, point c);
bool rectangle(point a, point b, point c, point d);
bool canFormRectangle(point a, point b, point c, point d);
