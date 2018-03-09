#include "Engine.h"

Engine::Engine(const string & f, const double pr):fuel(f),bprice(pr)
{
}

Engine::~Engine()
{
}

double Engine::getPrice()
{
	return this->bprice;
}
