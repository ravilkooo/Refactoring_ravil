#include "RegularPrice.h"
#include "Movie.h"

int RegularPrice::getPriceCode()
{
    return Movie::REGULAR;
}

double RegularPrice::getCharge(int daysRented)
{
	double thisAmount = 2;
	if (daysRented > 2)
		thisAmount += (daysRented - 2) * 1.5;
	return thisAmount;
}
