#pragma once
#include "Controller.h"
#include <iostream>
using namespace std;

class Ui
{
private:
	Controller ctrl;
public:
	Ui(const Controller& c):ctrl(c){}

	void run();
private:
	void addCar();
	void showAll();
	void saveToFile();
};