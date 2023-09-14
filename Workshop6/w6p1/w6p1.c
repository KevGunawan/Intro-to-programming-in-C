/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
#define MAX_ITEMS 10


#include <stdio.h>

int main(void)
{
    double scanIncome, income = 0, sum = 0;
    int loopflag = 0, numItems = 0, i = 0;
    const double MAX_INCOME = 400000.00, MIN_INCOME = 500.00;
    double cost[MAX_ITEMS];
    int priority[MAX_ITEMS];
    char finance[MAX_ITEMS];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &scanIncome);
        if (scanIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            printf("\n");
        }
        else if (scanIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            printf("\n");
        }
        else 
        {
            printf("\n");
            scanIncome = income;
            loopflag = 1;
        }         
    } while (loopflag == 0);
    
    loopflag = 0;

    do 
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);

        if (numItems < 1 || numItems > 10)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            printf("\n");
        }
        else {
            loopflag = 1;
        }
        
    } while (loopflag == 0);

    loopflag = 0;
    printf("\n");

    for (i = 0; i < numItems; i++)
    {
        printf("Item-%d Details:\n", i+1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < 100.00)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {
               
                sum = sum + cost[i];
                loopflag = 1;
            }
        } 
        while (loopflag == 0);

        loopflag = 0;
        do 
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d%*c", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else 
            {
                loopflag = 1;
            } 
        } 
        while (loopflag == 0);

        loopflag = 0;

        do 
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%c%*c", &finance[i]);

            if ((finance[i] == 'n') || (finance[i] == 'y'))
            {
                printf("\n");
                loopflag = 1;
                
            }
            else 
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                
            }

        }while (loopflag == 0);

        loopflag = 0;
    }
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
    }
       
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", sum);
    printf("\n");
    printf("Best of luck in all your future endeavours!\n");



    return 0;
}