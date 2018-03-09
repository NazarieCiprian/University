#pragma once
#include "Programmer.h"
#include "SourceFile.h"
#include "Exception.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include "Observer.h"
class Repository:public Observable
{
private:
	vector<Programmer> programmers;
	vector<SourceFile> files;
	string filename;

public:
	
	Repository(const string& file);
	~Repository();
	
	int findFile(const SourceFile& f);
	/*
	Adds a file to the list of files
	Input: f-the file to be added
	Throws an exception if the file already exists
	*/
	void addFile(const SourceFile& f);
	void removeFile(const SourceFile& f);
	/*
	Updates the information of a file
	Input:f - the file we want to update
	Throws an exception if the file does not exist in list
	*/
	void updateFile(const SourceFile& f);

	vector<Programmer> getProgrammers() { return this->programmers; }
	vector<SourceFile> getFiles() { return this->files; }

	void sortFiles();
	void readFiles();
	void readProgrammers();
	void writeFiles();
	void writeProgrammers();
};

void testRepo();