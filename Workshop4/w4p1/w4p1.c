/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    char loopVar; 
    int itNum, count ;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");

    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d%*c", &loopVar, &itNum);

        switch (loopVar)
        {
        case 'D':
            if (itNum <= 20 && itNum >= 3)
            {
                count = 0;
                printf("DO-WHILE: ");
                do
                {
                    printf("D");
                    count++;
                } while (count < itNum);
                printf("\n");

            }
            else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            printf("\n");
            break;

        case 'W':
            if (itNum <= 20 && itNum >= 3)
            {
                count = 0;
                printf("WHILE   : ");
                while (count < itNum)
                {
                    printf("W");
                    count++;
                }
                printf("\n");
            }
            else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            printf("\n");
            break;

        case 'F':
            if (itNum <= 20 && itNum >= 3)
            {
                printf("FOR     : ");
                for (count = 0; count < itNum; count++)
                {
                    printf("F");
                }
                printf("\n");
            }else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            printf("\n");
            break;

        case 'Q':
            if (itNum == 0)
            {
                printf("\n");
                printf("+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");

            }
            else
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            printf("\n");
            break;

        default:
            printf("ERROR: Invalid entered value(s)!\n");
            printf("\n");

        }

    } while (loopVar != 'Q' || itNum != 0);

    return 0;
}