//Simran Bhamra and Emily Bielski

#include "bookinfo.h"
#include "bookdata.h"
#include <iostream>
#include<iomanip>

using namespace std;

void bookInfo(string bookTitle, string isbn,string author,string publisher,string dataAdded, int qtyOnHand, double wholesale, double retail)
{
	//presents info for the user 
	cout << setw(39) << "Serendipity Booksellers" << endl;
	cout << setw(37) << "Book information" << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << left << setw(30) << "IBSN: " << isbn <<endl;
	cout << left << setw(30) << "Title: " <<  bookTitle<<endl;
	cout << left << setw(30) << "Author: " << author<< endl;
	cout << left << setw(30) << "Publisher: " << publisher << endl;
	cout << left << setw(30) << "Date Added: " << dataAdded<<endl;
	cout << left << setw(30) << "Quantity Added: " << qtyOnHand <<endl;
	cout << left << setw(30) << "Wholesales Cost: " <<  wholesale <<endl;
	cout << left << setw(30) << "Retail Price: " <<  retail << endl;
}

