#include "Iterator.h"

Iterator::Iterator(Set * set)
{
	this->set = set;
	this->current = this->set->tail;

}

Plate Iterator::getCurrent()
{
	return this->set->elems[this->current];
}

bool Iterator::valid()
{
	if (this->current == -1)
		return false;
	return true;
}

void Iterator::next()
{
	this->current = this->set->prev[this->current];
}

void Iterator::setIterator()
{
	this->current = this->set->tail;
}

void testIterator()
{
	Set* v = new Set{};
	Iterator r{ v };
	Plate a = Plate{ "AB",12,"ABC" };
	r.setIterator();
	assert(r.valid() == false);
	v->add(a);
	r.setIterator();
	assert(r.valid() == true);
	assert(r.getCurrent().getJud() == "AB");
	r.next();
	assert(r.valid() == false);
}
