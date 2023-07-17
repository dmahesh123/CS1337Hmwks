//
// Created by 12102 on 4/29/2023.
//

#ifndef HMWK111337_RECTANGLE_H
#define HMWK111337_RECTANGLE_H

#endif //HMWK111337_RECTANGLE_H
// Specification file for Rectangle derived class
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
    double width;
    double length;

public:
    Rectangle(double w, double l);
    double calcArea() const;
};

#endif
