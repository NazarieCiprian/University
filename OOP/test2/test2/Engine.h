#pragma once
#include <string>
using namespace std;

class Engine
{
protected:
	string fuel;
	double bprice;

public:
	Engine(const string& f, const double pr);
	virtual ~Engine();

	virtual double getPrice();
	virtual string toString() = 0;

	virtual Engine* clone() = 0;

};