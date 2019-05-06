//Simran Bhamra and Emily Bielski
#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 20;
extern string bookTitle[SIZE];
extern string isbn[SIZE];
extern string author[SIZE];
extern string publisher[SIZE];
extern string dateAdded[SIZE];
extern int qtyOnHand[SIZE];
extern double wholesale[SIZE];
extern double retail[SIZE];

void cashier()
{
	const double SALES_TAX = 0.06; //6% sales tax
	string isbnNumber[SIZE];
	string thisTitle[SIZE];
	int quantityBooks[SIZE];
	double unitPrice[SIZE];
	double subTotal[SIZE];
	string transDate;
	double orderSalesTax = 0;
	double runningTotal = 0;
	double grandTotal = 0;
	int validQty;
	char choice = 'Y';
	int counter = 0;
	string message;

	//process another transaction
	while (choice == 'Y' || choice == 'y')
	{
		cout << "Serendipity Booksellers\n";
		cout << "  Cashier Module\n\n";

		cout << "Enter Date: ";
		getline(cin, transDate);

		cout << "Enter ISBN: ";
		getline(cin, isbnNumber[counter]);

		for (int index = 0; index < SIZE; index++)
		{
			if (isbnNumber[counter] == isbn[index])
			{
				cout << "Title: " << bookTitle[index] << endl;
				cout << fixed << showpoint << setprecision(2) << "Price: " << retail[index] << endl;

				unitPrice[counter] = retail[index];
				thisTitle[counter] = bookTitle[index];
				validQty = qtyOnHand[index];

				if (validQty == 0) //we're out of stock
				{
					cout << "The book is out of stock!\n\n";
					return;
				}

				cout << "Enter Quantity of Book: ";
				cin >> quantityBooks[counter];

				while (quantityBooks[counter] < 1 || quantityBooks[counter] > validQty)
				{
					if (quantityBooks[counter] < 1)
						cout << "\nPlease enter a valid quantity.\n\n";
					else
						cout << "\nSorry, insufficient quantity in inventory\n\n";

					cout << "Enter Quantity of Book: ";
					cin >> quantityBooks[counter];
				}

				qtyOnHand[index] -= quantityBooks[counter];
				counter++;
				message = "\nAdd another title to this order? ";
				choice = anotherTransaction(message);
				cout << endl;
				break;
			}
			else if (index == SIZE - 1)
			{
				cout << "\nISBN number was not found.\n\n";
				message = "Re-enter ISBN number?\n";
				choice = anotherTransaction(message);
			}
		}//end for loop

		cout << endl;
	} //end while loop

	if (counter > 0)
	{
		cout << "Date: " << transDate << " \n\n";

		cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
		cout << "____________________________________________________________________________________";
		cout << "\n\n\n";

		for (int i = 0; i < counter; i++)
		{
			subTotal[i] = (quantityBooks[i] * unitPrice[i]);
			orderSalesTax += (subTotal[i] * SALES_TAX);
			runningTotal += subTotal[i];
			grandTotal = (orderSalesTax + runningTotal);

			//inline information
			cout << quantityBooks[i] << "\t"; //display quantity
			cout << left << setw(14) << isbn << "\t"; //display ISBN
			cout << left << setw(26) << thisTitle[i] << "\t$ "; //displays title
			cout << fixed << showpoint << right << setprecision(2); //set up number formatting
			cout << setw(6) << unitPrice[i] << "\t$ "; //display price
			cout << setw(6) << subTotal[i] << "\n\n\n"; //display subtotal in line			
		} //end for loop

		//calculated totals
		cout << "\t\tSubtotal\t\t\t\t\t\t$ ";
		cout << setw(6) << runningTotal << "\n";
		cout << "\t\tTax\t\t\t\t\t\t\t$ ";
		cout << setw(6) << orderSalesTax << "\n";
		cout << "\t\tTotal\t\t\t\t\t\t\t$ ";
		cout << setw(6) << grandTotal << "\n\n";

		cout << "\n\nThank you for shopping at Serendipity!\n";
		message = "Process another transaction (Y/N) ";
		choice = anotherTransaction(message);
	}//end if counter > 0

	cout << endl;
}

char anotherTransaction(string message)
{
	char choice;
	cout << message;
	cout << "Y = Yes, N = Np\n";
	cout << "Enter your choice: ";
	cin >> choice;
	cin.ignore();

	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		cout << "\nPlease enter Y for yes or N for no\n\n";
		cout << message << endl;
		cin >> choice;
		cin.ignore();
	}

	return choice;
}