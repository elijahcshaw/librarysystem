/*--------------------------------------------------------------------------
* @file: item.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for Item class
//-------------------------------------------------------------------------*/
// Item Class: Intended to be base class for specific types of Items stored 
// inside a Library.
//---------------------------------------------------------------------------
// Features: 
//  -- Can get title of Item
//  -- Can modify and get stock of Item
//
// Assumptions/implementation:
// -- Any derived class will have a title and stock
// -- Any derived class will implement the virtual operator overloads
//---------------------------------------------------------------------------
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Item {

public:

    /*-------------------------------------------------------------------------
    * Constructor
    *
    * Initialize all data members that apply to all items that would be in the 
    * library: title and stock
    * @pre: Nothing 
    * @post: Item is created with title = "" and stock = 0
    * @param: None
    */
    Item();

    /*-------------------------------------------------------------------------
    * Destructor
    *
    * virtual destructor that deallocates memory implemented by derived classes
    * @pre: Item is created 
    * @post: Item's memory is cleared if any is allocated by derived classes
    * @param: None
    */
    virtual ~Item();                    // destructor


    /*-------------------------------------------------------------------------
    * getTitle() 
    *
    * Returns the current Item's title in string format 
    * @pre: Item is instantiated and title is set from data given
    * @post: Item's title is returned to caller, blank if not set 
    * @param: None
    * @return: returns the title member of the Item
    */
    string getTitle() const;

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
    void modifyStock(int);

    /*-------------------------------------------------------------------------
    * getStock() 
    *
    * Returns the current stock amount, does not change the value
    * @pre: Item is instantiated 
    * @post: Item's current stock value is returned to caller 
    * @param: None 
    * @return: returns the number of stock
    */
    int getStock() const;

    /*-------------------------------------------------------------------------
    * displayItem()
    *
    * Pure virtual display function that is implemented by derived classes 
    * @pre: dependent upon derived implementation 
    * @post: dependent upon derived implementation 
    * @param: ifstream&: reference to an ifstream to pull data from file
    */
    virtual void displayItem() const = 0;

    /*-------------------------------------------------------------------------
    * setData(ifstream&)
    *
    * pure virtual function that is implemented by derived classes to uniquely 
    * set the data members for that derived class, independent of Item.
    * @pre:dependent upon derived implementation
    * @post: dependent upon derived implementation
    * @param: ifstream&: reference to an ifstream to pull data from file
    */
    virtual void setData(ifstream&) = 0;   // sets item data (for input file ONLY)

    /*-------------------------------------------------------------------------
    * setTransactionData(ifstream&)
    *
    * pure virtual function that is implemented by derived classes to uniquely 
    * set the data members for that derived class, independent of Item
    * Different from setData() because the command data is formatted differently
    * @pre: dependent upon derived implementation
    * @post: dependent upon derived implementation
    */
    virtual void setTransactionData(ifstream&) = 0; // sets item data (for command file ONLY)

    /*-------------------------------------------------------------------------
    * setFormat(char) 
    *
    * pure virtual function that is implemented by derived classes to set their
    * format. This extends beyond books because other objects stored in a 
    * library will have different storage formats. e.g. movies may be discs or
    * stored digitally on the library website 
    * @pre: dependent upon derived implementation
    * @post: dependent upon derived implementation
    * @param: char - one unique character to specify the format.
    * Note: currently, books are automatically stored as 'H' for hardcopy
    * Any request to checkout a non-hardcopy version will be denied.
    */
    virtual void setFormat(char) = 0;

    /*-------------------------------------------------------------------------
    * create()
    
    * Pure virtual function that will be implemented by derived classes.
    * Meant to be used by the factory to return a new empty object of that 
    * class. 
    * @pre: Factory hashes to the correct type and calls this method 
    * @post: New empty object is returned by the derived implementation
    * @param: None
    */
    virtual Item* create() const = 0;

    /*-------------------------------------------------------------------------
    * operator==
    *
    * Pure virtual overloaded equality operator e.g. Item2 == Item1
    * @pre: two objects of type Item exist
    * @post: None
    * @param: const Item& - Item to compare this object to
    * @return: bool (whether or not parameter equals calling object)
    * NOTE: This comparison is the responsibility of derived classes
    */
    virtual bool operator==(const Item &) const = 0;

    /*-------------------------------------------------------------------------
    * operator!=
    *
    * Pure virtual overloaded inequality operator e.g. Item2 == Item1
    * @pre: two objects of type Item exist
    * @post: None
    * @param: const Item& - Item to compare this object to
    * @return: bool (whether or not parameter not equal to calling object)
    * NOTE: This comparison is the responsibility of derived classes
    */
    virtual bool operator!=(const Item &) const = 0;

    
    /*-------------------------------------------------------------------------
    * operator<=
    *
    * Pure virtual overloaded less than or equals to operator 
    * e.g. Item1 <= Item2
    * @pre: two objects of type Item exist
    * @post: None
    * @param: const Item& - Item to compare this object to
    * @return: bool (whether or not calling object is <= parameter)
    * NOTE: This comparison is the responsibility of derived classes
    */
    virtual bool operator<=(const Item &) const = 0;

    /*-------------------------------------------------------------------------
    * operator>=
    *
    * Pure virtual overloaded greater than or equals to operator 
    * e.g. Item1 >= Item2
    * @pre: two objects of type Item exist
    * @post: None
    * @param: const Item& - Item to compare this object to
    * @return: bool (whether or not calling object is >= parameter)
    * NOTE: This comparison is the responsibility of derived classes
    */
    virtual bool operator>=(const Item &) const = 0;
    
    /*-------------------------------------------------------------------------
    * operator<
    *
    * Pure virtual overloaded less than operator e.g. Item1 < Item2
    * @pre: two objects of type Item exist
    * @post: None
    * @param: const Item& - Item to compare this object to
    * @return: bool (whether or not calling object is less than parameter)
    * NOTE: This comparison is the responsibility of derived classes
    */
    virtual bool operator<(const Item &) const = 0;

    /*-------------------------------------------------------------------------
    * operator>
    *
    * Pure virtual overloaded less than operator e.g. Item1 > Item2
    * @pre: two objects of type Item exist
    * @post: None
    * @param: const Item& - Item to compare this object to
    * @return: bool (whether or not calling object is greater than parameter)
    * NOTE: This comparison is the responsibility of derived classes
    */
    virtual bool operator>(const Item &) const = 0;
protected:
    string title; // the identifying title/name
    int stock;    // quantity available
};

#endif
