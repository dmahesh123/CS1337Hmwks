//
// Created by 12102 on 4/29/2023.
//

#ifndef HMWK111337_CIRCLE_H
#define HMWK111337_CIRCLE_H

#endif //HMWK111337_CIRCLE_H
// Specification file for Circle derived class
#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"

class Circle : public BasicShape
{
private:
    double centerX;
    double centerY;
    double radius;
public:
    Circle(double x, double y, double rad);
    double calcArea() const;
};

#endif
