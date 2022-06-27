/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Lab #: 8
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Given a user inputted number determine the minimum number of changes you would have 
*  to make such that the ending number would be composed of alternating digits 1 and 2.
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void userInput(long* input);
int numberOfChanges(long input);
void displayResults(int iterations);

int main()
{
    long input;     //Declaration of the variable used to store the user input.
    int iterations; //Declaration of the variable used to store the number of iterations from the numberOfChanges function.

    userInput(&input);  //Calls the userInput function.
    iterations = numberOfChanges(input);    //Calls the numberOfChanges function.
    displayResults(iterations); //Calls the displayResults function.
    
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
*    1. long* input: user inputted value
*
*  Function Description: gets the user inputted number and stores it in main.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void userInput(long* input) 
{
    int current_value;  //Declaration of the variable used to determine the current value, used in comparision with the previous value.
    long input_two;     //Variable used to replicate the input value.

    printf("Enter the initial configuration -> ");
    scanf("%ld", input);  //Stores the user input and passes the value back into main.

    current_value = 0;
    input_two = *input;

    while(input_two > 0)
    {
        current_value = input_two % 10;
        input_two = input_two / 10;

        if((current_value < 1) || (current_value > 2))
        {
            printf("\nError! Input must contain only digits 1 and 2!\n\n");
            printf("Enter the initial configuration -> ");
            scanf("%ld", input);  //Stores the user input and passes the value back into main.
        }
    } 
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: numberOfChanges
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. long input: user inputted value
*
*  Function Description: determine the minimum number of changes you would have to make 
*  such that the ending number would be composed of alternating digits 1 and 2.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
int numberOfChanges(long input)
{
    int iterations; //Declaration of the variable used for determining the number of times the loop changes the value.
    int current_value;  //Declaration of the variable used to determine the current value, used in comparision with the previous value.
    int previous_value; //Declaration of the variable used to determine the previous value, used in comparision with the current value.
    float counter; //Declaration of the variable used for determine the number of times the loop changers the value; this variable is returned by the function.

    iterations = 0;
    current_value = 0;
    previous_value = 0;

    while (input > 0)
    {
        previous_value = current_value;
        current_value = input % 10;
        input = input / 10;

        //printf("\nprevious_value: %d", previous_value);
        //printf("\ncurrent_value: %d", current_value);
        //printf("\niterations: %d", iterations);
        //printf("\n\ninput: %ld", input);
        
        if (previous_value == current_value)
        {
            if (current_value == 1)
            {
                current_value = 2;
                iterations += 1;
            }
            
            if (current_value == 2)
            {
                current_value = 2;
                iterations += 1;   
            }
            
        }
    }
    
    counter = (float) iterations / 2.0; 
    iterations = ceil(counter); //Rounds the number up

    return (iterations);
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
*    1. int iterations: number of times that the loop changed the value
*
*  Function Description: displays the number of required changes that the function numberOfChanges
*  made. 
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(int iterations)
{
    printf("\nFewest # of required changes: %d", iterations);
}