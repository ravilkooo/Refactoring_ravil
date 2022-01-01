#include "Customer.h"

string Customer::statement() {
	double totalAmount = 0;
	int bonusPoints = 0;
	string result = "Прокат " + getName() + "\n";

	for (auto& each : _rentals) {
		// Начисление бонусных очков
		bonusPoints++;

		// Бонус за двухдневный прокат новинки
		if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
			each.getDaysRented() > 1)
			bonusPoints++;

		// Вывод результатов для каждого проката
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
		totalAmount += each.getCharge();
	}

	// Добавление колонтитула
	result += "Сумма задолженности: " +
		to_string(totalAmount) + "\n";
	result += "Вы заработали " + to_string(bonusPoints) +
		" бонусных очков";
	return result;
}