/*****+**--**---**-**-**-*---*--*----***-*-**-******************************
*
*  Lab #: 02
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program, when given the side length of a hexagon, will 
*  calculate the area of the hexagon, the radius and area of the larger circle inscribed
*  in the large hexagon, the apothem, base, and area of a pentagon inscribed in the large
*  circle, and the area of the smaller circle inscribed in the pentagon.
*
******+**--**---**-**-**-*---*--*----***-*-**-*****************************/

#include<stdio.h>
#include<math.h>

int main (void)
{

  double hSideLength; //hexagon side length
  double hArea; //Area of the hexagon
  double aLargeCircle; //Radius of the large circle
  double rLargeCircle; //Area of the large circle
  double pApothem; //Apothem of the pentagon
  double pBase; //Base of pentagon
  double pArea; //Area of pentagon
  double aSmallCircle; //Area of the small circle.

  //User inputs the hexagon's side length.
  printf("\nEnter the hexagon side length -> ");
  scanf("%lf", &hSideLength);

  //Calculations 
  hArea = ((3 * sqrt(3)) / 2) * ((hSideLength) * (hSideLength)); //Calculations for the area of the hexagon.
  rLargeCircle = (sqrt(3) / 2) * hSideLength; //Calculations for the radius of the large circle.
  aLargeCircle = ((3 * M_PI) / 4) * ((hSideLength) * (hSideLength)); //Calculations for the area of the larger circle.
  pApothem = (((sqrt(3)) * cos(M_PI / 5)) / 2) * hSideLength; //Calculations for the apothem of the pentagon.
  pBase = (sqrt(3) * sin(M_PI / 5)) * hSideLength; //Calculations for the base of the pentagon.
  pArea = ((15 * sin((2 * M_PI) / 5)) / 8) * ((hSideLength) * (hSideLength)); //Calculations for the area of the pentagon.
  aSmallCircle = ((3 * M_PI * (cos(M_PI / 5) * (cos(M_PI / 5)))) / 4) * ((hSideLength) * (hSideLength)); //Calculations for the area of the small circle.

  //Print Statements  
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nArea of hexagon: %16.2lf", hArea);
  printf("\nRadius of large circle: %9.2lf", rLargeCircle);
  printf("\nArea of large circle: %11.2lf", aLargeCircle);
  printf("\nApothem of pentagon: %12.2lf", pApothem);
  printf("\nBase of pentagon: %15.2lf", pBase);
  printf("\nArea of pentagon: %15.2lf", pArea);
  printf("\nArea of small circle: %11.2lf", aSmallCircle);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

  return 0;
}