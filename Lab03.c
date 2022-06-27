/*****+----*-******-**-**----**--**-**-*-*-**-******************************
 *
 *  Lab #: 03
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: Given either the inradius or circumradius of the
 *  pentagon, this program calculates the following values: apothem, base, and
 *  area of the pentagon, area of the large, hexagon, and small circle.
 *
 ******+----*-******-**-**----**--**-**-*-*-**-*****************************/

#include<stdio.h>
#include<math.h>
#define PENT_CONST 1.72047740

int main (void)
{
  //Local Declarations
  char select; //char input
  double length; //length input

  double Apothem; //apothem of pentagon
  double pBase; //base of pentagon
  double pArea; //area of pentagon
  double aLargeCircle; //area of large circle
  double hArea; //area of hexagon
  double aSmallCircle; //area of small circle

  //User input
  printf("\nSelect the (I)ncircle or (C)ircumcircle radius -> ");
  scanf("%c", &select);

  printf("Enter the length -> ");
  scanf("%lf", &length);

  //Calculations
  Apothem = ((select / 73) * length) + (1 - (select / 73)) * length * cos(M_PI / 5);
  pBase = 2 * Apothem * tan(M_PI / 5);
  pArea =  pBase * pBase * PENT_CONST;
  aLargeCircle = M_PI * Apothem * Apothem;
  hArea = ((3 * sqrt(3)) / 2.0) * Apothem * Apothem;
  aSmallCircle = (M_PI * (Apothem * sin(M_PI / 3)) * (Apothem * sin(M_PI / 3)));

  //Print Statements
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nApothem of pentagon: %12.2lf", Apothem);
  printf("\nBase of pentagon: %15.2lf", pBase);
  printf("\nArea of pentagon: %15.2lf", pArea);
  printf("\nArea of large circle: %11.2lf", aLargeCircle);
  printf("\nArea of hexagon: %16.2lf", hArea);
  printf("\nArea of small circle: %11.2lf", aSmallCircle);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

  return 0;
}