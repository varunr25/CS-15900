/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
 *
 *  Lab #: 6
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: This program takes the user's input for four triangle side lengths.
                         Using these inputs, it calculates the largest possible triangle and the
                         sides it used to make it and the smallest possible triangle and the sides
                         it used to make it.
 *
 ******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/

#include <stdio.h>
#include <math.h>

void getInput(double* side, int num); //gets input values for sides
double triangleArea(double side_one, double side_two, double side_three); //finds the area of a triangle given 3 sides
void orderValues(double* side_two, double* side_three, double* side_four); //orders the values how they should be displayed
void noTri(double* side_one, double* side_two, double* side_three, double* side_four, double* smaller_area, double* larger_area); //checks to see if the triangle exists
void displayResults (double larger_area, double smaller_area, double side_one, double side_two, double side_three, double side_four); //displays our calculations in an organized way

int main ()
{
  double side_one; //stores the users input for side one
  double side_two; //stores the users input for side two
  double side_three; //stores the users input for side three
  double side_four; //stores the users input for side four

  double smaller_area; //stores the calculated small triangle area
  double larger_area; //stores the calculates large triangle area

  getInput(&side_one, 1); //Calls the getInput function and stores the input into side_one.
  getInput(&side_two, 2); //Calls the getInput function and stores the input into side_two.
  getInput(&side_three, 3); //Calls the getInput function and stores the input into side_three.
  getInput(&side_four, 4); //Calls the getInput function and stores the input into side_four.

  orderValues(&side_two, &side_three, &side_four); //Calls the orderValues function to rearrange the values.

  larger_area = triangleArea(side_one, side_two, side_three); //Calls the triangleArea function and stores the value in larger_area.
  smaller_area = triangleArea(side_one, side_three, side_four); //Calls the triangleArea function and stores the value in smaller_area.

  noTri(&side_one, &side_two, &side_three, &side_four, &smaller_area, &larger_area);

  displayResults(larger_area, smaller_area, side_one, side_two, side_three, side_four);

  return 0;
}

/*****+-*-****-***--**-**-*-***-**---*-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: getInput
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double* side: indexes the side variable we will store this in
 *    2. int num: tells what side we are entering a value for
 *
 *  Function Description: This function gets the user's inputs for each triangle side
 *   
 *
 ******+-*-****-***--**-**-*-***-**---*-*-*-**-*****************************/
void getInput(double* side, int num)
{
  printf("Enter length of side #%d -> ", num);
  scanf("%lf", side);
}

/*****+----**-**-*-*-*-*--*----*----**-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: triangleArea
 *
 *  Function Return Type:  double
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double side_one: first side of the triangle
 *    2. double side_two: second side of the triangle
 *    3. double side_three: third side of the triangle
 *
 *  Function Description: This function calculates the area of a triangle given
 *                        three side lengths
 *  
 *
 ******+----**-**-*-*-*-*--*----*----**-*-*-**-*****************************/
double triangleArea(double side_one, double side_two, double side_three)
{
  double p; //calculated height of the triangle
  double area; //calculated are of the triangle

  p = ((side_one + side_two + side_three) / 2.0);

  if (((side_one + side_two) <= side_three) && ((side_two + side_three) <= side_one) && ((side_one + side_three) <= side_two))
  {
    area = -1;
  }
  else
  {
    area = sqrt(p * (p - side_one) * (p - side_two) * (p - side_three));
  }

  return area;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: noTri
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double* side_one: indexes the value for side one
 *    2. double* side_two: indexes the value for side two
 *    3. double* side_three: indexes the value for side three
 *    4. double* side_four: indexes the value for side four
 *    5. double* smaller_area: indexes the value for the small triangle area
 *    6. double* larger_area: indexes the value for the large triangle area
 *
 *  Function Description: This function checks to see if the large triangle exists (side could be too big)
 *                        and if it is true, it will substitute the values with the small triangle area
 *
 ******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/

void noTri(double* side_one, double* side_two, double* side_three, double* side_four,  double* smaller_area, double* larger_area)
{
  if (*side_one + *side_three < *side_two)
  {
    *larger_area = *smaller_area;
    *side_two = *side_four;
  }

  else
  {
    return;
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
*    1. double* side_two: indexes the value for side two
*    2. double* side_three: indexes the value for side three
*    3. double* side_four: indexes the value for side four
*
*  Function Description: This function organizes the side values so they can be printed in the correct way
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/

void orderValues(double* side_two, double* side_three, double* side_four)
{
  double temp; //temporary value storage needed to swap

  if(*side_two < *side_three)
  {
    temp = *side_two;
    *side_two = *side_three;
    *side_three = temp;
  }

  if(*side_three < *side_four)
  {
    temp = *side_three;
    *side_three = *side_four;
    *side_four = temp;
  }
}

/*****+-*--***-***---***--*--**-***--*-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: displayResults
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double side_one: value for side one
 *    2. double side_two: value for side two
 *    3. double side_three: value for side three
 *    4. double side_four: value for side four
 *    5. double smaller_area: value for the small triangle area
 *    6. double larger_area: value for the large triangle area
 *
 *  Function Description: Displays the final result of the line distances and
 *  the interior angles.
 *
 ******+-*--***-***---***--*--**-***--*-*-*-**-*****************************/
void displayResults (double larger_area, double smaller_area, double side_one, double side_two, double side_three, double side_four)
{
  if (larger_area <= 0 || smaller_area <= 0)
  {
    printf("\nError: No triangles can be created from lengths given!\n");
  }
  
  else
  {
    printf ("\nLargest possible triangle area: %.2lf", larger_area);
    printf ("\nSide values used: %.1lf, %.1lf, %.1lf", side_one, side_two, side_three);

    printf ("\n\nSmallest possible triangle area: %.2lf", smaller_area);
    printf ("\nSide values used: %.1lf, %.1lf, %.1lf\n", side_one, side_four, side_three);
  }
}