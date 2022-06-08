/*----------------------------------------------------------------
* @file: book.cpp
* @authors: Elijah Shaw, Braxton Goss
* @brief: implementation for the Book object
*/ 

#include "book.h"

/*-------------------------------------------------------------------------
* Book Constructor
*
* Calls Item constructor to initalize members inherited from item and
* sets the book's year to zero.
* @pre: None
* @post: Book object is created and initialized to default values
* @param: None
*/
Book::Book() : Item() {
    year = 0;
}

/*-------------------------------------------------------------------------
* Destructor
* 
* Calls virtual Item destructor to delete members inherited from Item
* @pre: Book object exists
* @post: All memory associated with the Book is released
* @param: None
*/
Book::~Book() {}

/*-------------------------------------------------------------------------
* setFormat
* 
* virtual Item function - sets the format of the current book to a given
* parameter
* @pre: Book object exists
* @post: Book's format has been set to the parameter
* @param: char format - represents different formats to set the Book to
*/
void Book::setFormat(char format) {
    this->format = format;
}