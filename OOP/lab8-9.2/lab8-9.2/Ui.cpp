#include "Ui.h"

void Ui::run()
{
	while (true)
	{
		this->printMenu();
		int cmd = { 0 };
		cout << "Enter a command:";
		cin >> cmd;
		cin.ignore();
		if (cmd == 0)
		{
			break;
		}
		else if (cmd == 1)
		{
			while (true)
			{
				this->printAdminMenu();
				int cmdad = { 0 };
				cout << "Enter admin command:";
				cin >> cmdad;
				cin.ignore();
				if (cmdad == 0)
				{
					break;
				}
				if (cmdad == 1)
				{
					this->addCoatMenu();
				}
				else if (cmdad == 2)
				{
					this->showAll();
				}
				else if (cmdad == 3)
				{
					this->removeCoatMenu();
				}
				else if (cmdad == 4)
				{
					this->updateCoatMenu();
				}

			}
			
		}
		else if (cmd == 2)
		{
			while (true)
			{
				this->printUserMenu();
				int cmdu = { 0 };
				cout << "Enter user command:";
				cin >> cmdu;
				cin.ignore();
				if (cmdu == 0)
				{
					this->ctrl.emptyBasket();
					break;
				}
				else if (cmdu == 1)
				{
					this->showBySize();
				}
				else if (cmdu == 2)
				{
					this->addToBasket();
				}
				else if (cmdu == 3)
				{
					this->nextMenu();
				}
				else if (cmdu == 4)
				{
					this->showCart();
				}
				else if (cmdu == 5)
				{
					this->saveCart();
				}
				else if (cmdu == 6)
				{
					this->ctrl.openFile();
				}
			}
		}
		
	}
}

void Ui::printMenu()
{
	cout << "Available commands:" << endl;
	cout << "0 - to exit the app" << endl;
	cout << "1 - to enter admin mode" << endl;
	cout << "2 - to enter user mode" << endl;
}

void Ui::printAdminMenu()
{
	cout << "Available Admin Commands:" << endl;
	cout << "0 - to exit admin mode" << endl;
	cout << "1 - to add a new coat to the repo" << endl;
	cout << "2 - to see the contents of the repo" << endl;
	cout << "3 - to delete the contents of the repo" << endl;
	cout << "4 - to update the information of a coat" << endl;

}

void Ui::printUserMenu()
{
	cout << "Available user commands:" << endl;
	cout << "1 - to see the coats by size" << endl;
	cout << "2 - to buy the current coat" << endl;
	cout << "3 - to go to the next coat" << endl;
	cout << "4 - to see the cart and the bill" << endl;
	cout << "5 - to save the cart in a file or html" << endl;
	cout << "6 - to open the file/browser" << endl;
}

void Ui::showBySize()
{
	double size;
	cout << "Enter the size to see certain coats or 0 to see all of them:";
	cin >> size;
	cin.ignore();
	try
	{
		this->ctrl.showBySize(size);
	}
	catch (ControllerException& e)
	{
		cout << e.getMessage() << endl;
	}
	TrenchCoat c = this->ctrl.getCurrent();
	cout << "Do you want to buy it? Then enter 2" << endl;
	cout <<"Size:"<< c.getSize() << " Colour:" << c.getColour() << " Quantity:" << c.getQuantity() << " Price:" << c.getPrice()<<endl;
}

void Ui::addToBasket()
{
	try
	{
		TrenchCoat t = this->ctrl.getCurrent();
		this->ctrl.addToBasket(t);
		TrenchCoat c = this->ctrl.getCurrent();
		cout << "Size:" << c.getSize() << " Colour:" << c.getColour() << " Quantity:" << c.getQuantity() << " Price:" << c.getPrice() << endl;
	}
	catch (ControllerException& e)
	{
		cout << e.getMessage() << endl;
	}

		
	
}

void Ui::nextMenu()
{
	try
	{
		TrenchCoat t = this->ctrl.next();
		cout << "Do you want to buy it? Then enter 2" << endl;
		cout << "Size:" << t.getSize() << " Colour:" << t.getColour() << " Quantity:" << t.getQuantity() << " Price:" << t.getPrice() << endl;

	}
	catch (ControllerException& e)
	{
		cout << e.getMessage() << endl;
	}
}

