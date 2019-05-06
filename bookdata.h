//Simran Bhamra and Emily Bielski
#ifndef BOOKDATA_H
#define BOOKDATA_H
#include<string>

using namespace std; 

class bookdata 
{
private:
	string bookTitle;
	string isbn; 
	string author;
	string publisher;
	string dataAdded;
	int qtyOnHand;
	double wholesale;
	double retail;
	bool empty; 
public: 

	//constructor 
	bookdata() 
	{
		bookTitle = "";
		isbn = "";
		author = "";
		publisher = "";
		dataAdded = "";
		qtyOnHand = 0;
		wholesale = 0.0;
		retail = 0.0;
		empty = true; 
	}

	//setters and getters
	//setters 
	void setBookTitle(string bt) 
	{
		bookTitle = bt;
	}

	void setIsbn(int isbnNum) 
	{
		isbn = isbnNum; 
	}
	void setAuthor(string a) 
	{
		author = a;
	}
	void setPublisher(string p) 
	{
		publisher = p;
	}
	void setDataAdded(string da) 
	{
		dataAdded = da; 
	}
	void setQtyOnHand(int qty) 
	{
		qtyOnHand = qty;
	}
	void setWholeSale(double ws)
	{
		wholesale = ws; 
	}
	void setRetail(double r)
	{ 
		retail = r;
	}

	//empty bool functions
	bool isEmpty() 
	{
		return empty; 
	}

	bool insertBook() 
	{
		empty = false; 
	}
	
	bool removeBook() 
	{
		empty = true; 
	}

	//getters
	string getBookTitle() 
	{
		return bookTitle;
	}

	string getIsbn()
	{
		return isbn;
	}

	string getAuthor() 
	{
		return author; 
	}

	string getPub() 
	{
		return publisher;
	}

	string getDataAdded() 
	{
		return dataAdded; 
	}

	int getQty()
	{
		return qtyOnHand; 
	}
	
	double getWholeSale() 
	{
		return wholesale; 
	}
	
	double getRetail() 
	{
		return retail; 
	}

};
#endif