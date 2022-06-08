/*---------------------------------------------------------------------------
* @file: library.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: This class represents a library system and manages all of its 
* common day-to-day operations. 
---------------------------------------------------------------------------*/
// Library Class: As an implemenation of a real-life library, this class 
// handles all of the common operations that would occur to store Items 
// and handle Patron transactions
//---------------------------------------------------------------------------
// Features:
// -- Stores all items in separate sections of the library. 
// -- Reads and creates storage capacity for books (an item type), Patrons,
//    and transactions. These transactions are executed in the order 
//    received and update the library's data each time something is modified. 
// -- entire library can be displayed to the user 
//
// Assumptions/implementation: 
// -- For the library to be fully functional, all .txt files used for building
//    the library and executing transactions must be properly formatted. The data
//    can be invalid or wrong and the library will handle it, but the format
//    of the data must be consistent with how the library functions process
//    it.
// -- Library storage uses binarysearchtrees which are hashed to within the 
//    libraryStorage array. This allows the implementation to avoid using 
//    switch-cases or if/else statements for determining and accessing proper 
//    item storage.
// -- Library uses HashTable to store Patrons for instant lookup by ID.
// -- Library uses factories to create both Items and Transactions.
// -- Library must be dynamically allocated and deleted in order for there to 
//    be no memory leaks with the factories and storage containers. 
//---------------------------------------------------------------------------

#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "binarysearchtree.h"
#include "itemfactory.h"
#include "item.h"
#include "hashtable.h"
#include "transactionfactory.h"
#include "patron.h"
#include "constants.h"

using namespace std;


class Library {
    public:
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
        Library();

        /*-------------------------------------------------------------------------
        * Destructor
        * 
        * Deletes and nulls all data members of the Library object
        * @pre: Library object exists
        * @post: Memory associated with Library object is deallocated
        * @param: None
        */         
        ~Library(); 
        
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
        void buildBooksFromFile(ifstream&); 

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
        void buildPatronsFromFile(ifstream&); 
        
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
        void acceptTransactions(ifstream&);

        /*-------------------------------------------------------------------------
        * display() 
        * 
        * Displays the entire library (all media types) in an ordered and alligned
        * fashion to std::cout.
        * @pre: None, library can be empty or not. User is told if library is empty. 
        * @post: Library object exists
        * @param: None
        */         
        void display() const;

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
        void retrievePatron(int, Patron*&) const;
        
        /*-------------------------------------------------------------------------
        * createItem(char type)
        * 
        * Creates an Item of type represented by the parameter character
        * @pre: Library object exists
        * @post: New Item object exists
        * @param: char type - type of Item object to be created
        * @return: Item* - returns the new Item object
        */         
        Item* createItem(char type);

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
        BinarySearchTree* findTree(char type) const;
private:
        // Array to store all media type trees. 
        // Uses hash function to determine correct tree 
        BinarySearchTree* libraryStorage[MEDIA_TYPES]; 

        // HashTable class to store patrons 
        HashTable* patrons;
        
        // generates transactions for Patrons
        TransactionFactory* transactionFactory; 
        
        // generates items for library tree   
        ItemFactory* itemFactory;          
        
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
        int hash(char) const;              
    
};
#endif //LIBRARY_H