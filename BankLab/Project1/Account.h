#pragma once
#include "Customer.h"
#include <vector>

class Account
{

private:
	int _accountNumber;
	int _balanceInPennies = 0;
	Customer _accountOwner;
	std::vector<std::string> _log;

public:
	Account(Customer customer, int accountNumber);
	~Account();

	void Deposit(int numberOfPennies);
	void Withdraw(int numberOfPennies);
	int getBalance();
	int getAccountNumber();
	std::string getCustomerName();

	std::string showLog();
};

