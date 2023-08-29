#include <string>
#include <vector>
using namespace std;

class Patron
{
    private:
        int patronID;
        string name;
        int balance;
        int booksOut;
    
    public:
        Patron();
        Patron(string);
        Patron(int ,string, int, int);
        int getID();
        string getName();
        int getBalance();
        int getNumBooksOut();
        int checkIfTheyCan();
        void setID(int);
        void setName(string);
        void setBalance(int);
        void setNumBooksOut(int);
        void print();
};
