#include "TrenchCoat.h"

TrenchCoat::TrenchCoat():size(0),colour(""),quantity(0),price(0),photo(""){}

TrenchCoat::TrenchCoat(const double size, const std::string & colour, const int quantity, const double price, const std::string & photo)
{
	this->size = size;
	this->colour = colour;
	this->quantity = quantity;
	this->price = price;
	this->photo = photo;
}

std::istream & operator >> (std::istream & is, TrenchCoat & t)
{
	std::string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	t.size = stod(tokens[0]);
	t.colour = tokens[1];
	t.quantity = stoi(tokens[2]);
	t.price = stod(tokens[3]);
	t.photo = tokens[4];
	return is;
}

std::ostream & operator<<(std::ostream & os, TrenchCoat & t)
{
	os << t.size << "," << t.colour << "," << t.quantity << "," << t.price << "," << t.photo << "\n";
	return os;
}
