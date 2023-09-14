/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *x)
{
	int userInput;

	do
	{
		scanf("%d%*c", &userInput);

		if (userInput <=0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (userInput <= 0);

	if (x != NULL) 
	{
		*x = userInput;
	}
	return userInput;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *y)
{
	double userInput2;

	do
	{
		scanf("%lf%*c", &userInput2);

		if (userInput2 <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (userInput2 <= 0);

	if (y != NULL)
	{
		*y = userInput2;
	}
	return userInput2;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage (const int numOfProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numOfProducts);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS_SERVING);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatfoodInfo (const int counternum)
{
	struct CatFoodInfo information = { 0 };
	
	printf("Cat Food Product #%d\n", counternum + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&information.SKU);
	printf("PRICE         : $");
	getDoublePositive(&information.Price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&information.Weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&information.Cal);
	printf("\n");

	return information;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int *sku, double *price, double *weight, int *cal)
{
	printf("%07d %10.2lf %10.1lf %8d\n", *sku, *price, *weight, *cal);
}

// 7. Logic entry point
void start()
{
	int counter = 0;
	struct CatFoodInfo productInfo[MAX_PRODUCTS] = {{0}};

	openingMessage(MAX_PRODUCTS);

	for(counter = 0; counter < MAX_PRODUCTS; counter++)
	{
		productInfo[counter] = getCatfoodInfo(counter);
	}

	displayCatFoodHeader();

	for (counter = 0; counter < MAX_PRODUCTS; counter++)
	{
		displayCatFoodData(&productInfo[counter].SKU, &productInfo[counter].Price, &productInfo[counter].Weight, &productInfo[counter].Cal);
	}
}