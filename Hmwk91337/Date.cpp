//
// Created by 12102 on 4/23/2023.
//
#include<string>
#include "iostream"
using namespace std;
#include "Date.h"

string Date::monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void Date::set(int month_, int day_, int year_, int hour_) {
   month = month_;
   day = day_;
   year = year_;
   hour = hour_;

}

bool Date::operator<(const Date & rhs) {
   if (year < rhs.year) {
      return true;
   } else if (year > rhs.year) {
      return false;
   } else if (month < rhs.month) {
      return true;
   } else if (month > rhs.month) {
      return false;
   } else if (day < rhs.day) {
      return true;
   } else if (day > rhs.day) {
      return false;
   } else if (hour < rhs.hour) {
      return true;
   } else {
      return false;
   }
}

void Date::print() const {
   cout << monthName[month-1] << " " << day << ", " << year << ", " << hour << ":00";
}

int Date::getMonthFromDate() const {
   return month;
}

int Date::getDayFromDate() const {
   return day;
}

int Date::getYearFromDate() const {
   return year;
}

int Date::getHourFromDate() const {
   return hour;
}
/*
bool Date::operator>(const Date& rhs) {
   if (year > rhs.year) {
      return true;
   }
   else if (year == rhs.year && year > rhs.month) {
      return true;
   }
   else if (date1.year == rhs.year && date1.month == rhs.month && date1.day > rhs.day) {
      return true;
   }
   else if (date1.year == rhs.year && date1.month == rhs.month && date1.day == rhs.day && date1.hour > date2.hour) {
      return true;
   }
   else {
      return false;
   }
}
*/