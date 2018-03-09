#pragma once
#include "Engine.h"
#include <sstream>
class TurboEngine :public Engine
{
public:
	TurboEngine(const string& f, const double pr);
	~TurboEngine();

	double getPrice();

	string toString();

	Engine* clone()override;
};