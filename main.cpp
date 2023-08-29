#include <stdio.h>
#include <iostream>
#include <string>
#include <string>
#include <ctime>

//#include "books.h"
//#include "patrons.h"
#include "loans.h"

using namespace std;

Patrons pats;
Books inventory;
Loans exchanges;


int main(int argc, const char * argv[]) {
    //sets the seconds sence Januart 1,1970 to current time
    time_t currentTime = time(0);
     
    //initalizing and declairing menu variables
    int choice = -1;
    int subChoice = -1;
    int id = 0;

    //loads infromation from files for the collections
    cout<<"LOading data"<<endl;
    inventory.loadBooks();
    exchanges.loadLoans();
    pats.loadPatrons();
    //checks if any loans are overdue and changes the balance of patrons accordingly
    exchanges.checkOverDue(pats); 
    //loops the menu and choices untill user says otherwise
    while (choice != 0)
    {
        if(choice != -2)
        {
            //menu with list of choices for the user
            cout<<"What do you want to do?"<<endl;
            cout<<"1 - Add/Modify/Delete Book"<<endl;
            cout<<"2 - Add/Modify/Delete Patron"<<endl;
            cout<<"3 - Add/Modify/Delete Loan"<<endl;
            cout<<"4 - Find Book"<<endl;
            cout<<"5 - Find Patron"<<endl;
            cout<<"6 - Find Loan"<<endl;
            cout<<"7 - print Patrons"<<endl;
            cout<<"8 - print Books"<<endl;
            cout<<"9 - print Loans"<<endl;
            cout<<"0 - Quit"<<endl;
            cout<<"Enter your selection: ";
            scanf ("%d%*c", &choice);
        }
        
        switch(choice)
        {  
            //this case is to end the program and skip looking through all of the other cases 
            case 0: break;
            //case 1 is for adding, modifying, and deleting a chosen book
            case 1:
            {
                //this is the submenu for choice 1
                cout<<endl;
                cout<<"1 - Add Book"<<endl;
                cout<<"2 - Modify Book"<<endl;
                cout<<"3 - Find Book ID/ISBN"<<endl;
                cout<<"4 - Delete Book"<<endl;
                cout<<"Enter your selection: ";
                cin>>subChoice;

                switch(subChoice)    
                {
                    //this is the case for adding a book to the collection
                    case 1: 
                    {
                        inventory.addBook();  
                        choice = -1;
                        subChoice = -1;
                        break;
                    }
                    //this is the case for modifting a chosen book
                    case 2: 
                    {
                        //this is another submenu of the submenu stated above
                        Book* temp;
                        int sub2Choice;
                        cout<<"What do you want to modify?"<<endl;
                        cout<<"1 - Price"<<endl;
                        cout<<"2 - Current Status"<<endl;
                        cout<<"Enter your selection: ";
                        cin>>sub2Choice;
                        //this askes the user for the book they want to modify the price of
                        //then modifys the price based off of the user input
                        if(sub2Choice == 1)
                        {
                            
                            int book_ID;
                            cout<<"What book do you want to change the price?"<<endl;
                            cout<<"Enter book ID";
                            cin>>book_ID;
                            temp = inventory.findBook(book_ID);
                            float newPrice;
                            cout<<"What is the new price?"<<endl;
                            cin >> newPrice;
                            temp->setPrice(newPrice);
                        }
                        //this ask the user for the book they want to modift the status of 
                        //then modifys the status based off of a menu with 3 choices and changes accordingly
                        else if(sub2Choice == 2)
                        {
                            int iD;
                            int newStatus;
                            cout<<"Enter book ID" <<endl;
                            cin>>iD;
                            temp = inventory.findBook(iD); 
                            cout<<"What is the new status?"<<endl;
                            cout<<"0 - avaiable"<<endl;
                            cout<<"1 - checked out"<<endl;
                            cout<<"2 - being Repaired"<<endl;
                            cout<<"3 - lost"<<endl;
                            cin>>newStatus;
                            temp->setCurrentStatus(newStatus);

                        }
                        //this is if they enter an incorrect choice and it sends them back to the menu
                        else
                        {
                            choice = -1;
                            sub2Choice = -1;
                        }
                        break;
                    }
                    //this is for finding the book ID or book ISBN
                    //the case asks the user for the book title and author name then prints out the ID and ISBN
                    case 3: 
                    {
                        string the_title;
                        string the_name;
                        Book *foundBook;
                        cin.ignore();
                        cout<<"What is the Book Title?"<<endl;
                        getline(cin,the_title);
                        cout<<"What is the Author Name?"<<endl;
                        getline(cin,the_name);
                        foundBook = inventory.findID(the_title, the_name);
                        cout<<endl;
                        cout<<"Book ID: "<<foundBook->getID()<<endl;
                        cout<<"Book ISBN: "<<foundBook->getISBN()<<endl;
                        cout<<endl;
                        break;
                    }
                    //This case delets a book based off of the user input
                    //all other books keep ther original id
                    case 4: 
                    {
                        int id;
                        cout<<"Please enter the ID of the Book: ";
                        scanf("%i%*c", &id);
                        inventory.delBook(id);
                        break;
                    }
                }
                break;
            }
            //case 2 is for adding, modifying, and deleting a chosen patron
            case 2:
            {
                //this is the submenu for choice 2
                cout<<endl;
                cout<<"1 - Add Patron"<<endl;
                cout<<"2 - Modify Patron"<<endl;
                cout<<"3 - Find Patron ID"<<endl;
                cout<<"4 - Delete Patron"<<endl;
                cout<<"Enter your selection: ";
                cin>>subChoice;
                switch(subChoice)
                {
                    //this case adds a patron to the collection of patron 
                    //the patron is added with the input of there name
                    case 1: 
                    {
                        string pat_name;
                        cin.ignore();
                        cout<<"What is the patrons name?"<<endl;
                        getline(cin,pat_name);
                        pats.addPatron(pat_name);
                        break;
                    }
                    //this case is if the user mis typed a patrons name and would like to correct it
                    case 2: 
                    {
                        char sub2Choice;
                        cout<<"Whould you like to modify there name? y/n"<<endl;
                        cin>>sub2Choice;
                        //this is if they would like to correct a patrons name
                        if(sub2Choice == 'y')
                        {
                            Patron* temp;
                            int name_ID;
                            cout<<"Whos name would you like to change?"<<endl;
                            cout<<"Enter ID: ";
                            cin>>name_ID;
                            temp = pats.findPatronByID(name_ID);
                            string newName;
                            cin.ignore();
                            cout<<"What is the new name?"<<endl;
                            getline(cin, newName);
                            temp->setName(newName);
                        }
                        //this is to take them back to the original menu if they input no
                        else if(sub2Choice == 'n')
                        {
                            choice = -1;
                            sub2Choice = -1;
                        }
                        //this takes them back to the submenu if they inputed a wrong input
                        else
                        {
                            choice = -2;
                            break;
                        }
                        break;
                    }
                    //this case is to find a patrons id based off of thier name
                    case 3: 
                    {
                        string name;
                        Patron *foundPatron;
                        cin.ignore();
                        cout<<"Enter Patrons name: "<<endl;
                        getline(cin, name);
                        cout<<name<<endl;
                        foundPatron = pats.findPatronByName(name);
                        if(foundPatron == NULL)
                        {
                        cout<<"Nothing found"<<endl;
                        break;
                        }
                        cout<<"ID: "<<foundPatron->getID()<<endl;
                        break;
                    }
                    //this case delets a patron while not modifying any other patrons id
                    case 4: 
                    {
                        int id;
                        cout<<"Please enter the ID of the Patron: ";
                        cin>>id;
                        pats.deletPatron(id);
                        break;
                    }
                }
                break;
            }
            //case 3 is for adding, modifying, and deleting a chosen lOan or rechecking a book
            case 3:
            {
                //this is the submenu of choice 3
                cout<<endl;
                cout<<"1 - Add Loan"<<endl;
                cout<<"2 - Find Loan ID"<<endl;
                cout<<"3 - Recheck Book"<<endl;
                cout<<"3 - Delete Loan"<<endl;
                cout<<"Enter your selection: ";
                cin>>subChoice;
                switch(subChoice)
                {
                    //this case is if the user wants to check out a book
                    case 1: 
                    {
                        Patron* temp;
                        int id2;
                        int checker;
                        cout << "Enter Patron ID: ";
                        cin>>id2;
                        temp = pats.findPatronByID(id2);
                        //this section checks if the patron has to many books checked out or an unpaid balance
                        checker = temp->checkIfTheyCan();
                        if(checker == 0)
                        {
                            exchanges.addLoan(id2,inventory);
                        }
                        else if(checker == 1)
                        {
                            cout<<"You Have to many books checked out"<<endl;
                        }
                        else if(checker == 2)
                        {
                            char choice1;
                            cout<<"You have an unpaided balance"<<endl;
                            cout<<"Whould you like to pay it? y/n"<<endl;
                            cin>>choice1;
                            if(choice1 == 'y')
                            {
                                cout<<"Enter card"<<endl;
                                cout<<"Transaction complete"<<endl;
                                temp->setBalance(0);
                                cout<<"Redirecting to new loan page"<<endl;
                                exchanges.addLoan(id2,inventory);
                            }
                            else
                            {
                                break;
                            }
                        }
                        break;
                    }
                    //This section is for the user to find the loan id by either
                    //both patron and book ID or only the patrons ID
                    case 2: 
                    {
                        //this is a submenu for finding the loan id
                        char sub2Choice;
                        cout<<"Do you know Patron's ID and the Book's ID?"<<endl;
                        cout<<"Both - y"<<endl;
                        cout<<"only Patron's ID - o"<<endl;
                        cout<<"Neither - n"<<endl;
                        cin>>sub2Choice;
                        //this case is to find the loan id by both ID's
                        if(sub2Choice == 'y')
                        {
                            Loan *temp;
                            int pats_ID;
                            int books_ID;
                            cout<<"Enter Patron's ID: ";
                            cin>>pats_ID;
                            cout<<"Enter Book's ID: ";
                            cin>>books_ID;
                            temp = exchanges.findLoan(pats_ID,books_ID);
                            cout<<"Loan ID: "<<temp->getLoanID()<<endl;
                            cout<<endl;
                        }
                        //this case finds the loan id by outputing all the loans for the patron
                        //then theu choose which loan they needed the ID and its outputted
                        else if(sub2Choice == 'o')
                        {
                            int pats_ID;
                            Loan *temp;
                            cout<<"Enter Patrons ID: "<<endl;
                            cin>>pats_ID;
                            temp = exchanges.findLoanByPatron(pats_ID);
                            cout<<"Loan ID: "<<temp->getLoanID()<<endl;
                            cout<<endl;
                        }
                        //this is for if they enter n or anyother letter
                        else
                        {
                            choice = -1;
                            subChoice = -1;
                        }
                        break;
                    }
                    //this case is for rechecking a book
                    case 3:
                    {
                        int iD;
                        cout<<"Enter Loan ID"<<endl;
                        cin>>iD;
                        exchanges.rechceck(iD);
                        break;
                    }
                    //this case is for returning a book
                    case 4: 
                    {
                        int id;
                        cout<<"Please enter the ID of the Loan: ";
                        cin>>id;
                        exchanges.delLoan(id,inventory,pats);
                        break;
                    }
                }
                break;
            }
            //this case is to find a book by either book title. author name, or both
            case 4: 
            {
                //varanles
                char userChoice;
                Book *temp;
                string btitle, bauthor;
                //this is a submenu for choice 4
                cout<<endl;
                cout<<"Do you know the Book title and author name?"<<endl;
                cout<<"Both - y"<<endl;
                cout<<"Book title - t"<<endl;
                cout<<"Book author - a"<<endl;
                cin>>userChoice;cin.ignore();
                //this is for choice y and finds the book by book title and author name
                if(userChoice == 'y')
                {
                    cout<<endl;
                    cout<<"What is the Book's title?"<<endl;
                    getline(cin,btitle);
                    cout<<"What is the Authors name?"<<endl;
                    getline(cin,bauthor);
                    temp = inventory.findID(btitle,bauthor);
                    //this returns to user that nothing is found for ther input
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this is for choice t that uses only the book title to find book
                //this also outputs all the books with the name the user inputted
                else if(userChoice == 't')
                {
                    cout<<endl;
                    cout<<"what is the book title?"<<endl;
                    getline(cin,btitle);
                    inventory.findByTitle(btitle);
                    cout<<endl;
                }
                //this is for choice a that uses only the author name to find book
                //this also outputs all the books from the author inputted by the user
                else if(userChoice == 'a')
                {
                    cout<<endl;
                    cout<<"what is the Author's name?"<<endl;
                    getline(cin,bauthor);
                    inventory.findByAuther(bauthor);
                    cout<<endl;
                }
                //this tells the user they are returning to the menu after a incorrect input
                else
                {
                    cout<<"Incorrect input returning to menu."<<endl;
                }
                break;
            }
            //this case is for finding a patron
            case 5: 
            {
                //varables
                char userChoice;
                Patron *temp;
                string name;
                int iD;
                //this askes the user if theu know their id
                cout<<endl;
                cout<<"Do you know the ID? y/n"<<endl;
                cin>>userChoice;cin.ignore();
                //this section is for if they input that they know their id
                if(userChoice == 'y')
                {
                    //asks the user for the patrons id
                    cout<<endl;
                    cout<<"What is the Patron's ID?"<<endl;
                    cin>>iD;
                    temp = pats.findPatronByID(iD);
                    //this outputs nothing found if the patron cannot be found form inputted id
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this section is for the user not knowing the patron id and finds the patron by name
                //this also outputs all patrons with the inputted name
                else if(userChoice == 'n')
                {
                    //asks the user for the patrons name
                    cout<<endl;
                    cout<<"What is the Patron's name?"<<endl;
                    getline(cin,name);
                    temp = pats.findPatronByName(name);
                    //this outputs nothing found if the patron cannot be found form inputted name
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this outputs a error message and returns the user to the menu
                else
                {
                    cout<<"Incorrect input returning to menu."<<endl;
                }
                break;
            }
            //this case is to find a loan by loanID, bookID and patron ID, bookID, or patronID
            case 6: 
            {
                //varables
                char userChoice;
                Loan *temp;
                int lID, pID, bID;
                //submenu for choice 6 asking the user for what informtaion the user knows
                cout<<endl;
                cout<<"Do you know the Loan ID or Book ID and/or Patron ID?"<<endl;
                cout<<"LoanID - l"<<endl;
                cout<<"Both Book and Patron- y"<<endl;
                cout<<"BookID - b"<<endl;
                cout<<"PatronID - p"<<endl;
                cin>>userChoice;cin.ignore();
                //this is for choice L which asks the user for the loan id and outputs the loan
                if(userChoice == 'l')
                {
                    cout<<endl;
                    cout<<"What is the Loan ID?"<<endl;
                    cin>>lID;
                    temp = exchanges.findLonaByID(lID);
                    //this outputs nothing found if the loan cannot be found form inputted id
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this is for choice y which asks the user for the book id and patron id then outputs the loan
                else if(userChoice == 'y')
                {
                    cout<<endl;
                    cout<<"what's the Book ID?"<<endl;
                    cin>>bID;
                    cout<<"What's the Patron's ID?"<<endl;
                    cin>>pID;
                    temp = exchanges.findLoan(pID,bID);
                    //this outputs nothing found if the loan cannot be found form inputted
                    //book and patron ID
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this is for choice b which asks the user for the book id and outputs the loan with that book id
                else if(userChoice == 'b')
                {
                    cout<<endl;
                    cout<<"What is the Book ID?"<<endl;
                    cin>>bID;
                    temp = exchanges.findLoanByBook(bID);
                    //this outputs nothing found if the loan cannot be found form inputted book ID
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this is for choice p which asks the user for the patron id and outputs the loans that the patron has
                else if(userChoice == 'p')
                {
                    cout<<endl;
                    cout<<"What is the Patron's ID?"<<endl;
                    cin>>pID;
                    temp = exchanges.findLoanByPatron(pID);
                    //this outputs nothing found if the loan cannot be found form inputted patron ID
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this outputs a error message and returns the user to the menu
                else
                {
                    cout<<"Incorrect input returning to menu."<<endl;
                }
                break;
            }
            //this case prints all of the patrons 
            case 7: pats.prtlist();break;
            //this case prints all of the books 
            case 8: inventory.prtlist();break;
            //this case prints all of the loans 
            case 9: exchanges.prtlist();break;
            //this case gets back to a submenu
            case -2: break;
        }
    }
    //this stroes all of the books, loans, and patrons in their respected files
    cout<<"Storeing data"<<endl;
    inventory.storeBooks();
    exchanges.storeLoans();
    pats.storePatrons();
    //this erases all the data for every collection after stroing the data
    inventory.cleanup();
    exchanges.cleanup();
    pats.cleanup();
    return 0;
}
