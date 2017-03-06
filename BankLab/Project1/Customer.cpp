#include "Customer.h"

using namespace std;


Customer::Customer(std::string firstName, std::string lastName) : _firstName(firstName), _lastName(lastName)
{
}

Customer::~Customer()
{
}

std::string Customer::getFullName()
{
	return _lastName + ", " + _firstName;
}
