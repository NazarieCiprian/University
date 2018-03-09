#pragma once
#include "Repository.h"
#include "Bag.h"
class Controller
{
private:
	Repository repo;
	Bag bag;
public:
	//default constructor for controller
	Controller(const Repository& r):repo(r){}
	/*
	Adds a trechcoat with the given data to the repository
	Returns 1 if we added a new trenchcoat or 0 if we update the quantity
	*/
	int addCoatCont(double size, const std::string& colour, double price,int quantity,const std::string& photo,double length);
	/*
	Removes a coat from the repository
	Input:size - the size of the trenchcoat
	colour - the colour of the trenchcoat
	Returns 1 if we succesfull remoe the coat and 0 otherwise
	*/
	int removeCoatCont(double size, std::string& colour);

	int updateCoatCont(double size, const std::string& colour, double price, int quantity, const std::string& photo,double length);
	void addBag(const TrenchCoat& tc);
	double getBill() { return this->bag.getBill(); }
	void printBag();
	Repository getRepo()const { return repo; }

	void reduceQuantity(int pos);
};