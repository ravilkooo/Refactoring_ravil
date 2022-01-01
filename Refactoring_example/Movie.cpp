#include "Movie.h"

double Movie::getCharge(int daysRented) {
	double thisAmount = 0;
	switch (getPriceCode()) {
	case Movie::REGULAR:
		thisAmount += 2;

		if (daysRented > 2)
			thisAmount += (daysRented - 2) * 1.5;
		break;

	case Movie::NEW_RELEASE:
		thisAmount += daysRented * 3;
		break;

	case Movie::CHILDREN:
		thisAmount += 1.5;
		if (daysRented > 3)
			thisAmount += (daysRented - 3) * 1.5;
		break;
	}
	return thisAmount;
}

int Movie::getBonus(int daysRented)
{
	// Начисление бонусных очков
	int bonusPoints = 1;

	// Бонус за двухдневный прокат новинки
	if ((getPriceCode() == Movie::NEW_RELEASE) &&
		daysRented > 1)
		bonusPoints++;
	return bonusPoints;
}