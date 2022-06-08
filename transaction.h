/*---------------------------------------------------------------------------
* @file: transaction.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the Transaction class.
---------------------------------------------------------------------------*/
// Transaction Class: Intended to be base class for specific types of 
// Transactions stored inside a Patron.
//---------------------------------------------------------------------------
// Features: 
//  -- N/A (all methods virtual, Transaction itself doesn't have any 
//     implementation beyond constructor and destructor)
//
// Assumptions/implementation:
// -- Any derived class will implement pure virtual functions
//---------------------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Library;
#include "item.h"
#include <fstream>

class Transaction {
    public:

        /*-------------------------------------------------------------------------
        * Constructor
        *
        * Nothing to initialize
        * @pre: Nothing
        * @post: New Transaction object exists
        * @param: None 
        */
        Transaction(); 

        /*-------------------------------------------------------------------------
        * Destructor
        *
        * Nothing to delete
        * @pre: Transaction object exists
        * @post: Memory associated with the Transaction object is released
        * @param: None 
        */
        virtual ~Transaction();


        /*-------------------------------------------------------------------------
        * create()
        *
        * Pure virtual function to be implemented by derived classes. Used to get
        * new Transaction objects from the HashTable
        * @pre: Transaction object exists
        * @post: a new Transaction object is created. Caller object is unchanged.
        * @param: None 
        * @return: returns the Transaction object created
        */    
        virtual Transaction* create() const = 0;

        /*-------------------------------------------------------------------------
        * execute(Library&, ifstream&)
        *
        * Pure virtual function to be implemented by derived classes. This method
        * is designed to change a Library object based on command data in a file.
        * How it changes the Library (or if it does at all) is up to the derived
        * classes.
        * @pre: Library and a command file exist.
        * @post: The next command specified in the file is executed, but this will
        * cause no change in the library if any part of the command is invalid.
        * @param: Library& - the library the command should change
        * @param: ifstream& - the ifstream providing data for commands (1 per line)
        * @return: returns a bool marking whether or not to save this transaction
        * to the library (and patron) history. Returns true if it should be saved 
        * and returns false if it should not (determined by derived classes)
        */
        virtual bool execute(Library&, ifstream&) = 0; 

        /*-------------------------------------------------------------------------
        * display() 
        *
        * Virtual display function for each transaction type that is derived from 
        * this class. The display for each transaction type will be different.
        * @pre: execute() has already been called, transaction exists in library
        * @post: transaction is displayed to std::cout 
        * @param: None 
        */
        virtual void display() const = 0;
    
  private:
    // no member variables
}; //TRANSACTION_H
#endif