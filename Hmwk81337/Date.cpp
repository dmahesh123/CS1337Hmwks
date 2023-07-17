#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/*Implement a Date class that has the following private member variables:
• month of type int
• day of type int
• year of type int
• hour of type int // hour is in military time, e.g. 23 for 11 PM
In what follows, a date will be represented as mm/dd/yyyy/hh*/

// Mutator that sets the variables month, day, year, and hour to the parameter values
void Date::set(int month_, int day_, int year_, int hour_)
{
   month = month_;
   day = day_;
   year = year_;
   hour = hour_;
}//closes set mutator

// Overloaded == relational operator
//is true if and only if the month, day, year and hour are equal
bool Date::operator==(const Date &rhs)
{
   return (month == rhs.month && day == rhs.day && year == rhs.year && hour == rhs.hour);
}//closes  Overloaded == relational operator

// Overloaded < relational operator
//is true if and only if date d2 comes after date d1 chronologically.
// For example, (03/08/2200/23) < (03/09/2200/00)
bool Date::operator<(const Date &rhs)
{
   if (year < rhs.year)
      return true;
   else if (year == rhs.year)
   {
      if (month < rhs.month)
         return true;
      else if (month == rhs.month)
      {
         if (day < rhs.day)
            return true;
         else if (day == rhs.day)
         {
            if (hour < rhs.hour)
               return true;
         }//closes if check for hour
      }//closes if check for month
   }//closes if check for year
   return false;
}//closes Overloaded < relational operator

// Overloaded <= relational operator
// is true if and only if (d1 == d2) is true, or (d1 < d2) is true
bool Date::operator<=(const Date &rhs)
{
   return (*this == rhs) || (*this < rhs);
}//closes Overloaded <= relational operator

// Overloaded - operator
/*A year is a leap year if it meets either condition 1 or 2:

The year is divisible by 4 and not divisible by 100
The year is divisible by 400
For the extra credit, your overloaded – should account for the leap years*/

// returns the number of hours elapsed from d1 to d2. For example, if d1 is 02/13/2100/00 and d2 is 02/14/2100/10,
// (d2 – d1) is equal to 34 hours. If d2 == d1, (d2 – d1) should be zero. If d2 < d1, (d2 – d1) should return –(d1 – d2) and therefore be negative
//The suggestion is to implement the function f() as an array, where the month would be used as the index into the array.
int Date::operator-(const Date &rhs)
{
   int numOfHours = 0;
   if (*this < rhs)
   {
      int dayMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      int dayYear = 0;
      for (int i = month + 1; i <= 12; i++)
      {
         dayYear += dayMonth[i];
      }//closes for month
      dayYear += dayMonth[month] - day;
      for (int i = year + 1; i < rhs.year; i++)
      {
         dayYear += (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) ? 366 : 365;
      }//closes for year
      for (int i = 1; i < rhs.month; i++)
      {
         dayYear += dayMonth[i];
      }//closes for month
      dayYear += rhs.day;

      // Calculate the elapsed hours
      numOfHours = -1 * ((dayYear * 24) + (rhs.hour - hour));
   }//closes if hours are negative
   else if (*this == rhs)
   {
      cout << "";
   }//closes if hour is 0
   else
   {
      // If rhs is greater than or equal to *this, consider positive hours
      int numDaysMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      int numDaysYear = 0;
      for (int i = rhs.month + 1; i <= 12; i++)
      {
         numDaysYear += numDaysMonth[i];
      }//closes for month
      numDaysYear += numDaysMonth[rhs.month] - rhs.day;
      for (int i = rhs.year + 1; i < year; i++)
      {
         numDaysYear += (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) ? 366 : 365;
      }//closes for year
      for (int i = 1; i < month; i++)
      {
         numDaysYear += numDaysMonth[i];
      }//closes for month
      numDaysYear += day;

      // Calculate the elapsed hours
      numOfHours = (numDaysYear * 24) + (hour - rhs.hour);
   }//closes if hours are positive
   return numOfHours;
}//closes operator - overloading


// Prints the date in the format ”Month dd, yyyy, hh:00”. For example, “March 12, 2103, 23:00”.
//Do not write a constructor.
void Date::print()
{
   string monthNames1[13];
   string monthNames[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September",
                          "October", "November", "December"};
   for (int i = 1; i <= 12; i++)
   {
      if (month == i)
      {
         cout << monthNames[i] << " " << day << ", " << year << ", " << hour << ":00";
         break;
      }//closes printing by day year and hour
   }//closes for loop to print
}//closes Print function