#include "utils.h"

vector<string> tokenize(const string & str, char delimiter)
{
	vector<string>result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
	{
		result.push_back(token);
	}
	return result;


}
