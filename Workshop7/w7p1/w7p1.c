/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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

#define MAX_LENGTH 70
#define MIN_LENGTH 10
#define MAX_LIVES 10
#define PATH_MULTI 5


struct GameInfo 
{
    int numLives, numTreasures;
    char symbol;
    int moves[MAX_LENGTH];
};

struct PlayerInfo 
{
    int numMoves, pathLength;
    int bombs[MAX_LENGTH], treasures[MAX_LENGTH];
};

int main(void)
{
    int i = 0, j = 0;

    struct GameInfo playerConfig;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    //setting player symbol
    printf("Enter a single character to represent the player: ");
    scanf("%c%*c", &playerConfig.symbol);

    //setting lives
    do 
    {
        printf("Set the number of lives: ");
        scanf("%d%*c", &playerConfig.numLives);
        if (playerConfig.numLives < 1 || playerConfig.numLives > MAX_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }

    } while (playerConfig.numLives < 1 || playerConfig.numLives > MAX_LIVES);
    
    printf("Player configuration set-up is complete\n");
    printf("\n");

    struct PlayerInfo gameConfig;

    printf("GAME Configuration\n");
    printf("------------------\n");
    
    //setting pathlength
    do 
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d%*c", &gameConfig.pathLength);
        if (gameConfig.pathLength < MIN_LENGTH || gameConfig.pathLength > MAX_LENGTH || gameConfig.pathLength % PATH_MULTI != 0) 
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (gameConfig.pathLength < MIN_LENGTH || gameConfig.pathLength > MAX_LENGTH || gameConfig.pathLength % PATH_MULTI != 0);

    int maxMoves = gameConfig.pathLength * 0.75;

    //setting number of moves
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d%*c", &gameConfig.numMoves);

        if (gameConfig.numMoves < playerConfig.numLives || gameConfig.numMoves > maxMoves)
        {
            printf("    Value must be between %d and %d\n", playerConfig.numLives, maxMoves);
        }
    } while (gameConfig.numMoves < playerConfig.numLives || gameConfig.numMoves > maxMoves);

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameConfig.pathLength);

    //bomb placements
    for (i = 0; i < gameConfig.pathLength; i = i + 5) 
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = i; j < i + PATH_MULTI; j++)
        {
            scanf(" %d%*c", &gameConfig.bombs[j]);
        }
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameConfig.pathLength);

    //treasure placements
    for (i = 0; i < gameConfig.pathLength; i = i + 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = i; j < i + PATH_MULTI; j++) 
        {
            scanf(" %d%*c", &gameConfig.treasures[j]);
        }
    }
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", playerConfig.symbol);
    printf("   Lives      : %d\n", playerConfig.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", gameConfig.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < gameConfig.pathLength; i++) 
    {
        printf("%d",gameConfig.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < gameConfig.pathLength; i++)
    {
        printf("%d", gameConfig.treasures[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    




    return 0;
}