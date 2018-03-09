#pragma once
#include "Engine.h"
#include "ElectricEngine.h"
#include "TurboEngine.h"

class Car
{
private:
	string body;
	Engine* e;
public:
	Car(const string& b,Engine* eng);
	~Car();
	string getBody() { return this->body; }
	double computePrice();
	string toString();

	Car* clone();

};