/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Homework #: 7
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Asks the user for a seed value and power value that will be used
*  for randomly generating values of an array of size 1000. Then, the program rearranges 
*  the digits of the individual elements in the array and then sorts the values. Finally, 
*  the program prints out the largest 5 elements after rearranging the elements and digits in
*  descending order and the smallest 5 elements in ascending order.
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1000

void getInput(int *seed, int *power);
void sortValues(int Arr[]);
void sortDigits(int Arr[]);
void generateValues(int Arr[], int range);
void displayResults(int Arr[]);

int main()
{
    int seed;       //Declaration of the variable used to store the user inputted seed value.
    int power;      //Declaration of the variable used to store the user inputted power.
    int Arr[SIZE];  //Declaration of the array used to store the elements.        

    getInput(&seed, &power);    //Calls the getInput function and stores the values for seed and power in main.
    srand(seed);                //Uses the srand function.

    generateValues(Arr, power); //Calls the generateValues function.
    
    sortDigits(Arr);    //Calls the sortDigits function.
    sortValues(Arr);    //Calls the sortValues function.
    
    displayResults(Arr);    //Calls the displayElements function.

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
*    1. int *seed: the user inputted seed value.
*    2. int *power: the user inputted power value.
*
*  Function Description: Asks the user for their input and sends the values to main.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void getInput(int *seed, int *power)
{
    int input;      //Declaration of the temporary variable used to store the input
    printf("Enter seed value -> ");
    scanf("%d", &input);

    *seed = input;   //Sets the temporary input equal to the variable that will be passed back to main.

    while(input <= 0) //Loop to determine if there is an error with the initial input, If there is an error, reprompts the user.
    {
        printf("\nError! Positive seed values only!!");
        printf("\n\nEnter seed value -> ");
        scanf("%d", &input);
        *seed = input;  //Sets the temporary input equal to the variable that will be passed back to main.
    }

    printf("Enter maximum power of ten for range -> ");
    scanf("%d", &input);

    *power = input;   //Sets the temporary input equal to the variable that will be passed back to main.

    while(input > 8) //Loop to determine if there is an error with the initial input, If there is an error, reprompts the user.
    {
        printf("\nError! Power of ten cannot exceed eight!\n\n");
        printf("Enter maximum power of ten for range -> ");
        scanf("%d", &input);
        *power = input; //Sets the temporary input equal to the variable that will be passed back to main.
    }
    
    while(input <= 0) //Loop to determine if there is an error with the initial input, If there is an error, reprompts the user.
    {
        printf("\nError! Power of ten must be positive!!\n\n");
        printf("Enter maximum power of ten for range -> ");
        scanf("%d", &input);
        *power = input; //Sets the temporary input equal to the variable that will be passed back to main.
    }
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
*    1. int Arr[]: the array of values.
*    2. int power: the user inputted power value.
*
*  Function Description: fills the array with randomly generated values.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void generateValues(int Arr[], int power)
{
    int i;      //Declaration of the variable used for iterations.
    int range;  //Creating the range of values for random generation.

    range = pow(10, power); //Calculating the range

    for (i = 0; i < SIZE; i++)
    {
        Arr[i] = (rand() % range);
    }
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: sortValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int Arr[]: the array of values.
*
*  Function Description: sorts the values in the array.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void sortValues(int Arr[])
{
    int i;      //Declaration of the variable used for the first for-loops iterations.
    int j;      //Declaration of the variable used for the second for-loops iterations.
    int temp;   //Declaration of the variable used for the temporary variable.

    for (i = 0; i < SIZE; i++)  //Bubble Sort algorithm. 
    {
        for (j = 0; j < SIZE - 1; j++)
        {
            if (Arr[j] > Arr[j + 1])
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
*  Name of Function: sortDigits
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int Arr[]: the array of values.
*
*  Function Description: sorts the digits of each element in the array.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void sortDigits(int Arr[])
{
    int i;           //Declaration of the variable used for the first for-loops iterations.
    int digit;       //Declaration of the variable used for the second for-loops iterations.
    int temp;        //Declaration of the variable used for the temporary variable.
    int num;         //Declaration of the variable used for the final variable for changing the digits of an element of Arr[].

    num = 0;         //Initializes num to zero.

    for (i = 0; i < SIZE; i++)
    {
        for (digit = 9; digit >= 0; digit--)
        {
            for (temp = Arr[i]; temp > 0; temp /= 10)
            {
                if (temp % 10 == digit)
                {
                    num = (num * 10) + digit;
                }        
            }
        }

        Arr[i] = num;   //Reassigns Arr[i] to the rearranged digits number.
        num = 0;    //Resets num to zero.
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
*    1. int Arr[]: the array of values.
*
*  Function Description: displays the final results to the user.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(int Arr[])
{
    int i;  //Declaration of the variable used for the for-loops iterations.

    printf("\nLargest 5 values in data:");

    for (i = SIZE - 1; i > SIZE - 6; i--)
    {
        printf(" %d", Arr[i]);
    }

    printf("\nSmallest 5 values in data:");

    for (i = 0; i < 5; i++)
    {
        printf(" %d", Arr[i]);
    }
}