#include "TrenchCoat.h"
//#include <shellapi.h>
//#include <Windows.h>
TrenchCoat::TrenchCoat() :size(0), colour(""), price(0), quantity(0), photo(""){}

TrenchCoat::TrenchCoat(double size, const std::string & colour, double price, int quantity, const std::string & photo,double length)
{
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
	this->length = length;

}

bool TrenchCoat::operator==(const TrenchCoat & a)
{
	if (this->size == a.getSize() && this->colour == a.getColour())
		return true;
	return false;
}

bool TrenchCoat::operator<(int length)
{
	if (this->length < length)
		return true;
	return false;
}

void TrenchCoat::showPhoto()
{
	//ShellExecuteA(NULL, NULL, "launcher.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}
