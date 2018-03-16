#include "RepoSet.h"
#include <iostream>
using namespace std;
Set::Set(int capacity)
{
	this->cap = capacity;
	this->elems = new Plate[this->cap];
	this->next = new int[this->cap];
	this->prev = new int[this->cap];
	this->head = -1;
	this->tail = -1;
	for (int i = 0; i < this->cap-1; i++)
	{
		this->next[i] = i + 1;
	}
	this->next[this->cap - 1] = -1;
	this->prev[0] = -1;
	for (int i = 1; i < this->cap; i++)
	{
		this->prev[i] = i - 1;
	}
	this->firstEmpty = 0;
}

Set::Set(const Set & v)
{
	this->cap = v.cap;
	this->elems = new Plate[this->cap];
	this->next = new int[this->cap];
	this->prev = new int[this->cap];
	for (int i = 0; i < this->cap; i++)
	{
		this->elems[i] = v.elems[i];
		this->next[i] = v.next[i];
		this->prev[i] = v.prev[i];
	}
	this->head = v.head;
	this->tail = v.tail;
	this->firstEmpty = v.firstEmpty;
}

Set::~Set()
{
	delete[]this->elems;
	delete[]this->next;
	delete[]this->prev;
}

Set & Set::operator=(const Set & v)
{
	if (this == &v)
		return *this;
	this->cap = v.cap;
	delete[]this->elems;
	delete[]this->next;
	delete[]this->prev;
	this->elems = new Plate[this->cap];
	this->next = new int[this->cap];
	this->prev = new int[this->cap];
	for (int i = 0; i < this->cap; i++)
	{
		this->elems[i] = v.elems[i];
		this->next[i] = v.next[i];
		this->prev[i] = v.prev[i];
	}
	this->head = v.head;
	this->tail = v.tail;
	this->firstEmpty = v.firstEmpty;
	return *this;


}

Plate & Set::operator[](int pos)
{
	return this->elems[pos];
}

void Set::add(const Plate & e)
{

	if (this->firstEmpty == -1)
		this->resize();
	
	if (this->search(e) == true)
		throw Exception("Plate already in set");
	int newElem = this->firstEmpty;
	this->firstEmpty = this->next[this->firstEmpty];
	if(this->firstEmpty!= -1)
		this->prev[this->firstEmpty] = -1;
	this->elems[newElem] = e;
	this->next[newElem] = this->head;
	if(this->head != -1)
		this->prev[this->head] = newElem;
	this->prev[newElem] = -1;
	this->head = newElem;
	this->tail = 0;
	//cout << this->size() << " ";
}


void Set::remove(const Plate & e)
{
	/*if (this->search(e) == false)
		throw Exception("Elemetn not in set");*/

	int current = this->head;
	int previous = -1;
	while (current != -1 && this->elems[current] != e)
	{
		previous = current;
		current = this->next[current];
	}
	if (current != -1)
	{
		if (current == this->head)
		{
			this->head = this->next[this->head];
			this->prev[this->head] = -1;
			this->prev[this->firstEmpty] = current;
			this->next[current] = this->firstEmpty;
			this->prev[current] = -1;
			this->firstEmpty = current;
		}
		else if (current == this->tail)
		{
			this->next[previous] = -1;
			this->tail = previous;
			this->next[current] = this->firstEmpty;
			this->prev[this->firstEmpty] = current;
			this->prev[current] = -1;
			this->firstEmpty = current;

		}
		else
		{
			this->next[previous] = this->next[current];
			this->prev[this->next[current]] = previous;
			this->next[current] = this->firstEmpty;
			this->prev[this->firstEmpty] = current;
			this->prev[current] = -1;
			this->firstEmpty = current;
		}
	}
	else
		throw Exception("Element not in set");
}

bool Set::search(const Plate & e)
{
	
	int current = this->head;
	while (current != -1 && this->elems[current] != e)
		current = this->next[current];
	if (current != -1)
		return true;
	return false;
}

int Set::size()
{
	int size = 0;
	int current = this->head;
	while (current != -1)
	{
		current = this->next[current];
		size++;
	}
	return size;
}

void Set::resize()
{
	int old = this->cap;
	this->cap *= 2;
	Plate* els=new Plate[this->cap];
	int* nex=new int[this->cap];
	int* pre=new int[this->cap];
	for (int i = 0; i < old; i++)
	{
		els[i] = this->elems[i];
		nex[i] = this->next[i];
		pre[i] = this->prev[i];
		/*this->elems[i] = els[i];
		this->next[i] = nex[i];
		this->prev[i] = pre[i];*/
	}
	for (int i = old; i < this->cap - 1; i++)
	{
		nex[i] = i + 1;
	}
	nex[this->cap-1] = -1;
	for (int i = old + 1; i < this->cap; i++)
	{
		pre[i] = i - 1;
	}
	pre[old] = - 1;
	this->firstEmpty = old;
	
	delete[]this->next;
	delete[]this->elems;
	delete[]this->prev;
	this->elems = els;
	this -> next = nex;
	this->prev = pre;

}

void testRepo()
{
	Set v;
	Plate a{ "CJ",10,"ABC" };
	Plate c{ "AB",10,"ABC" };
	v.add(a);
	assert(v.size() == 1);
	try
	{
		v.add(a);
	}
	catch(Exception& e)
	{
		assert(true);
	}
	Plate b{ "GJ",10,"ABC" };
	v.add(b);
	//assert(v.size() == 2);
	assert(v.search(a) == true);
	assert(v.search(c) == false);
	v.remove(b);
	v.add(b);
	v.add(c);
	v.remove(b);
	assert(v.size() == 2);
	try
	{
		v.remove(b);
	}
	catch (Exception& e)
	{
		assert(true);
		string exc = e.getMessage();
	}
	//Plate * elems = v.getAll();
	Set rep= v;

	Plate a1{ "SV",10,"LAL" };
	Plate b1{ "SV",87,"TZU" };
	Plate c1{ "SV",11,"LAL" };
	Plate d{ "SV",82,"TZU" };
	Plate e{ "SV",13,"LAL" };
	Plate f{ "SV",84,"TZU" };
	Plate g{ "SV",14,"LAL" };
	Plate h{ "SV",85,"TZU" };
	Plate i{ "SV",23,"LAL" };
	Plate j{ "SV",44,"TZU" };
	Plate k{ "SV",45,"TZU" };
	Set s;
	s.add(a1);
	s.add(b1);
	s.add(c1);
	s.add(d);
	s.add(e);
	s.add(f);
	s.add(g);
	s.add(h);
	s.add(i);
	s.add(j);
	s.add(k);
	v = v;
	v = s;
	//v.remove(a1);
	Plate plat = s[0];
	
}
