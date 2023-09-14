/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012   
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int month, year, days;
    double morning, evening, sumMorning = 0, sumEvening = 0;

    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year < MIN_YEAR) || (year > MAX_YEAR))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if ((month < JAN) || (month > DEC))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (((year < MIN_YEAR) || (year > MAX_YEAR)) || ((month < JAN) || (month > DEC)));

    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");
     
    for (days = 1; days <= LOG_DAYS; days++)
    {
        printf("%d-", year);
        switch (month)
        {
        case 1:

            printf("JAN");
            break;
        case 2:

            printf("FEB");
            break;
        case 3:

            printf("MAR");
            break;
        case 4:

            printf("APR");
            break;
        case 5:

            printf("MAY");
            break;
        case 6:

            printf("JUN");
            break;
        case 7:

            printf("JUL");
            break;
        case 8:

            printf("AUG");
            break;
        case 9:

            printf("SEP");
            break;
        case 10:

            printf("OCT");
            break;
        case 11:

            printf("NOV");
            break;
        case 12:

            printf("DEC");
            break;
        }
        if (days < 10) 
        {
            printf("-0%d\n", days);
        }
        else {
            printf("-%d\n", days);
        }
       
        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning);

            if (morning < 0.0 || morning > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else 
            {
                sumMorning = morning + sumMorning;
            }

        } while (morning < 0.0 || morning > 5.0);

        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening);

            if (evening < 0.0 || evening > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else 
            {
                sumEvening = evening + sumEvening;
                printf("\n");
            }

        } while (evening < 0.0 || evening > 5.0);
    }
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", sumMorning);
    printf("Evening total rating:  %.3lf\n", sumEvening);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", sumMorning + sumEvening);
    printf("\n");
    printf("Average morning rating:  %.1lf\n", sumMorning / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", sumEvening / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (sumMorning + sumEvening) / (2*LOG_DAYS));


    return 0;
}