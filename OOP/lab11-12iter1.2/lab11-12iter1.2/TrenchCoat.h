#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "utils.h"
using namespace std;
class TrenchCoat
{
private:
	double size;
	std::string colour;
	int quantity;
	double price;
	std::string photo;
public:
	TrenchCoat();
	TrenchCoat(const double size, const std::string& colour, const int quantity, const double price, const std::string& photo);

	double getSize()const { return this->size; }
	std::string getColour()const { return this->colour; }
	int getQuantity()const { return this->quantity; }
	double getPrice()const { return this->price; }
	std::string getPhoto()const { return this->photo; }

	void setQuantity(int q) { this->quantity = q; }
	void setPrice(double price) { this->price = price; }

private:

	friend std::istream& operator >> (std::istream& is, TrenchCoat& t);
	friend std::ostream& operator<<(std::ostream&os, TrenchCoat& t);
};