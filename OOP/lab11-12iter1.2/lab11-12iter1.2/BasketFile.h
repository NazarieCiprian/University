#pragma once
#include "Basket.h"
#include "Repository.h"
#include <fstream>
class BasketFile : public Basket
{
protected:
	string filename;

public:
	BasketFile();
	virtual~BasketFile() {};

	void setFilename(const string& filename);
	virtual void writeToFile() = 0;
	virtual void displayBasket() = 0;
};
