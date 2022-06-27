/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Lab #: 10
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:Using a user inputted seed value, generates 500 points (x,y), 
*  finds the maximum distance between two points, the number of horizontal lines, and 
*  the number of vertical lines. 
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 500

int userInput();
void generateValues(int A[], int B[]);
int checkHoriz(int A[], int B[]);
int checkVert(int A[], int B[]);
double calcDistance(int A[], int B[]);
void displayResults(double maxDist, int horiCount, int vertCount);

int main()
{
    int seed;       //Declaration of the variable used for the inputted seed value.
    int A[SIZE];    //Array of X values
    int B[SIZE];    //Array of Y values
    int vertCount;  //Declaration of the variable used for storing the number of vertical lines.
    int horiCount;  //Declaration of the variable used for storing the number of horizontal lines.
    double maxDist; //Declaration of the variable used for storing the maximum distance value.

    seed = userInput();       //Calls function userInput and generates the random values.
    srand(seed);              //generates the series of random values

    generateValues(A, B);           //Calls function generateValues to fill arrays A and B with random values.
    vertCount = checkVert(A,B);     //Calls function checkVert and stores the value in the variable vertCount.
    horiCount = checkHoriz(A,B);    //Calls function checkHoriz and stores the value in the variable horiCount.  
    maxDist = calcDistance(A, B);   //Calls function calcDistance and stores the value in the variable maxDist.
    displayResults(maxDist, horiCount, vertCount);      //Calls function displayResults.
    
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
*  Function Description: stores the user inputted seed value.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int userInput() 
{
    int sd; //Declaration of the variable used for storing the user input
    
    do
    {
        printf("Enter seed value -> ");
        scanf("%d", &sd);  //Stores the user input and passes the value back into main.

    if (sd <= 0)
    {
        printf("\nError! Positive seed values only!!\n\n");
    }
  } while (sd <= 0);
    
    return (sd); //returns the seed to the main function
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
*    1. int A[]: array of X values.
*    2. int B[]: array of Y values.
*
*  Function Description:
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void generateValues(int A[], int B[])
{
    int i; //Declaration of the variable used for iterations.
    
    for (i = 0; i < SIZE; i++)
    {
        A[i] = (rand() % 201) - 100;
        B[i] = (rand() % 201) - 100;
    }
    return;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: checkHoriz
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int A[]: array of X values.
*    2. int B[]: array of Y values.
*
*  Function Description: determines the number of horizontal lines.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int checkHoriz(int A[], int B[])
{
    int i;          //Declaration of the variable used for iterations. 
    int j;          //Declaration of the variable used for iterations.
    int counter;    //Declaration of the variable used for counting the number of times the if statement is true.    

    counter = 0;    //Initializes the counter variable to 0.    
    
    for (i = 0; i < SIZE; i++)
    {
        for (j = i + 1; j < SIZE; j++)
        {
            if (B[i] == B[j] && A[i] != A[j])
            {
                counter++;
            }
        }
    }

    return (counter);
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: checkVert
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int A[]: array of X values.
*    2. int B[]: array of Y values.
*
*  Function Description: determines the number of vertical lines.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int checkVert(int A[], int B[])
{
    int i;          //Declaration of the variable used for iterations. 
    int j;          //Declaration of the variable used for iterations.
    int counter;    //Declaration of the variable used for counting the number of times the if statement is true.       
    
    counter = 0;    //Initializes the counter variable to 0.
    
    for (i = 0; i < SIZE; i++)
    {
       for (j = i + 1; j < SIZE; j++)
       {
            if (A[i] == A[j] && B[i] != B[j])
            {
                counter++;
            }
       }
    }

    return (counter);
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: calcDistance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int A[]: array of X values.
*    2. int B[]: array of Y values.
*
*  Function Description: finds the maximum distance value between two points.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double calcDistance(int A[], int B[])
{
    int i;              //Declaration of the variable used for 
    int j;              //Declaration of the variable used for 
    double dist;        //Declaration of the variable used for 
    double maxDist;     //Declaration of the variable used for 

    maxDist = 0;

    for (i = 0; i < SIZE; i++)
    {
        for (j = i + 1; j < SIZE; j++)
        {
           dist = sqrt(pow(A[j] - A[i], 2) + pow(B[j] - B[i], 2)); 
           if (dist > maxDist)
           {
               maxDist = dist;
           }
        }
    }   

    return maxDist;
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
*    1. double maxDist: value of the maximum distance.
*    2. int horiCount: number of horizontal lines.
*    3. int vertCount: number of vertical lines.
*
*  Function Description: displays the final results back to the user.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(double maxDist, int horiCount, int vertCount)
{
    printf("\nMaximum Distance: %0.1lf\n", maxDist);
    printf("Horizontal Lines: %d\n", horiCount);
    printf("Vertical Lines: %d", vertCount);
}