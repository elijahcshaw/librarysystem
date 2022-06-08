/*---------------------------------------------------------------------------
* @file: transactionfactory.cpp
* @authors: Braxton Goss & Elijah Shaw
* @brief: implementation of the TransactionFactory class
--------------------------------------------------------------------------*/
#include "transactionfactory.h"
#include "checkout.h"
#include "display.h"
#include "history.h"
#include "return.h"


/*-------------------------------------------------------------------------
* Constructor
*
* Initialize the array and inputs the keys for different transaction types.
* @pre: Nothing 
* @post: TransactionFactory object is created
* @param: None
*/
TransactionFactory::TransactionFactory(){

    // initialize 0->TRANSACTION TYPES to nullptr 
    for (int i = 0; i < TRANSACTION_TYPES; i++){
        transactionFactory[i] = nullptr;
    }

    // Checkout
    // C's ASCII Value = 67
    transactionFactory[C_HASH_VALUE] = new Checkout;

    // Display 
    // D's ASCII Value = 68
    transactionFactory[D_HASH_VALUE] = new Display;

    // History
    // H's ASCII Value = 72
    transactionFactory[H_HASH_VALUE] = new History;

    // Return
    // R's ASCII Value = 82
    /*
    REMOVE HARD CODED NUMBERS, USE BUILT-IN ASCII SUBTRACTION TO CALCULATE 
    */ 
    transactionFactory[R_HASH_VALUE] = new Return;

}

/*-------------------------------------------------------------------------
* Destructor
*
* Deletes and nulls all entries in the array
* @pre: TransactionFactory object exists 
* @post: memory associated with TransactionFactory object is released
* @param: None
*/
TransactionFactory::~TransactionFactory(){

    for (int i = 0; i < TRANSACTION_TYPES; i++){
        if (transactionFactory[i] != nullptr){
            delete transactionFactory[i];
            transactionFactory[i] = nullptr;
        }
    }

}

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
Transaction* TransactionFactory::createTransaction(char type){
    int subscript = hashTransaction(type);
    if (transactionFactory[subscript] == nullptr) {
        cout << endl; 
        cout << "ERROR: " << type << 
        " is not a valid transaction type." << endl;
        return nullptr;
    }else{
        return transactionFactory[subscript]->create();
    }
}


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
int TransactionFactory::hashTransaction(char type){
    return type - 'A';
} 