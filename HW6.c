/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Homework #: 6
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Given a seed for the random number generator, 
*  create a data set of 75 elements in the range from 1 to 100 (inclusive of both endpoints) 
*  and display the mean, standard deviation, values less than one deviation from the mean, 
*  and values greater than one deviation from the mean.
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 75

int userInput();
void arrayCreation(int Arr[]);
double meanCalculation(int Arr[]);
double standardDevCalculation(int Arr[], double mean);
void displayResults(int Arr[], double mean, double standard_dev);

int main()
{
    int seed_value;         //Declaration of the variable used to store the user inputted seed value.
    int Arr[SIZE];          //Declaration of the empty array.
    double mean;            //Declaration of the variable used to store the mean of all elements in Arr.
    double standard_dev;    //Declaration of the variable used to store the standard deviation of all elements in Arr.

    seed_value = userInput();   //Stores seed_value to the input.
    arrayCreation(Arr);         //Sets each element of the array to randomly generated values.
    mean = meanCalculation(Arr);    //Finds the mean of all of the elements in array Arr.
    standard_dev = standardDevCalculation(Arr, mean);   //Finds the standard deviation of all of the elements in array Arr.
    displayResults(Arr, mean, standard_dev);    //Displays the final results.

    return 0;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: userInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: asks the user for their input and returns the number to main.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int userInput() 
{
    int seed_value;     //Declaration of the variable used to store the user input.
    
    do
    {
        printf("Enter seed value -> ");
        scanf("%d", &seed_value);  

        if (seed_value <= 0)
        {
            printf("\nError! Positive seed values only!!\n\n");
        }
    } while (seed_value <= 0);
  
    srand(seed_value); //Generates the series of random values.
    
    return (seed_value); 
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: arrayCreation
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int Arr[]: empty array of size 75.
*
*  Function Description: creates an array of size 75 and assigns a random generated number
*  to each element of the arry.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void arrayCreation(int Arr[])
{
    int i; //Declaration of the variable used as an iteration increment.

    for(i = 0; i < SIZE; i++)
    {
        Arr[i] = rand() % 100 + 1;  //Assigns the element in the array to a random number.
    }
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: meanCalculation
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int Arr[]: empty array of size 75.
*
*  Function Description: finds the mean of all of the elements in array Arr.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double meanCalculation(int Arr[])
{
    double sum;     //Declaration of the variable used to store the sum of all elements in Arr.
    double mean;    //Declaration of the variable used to store the mean.
    int i;          //Declaration of the variable used as an iteration increment.

    for (i = 0; i < SIZE; i++)
    {
        sum += Arr[i];  //Adds to the sum.
    }

    mean = sum / SIZE;  //Calculates the mean.

    return mean;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: standardDevCalculation
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int Arr[]: empty array of size 75.
*    2. double mean: the mean of all of the elements in array Arr.
*
*  Function Description: calculates the standard deviation of all of the element
*  within array Arr.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double standardDevCalculation(int Arr[], double mean)
{
    double deviation;    //Declaration of the variable used to store
    int i;               //Declaration of the variable used as an iteration increment.

    deviation = 0;      //Initializes the standard deviation at zero.

    for (i = 0; i < SIZE; i++)
    {
        deviation += pow(Arr[i] - mean, 2); 
    }

    deviation /= SIZE - 1;
    deviation = sqrt(deviation);

    return deviation;
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
*    1. int Arr[]: empty array of size 75.
*    2. double mean: the mean of all of the elements in array Arr.
*    3. double standard_dev: the standard deviation of all of the elements in array Arr.
*
*  Function Description:
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(int Arr[], double mean, double standard_dev)
{
    int i;  //Declaration of the variable used as an iteration increment.

    printf("\nData set mean: %.1lf", mean);
    printf("\nData set standard deviation: %.1lf", standard_dev);
    printf("\nValues less than one deviation from mean: ");
    for (i = 0; i < SIZE; i++)
    {
        if (Arr[i] < (mean - standard_dev))
        {
            printf("%d ", Arr[i]);
        }
    }
    printf("\nValues greater than one deviation from mean: ");
    for (i = 0; i < SIZE; i++)
    {
        if (Arr[i] > (mean + standard_dev))
        {
            printf("%d ", Arr[i]);
        }
    }
}