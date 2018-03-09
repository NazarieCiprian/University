#include "Bag.h"
#include <string>
void Bag::addToBasket(const TrenchCoat & c)
{
	this->coats.add(c);
	this->bill += c.getPrice();
}

TrenchCoat Bag::getCurrentCoat()
{
	if (this->current == this->coats.getSize())
		this->current = 0;
	return this->coats[this->current];
}

void Bag::printBag()
{
	for (int i = 0; i < coats.getSize(); i++)
	{
		TrenchCoat c = this->coats.getAllElems()[i];
		cout <<"Size:"<<c.getSize() << " " <<"Colour:"<< c.getColour() << " " <<"Price:"<< c.getPrice()<<endl;

	}
}
