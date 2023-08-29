#include <string>
#include <vector>
using namespace std;

class Book 
{    
    private:
        string author;
        string title;
        int itemID;
        string isbn;
        float price;
        int currentStatus; //0-avaiable, 1-checked out, 2-being Repaired, 3-lost

    public:
        Book (string, string, int, float, string, int);
        string getAuthor();
        string getTitle();
        int getID();
        string getISBN();
        float getPrice();
        int getCurrentStatus();
        void setPrice(float);
        void setCurrentStatus(int);
        void print();
};