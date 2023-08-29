#include "patrons.h"

using namespace std;

//returns patroncount
int Patrons::getcount() { return patroncount;}
//increases patroncount
void Patrons::inccount() {patroncount++;}
//decreases patroncount
void Patrons::deccount() { patroncount--;}

//adds a patron to the collection with one name from the user
void Patrons::addPatron(string n)
{

    patronlist.push_back(new Patron(nextAvaiableID,n,0,0));
    inccount();
}

//this delets one patron that the user picks by entering the patron id
void Patrons::deletPatron(int id)
{
    for (auto it = patronlist.begin(); it !=patronlist.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            patronlist.erase(it);
            break;
        }
    }
    deccount();
}

//this searchs through each patron and compairs id, then returns a loan by pointer of the mactched id
Patron* Patrons::findPatronByID(int id)
{
    Patron *temp;
    for(auto it = patronlist.begin(); it != patronlist.end(); ++it)
    {
        if ((*it)->getID() == id) 
            return *it;
        
    }
  
    return NULL;
  
}

//this searchs through each patron and compairs names, then returns a loan by pointer of the mactched name
Patron* Patrons::findPatronByName(string n)
{
    Patron *temp;
    for(auto it = patronlist.begin(); it != patronlist.end(); ++it)
    {
        temp = *it;
        if(temp->getName() == n)
        {
            return temp;
        }
    }
    return NULL;
}

//this delets patron objects then clears the vector
void Patrons::cleanup()
{
    for (auto it = patronlist.begin(); it !=patronlist.end(); ++it)
    {
        delete *it;
    }
    patronlist.clear();
}

//this prints all the patrons in a formatted way
void Patrons::prtlist()
{
    Patron *temp;
    cout << endl;
    for (auto it = patronlist.begin(); it !=patronlist.end(); ++it)
    {
        temp = *it;
        cout << "Customer name: " << temp->getName() << endl;
        cout << "customer id: " << temp->getID() << endl;
        cout << "Balance: $" << temp->getBalance() << endl;
        cout << "Number of books out : " << temp->getNumBooksOut() << endl;
        cout << endl;
    }
}

//this stores patrons in a formatted way in patrons.dat for storage
void Patrons::storePatrons()
{
    ofstream fout;
    fout.open("patrons.dat");
    fout << patroncount << endl;
    
    Patron *temp;
    for (auto it = patronlist.begin(); it != patronlist.end(); ++it)
    {
        temp = *it;
        fout << temp->getID() << " "  << temp->getBalance() << " " << temp->getNumBooksOut()<< endl;
        fout << temp->getName()<<endl;
    }
    fout.close();
}

//this loads patrons in a formatted way from patrons.dat for use
void Patrons::loadPatrons()
{
    ifstream fin;
    int id;
    int balance;
    int books;
    string name;
    fin.open("patrons.dat");
    fin >> patroncount;
    
    for ( int i=0; i < patroncount; i++)
    {
        fin >> id; 
        fin>>balance ; 
        fin>> books; fin.ignore();
        getline(fin,name);
        patronlist.push_back(new Patron(id,name,balance,books));
        if(id >= nextAvaiableID)
            nextAvaiableID++;
    }
    fin.close();
    
}
