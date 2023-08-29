#include <iostream>
#include "patron.h"
using namespace std;

//constructors
Patron::Patron() { }
Patron::Patron(string n) {name = n;}
Patron::Patron(int id, string n, int b, int num) {patronID = id; name = n; balance = b; booksOut = num;}

//gets for all the variables
int Patron::getID() {return patronID;}
string Patron::getName() {return name;}
int Patron::getBalance() {return balance;}
int Patron::getNumBooksOut() {return booksOut;}

//this function is to check if the patron can check out a book
//checks the number of books out and their balance
int Patron::checkIfTheyCan()
{
    cout<<booksOut<<endl;
    if(booksOut >= 5)
    {
        return 1;
    }
    if(balance > 0)
    {
        return 2;
    }
    return 0;
}

//sets for all the variables
void Patron::setID(int id) {patronID = id;}
void Patron::setName(string n) {name = n;}
void Patron::setBalance(int b) {balance = b;}
void Patron::setNumBooksOut(int num) {booksOut = num;}

//prints out all the patron information
void Patron::print() {
    cout << "Patron name: " << name << endl;
    cout << "Patron id: " << patronID << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Number of books out : " << booksOut << endl;
    cout << endl;
}
