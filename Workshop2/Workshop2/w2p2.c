/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', tomSize = 'L', sallySize = 'M';
    double priceS, priceM, priceL;
    int numShirtS, numShirtM, numShirtL;

    printf("Set Shirt PriceS\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &priceS);
    printf("Enter the price for a MEDIUM Shirt: $");
    scanf("%lf", &priceM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &priceL);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    int smallDec = priceS * 100.0; 
    int mediumDec = priceM * 100.0;
    int largeDec = priceL * 100.0;

    printf("SMALL  : $%.2lf\n", priceS);
    printf("MEDIUM : $%.2lf\n", priceM);
    printf("LARGE  : $%.2lf\n", priceL);
    printf("\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirtS);
    printf("\n");

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numShirtL);
    printf("\n");

    printf("Sally's shirt size is %c\n", sallySize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numShirtM);
    printf("\n");

   //calculations for patty
    int subTotal = smallDec * numShirtS;
    double decSubTotal = (double)subTotal / 100.0;    
    double totalTax = (double)subTotal * TAX;
    int roundedTax = totalTax + 0.5;
    double roundedTotal = (double)roundedTax / 100.0;
    double Total = roundedTotal + decSubTotal;
   //calculations for tommy 
    int subTotalL = largeDec * numShirtL;
    double decSubTotalL = (double)subTotalL / 100.0;
    double totalTaxL = (double)subTotalL * TAX;
    int roundedTaxL = totalTaxL + 0.5;
    double roundedTotalL = (double)roundedTaxL / 100.0;
    double TotalL = roundedTotalL + decSubTotalL;
   //calculations for sally
    int subTotalM = mediumDec * numShirtM;
    double decSubTotalM = (double)subTotalM / 100.0;
    double totalTaxM = (double)subTotalM * TAX;
    int roundedTaxM = totalTaxM + 0.5;
    double roundedTotalM = (double)roundedTaxM / 100.0;
    double TotalM = roundedTotalM + decSubTotalM;
  //calculations for grandtotals
    int subGrandTotal = subTotal + subTotalL + subTotalM;
    double dSubGrandTotal = (double)subGrandTotal / 100.0;
    double grandTotalTax = (double)subGrandTotal * TAX;
    int roundedGrandTax = grandTotalTax + 0.5;
    double roundedGrand = (double)roundedGrandTax / 100.0;
    double Grandtotal = roundedGrand + dSubGrandTotal;
    int Grandtotal2 = subGrandTotal + roundedGrandTax;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, priceS, numShirtS, decSubTotal, roundedTotal, Total);
    printf("Tommy %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, priceL, numShirtL, decSubTotalL, roundedTotalL, TotalL);
    printf("Sally %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", sallySize, priceM, numShirtM, decSubTotalM, roundedTotalM, TotalM);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", dSubGrandTotal, roundedGrand, Grandtotal);

    int totalShirts = numShirtS + numShirtM + numShirtL;
    //average calculations
    int subAvg = subGrandTotal / (totalShirts*100);
    double dSubAvg = (double)subAvg / 100.0;
    int totalAvg = Grandtotal2 / (totalShirts * 100);
    double totalAvg2 = (double)totalAvg / 100.0;
    //Toonies calculations 
    int Toonies = subGrandTotal / 200.0;
    int remainder200 = subGrandTotal % 2;
    double remainder201 = remainder200 / 100.0;
    //

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", dSubGrandTotal);
    printf("Toonies %3d %9.4lf\n", Toonies, remainder201);




    
    return 0;
}