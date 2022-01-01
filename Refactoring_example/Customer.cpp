#include "Customer.h"

string Customer::statement() {
	double totalAmount = 0;
	int bonusPoints = 0;
	string result = "������ " + getName() + "\n";

	for (auto& each : _rentals) {
		bonusPoints += bonusFor(each);

		// ����� ����������� ��� ������� �������
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
		totalAmount += each.getCharge();
	}

	// ���������� �����������
	result += "����� �������������: " +
		to_string(totalAmount) + "\n";
	result += "�� ���������� " + to_string(bonusPoints) +
		" �������� �����";
	return result;
}

int Customer::bonusFor(Rental& each)
{
	// ���������� �������� �����
	int bonusPoints = 1;

	// ����� �� ����������� ������ �������
	if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
		each.getDaysRented() > 1)
		bonusPoints++;
	return bonusPoints;
}
