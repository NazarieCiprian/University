#pragma once
#include "Repository.h"
#include "CoatValidator.h"
#include "Basket.h"
#include "ControllerException.h"
#include "BasketFile.h"
class Controller
{
private:
	Repository repo;
	CoatValidator valid;
	BasketFile* bask;
public:
	Controller(const Repository& r,BasketFile *p, const CoatValidator& val):repo(r),bask(p),valid(val){}
	
	void addCoatCont(const TrenchCoat& t);
	void updateCoatCont(const TrenchCoat& t);
	void removeCoatCont(const TrenchCoat& t);

	vector<TrenchCoat> getCoats(){ return this->repo.getAll(); }

	void showBySize(double size);
	void addToBasket(const TrenchCoat& c);
	void emptyBasket();
	TrenchCoat getCurrent(){ return this->bask->getCurrent(); }
	TrenchCoat next() { return this->bask->next(); }
	vector<TrenchCoat> getCart() { return this->bask->getCart(); }
	double getBill() { return this->bask->getBill(); }
	void saveCart(const string& filename);
	void openFile();


};