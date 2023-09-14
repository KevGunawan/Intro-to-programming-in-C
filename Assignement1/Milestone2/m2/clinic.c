/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, num =0;

    displayPatientTableHeader();

    for (i = 0; i < max; i++) 
    {
        if(patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            num++;
        }
    }

    if(num == 0)
    {
        printf("*** No records found ***");
    
    }

    printf("\n");
    
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int searchOption = 3;

    while (searchOption != 0)
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");

        searchOption = inputIntRange(0, 2);
        printf("\n");

        if (searchOption == 1)
        {
            searchPatientByPatientNumber(patient, max);
        }
        else if (searchOption == 2) 
        {
            searchPatientByPhoneNumber(patient, max);
        }
    }
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int value = -1;

    for (i = 0; i < max && value == -1; i++)
    {
        if(patient[i].patientNumber == 0)
        {
            value = i;
        }
    }
    if (value == -1)
    {
        printf("ERROR: Patient listing is FULL!\n");
        printf("\n");
        
    }
    else 
    {
        patient[value].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[value]);
    }

}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int i = 0, patientNum = 0;

    printf("Enter the patient number: ");

    patientNum = inputIntPositive();
    i = findPatientIndexByPatientNum(patientNum, patient, max);
    printf("\n");

    if (i == -1)
    {
        printf("ERROR: Patient record not found!\n");  
    }
    else
    {
        menuPatientEdit(&patient[i]);
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int i = 0, patientNum = 0;
    char option = 'x';

    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    printf("\n");

    i = findPatientIndexByPatientNum(patientNum, patient, max);

    if (i== -1)
    {
        printf("ERROR: Patient record not found!\n");
        printf("\n");
        
    }
    else
    {
        displayPatientData(&patient[i], FMT_FORM);

        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        option = inputCharOption("yn");

        if (option == 'y')
        {
            patient[i].patientNumber = 0;
            strcpy(patient[i].name,"\0");
            strcpy(patient[i].phone.number,"\0");
            strcpy(patient[i].phone.description,"\0");
            printf("Patient record has been removed!\n");
            printf("\n");
        }
        else
        {
            printf("Operation aborted.\n");
            printf("\n");
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNum = 0, i = 0, found = 0;

    printf("Search by patient number: ");
    patientNum = inputIntPositive();

    printf("\n");

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNum)
        {
            displayPatientData(&patient[i], FMT_FORM);
            printf("\n");

            found = 1;
        }
    }
    if (found == 0)
    {
        printf("*** No records found ***\n");
        printf("\n");
    }
    suspend();

}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char PhoneNumber[11] = { '\0' };
    int i = 0, found = 0;

    printf("Search by phone number: ");
    inputCString(PhoneNumber, 0, 10);
    
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, PhoneNumber) == 0)
        {
            printf("%4.5d %-16s", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);

            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\n");
        printf("*** No records found ***\n");
    }
    printf("\n");
    suspend();
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i = 0, num = 0, count = 0;

    for (i = 0; i < max && patient[i].patientNumber != '\0'; i++)
    {
        count++;
    }

    num = patient[count - 1].patientNumber + 1;

    return num;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int num = 0, found = 0, i = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            found = 1;
            num = i;
        }
    }
    if (found != 1)
    {
        num = -1;
    }
    return num;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
    printf("*** New patient record added ***\n");
    printf("\n");
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int option = 0;
    char p1[] = { "CELL" };
    char p2[] = { "HOME" };
    char p3[] = { "WORK" };
    char p4[] = { "TBD" };

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    option = inputIntRange(1, 4);

    if (option == 1)
    {
        strcpy(phone->description, p1);
    }
    else if (option == 2)
    {
        strcpy(phone->description, p2);
    }
    else if (option == 3)
    {
        strcpy(phone->description, p3);
    }
    else if (option == 4)
    {
        strcpy(phone->description, p4);
    }

    if (option != 4)
    {
        printf("\n");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
    }
       
    printf("\n");
}

