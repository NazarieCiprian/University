#include "Repository.h"

Repository::Repository(const string& file)
{
	this->filename = file;
	this->readFiles();
	this->readProgrammers();
	this->sortFiles();
}

Repository::~Repository()
{
	this->writeFiles();
	this->writeProgrammers();
}

int Repository::findFile(const SourceFile & f)
{
	for (unsigned int i = 0; i < this->files.size(); i++)
		if (files[i].getName() == f.getName())
			return i;
	return -1;
}

void Repository::addFile(const SourceFile & f)
{
	int pos = this->findFile(f);
	if (pos != -1)
		throw Exception("File already exists!");
	this->files.push_back(f);
	this->sortFiles();
	this->notify();
}

void Repository::removeFile(const SourceFile & f)
{
	int pos = this->findFile(f);
	if (pos == -1)
		throw Exception("File not in list!");
	this->files.erase(files.begin() + pos);
	this->sortFiles();
}

void Repository::updateFile(const SourceFile & f)
{
	int pos = this->findFile(f);
	if (pos == -1)
		throw Exception("File not in list!");
	this->files[pos] = f;
	this->sortFiles();
	this->notify();
}

void Repository::sortFiles()
{
	for (unsigned int i = 0; i < this->files.size() - 1; i++)
	{
		for (unsigned int j = i + 1; j < this->files.size(); j++)
		{
			if (files[i].getName() > files[j].getName())
			{
				SourceFile aux;
				aux = files[i];
				files[i] = files[j];
				files[j] = aux;
			}
		}
	}

}

void Repository::readFiles()
{
	ifstream file(this->filename);

	SourceFile f;
	while (file >> f)
		this->files.push_back(f);
	file.close();
}

void Repository::readProgrammers()
{
	ifstream file("programmers.txt");

	Programmer p;
	while (file >> p)
		this->programmers.push_back(p);
	file.close();
}

void Repository::writeFiles()
{
	ofstream file(this->filename);

	for (auto it : this->files)
		file << it;
	file.close();
}

void Repository::writeProgrammers()
{
	ofstream file("programmers.txt");
	
	for (auto it : this->programmers)
		file << it;
}

void testRepo()
{
	Repository repo{ "test1.txt" };
	SourceFile f1{ "game","not_revised","john","-" };
	SourceFile f2{ "game","revised","john","mary" };
	try
	{
		repo.updateFile(f2);
		assert(false);
	}
	catch (Exception& e)
	{
		assert(true);
	}
	repo.addFile(f1);
	try
	{
		repo.updateFile(f2);
		assert(true);
	}
	catch (Exception& e)
	{
		assert(false);
	}
	try
	{
		repo.removeFile(f2);
		assert(true);
	}
	catch (Exception& e)
	{
		assert(false);
	}
	try
	{
		repo.removeFile(f2);
		assert(false);
	}
	catch (Exception& e)
	{
		assert(true);
	}
}
