#include "myclass.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
#include "Repository.h"
#include "Controller.h"
#include "TrenchCoat.h"
#include "HtmlBasket.h"
#include "CSVBasket.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository r{ "coats.txt" };
	TrenchCoat b{ 120,"red",10,50.9,"google" };
	TrenchCoat d{ 130,"blue",20,60.9,"google" };
	//r.addCoat(d);
	CoatValidator val;
	HtmlBasket* p = new HtmlBasket{};
	Controller *ctrl=new Controller{ r,p,val };
	GUI w{ ctrl };
	w.show();

	return a.exec();
}
