/**
* @file: main.cpp
* @authors: Braxton Goss & Elijah Shaw
* @brief: driver class for Library and related classes
*/
//---------------------------------------------------------------------------
// Main: Driver for the entire library
// --------------------------------------------------------------------------
// Features:
//   -- Creates library on heap
//   -- Inserts items (in this case books) into the library
//   -- Creates Patrons and associates them with the library
//   -- Executes all commands on the library
//
// Assumptions:
//   -- all three data files (books, patrons, commands) are stored 
//   in the same directory as main.cpp 
//   -- library.h is stored in the same directory as main.cpp
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream> 
using namespace std;
#include "library.h"

int main() {
    
    // load data files
    ifstream libraryData("data4books.txt");
    ifstream patronData("data4patrons.txt");
    ifstream transactionData("data4commands.txt");

    // instantiate the library object
    Library* ourLibrary = new Library();
    
    // call build methods on library object 
    ourLibrary->buildBooksFromFile(libraryData);
    ourLibrary->buildPatronsFromFile(patronData); 

    // execute all the commands from command file
    ourLibrary->acceptTransactions(transactionData);        

    // library is a ptr, need to deallocate memory
    delete ourLibrary;
}