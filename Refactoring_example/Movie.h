#pragma once
#include <string>
#include "Price.h"
#include "RegularPrice.h"
#include "NewReleasePrice.h"
#include "ChildrenPrice.h"
using namespace std;


class Movie
{
public:
	static const int CHILDREN = 2;
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;
private:
	string _title;
	Price* _price;

public:
	Movie() {
		_title = "";
		setPriceCode(REGULAR);
	}

	Movie(string title, int priceCode){
		_title = title;
		setPriceCode(priceCode);
	}

	int getPriceCode() {
		return _price->getPriceCode();
	}

	void setPriceCode(int arg);

	string getTitle() {
		return _title;
	}
	double getCharge(int);
	int getBonus(int daysRented);
};

