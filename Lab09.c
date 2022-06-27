/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Lab #: 9
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program asks the user for their input and determines if the
*  input value is a perfect square or if it is a semi-square.  
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getInput(int *b);
int calculate(int start_value);
int perfectSquare(int b);
int semiSquare(int b);
void displayResults(int final_value);

int main()
{
    int start_value;    //Declaration of the variable used for input.
    int final_value;    //Declaration of the variable used for identification and displaying the results.

    getInput(&start_value);     //Calls the getInput function and sets start_value equal to the input.
    final_value = calculate(start_value);   //Calls the calculate function and sets final_value equal to the return.
    displayResults(final_value);   //Calls the displayResults function.

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
*    1. int *b: the user inputted value.
*
*  Function Description: Asks the user for their input and returns it to main.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void getInput(int *b)
{
    int input;    //Declaration of the variable used for temporarily storing the input.
    printf("Enter starting value -> ");
    scanf("%d", b);

    input = *b;   //Sets the temporary input equal to the input.

    while(input <= 0) //Loop to determine if there is an error with the initial input, If there is an error, reprompts the user.
    {
        printf("\nError! Positive values only!");
        printf("\n\nEnter starting value -> ");
        scanf("%d", b);
        input = *b;
    }
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: calculate
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int start_value: the user input
*
*  Function Description: determines if the input was a perfect square or semi square.  
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int calculate(int start_value)
{
    int perfect;    //Declaration of the variable used for storing the perfect square.
    int semi;       //Declaration of the variable used for storing the semi square.
    int calc;       //Declaration of the variable used for returning to main.
    
    perfect = -1;   //Initializes variable perfect to be -1.
    semi = -1;      //Initializes variable semi to be -1.     

    while (perfect < 0 && semi < 0) //Determines if the input is a perfect square or semi square.
    {
        perfect = perfectSquare(start_value);
        semi = semiSquare(start_value);
        start_value++;  
    }

    if (perfect > 0)
    {
        calc = perfect;
    }
    else
    {
        calc = semi * -1; 
    }

    return calc;
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
*    1. int b: the user inputted value
*
*  Function Description: determines if the user inputted value is a perfect square.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int perfectSquare(int b)
{
    int boolean;    //Declaration of the variable used as a boolean variable.
    int square;     //Declaration of the variable used for storing the perfect square value.

    square = (int) sqrt(b) * (int) sqrt(b); //Squares the b value and stores it.

    if (square == b)
    { 
        boolean = b;
    }
    else
    { 
        boolean = -1;
    }

    return boolean;
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
*    1. int b: the user inputted value
*
*  Function Description: if the user inputed value is a semi square, determines the 
*  identfied value.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int semiSquare(int b)
{
    int a;      //Declaration of the variable used for the product of the square of another integer.
    int c;      //Declaration of the variable used for the third integer.
    int final_value;    //Declaration of the variable used for final value that will be returned to main.

    final_value = 0;    //Initializes final_value to zero.

    for (a = 3; a < (b / 2); a++)
    {
        for (c = 2; c < a; c++)
        {
            if (b % c == 0)
            {
                if (a == (int) sqrt(perfectSquare(b / c)))
                { 
                    final_value = b;
                }
                else if (final_value > 0)
                { 
                    final_value = final_value;
                }
                else
                { 
                    final_value = -1;
                }
            }
            
            else if (final_value > 0)
            { 
                final_value = final_value;
            }
            
            else
            { 
                final_value = -1;
            }
        }
    }

    return final_value;
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
*    1. int final_value: the identified value
*
*  Function Description: displays the final results of all the calculations.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(int final_value)
{
  printf("\nIdentified value: %d\nStatus: ", abs(final_value));

  if (final_value > 0)
  {
    printf("Perfect square\n");
  }

  else
  {
    printf("Semi-square\n");
  }
}