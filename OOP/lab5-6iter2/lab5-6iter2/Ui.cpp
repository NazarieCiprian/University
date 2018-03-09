#include "Ui.h"
#include <string>
void Ui::run()
{
	while (true)
	{
		Ui::printMenu();
		int command{ 0 };
		cout << "Input the command:";
		cin >> command;
		cin.ignore();
		if (command == 0)
		{
			cout << "Bye bye";
			break;
		}
		else if (command == 1)
		{
			while (true)
			{
				Ui::printAdminMenu();
				int adcommand{ 0 };
				cout << "Input the command:";
				cin >> adcommand;
				cin.ignore();
				if (adcommand == 1)
				{
					this->addCoatMenu();
				}
				else if (adcommand == 2)
				{
					this->showAllCoats();
				}
				else if (adcommand == 3)
				{
					this->removeCoatMenu();
				}
				else if (adcommand == 4)
				{
					this->updateCoatMenu();
				}
				else if (adcommand == 5)
				{
					this->showLess();
				}
				else if (adcommand == 0)
				{
					cout << "Back to normal mode" << endl;
					break;
				}
			}
			

		}
		else if (command == 2)
		{
			while (true)
			{
				Ui::printUserMenu();
				int ucommand{ 0 };
				cout << "Input a command:";
				cin >> ucommand;
				cin.ignore();
				if (ucommand == 1)
				{
					this->goThrough();
				}
				else if (ucommand == 0)
				{
					break;
				}
			}
		}
	}
}
void Ui::printMenu()
{
	cout << "Available commands:" << endl;
	cout << "0 - to exit application" << endl;
	cout << "1 - to enter admin mode" << endl;
	cout << "2 - to enter the user mode" << endl;
}

void Ui::printAdminMenu()
{
	cout << "Available commands for admin:" << endl;
	cout << "0 - to exit admin mode" << endl;
	cout << "1 - to add a new trenchcoat" << endl;
	cout << "2 - to see the contents" << endl;
	cout << "3 - to remove a trenchcoat" << endl;
	cout << "4 - to update the trenchcoat" << endl;
}

void Ui::printUserMenu()
{
	cout << "Available user commands: " << endl;
	cout << "1 - to go through the coats\n" << endl;
	cout << "0 - to see return to exit user mode\n" << endl;
}

void Ui::showAllCoats()
{
	DynamicVector<TrenchCoat> coats = this->ctrl.getRepo().getCoats();
	TrenchCoat* tc = coats.getAllElems();
	int n = coats.getSize();
	if (tc == NULL)
		return;
	if (n == 0)
	{
		cout << "There are no coats" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			TrenchCoat c = tc[i];
			cout << "Size:" << c.getSize() << " " << "Colour:" << c.getColour() << " " << "Price:" << c.getPrice() << " " << "Quantity:" << c.getQuantity()<<" Length:"<<c.getLength() << endl;
		}
	}
}

void Ui::addCoatMenu()
{
	double size;
	cout << "Enter the size: ";
	cin >> size;
	cin.ignore();
	std::string colour;
	cout << "Enter the colour:";
	cin >> colour;
	double price;
	cout << "Enter the price: ";
	cin >> price;
	cin.ignore();
	int quantity;
	cout << "Enter the quantity:";
	cin >> quantity;
	cin.ignore();
	cout << "Enter the link:";
	std::string photo;
	cin >> photo;
	double length;
	cout << "Enter the length:";
	cin >> length;
	cin.ignore();
	int res=this->ctrl.addCoatCont(size, colour, price, quantity, photo,length);
	if (res == 1)
	{
		cout << "New coat has been added"<<endl;
	}
	else
	{
		cout << "Coat already exists;quantity has been updated"<<endl;
	}
}

void Ui::removeCoatMenu()
{
	double size;
	cout << "Enter the size: ";
	cin >> size;
	cin.ignore();
	std::string colour;
	cout << "Enter the colour:";
	cin >> colour;
	int res=this->ctrl.removeCoatCont(size, colour);
	if (res == 1)
	{
		cout << "Coat succesful removed"<<endl;
	}
	else
	{
		cout << "Error!Could not remove coat"<<endl;
	}
}

void Ui::updateCoatMenu()
{
	double size;
	cout << "Enter the size: ";
	cin >> size;
	cin.ignore();
	std::string colour;
	cout << "Enter the colour:";
	cin >> colour;
	double price;
	cout << "Enter the price: ";
	cin >> price;
	cin.ignore();
	int quantity;
	cout << "Enter the quantity:";
	cin >> quantity;
	cin.ignore();
	cout << "Enter the link:";
	std::string photo;
	cin >> photo;
	double length;
	cout << "Enter the length:";
	cin >> length;

	int res = this->ctrl.updateCoatCont(size, colour, price, quantity, photo,length);
	if (res == 1)
	{
		cout << "Information has been updated" << endl;
	}
	else
	{
		cout << "Information has not been updated" << endl;
	}
}

