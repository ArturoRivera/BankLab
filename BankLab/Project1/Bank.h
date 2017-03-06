#pragma once
#include <string>
#include <vector>
#include "Account.h"


class Bank
{

private:
	std::string _name;
	std::vector<Account> _accounts;
public:
	Bank(std::string name);
	~Bank();

	std::string getName();
};

