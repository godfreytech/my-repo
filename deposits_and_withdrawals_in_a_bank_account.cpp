// deposits_and_withdrwawls_in_a_bank_account.cpp : Defines the entry point for the console application.
//

/* PROGRAM TO HAVE DEPOSITS AND WITHDRAWALS IN AN ACCOUNT AS WELL AS OPENING A NEW ACCOUNT*/

#include<iostream>
using namespace std;

//constant for maximum number of accounts - 50
#define maximum_accounts 50

class accounts
{
	long number;				//account number
	double credit;				//account credit
public:
	//prototypes
	void input_details();		//to input account details
	void show_details();		//to show account details
	long get_number();			//to return account number
	double get_credit();		//to return account credit
	void deposit(double);		//to deposit to an account
	void withdraw(double);		//to withdraw
};

void accounts::input_details()
{
	cout << "\nInput the new account number "; cin >> number;
	cout << "\nInput account opening credit "; cin >> credit;
}

void accounts::show_details()
{
	cout << "\nAccount number: " << number << "Credit:" << credit;
}

long accounts::get_number()
{
	return(number);
}

double accounts::get_credit()
{
	return(credit);
}

void accounts::deposit(double a)
{
	credit += a;
}
void accounts::withdraw(double a)
{
	credit -= a;
}

int main()
{

	accounts account[maximum_accounts];
	int count = 0; // counter for accounts
	int number, c;
	double amount;
	char choice = '1';
	//repeating operations
	while (choice == '1' || choice == '2' || choice == '3' || choice == '4')
	{
		//show menu
		cout << "\nInput 1 to record a new account";
		cout << "\n2 to deposit";
		cout << "\n3 to withdraw";
		cout << "\n4 to display an account's details";
		cout << "\nor other value to exit"; cin >> choice;

		//select operation to do
		switch (choice)
		{
			case '1': //opening new account -----------
			account[count].input_details();
			count++;
			cout << "\nAccount added.\n";
			break;

			case '2': //depositing some amount -----------
			cout << "\nInput the account number ";
			cin >> number;
			cout << "\nInput the amount to deposit ";
			cin >> amount;

			//search for account number
			c = 0;
			while (account[c].get_number() != number && c < count)
			c++;

			//if number not found, show message
			if (c == count)
				cout << "\nAccount not found";
			else // else deposit
				account[c].deposit(amount);
			cout << "nTransaction complete.\n"; 
			break;

			case '3': //withdrawing some amount -----------
			cout << "\nInput the account number ";
			cin >> number;
			cout << "\nInput the amount to withdraw ";
			cin >> amount;

			//search for account number
			c = 0;
			while (account[c].get_number() != number && c < count)
			c++;

			//if number not found, show message
			if (c == count)
			cout << "\nAccount not found";
			else // else withdraw if credit is enough
			if (account[c].get_credit() >= amount)
			account[c].withdraw(amount);
			else // else give message
			cout << "\nSorry. You don't have enough credit";
			cout << "nTransaction complete.\n";
			break;

			case '4': //displaying account -----------
			cout << "\nInput the account number ";
			cin >> number;
				

			//search for account number
			c = 0;
			while (account[c].get_number() != number && c < count)
			c++;

			//if number not found, show message
			if (c == count)
			cout << "\nAccount not found";
			else // else deposit
			account[c].show_details();
			cout << "\n";
			break;
			system("PAUSE");
		}
	}
}
