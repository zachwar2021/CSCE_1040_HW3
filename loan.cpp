#include <iostream>
#include <string>
#include "loan.h"
using namespace std;

//constructor
Loan::Loan(int id, int id2, int id3, long int date, int t, int s) {loanID = id; patronID = id2; bookID = id3; dueDate = date; timesRecheked = t; currentStatus = s;}

//gets for all the varables
int Loan::getLoanID() {return loanID;}
int Loan::getBookID() {return bookID;}
int Loan::getPatronID() {return patronID;}
int Loan::getTimesRecheked() {return timesRecheked;}
long int Loan::getDueDate() {return dueDate;}
int Loan::getCurrentStatus() {return currentStatus;}

//sets for timesrecheked, duedate, and currecntstatus
void Loan::setTimesRecheked(int times) {timesRecheked = times;}
void Loan::setDueDate(long int date) {dueDate = date;}
void Loan::setCurrentStatus(int status) {currentStatus = status;}

//prints with duedate as a string
void Loan::print() {
    tm *ltm = localtime(&dueDate);
    //prints differently depending on if the book in the lona is overdue or not
    if(currentStatus == 1)
    {
        cout<<"Loan ID: "<<loanID<< " " <<"Book ID: "<<bookID<< " " << " "  <<"currentStatus: Not Overdue"<<endl;
        cout<< "Due date: " << 1+ltm->tm_mon << "/" << ltm->tm_mday << "/" << (1900 + ltm->tm_year) <<endl;
    }
    else
    {
        cout<<"Loan ID: "<<loanID<< " " <<"Book ID: "<<bookID<< " " << " "  <<"currentStatus: Overdue"<<endl;
        cout<< "Due date: " << 1+ltm->tm_mon << "/" << ltm->tm_mday << "/" << (1900 + ltm->tm_year) <<endl;
    }
}

