//
// Created by 12102 on 4/29/2023.
//

#ifndef HMWK111337_BASICSHAPE_H
#define HMWK111337_BASICSHAPE_H

#endif //HMWK111337_BASICSHAPE_H
// Specification file for BasicShape base class
#ifndef BASICSHAPE_H
#define BASICSHAPE_H
#include <string>
using namespace std;

class BasicShape
{
private:
    double area;

public:
    class NegativeValue // Exception class
    {};

    double getArea() const
    {
       return area;
    }

    virtual double calcArea() const = 0;

    void setArea(double area_)
    {
       area = area_;
    }
};

#endif
