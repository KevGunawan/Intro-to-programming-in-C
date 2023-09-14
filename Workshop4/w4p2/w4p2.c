/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  :
Student ID#:
Email      :
Section    :
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{

    int apple, orange, pear, tomato, cabbage, play;
    int applesPicked, orangesPicked, pearsPicked, tomatoesPicked, cabbagesPicked;

    do
    { 
        printf("Grocery Shopping\n");
        printf("================\n");

        do {
            printf("How many APPLES do you need? : ");
            scanf("%d%*c", &apple);

            if (apple >= 0) {
                printf("\n");
            }
            else
                printf("ERROR: Value must be 0 or more.\n");    
        } while (apple < 0);
           
        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d%*c", &orange);

            if (orange >= 0) {
                printf("\n");
            }
            else
                printf("ERROR: Value must be 0 or more.\n");
        } while (orange < 0);

        do {
            printf("How many PEARS do you need? : ");
            scanf("%d%*c", &pear);

            if (pear >= 0) {
                printf("\n");
            }
            else
                printf("ERROR: Value must be 0 or more.\n");
        } while (pear < 0);

        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d%*c", &tomato);

            if (tomato >= 0) {
                printf("\n");
            }
            else
                printf("ERROR: Value must be 0 or more.\n");
        } while (tomato < 0);

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d%*c", &cabbage);

            if (cabbage >= 0) {
                printf("\n");
            }
            else
                printf("ERROR: Value must be 0 or more.\n");
        } while (cabbage < 0);

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");

        while (apple > 0) {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d%*c", &applesPicked);

            if (applesPicked > apple) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apple);
            }
            else if (applesPicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (apple - applesPicked > 0) {
                apple = apple - applesPicked; 
                printf("Looks like we still need some APPLES...\n");
            } 
            else { // else if (applesPicked == apples)
                apple -= applesPicked;
                printf("Great, that's the apples done!\n");
                printf("\n");
            }
        }
        while (orange > 0) {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d%*c", &orangesPicked);

            if (orangesPicked > orange) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", orange);
            }
            else if (orangesPicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (orange - orangesPicked > 0) {
                orange = orange - orangesPicked;
                printf("Looks like we still need some ORANGES...\n");
            }
            else{
                orange = 0;
                printf("Great, that's the oranges done!\n");
                printf("\n");
            }
        }
        while (pear > 0) {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d%*c", &pearsPicked);

            if (pearsPicked > pear) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pear);
            }
            else if (pearsPicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pear - pearsPicked > 0) {
                pear = pear - pearsPicked;
                printf("Looks like we still need some PEARS...\n");
            }
            else {
                pear = 0;
                printf("Great, that's the pears done!\n");
                printf("\n");
            }
        }
        while (tomato > 0) {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d%*c", &tomatoesPicked);

            if (tomatoesPicked > tomato) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomato);
            }
            else if (tomatoesPicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (tomato - tomatoesPicked > 0) {
                tomato = tomato - tomatoesPicked;
                printf("Looks like we still need some TOMATOES...\n");
            }
            else {
                tomato = 0;
                printf("Great, that's the tomatoes done!\n");
                printf("\n");
            }
        }
        while (cabbage > 0) {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d%*c", &cabbagesPicked);

            if (cabbagesPicked > cabbage) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbage);
            }
            else if (cabbagesPicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (cabbage - cabbagesPicked > 0) {
                cabbage = cabbage - cabbagesPicked;
                printf("Looks like we still need some CABBAGES...\n");
            }
            else {
                cabbage = 0;
                printf("Great, that's the cabbages done!\n");
                printf("\n");
            }
        }
        printf("All the items are picked!\n");
        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d%*c", &play);
        printf("\n");
    
    }while (play != 0);
    printf("Your tasks are done for today - enjoy your free time!\n");




    return 0;
}