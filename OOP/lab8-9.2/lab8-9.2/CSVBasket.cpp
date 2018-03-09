#include "CSVBasket.h"

void CSVBasket::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("Cant open CSV file");
	for (auto c : this->getCart())
		file << c;
	file.close();

}

void CSVBasket::displayBasket()
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "D:\\Program Files (x86)\\Microsoft Office\\Office14\\EXCEL.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
