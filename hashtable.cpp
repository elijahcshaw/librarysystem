/*------------------------------------------------------------------------
* @file: hashtable.cpp
* @authors: Elijah Shaw, Braxton Goss
* @brief: implementation for simple HashTable
-------------------------------------------------------------------------*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include "patron.h"
#include "hashtable.h"
using namespace std;

/*-------------------------------------------------------------------------
* Constructor
*
* Initializes the hashTable[] to have nullptr at each index
* @pre: Nothing
* @post: New HashTable object exists
* @param: None
*/
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

/*-------------------------------------------------------------------------
* Destructor
*
* Deletes any occupied spaces in hashTable[]
* @pre: HashTable object exists
* @post: Memory associated with HashTable object is released
* @param: None
*/
HashTable::~HashTable() {
    HashTableEntry* curr;
    HashTableEntry* curr_next;
    for (int i = 0; i < TABLE_SIZE; i++){
        curr = hashTable[i];
        while (curr != nullptr){
            curr_next = curr->next;
            delete curr;
            curr = curr_next;
        }
        hashTable[i] = nullptr;
    }
}

/*-------------------------------------------------------------------------
* hashFunc(int)
*
* Returns the hash value based on the integer passed. 
* @pre: integer passed to function represents possible IDs of patrons 
* @post: index of passed patronID in the hashtable 
* @param: int - patronID we're using to identify a Patron object
* @return: int - index given by hashing the passed patronID
*/
int HashTable::hashFunc(int ID) {
    return ID % TABLE_SIZE;
}

/*-------------------------------------------------------------------------
* insert(int, Patron*)
*
* Inserts a Patron object into the HashTable using their ID as a key
* Duplicate ID's are not allowed and therefore are not inserted 
* @pre: HashTable object exists, Patron object exists
* @post: passed Patron object is inserted into hashTable[]
* @param: int - patronID of the Patron object to be inserted
* @param: Patron* - pointer to the Patron object to be inserted
*/     
void HashTable::insert(int ID, Patron* patron) {
    int index = hashFunc(ID);
    HashTableEntry* prev = nullptr;
    HashTableEntry* curr = hashTable[index];

    // case #1: no collision 
    if (curr == nullptr){
        curr = new HashTableEntry(ID, patron);
        curr->patron = patron;
        curr->ID = ID;
        hashTable[index] = curr;
        
    // case #2: collision 
    } else {
        while(curr != nullptr){
    
            // no duplicate IDs allowed
            if (curr->ID == ID){
                cout << "\nERROR: Patron with ID: " << ID << " exists already.\n";
                delete patron;
                return;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        curr = new HashTableEntry(ID, patron);
        prev->next = curr;
    }
}

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
void HashTable::retrieve(int ID, Patron*& retrieved) {
    int index = hashFunc(ID);
    HashTableEntry* curr = hashTable[index];
    // loop through list at index until we reach end or find matching ID
    while (curr != nullptr) {
        if (curr->ID == ID) {
            retrieved = curr->patron;
            return;
        }
        curr = curr->next;
    }
    return;
}

