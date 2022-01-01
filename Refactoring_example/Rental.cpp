#include "Rental.h"

double Rental::getCharge()
{
	double thisAmount = 0;
	switch (getMovie().getPriceCode()) {
		case Movie::REGULAR:
		thisAmount += 2;

		if (getDaysRented() > 2)
			thisAmount += (getDaysRented() - 2) * 1.5;
		break;

		case Movie::NEW_RELEASE:
		thisAmount += getDaysRented() * 3;
		break;

		case Movie::CHILDREN:
		thisAmount += 1.5;
		if (getDaysRented() > 3)
			thisAmount += (getDaysRented() - 3) * 1.5;
		break;
	}
	return thisAmount;
}

int Rental::getBonus()
{
	// Начисление бонусных очков
	int bonusPoints = 1;

	// Бонус за двухдневный прокат новинки
	if ((getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
		getDaysRented() > 1)
		bonusPoints++;
	return bonusPoints;
}