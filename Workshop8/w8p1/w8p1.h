#pragma once
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

#define MAX_PRODUCTS 3
#define NUM_GRAMS_SERVING 64

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo 
{
    int SKU, Cal;
    double Price, Weight;
};


// ----------------------------------------------------------------------------
// function prototypes

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
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int* sku, double* price, double* weight, int* cal);

// 7. Logic entry point
void start();
