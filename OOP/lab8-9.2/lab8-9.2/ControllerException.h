#pragma once
#include <string>
using namespace std;
class ControllerException
{
private:
	string message;
public:
	ControllerException(const string& msg):message(msg){}
	string getMessage()const { return this->message; }
};