/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Lab #: 11
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes the user inputted seed and generates an array
*  of randomly generated values and finds the number of perfect squares and semi squares, if any,
*  and displays them to the user.   
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100        //Sets the default size to 100.

void userInput(int* seed, int* range);
void orderValues(int Arr[]);
void generateValues(int Arr[], int range);
int perfectSquare(int Arr[], int* max);
int semiSquare(int Arr[], int max);

int main()
{
    int seed;                   //Declaration of the variable used for storing the seed value.
    int range;                  //Declaration of the variable used for storing the range.
    int Arr[SIZE] = {0};        //Declaration of the array used for storing all 100 elements.
    int max;                    //Declaration of the variable used for the maximum number.
    int count;                  //Declaration of the variable used for the total count of iterations.

    userInput(&seed, &range);   //Calls the userInput function.
    srand(seed);                //Uses the seed for generating values.
    
    generateValues(Arr, range); //Calls the generateValues function.
    orderValues(Arr);           //Calls the orderValues function.
    
    max = 0;                    //Initalizes the max to zero.
    count = perfectSquare(Arr, &max) + semiSquare(Arr, max);   //Calculuates the total number of iterations between the two functions.

    if(count == 0)  //If no values are found, prints out an error message.
    {
        printf("Result: No perfect or semi-squares found.");
    }

    return(0);
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
 *    1. int* seed: the user inputted seed value.
 *    2. int* range: the user inputted range value.
 *
 *  Function Description: gets the user inputs and stores the values back in main.
 *
 ******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void userInput(int* seed, int* range)
{
    int sd;     //Declaration of the variable used for storing the user input seed value.
    int rng;    //Declaration of the variable used for storing the user inputted range value.

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
        printf("Enter maximum range value -> ");
        scanf("%d", &rng);  //Stores the user input and passes the value back into main.

        if (rng <= 0)
        {
            printf("\nError! Positive range values only!!\n\n");
        }
    } while (rng <= 0);

    *range = rng;
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
 *    1. int Arr[]: the array of randomly generated values.
 *    2. int range: the user inputted range.
 *
 *  Function Description: generates 100 values and fills the array with the values.
 *
 ******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
 void generateValues(int Arr[], int range)
{
    int i; //Declaration of the variable used for iterations.

    for (i = 0; i < SIZE; i++)
    {
        Arr[i] = (rand() % range) + 1;
    }
}

 /*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: orderValues
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *  1. int Arr[]: the array of randomly generated values.
 *
 *  Function Description: uses a bubble sort to order the values in the array from 
 *  least to greatest.
 *
 ******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
 void orderValues(int Arr[])
{
    int i;      //Declaration of the variable used for iterating the first for-loop.
    int j;      //Declaration of the variable used for iterating the sceond for-loop.
    int temp;   //Declaration of the variable used for temporary variable.    

    for(i = 1; i < SIZE; i++)
    {
        for(j = 0; j < SIZE-i; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }
}

 /*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: perfectSquare
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int Arr[]: the array of randomly generated values.
 *    2. int* max: the values of the maximum value.
 *
 *  Function Description: determines the number of perfect squares and displays them to the user. Returns the 
 *  number of iterations to main.
 *
 ******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
 int perfectSquare(int Arr[], int* max)
{
    int sqrval;         //Declaration of the variable used for temporary storage for the base of the perfect square
    int i;              //Declaration of the variable used for iterating the first for-loop.
    int counter;        //Declaration of the variable used for the counter variable. 

    counter = 0;        //Initializes the counter to zero.
    *max = (int)sqrt(Arr[SIZE-1]);  //Finds the maximum square.

    for(i = 0; i < SIZE; i++)
    {
        for(sqrval = 1; sqrval <= *max; sqrval++)
        {
            if(Arr[i] == sqrval * sqrval)
            {
                if(counter == 0)
                {
                    printf("\nPerfect squares:");
                }

                printf(" %d", Arr[i]);
                Arr[i] = 0;
                counter++;
            }
        }
    }

    printf("\n");
    return counter;
}

 /*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: semiSquare
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int Arr[]: the array of randomly generated values.
 *    2. int* max: the values of the maximum value.
 *
 *  Function Description: determines the number of semi-square and displays them to the user. Returns the 
 *  number of iterations to main.
 *
 ******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int semiSquare(int Arr[], int max)
{
    int ssValue;    //Declaration of the variable used for the base of the perfect-square factor in semi-square.
    int square;     //Declaration of the variable used for the perfect-square factor in semi-square calculation.
    int c_count;    //Declaration of the variable used for the third integer in semi-square.
    int semi;       //Declaration of the variable used for the value of semi-square which updates in each iteration.
    int i;          //Declaration of the variable used for iterating the for-loop.
    int counter;    //Declaration of the variable used for the total number of iterations.    
    int ct;         //Declaration of the variable used for the number of iterations while displaying a semi square value.

    counter = 0;    //Intializes the overall counter to 0.

    for (i = 0; i < SIZE; i++)
    {
        ct = 0;
        for (ssValue = 1; ssValue < max; ssValue++)
        {
            square = ssValue * ssValue;

            for (c_count = 1; c_count < ssValue; c_count++)
            {
                semi = square * c_count;
                
                if (Arr[i] == semi && ct == 0)
                {
                    if (counter == 0)
                    {
                        printf("Semi-squares:");
                    }
                    printf(" %d", Arr[i]);
                    counter++;
                    ct++;
                }
            }
        }
    }

    return counter;
}