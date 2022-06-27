/*****+**--*--*--***---****-**--*----***-*-**-******************************
*
*  Homework #: 2
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes the input of two points on a first road and
*   a third point on a second road that is perpendicular to the first. Using this information, 
*   the programs determines the distance from the points on the first road to that on the second
*   and the coordinates at which the two lines intersect.
*
******+**--*--*--***---****-**--*----***-*-**-*****************************/
#include<stdio.h>
#include<math.h>

int main()
{
    double xc_first;   //Declaration for the input of the first x coordinate.
    double yc_first;   //Declaration for the input of the first y coordinate.

    double xc_second;  //Declaration for the input of the second x coordinate.
    double yc_second;  //Declaration for the input of the second y coordinate.

    double xc_perp;    //Declaration for the input of the perpendicular x coordinate.
    double yc_perp;    //Declaration for the input of the perpendicular y coordinate.
    
    double d_oneperp;     //Declaration for the distance computation from the first point to the second point. 
    double d_twoperp;     //Declaration for the distance computation from the second point to the first point.
    
    double xc_intersection;     //Declaration for the x-coordinate of intersection.
    double yc_intersection;     //Declaration for the y-coordinate of intersection.

    //The following declarations are variables that will be used and explained later in the code.
    double slope_road;
    double perpendicular_slope;
    double b_road;
    double b_perpendicular;
    double temp_slope_road;

    printf("Enter coordinates for first point of road -> ");  //Asking for user input.
    scanf("%lf %lf", &xc_first, &yc_first);     

    printf("Enter coordinates for second point of road -> ");  //Asking for user input. 
    scanf("%lf %lf", &xc_second, &yc_second); 

    printf("Enter coordinates for point on perpendicular road -> ");  //Asking for user input.
    scanf("%lf %lf", &xc_perp, &yc_perp);

    //The following equations calculate the distance from first and second points the user inputs to the poin of the perpendicular road. 
    d_oneperp = sqrt(((xc_first - xc_perp) * (xc_first - xc_perp)) + ((yc_first - yc_perp) * (yc_first - yc_perp)));    
    d_twoperp = sqrt(((xc_second - xc_perp) * (xc_second - xc_perp)) + ((yc_second - yc_perp) * (yc_second - yc_perp)));
    
    //Finding the points of intersection using "y = mx + b" and applying it to the road and finding the slope of the perpendicular road and solving for the points on that road.
    slope_road = (yc_first - yc_second) / (xc_first - xc_second);   //Finding the slope of the road using the inputted coordinates.
    perpendicular_slope = (-1.0 / slope_road);                    //Finding the slope of the perpendicular road using the inputted coordinates.
    
    //Solving for the x-intercept.
	b_road = yc_first - (slope_road * xc_first) ;                         
    b_perpendicular = yc_perp - (perpendicular_slope * xc_perp);                        

    //Creating and solving a systems of equations.
    b_perpendicular = b_perpendicular - b_road;                 //Calculating the x-intercepts value using the x-intercepts of the previous functions. 
    temp_slope_road = slope_road;                               //Creating a temp. value that will be used in a calculation w/out overwriting the original value. 
    temp_slope_road = slope_road - perpendicular_slope;         //Calculating the new slope.
    xc_intersection = b_perpendicular / temp_slope_road ;       //Finding the x-intercept. 
    yc_intersection = (slope_road * xc_intersection) + b_road;  //Calculating the y-intercept using the x-intercept. 

    //Displaying the final answers.
    printf("Distance from (%0.1lf, %1.1lf) to (%0.1lf, %1.1lf): %2.1lf", xc_first, yc_first, xc_perp, yc_perp, d_oneperp);
    printf("\nDistance from (%0.1lf, %1.1lf) to (%0.1lf, %1.1lf): %2.1lf", xc_second, yc_second, xc_perp, yc_perp, d_twoperp);
    printf("\nCoordinate of intersection: %2.1lf, %2.1lf", xc_intersection, yc_intersection);

    return 0;
}