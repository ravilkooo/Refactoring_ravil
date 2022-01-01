#include "Customer.h"

string Customer::statement() {
	string result = "������ " + getName() + "\n";

	for (auto& each : _rentals) {
		// ����� ����������� ��� ������� �������
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
	}

	// ���������� �����������
	result += "����� �������������: " +
		to_string(getTotalCharge()) + "\n";
	result += "�� ���������� " + to_string(getBonusPoints()) +
		" �������� �����";
	return result;
}

string Customer::statement_short() {
	string result = "������ " + getName() + "\n";

	// ���������� �����������
	result += "����� �������������: " +
		to_string(getTotalCharge()) + "\n";
	result += "�� ���������� " + to_string(getBonusPoints()) +
		" �������� �����";
	return result;
}

double Customer::getTotalCharge() {
	double totalAmount = 0;
	for (auto& each : _rentals) {
		totalAmount += each.getCharge();
	}
	return totalAmount;
}

int Customer::getBonusPoints() {
	int bonusPoints = 0;
	for (auto& each : _rentals) {
		bonusPoints += each.getBonus();
	}
	return bonusPoints;
}