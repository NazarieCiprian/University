#include "Repository.h"

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

int Repository::findCoat(const TrenchCoat & t)
{
	for (unsigned int i = 0; i < coats.size(); i++)
		if (coats[i].getSize() == t.getSize() && coats[i].getColour() == t.getColour())
			return i;
	return -1;

}

void Repository::addCoat(const TrenchCoat & t)
{
	int pos = this->findCoat(t);
	if (pos != -1)
		throw RepositoryException("Cant find the coat!");
	this->coats.push_back(t);
	this->writeToFile();
}

void Repository::updateCoat(const TrenchCoat & t)
{
	int pos = this->findCoat(t);
	if (pos == -1)
		throw RepositoryException("Cant find the coat!");
	this->coats[pos] = t;
	this->writeToFile();
}

void Repository::removeCoat(const TrenchCoat & t)
{
	int pos = this->findCoat(t);
	if (pos == -1)
		throw RepositoryException("Cant find the coat!");
	this->coats.erase(this->coats.begin()+pos);
	this->writeToFile();
}

vector<TrenchCoat> Repository::getAll()
{
	
	return this->coats;
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("File not open!");
	TrenchCoat t;
	while (file >> t)
	{
		this->coats.push_back(t);
	}
	file.close();

}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("Cant open file for writting!");
	for (auto c : coats)
	{
		file << c;
	}
	file.close();
}

