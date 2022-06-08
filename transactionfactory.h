/*--------------------------------------------------------------------------
* @file: transactionfactory.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the TransactionFactory class 
---------------------------------------------------------------------------*/
// TransactionFactory Class: Creates new Transaction objects using a 
// simplified hash technique.
//--------------------------------------------------------------------------
// Features: 
//  -- Does not violate the open-closed principle.
//  -- Can create any existing type of Transaction.
//
// Assumptions/implementation:
// -- All Transaction creation is dependent upon hashing and array indicies.
// -- Switch-Cases and if/else statements are never used. 
// -- Transactions can't be created unless explicitly instantiated in 
//    constructor and stored in the factory's array
// -- Transactions stored in the factory array must have a create() method 
//    that returns a new object of that same type.
//---------------------------------------------------------------------------
#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
#include "transaction.h" 
#include "constants.h"


// Current Transactions Implemented: 

class TransactionFactory {
  public:
    /*-------------------------------------------------------------------------
    * Constructor
    *
    * Initialize the array and inputs the keys for different transaction types.
    * @pre: Nothing 
    * @post: TransactionFactory object is created
    * @param: None
    */
    TransactionFactory();

    /*-------------------------------------------------------------------------
    * Destructor
    *
    * Deletes and nulls all entries in the array
    * @pre: TransactionFactory object exists 
    * @post: memory associated with TransactionFactory object is released
    * @param: None
    */
    ~TransactionFactory();

    /*-------------------------------------------------------------------------
    * createTransaction(char)
    *
    * Creates new Transaction objects of different subclasses based on a given 
    * key
    * Determines the type of object using private method hashTransaction(char)
    * @pre: TransactionFactory object exists 
    * @post: a new Transaction object is created
    * @param: char - the key for a type of Transaction within the 
    * TransactionFactory's array
    * @return: returns the new Transaction object
    */
    Transaction* createTransaction(char);

  private:

    // stores objects to create 
    Transaction* transactionFactory[TRANSACTION_TYPES]; 

    /*-------------------------------------------------------------------------
    * hashTransaction
    *
    * Hashes a given character by subtracting 'A'
    * @pre: TransactionFactory object exists 
    * @post: An integer is returned
    * @param: char - the key to be hashed against to find right kind of object
    * @return: int - the index of the right Transaction type inside 
    * transactionFactory[]
    */
    int hashTransaction(char);
}; //TRANSACTIONFACTORY_H
#endif