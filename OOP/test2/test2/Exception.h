#pragma once
#include <string>
using namespace std;
class Exception
{
private:
	string message;

public:

	Exception(const string& msg):message(msg){}

	string getException() { return this->message; }

};