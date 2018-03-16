#include "Ui.h"
#include "Validator.h"
void Ui::run()
{
	while (true)
	{
		try
		{
			int cmd = { 0 };
			cout << "Command:";
			cin >> cmd;
			cin.ignore();
			if (cmd == 0)
			{
				break;
			}
			else if (cmd == 1)
			{
				this->addMenu();
			}
			else if (cmd == 2)
			{
				this->printMenu();
			}
			else if (cmd == 3)
			{
				this->removeMenu();
			}
			else if (cmd == 4)
			{
				this->searchMenu();
			}
			else if (cmd == 5)
			{
				this->sizeMenu();
			}
		}
		catch (Exception& e)
		{
			cout << e.getMessage() << endl;
		}
	}
}

void Ui::addMenu()
{
	string jud;
	cout << "Judet:";
	cin >> jud;
	int nr;
	cout << "Number:";
	cin >> nr;
	string chars;
	cout << "Random chars:";
	cin >> chars;
	Plate a{ jud,nr,chars };
	valid(a);
	//it.getSet()->add(a);
	this->repo->add(a);
}

void Ui::printMenu()
{
	//cout << "Salut";
	//cout << it.getCurrent().getJud();
	this->it.setIterator();
	cout << it.getCurrent().getNumber();
	while (it.valid())
	{
		Plate a = it.getCurrent();
		cout << "Plate:" << a.getJud() << " " << a.getNumber() << " " << a.getRand() << endl;
		it.next();
	}
}

void Ui::removeMenu()
{
	string jud;
	cout << "Judet:";
	cin >> jud;
	int nr;
	cout << "Number:";
	cin >> nr;
	cin.ignore();
	string chars;
	cout << "Chars:";
	cin >> chars;
	Plate a{ jud,nr,chars };
	valid(a);
	this->repo->remove(a);
	//cout << this->repo.size();
}

void Ui::searchMenu()
{
	string jud;
	cout << "Enter the district:";
	cin >> jud;
	int number;
	cout << "Enter the number:";
	cin >> number;
	string chars;
	cout << "Enter 3 random chars:";
	cin >> chars;
	Plate a{ jud,number,chars };
	valid(a);
	if (this->repo->search(a))
		cout << "Plate is in storage" << endl;
	else
		cout << "Plate is not in storage" << endl;

}

void Ui::sizeMenu()
{
	int size = this->repo->size();
	cout << "Size of the set is:" << size << endl;
}

void testValidator()
{
	Plate a{ "12",12,"ABC" };
	Plate b{ "SV",-1,"ABC" };
	Plate c{ "SV",12,"123" };
	try
	{
		valid(a);
	}
	catch (Exception& e)
	{
		assert(true);
	}

	try
	{
		valid(b);
	}
	catch (Exception& e)
	{
		assert(true);
	}
	try
	{
		valid(c);
	}
	catch (Exception& e)
	{
		assert(true);
	}
	Plate d{ "S",12,"ABC" };
	Plate e{ "SV",12,"AB" };
	try
	{
		valid(d);
	}
	catch (Exception& exc)
	{
		assert(true);
	}
	try
	{
		valid(e);
	}
	catch (Exception& exc)
	{
		assert(true);
	}
	Plate val{ "SV",10,"ABC" };
	valid(val);
}
