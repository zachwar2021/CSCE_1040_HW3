#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <typeinfo>
#include "book.h"
using namespace std;

class Books{
    private:
        int bookcount;
        typedef vector<Book*> custtype;
        custtype booklist;
        vector<Book>::iterator it;
        int nextAvaiableID = 2;
    public:
        Books() {bookcount = 0;}
        int getcount();
        void inccount();
        void deccount();
        void addBook();
        void delBook(int);
        Book* findID(string,string);
        Book* findBook(int);
        void findByTitle(string);
        void findByAuther(string);
        void cleanup();
        void prtlist();
        void storeBooks();
        void loadBooks();
};
