#pragma once
#include "Engine.h"
#include <sstream>
class ElectricEngine: public Engine
{
private:
	int autonom;

public:
	ElectricEngine(const string& f, const double pr, int a);
	~ElectricEngine();

	double getPrice()override;
	string toString()override;
	
	Engine* clone()override;
};