/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Kevin Gunawan
Student ID#: 177378213
Email      : kgunawan1@myseneca.ca  
Section    : NGG
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    const int productID1 = 111, productID2 = 222, productID3 = 111;
    const double productPrice1 = 111.49, productPrice2 = 222.99, productPrice3 = 334.49;
    const int producttax1 = 'Y', producttax2 = 'N', producttax3 = 'N';
    double averagePrice = (productPrice1 + productPrice2 + productPrice3) / 3;
  
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", productID1);
    printf("  Taxed: %c\n", producttax1);
    printf("  Price: $%.4lf\n", productPrice1);
    printf("\n");
    printf("Product-2 (ID:%d)\n", productID2);
    printf("  Taxed: %c\n", producttax2);
    printf("  Price: $%.4lf\n", productPrice2);
    printf("\n");
    printf("Product-3 (ID:%d)\n", productID3);
    printf("  Taxed: %c\n", producttax3);
    printf("  Price: $%.4lf\n", productPrice3);
    printf("\n");
    printf("The average of all prices is: $%.4lf\n", averagePrice);
    printf("\n");
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", (producttax1 == 'Y'));
    printf("\n");
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", (producttax2 == producttax3));
    printf("\n");
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n", testValue, (productPrice3 < testValue));
    printf("\n");
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", (productPrice3 >(productPrice1+productPrice2)));
    printf("\n");
    printf("5. Is the price of product 1 equal to or more than the price difference\n "); 
    printf("  of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n", (productPrice1 >= (productPrice3 - productPrice2)), (productPrice3 - productPrice2));
    printf("\n");
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", (productPrice2 >= averagePrice));
    printf("\n");
    printf("7. Based on product ID, product 1 is unique -> %d\n",(productID1 != productID2 && productID1 != productID3));
    printf("\n");
    printf("8. Based on product ID, product 2 is unique -> %d\n",(productID2 != productID1 && productID2 != productID3));
    printf("\n");
    printf("9. Based on product ID, product 3 is unique -> %d\n",(productID3 != productID1 && productID3 != productID2));
    printf("\n");
   

    return 0;
}