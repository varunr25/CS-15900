/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Homework #:3
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program asks the user to enter the percentage of defective units produced, 
*  enter number of units to sample, and enter number of defective units in sample. Using this information,
*  the program finds the binomial distribution and outputs it.
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/
#include<stdio.h>
#include<math.h>

void getInput(double* percent_defective, int* num_units, int* defective_units);
double factorial(double defective_units);
double binomialDistribution(double num_units, double defective_units, double percent_defective);
void displayResults(double average, int num_units, double prob1, int defective_units, double prob2);

int main()
{
    double percent_defective;       //Declaration of the percentage of defective units.
    int num_units;                  //Declaration of the number of units in the sample.
    int defective_units;            //Declaration of the number of defective units.
    double probability_zero;        //Declaration of the probability of zero.
    double probability_defective;   //Declaration of the probability of defective units.

    getInput(&percent_defective, &num_units, &defective_units); //Gets the inputs from the user.

    probability_zero = binomialDistribution(num_units, 0, percent_defective);   //Stores the value from binomialDistribution into the variable.
    probability_defective = binomialDistribution(num_units, defective_units, percent_defective); //Stores the value from binomialDistribution into the variable. 

    displayResults(percent_defective, num_units, probability_zero, defective_units, probability_defective); //Displays the final results.
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
*    1. double, percent_defective: user enters the percentage of defective units.
*    2. int, num_units: user enters the number of units to sample.
*    3. int, defective_units: user enters the number of defective units.
*
*  Function Description: This function gets the user inputs for the variables listed above. 
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void getInput(double* percent_defective, int* num_units, int* defective_units)
{
    printf("Enter percentage of defective units produced -> ");
    scanf("%lf", percent_defective);

    printf("Enter number of units to sample -> ");
    scanf("%d", num_units);
      
    printf("Enter number of defective units in sample -> ");
    scanf("%d", defective_units);
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: factorial
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double defective_units: number of defective units
*
*  Function Description: This number finds the factorial of the number of defective units.
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double factorial(double defective_units)
{
    double factorial;   //Declaration of the factorial.
    factorial = (pow(defective_units, defective_units)) * (exp(defective_units * -1.0)) * (sqrt((2.0 * defective_units + (1.0/3.0)) * M_PI));   //Calculates the factorial.

    return factorial;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: binomialDistribution
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double num_units: number of units
*    2. double defective_units: number of defective units
*    3. double percent_defective: percent of defective units
*
*  Function Description: This function finds the binomial distribution with the numbers above.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double binomialDistribution(double num_units, double defective_units, double percent_defective)
{
    double binomial_distribution; //Declaration of the binomial distrubution. 
    double factorial_one;   //Declaration of the 1st factorial.
    double factorial_two;   //Declaration of the 2nd factorial.
    double factorial_three; //Declaration of the 3rd factorial.
    double rate_one;    //Declaration of the 1st rate.
    double rate_two;    //Declaration of the 2nd rate.

    rate_one = (percent_defective * 0.01);  //Calculations for the 1st rate.
    rate_two = (1.0 - rate_one);    //Calculations for the 2nd rate.
        
    factorial_one = factorial(num_units);   //Stores the value from the factorial function into the variable.
    factorial_two = factorial(num_units - defective_units); //Stores the value from the factorial function into the variable.
    factorial_three = factorial(defective_units);   //Stores the value from the factorial function into the variable.
    
    binomial_distribution = pow(rate_one, defective_units) * pow(rate_two, (num_units - defective_units)) * factorial_one / (factorial_two * factorial_three);  //Calculations of the binomial distribution
    
    return binomial_distribution;
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
*    1. double percent_defective
*    2. int num_units
*    3. double probability_zero
*    4. int defective_units
*    5. double probability_defective
*
*  Function Description: This function takes all of the collected data as well as the 
*  calculations and displays them to the user.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
void displayResults(double percent_defective, int num_units, double probability_zero, int defective_units, double probability_defective)
{
    printf("\nAverage number of defective units: %1.4lf", percent_defective);
    printf("%c", 37);
    printf("\nSelecting %d units with 0 being defective has a probability of: %0.3lf", num_units, probability_zero);
    printf("\nSelecting %d units with %d being defective has a probability of: %0.3lf", num_units, defective_units, probability_defective);
}