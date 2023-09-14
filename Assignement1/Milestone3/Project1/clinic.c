/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, num = 0;

    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            num++;
        }
    }

    if (num == 0)
    {
        printf("*** No records found ***");

    }

    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int value = -1;

    for (i = 0; i < max && value == -1; i++)
    {
        if (patient[i].patientNumber == 0)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int i = 0, patientNum = 0, exit = 1;
    char option = 'x', newline = 'x';

    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    printf("\n");

    i = findPatientIndexByPatientNum(patientNum, patient, max);

    if (i == -1)
    {
        printf("ERROR: Patient record not found!\n");
        printf("\n");

    }
    else
    {
        displayPatientData(&patient[i], FMT_FORM);

        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        
        exit = 1;
        do 
        {
            scanf("%c%c", &option, &newline);

            if ((option == 'y' || option == 'Y') && (newline == '\n'))
            {
                patient[i].patientNumber = 0;
                strcpy(patient[i].name, "\0");
                strcpy(patient[i].phone.number, "\0");
                strcpy(patient[i].phone.description, "\0");
                printf("Patient record has been removed!\n");
                printf("\n");
                exit = 0;
            }
            else if ((option == 'n' || option == 'N') && (newline == 'n'))
            {
                printf("Operation aborted.\n\n");
                exit = 0;
                clearInputBuffer();
            }
            else
            {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (exit);
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i = 0, j = 0;

    arrange(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(NULL, 1);
    for(i = 0; i < data->maxAppointments; i++)
    {
        for(j = 0; j < data->maxPatient; j++)
        {
            if(data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }
    
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int monthLast = 31;
    int i = 0, j = 0;
    struct Date date;

    printf("Year        : ");

    date.year = inputIntPositive();

    printf("Month (1-12): ");

    date.month = inputIntRange(1, 12);

    printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11)
        {
            monthLast = 30;
        }
        if (date.month == 2)
        {
            monthLast = 28;
        }
        if (date.year % 4 == 0 && date.month == 2)
        {
            monthLast = 29;
        }
    printf("%d)  : ", monthLast);
    date.day = inputIntRange(1, monthLast);
    printf("\n");

    arrange(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for(j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }

    }
    printf("\n");
}



// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* ap, int maxAppointments, struct Patient patient[], int maxPatients)
{
    struct Date date;
    struct Time time;

    int monthLast = 31;
    int patientNum, index, notAvail = 1;

    printf("Patient Number: ");
    patientNum = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNum, patient, maxPatients);

    if (index >= 0)
    {
        while(notAvail)
        {
            printf("Year        : ");

            date.year = inputIntPositive();

            printf("Month (1-12): ");

            date.month = inputIntRange(1, 12);

            printf("Day (1-");
            if (date.month == 4 || date.month == 9 || date.month == 11)
            {
                monthLast = 30;
            }
            if (date.month == 2)
            {
                monthLast = 28;
            }
            if (date.year % 4 == 0 && date.month == 2)
            {
                monthLast = 29;
            }
            printf("%d)  : ", monthLast);
            date.day = inputIntRange(1, monthLast);
        
            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            if (available(date, time, ap, maxAppointments))
            {
                printf("\n");
                printf("ERROR: Appointment timeslot is not available!\n\n");

            }
            else
            {
                while ((time.hour < START || time.hour > END) || (time.hour == END && time.min > 0) || (time.min % TIME_INTERVALS != 0))
                {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START, END, TIME_INTERVALS);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);

                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);

                }
                notAvail = 0;
            }
            
        }
        index = availableSpot(ap, maxAppointments);
        ap[index].date = date;
        ap[index].time = time;
        ap[index].patientNumber = patientNum;
        printf("\n");
        printf("*** Appointment scheduled! ***\n\n");
    }
    else
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n\n");
    }
}

// Remove an appointment record from the appointment array
// Todo:

void removeAppointment(struct Appointment* ap, int maxAppointments, struct Patient patient[], int maxPatients)
{
    struct Date date;

    int index, patientNum, monthLast = 31, appointmentIndex;

    printf("Patient Number: ");
    patientNum = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNum, patient, maxPatients);

    if (index >= 0)
    {

        printf("Year        : ");

        date.year = inputIntPositive();

        printf("Month (1-12): ");

        date.month = inputIntRange(1, 12);

        printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11)
        {
            monthLast = 30;
        }
        if (date.month == 2)
        {
            monthLast = 28;
        }
        if (date.year % 4 == 0 && date.month == 2)
        {
            monthLast = 29;
        }
        printf("%d)  : ", monthLast);
        date.day = inputIntRange(1, monthLast);

        appointmentIndex = validRemove(patientNum, date, ap, maxAppointments);

        if (appointmentIndex >= 0)
        {
            printf("\n");

            displayPatientData(&patient[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");
            
            if (inputCharOption("yn") == 'y')
            {
                ap[appointmentIndex].patientNumber = 0;
                printf("\n");
                printf("Appointment record has been removed!\n\n");
                           
            }
            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
       
    }else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int next, maxNum = patient[0].patientNumber, i;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > max)
        {
            maxNum = patient[i].patientNumber;
        }
    }
    next = maxNum + 1;
    return next;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
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
//converts and arranges appointments in ascending order in minutes
void arrange(struct Appointment appoints[], int max)
{
    int i = 0, j = 0;
    struct Appointment tem;
 
    for(i = 0; i < max; i++)
    {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;

    }

    for(i = max - 1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(appoints[j].time.min > appoints[j+1].time.min)
            {
                tem = appoints[j]; 
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = tem;
            }
        }
    }

    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }
}


// check available timeslot 
int available(struct Date date, struct Time time, struct Appointment* ap, int maxAppointments)
{
    int i = 0, av = 0;
    for (i = 0; i < maxAppointments; i++)
    {
        if (date.year == ap[i].date.year && date.month == ap[i].date.month && 
            date.day == ap[i].date.day && time.hour == ap[i].time.hour
            && time.min == ap[i].time.min)
        {
            av = 1;
        }
    }
    return av;
}

//checks if the next slot is available and returns index value
int availableSpot(struct Appointment* ap, int maxAppointments)
{
    int i = 0, av = 0;

    while (av == 0 && i < maxAppointments)
    {
        if (ap[i].patientNumber < 1)
        {
            av = 1;
        }
        i++;
    }
    return i;
}

//checks if appointment is valid
int validRemove(int patientNumber, struct Date date, struct Appointment* ap, int maxAppointments)
{
    int i = 0, valid = 0;

    while (valid == 0 && i < maxAppointments)
    {
        if ((ap[i].patientNumber == patientNumber) && 
            (ap[i].date.day == date.day) &&
            (ap[i].date.month == date.month) && 
            (ap[i].date.year == date.year))
        {
            valid = 1;
        }
        i++;
    }
    return i - 1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
  int i = 0;

  FILE* fp;
  fp = fopen(datafile, "r");

  if(fp != NULL)
  {
      i = 0;
      while(fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF)
      {
          i++;
          if(i >= max)
          {
              break;
          }
      }
      fclose(fp);
  }
  else
  {
      printf("ERROR: File could not be read\n");
  }
  return i;

}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:

int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i, count = 0;

    FILE* fp;

    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        for (i = 0; i < max && !feof(fp); i++)
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            if (!feof(fp))
            {
                count++;
            }
        }fclose(fp);
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }
    return count;
}