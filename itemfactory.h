/*--------------------------------------------------------------------------
* @file: itemfactory.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the ItemFactory class 
//-------------------------------------------------------------------------*/
// ItemFactory Class: Creates new Item objects using a simplified hash 
// technique.
//---------------------------------------------------------------------------
// Features: 
//  -- Does not violate the open-closed principle.
//  -- Can create any existing type of Item.
//
// Assumptions/implementation:
// -- All Item creation is dependent upon hashing and array indicies .
// -- Switch-Cases and if/else statements are never used. 
// -- Items can't be created unless explicitly instantiated in constructor
//    and stored in the factory's array
// -- Items stored in the factory array must have a create() method that 
//    returns a new object of that same type.
//---------------------------------------------------------------------------

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "book.h"
#include "constants.h"

class ItemFactory {
  public:
    /*-------------------------------------------------------------------------
    * Constructor
    *
    * Initialize the array and inputs the keys for different item types.
    * @pre: Nothing 
    * @post: ItemFactory object is created
    * @param: None
    */
    ItemFactory();            

    /*-------------------------------------------------------------------------
    * Destructor
    *
    * Deletes and nulls all entries in the array
    * @pre: ItemFactory object exists 
    * @post: memory associated with ItemFactory object is released
    * @param: None
    */
    ~ItemFactory();          // Deconstructor


    /*-------------------------------------------------------------------------
    * createItem(char)
    *
    * Creates new Item objects of different subclasses based on a given key
    * Determines the type of object using private method hashItem(char)
    * @pre: ItemFactory object exists 
    * @post: a new Item object is created
    * @param: char - the key for a type of Item within the ItemFactory's array
    * @return: returns the new Item object
    */
    Item* createItem(char); // creates a specific book using hash function
  private:
    Item* itemFactory[ITEM_TYPES]; // array for hashtable

    /*-------------------------------------------------------------------------
    * hashItem
    *
    * Hashes a given character by subtracting 'A'
    * @pre: ItemFactory object exists 
    * @post: An integer is returned
    * @param: char - the key to be hashed against to find right kind of object
    * @return: int - the index of the right Item type inside itemFactory[]
    */
    int hashItem(char) const;
}; //ITEMFACTORY_H

#endif