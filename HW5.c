/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Homework #: 8
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program asks the user to input 0 for even or 1 for odd, a starting value,
*  and an ending value. Using this information, the program finds the Boiler Numbers. If the boolean is odd, the 
*  Boiler Numbers that are displayed will also be odd; same if they are even.  
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>

void getInput(int* even_odd, int* start_value, int* end_value);
void boilerNumbers(int even_odd, int start_value, int end_value);
int getCounter(int even_odd, int start_value, int end_value);
void displayResults(int even_odd, int counter); 

int main()
{
    int even_odd;       //Declaration of the variable used to store the boolean for even or odd (0 = even, 1 = odd).
    int start_value;    //Declaration of the variable used to store the starting value.
    int end_value;      //Declaration of the variable used to store the ending value.
    int count;          //Declaration of the variable used to store the number of times that a boiler number is created.

    getInput(&even_odd, &start_value, &end_value);          //Calls the getInput function and stores the values for variables even_odd, start_value, end_value.
    count = getCounter(even_odd, start_value, end_value);   //Calls the getCounter function and stores the value in variable count.
    displayResults(even_odd, count);                        //Calls the displayResults function, which will print out an error or even/odd.
    boilerNumbers(even_odd, start_value, end_value);        //Calls the boilerNumbers function, which will display the boilerNumbers.

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
*    1. int* even_odd: the boolean for even or odd (0 = even, 1 = odd).
*    2. int* start_value: the starting value.
*    3. int* end_value: the ending value.
*
*  Function Description: gets the user's input and stores the value for the variable listed above
*  in the main function.  
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void getInput(int* even_odd, int* start_value, int* end_value)
{
    printf("Enter 0 for even or 1 for odd values -> "); //Gets the user input for the boolean (0 = even, 1 = odd).
    scanf("%d", even_odd);
    
    //If the user inputs a value that is neither 0 or 1, prints an error and reprompts.
    while ((*even_odd < 0) || (*even_odd > 1)) 
    {
        printf("\nError! Select a valid option!!\n\n");
        printf("Enter 0 for even or 1 for odd values -> ");
        scanf("%d", even_odd);
    }

    printf("Enter starting value -> ");     //Gets the user input for the starting value.
    scanf("%d", start_value);

    //If the user inputs a start value less than 0, prints an error and reprompts.
    while (*start_value <= 0) 
    {
        printf("\nError! Starting value must be positive!\n\n");
        printf("Enter starting value -> ");
        scanf("%d", start_value);
    }
    
    printf("Enter ending value -> ");   //Gets the user input for the ending value.
    scanf("%d", end_value);

    //If the user inputs a ending value less than or equal to the start value, prints an error and reprompts.    
    while ((*end_value == *start_value) || (*end_value < *start_value))  
    {  
        printf("\nError! Ending value must be > %d\n\n", *start_value);
        printf("Enter ending value -> ");
        scanf("%d", end_value);
    }
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: boilerNumbers
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int even_odd: the boolean for even or odd (0 = even, 1 = odd).
*    2. int start_value: the starting value.
*    3. int end_value: the ending value.
*
*  Function Description: calculates the Boiler Numbers and displays each one if the condition
*  (described in the comments within the function) are met.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void boilerNumbers(int even_odd, int start_value, int end_value)
{
    int boiler_num;     //Declaration of the variable used store the current Boiler Number.
    
    while (start_value <= end_value)
    {
        boiler_num = (start_value * (start_value + 1)) / 2; //Calculations to determine the Boiler Number.
        
        if(even_odd == 0)
        {
            if(boiler_num % 2 == 0)
            {
                printf("%d ", boiler_num);     //If the boolean is even and the Boiler Number is also even, prints out the Boiler Number.           
            }
        }
        
        else if(even_odd == 1)
        {
            if(boiler_num % 2 != 0)
            {
                printf("%d ", boiler_num);     //If the boolean is odd and the Boiler Number is also odd, prints out the Boiler Number.                   
            }
        }

        start_value++; //Increments the starting value and runs the loop again.
    }
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getCounter
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int even_odd: the boolean for even or odd (0 = even, 1 = odd).
*    2. int start_value: the starting value.
*    3. int end_value: the ending value.
*
*  Function Description: determines the number of times that a Boiler Number that meets the condition
*  (described in the comments within the function).
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int getCounter(int even_odd, int start_value, int end_value)
{
    int boiler_num;     //Declaration of the variable used to store the current Boiler Number.
    int count;          //Declaration of the variable used to determine the number of times that a Boiler Number is created. 

    count = 0;  //Starts the count at zero.

    while (start_value <= end_value)
    {
        boiler_num = (start_value * (start_value + 1)) / 2; //Calculations to determine the Boiler Number.
        
        if(even_odd == 0)
        {
            if(boiler_num % 2 == 0)
            {
                count++;    //If the boolean is even and the Boiler Number is also even, increments the variable count by 1.
            }
        }

        else if(even_odd == 1)
        {
            if(boiler_num % 2 != 0)
            {
                count++;    //If the boolean is odd and the Boiler Number is also odd, increments the variable count by 1.
            }
        }
        start_value++;
    }
    
    return count;    
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
*    1. int even_odd: the boolean for even or odd (0 = even, 1 = odd).
*    2. int counter: the number of times that a Boiler Number is created.
*
*  Function Description: displays the final results of the program.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(int even_odd, int counter)
{
    if (counter <= 0)
    {
        printf("\nError: No values generated.");
    }
    else if (counter > 0)
    {
        if (even_odd == 0)
        {
            printf("\nEven Boiler numbers: ");
        }
        else if (even_odd == 1)
        {
            printf("\nOdd Boiler numbers: ");
        }
    }
}