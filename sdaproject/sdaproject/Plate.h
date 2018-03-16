#pragma once
#include <string>
#include <assert.h>
using namespace std;

class Plate
{
private:
	string jud;
	int number;
	string randchars;

public:
	/*
	Contrustctors for objects of type plate
	*/
	Plate();
	Plate(const string& jud, const int nr, const string& r);
	/*
	Getters for the object atributes
	*/
	string getJud()const { return jud; }
	int getNumber()const { return number; }
	string getRand()const { return randchars; }
	/*
	Setters for the objects atributes
	*/
	void setJud(const string& j);
	void setNumber(const int nr);
	void setRand(const string& r);
	/*
	Overwritting the != opeartor
	*/
	bool operator !=(const Plate& e);
};

void testPlate();