/*****+*---**----*-**--*-*---**-----**-*-*-**-******************************
*
*  Lab #: 5
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes the user's inputs to find a third angle, the find the
   exterior angle and distance of each of the three lines.
*
******+*---**----*-**--*-*---**-----**-*-*-**-*****************************/

#include <stdio.h>
#include <math.h>

void getInput(double* xc, double* yc, double* angle, int num);
double distance (double one_xc, double one_yc, double two_xc, double two_yc);
double constant (double one_xc, double one_yc, double one_angle);
double xcoordinate(double one_angle, double one_constant, double two_angle, double two_constant);
double ycoordinate (double one_angle, double one_constant, double three_xc);
double angle(double one_distance, double two_distance, double three_distance);
void displayResults (double one_distance, double two_distance, double three_distance, double one_angle, double two_angle, double three_angle);

int main ()
{
  double one_xc;            //Declaration of the first X-coordinate.
  double one_yc;            //Declaration of the first Y-coordinate.
  double one_angle;   //Declaration of the 1st angle input.

  double two_xc;            //Declaration of the second X-coordinate.
  double two_yc;            //Declaration of the second Y-coordinate.
  double two_angle;   //Declaration of the 2nd angle input.

  double three_xc;    //Declaration of the third X-coordinate.
  double three_yc;    //Declaration of the third Y-coordinate.
  double three_angle; //Declaration of the third angle.

  double one_constant;  //Declaration of the first constant.
  double two_constant;  //Declaration of the second constant.

  double one_two_distance;    //Declaration of the variable use to store Line 1
  double one_three_distance;  //Declaration of the variable use to store Line 2
  double two_three_distance;  //Declaration of the variable use to store Line 3

  getInput(&one_xc, &one_yc, &one_angle, 1);  //Gets the user inputs for the first x and y coordinates and angle.
  getInput(&two_xc, &two_yc, &two_angle, 2);  //Gets the user inputs for the second x and y coordinates and angle.

  one_constant = constant(one_xc, one_yc, one_angle);  //Stores the value from the constant function into variable one_constant.
  two_constant = constant(two_xc, two_yc, two_angle);  //Stores the value from the constant function into variable two_constant.

  three_xc = xcoordinate(one_angle, one_constant, two_angle, two_constant);  //Stores the value from the xcoordinate function into variable three_xc.
  three_yc = ycoordinate(one_angle, one_constant, three_xc); //Stores the value from the ycoordinate function into variable three_yc.

  one_two_distance = distance(one_xc, one_yc, two_xc, two_yc);   //Stores the value from the distance function in variable one_two_distance.
  two_three_distance = distance(two_xc, two_yc, three_xc, three_yc); //Stores the value from the distance function in variable two_three_distance.
  one_three_distance = distance(one_xc, one_yc, three_xc, three_yc); //Stores the value from the distance function in variable one_three_distance.

  one_angle = angle(one_two_distance, one_three_distance, two_three_distance); //Stores the value from the angle function in variable one_angle.
  two_angle = angle(two_three_distance, one_two_distance, one_three_distance); //Stores the value from the angle function in variable two_angle.
  three_angle = angle(two_three_distance, one_three_distance, one_two_distance); //Stores the value from the angle function in variable three_angle.

  displayResults(one_two_distance, two_three_distance, one_three_distance, one_angle, two_angle, three_angle); //Calls the displayResults function

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
*    1. double* xc: x-coordinate input.
*    2. double* yc: y-coordinate input.
*    3. double* angle: angle input.
*    4. int num: tells the user which coordinate point they are entering.
*
*  Function Description: This function asks the user to input values for the 
*  x and y coordinates of three different points. 
*
******+-*-****-***--**-**-*-***-**---*-*-*-**-*****************************/
void getInput(double* xc, double* yc, double* angle, int num)
{
    printf("Enter coordinates for point #%d -> ", num);
    scanf("%lf %lf", xc, yc);

    printf("Enter angle at x-axis for line passing through point #%d -> ", num);
    scanf("%lf", angle);
}

/*****+----**-**-*-*-*-*--*----*----**-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: distance
 *
 *  Function Return Type: double 
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double one_xc, X-coordinate #1
 *    2. double one_yc, Y-coordinate #1
 *    3. double two_xc, X-coordinate #2
 *    4. double two_yc, Y-coordinate #2
 *
 *  Function Description: This function finds the distance between two points when given
 *  the x and y coordinates of the two points.
 *
 ******+----**-**-*-*-*-*--*----*----**-*-*-**-*****************************/
double distance(double one_xc, double one_yc, double two_xc, double two_yc)
{
  double distance;  //Declaration of the distance variable.
  distance = sqrt (pow ((one_xc - two_xc), 2.0) + pow ((one_yc - two_yc), 2.0)); //Distance calculations.

  return distance;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: constant
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double one_xc, X-coordinate #1
*    2. double one_yc, Y-coordinate #1
*    3. double one_angle, angle #1
*
*  Function Description:
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double constant(double one_xc, double one_yc, double one_angle)
{
  double constant;	//Declaration of the constant variable.
  constant = one_yc - one_xc * tan (one_angle * M_PI / 180); //Constant calculations.

  return constant;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: xcoordinate
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double one_angle, angle #1
*    2. double one_constant, constant #1
*    3. double two_angle, angle #2
*    4. double two_constant, constant #2
*
*  Function Description: This function finds the x-coordinate of the 3rd point.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double xcoordinate(double one_angle, double one_constant, double two_angle, double two_constant)
{
  double three_xc;		  //Declaration of the x-coordinate of point 3.
  double one_gradient;	//Declaration of the gradient for line 1.
  double two_gradient;	//Declaration of the gradient for line 2.

  one_gradient = tan (one_angle * M_PI / 180);	//Line 1 gradient calculations.
  two_gradient = tan (two_angle * M_PI / 180);  //Line 2 gradient calculations.
  three_xc = (two_constant - one_constant) / (one_gradient - two_gradient); //X-coordinate calculations.
 
  return three_xc;
}

/*****+*--**-----*-**--*-*---**-----**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: ycoordinate
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double one_angle, angle #1.
*    2. double one_constant, constant #1.
*    3. double three_xc, x-coordinate #3.
*
*  Function Description: This function finds the y-coordinate of the 3rd point.
*
******+*--**-----*-**--*-*---**-----**-*-*-**-*****************************/
double ycoordinate (double one_angle, double one_constant, double three_xc)
{
  double three_yc;	  	//Declaration of the y-coordinate of point 3.
  double one_gradient;	//Declaration of the gradient for line 1.

  one_gradient = tan (one_angle * M_PI / 180);  //Line 1 gradient calculations
  three_yc = one_gradient * three_xc + one_constant; //Y-coordinate calculations.

  return three_yc;
}

/*****+----**-**-*-*-*-*--*----*----**-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: angle
 *
 *  Function Return Type: double 
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double one_distance, distance #1
 *    2. double two_distance, distance #2
 *    3. double three_distance, distance #3
 *
 *  Function Description: This function finds the interior angle of the line using 
 *  the previously found lines and the Law of Cosine.
 *
 ******+----**-**-*-*-*-*--*----*----**-*-*-**-*****************************/
double angle(double one_distance, double two_distance, double three_distance)
{
  double three_angle;		//Declaration of the 3rd angle.
  three_angle = acos ((pow (one_distance, 2.0) + pow (two_distance, 2.0) - pow (three_distance, 2.0)) / (2 * one_distance * two_distance)); //Angle 3 calculations.
  three_angle *= 180.0 / M_PI;  //Converts angle three into degrees from radians.

  return three_angle;
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
 *  1. double one_distance - distance between point 1 and point 2
 *  2. double two_distance - distance between point 2 and point 2
 *  3. double three_distance - distance between point 1 and point 3
 *  4. double one_angle - angle 1
 *  5. double two_angle - angle 2
 *  6. double three_angle - angle 3
 *
 *  Function Description: Displays the final result of the line distances and
 *  the interior angles.
 *
 ******+-*--***-***---***--*--**-***--*-*-*-**-*****************************/
void displayResults (double one_distance, double two_distance, double three_distance, double one_angle, double two_angle, double three_angle)
{
  printf ("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf ("\nLine #1 Distance: %5.1f Angle: %5.1f", one_distance, three_angle);
  printf ("\nLine #2 Distance: %5.1f Angle: %5.1f", two_distance, one_angle);
  printf ("\nLine #3 Distance: %5.1f Angle: %5.1f\n", three_distance, two_angle);
  printf ("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}