#pragma once
#include "RepoSet.h"
#include "Iterator.h"
#include <iostream>
using namespace std;
class Ui
{
private:
	Set *repo;
	Iterator it;
public:
	
	Ui(Set* r):repo(r),it(r){}

	void run();

private:

	void addMenu();
	void printMenu();
	void removeMenu();
	void searchMenu();
	void sizeMenu();

};

void testValidator();