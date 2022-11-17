// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi
// Jonathan Ward - based on examples from Prof. Steve Hendrikse

// common user input routines

#include "input.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTRINGTODOUBLE		20

int countOfCharInString(char* string, char c)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == c)
            count++;
    }
    return count;
}

void removeNewLineFromString(char* string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '\n')
            string[i] = '\0';
    }
}

bool stringIsNumeric(char* string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!(isdigit(string[i]) || string[i] == '.' 
            || string[i] == '-' || string[i] == '+'))
            return false;
    }

    // should be at most 1 period, and 1 plus or minus sign at the beginning
    int countOfPlus = countOfCharInString(string, '+');
    int countOfMinus = countOfCharInString(string, '-');
    if (countOfCharInString(string, '.') <= 1 
        && countOfPlus <= 1 && countOfMinus <= 1)
    {
        if (countOfPlus == 1 && countOfMinus == 0 && string[0] == '+')
            return true;
        else if (countOfMinus == 1 && countOfPlus == 0 && string[0] == '-')
            return true;
        else if (countOfMinus == 0 && countOfPlus == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool promptAndGetDoubleInput(char* prompt, double* userInput)
{
    puts(prompt);

    char input[MAXSTRINGTODOUBLE];
    fgets(input, (int)MAXSTRINGTODOUBLE, stdin);
    removeNewLineFromString(input);

    if (!stringIsNumeric(input))
        return false;
    else
    {
        *userInput = (double)atof(input);
        return true;
    }
}

bool promptAndGetStringInput(char* prompt, char* userInput, size_t maxLength)
{
    puts(prompt);
    fgets(userInput, (int)maxLength, stdin);
    removeNewLineFromString(userInput);         // optional

    if (strlen(userInput) > 0)
        return true;
    else
        return false;
}
