#pragma once
#include <string>
class FileException 
{
private:
	std::string message;
	
public:
	FileException(std::string msg);
	std::string getMessage()const;

};

class RepositoryException
{
private:
	std::string message;
public:
	RepositoryException(std::string msg);
	std::string getMessage()const;
};