//Simran Bhamra and Emily Bielski
#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
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


void invMenu()
{
	int choice = 0;

	while (choice != 5)
	{
		cout << "Serendipity Booksellers\n";
		cout << "   Inventory Database\n\n";

		cout << "1. Look Up a Book\n";
		cout << "2. Add a Book\n";
		cout << "3. Edit a Book's Record\n";
		cout << "4. Delete a Book\n";
		cout << "5. Return to the Main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;


		//validate input
		while (choice < 1 || choice > 5)
		{
			cout << "\nPlease enter a number in the range 1 - 5\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			lookUpBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			cout << "\nYou selected item 5";
			break;
		}

		cout << endl;
	}//end while choice !=5
}

void lookUpBook()
{
	bool found = false;
	int index = 0;
	string searchTitle;

	cin.ignore();

	cout << "Enter the title of the book to search for: ";
	getline(cin, searchTitle);

	while (!found && index < SIZE)
	{
		if (bookTitle[index] == searchTitle)
			found = true;
		else
			index++;
	}

	if (found)
	{
		cout << "This should print the book info now." << endl;
		//bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);
	}
		
	else
		cout << "The book you searched for is not in the inventory" << endl;

}

void addBook()
{
	bool found = false;
	int index = 0;

	while (!found && index < SIZE)
	{
		if (bookTitle[index] == "")
			found = true;
		else
			index++;
	}

	if (found)
	{
		cin.ignore();
		cout << "Enter Title: ";
		getline(cin, bookTitle[index]);

		cout << "Enter ISBN :";
		getline(cin, isbn[index]);

		cout << "Enter Author :";
		getline(cin, author[index]);

		cout << "Enter Publisher :";
		getline(cin, publisher[index]);

		cout << "Enter Date Added to Inventory :";
		getline(cin, dateAdded[index]);

		cout << "Enter Quantity Added :";
		cin >> qtyOnHand[index];

		cout << "Enter Wholesale Price :";
		cin >> wholesale[index];

		cout << "Enter Retail Price:";
		cin >> retail[index];

		cout << "\n\nRecord was entered.";
	}
	else
		cout << "No more books may be added\n";

}

void editBook()
{
	bool found = false;
	int index = 0;
	int choice = 0;
	string searchTitle;

	cin.ignore();

	cout << "Enter thetitle of the book to edit: ";
	getline(cin, searchTitle);

	while (!found && index < SIZE)
	{
		if (bookTitle[index] == searchTitle)
			found = true;
		else
			index++;
	}

	if (found)
	{
		cout << "This should print the book info now." << endl;
		//bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);
		

		do
		{
			cout << "\nYou may edit any of the following: " << endl;
			cout << "1. ISBN\n";
			cout << "2. Title\n";
			cout << "3. Author\n";
			cout << "4. Publisher\n";
			cout << "5. Date book was added to inventory\n";
			cout << "6. Quantity on hand\n";
			cout << "7. Wholesale cost\n";
			cout << "8. Retail Price\n";
			cout << "9. Exit\n\n";
			cin >> choice;

			while (choice < 1 || choice > 9)
			{
				cout << "\nPlease enter a number in the range between 1 and 9." << endl;
				cout << "Enter your choice :";
				cin >> choice;
			}

			switch (choice)
			{
			case 1:
				cout << "\nCurrent ISBN: ";
				cout << isbn[index] << endl;
				cin.ignore();
				cout << "Enter new ISBN: ";
				cin >> isbn[index];
				break;
			case 2:
				cout << "\nCurrent Title: ";
				cout << bookTitle[index] << endl;
				cin.ignore();
				cout << "Enter new Title: ";
				getline(cin, bookTitle[index]);
				break;
			case 3:
				cout << "\nCurrent Author: ";
				cout << author[index] << endl;
				cin.ignore();
				cout << "Enter new Author: ";
				getline(cin, author[index]);
				break;
			case 4:
				cout << "\nCurrent Publisher: ";
				cout << publisher[index] << endl;
				cin.ignore();
				cout << "Enter new Publisher: ";
				getline(cin, publisher[index]);
				break;
			case 5:
				cout << "\nCurrent Date Added: ";
				cout << dateAdded[index] << endl;
				cin.ignore();
				cout << "Enter new Date: ";
				getline(cin, dateAdded[index]);
				break;
			case 6:
				cout << "\nCurrent Quantity on Hand: ";
				cout << qtyOnHand[index] << endl;
				cin.ignore();
				cout << "Enter new Quantity On Hand: ";
				cin >> qtyOnHand[index];
				break;
			case 7:
				cout << "\nCurrent Wholesale Cost: ";
				cout << wholesale[index] << endl;
				cin.ignore();
				cout << "Enter new Wholesale Cost: ";
				cin >> wholesale[index];
				break;
			case 8:
				cout << "\nCurrent Retail Price: ";
				cout << retail[index] << endl;
				cin.ignore();
				cout << "Enter new Retail Price: ";
				cin >> retail[index];
				break;
			}
		} while (choice != 9);
	}
	else
		cout << "The book you searched for is not in the inventory\n\n";
}

void deleteBook()
{
	bool found = false;
	int index = 0;
	string searchTitle;
	char confirm;

	cin.ignore();

	cout << "Enter the title of the book to delete: ";
	getline(cin, searchTitle);

	while (!found && index < SIZE)
	{
		if (bookTitle[index] == searchTitle)
			found = true;
		else
			index++;
	}

	if (found)
	{
		cout << "This should print the book info now." << endl;
		//bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);
		

		cout << "Are you sure you want to delete this book from the inventory?";
		cin >> confirm;

		if (confirm == 'Y' || confirm == 'y')
		{
			bookTitle[index] = "";
			isbn[index] = "";
			author[index] = "";
			publisher[index] = "";
			dateAdded[index] = "";
			qtyOnHand[index] = 0;
			wholesale[index] = 0;
			retail[index] = 0;
		}
	}
	else
		cout << "The book you searched for is not in the inventory\n";
}