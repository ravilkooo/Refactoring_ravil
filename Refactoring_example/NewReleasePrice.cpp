#include "NewReleasePrice.h"
#include "Movie.h"

int NewReleasePrice::getPriceCode()
{
    return Movie::NEW_RELEASE;
}

double NewReleasePrice::getCharge(int daysRented)
{
    return daysRented*3;
}