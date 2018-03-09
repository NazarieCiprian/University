#pragma once
#include "BasketFile.h"
#include <fstream>
#include <Windows.h>
class CSVBasket : public BasketFile
{
public:
	void writeToFile()override;

	void displayBasket()override;
};