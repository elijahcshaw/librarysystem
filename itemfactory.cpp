/*---------------------------------------------------------------------------
* @file: itemfactory.cpp
* @authors: Elijah Shaw, Braxton Goss
* @brief: implementation for ItemFactory class 
//------------------------------------------------------------------------*/
#include "itemfactory.h"
#include "fictionbook.h"
#include "childrenbook.h"
#include "periodicalbook.h"

/*-------------------------------------------------------------------------
* Constructor
*
* Initialize the array and inputs the keys for different item types.
* @pre: Nothing 
* @post: ItemFactory object is created
* @param: None
*/
ItemFactory::ItemFactory() {
    
    // For reference in .h file: Book* itemFactory[BOOK_TYPES]; // array for hashtable
    for (int i = 0; i < ITEM_TYPES; i++){
        itemFactory[i] = nullptr;
    }
    // position 2
    itemFactory[C_HASH_VALUE] = new ChildrenBook;

    // positon 5
    itemFactory[F_HASH_VALUE] = new FictionBook;

    // position 15 
    itemFactory[P_HASH_VALUE] = new PeriodicalBook;
}

/*-------------------------------------------------------------------------
* Destructor
*
* Deletes and nulls all entries in the array
* @pre: ItemFactory object exists 
* @post: memory associated with ItemFactory object is released
* @param: None
*/
ItemFactory::~ItemFactory() {
    for (int i = 0; i < ITEM_TYPES; i++) {
        if (itemFactory[i] != nullptr) {
            delete itemFactory[i];
            itemFactory[i] = nullptr;
        }
    }

}

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
Item* ItemFactory::createItem(char type) {
    int subscript = hashItem(type);
    if (itemFactory[subscript] == nullptr) { 
        cout << endl;
        cout << "ERROR: " << type << " is not a valid item type." << endl;
        return nullptr;
    }else{
        return itemFactory[subscript]->create();
    }
}

/*-------------------------------------------------------------------------
* hashItem
*
* Hashes a given character by subtracting 'A'
* @pre: ItemFactory object exists 
* @post: An integer is returned
* @param: char - the key to be hashed against to find right kind of object
* @return: int - the index of the right Item type inside itemFactory[]
*/
int ItemFactory::hashItem(char type) const {
    return type - 'A';
}