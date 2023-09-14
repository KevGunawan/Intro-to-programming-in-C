#pragma once
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Kevin Gunawan
Student ID#: 177378213
Email      : kgunawan1@myseneca.ca
Section    : NGG
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//validates for a proper integer value 
int inputInt(void);

//validates for a positive integer 
int inputIntPositive(void);

//validates for an integer with in a range of values 
int inputIntRange(int Min, int Max);

// validates for whether inputed character  is a valid option 
char inputCharOption(const char validChar[]);

// validates whether the length of the string is valid 
char inputCString(char* String, int Min, int Max);

//validates for proper phonenumber 
void displayFormattedPhone(const char* string);
