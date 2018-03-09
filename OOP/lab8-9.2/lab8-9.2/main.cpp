#include "Ui.h"
#include "CSVBasket.h"
#include "HtmlBasket.h"
int main()
{
	//testRepo();
	Repository r{ "coats.txt" };
	CoatValidator val;
	HtmlBasket* b = new HtmlBasket();
	CSVBasket* p = new CSVBasket();
	int a;
	cout << "The cart will be stored in html or csv?(0/1)";
	cin >> a;
	cin.ignore();
	if (a == 0)
	{
		Controller ctrl{ r,b,val };
		Ui ui{ ctrl };
		ui.run();
	}
	else
	{
		Controller ctrl{ r,p,val };
		Ui ui{ ctrl };
		ui.run();
	}
	
	delete b;
	delete p;
	return 0;

}