#include "Plate.h"

Plate::Plate():jud(""),number(0),randchars("")
{
}

Plate::Plate(const string & jud, const int nr, const string & r)
{
	this->jud = jud;
	this->number = nr;
	this->randchars = r;
}

void Plate::setJud(const string & j)
{
	this->jud = j;
}

void Plate::setNumber(const int nr)
{
	this->number = nr;
}

void Plate::setRand(const string & r)
{
	this->randchars = r;
}

bool Plate::operator!=(const Plate & e)
{
	if (this->jud != e.jud || this->number != e.number || this->randchars != e.randchars)
		return true;
	return false;
}

void testPlate()
{
	Plate a;
	Plate b{ "SV",97,"BCJ" };
	string c = b.getJud();
	assert(c == "SV");
	c = b.getRand();
	assert(c == "BCJ");
	int n = b.getNumber();
	assert(n == 97);
	b.setJud("CJ");
	assert(b.getJud() == "CJ");
	b.setNumber(14);
	assert(b.getNumber() == 14);
	b.setRand("AAA");
	assert(b.getRand() == "AAA");

}
