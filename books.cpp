#include "books.h"
using namespace std;

//returns bookcount
int Books::getcount() {return bookcount;}
//increases bookcount
void Books::inccount() {bookcount++;}
//decreases bookcount
void Books::deccount() {bookcount--;}

//adds a book to the collection by asking the user for all required information
void Books::addBook()
{
    int status, isb, iD; 
    float pr;
    string d1, d2,d3;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin,d1);

    cout << "Enter Author name: ";
    getline(cin,d2);
    iD=nextAvaiableID;

    cout << "Enter price: ";
    cin  >> pr;
    cin.ignore();
    cout << "Enter ISBN: ";
    getline(cin,d3);
    
    cout << "Enter current status:" << endl;
    cout << "0-avaiable" << endl;
    cout << "1-checked out" << endl;
    cout << "2-being Repaired" << endl;
    cout << "3-lost" <<endl;
    cin>>status;

    booklist.push_back(new Book(d2,d1,iD,pr,d3,status));
    inccount();

}

//delets the book from the collection without messing with other books ID's
void Books::delBook(int id)
{
    ;
    for (auto it = booklist.begin(); it !=booklist.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            booklist.erase(it);
        }
    }
    
    deccount();
}

//finds a book's ID from the paramiters of a title and author name
Book* Books::findID(string t,string n)
{
    Book *temp;
    for (auto it = booklist.begin(); it != booklist.end(); ++it)
    {
        temp = *it;
        if(temp->getTitle() == t && temp->getAuthor() == n)
        {
            return *it;
        }
    }
    return NULL;
}

//finds a book from the book ID
Book* Books::findBook(int iD)
{
    Book *temp ;
    for (auto it = booklist.begin(); it != booklist.end(); ++it)
    {
        temp = *it;
        if (temp->getID() == iD)
        {
            return temp;
        }
    }
    return NULL;
}

//finds and prints all books with the same title as the paramiter t
void Books::findByTitle(string t)
{
    Book *temp;
    int count = 0;
    cout<<endl;
    cout<<"Here are your choice's"<<endl;
    cout<<endl;
    for (auto it = booklist.begin(); it != booklist.end(); ++it)
    {
        temp = *it;
        if (temp->getTitle() == t)
        {
            count++;
            temp->print();
        }
    }
    if(count == 0)
    {
        cout<<"Nothing found"<<endl;
    }
}

//finds and prints all books with the same author as the paramiter a
void Books::findByAuther(string a)
{
    Book *temp;
    int count = 0;
    cout<<endl;
    cout<<"Here are your choice's"<<endl;
    cout<<endl;
    for (auto it = booklist.begin(); it != booklist.end(); ++it)
    {
        temp = *it;
        if (temp->getAuthor() == a)
        {
            count++;
            temp->print();
        }
    }
    if(count == 0)
    {
        cout<<"Nothing found"<<endl;
    }
}

//deletes all of the book's in the collection then clears the collection
void Books::cleanup()
{
    for (auto it = booklist.begin(); it != booklist.end(); ++it)
    {
        
        delete *it;
    }
    booklist.clear();
}

//prints everybook in the collection
void Books::prtlist()
{
    cout<<endl;
    Book *temp;
    for (auto it = booklist.begin(); it !=booklist.end(); ++it)
    {
        temp=*it;
        if(temp->getCurrentStatus() == 0)
        {
            cout << "Book Name: " << temp->getTitle() << endl;
            cout << "Book Author: " << temp->getAuthor() << endl;
            cout << "ID: " << temp->getID() << " price: $" <<  temp->getPrice() << endl;
            cout << "Avaliable" << endl;
            cout << "ISBN" << temp->getISBN() << endl;
        }
        else if(temp->getCurrentStatus() == 1)
        {
            cout << "Book Name: " << temp->getTitle() << endl;
            cout << "Book Author: " << temp->getAuthor() << endl;
            cout << "ID: " << temp->getID() << " price: $" <<  temp->getPrice() << endl;
            cout << "Checked Out" << endl;
            cout << "ISBN" << temp->getISBN() << endl;
        }
        else if(temp->getCurrentStatus() == 2)
        {
            cout << "Book Name: " << temp->getTitle() << endl;
            cout << "Book Author: " << temp->getAuthor() << endl;
            cout << "ID: " << temp->getID() << " price: $" <<  temp->getPrice() << endl;
            cout << "Being Repaired" << endl;
            cout << "ISBN" << temp->getISBN() << endl;
        }
        else if(temp->getCurrentStatus() == 3)
        {
            cout << "Book Name: " << temp->getTitle() << endl;
            cout << "Book Author: " << temp->getAuthor() << endl;
            cout << "ID: " << temp->getID() << " price: $" <<  temp->getPrice() << endl;
            cout << "Lost" << endl;
            cout << "ISBN" << temp->getISBN() << endl;
        }
        cout<<endl;
        
    }
}

//stores all the books information in a file called books.dat
void Books::storeBooks()
{
    ofstream fout;
    fout.open("books.dat");
    fout << bookcount << endl;
    
    Book *temp;
    for (auto it = booklist.begin(); it !=booklist.end(); ++it)
    {
        temp=*it;
        fout << temp->getID() << " " <<  temp->getPrice() << " " << temp->getCurrentStatus()<< endl; 
        fout << temp->getISBN() << endl;
        fout << temp->getAuthor() << endl;
        fout << temp->getTitle() << endl;      
    }
    fout.close();
}

//loads all the books from a file called books.dat
void Books::loadBooks()
{
    ifstream fin;
    int id;
    float pr;
    int currentStatus;
    string name,bookName, isBn;
    fin.open("books.dat");
    fin >> bookcount;
    
    for ( int i=0; i < bookcount; i++)
    {
        fin >> id; 
        fin >> pr; 
        fin >> currentStatus;
        fin.ignore();
        getline(fin, isBn);
        getline(fin, name);
        getline(fin, bookName);
        booklist.push_back(new Book(name, bookName, id, pr, isBn, currentStatus));
        if(id >= nextAvaiableID)
            nextAvaiableID++;
    }
    fin.close();
    
}
