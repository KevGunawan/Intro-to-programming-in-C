/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
    double income = 0, sum = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    int loopflag = 0, numItems = 0, i = 0, selection, prioSel, j = 0;
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
        scanf("%lf%*c", &income);
        if (income < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            printf("\n");
        }
        else if (income > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            printf("\n");
        }
        else
        {
            printf("\n");
            loopflag = 1;
        }
    } while (loopflag == 0);

    loopflag = 0;

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d%*c", &numItems);

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
        printf("Item-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf%*c", &cost[i]);

            if (cost[i] < 100.00)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {

                sum = sum + cost[i];
                loopflag = 1;
            }
        } while (loopflag == 0);

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
        } while (loopflag == 0);

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

        } while (loopflag == 0);

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
       
    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d%*c", &selection);

        switch (selection) 
        {
        case 0:
            selection = 0;
            break;
        default:
            printf("\n");
            printf("ERROR: Invalid menu selection.\n");
            printf("\n");
            break;

        case 1:
            for (i = 0; i < numItems; i++) 
            {
                if (finance[i] == 'y') 
                {
                    j++;
                }
            }
            double forecastMonths = sum / income;
            int years = forecastMonths / 12;
            int months = (int)forecastMonths % 12;
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", sum);
            printf("Forecast: %d years, %d months\n", years, months+1);
            if (j > 0) 
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            printf("\n");
            j = 0;
            break;

        case 2:
            printf("\n");
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d%*c", &prioSel);

            switch (prioSel) 
            {
            case 1:
                printf("\n");
                printf("====================================================\n");
                printf("Filter:   by priority (1)\n");
                for (i = 0; i < numItems; i++) 
                {
                    if (priority[i] == 1)
                    {
                        sum1 += cost[i];

                        if (finance[i] == 'y')
                        {
                            j++;

                        }
                    }
                }
                double forcastMonth1 = sum1 / income;
                int years1 = forcastMonth1 / 12;
                int months1 = (int)forcastMonth1 % 12;
                printf("Amount:   $%.2lf\n", sum1);
                printf("Forecast: %d years, %d months\n", years1, months1+1);
                if (j > 0)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");
                printf("\n");
                j = 0;
                break;
            case 2:
                printf("\n");
                printf("====================================================\n");
                printf("Filter:   by priority (2)\n");
                for (i = 0; i < numItems; i++)
                {
                    if (priority[i] == 2)
                    {
                        sum2 = sum2 + cost[i];
                        if (finance[i] == 'y')
                        {
                            j++;

                        }
                    }
                }
                double forecastMonth2 = sum2 / income;
                int years2 = forecastMonth2 / 12;
                int months2 = (int)forecastMonth2 % 12;
                printf("Amount:   $%.2lf\n", sum2);
                printf("Forecast: %d years, %d months\n", years2, months2+1);
                if (j > 0)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");
                printf("\n");
                j = 0;
                break;
            case 3:
                printf("\n");
                printf("====================================================\n");
                printf("Filter:   by priority (3)\n");
                for (i = 0; i < numItems; i++)
                {
                    if (priority[i] == 3)
                    {
                        sum3 = sum3 + cost[i];
                        if (finance[i] == 'y')
                        {
                            j++;

                        }
                    }
                }
                double forecastMonth3 = sum3 / income;
                int years3 = forecastMonth3 / 12;
                int months3 = (int)forecastMonth3 % 12;
                printf("Amount:   $%.2lf\n", sum3);
                printf("Forecast: %d years, %d months\n", years3, months3+1);
                if (j > 0)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");
                printf("\n");
                j = 0;
                break;  
            }
            
        }

    } while (selection != 0);
    printf("\n");
    printf("Best of luck in all your future endeavours!\n");
    return 0;
}






