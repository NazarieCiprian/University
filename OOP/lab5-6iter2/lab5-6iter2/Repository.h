#pragma once
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<TrenchCoat> coats;
public:
	//default constructor
	Repository(){}
	int findPos(double size, const std::string colour);
	/*
	Adds a new trenchcoat to the repository
	Input:c- the new coat that we want to add
	Returns 1 if we added a new coat and 0 if we increased the quantity of an existing coat
	*/
	int addCoat(const TrenchCoat& c);

	int removeCoat(double size, const std::string& colour);

	int updateCoat(const TrenchCoat& c);

	DynamicVector<TrenchCoat> getCoats() const{ return coats; }
	void reduceQuantity(int pos);
};