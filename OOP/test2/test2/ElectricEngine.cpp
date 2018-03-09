#include "ElectricEngine.h"

ElectricEngine::ElectricEngine(const string & f, const double pr, int a):Engine(f,pr),autonom(a)
{
}

ElectricEngine::~ElectricEngine()
{
}

double ElectricEngine::getPrice()
{
	double p;
	p = this->bprice + this->autonom*0.01;
	return p;
}

string ElectricEngine::toString()
{
	stringstream buffer;
	buffer << " Electric engine fuel:" << this->fuel << " autonomy:" << this->autonom<<" ";
	return buffer.str();
}

Engine * ElectricEngine::clone()
{
	return new ElectricEngine(*this);
}
