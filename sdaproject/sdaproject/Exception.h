#pragma once
#include <string>
using namespace std;

class Exception
{
private:
	string message;

public:
	Exception(const string& msg):message(msg){}
	string getMessage() { return this->message; }
};