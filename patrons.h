#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

#include "patron.h"

class Patrons
{
private:
    int patroncount;

    typedef vector<Patron*> custtype;
    custtype patronlist;
    vector<Patron>::iterator it;
    int nextAvaiableID = 100001;
public:
    Patrons() {patroncount = 0; }
    int getcount();

    void inccount();
    void deccount();

    void addPatron(string);
    void deletPatron(int);
    Patron* findPatronByID(int);
    Patron* findPatronByName(string);
    void cleanup();
    void prtlist();
    void loadPatrons();
    void storePatrons();
};
