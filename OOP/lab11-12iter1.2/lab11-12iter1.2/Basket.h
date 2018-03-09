#pragma once
#include "TrenchCoat.h"
#include <vector>
#include <algorithm>
#include "ControllerException.h"
using namespace std;
class Basket
{
private:
	vector<TrenchCoat> cart;
	vector<TrenchCoat> filtered;
	int current;
	double bill;
public:
	Basket();

	vector<TrenchCoat> getCart()const { return this->cart; }
	vector<TrenchCoat> getFiltered()const { return this->filtered; }

	void setFiltered(const vector<TrenchCoat>& v);
	void addCoatCart(const TrenchCoat&  t);
	void reduceQuantity(const TrenchCoat& t);
	void setCurret();
	TrenchCoat next();
	TrenchCoat getCurrent();
	void emptyFiltered();
	void remove(const TrenchCoat& t);
	double getBill() { return this->bill; }
}; 
