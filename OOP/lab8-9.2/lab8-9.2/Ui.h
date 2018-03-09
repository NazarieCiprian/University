#pragma once
#include "Controller.h"

class Ui
{
private:
	Controller ctrl;

public:
	Ui(const Controller& c) :ctrl(c) {};
	void run();

private:
	void printMenu();
	void printAdminMenu();
	void printUserMenu();
	void showBySize();
	void addToBasket();
	void nextMenu();
	void showCart();
	void saveCart();

	void showAll();
	void addCoatMenu();
	void updateCoatMenu();
	void removeCoatMenu();
};