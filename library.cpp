/*---------------------------------------------------------------------------
* @file: library.cpp
* @authors: Elijah Shaw, Braxton Goss
* @brief: Implementation for the Library class 
//------------------------------------------------------------------------*/
#include "library.h"
#include <iostream>
#include <fstream>
#include "string"

using namespace std;


/*-------------------------------------------------------------------------
* Constructor
* 
* Builds a library object, initialize all storage containers and factories
* This includes: trees for item storage, itemFactory, transacationFactory,
* and the patron hashTable[]. 
* @pre: None
* @post: Library object gets created 
* @param: None
*/
Library::Library() {
    for (int i = 0; i < MEDIA_TYPES; i++) {
        libraryStorage[i] = nullptr;
    }
    // Stores all CHILDREN books in sorted 
    // order (sorted by: title, then by author)
    libraryStorage[C_HASH_VALUE] = new BinarySearchTree("CHILDREN BOOKS", "AVAIL,TITLE,AUTHOR,YEAR");
    
    // Stores all FICTION books in sorted 
    // order (sorted by: author, then title)
    libraryStorage[F_HASH_VALUE] = new BinarySearchTree("FICTION BOOKS", "AVAIL,TITLE,AUTHOR,YEAR");

    // Stores all PERIODICAL books in sorted 
    // order (sorted by: year, then month)
    libraryStorage[P_HASH_VALUE] = new BinarySearchTree("PERIODICALS", "AVAIL,TITLE,MONTH,YEAR");

    // book factory
    itemFactory = new ItemFactory();

    // patron list 
    patrons = new HashTable();

    // transaction factory
    transactionFactory = new TransactionFactory();

}

/*-------------------------------------------------------------------------
* Destructor
* 
* Deletes and nulls all data members of the Library object
* @pre: Library object exists
* @post: Memory associated with Library object is deallocated
* @param: None
*/     
Library::~Library() {
    for (int i = 0; i < MEDIA_TYPES; i++) {
        if (libraryStorage[i] != nullptr) {
            delete libraryStorage[i];
            libraryStorage[i] = nullptr;
        }
    }
    delete itemFactory;
    delete patrons;
    delete transactionFactory;
}

/*-------------------------------------------------------------------------
* buildBooksFromFile(ifstream&)
* 
* Builds all of the books from the given data file. Each book contains 
* data and can be categorized by the first character on each line 
* @pre: Library object and the file that ifstream& references must exist 
* @post: Media trees in Library object now contain any entries in the given
* book data
* @param: ifstream& - references the file that contains book data
*/        
void Library::buildBooksFromFile(ifstream& infile) {
    char type;
    infile >> type;

    while (!infile.eof()) {
        Item* newItem = itemFactory->createItem(type);
        if (newItem) {
            
            // sets all book formats to hard copy, 
            // would be changed to read from file if given format 
            newItem->setData(infile); 
            libraryStorage[hash(type)]->insert(newItem);
        } else {
            string oldLine = "";
            getline(infile, oldLine);
        }
        infile >> type;
    }
}

/*-------------------------------------------------------------------------
* buildPatronsFromFile(ifstream&)
* 
* Builds the HashTable to store the patrons based on their ID in the file 
* Each patron will be given a unique ID (duplicates are rejected), a 
* first name, and a last name. 
* @pre: Library object and the file that ifstream& references must exist 
* @post: Patron HashTable object gets filled with entries of patrons from
* the given patron file. 
* @param: Ifstream& - references the file that contains patron data 
*/         
void Library::buildPatronsFromFile(ifstream& infile) {
    int ID;
    infile >> ID;

    while (!infile.eof()) {
        Patron* newPatron = new Patron();
        newPatron->setData(ID, infile);
        patrons->insert(ID, newPatron);
        infile >> ID;
    }
}

/*-------------------------------------------------------------------------
* acceptTransactions(ifstream&)
* 
* Executes all the transactions from the given data file. Each transaction 
* contains data and can be categorized by the first character on each line
* @pre: Library object and the file that ifstream& references must exist 
* @post: Patrons in Patron HashTable and Items in the media trees are 
* changed or unchanged. Transactions are recorded for Patrons, when needed.
* @param: infile& - references the file that contains transaction data 
*/ 
void Library::acceptTransactions(ifstream& infile) {
    char type; 
    infile >> type;
    while (!infile.eof()) {
        Transaction* newTransaction = transactionFactory->createTransaction(type);
        bool transactionKept;
        if (newTransaction) {
            transactionKept = newTransaction->execute(*this, infile);
            if (!transactionKept) {
                delete newTransaction;
            }
        }else{
            string oldLine = "";
            getline(infile, oldLine);
        }
        infile >> type;
    }
}

/*-------------------------------------------------------------------------
* display() 
* 
* Displays the entire library (all media types) in an ordered and alligned
* fashion to std::cout.
* @pre: None, library can be empty or not. User is told if library is empty. 
* @post: Library object exists
* @param: None
*/ 
void Library::display() const{
    cout << "----------------------------------------";
    cout << "----------------------------------------";
    bool empty = true;
    for (int i = 0; i < MEDIA_TYPES; i++) {
        if (libraryStorage[i] != nullptr) {
            libraryStorage[i]->display();
            empty = false;
        }
    }
    if (empty){
        cout << "Library is empty, There is nothing to display." << endl;
    }
    cout << "----------------------------------------";
    cout << "----------------------------------------" << endl;
}

// **************************************** // 
// ***** Helper Functions start here ****** // 
// **************************************** // 
/*-------------------------------------------------------------------------
* retrievePatron(int, Patron*&)
* 
* Searches for a Patron object in the Library's HashTable by the patronID.
* If found, the paramater reference now points to that Patron object.
* @pre: Library object exists, Patron* exists
* @post: Library object exists
* @param: int - ID of the Patron being retrieved
* @param: Patron*& - empty pointer reference that can be set to Patron 
* being retrieved.
*/  
void Library::retrievePatron(int patronID, Patron*& potentialPatron) const {
    patrons->retrieve(patronID, potentialPatron);
}

/*-------------------------------------------------------------------------
* createItem(char type)
* 
* Creates an Item of type represented by the parameter character
* @pre: Library object exists
* @post: New Item object exists
* @param: char type - type of Item object to be created
* @return: Item* - returns the new Item object
*/         
Item* Library::createItem(char type) {
    return itemFactory->createItem(type);
}

/*-------------------------------------------------------------------------
* findTree(char type)
* 
* Hashes into a media tree (libraryStorage) by using hash(char) to find a
* tree of Item type. Method is only used once type is validated.
* @pre: Library exists
* @post: Library object is unchanged
* @param: char type - the character associated with the Item type of the 
* tree to be found
* @return: BinarySearchTree* - returns pointer to the tree to be found
*/ 
BinarySearchTree* Library::findTree(char type) const {
    return libraryStorage[hash(type)];
}

/*-------------------------------------------------------------------------
* hash(char type)
* 
* Finds the index for a certain Item tree using hashing on the parameter 
* char
* @pre: Library exists
* @post: Library object is unchanged
* @param: char type - the character associated with the Item type of the 
* tree to be found
* @return: int - index of tree to be found in libraryStorage[]
*/ 
int Library::hash(char type) const {
    return type - 'A';
}