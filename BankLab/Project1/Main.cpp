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
		cout << "What would you like to do?" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: AddAccountMenu(); break;
		case 2: TransactMenu(); break;
		case 3: DisplayAccountsMenu();
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

	//Get the amount
	system("cls");
	cout << "How many pennies?";
	int pennies;
	cin >> pennies;

	switch (transactionType)
	{
	case 1: bank.Deposit(chosenAccount, pennies); break;
	case 2: bank.Withdraw(chosenAccount, pennies); break;
	default: break;
	}


}

void DisplayAccountsMenu()
{
	system("cls");
	cout << bank.ListAccounts();
	system("pause");
}