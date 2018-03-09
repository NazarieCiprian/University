#include "Car.h"

Car::Car(const string & b,Engine* eng):body(b),e(eng)
{
}

Car::~Car()
{
}

double Car::computePrice()
{
	double p;
	if (body == "sedan")
	{
		p = 8000 + this->e->getPrice();
	}
	else
		p = 9000 + this->e->getPrice();
	return p;
}

string Car::toString()
{
	stringstream buffer;
	buffer << "Car body:" << this->body << this->e->toString();
	return buffer.str();
}

Car * Car::clone()
{
	return new Car(*this);
}
