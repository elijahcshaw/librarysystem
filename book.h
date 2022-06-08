//---------------------------------------------------------------------------
/*
* @file: book.h 
* @authors: Braxton Goss & Elijah Shaw
* @brief: header file for book class
*/
//---------------------------------------------------------------------------
// Book Class: Object inheriting from Item. Intended to be base class for 
// specific types of Books.
// Features: 
//  -- Derived class of Item. Contains all data members of Item.
//  -- Stores the Book's format and year published. 
//  -- Can set the Book's format to a new format 
//
// Assumptions/implementation:
// -- Any derived class will have a year and format (as well as title and stock
//    from Item)
// -- Any derived class will implement the virtual operator overloads from
//    Item
//---------------------------------------------------------------------------
#ifndef BOOK_H
#define BOOK_H

#include "item.h"
#include <fstream>
using namespace std;

class Book: public Item {
  public:

    /*-------------------------------------------------------------------------
    * Book Constructor
    *
    * Calls Item constructor to initalize members inherited from Item and
    * sets the book's year to zero.
    * @pre: None
    * @post: Book object is created and initialized to default values
    * @param: None
    */
    Book();

    /*-------------------------------------------------------------------------
    * Destructor
    *
    * Calls virtual Item destructor to delete members inherited from Item
    * @pre: Book object exists
    * @post: All memory associated with the Book is released
    * @param: None
    */
    ~Book();              // destructor
    

    /*-------------------------------------------------------------------------
    * setFormat
    * 
    * virtual Item function - sets the format of the current book to a given
    * parameter
    * @pre: Book object exists
    * @post: Book's format has been set to the parameter
    * @param: char format - represents different formats to set the Book to
    */
    virtual void setFormat(char);

  protected:
    int year;     // year book was published
    char format;  // format of the book (hard copy, etc.)
};
#endif //BOOK_H