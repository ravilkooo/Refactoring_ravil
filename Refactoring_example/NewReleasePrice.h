#pragma once
#include "Price.h"
class NewReleasePrice :
    public Price {
    // Inherited via Price
    virtual int getPriceCode() override;

    // Inherited via Price
    virtual double getCharge(int daysRented) override;
    
    virtual int getBonus(int daysRented) {
        // ���������� �������� �����
        int bonusPoints = Price::getBonus(daysRented);

        // ����� �� ����������� ������ �������
        if (daysRented > 1)
            bonusPoints++;
        return bonusPoints;
    }
};

