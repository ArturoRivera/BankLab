#include "Customer.h"
#include "Bank.h"
#include "Account.h"
#include <iostream>
using namespace std;

Bank bank = Bank("Wells Fargo");

void DisplayMenu();
void TransactMenu();
void AddAccountMenu();
void DisplayAccountsMenu();
void DisplayTransactionLog();

int main()
{
	DisplayMenu();

	system("pause");
	return 0;
}

void DisplayMenu() 
{
	int choice = 0;

	do
	{
		system("cls");
		cout << "Welcome to " << bank.getName() << endl;
		cout << "1) Create Account" << endl;
		cout << "2) Deposit or Withdraw" << endl;
		cout << "3) Display Accounts" << endl;
		cout << "4) Display Transaction Log" << endl;
		cout << "What would you like to do?" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: AddAccountMenu(); break;
		case 2: TransactMenu(); break;
		case 3: DisplayAccountsMenu();
		case 4: DisplayTransactionLog();
		default: break;
		}
	} while (choice != 10);

}

void AddAccountMenu()
{
	system("cls");
	cout << "Customer First Name: ";
	string firstName;
	cin >> firstName;

	cout << "Customer Last Name: ";
	string lastName;
	cin >> lastName;

	cout << "Account Number: ";
	int accountNumber;
	cin >> accountNumber;

	Customer customer = Customer(firstName, lastName);
	Account newAccount = Account(customer, accountNumber);
	bank.CreateAccount(newAccount);
}

void TransactMenu() 
{
	//Get account
	system("cls");
	cout << "Which Account?" << endl;
	cout << bank.ListAccounts() << endl;

	int chosenAccount;
	cin >> chosenAccount;

	//Get transaction type
	system("cls");
	cout << "1) Deposit" << endl;
	cout << "2) Withdraw" << endl;


	int transactionType;
	cin >> transactionType;

	

	switch (transactionType)
	{
	case 1: system("cls");
		cout << "How many pennies?";
		int pennies;
		cin >> pennies;
		bank.Deposit(chosenAccount, pennies); break;

	case 2: system("cls");
		cout << "How many pennies?";
		cin >> pennies;
		bank.Withdraw(chosenAccount, pennies); break;

	default: break;
	
	}


}

void DisplayAccountsMenu()
{
	system("cls");
	cout << bank.ListAccounts();
	system("pause");
}

void DisplayTransactionLog()
{
	system("cls");
	cout << "Which account do you want to display a transaction log for?" << endl;
	cout << bank.ListAccounts();
	int choice;
	cin >> choice;

	system("cls");
	cout << bank.GetTransactionLog(choice) << endl;
	system("pause");

}