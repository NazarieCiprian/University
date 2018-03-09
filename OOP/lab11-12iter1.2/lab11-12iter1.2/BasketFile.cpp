#include "BasketFile.h"

BasketFile::BasketFile() :Basket(), filename("")
{
}

void BasketFile::setFilename(const string & filename)
{
	this->filename = filename;
}
