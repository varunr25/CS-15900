/*****+----**-**-*-*-*-*--*----*----**-*-*-**-******************************
 *
 *  Lab #: 04
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: This program asks the user to input 3 points of a triangle
 *  to calculate the length of each side and interior angles. The program achieves 
 *  this by calculating each in a separate funct
 * ion and calling that function in 
 *  the main function.    
 *
 ******+----**-**-*-*-*-*--*----*----**-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>

//Function Declarations
void getInput(double* , double* , int );
double distance (double , double , double , double );
double angle(double , double , double );
void displayResults(double , double , double , double , double , double );

int main()
{
  double one_xc;  //Declaration of the first X-coordinate.
  double one_yc;  //Declaration of the first Y-coordinate.

  double two_xc;  //Declaration of the second X-coordinate.
  double two_yc;  //Declaration of the second Y-coordinate.

  double three_xc;    //Declaration of the third X-coordinate.
  double three_yc;    //Declaration of the third Y-coordinate.

  double one_two_distance;    //Declaration of the variable use to store Line 1
  double one_three_distance;  //Declaration of the variable use to store Line 2
  double two_three_distance;  //Declaration of the variable use to store Line 3

  double line_one_angle;  //Declaration of the variable use to store Angle 1.
  double line_two_angle;  //Declaration of the variable use to store Angle 2.
  double line_three_angle;    //Declaration of the variable use to store Angle 3.

  getInput(&one_xc, &one_yc, 1);
  getInput(&two_xc, &two_yc, 2);
  getInput(&three_xc, &three_yc, 3);

  one_two_distance = distance(one_xc, one_yc, two_xc, two_yc);    //Calls the distance function to determine the length of line 1.
  one_three_distance = distance(one_xc, one_yc, three_xc, three_yc);  //Calls the distance function to determine the length of line 2.
  two_three_distance = distance(two_xc, two_yc, three_xc, three_yc);  //Calls the distance function to determine the length of line 3.

  line_one_angle = angle(one_three_distance, two_three_distance, one_two_distance);   //Calls the angle function to determine the length of angle 1.
  line_two_angle = angle(one_two_distance, one_three_distance, two_three_distance);   //Calls the angle function to determine the length of angle 2.
  line_three_angle = angle(one_two_distance, two_three_distance, one_three_distance); //Calls the angle function to determine the length of angle 3.

  displayResults(one_two_distance, line_one_angle, two_three_distance, line_two_angle, one_three_distance, line_three_angle);

  return 0;
}

/*****+-*-****-***--**-**-*-***-**---*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getInputs
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double one_xc, X-coordinate #1
*    2. double one_yc, Y-coordinate #1
*    3. double two_xc, X-coordinate #2
*    4. double two_yc, Y-coordinate #2
*    5. double three_xc, X-coordinate #3
*    6. double three_yc, Y-coordinate #3
*
*  Function Description: This function asks the user to input values for the 
*  x and y coordinates of three different points. 
*
******+-*-****-***--**-**-*-***-**---*-*-*-**-*****************************/

void getInput(double* xc, double* yc, int num)
{
  printf("Enter coordinates for point #%d -> ", num);
  scanf("%lf %lf", xc, yc); 
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
 *    1. double x1, X-coordinate #1
 *    2. double y1, Y-coordinate #1
 *    3. double x2, X-coordinate #2
 *    4. double y2, Y-coordinate #2
 *
 *  Function Description: This function finds the distance between two points when given
 *  the x and y coordinates of the two points.
 *
 ******+----**-**-*-*-*-*--*----*----**-*-*-**-*****************************/
double distance (double x1, double y1, double x2, double y2)
{
  double dis; //temporary storage of distance

  dis = (sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)));

  return(dis);
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
 *    1. double d1, distance #1
 *    2. double d2, distance #2
 *    3. double d3, distance #3
 *
 *  Function Description: This function finds the interior angle of the line using 
 *  the previously found lines and the Law of Cosine.
 *
 ******+----**-**-*-*-*-*--*----*----**-*-*-**-*****************************/

double angle(double d1, double d2, double d3)
{
  double ang; //temporary storage of angle

  ang = ((acos(((pow(d1, 2) + pow(d2, 2) - pow(d3, 2)) / (2 * d1 * d2)))) * (180 / M_PI));

  return(ang);
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
 *  1. double dis_12 - distance between point 1 and point 2
 *  2. double dis_23 - distance between point 2 and point 2
 *  3. double dis_13 - distance between point 1 and point 3
 *  4. double ang_1 - angle 1
 *  5. double ang_2 - angle 2
 *  6. double ang_3 - angle 3
 *
 *  Function Description: Displays the final result of the line distances and
 *  the interior angles.
 *
 ******+-*--***-***---***--*--**-***--*-*-*-**-*****************************/
void displayResults(double dis_12, double ang_1, double dis_23, double ang_2, double dis_13, double ang_3)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nLine #1 Distance:%6.1lf Angle:%6.1f", dis_12, ang_1);  //Display length of line 1 and angle 1.
  printf("\nLine #2 Distance:%6.1lf Angle:%6.1f", dis_23, ang_2);  //Display length of line 2 and angle 2.
  printf("\nLine #3 Distance:%6.1lf Angle:%6.1f", dis_13, ang_3);  //Display length of line 3 and angle 3.
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
}