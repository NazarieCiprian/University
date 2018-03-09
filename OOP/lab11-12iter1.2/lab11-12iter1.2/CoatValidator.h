#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "TrenchCoat.h"
using namespace std;
class CoatException
{
private:
	vector<string> message;

public:
	CoatException(vector<string> err);
	vector<string> getErrors()const;

};

class CoatValidator
{
public:
	CoatValidator() {}
	static void validate(const TrenchCoat& t);
}; 