void Ui::goThrough()
{
	int size;
	cout << "Please enter the size or 0 for all coats:";
	cin >> size;
	cin.ignore();
	while (size < 0)
	{
		cout << "Please enter the size or 0 for all coats:";
		cin >> size;
		cin.ignore();
	}
	DynamicVector<TrenchCoat> coats = this->ctrl.getRepo().getCoats();
	TrenchCoat* tc = coats.getAllElems();
	int length = coats.getSize();
	int i, cmd;
	
	if (size == 0)
	{
		i = 0;
		int tmpl;
		tmpl = length;
		while (true)
		{
			TrenchCoat c = tc[i];
			cout << "Current coat:" << endl;
			cout << "Size:" << c.getSize() << " " << "Colour:" << c.getColour() << " " << "Price:" << c.getPrice() << " " << "Quantity:" << c.getQuantity() << endl;
			//tc[i].showPhoto();
			cout << "Available options: "<<endl;
			cout << " 1 - buy the coat;" << endl;
			cout << "2 - to go to next coat" << endl;
			cout << "3 - to see your basket" << endl;
			cout << "4 - to exit " << endl;
			cin >> cmd;
			cin.ignore();
			if (cmd == 1)
			{
				this->ctrl.addBag(tc[i]);
				tc[i].setQuantity(tc[i].getQuantity() - 1);
				this->ctrl.reduceQuantity(i);
				cout << "Current bill is:" << this->ctrl.getBill() << endl;
				if (tc[i].getQuantity() == 0)
				{
					int res = this->ctrl.removeCoatCont(tc[i].getSize(), tc[i].getColour());
					coats.remove(i);
					TrenchCoat* tc = coats.getAllElems();
					if (i ==tmpl-1)
					{
						i = 0;
					}
					tmpl--;
				}

			}
			else if (cmd == 2)
			{
				if (i == tmpl - 1)
					i = 0;
				else
					i++;
			}
			else if (cmd == 3)
			{	
				cout << "Your basket contains: ";
				this->ctrl.printBag();

			}
			else if (cmd == 4)
			{
				break;
			}
			
		}
	}
	else
	{
		i = 0;
		int tmpl;
		tmpl = length;
		while (true)
		{
			TrenchCoat c = tc[i];
			if (tc[i].getSize() == size)
			{
				cout << "Current coat:" << endl;
				cout << "Size:" << c.getSize() << " " << "Colour:" << c.getColour() << " " << "Price:" << c.getPrice() << " " << "Quantity:" << c.getQuantity() << endl;
				cout << "Available options: " << endl;
				cout << " 1 - buy the coat;" << endl;
				cout << "2 - to go to next coat" << endl;
				cout << "3 - to see your basket" << endl;
				cout << "4 - to exit " << endl;
				cin >> cmd;
				cin.ignore();
				if (cmd == 1)
				{
					this->ctrl.addBag(tc[i]);
					tc[i].setQuantity(tc[i].getQuantity() - 1);
					this->ctrl.reduceQuantity(i);
					cout << "Current bill is:" << this->ctrl.getBill() << endl;
					if (tc[i].getQuantity() == 0)
					{
						int res = this->ctrl.removeCoatCont(tc[i].getSize(), tc[i].getColour());
						coats.remove(i);
						TrenchCoat* tc = coats.getAllElems();
						if (i == tmpl - 1)
						{
							i = 0;
						}
						tmpl--;
					}

				}
				else if (cmd == 2)
				{
					if (i == tmpl - 1)
						i = 0;
					else
						i++;
				}
				else if (cmd == 3)
				{
					cout << "Your basket contains: ";
					this->ctrl.printBag();

				}
				else if (cmd == 4)
				{
					break;
				}

			}
			else
			{
				if (i == tmpl - 1)
				{
					i = 0;
				}
				else
					i++;
			}
			
			}
		}
	
}

void Ui::showLess()
{
	int lungime;
	cout << "Enter the length:";
	cin >> lungime;
	cin.ignore();
	DynamicVector<TrenchCoat> coats = this->ctrl.getRepo().getCoats();
	int length = coats.getSize();
	TrenchCoat *tc = coats.getAllElems();
	for (int i = 0; i < length; i++)
	{
		TrenchCoat c = tc[i];
		if(c <lungime)
			cout << "Size:" << c.getSize() << " " << "Colour:" << c.getColour() << " " << "Price:" << c.getPrice() << " " << "Quantity:" << c.getQuantity() <<" Length:"<<c.getLength()<< endl;
	}
}
