//
// Created by 12102 on 4/29/2023.
//
#include <iostream>
#include <iomanip>
#include "Circle.h"
#include "Rectangle.h"
#include "BasicShape.h"


//Design a class named Circle derived from BasicShape that has the following private member variables:
//• double centerX;
//• double centerY;
//• double radius;


class NegativeValue // Exception class has no member
{
};//closes exception class
//• Constructor Circle(centerX_, centerY_, radius_) that takes the arguments and sets the member variables. The area should be set by calling calcArea then setArea. The constructor must throw the NegativeValue exception if any of the argument values is negative

Circle::Circle(double centerX_, double centerY_, double radius_)
{
   calcArea();
   if (centerX_ < 0|| centerY_<0||radius_<0)
   {
      throw NegativeValue();
   }//closes if value is invalid
   else
   centerX = centerX_;
   centerY = centerY_;
   radius=radius_;
   double area = calcArea();
   setArea(area);

}//closes valid value and Circle
//• Overridden calcArea(), which returns the area calculated as 3.14159* radius * radius

double Circle::calcArea() const
{
   return 3.14159 * radius * radius;
}//closes calc area
