#include "Customer.h"

string Customer::statement() {
	string result = "Прокат " + getName() + "\n";

	for (auto& each : _rentals) {
		// Вывод результатов для каждого проката
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
	}

	// Добавление колонтитула
	result += "Сумма задолженности: " +
		to_string(getTotalCharge()) + "\n";
	result += "Вы заработали " + to_string(getBonusPoints()) +
		" бонусных очков";
	return result;
}

string Customer::statement_short() {
	string result = "Прокат " + getName() + "\n";

	// Добавление колонтитула
	result += "Сумма задолженности: " +
		to_string(getTotalCharge()) + "\n";
	result += "Вы заработали " + to_string(getBonusPoints()) +
		" бонусных очков";
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