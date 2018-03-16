#pragma once
#include "Plate.h"
#include "Exception.h"
class Set
{
	friend class Iterator;
private:
	Plate *elems;
	int *next;
	int *prev;
	int firstEmpty;
	int head;
	int tail;
	int cap;

public:
	//Set constructor
	Set(int capacity = 10);
	//Set copy constructor
	Set(const Set& v);
	//destructor
	~Set();
	Set& operator=(const Set& v);
	Plate& operator[](int pos);
	/*
	Adds a new elemet to the list of elements
	Input:e - an element of type Plates
	Output:-
	Throws an exception if the plate already exists
	*/
	void add(const Plate& e);
	/*
	Removes an element from the list of elements
	Input:e - the element we want to remove
	Output:-
	Throws an exception if the element does not exist
	*/
	void remove(const Plate& e);
	/*
	Searches for an element 
	Input:e - the element we are looking for
	Output:returns true if the element exists and false otherwise
	*/
	bool search(const Plate& e);
	/*
	Returns the size of the set
	Input:-
	Output: an integer representing the number of elements in the set
	*/
	int size();
	
	//Plate* getAll() { return this->elems; }
private:
	/*
	Performs a resize for the case in which the set is full.Doubles its dimension
	*/
	void resize();

};
void testRepo();
