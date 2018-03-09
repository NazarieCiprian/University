#include "TurboEngine.h"

TurboEngine::TurboEngine(const string & f, const double pr):Engine(f,pr)
{
}

TurboEngine::~TurboEngine()
{
}

double TurboEngine::getPrice()
{
	double p;
	if (this->fuel == "diesel")
		p = this->bprice + 0.01 * 150;
	else
		p = this->bprice + 0.01 * 100;
	return p;

}

string TurboEngine::toString()
{
	stringstream buffer;
	buffer << "Turbo engine fuel:" << this->fuel <<" ";
	return buffer.str();
}

Engine * TurboEngine::clone()
{
	return new TurboEngine(*this);
}
