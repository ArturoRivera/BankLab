#include "Account.h"




Account::Account(Customer customer, int accountNumber) : _accountOwner(customer), _accountNumber(accountNumber)
{
}



Account::~Account()
{
}



void Account::Deposit(int numberOfPennies)
{
	_balanceInPennies += numberOfPennies;
	_log.push_back("You added " + std::to_string(numberOfPennies) + " to your account.");
}



void Account::Withdraw(int numberOfPennies)
{
	_balanceInPennies -= numberOfPennies;
	_log.push_back("You withdrew " + std::to_string(numberOfPennies) + " from your account.");
}



int Account::getBalance()
{
	return _balanceInPennies;
}



int Account::getAccountNumber()
{
	return _accountNumber;
}


std::string Account::getCustomerName()
{
	return _accountOwner.getFullName();
}



std::string Account::showLog()
{
	std::string output;
	for (auto log : _log)
	{
		output += log + "\n";
	}
	return output;
}