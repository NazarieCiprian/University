#include "Controller.h"

void Controller::addCoatCont(const TrenchCoat & t)
{
	valid.validate(t);
	this->repo.addCoat(t);
}

void Controller::updateCoatCont(const TrenchCoat & t)
{
	valid.validate(t);
	this->repo.updateCoat(t);

}

void Controller::removeCoatCont(const TrenchCoat & t)
{
	valid.validate(t);
	this->repo.removeCoat(t);
}

bool Controller::sizeSort(TrenchCoat a, TrenchCoat b)
{
	if (a.getSize() < b.getSize())
		return true;
	return false;
}

vector<TrenchCoat> Controller::getSortedCoats()
{
	vector<TrenchCoat> v=this->repo.getAll();
	TrenchCoat x;
	for(unsigned int  i = 0;i<v.size()-1;i++)
		for(unsigned int j = i+1;j<v.size();j++)
		if (sizeSort(v[i], v[j]) == false)
		{
			x = v[i];
			v[i] = v[j];
			v[j] = x;
		}
	return v;

}

void Controller::showBySize(double size)
{
	vector<TrenchCoat> all = this->getCoats();
	if (size == 0)
	{
		this->bask->setFiltered(all);
	}
	else
	{
		vector<TrenchCoat> sent;
		for (auto coat : all)
		{
			if (coat.getSize() == size)
				sent.push_back(coat);
		}
		this->bask->setFiltered(sent);
	}
}

void Controller::addToBasket(const TrenchCoat & c)
{
	this->bask->reduceQuantity(c);
	TrenchCoat t = this->bask->getCurrent();
	this->repo.updateCoat(t);
	if (this->bask->getCurrent().getQuantity() == 0)
	{
		this->bask->remove(c);
		this->repo.removeCoat(c);
		this->bask->setCurret();
	}
	this->bask->addCoatCart(c);
}

void Controller::emptyBasket()
{
	this->bask->emptyFiltered();
}

void Controller::saveCart(const string& filename)
{
	if (this->bask == nullptr)
		return;
	this->bask->setFilename(filename);
	this->bask->writeToFile();
}

void Controller::openFile()
{
	if (this->bask == nullptr)
		return;
	this->bask->displayBasket();
}
