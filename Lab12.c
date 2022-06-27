/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Lab  #: 12
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes the user's unputs and check every value in the data set.
*  For every value in the data set that is a multiple of nine, change it to the value in its ones place. 
*  All values that are not multiples of nine can be changed into negative one (-1). Finally, the program
*  displays back to the user the possible locations of the street the loud sound may have originated from.
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void userInput(int* seed, int* size);
void generateValues(int *Arr, int size);
void checkMultNine(int *Arr, int size);
void reassign(int *Arr, int size);
void displayResults(int *Arr, int size);

int main()
{
    int seed;   //Declaration of the variable used for storing the user inputted seed value.
    int size;   //Declaration of the variable used for storing the user inputted size value.
    int *Arr;   //Declaration of the array used for storing the randomly generated values.
    
    userInput(&seed, &size);    //Calls the userInput function and stores the values in main.
    srand(seed);                //Uses the seed for generating values.
    
    Arr = (int*) malloc(sizeof(int) * size);    
    
    generateValues(Arr, size);  //Generates the values to store in the array.
    checkMultNine(Arr, size);   //Checks each element in the array to see if there is a multiple of 9.
    reassign(Arr, size);        //Reassigns values as needed.
    displayResults(Arr, size);  //Displays the final results to the user
    
    return 0;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: userInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int* seed: variable used for storing the user input seed value.
*    2. int* size: variable used for storing the user inputted size value.
*
*  Function Description: asks the user for their input and stores the values back in main.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void userInput(int* seed, int* size)
{
    int sd;     //Declaration of the variable used for storing the user input seed value.
    int sz;     //Declaration of the variable used for storing the user inputted size value.

    do
    {
        printf("Enter seed value -> ");
        scanf("%d", &sd);  //Stores the user input and passes the value back into main.

        if (sd <= 0)
        {
            printf("\nError! Positive seed values only!!\n\n");
        }
    } while (sd <= 0);

    *seed = sd;

    do
    {
        printf("Enter desired data set size -> ");
        scanf("%d", &sz);  //Stores the user input and passes the value back into main.

        if (sz <= 0)
        {
            printf("\nError! Positive range values only!!\n\n");
        }
    } while (sz <= 0);

    *size = sz;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: generateValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *Arr: the array of values.
*    2. int* size: variable used for storing the user inputted size value.
*
*  Function Description: stores a randomly generated value into each element in the array.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void generateValues(int *Arr, int size)
{
    int i;      //Declaration of the variable used for iterations.
    int range;  //Declaration of the variable used for determining the range of values in the array. 

    range = (999 - 0) + 1;  //Range calculations.

    for (i = 0; i < size; i++)
    {
        Arr[i] = (rand() % range);
    }
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: checkMultNine
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *Arr: the array of values.
*    2. int* size: variable used for storing the user inputted size value.
*
*  Function Description: check each element in the array to see if there is a multiple of 9. If
*  the element is not a multiple of 9, set the element value to -1.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void checkMultNine(int *Arr, int size)
{  
    int i;      //Declaration of the variable used for iterations.

    for (i = 0; i < size; i++)
    {
        if (Arr[i] % 9 == 0)
        {
            Arr[i] = (Arr[i] % 10);
        }
        
        else if (Arr[i] % 9 != 0)
        {   
            Arr[i] = -1;
        }
    }
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: reassign
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *Arr: the array of values.
*    2. int* size: variable used for storing the user inputted size value.
*
*  Function Description: reassigns the values in the array to the distance away from the home.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void reassign(int *Arr, int size)
{
    int i;          //Declaration of the variable used for iterations.
    int temp;       //Declaration of the variable used for the temporary value.
 
    for (i = 0; i < size; i++)
    {       
        if (Arr[i] != -1)
        {
            temp = i - Arr[i];  //Updates the temporary variable.
            if (temp >= 0)
            {
                Arr[temp] = 0;
            }
            
            temp = i + Arr[i];  //Updates the temporary variable.
            if (temp < size)
            {
                Arr[temp] = 0;
            }
        }
        
    }
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
*    1. int *Arr: the array of values.
*    2. int* size: variable used for storing the user inputted size value.
*
*  Function Description: displays the final results back to the user.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(int *Arr, int size)
{
    int i;          //Declaration of the variable used for iterations.
    int counter;    //Declaration of the variable used for counting the number of times a value was reassigned.
    
    counter = 0;    //Initializes the counter variable to zero.
    
    printf("\nPossible locations:");
    for(i = 0; i < size; i++)
    {
        if (Arr[i] == 0)
        {
            printf(" %d", i);
            counter++;
        }
    }
    
    if (counter == 0)
    {   
        printf(" None");
    }
}