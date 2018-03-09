#include "Programmer.h"

istream & operator >> (istream & is, Programmer & p)
{
	string line;
	getline(is, line);
	vector<string>tokens = p.tokenize(line, ',');
	if (tokens.size() != 3)
		return is;
	p.name = tokens[0];
	p.nrrevised = stoi(tokens[1]);
	p.totalfile = stoi(tokens[2]);
	return is;
}

ostream & operator<<(ostream & os, const Programmer & p)
{
	os << p.name << "," << p.nrrevised << "," << p.totalfile << endl;
	return os;
}

vector<string> Programmer::tokenize(string line, char delimiter)
{
	stringstream buffer(line);
	string token;
	vector<string>result;
	while (getline(buffer, token, delimiter))
		result.push_back(token);
	return result;
}
