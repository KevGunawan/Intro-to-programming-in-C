/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    double priceS, priceM, priceL;
    int numShirt;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf",&priceS);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf",&priceM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf",&priceL);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    int smallDec = priceS * 100.0;
                
    printf("SMALL  : $%.2lf\n", priceS);
    printf("MEDIUM : $%.2lf\n", priceM);
    printf("LARGE  : $%.2lf\n", priceL);
    printf("\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirt);
    printf("\n");

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n",numShirt);
    int subTotal = smallDec * numShirt; //calculated the subtotal
    double decSubTotal = (double)subTotal / 100.0; //cast the subtotal as a double
    printf("Sub-total: $%.4lf\n", decSubTotal);
    double totalTax = subTotal * TAX; //calculated the tax
    int roundedTax = totalTax + 0.5; //calculated the rounding as integer 
    double roundedTotal = (double)roundedTax / 100.0; //cast the rounded tax as a double
    printf("Taxes    : $ %.4lf\n", roundedTotal);
    double Total = roundedTotal + decSubTotal; //calculated the total
    printf("Total    : $%.4lf\n", Total);
    printf("\n");


    return 0;
}