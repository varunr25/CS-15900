/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Homework #: 4 
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program inputs the date as an integer and displays the number of days
*  remaining in the current month and for the rest of the year.  
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include<stdio.h>
#include<math.h>

#define JAN 31  // Defines the number of days in the month January.
#define FEB 28  // Defines the number of days in the month February.
#define MAR 31  // Defines the number of days in the month March.
#define APR 30  // Defines the number of days in the month April.
#define MAY 31  // Defines the number of days in the month May. 
#define JUN 30  // Defines the number of days in the month June.
#define JUL 31  // Defines the number of days in the month July.
#define AUG 31  // Defines the number of days in the month August.
#define SEP 30  // Defines the number of days in the month September.
#define OCT 31  // Defines the number of days in the month October.
#define NOV 30  // Defines the number of days in the month November.
#define DEC 31  // Defines the number of days in the month December.

void getInput(int*);
void numberItems(int, int*, int*, int*);
int leapYear(int);
int daysLeftMonth(int, int, int);
int daysLeftYear(int, int, int, int);
int isValid(int, int, int, int, int);
void displayResults(int, int, int);

int main() 
{
    int date;   // Variable use to store the date value that the user inputs.
    int days;   // Variable use to store the current day based off the input.
    int months; // Variable use to store the current month based off the input.
    int years;  // Variable use to store the current year based off the input.
    int remaining_month_days;   // Variable use to store the number of day remaining in the month.
    int remaining_year_days;    // Variable use to store the number of day remaining in the year.
    int leap_identifier;        // Boolean used to determine if the year is a leap year.
    int valid_identifier;       // Boolean used to determine if the inputted MMDDYYY is valid.

    getInput(&date);    //Stores the value from getInput into variable date.
    numberItems(date, &days, &months, &years);  //Stores the value from numberItems into variables for days, months, and years.

    leap_identifier = leapYear(years);       //Basically a boolean to determine if the year is a leap year. 1 if true, 0 if false
    remaining_month_days = daysLeftMonth(days, months, leap_identifier); // Stores the value from daysLeftMonth into variable remaining_month_days.
    remaining_year_days = daysLeftYear(days, months, years, leap_identifier); // Stores the value from daysLeftYear into variable remaining_year_days.
    valid_identifier = isValid(remaining_month_days, days, months, remaining_year_days, leap_identifier); // Stores the value from isValid into variable valid_identifier.

    displayResults(remaining_month_days, remaining_year_days, valid_identifier); // Function call of displayResults.
    
    return 0;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int* date: used to store the user input.
*
*  Function Description:
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void getInput(int* date)
{
    printf("Enter a date in the form MMDDYYYY -> ");
    scanf("%d", date);
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: numberItems
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int date: user inputted date
*    2. int* days: current day based off the input
*    3. int* months: current mont based off the input
*    4. int* years: current year based off the input
*
*  Function Description: Determines the number of month, days, and year based off the input.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void numberItems(int date, int* days, int* months, int* years)
{
    *months = (date / 1000000);  // Isolates the month value from the input (MM).
    *days = (date / 10000) % 100;  // Isolates the day value from the input (DD).
    *years = date % 10000; // Isolates the year value from the input (YYYY).
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: daysLeftMonth
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int days: current day based off the input
*    2. int months: current month based off the input
*    3. int identifier: boolean to determine if the input is a leap year. 1 if true, 0 if false.
*
*  Function Description: determines the number of days left in the current month.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int daysLeftMonth(int days, int months, int identifier)
{
    int current_month; //Variable used, in the switch structure, to determine the number of days in the current month.
    int remaining_days; //Variable used, after the switch structure, to determine the number of remaining days in the month.
    
    if (identifier == 1)
    {
        current_month = 29; // Special case for if the original input is a leap year.
    }
    else
    {
        switch(months)  
        {
            case 1: current_month = JAN;
                    break;
                
            case 2: current_month = FEB;
                    break;

            case 3: current_month = MAR;
                    break;

            case 4: current_month = APR;
                    break;

            case 5: current_month = MAY;
                    break;

            case 6: current_month = JUN;
                    break;

            case 7: current_month = JUL;
                    break;

            case 8: current_month = AUG;
                    break;

            case 9: current_month = SEP;
                    break;

            case 10: current_month = OCT;
                    break;

            case 11: current_month = NOV;
                    break;

            case 12: current_month = DEC;
                    break;
        }
    }
    
    remaining_days = current_month - days; // Calculates the remaining days in the month.

    return remaining_days;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: daysLeftYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int days: current day based off the input
*    2. int months: current month based off the input
*    3. int identifier: boolean to determine if the input is a leap year. 1 if true, 0 if false.
*
*  Function Description: determines the number of days left in the year.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int daysLeftYear(int days, int months, int years, int identifier)
{ 
    int remaining_years; //Variable used, after the switch structure, to determine the number of days in the current year.
    int days_end; //Variable used, in the switch structure to determine the amount of days remaining based off when the current month ends.
    
    switch(months)
    {
        case 1: days_end = 365;
                break;
            
        case 2: days_end = 365 - (JAN);              
                break;

        case 3: days_end = 365 - (JAN + FEB);
                break;

        case 4: days_end = 365 - (JAN + FEB + MAR);
                break;

        case 5: days_end = 365 - (JAN + FEB + MAR + APR);
                break;

        case 6: days_end = 365 - (JAN + FEB + MAR + APR + MAY);
                break;

        case 7: days_end = 365 - (JAN + FEB + MAR + APR + MAY + JUN);
                break;

        case 8: days_end = 365 - (JAN + FEB + MAR + APR + MAY + JUN + JUL);
                break;

        case 9: days_end = 365 - (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG);
                break;

        case 10: days_end = 365 - (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP);
                break;

        case 11: days_end = 365 - (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT);
                break;

        case 12: days_end = 365 - (JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT + NOV);
                break;
    }

    remaining_years = days_end - days;  //Calculations for the the remaining days in the year.

    if (identifier == 1)  // Special case for a leap year.
    {
        remaining_years = remaining_years + 1; 
    }

    return remaining_years;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: leapYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year: current year based off the input
*
*  Function Description: determines if the input is a leap year
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int leapYear(int year)
{
    int identifier; // Boolean integer used to determine if the input is a leap year. 1 if true, 0 if false.
    
    if (year % 4 == 0)
    {
            if (year % 100 != 0)
            {
                identifier = 1;
            }
            else if (year % 400 == 0)
            {
                identifier = 0;
            }
    }

    return identifier;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: isValid
*
*  Function Return Type: int 
*
*  Parameters (list data type, name, and comment one per line):
*    1. int remaining_month_days: number of days left in the month.
*    2. int days: current day based off the input
*    3. int months: current month based off the input
*    4. int remaining_year_days: number of days left in the year.  
*    5. int leap_identifier: boolean to determine if the input is a leap year. 1 if true, 0 if false.
*
*  Function Description: determines if the input is valid.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int isValid(int remaining_month_days, int days, int months, int remaining_year_days, int leap_identifier)
{
        int valid; // Boolean integer used to determine if the input is a valid date. 1 if true, 0 if false.

        if ((remaining_month_days < 0 || remaining_year_days < 0) || (months < 1 || months > 12) || (days < 1 || days > 31))
        {
           valid = 0;
        }
        else
        {
           valid = 1;
        }

    return valid;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: displayResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int days_month: number of days left in the month.
*    2. int days_year: number of days left in the year.
*    3. int valid: boolean to determine if the input is valid. 1 if true, 0 if false. 
*
*  Function Description: displays the results or an error, if there is one. 
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(int days_month, int days_year, int valid)
{
    if (valid == 1)
    {
        printf("\nDays remaining in current month: %d", days_month);
        printf("\nDays remaining in current year: %d", days_year);       
    }
    else if (valid == 0)
    {
        printf("\nError: Date entered is not valid!");
    }
}