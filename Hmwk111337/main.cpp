#include <iostream>
#include <iomanip>
#include "Circle.h"
#include "Rectangle.h"
#include "BasicShape.h"

using namespace std;

/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 4/29/2023
This is a program that calculates the area of shapes rectangle and circle using inheritance,
pure virtual member functions, abstract base classes and exceptions.

 The constructors in the derived classes must throw the NegativeValue exception class when a value entered is negative.
The exceptions must be caught in the main. If an exception is caught, the program should print
 “Negative input value” and prompt the user to reenter the values.
*/

/*
 * Prompt the user to enter the x coordinate, y coordinate and radius of a circle
Attempt to statically create a Circle with the x, y coordinates and radius entered – Ask user to reenter as long as any of the values is  <  0
If creation is successful, print the Circle’s area
Prompt the user to enter the length and width of a rectangle
Attempt to statically create a Rectangle with the length and width entered - Ask user to reenter as long as any of the values is < 0
If creation is successful, print the Rectangle’s area
 */
int main()
{
   double xCord, yCord, radiusCirc;//coordinates for x, y and radius of circle
   cout << "================= Circle =================" << endl;


   while (true) // loop until valid input is entered
   {
      cout << "Please enter the x coordinate of the circle's center: ";
      cin >> xCord;

      cout << "Please enter the y coordinate of the circle's center: ";
      cin >> yCord;

      cout << "Please enter the radius of the circle: ";
      cin >> radiusCirc;

      try
      {
         Circle circle(xCord, yCord, radiusCirc);
         cout << "***** The area of the circle is " << circle.getArea() << ".";
         break; // exit loop if input is valid
      }//closes try block for circle
      catch (const BasicShape::NegativeValue &)
      {
         cout << "***** Negative input value\n" << endl;
      }//closes catch block for circle
   }//closes while loop for circle


   double len, wid;//length and width of recatngle to calculate area
   cout << "================= Rectangle =================" << endl;


   while (true) // loop until valid input is entered
   {
      cout << "Please enter the length of the rectangle: ";
      cin >> len;

      cout << "Please enter the width of the rectangle: ";
      cin >> wid;
      try
      {
         Rectangle rect(len, wid);
         cout << "***** The area of the rectangle is " << rect.calcArea() << ".";
         break; // exit loop if input is valid
      }//closes try block for rectangle
      catch (const BasicShape::NegativeValue &)
      {
         cout << "***** Negative input value\n" << endl;
      }//closes catch block for rectangle
   }//closes while loop for rectangle

   return 0;
}//closes main
