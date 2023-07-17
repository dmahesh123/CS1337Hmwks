//
// Created by 12102 on 3/28/2023.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>

using namespace std;
#ifndef HMWK61337_PRODUCT_H
#define HMWK61337_PRODUCT_H

#endif //HMWK61337_PRODUCT_H

class Product
{
private:
    string PLU;
    string name;
    int type;
    double price;
    int inventory;
public:
    void setProductAttributes(string, string, int, double, int);
    void setInventory(int);
    string getPLU() const;
    string getName() const;
    int getType() const;
    double getPrice() const;
    int getInventory() const;
};

