//
// Created by 12102 on 4/29/2023.
//
#include <iostream>
#include <iomanip>
#include "Circle.h"
#include "Rectangle.h"
#include "BasicShape.h"

//Design a class named Rectangle derived from BasicShape that has the following private member variables:
//• double width;
//• double length;

class NegativeValue // Exception class has no member
{
};//closes exception class
//• Constructor Rectangle(width_, length_) that takes the arguments and sets the member variables.
// The area should be set by calling calcArea then setArea. The constructor must throw the NegativeValue
// exception if any of the argument values is negative

Rectangle::Rectangle(double width_, double length_)
{
   calcArea();
   if (width_ < 0|| length_<0)
   {
      throw NegativeValue();
   }//closes catch
   else
      width = width_;
   length = length_;
   double area = calcArea();
   setArea(area);

}//closes Rectangle
//• Overridden calcArea(), which returns the area calculated as width * length

double Rectangle::calcArea() const
{
   return width * length;
}//closes calcArea
