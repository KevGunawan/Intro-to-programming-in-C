/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* x)
{
	int userInput;

	do
	{
		scanf("%d%*c", &userInput);

		if (userInput <= 0)
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
double getDoublePositive(double* y)
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
void openingMessage(const int numOfProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numOfProducts);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS_SERVING);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatfoodInfo(const int counternum)
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
void displayCatFoodData(const int* sku, double* price, double* weight, int* cal)
{
	printf("%07d %10.2lf %10.1lf %8d\n", *sku, *price, *weight, *cal);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* poundsToKG, double* resultKG)
{	
	if (resultKG != NULL)
	{
		*resultKG = *poundsToKG / POUNDS_TO_KG;
	
	}
	return *poundsToKG / POUNDS_TO_KG;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* poundsToG, int* resultG)
{	
	double resultFromConvert = convertLbsKg(poundsToG, &resultFromConvert);


	if (resultG != NULL)
	{
		*resultG = resultFromConvert * 1000;
	}
	return (int) (resultFromConvert * 1000);
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* result_KG, int *result_G)
{
	*result_KG = convertLbsKg(pounds, result_KG);
	*result_G = convertLbsG(pounds, result_G);

	
}


// 11. calculate: servings based on gPerServ
double calculateServings(const int serv_G, const int G_prod, double* numServ)
{
	double result = (double) G_prod / (double) serv_G;
	if (numServ != NULL)
	{
		*numServ = result;
	
	}
	return result;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double* prod_price, const double* num_Serv, double* resCpS)
{
	if (resCpS != NULL)
	{
		*resCpS = *prod_price / *num_Serv;
	}
		return *prod_price / *num_Serv;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double *calTotal, double *res)
{
	
	if (res != NULL)
	{
		*res = *productPrice / *calTotal;
	}
	return  *productPrice / *calTotal;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo * product)
{
	struct ReportData data = { 0 };
	
	data.SKU = product->SKU;
	data.Price = product->Price;
	data.weightPounds = product->Weight; //bag-lbs
	data.Cal = product->Cal; //cal/serv
	data.weightKilos = convertLbsKg(&data.weightPounds, &data.weightKilos); //bag-kgs
	data.weightG = convertLbsG(&data.weightPounds, &data.weightG); //bag-gs
	data.totalServings = calculateServings(NUM_GRAMS_SERVING, data.weightG, &data.totalServings);//servings
	data.costServ = calculateCostPerServing(&data.Price, &data.totalServings, &data.costServ); //$/serv
	double caltotal = data.Cal * data.totalServings;
	data.costCal = calculateCostPerCal(&data.Price, &caltotal, &data.costCal); //$/cal

	return data;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\n");
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_GRAMS_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData display, const int cheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", display.SKU, display.Price, display.weightPounds, display.weightKilos, display.weightG, display.Cal, display.totalServings, display.costServ, display.costCal);

}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo finalDisplay)
{
	
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%0.2lf\n", finalDisplay.SKU, finalDisplay.Price);
	printf("\n");
	printf("Happy shopping!\n");

}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int counter = 0, cheapestProduct = 0;
	double cheap = 1000.0;
	struct CatFoodInfo productInfo[MAX_PRODUCTS] = { {0} };
	struct ReportData  finalInfo[MAX_PRODUCTS] = { { 0 } };

	

	openingMessage(MAX_PRODUCTS);
	//populates the arrays for catfoodinfo and reportdata
	for (counter = 0; counter < MAX_PRODUCTS; counter++)
	{
		productInfo[counter] = getCatfoodInfo(counter);
		finalInfo[counter] = calculateReportData(&productInfo[counter]);
	}

	//searches for the location of the cheapest product 
	for (counter = 0; counter < MAX_PRODUCTS; counter++)
	{
		if (finalInfo[counter].costServ < cheap)
		{
			cheap = finalInfo[counter].costServ;
			cheapestProduct = counter;
		}
	}
	
	displayCatFoodHeader();

	for (counter = 0; counter < MAX_PRODUCTS; counter++)
	{
		displayCatFoodData(&productInfo[counter].SKU, &productInfo[counter].Price, &productInfo[counter].Weight, &productInfo[counter].Cal);
	}

	displayReportHeader();


    //displays the reportdata and appends *** denoting the cheapest product
	for (counter = 0; counter < MAX_PRODUCTS; counter++)
	{
		displayReportData(finalInfo[counter], cheapestProduct);
	    if (counter == cheapestProduct)
		{
			printf(" ***");
		}
		printf("\n");
	}

	//displays SKU and price of the cheapest product
	printf("\n");
	displayFinalAnalysis(productInfo[cheapestProduct]);

}