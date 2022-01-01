#pragma once
#include "Price.h"
class ChildrenPrice :
    public Price {
    // Inherited via Price
    virtual int getPriceCode() override;

    // Inherited via Price
    virtual double getCharge(int daysRented) override;
};

