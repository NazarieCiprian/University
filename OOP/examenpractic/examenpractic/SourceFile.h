#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class SourceFile
{
private:
	string name;
	string status;
	string fcreator;
	string reviser;

public:
	SourceFile():name(""),status(""),fcreator(""),reviser(""){}
	SourceFile(const string& n,const string& s,const string& c,const string& r):name(n),status(s),fcreator(c),reviser(r){}

	string getName()const { return this->name; }
	string getStatus()const { return this->status; }
	string getFCreator()const { return this->fcreator; }
	string getReviser()const { return this->reviser; }

	void setStatus(const string& val) { this->status = val; }
	void setReviser(const string& val) { this->reviser = val; }

	friend istream& operator>>(istream& is, SourceFile& s);
	friend ostream& operator<<(ostream& os, const SourceFile& s);

private:
	vector<string> tokenize(string line, char delimiter);
};