#include "loans.h"
using namespace std;

//returns loancount
int Loans::getcount() {return loancount;}
//increases loancount
void Loans::inccount() {loancount++;}
//decreases loancount
void Loans::deccount() {loancount--;}

//adds a loan to the collection from the pramiters of a patrons id and book collection
//gets the book id from user and presets the duedate
void Loans::addLoan(int id2,Books inventory)
{
    Book *temp;
    int id, id3;
    time_t date = time(0);
    date += 864000;
    id = nextAvaiableID;
    
    cout << "Enter Book ID: ";
    cin >> id3;
    cin.ignore();
    
    temp = inventory.findBook(id3);
    temp->setCurrentStatus(1);
    
    loanlist.push_back(new Loan(id,id2,id3,date,0,0));
    inccount();

}

//delets loan from parameters of the loan ID, book collection, and patron collection
//sets the book status to avaliable and patrons number of books out ot one less
void Loans::delLoan(int id,Books invintory,Patrons pats)
{
    int ord;
    Book *btemp;
    Patron *ptemp;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        if ((*it)->getLoanID() == id)
        {
            loanlist.erase(it);
            btemp = invintory.findBook((*it)->getBookID());
            ptemp = pats.findPatronByID((*it)->getPatronID());
            btemp->setCurrentStatus(0);
            ptemp->setNumBooksOut(ptemp->getNumBooksOut()-1);
        }
    }
    deccount();
}
//this checks all of the loans and sees which loan is overdue and stes status
//and patron balance accordingly
void Loans::checkOverDue(Patrons pats)
{
    time_t currentTime = time(0);
    Loan *temp;
    Patron* temp2;
    int due;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        if(temp->getDueDate() <= currentTime)
        {
            temp->setCurrentStatus(1);
            temp2 = pats.findPatronByID(temp->getPatronID());
            due = currentTime - (temp->getDueDate());
            temp2->setBalance(.25*due);
        }
    }
}

//this rechceks books but first it checks how many times the book has been reched and 
//then sets a new duedate accordingly
void Loans::rechceck(int id)
{
    time_t currenttime = time(0);
    Loan *temp;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        if(temp->getLoanID() == id)
        {
            if(temp->getTimesRecheked()==1)
            {
                cout<<"Already rechecked out once"<<endl;
                cout<<endl;
                break;
            }
            else
            {
                temp->setTimesRecheked(1);
                temp->setDueDate(currenttime+864000);
                cout<<"Thank you for reachecking out the book"<<endl;
                cout<<endl;
            }
        }
    }
}

//this finds a loan by inputing a loan id, then returns the loan pointer
Loan* Loans::findLonaByID(int loID)
{
    Loan *temp;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        if (temp->getLoanID() == loID)
                return temp;
    }
                                                                
  return NULL;
}

//this finds a loan by inputtin patrons id and book id , then return the loan as pointer
Loan* Loans::findLoan(int patID, int bookID)
{
    Loan *temp;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        if (temp->getPatronID() == patID)
            if (temp->getBookID() == bookID)
                return temp;
    }
                                                                
  return NULL;
}

//this finds a loan by inputting patrons id, outputs all loans that the patron has and has the user pick
//then return the user picked loan as pointer
Loan* Loans::findLoanByPatron(int patID)
{
    Loan *temp;
    int loannumber;
    int user_pick;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    { 
        temp = *it;
        if (temp->getPatronID() == patID)
        {
            cout<<loannumber<<"."<<endl;
            temp->print();
        }
        loannumber++;
    }
    cout<<endl;
    cout<<"Which loan is the correct loan?"<<endl;
    cout<<"If non are correct enter -1"<<endl;
    cin>>user_pick;
    if(user_pick == -1)
        return NULL;
    return loanlist[user_pick];
}

//this finds a loan by inputting book id, outputs all loans that is realated to the book and has the user pick
//then return the user picked loan as pointer
Loan* Loans::findLoanByBook(int bID)
{
    Loan *temp;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        if (temp->getBookID() == bID)
                return temp;
    }
                                                                
  return NULL;
}

//this deletes all the loans in the collection then clears the vector
void Loans::cleanup()
{
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        delete *it;
    }
    loanlist.clear();
}

//this prints all of the loans in the vector is a formated style
void Loans::prtlist()
{
    Loan *temp;
    cout<<endl;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        time_t date = temp->getDueDate();
        tm *ltm = localtime(&date);
        cout << "Loan id: " << temp->getLoanID() << " Patron id: " << temp->getPatronID() << " Book id: " << temp->getBookID() << endl;
        cout<< "Due date: " << 1+ltm->tm_mon << "/" << ltm->tm_mday << "/" << (1900 + ltm->tm_year) <<endl;
        if(temp->getCurrentStatus() == 1)
            cout<<"OVERDUE"<<endl;
        else
            cout<<"Not overdue"<<endl;
        cout<<endl;
    }
    cout<<endl;
}

//this stores all the loans data in a file called loans.dat for saving everything
void Loans::storeLoans()
{
    ofstream fout;
    fout.open("Loans.dat");
    fout << loancount << endl;
    
    Loan *temp;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        temp = *it;
        fout << temp->getLoanID() << " " << temp->getPatronID() << " " << temp->getBookID() << " " << temp->getDueDate() << " " << temp->getTimesRecheked()<< " " << temp->getCurrentStatus()<<endl;
    }
    fout.close();
}

//This loads everything in loans.dat from storage 
void Loans::loadLoans()
{
    ifstream fin;
    int id, itmid, cusid, rechecked, status; 
    long int date;
  
    fin.open("Loans.dat");
    fin >> loancount; fin.ignore();
    
    for (int i = 0; i < loancount; i++)
    {
        fin >> id;
        fin >> cusid;
        fin >> itmid; 
        fin >> date;
        fin >> rechecked;
        fin >> status;
        loanlist.push_back(new Loan(id,cusid,itmid,date,rechecked,status));
        if(id >= nextAvaiableID)
            nextAvaiableID++;
    }

    fin.close();
    
}
