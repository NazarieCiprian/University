#pragma once
#include "TrenchCoat.h"
#include <fstream>
#include "RepositoryException.h"
#include <assert.h>
class Repository
{
private:

	vector<TrenchCoat> coats;
	string filename;

public:
	Repository(const std::string& filename);
	
	int findCoat(const TrenchCoat& t);
	void addCoat(const TrenchCoat& t);
	void updateCoat(const TrenchCoat& t);
	void removeCoat(const TrenchCoat& t);
	vector<TrenchCoat> getAll();
private:
	void readFromFile();
	void writeToFile();
};

