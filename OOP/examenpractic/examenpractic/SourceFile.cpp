#include "SourceFile.h"

istream & operator >> (istream & is, SourceFile & s)
{
	string line;
	getline(is, line);
	vector<string>tokens = s.tokenize(line, ',');
	if (tokens.size() != 4)
		return is;
	s.name = tokens[0];
	s.status = tokens[1];
	s.fcreator = tokens[2];
	s.reviser = tokens[3];
	return is;
}

ostream & operator<<(ostream & os, const SourceFile & s)
{
	os << s.name << "," << s.status << "," << s.fcreator << "," << s.reviser << endl;
	return os;
}

vector<string> SourceFile::tokenize(string line, char delimiter)
{
	stringstream buffer(line);
	string token;
	vector<string>result;
	while (getline(buffer, token, delimiter))
		result.push_back(token);
	return result;
}
