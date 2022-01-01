#pragma once
#include "Price.h"
class NewReleasePrice :
    public Price {
    // Inherited via Price
    virtual int getPriceCode() override;

    // Inherited via Price
    virtual double getCharge(int daysRented) override;
    
    virtual int getBonus(int daysRented) {
        // Начисление бонусных очков
        int bonusPoints = Price::getBonus(daysRented);

        // Бонус за двухдневный прокат новинки
        if (daysRented > 1)
            bonusPoints++;
        return bonusPoints;
    }
};

