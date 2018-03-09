#include "Ui.h"
#include "Exception.h"
void Ui::run()
{
	this->ctrl.addCar("sedan", "electric", "electricity", 100);
	this->ctrl.addCar("convertible", "turbo", "diesel", 120);
	while (true)
	{
		int cmd = { 0 };
		cout << "Command:";
		cin >> cmd;
		cin.ignore();
		try
		{
			if (cmd == 0)
			{
				break;
			}
			else if (cmd == 1)
			{
				this->addCar();
			}
			else if (cmd == 2)
			{
				this->showAll();
			}
			else if (cmd == 3)
			{
				this->saveToFile();
			}
		}
		catch (Exception& e)
		{
			cout << e.getException() << endl;
		}
	}
}

void Ui::addCar()
{
	string body;
	cout << "Enter car body:";
	cin >> body;
	if (body != "sedan" && body != "convertible")
		throw Exception("Invalid body");
	string engine;
	cout << "Engine:";
	cin >> engine;
	if (engine != "electric" && engine != "turbo")
		throw Exception("Invalid engine");
	string fuel;
	cout << "Fuel:";
	cin >> fuel;
	if (fuel != "electricity" && fuel != "diesel" && fuel != "gasoline")
		throw Exception("Invalid fuel");
	int a;
	cout << "Autonomy:";
	cin >> a;
	double p = this->ctrl.addCar(body, engine, fuel, a);
	cout << "Body: " << body << " engine: " << engine << " fuel: " << fuel << " autonomy: " <<a<< endl;
	cout <<endl<< p << endl;
	
}

void Ui::showAll()
{
	vector<Car*> all = this->ctrl.getAll();
	for (auto a : all)
		cout << a->toString() <<" Price:"<<a->computePrice()<< endl;
}

void Ui::saveToFile()
{
	double price;
	cout << "Enter price:";
	cin >> price;
	cin.ignore();
	string filename;
	cout << "Filename:";
	cin >> filename;
	vector<Car*> some = this->ctrl.getCarMaxPrice(price);
	this->ctrl.writeToFile(some,filename);

}