void Ui::showCart()
{
	vector<TrenchCoat> coat = this->ctrl.getCart();
	double bill = this->ctrl.getBill();
	if (coat.size() == 0)
		cout << "The cart is empty" << endl;
	else
	{
		cout << "The bill is:" << bill << endl;
		for (auto c : coat)
			cout << "Size:" << c.getSize() << " Colour:" << c.getColour() << " Price:" << c.getPrice() << endl;
	}
	
}

void Ui::saveCart()
{
	string filename;
	cout << "Input the name of the file:" << endl;
	cin >> filename;
	try
	{
		this->ctrl.saveCart(filename);

	}
	catch (FileException& e)
	{
		cout << e.getMessage() << endl;
	}
}


void Ui::showAll()
{
	vector<TrenchCoat> v = this->ctrl.getCoats();
	for (auto coat : v)
		cout << "Size:" << coat.getSize() << " Colour:" << coat.getColour() << " Quantity:" << coat.getQuantity() << " Price:" << coat.getPrice() << endl;
}

void Ui::addCoatMenu()
{
	double size;
	cout << "Enter the size:";
	cin >> size;
	cin.ignore();
	std::string colour;
	cout << "Enter the colour:";
	cin >> colour;
	cin.ignore();
	int quantity;
	cout << "Enter the quantity:";
	cin >> quantity;
	cin.ignore();
	double price;
	cout << "Enter the price:";
	cin >> price;
	cin.ignore();
	std::string photo;
	cout << "Enter the photo:";
	cin >> photo;
	cin.ignore();
	TrenchCoat c{ size,colour,quantity,price,photo };
	try
	{
		this->ctrl.addCoatCont(c);
	}
	catch (RepositoryException& e)
	{
		cout << e.getMessage() << endl;
	}
	catch (FileException& e)
	{
		cout << e.getMessage() << endl;
	}
	catch (CoatException& e)
	{
		for (auto i : e.getErrors())
			cout << i << endl;

	}
}

void Ui::updateCoatMenu()
{
	double size;
	cout << "Enter the size:";
	cin >> size;
	cin.ignore();
	std::string colour;
	cout << "Enter the colour:";
	cin >> colour;
	cin.ignore();
	int quantity;
	cout << "Enter the quantity:";
	cin >> quantity;
	cin.ignore();
	double price;
	cout << "Enter the price:";
	cin >> price;
	cin.ignore();
	std::string photo;
	cout << "Enter the photo:";
	cin >> photo;
	cin.ignore();
	TrenchCoat c{ size,colour,quantity,price,photo };
	try
	{
		return this->ctrl.updateCoatCont(c);
	}
	catch (FileException& e)
	{
		cout << e.getMessage() << endl;
	}
	catch (RepositoryException& e)
	{
		cout << e.getMessage()<<endl;
	}
	catch (CoatException& e)
	{
		for (auto i : e.getErrors())
			cout << i << endl;
	}
}

void Ui::removeCoatMenu()
{
	double size;
	cout << "Enter the size:";
	cin >> size;
	cin.ignore();
	std::string colour;
	cout << "Enter the colour:";
	cin >> colour;
	cin.ignore();
	int quantity;
	cout << "Enter the quantity:";
	cin >> quantity;
	cin.ignore();
	double price;
	cout << "Enter the price:";
	cin >> price;
	cin.ignore();
	std::string photo;
	cout << "Enter the photo:";
	cin >> photo;
	cin.ignore();
	TrenchCoat c{ size,colour,quantity,price,photo };
	
	try
	{
		this->ctrl.removeCoatCont(c);
	}
	catch (FileException& e)
	{
		cout << e.getMessage() << endl;
	}
	catch (RepositoryException& e)
	{
		cout << e.getMessage() << endl;
	}
	catch (CoatException& e)
	{
		for (auto i : e.getErrors())
			cout << i << endl;
	}
}
