#pragma once
#include <iostream>


class TrenchCoat
{
private:
	double size;
	std::string colour;
	double price;
	int quantity;
	std::string photo;
	double length;
public:
	//Default constructor 
	TrenchCoat();
	//Constructor defined by user
	TrenchCoat(double size, const std::string& colour, double price, int quantity, const std::string& photo,double length);
	//getters for the attributes of the class
	double getSize() const{ return this->size; }
	std::string getColour()const { return this->colour; }
	double getPrice()const { return this->price; }
	int getQuantity() const{ return this->quantity; }
	std::string getPhoto() const{ return this->photo; }
	double getLength()const { return this->length; }
	//setters for the attributes
	void setPrice(double p) { price = p; }
	void setQuantity(int q) { quantity = q; }
	void setPhoto(const std::string& ph) { photo = ph; }
	void setLength(double len) { length = len; }
	bool operator==(const TrenchCoat& a);
	bool operator<(int length);

	void showPhoto();
};