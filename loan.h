#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Loan
{
private:
    int loanID;
    int bookID;
    int patronID;
    int timesRecheked;
    time_t dueDate;
    int currentStatus;//1-overdue or 0-not
public:
    Loan(int, int, int, long int, int, int);
    int getLoanID();
    int getBookID();
    int getPatronID();
    int getTimesRecheked();
    time_t getDueDate();
    int getCurrentStatus();
    void setTimesRecheked(int);
    void setDueDate(long int);
    void setCurrentStatus(int);
    void print();
