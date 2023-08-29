#include <iostream>
#include "book.h"
using namespace std;

//book constructor
Book::Book (string n, string t, int id, float p, string is, int status)  
{
    author = n; 
    title = t; 
    itemID = id; 
    price = p; 
    isbn = is; 
    currentStatus = status;
}

//get functions for book varables 
string Book::getAuthor() {return author;}
string Book::getTitle() {return title;}
int Book::getID()  {return itemID;}
string Book::getISBN() {return isbn;}
float Book::getPrice() {return price;}
int Book::getCurrentStatus() {return currentStatus;}

//set functions for price and currentstatus
void Book::setPrice(float p) {price = p;}
void Book::setCurrentStatus(int c) {currentStatus = c;}

//print function for book
void Book::print() {
    //has 4 if statments for each version of current status
    if(currentStatus == 0)
    {
        cout << "Book Name: " << title << endl;
        cout << "Book Author: " << author << endl;
        cout << "ID: " << itemID << " price: $" <<  price << endl;
        cout << "Avaliable" << endl;
        cout << "ISBN" << isbn << endl;
    }
    else if(currentStatus == 1)
    {
        cout << "Book Name: " << title << endl;
        cout << "Book Author: " << author << endl;
        cout << "ID: " << itemID << " price: $" <<  price << endl;
        cout << "Checked Out" << endl;
        cout << "ISBN" << isbn << endl;
    }
    else if(currentStatus == 2)
    {
        cout << "Book Name: " << title << endl;
        cout << "Book Author: " << author << endl;
        cout << "ID: " << itemID << " price: $" <<  price << endl;
        cout << "Being Repaired" << endl;
        cout << "ISBN" << isbn << endl;
    }
    else if(currentStatus == 3)
    {
        cout << "Book Name: " << title << endl;
        cout << "Book Author: " << author << endl;
        cout << "ID: " << itemID << " price: $" <<  price << endl;
        cout << "Lost" << endl;
        cout << "ISBN" << isbn << endl;
    }
    cout<<endl;
}