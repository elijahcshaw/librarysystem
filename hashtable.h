/*---------------------------------------------------------------------------
* @file: hashtable.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: Header file for HashTable class. This file also contains the
* separate class that represents each entry in the HashTable[] called 
* HashTableEntry. HashTable is a friend class of HashTableEntry. 
---------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "patron.h"
#include "constants.h"
using namespace std;

//---------------------------------------------------------------------------
// HashTableEntry Class: Non-templated class that is designed to hold Patron
// objects only. These entries are stored in its friend class called 
// HashTable. Each entry is given a key-ID, a value-ptr to a patron, and a
// ptr to the next HashTableEntry in the case of a collision in the HashTable.
//---------------------------------------------------------------------------
// Features:
// -- Can point to another HashTableEntry
// -- Contains key:value pairs of PatronID and pointer to the patron
//
// Assumptions/implementation:
// -- Any managing or changing of members in a HashTableEntry is done by the
//    HashTable class itself.
//---------------------------------------------------------------------------
class HashTableEntry {
private:
    int ID; // key
    Patron* patron; // value
    HashTableEntry *next; // next ptr to handle hash collisions 

    /*-------------------------------------------------------------------------
    * HashTableEntry Constructor
    *
    * Initialize all data values of an entry 
    * @pre: entry constructor is called
    * @post: entry is initialized with int ID, patron pointer, and nullptr next
    * @param: ID - 4 digit patronID 
    * @param: patron - pointer to the patron associated with this entry 
    */
    HashTableEntry(int ID, Patron* patron) {
        this->ID = ID;
        this->patron = patron;
        this->next = nullptr;
    }
    
    /*-------------------------------------------------------------------------
    * HashTableEntry Destructor
    *
    * Deletes associated Patron object
    * @pre: HashTableEntry exists
    * @post: Memory associated with HashTableEntry object is released
    * @param: None
    */
    ~HashTableEntry() {
        delete patron;
        patron = nullptr;
    }
    // HashTable can access all private members of entries
    friend class HashTable; 
};


//---------------------------------------------------------------------------
// HashTable Class: simple HashTable object that uses separate chaining to 
// handle collisions. Designed for Patron objects only.
//---------------------------------------------------------------------------
// Features:
// -- hashes Patron objects
// -- handles any collisions of PatronId's by using the technique of separate
//    chaining. 
// -- Patron's can be inserted and retrieved from the HashTable. 
//
// Assumptions/implementation:
// -- The separate chaining essentially makes each index (HashTableEntry) into 
//    a singly-linked list. Any additional collisions are added to the end of 
//    that index's linked list. 
// -- Retrieval must be given a garbage pointer to point to the retrieved 
//    object, if it can be found.
// -- HashTable size is current set to TABLE_SIZE which is 100.
// -- HashFunction will always yield a valid index within the table by using 
//    the modulus operator of the size. 
//---------------------------------------------------------------------------
class HashTable {
    private:
        HashTableEntry *hashTable[TABLE_SIZE]; // hashTable array
    public:
    /*-------------------------------------------------------------------------
    * Constructor
    *
    * Initializes the hashTable[] to have nullptr at each index
    * @pre: Nothing
    * @post: New HashTable object exists
    * @param: None
    */
    HashTable();

    /*-------------------------------------------------------------------------
    * Destructor
    *
    * Deletes any occupied spaces in hashTable[]
    * @pre: HashTable object exists
    * @post: Memory associated with HashTable object is released
    * @param: None
    */
    ~HashTable();

    /*-------------------------------------------------------------------------
    * hashFunc(int)
    *
    * Returns the hash value based on the integer passed. 
    * @pre: integer passed to function represents possible IDs of patrons 
    * @post: index of passed patronID in the hashtable 
    * @param: int - patronID we're using to identify a Patron object
    * @return: int - index given by hashing the passed patronID
    */
    int hashFunc(int);         

    /*-------------------------------------------------------------------------
    * insert(int, Patron*)
    *
    * Inserts a Patron object into the HashTable using their ID as a key
    * @pre: HashTable object exists, Patron object exists
    * @post: passed Patron object is inserted into hashTable[]
    * @param: int - patronID of the Patron object to be inserted
    * @param: Patron* - pointer to the Patron object to be inserted
    */        
    void insert(int, Patron*);    

    /*-------------------------------------------------------------------------
    * retrieve(int, Patron*&)
    *
    * Given a possible patronID (valid or not) and a pointer to a patron,
    * search through the entire hashTable[] until the patron with the same
    * ID is found, the 2nd parameter is the return object. 
    * 2nd parameter is return object
    * @pre: hashTable[] is initialized, int is positive, patron* is declared 
    * @post: passed Patron reference is nullptr or points to Patron object in
    * table
    * @param: int - patronID of the Patron object to be retrieved
    * @param: Patron*& - Reference to the location of the patron in 
    * the hashTable[], if not found: reference will be nullptr 
    */
    void retrieve(int, Patron*&); 
};