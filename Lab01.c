/*****+-*-**-***-*---*-*-----**-***--***-*-**-******************************
*
*  Lab #: 01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Given the entered value of the height of the cone and 
*  the radius of the hemisphere, this program calculates the total volume of 
*  the given object. First, it calculates the volume of the hemisphere and 
*  the cone respectively. Next, the program adds the results to obtain the 
*  total volume of the given object in metrics and converts the total volume 
*  from cubic meters to cubic feet.
*
******+-*-**-***-*---*-*-----**-***--***-*-**-*****************************/

#include<stdio.h>
#define PI 3.1416 //Defines the value of PI.
#define CONV 35.315 //Defines the conversion factor from cubic meters to cubic feet.

int main (void)
{
  //Local Declarations
  float height;         //height of the cone.
  float radius;         //radius of the hemisphere.
  float vCone;          //volume of the cone.
  float vHemisphere;    //volume of the hemisphere.
  float vTotal;         //total volume in cubic meters.
  float vConverted;     //total volume in cubic feet.

  //Statements
  printf("\nEnter the height of the cone in meters -> ");  //Input the height of the cone.
  scanf("%f", &height);     //Stores the value into the "height" variable.

  printf("Enter the radius of the hemisphere in meters -> "); //Input the user to input the radius of the hemisphere.
  scanf("%f",&radius);  //Stores the value into the "radius" variable.

  vHemisphere = (2 / 3.0) * PI * radius * radius * radius;
  vCone = (1 / 3.0) * PI * radius * radius * height;

  printf("\nThe volume of the hemisphere: %2.2f cubic meters", vHemisphere);  //Prints out the volume of the hemisphere.
  printf("\nThe volume of the cone: %2.2f cubic meters", vCone);              //Prints out the volume of the cone.

  vTotal = vCone + vHemisphere;     //Volume calculations for the object. Uses the volume values of both the hemisphere and cone. 
  printf("\nThe total volume of the shape: %2.2f cubic meters", vTotal); //Displays the total volume of the shape in cubic meters

  vConverted = vTotal * CONV;     //Calculations for the volume converted from cubic meters to cubic feet. 
  printf("\nThe total volume of the shape: %2.2f cubic feet", vConverted); //Displays the total volume of the shape in cubic feet.

  return (0);
}