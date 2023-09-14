#pragma once
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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define NUM_GRAMS_SERVING 64
#define POUNDS_TO_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int SKU, Cal;
    double Price, Weight;
};

struct ReportData
{
    int SKU, Cal, weightG;
    double Price, weightPounds, weightKilos, totalServings, costServ, costCal;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* x);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* y);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatfoodInfo(const int counternum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int* sku, double* price, double* weight, int* cal);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* poundsToKG, double* resultKG);

// 9. convert lbs: g
int convertLbsG(const double* poundsToG, int* resultG);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* result_KG, int* result_G);

// 11. calculate: servings based on gPerServ
double calculateServings(const int serv_G, const int G_prod, double* numServ);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* prod_price, const double* num_Serv, double* resCpS);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double *calTotal, double *res);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData display, const int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo finalDisplay);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);