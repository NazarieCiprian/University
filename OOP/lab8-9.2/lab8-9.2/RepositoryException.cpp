#include "RepositoryException.h"

FileException::FileException(std::string msg)
{
	this->message = msg;
}

std::string FileException::getMessage() const
{
	return this->message;
}

RepositoryException::RepositoryException(std::string msg)
{
	this->message = msg;
}

std::string RepositoryException::getMessage() const
{
	return this->message;
}
