// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi       

// implementation of calculation functions for polygon checker

#define _CRT_SECURE_NO_WARNINGS
#include "polygon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

point createPoint(double xValue, double yValue)
{
    point p = { 0 };
    p.x = xValue;
    p.y = yValue;
    return p;
}

POLYGON createPolygon(int numSides, double* sideLengths, double* angles, 
    point* coordinates, bool regular, char* name, char* description)
{
    POLYGON p = { 0 };
    p.numSides = numSides;
    for (size_t i = 0; i < numSides; i++)
    {
        p.sides[i] = sideLengths[i];
        p.angles[i] = angles[i];
        p.vertices[i].x = coordinates[i].x;
        p.vertices[i].y = coordinates[i].y;
    }
    p.regular = regular;
    strncpy(p.name, name, MAX_STRING_LEN);
    p.name[MAX_STRING_LEN - 1] = '\0';
    strncpy(p.description, description, MAX_STRING_LEN);
    p.name[MAX_STRING_LEN - 1] = '\0';
    return p;
}

bool analyzePolygon(int numSides, double* sideLengths, double* angles, 
    point* coordinates)
{
    if (!isPolygon(sideLengths, numSides))
        return false;

    puts(findPolygonName(numSides));

    if (isRegular(sideLengths, numSides))
    {
        puts("This is a regular polygon.");
        printf("The area is: %g\n", findRegularPolygonArea(sideLengths, numSides));
        printf("The angles are: %g\n", findRegularPolygonAngles(sideLengths, numSides));
    }
    printf("Perimeter: %g\n", findPerimeter(sideLengths, numSides));

    if (numSides == SIDES_PER_TRIANGLE)
    {
        puts("This is a triangle.");
        findTriangleAngles(sideLengths, angles);
        puts("The angles are: ");
        for (int i = 0; i < SIDES_PER_TRIANGLE; i++)
            printf("Angle %d: %g\n", i + 1, angles[i]);

        double area = findTriangleArea(sideLengths);
        printf("The area is: %g\n", area);
    }
    if (numSides == SIDES_PER_QUADRILATERAL)
    {
        puts("This is a quadrilateral.");
        findSideLengths(coordinates, sideLengths, numSides);
        printf("Specifically, it is a %s\n", analyzeQuadrilateral(sideLengths,
            angles, coordinates));
    }

    return true;
}

bool isPolygon(double* sides, int numSides)
{
    // check that all side lengths are more than zero
    for (size_t i = 0; i < numSides; i++)
        if (sides[i] <= 0)
            return false;

    // find sum of all side lengths, and length of longest side
    double sum = 0;
    double longest = 0;
    for (size_t i = 0; i < numSides; i++)
    {
        sum += sides[i];
        // longest = longest < side[i] ? side[i] : longest;
        if (longest < sides[i])
            longest = sides[i];
    }

    // check that longest side is less than the sum of the others.  
    // if so, they can form a polygon.
    if (longest < (sum - longest))
        return true;

    return false;
}

double findPerimeter(double* sideLenths, int numSides)
{
    double perimeter = 0;
    for (size_t i = 0; i < numSides; i++)
        perimeter += sideLenths[i];

    return perimeter;
}

char* findPolygonName(int numSides)
{
    switch (numSides)
    {
    case 3:
        return "triangle";
    case 4:
        return "quadrilateral";
    case 5:
        return "pentagon";
    case 6:
        return "hexagon";
    case 7:
        return "septagon";
    case 8:
        return "octagon";
    case 9:
        return "nonagon";
    case 10:
        return "decagon";
    case 11:
        return "hendecagon";
    case 12:
        return "dodecagon";
    case 13:
        return "tridecagon";
    case 14:
        return "tetradecagon";
    case 15:
        return "pentadecagon";
    case 16:
        return "hexadecagon";
    case 17:
        return "heptadecagon";
    case 18:
        return "octadecagon";
    case 19:
        return "enneadecagon";
    case 20:
        return "icosagon";
    default:
        return "";
    }
}
//
//char* findPolygonDescription(int numSides, double* sides, double* angles)
//{
//    // by calling analyzeTriangle and analyzeQuadrilateral
//    char* description = "";
//    if (numSides == SIDES_PER_TRIANGLE)
//        description = analyzeTriangle(sides);
//    else if (numSides == SIDES_PER_QUADRILATERAL)
//        description = analyzeQuadrilateral(sides, angles);
//
//    return description;
//}

bool isRegular(double* sides, int numSides)
{
    // return true if all side lengths are the same
    double side0 = sides[0];
    for (size_t i = 1; i < numSides; i++)
        if (sides[i] != sides[0])
            return false;

    return true;
}

double findRegularPolygonAngles(double* sides, int numSides)
{
    double numberOfSides = numSides;
    return ((double)180 * (numberOfSides - (double)2) / numberOfSides);
}

double findRegularPolygonArea(double* sides, int numSides)
{
    const double pi = acos(-1);
    double apothem = sides[0] / 
        (2.0 * tan((180.0 / (double)numSides) * pi / 180.0));

    return (double)numSides * sides[0] * apothem / 2.0;
}

