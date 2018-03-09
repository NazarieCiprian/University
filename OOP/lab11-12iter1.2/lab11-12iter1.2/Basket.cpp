#include "Basket.h"

Basket::Basket()
{
	this->bill = 0;
	this->current = 0;
}

void Basket::setFiltered(const vector<TrenchCoat>& v)
{
	for (auto c : v)
		this->filtered.push_back(c);
}

void Basket::addCoatCart(const TrenchCoat & t)
{
	this->cart.push_back(t);
	this->bill += t.getPrice();
}

void Basket::reduceQuantity(const TrenchCoat & t)
{
	for (auto& coat : this->filtered)
		if (coat.getColour() == t.getColour() && coat.getSize() == t.getSize())
			coat.setQuantity(coat.getQuantity() - 1);
}

void Basket::setCurret()
{
	if (this->current == this->filtered.size() - 1)
	{
		this->current = 0;
	}
	else
		this->current++;
}

TrenchCoat Basket::next()
{
	if (this->filtered.size() == 0)
		throw ControllerException("You haven't choose what you want to see yet");
	if (this->current == this->filtered.size() - 1)
		this->current = 0;
	else
		this->current++;

	return this->filtered[this->current];
}

TrenchCoat Basket::getCurrent()
{
	if (this->filtered.size() == 0)
		throw ControllerException("You haven't choose what you want to see yet");
	return this->filtered[this->current];
}

void Basket::emptyFiltered()
{
	this->filtered.clear();
	this->cart.clear();
	this->bill = 0;
	this->current = 0;
}

void Basket::remove(const TrenchCoat & t)
{
	this->filtered.erase(this->filtered.begin() + this->current);
}
