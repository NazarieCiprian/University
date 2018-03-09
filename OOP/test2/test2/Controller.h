#pragma once
#include "Car.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

class Controller
{
private:
	vector<Car*> cars;
public:

	Controller(){}
	Controller(const Controller& c);
	~Controller();
	
	double addCar(const string& body, const string engine, const string& fuel, int autonomy);
	vector<Car*> getAll() { return this->cars; }
	vector<Car*> getCarMaxPrice(double price);
	void writeToFile(vector<Car*> c,string filename);
	
private:
	Engine* createEngine(const string& eng, const string& fuel, int autonomy);

};