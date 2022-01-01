#include "Rental.h"

double Rental::getCharge()
{
	return getMovie().getCharge(getDaysRented());
}

int Rental::getBonus()
{
	return getMovie().getBonus(getDaysRented());
}