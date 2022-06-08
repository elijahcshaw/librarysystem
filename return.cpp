/**
* @file return.cpp
* @author Braxton Goss, Elijah Shaw
* @brief implementation of the return class (type of transaction)
*/
#include "transaction.h"
#include "return.h"
#include "library.h"


/*-------------------------------------------------------------------------
* Constructor 
*
* Initializes patronID to be 0 and item to be nullptr.
* @pre: Nothing
* @post: new Return object exists
* @param: None
*/
Return::Return() : Transaction() {
    patronID = 0;
}

/*-------------------------------------------------------------------------
* Destructor
*
* Nulls out the member item. Transactions aren't responsible for deleting
* Item objects they are associated with.
* @pre: Return object exists
* @post: Memory associated with that Return object is released (except
* for item)
* @param: None
*/
Return::~Return() {
    
}

/*-------------------------------------------------------------------------
* create()
*
* Returns a pointer to a newly created & empty Return object
* This method is used inside of TransactionFactory to create new objects 
* without using Switch-Case or If-else statements. 
* @pre: Nothing 
* @post: empty Return object is returned to the caller 
* @param: None
* @return: returns the new Return object
*/
Return* Return::create() const {
    return new Return();
} 

/*-------------------------------------------------------------------------
* execute(Library&, ifstream&)
*
* Executes the Return command: validates the patronID, validates the item 
* that is requested to be returned, assigns the Return to the patron's 
* history, and adds 1 quantity of that item to the library quantity. 
* @pre: Library and a command file exist
* @post: An item in zero or one library trees is modified, associated with
* this Return, and associated with the Patron given by command data.
* @param: Library& - the library the command should change
* @param: ifstream& - the ifstream providing data for commands (1 per line),
* in this case marked by an R as the first char of the line. The rest of the
* line should provide patronID, item type and item data
* @return: returns a bool marking whether or not to save this Return
* to patron history. Returns true if the Return should be saved, and
* false otherwise (determined by validity of data for Return objects).
*/
bool Return::execute(Library& currLibrary, ifstream& infile) {
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
                if (potentialPatron->hasItem(realItem)) {
                    item = realItem;
                    realItem->modifyStock(1);
                    // add to patrons list of books
                    potentialPatron->removeItem(realItem);
                    potentialPatron->addToHistory(this);
                    delete potentialItem;
                    return true;
                }else{
                    cout << endl;
                    cout << "ERROR: ";
                    potentialPatron->display();
                    cout << " tried to return " << potentialItem->getTitle();
                    cout << " -- doesn't have it checked out." << endl;
                }
            } else {
                cout << endl;
                cout << "ERROR: ";
                potentialPatron->display();
                cout << " tried to return " << potentialItem->getTitle();
                cout << " -- can't find in library." << endl;
            }
        } else {
            // if book type given is invalid, 
            cout << endl;
            cout << "ERROR: Cannot return for invalid item type: " << itemType << endl;
            string oldLine = "";
            getline(infile, oldLine);
        }
        delete potentialItem;
    }else{
        // if patron doesn't exist, output error message
        cout << endl;
        cout << "Cannot return for invalid Patron ID: " << patronID << endl;
        string oldLine = "";
        getline(infile, oldLine);
    }
    
    return false;
} 

/*-------------------------------------------------------------------------
* display()
*
* Prints to the std::cout the Return action and what item is associated 
* with the Return. 
* @pre: execute() has already been called by this object.
* @post: user is notified of Return data 
* @param: None
*/
void Return::display() const {
    cout << "Returned " << item->getTitle() << endl;
}