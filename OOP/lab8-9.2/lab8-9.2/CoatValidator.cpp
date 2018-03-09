#include "CoatValidator.h"

CoatException::CoatException(vector<string> err):message(err){}

vector<string> CoatException::getErrors() const
{
	return this->message;
}

void CoatValidator::validate(const TrenchCoat & t)
{
	vector<string>errors;
	if (t.getSize() <= 0 || t.getSize() >200)
		errors.push_back("Invalid size!");
	if (t.getQuantity() <= 0)
		errors.push_back("Invalid quantity");
	if (t.getPrice() <= 0)
		errors.push_back("Invalid price");
	int poswww = t.getPhoto().find("www");
	int poshttp = t.getPhoto().find("http");
	if (poswww != 0 && poshttp != 0)
		errors.push_back("Invalid link!");
	if (errors.size() > 0)
		throw CoatException(errors);
}
