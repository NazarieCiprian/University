#pragma once
#include "Controller.h"
using namespace std;
class Ui
{
private:
	Controller ctrl;
public:
	Ui(const Controller& c):ctrl(c){}

	void run();
private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

	void showAllCoats();
	void addCoatMenu();
	void removeCoatMenu();
	void updateCoatMenu();
	void goThrough();
	void showLess();
};