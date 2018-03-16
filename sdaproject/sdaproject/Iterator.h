#pragma once
#include "Plate.h"
#include "RepoSet.h"
class Iterator 
{
private:
	Set* set;
	int current;

public:
	Iterator(Set* set);
	Plate getCurrent();
	bool valid();
	void next();
	void setIterator();
	//Set* getSet() { return set; }
};

void testIterator();