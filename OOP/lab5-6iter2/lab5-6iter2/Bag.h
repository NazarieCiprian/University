#pragma once
#include "DynamicVector.h"
#include "TrenchCoat.h"
using namespace std;
class Bag
{
private:
	DynamicVector<TrenchCoat> coats;
	double bill;
public:
	Bag():bill(0){}

	void addToBasket(const TrenchCoat& c);

	void printBag();

	double getBill()const { return bill; }


};