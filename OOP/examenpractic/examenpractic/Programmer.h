#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class Programmer
{
private:
	string name;
	int nrrevised;
	int totalfile;

public:
	Programmer():name(""),nrrevised(0),totalfile(0){}
	Programmer(const string& n,const int rev,const int total):name(n),nrrevised(rev),totalfile(total){}
	
	string getName()const { return this->name; }
	int getNrRevised()const { return this->nrrevised; }
	int getTotalFile()const { return this->totalfile; }

	void setNrRevised(int val) { this->nrrevised = val; }

	friend istream& operator >> (istream& is, Programmer& p);
	friend ostream& operator<<(ostream& os, const Programmer& p);

private:
	vector<string> tokenize(string line, char delimiter);
};