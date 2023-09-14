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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>

#include "core.h"



// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
//validates for a proper integer value 
int inputInt(void)
{
    char newLine = 'x';
    int value;

    while (newLine != '\n')
    {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return value;
}

//validates for a positive integer 
int inputIntPositive(void)
{
    int value = inputInt();

    while(value < 0)
    {
        if (value < 0) 
        {
            printf("ERROR! Value must be > 0: ");
            value = inputInt();
        }
    }
    return value;
}
//validates for an integer with in a range of values 
int inputIntRange(int Min, int Max)
{
    int value = inputInt();
    
    while (value < Min || value > Max)
    {
        if (value < Min || value > Max)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", Min, Max);
            value = inputInt();
        }
    }
    return value;
}

// validates for whether inputed character  is a valid option 
char inputCharOption(const char validChar[])
{
   int valid = 0;
   char input = 'x';

    do {
        scanf("%c", &input);
        clearInputBuffer();
        
        if (strchr(validChar, input))
        {
            valid = 1;
        }
            
        if (valid != 1)
        {
            printf("ERROR: Character must be one of [qwErty]: ");
        }
        
    } while (!valid);
    return input;
}

// validates whether the length of the string is valid 
char inputCString (char * String, int Min, int Max)

{
    char input[1000] = { '\0' };
    int valid = 0;

    do
    {
        scanf("%[^\n]", input);
        clearInputBuffer();
        

        if (strlen(input) >= Min && strlen(input) <= Max)
        {
            valid = 1;
            strcpy(String, input);
        }

        if (valid != 1)
        {
            if (Min == Max)
            {
                printf("ERROR: String length must be exactly %d chars: ", Min);
            }
            else if (strlen(input) > Max)
            {
                printf("ERROR: String length must be no more than %d chars: ", Max);
            }
            else if (strlen(input) < Min)
            {
                printf("ERROR: String length must be between %d and %d chars: ", Min, Max);
            }
        }
    } while (valid != 1);
    return 'c';
}
   
//validates for proper phonenumber 

void displayFormattedPhone(const char* string)
{
    int valid = 0;
    int i = 0;
    int numValid = 0;
    int j = 0;
    //char validNumbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char validNumbers[] = "0123456789";

    if (string != NULL)
    {
        for (i = 0; i < strlen(string); i++)
        {
            if (strchr(validNumbers, string[i]) != NULL)
            {
                numValid++;
            }
        }
        
        if (strlen(string) == 10 && numValid == 10)
        {
            valid = 1;
        }
    }
    if (valid)
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
            string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8], string[9]);
    }
    else
    {
        printf("(___)___-____");
    }
}
    


