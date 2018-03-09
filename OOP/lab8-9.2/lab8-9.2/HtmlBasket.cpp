#include "HtmlBasket.h"
#include <Windows.h>
void HtmlBasket::writeToFile()
{
	ofstream f(this->filename);
	if (!f.is_open())
		throw FileException("Cant open file");
	f << "<!DOCTYPE html> \n";
	f << "<html>";
	f << "<head>\n";
	f << "<title>Basket</title>\n";
	f << "</head>\n";
	f << "<body>\n";
	f << "<table border=\"1\">\n ";
	f << "<tr>\n";
	f << "<td>Size</td>\n";
	f << "<td>Colour</td>\n";
	f << "<td>Quantity</td>\n";
	f << "<td>Price</td>\n";
	f << "<td>Link</td>\n";
	f << "</tr>\n";
	for (auto c : this->getCart())
	{
		f << "<tr>\n";
		f << "<td>\n" << c.getSize() << "</td>\n";
		f << "<td>\n" << c.getColour() << "</td>\n";
		f << "<td>\n" << c.getQuantity() << "</td>\n";
		f << "<td>\n" << c.getPrice() << "</td>\n";
		f << "<td>\n" << "<a href=" << c.getPhoto()<<"</a>" << "</td>\n";
		f << "</tr>\n";
	}
	f << "</table>\n";
	f << "</body>\n";
	f << "</html>\n";
	f.close();

}

void HtmlBasket::displayBasket()
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Opera\\launcher.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
