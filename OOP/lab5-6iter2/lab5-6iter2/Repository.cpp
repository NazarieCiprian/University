#include "Repository.h"

int Repository::findPos(double size, const std::string colour)
{
	TrenchCoat* coatsInArray = this->coats.getAllElems();
	for (int i = 0; i < this->coats.getSize(); i++)
	{
		TrenchCoat t = coatsInArray[i];
		if (t.getSize() == size && t.getColour() == colour)
			return i;
	}
	return -1;
}

int Repository::addCoat(const TrenchCoat & c)
{
	int pos = this->findPos(c.getSize(), c.getColour());
	if (pos != -1)
	{
		this->coats.increaseQuantity(c.getQuantity(), pos);
		return 0;
	}
	this->coats.add(c);
	return 1;
}

int Repository::removeCoat(double size, const std::string & colour)
{
	int pos = findPos(size, colour);
	if (pos == -1)
	{
		return 0;
	}
	this->coats.remove(pos);
	return 1;
}

int Repository::updateCoat(const TrenchCoat & c)
{
	int pos = this->findPos(c.getSize(), c.getColour());
	if (pos == -1)
	{
		return 0;
	}
	this->coats.update(c,pos);
	return 1;
}

void Repository::reduceQuantity(int pos)
{
	this->coats.reduceQuantity(pos);
}
