// CSCN71020 - Fall 2022 - Group Project
// Group 6: Jonathan Ward, Drasti Patel, Komalpreet Kaur, Nonso Ekpunobi
// Jonathan Ward - based on examples from Prof. Steve Hendrikse

// declarations for common user input routines

#pragma once
#include <stdbool.h>
#include <stdio.h>

int countOfCharInString(char* string, char c);

void removeNewLineFromString(char* string);

bool stringIsNumeric(char* string);

bool promptAndGetDoubleInput(char* prompt, double* response);

bool promptAndGetStringInput(char* prompt, char* response, size_t max);
