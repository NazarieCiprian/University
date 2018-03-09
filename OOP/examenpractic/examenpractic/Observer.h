#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
	virtual ~Observer(){}
	virtual void update() = 0;
};

class Observable
{
private:
	vector<Observer*> observers;

public:
	virtual ~Observable(){}

	void addObserver(Observer* obs)
	{
		this->observers.push_back(obs);
	}
	void removeObserver(Observer* obs)
	{
		this->observers.erase(remove(observers.begin(), observers.end(), obs));
	}

	void notify()
	{
		for (auto it : this->observers)
			it->update();
	}
};