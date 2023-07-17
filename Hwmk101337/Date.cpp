//
// Created by 12102 on 4/28/2023.
//

#include "Date.h"
#include <iostream>

using namespace std;
//Implement a Date class that has the following private member variables:
//• month of type int
//• day of type int
//• year of type int
//• hour of type int // hour is in military time, e.g. 23 for 11 PM
//In what follows, a date will be represented as mm/dd/yyyy/hh
//and the following member functions:

//• set(month_, day_, year_, hour_) mutator that sets the variables month, day, year, and hour to the parameter values

void Date::set(int month_, int day_, int year_, int hour_)
{
   month = month_;
   day = day_;
   year = year_;
   hour = hour_;
}

//public:


//• print(): Prints the date in the format ”Month dd, yyyy, hh:00”. For example, “March 12, 2103, 23:00”.

void Date::print() const
{
   cout << month << ' ' << day << ", " << year << ", " << hour << ":00\n";
}//closes print
//• getMonth(): accessor that returns the month

int Date::getMonth() const
{
   return month;
}//closes getMonth
//• getDay(): accessor that returns the day

int Date::getDay() const
{
   return day;
}//closes getDay
//• getYear(): accessor that returns the year
//Do not write a constructor.
int Date::getYear() const
{
   return year;
}//closes getYear
//• getHour(): accessor that returns the hour

int Date::getHour() const
{
   return hour;
}//closes getHour
