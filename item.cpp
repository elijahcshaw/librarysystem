/*---------------------------------------------------------------------------
* @file: item.cpp
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the Item class
//------------------------------------------------------------------------*/

#include "item.h"

/*-------------------------------------------------------------------------
* Constructor
*
* Initialize all data members that apply to all items that would be in the 
* library: title and stock
* @pre: Nothing 
* @post: Item is created with title = "" and stock = 0
* @param: None
*/
Item::Item() {
    title = "";
    stock = 0;
}

/*-------------------------------------------------------------------------
* Destructor
*
* virtual destructor that deallocates memory implemented by derived classes
* @pre: Item is created 
* @post: Item's memory is cleared if any is allocated by derived classes
* @param: None
*/
Item::~Item() {}

/*-------------------------------------------------------------------------
* getTitle() 
*
* Returns the current Item's title in string format 
* @pre: Item is instantiated and title is set from data given
* @post: Item's title is returned to caller, blank if not set 
* @param: None
* @return: returns the title member of the Item
*/
string Item::getTitle() const{
    return this->title;
}

/*-------------------------------------------------------------------------
* modifyStock(int)
*
* Stock for the item is changed (up or down) based on integer passed.
* Negative int passed means that the stock will decrease by that amount 
* Positive int passed means that the stock will incease by that amount
* @pre: Item is instantiated
* @post: The Item's stock is changed (up or down based on parameter) 
* @param: int: signed integer to change stock up or down 
*/
void Item::modifyStock(int num) {
    stock += num;
}

/*-------------------------------------------------------------------------
* getStock() 
*
* Returns the current stock amount, does not change the value
* @pre: Item is instantiated 
* @post: Item's current stock value is returned to caller 
* @param: None
* @return: returns the number of stock 
*/
int Item::getStock() const {
    return this->stock;
}