/*---------------------------------------------------------------------------
* @file: patron.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the patron class
---------------------------------------------------------------------------*/
// Patron Class: 
// --------------------------------------------------------------------------
// Features: 
//  -- Stores vector of Transactions (its own transaction history)
//  -- Stores vector of currently checked out Items 
//     (used to verify valid returns)
//  -- Patron sets it's own patron ID from the int and names 
//     from the patron ifstream&. 
//  -- Can display current patron info (both data and transaction 
//     history)
//  -- Can tell whether or not an item is currently checked out via hasItem()
//  -- can retrieve patron's ID using getID() 
//  -- can add any Item to patron's history using addToHistory()
// --------------------------------------------------------------------------
// Assumptions/implementation:
//  -- Deleting Patron doesn't delete any of the Items in its checked out 
//     items list
//  -- Return and Checkout are the two Transaction classes added to history
//  -- Library::buildPatronsFromFile reads the int first, 
//     so the int is passed and set inside setData while the rest of the 
//     patron data is parsed via infile&. 
//  -- STL Vectors are used to simplify memory management and never 
//     allocate a static size of transactions. After years of collecting 
//     transaction history on 1 single person, there could be any range of 
//     executed transactions in their history. 
//---------------------------------------------------------------------------
#ifndef PATRON_H
#define PATRON_H

#include <vector>
#include "transaction.h"
#include "item.h"
#include <fstream>

using namespace std;
class Patron {
    public:

        /*-------------------------------------------------------------------------
        * Constructor
        * 
        * Initializes members to default values (blank strings for firstName 
        * & lastName, 0 for ID)
        * @pre: Nothing
        * @post: Patron object exists
        * @param: None
        */
        Patron();

        /*-------------------------------------------------------------------------
        * Destructor
        * 
        * Deallocates memory of all transactions associated with this patron 
        * @pre: Patron object exists
        * @post: Memory associated with the Patron object is released
        * @param: None
        */
        ~Patron();

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
        void setData(int ID, ifstream&);
        
        /*-------------------------------------------------------------------------
        * getID()
        * 
        * Finds the ID of the Patron object
        * @pre: Patron object exists
        * @post: Patron is unchanged
        * @param: None
        * @return: int - the ID associated with this Patron object
        */
        int getID() const;

        /*-------------------------------------------------------------------------
        * addToHistory(Transaction*)
        * 
        * Adds a Transaction into the Patron's list of transactions
        * @pre: Patron object exists
        * @post: Patron's transaction list has increased in size by one.
        * @param: Transaction* - pointer to a Transaction object to be added on to
        * Patron's transaction list
        */
        void addToHistory(Transaction*);

        /*-------------------------------------------------------------------------
        * addItem(Item*)
        * 
        * Adds an Item into the Patron's list of checkedOutItems
        * @pre: Patron object exists
        * @post: Patron's Item list has increased in size by one.
        * @param: Item* - pointer to an Item object to be added on to Patron's list
        * of checked out Items.
        */
        void addItem(Item*);

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
        void removeItem(Item*);

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
        bool hasItem(Item*) const;

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
        void displayHistory() const;

        /*-------------------------------------------------------------------------
        * display() 
        *
        * Display the basic information about the patron - ID, firstname, lastname
        * @pre: Patron has all data members initialized 
        * @post: data is sent to std::cout
        * @param: None
        */
        void display() const;

    private:
        int ID;             // patron's ID number
        string firstName;   // patron's first name
        string lastName;    // patron's last name
        vector<Transaction*> transactions;  // A list of all the transactions
        vector<Item*> checkedOutItems; // A list of currently checked out items
}; //PATRON_H

#endif