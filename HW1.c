/*****+**-***---**-*---*-**-**--*-*--***-*-**-******************************
*
*  Homework #:01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified;  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: 
*
******+**-***---**-*---*-**-**--*-*--***-*-**-*****************************/
#include <stdio.h>
#define MC 2.20462262       //Defines the value of the conversion factor used for converting from lbs to kg.
#define VC 3.2808399    //Defines the value of the conversion factor used from converting from ft/s to m/s.

int main()
{
  float mass;         //declaration of the mass
  float velocity;     //declaration of the velocity
  float massConverted;    //declaration of the converted mass
  float velocityConverted;    //declaration of the converted velocity
  float kEnergy;      //declaration of the kinetic energy

  printf("Enter the object mass in pounds -> ");  //user inputs the object's mass in pounds.
  scanf("%f", &mass);         //Stores the user value into the "mass" variable.

  printf("Enter the object velocity ft/s -> ");   //user inputs the object's velocity in ft/s.
  scanf("%f", &velocity);     //Stores the user value into the "velocity" variable.

  massConverted = mass / MC;  //Calculations for converting the mass from pounds to kg.
  printf("\nThe mass of the object: %2.2f", massConverted);         //displays the object's mass in kilograms.
  printf(" (kg)");    //adds units to the previous line.

  velocityConverted = velocity / VC;  //Calculations for converting the velocity from ft/s to m/s.
  printf("\nThe velocity of the object: %2.2f", velocityConverted);     //displays the object's velocity in m/s.
  printf(" (m/s)");   //adds units to the previous line.

  kEnergy = (1 / 2.0) * massConverted * velocityConverted * velocityConverted;  //Calculations for determining the kinetic energy.

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nThe kinetic energy of the object: %2.2f", kEnergy);      //displays the object's kinetic energy, in Joules, using the converted mass and velocity.  
  printf(" (J)\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}