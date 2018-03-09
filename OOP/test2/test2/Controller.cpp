#include "Controller.h"
#include "Exception.h"
Controller::Controller(const Controller & c)
{
	for (auto c : c, cars)
		this->cars.push_back(c->clone());
}

Controller::~Controller()
{
	for (auto c : this->cars)
		delete c;
}

double Controller::addCar(const string & body, const string engine, const string & fuel, int autonomy)
{
	Engine* e;
	/*if (engine == "electric")
	{
		e = new ElectricEngine{ fuel,3000,autonomy };
	}
	else
	{
		e = new TurboEngine{ fuel,3000 };
	}*/
	e = this->createEngine(engine, fuel, autonomy);
	Car *c = new Car{ body,e->clone() };
	this->cars.push_back(c->clone());
	return c->computePrice();
}

vector<Car*> Controller::getCarMaxPrice(double price)
{
	vector<Car*> some;
	for (auto c : this->cars)
		if(c->computePrice()<price)
			some.push_back(c->clone());
	return some;
}

void Controller::writeToFile(vector<Car*> c,string filename)
{
	ofstream fout(filename);
	if (!fout.is_open())
		throw Exception("Cant open file");
	for (auto it : c)
	{
		if (it->getBody() == "sedan")
		{
			double price;
			price = it->computePrice();
			fout << it->toString() << " Price:" << price << endl;
		}
	}
	for (auto it : c)
	{
		if (it->getBody() == "convertible")
		{
			double price;
			price = it->computePrice();
			fout << it->toString() << " Price:" << price << endl;
		}
	}
}



Engine * Controller::createEngine(const string & eng, const string & fuel, int autonomy)
{
	if (eng == "electric")
		return new ElectricEngine{ fuel,3000,autonomy };
	else
		return new TurboEngine{ fuel,3000 };
}
