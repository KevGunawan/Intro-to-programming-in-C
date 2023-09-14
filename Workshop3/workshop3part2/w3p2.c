/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffeetype1, coffeetype2 , coffeetype3;
    int bagtype1, bagtype2, bagtype3;
    char cream1, cream2, cream3 ;
    char coffeeprf, withcream;
    int servings;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &coffeetype1);
    printf("Bag weight (g): ");
    scanf("%d%*c", &bagtype1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream1);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &coffeetype2);
    printf("Bag weight (g): ");
    scanf("%d%*c", &bagtype2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream2);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &coffeetype3);
    printf("Bag weight (g): ");
    scanf("%d%*c", &bagtype3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream3);
    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeetype1 == 'l' || coffeetype1 == 'L'), (coffeetype1 == 'm' || coffeetype1 == 'M'), (coffeetype1 == 'r' || coffeetype1 == 'R'), bagtype1, (bagtype1 / GRAMS_IN_LBS), (cream1 == 'y' || cream1 == 'Y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeetype2 == 'l' || coffeetype2 == 'L'), (coffeetype2 == 'm' || coffeetype2 == 'M'), (coffeetype2 == 'r' || coffeetype2 == 'R'), bagtype2, (bagtype2 / GRAMS_IN_LBS), (cream2 == 'y' || cream2 == 'Y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeetype3 == 'l' || coffeetype3 == 'L'), (coffeetype3 == 'm' || coffeetype3 == 'M'), (coffeetype3 == 'r' || coffeetype3 == 'R'), bagtype3, (bagtype3 / GRAMS_IN_LBS), (cream3 == 'y' || cream3 == 'Y'));
    printf("\n");
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &coffeeprf);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &withcream);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &servings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeetype1 == 'l' || coffeetype1 == 'L') && (coffeeprf == 'l' || coffeeprf == 'L')) || ((coffeetype1 == 'm' || coffeetype1 == 'M') && (coffeeprf == 'm' || coffeeprf == 'M')) || ((coffeetype1 == 'r' || coffeetype1 == 'R') && (coffeeprf == 'r' || coffeeprf == 'R')), (bagtype1 == 250 && servings >= 1 && servings <= 4) || (bagtype1 == 500 && servings >= 5 && servings <= 9) || (bagtype1 == 1000 && servings >= 10), ((cream1 == 'y' || cream1 == 'Y') && (withcream == 'y' || withcream == 'Y')) || ((cream1 == 'n' || cream1 == 'N') && (withcream == 'n' || withcream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeetype2 == 'l' || coffeetype2 == 'L') && (coffeeprf == 'l' || coffeeprf == 'L')) || ((coffeetype2 == 'm' || coffeetype2 == 'M') && (coffeeprf == 'm' || coffeeprf == 'M')) || ((coffeetype2 == 'r' || coffeetype2 == 'R') && (coffeeprf == 'r' || coffeeprf == 'R')), (bagtype2 == 250 && servings >= 1 && servings <= 4) || (bagtype2 == 500 && servings >= 5 && servings <= 9) || (bagtype2 == 1000 && servings >= 10), ((cream2 == 'y' || cream2 == 'Y') && (withcream == 'y' || withcream == 'Y')) || ((cream2 == 'n' || cream2 == 'N') && (withcream == 'n' || withcream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeetype3 == 'l' || coffeetype3 == 'L') && (coffeeprf == 'l' || coffeeprf == 'L')) || ((coffeetype3 == 'm' || coffeetype3 == 'M') && (coffeeprf == 'm' || coffeeprf == 'M')) || ((coffeetype3 == 'r' || coffeetype3 == 'R') && (coffeeprf == 'r' || coffeeprf == 'R')), (bagtype3 == 250 && servings >= 1 && servings <= 4) || (bagtype3 == 500 && servings >= 5 && servings <= 9) || (bagtype3 == 1000 && servings >= 10), ((cream3 == 'y' || cream3 == 'Y') && (withcream == 'y' || withcream == 'Y')) || ((cream3 == 'n' || cream3 == 'N') && (withcream == 'n' || withcream == 'N')));
    printf("\n");
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &coffeeprf);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &withcream);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &servings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeetype1 == 'l' || coffeetype1 == 'L') && (coffeeprf == 'l' || coffeeprf == 'L')) || ((coffeetype1 == 'm' || coffeetype1 == 'M') && (coffeeprf == 'm' || coffeeprf == 'M')) || ((coffeetype1 == 'r' || coffeetype1 == 'R') && (coffeeprf == 'r' || coffeeprf == 'R')), (bagtype1 == 250 && servings >= 1 && servings <= 4) || (bagtype1 == 500 && servings >= 5 && servings <= 9) || (bagtype1 == 1000 && servings >= 10), ((cream1 == 'y' || cream1 == 'Y') && (withcream == 'y' || withcream == 'Y')) || ((cream1 == 'n' || cream1 == 'N') && (withcream == 'n' || withcream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeetype2 == 'l' || coffeetype2 == 'L') && (coffeeprf == 'l' || coffeeprf == 'L')) || ((coffeetype2 == 'm' || coffeetype2 == 'M') && (coffeeprf == 'm' || coffeeprf == 'M')) || ((coffeetype2 == 'r' || coffeetype2 == 'R') && (coffeeprf == 'r' || coffeeprf == 'R')), (bagtype2 == 250 && servings >= 1 && servings <= 4) || (bagtype2 == 500 && servings >= 5 && servings <= 9) || (bagtype2 == 1000 && servings >= 10), ((cream2 == 'y' || cream2 == 'Y') && (withcream == 'y' || withcream == 'Y')) || ((cream2 == 'n' || cream2 == 'N') && (withcream == 'n' || withcream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeetype3 == 'l' || coffeetype3 == 'L') && (coffeeprf == 'l' || coffeeprf == 'L')) || ((coffeetype3 == 'm' || coffeetype3 == 'M') && (coffeeprf == 'm' || coffeeprf == 'M')) || ((coffeetype3 == 'r' || coffeetype3 == 'R') && (coffeeprf == 'r' || coffeeprf == 'R')), (bagtype3 == 250 && servings >= 1 && servings <= 4) || (bagtype3 == 500 && servings >= 5 && servings <= 9) || (bagtype3 == 1000 && servings >= 10), ((cream3 == 'y' || cream3 == 'Y') && (withcream == 'y' || withcream == 'Y')) || ((cream3 == 'n' || cream3 == 'N') && (withcream == 'n' || withcream == 'N')));
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    printf("\n");

    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/