bool pointsMatch(point* coordinates, int numSides)
{
    for (size_t i = 0; i < numSides; i++)
        for (size_t j = i + 1; j < numSides; j++)
            if (coordinates[i].x == coordinates[j].x)
                if (coordinates[i].y == coordinates[j].y)
                    return true;

    return false;
}
//
//void printPolygonInfo(double* sides, point* vertices, int numSides)
//{
//    /*
//        If pointsMatch, skip printing coordinates because it should mean that
//        they are still zeroed because they have not been given by the user.
//        (This is used instead of checking for points being '(0,0), which could
//        actually be valid.
//    */
//    if (!pointsMatch(vertices, numSides))
//        for (size_t i = 0; i < numSides; ++i)
//            printf("Vertex %d: (%g, %g)\n", (int)i+1, vertices[i].x, vertices[i].y);
//
//    if (sides[0] != 0)
//        ;
//    // print side lengths
//}

// redundant legacy function
bool isTriangle(double* sides)
{
    // checking for <= 0 should be handled by input validation, but 
    // we will still include this check here... just in case
    if (sides[0] <= 0 || sides[1] <= 0 || sides[2] <= 0)
        return false;

    else if (((sides[0] + sides[1]) > sides[2]) &&
        ((sides[0] + sides[2]) > sides[1]) &&
        ((sides[1] + sides[2]) > sides[0]))
        return true;

    else
        return false;
}

// determine angles based on side lengths
void findTriangleAngles(double* sides, double* angles)
{
    angles[0] = radiansToDegrees(acos((pow(sides[1], 2) + pow(sides[2], 2)
        - pow(sides[0], 2)) / (2.0 * sides[1] * sides[2])));

    angles[1] = radiansToDegrees(acos((pow(sides[0], 2) + pow(sides[2], 2)
        - pow(sides[1], 2)) / (2.0 * sides[0] * sides[2])));

    angles[2] = radiansToDegrees(acos((pow(sides[0], 2) + pow(sides[1], 2)
        - pow(sides[2], 2)) / (2.0 * sides[0] * sides[1])));

    printf("Angles: %lf  %lf  %lf \n\n\n", angles[0], angles[1], angles[2]);
}

double findTriangleArea(double* sides)
{
    // using Heron's formula
    double halfPerim = findPerimeter(sides, SIDES_PER_TRIANGLE) / (double)2;
    return sqrt(halfPerim * (halfPerim - sides[0]) * (halfPerim - sides[1])
        * (halfPerim - sides[2]));
}

char* analyzeTriangle(double* sides)
{
    char* result = "";
    if (!isTriangle(sides))     // single function to check this
    {
        result = "Not a triangle";
    }
    else if (sides[0] == sides[1] && sides[0] == sides[2])
    {
        result = "Equilateral triangle";
    }
    else if ((sides[0] == sides[1] && sides[0] != sides[2]) ||
        (sides[0] == sides[2] && sides[0] != sides[1]) ||
        (sides[1] == sides[2] && sides[1] != sides[0]))
    {
        result = "Isosceles triangle";
    }
    else
    {
        result = "Scalene triangle";
    }
    return result;
}

double radiansToDegrees(double rad)
{
    return rad * (180.0 / acos(-1));
}

char* analyzeQuadrilateral(double* sides, double* angles, point* vertices)
{
    int numEquivalentSides = 0;
    int numEquivalentAngles = 0;
    
    if (sides[0] == sides[1] == sides[2] == sides[3])
    {
        //if (angles[0] == 90)
        if (canFormRectangle(vertices[0], vertices[1], vertices[2], vertices[3]))
            return "square";
        else
            return "rhombus";
    }
    else if ((sides[0] == sides[1] && sides[2] == sides[3])
        || (sides[0] == sides[3] && sides[2] == sides[1])
        || (sides[0] == sides[2] && sides[1] == sides[3]))
    {
        //if (angles[0] == 90)
        if (canFormRectangle(vertices[0], vertices[1], vertices[2], vertices[3]))
            return "rectangle";
        else
            return "parallelogram or kite";
    }

    return "";
}

// determine side lengths based on coordinates of points
void findSideLengths(point* vertices, double* sides, int numSides)
{
    for (int i = 0; i < numSides; i++)
    {
        if (i == numSides - 1)
            sides[i] = getDistance(vertices[0], vertices[i]);
        else
            sides[i] = getDistance(vertices[i], vertices[i+1]);
    }
}

double getDistance(point a, point b)
{
    // using pythagorean theorem
    return (a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y);
}

bool orthogonal(point a, point b, point c)
{
    return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

bool rectangle(point a, point b, point c, point d)
{
    return
        orthogonal(a, b, c) &&
        orthogonal(b, c, d) &&
        orthogonal(b, d, a);
}

bool canFormRectangle(point a, point b, point c, point d)
{
    return
        rectangle(a, b, c, d) ||
        rectangle(b, c, d, a) ||
        rectangle(c, a, b, d) ||
        rectangle(d, b, c, a);
}
