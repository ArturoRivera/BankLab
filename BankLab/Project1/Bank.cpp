#include "Bank.h"




Bank::Bank(std::string name) : _name(name)
{
}

Bank::~Bank()
{
}

std::string Bank::getName()
{
	return _name;
}
