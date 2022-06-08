/*------------------------------------------------------------------------
* @file: history.cpp
* @authors: Elijah Shaw, Braxton Goss
* @brief: implementation for the history (type of transaction) class 
-------------------------------------------------------------------------*/

#include "transaction.h"
#include "history.h"
#include "library.h"

/*-------------------------------------------------------------------------
* Constructor 
*
* Initializes patronID to be 0
* @pre: Nothing
* @post: new History object exists
* @param: None
*/
History::History() : Transaction() {
    
}

/*-------------------------------------------------------------------------
* Destructor
*
* Nothing to delete
* @pre: History object exists
* @post: Memory associated with that History object is released
* @param: None
*/
History::~History() {
    
}

/*-------------------------------------------------------------------------
* create()
*
* Returns a pointer to a newly created & empty History object
* This method is used inside of TransactionFactory to create new objects 
* without using Switch-Case or If-else statements. 
* @pre: Nothing 
* @post: empty History object is returned to the caller 
* @param: None
* @return: returns the new History object
*/
History* History::create() const {
    return new History();
}

/*-------------------------------------------------------------------------
* execute(Library&, ifstream&)
*
* Executes the History command: Displays a Patron's recorded transaction 
* history.
* @post: Transaction data for a Patron is printed in a formatted manner.
* @param: ifstream& - the ifstream providing data for commands (1 per line),
* in this case marked by an H, followed by a 4 digit number for patronID. 
* @return: returns a bool marking whether or not to save this History
* to patron history. Always returns false, as there is no information to 
* save or print in the future related to this History object.
*/
bool History::execute(Library& currLibrary, ifstream& infile) {
    int patronID;
    infile >> patronID; 
    Patron* potentialPatron = nullptr;
    currLibrary.retrievePatron(patronID, potentialPatron);
    if (potentialPatron){
        potentialPatron->displayHistory();
    }else{
        cout << endl;
        cout << "Cannot print history for invalid Patron ID: " << patronID << endl;
    }
    return false;
} 



/*-------------------------------------------------------------------------
* display() 
*
* Prints to the std::cout the History action, which is always nothing.
* This function is never called on this object b/c it's never saved as part 
* of a patron's history. Whenever a history object is created, execute() 
* handles printing the associated patron's entire history of transactions 
* with the library. 
* @pre: execute() has already been called by this object.
* @post: Nothing gets printed for history 
* @param: None
*/
void History::display() const {
    // nothing to display, not saved as part of a patron's transaction list
}