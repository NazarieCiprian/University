
#pragma once
#include "BasketFile.h"

class HtmlBasket : public BasketFile
{
	void writeToFile() override;

	void displayBasket() override;
};
