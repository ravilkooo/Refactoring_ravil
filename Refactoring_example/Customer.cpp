#include "Customer.h"

string Customer::statement() {
	double totalAmount = 0;
	int bonusPoints = 0;
	string result = "������ " + getName() + "\n";

	for (auto& each : _rentals) {
		double thisAmount = amountFor(each);

		// ���������� �������� �����
		bonusPoints++;

		// ����� �� ����������� ������ �������
		if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
			each.getDaysRented() > 1)
			bonusPoints++;

		// ����� ����������� ��� ������� �������
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(thisAmount) + "\n";
		totalAmount += thisAmount;
	}

	// ���������� �����������
	result += "����� �������������: " +
		to_string(totalAmount) + "\n";
	result += "�� ���������� " + to_string(bonusPoints) +
		" �������� �����";
	return result;
}

double Customer::amountFor(Rental & aRental)
{
	double thisAmount = 0;
	switch (aRental.getMovie().getPriceCode()) {
	case Movie::REGULAR:
		thisAmount += 2;

		if (aRental.getDaysRented() > 2)
			thisAmount += (aRental.getDaysRented() - 2) * 1.5;
		break;

	case Movie::NEW_RELEASE:
		thisAmount += aRental.getDaysRented() * 3;
		break;

	case Movie::CHILDREN:
		thisAmount += 1.5;
		if (aRental.getDaysRented() > 3)
			thisAmount += (aRental.getDaysRented() - 3) * 1.5;
		break;
	}
	return thisAmount;
}
