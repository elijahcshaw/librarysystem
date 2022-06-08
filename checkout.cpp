/**
* @file: checkout.cpp
* @authors: Braxton Goss & Elijah Shaw
* @brief: implementation of the transaction type - checkout
*/

#include "transaction.h"
#include "checkout.h"
#include "library.h"

/*-------------------------------------------------------------------------
* Constructor 
*
* Initializes patronID to be 0 and item to be nullptr.
* @pre: Nothing
* @post: new Checkout object exists
* @param: None
*/
Checkout::Checkout() : Transaction() {
    patronID = 0;
}

/*-------------------------------------------------------------------------
* Destructor
*
* Nulls out the member item. Transactions aren't responsible for deleting
* Item objects they are associated with.
* @pre: Checkout object exists
* @post: Memory associated with that Checkout object is released (except
* for item)
* @param: None
*/
Checkout::~Checkout() {}

/*-------------------------------------------------------------------------
* create()
*
* Returns a pointer to a newly created & empty Checkout object
* This method is used inside of TransactionFactory to create new objects 
* without using Switch-Case or If-else statements. 
* @pre: Nothing 
* @post: empty Checkout object is returned to the caller 
* @param: None
* @return: returns the new Checkout object
*/
Checkout* Checkout::create() const {
    return new Checkout();
}

/*-------------------------------------------------------------------------
* execute(Library&, ifstream&)
*
* Executes the checkout command: validates the patronID, validates the item 
* that is requested to be checked out, assigns the checkout to the patron's 
* history, and removes 1 quantity of that item from the library quantity. 
* @pre: Library and a command file exist
* @post: An item in zero or one library trees is modified, associated with
* this Checkout, and associated with the Patron given by command data.
* @param: Library& - the library the command should change
* @param: ifstream& - the ifstream providing data for commands (1 per line),
* in this case marked by a C as the first char of the line. The rest of the
* line should provide patronID, item type and item data
* @return: returns a bool marking whether or not to save this Checkout
* to patron history. Returns true if the Checkout should be saved, and
* false otherwise (determined by validity of data for Checkout objects).
*/
bool Checkout::execute(Library& currLibrary, ifstream& infile) {
    // find the patron if it exists
    infile >> patronID;
    Patron* potentialPatron = nullptr;
    currLibrary.retrievePatron(patronID, potentialPatron);

    // if patron exists in library database
    if (potentialPatron) {
        char itemType;
        infile >> itemType;
        char itemFormat;
        infile >> itemFormat;

        Item* potentialItem = currLibrary.createItem(itemType);

        // if item is valid type
        if (potentialItem) {
            // create item from the data given
            potentialItem->setTransactionData(infile);
            potentialItem->setFormat(itemFormat);
            
            // hash to the correct tree in libraryStorage
            // itemType has already been validated above, no need to check tree type
            BinarySearchTree* section = currLibrary.findTree(itemType);
            
            // find item in library section 
            Item* realItem = nullptr;
            section->retrieve(*potentialItem, realItem);
            
            // if item exists in library
            if (realItem) {
                if (realItem->getStock() > 0) {
                    item = realItem;
                    realItem->modifyStock(-1);
                    // add to patrons list of books
                    potentialPatron->addItem(realItem);
                    potentialPatron->addToHistory(this);
                    delete potentialItem;
                    return true;
                } else {
                    cout << endl;
                    cout << "ERROR: ";
                    potentialPatron->display();
                    cout << " tried to check out " << potentialItem->getTitle();
                    cout << " -- item is out of stock." << endl;
                }
            } else {
                cout << endl;
                cout << "ERROR: ";
                potentialPatron->display();
                cout << " tried to check out " << potentialItem->getTitle();
                cout << " -- can't find in library." << endl;
            }
        } else {
            // if book type given is invalid, 
            cout << endl;
            cout << "ERROR: Cannot checkout for invalid item type: " << itemType << endl;
            string oldLine = "";
            getline(infile, oldLine);
        }
        delete potentialItem;
    }else{
        // if patron doesn't exist, output error message
        cout << endl;
        cout << "ERROR: Cannot checkout for invalid Patron ID: " << patronID << endl;
        string oldLine = "";
        getline(infile, oldLine);
    }
    
    return false;
}

/*-------------------------------------------------------------------------
* display()
*
* Prints to the std::cout the checkout action and what item is associated 
* with the checkout. 
* @pre: execute() has already been called by this object.
* @post: user is notified of checkout data 
* @param: None
*/
void Checkout::display() const {
    cout << "Checked out " << item->getTitle() << endl;
}