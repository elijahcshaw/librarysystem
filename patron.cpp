/*---------------------------------------------------------------------------
* @file: display.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: implementation for the Patron class 
//------------------------------------------------------------------------*/
#include "patron.h"
#include <iostream>

using namespace std;

/*-------------------------------------------------------------------------
* Constructor
* 
* Initializes members to default values (blank strings for firstName 
* & lastName, 0 for ID)
* @pre: Nothing
* @post: Patron object exists
* @param: None
*/
Patron::Patron(){
    // set ID to zero
    ID = 0;
    // set firstName empty
    firstName = "";
    // set lastName empty
    lastName = "";
}       

/*-------------------------------------------------------------------------
* Destructor
* 
* Deallocates memory of all transactions associated with this patron 
* @pre: Patron object exists
* @post: Memory associated with the Patron object is released
* @param: None
*/
Patron::~Patron(){
    for (int i = 0; i < transactions.size(); i++){
        delete transactions[i];
    }
}

/*-------------------------------------------------------------------------
* setData()
* 
* Sets the members of Patron according to an ifstream for a file of data
* @pre: Patron object exists
* @post: Patron's members are changed according to the file data passed
* @param: int ID - what this Patron's ID will be set to
* @param: ifstream& - ifstream for a file that contains patron data (1 per
* line) that follows the pattern "ID lastName firstName"
*/
void Patron::setData(int passedID, ifstream& infile){
    ID = passedID;
    infile >> firstName;
    infile >> lastName;
}

/*-------------------------------------------------------------------------
* getID()
* 
* Finds the ID of the Patron object
* @pre: Patron object exists
* @post: Patron is unchanged
* @param: None
* @return: int - the ID associated with this Patron object
*/
int Patron::getID() const{
    return ID;
}

/*-------------------------------------------------------------------------
* addToHistory(Transaction*)
* 
* Adds a Transaction into the Patron's list of transactions
* @pre: Patron object exists
* @post: Patron's transaction list has increased in size by one.
* @param: Transaction* - pointer to a Transaction object to be added on to
* Patron's transaction list
*/
void Patron::addToHistory(Transaction* transaction){
    transactions.push_back(transaction);
}

/*-------------------------------------------------------------------------
* addItem(Item*)
* 
* Adds an Item into the Patron's list of checkedOutItems
* @pre: Patron object exists
* @post: Patron's Item list has increased in size by one.
* @param: Item* - pointer to an Item object to be added on to Patron's list
* of checked out Items.
*/
void Patron::addItem(Item* item) {
    checkedOutItems.push_back(item);
}

/*-------------------------------------------------------------------------
* removeItem(Item*)
* 
* When an item is returned that is currently checked out, the item is 
* removed from the patron's current list of items. 
* @pre: Item may or may not exist in the current list
* @post: If Item was currently checked out by patron, it is removed 
* @param: Item* can be any derived class of Item (to allow for additional
* media types to be added to the library in the future. 
*/
void Patron::removeItem(Item* item) {
    for (int i = 0; i < checkedOutItems.size(); i++){
        if (checkedOutItems[i] == item){
            checkedOutItems[i] = nullptr;
            return;
        }
    }
}

/*-------------------------------------------------------------------------
* hasItem(Item*)
* 
* Tests to see if a user already has the parameter item checked out.
* Used to make sure that all returns are valid and patrons are not able 
* to return books they never checked out first. 
* @pre: Patron object must be instantiated 
* @post: Object is unchanged
* @param: Item* - pointer to Item that Patron will be checked for
* @return: bool - whether or not a Patron has the parameter Item 
*/
bool Patron::hasItem(Item* item) const {
    bool result = false;
    for (int i = 0; i < checkedOutItems.size(); i++){
        if (checkedOutItems[i] == item){
            result = true;
            break;
        }
    }
    return result;
}

/*-------------------------------------------------------------------------
* displayHistory() 
* 
* If a patron has any transactions in the library, displays all of them 
* in the order they were added. If the patron has no transactions with the
* library, the user is also notified of that fact. 
* @pre: Patron has a vector (empty or not) of Transactions 
* @post: entire history is displayed or no history message is displayed 
* @param: None
*/
void Patron::displayHistory() const {
    cout << endl;
    if (transactions.size() == 0) {
        cout << "Patron has no transaction history to display." << endl;
        return;
    }
    cout << "History for ";
    this->display();
    for (int i = 0; i < transactions.size(); i++) {
        transactions[i]->display();
    }
}

/*--------------------------------------------------------------------------
* display() 
*
* Display the basic information about the patron - ID, firstname, lastname
* @pre: Patron has all data members initialized 
* @post: data is sent to std::cout
* @param: None
*/
void Patron::display() const {
    cout << "Patron: " << ID << " " << firstName << " " << lastName << endl;
}
