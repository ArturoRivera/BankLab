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



void Bank::CreateAccount(Account newAccount)
{	
	_accounts.push_back(newAccount);
}



std::string Bank::ShowAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	for (auto account : _accounts)
	{
		output += std::to_string(account.getAccountNumber()) + ") " + account.getCustomerName() + " - " + std::to_string(account.getBalance());
	}
	return output;
}



std::string Bank::ListAccounts()
{
	std::string output = "Accounts for " + _name + "\n";

	for (Account account : _accounts)
	{
		output += std::to_string(account.getAccountNumber()) + ") " + account.getCustomerName() + ": " + std::to_string(account.getBalance()) + "\n";
	
	}
	return output;

}



void Bank::Deposit(int accountNumber, int amount)
{
	for (Account &account : _accounts){
		if (account.getAccountNumber() == accountNumber){
			account.Deposit(amount);
			return;
		}
	}
	return;
}



void Bank::Withdraw(int accountNumber, int amount)
{
	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber) 
		{
			account.Withdraw(amount);
			return;
		}
	}
	return;
}



std::string Bank::GetTransactionLog(int accountNumber)
{
	std::string output = "Transaction Log for Account #: " + std::to_string(accountNumber) + ":\n\n";
	for (Account account : _accounts)
	{
		if (account.getAccountNumber() == accountNumber)
		{
			output += account.showLog();
			return output;
		}
	}
	return output;
}
