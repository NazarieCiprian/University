#include "Controller.h"

int Controller::addCoatCont(double size, const std::string & colour, double price, int quantity, const std::string & photo, double length)
{
	TrenchCoat c{ size, colour, price, quantity,photo, length };
	int res = this->repo.addCoat(c);
	return res;
}

int Controller::removeCoatCont(double size, std::string & colour)
{
	int res = this->repo.removeCoat(size, colour);
	return res;
}

int Controller::updateCoatCont(double size, const std::string & colour, double price, int quantity, const std::string & photo,double length)
{
	TrenchCoat c{ size,colour,price,quantity,photo,length };
	int res = this->repo.updateCoat(c);
	return res;
}

void Controller::addBag(const TrenchCoat & tc)
{
	this->bag.addToBasket(tc);
}

void Controller::printBag()
{
	this->bag.printBag();
}

void Controller::reduceQuantity(int pos)
{
	this->repo.reduceQuantity(pos);
}


