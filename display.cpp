/*---------------------------------------------------------------------------
* @file: display.cpp
* @authors: Braxton Goss & Elijah Shaw
* @brief: implementation of
--------------------------------------------------------------------------*/

#include "transaction.h"
#include "display.h"
#include "library.h"

/*-------------------------------------------------------------------------
* Constructor 
*
* Nothing to initialize
* @pre: Nothing
* @post: new Display object exists
* @param: None
*/
Display::Display() : Transaction() {}

/*-------------------------------------------------------------------------
* Destructor
*
* Nothing to delete
* @pre: Display object exists
* @post: Memory associated with that Display object is released
* @param: None
*/
Display::~Display() {}

/*-------------------------------------------------------------------------
* create()
*
* Returns a pointer to a newly created & empty Display object
* This method is used inside of TransactionFactory to create new objects 
* without using Switch-Case or If-else statements. 
* @pre: Nothing 
* @post: empty Display object is returned to the caller 
* @param: None
* @return: returns the new Display object
*/
Display* Display::create() const {
    return new Display();
}

/*-------------------------------------------------------------------------
    * execute(Library&, ifstream&)
    *
    * Executes the Display command: displays the entire library collection of
    * items.
    * @post: Item data in the library is printed in a formatted and sectioned 
    * manner.
    * @param: ifstream& - the ifstream providing data for commands (1 per line),
    * in this case marked by a D. 
    * @return: returns a bool marking whether or not to save this Display
    * to patron history. Always returns false, as there is no information to 
    * save or print in the future related to this Display object.
    */
bool Display::execute(Library& currLibrary, ifstream& infile) {
    currLibrary.display();
    return false;
}

/*-------------------------------------------------------------------------
* display()
*
* Prints to the std::cout the Display action, which is always nothing.
* @pre: execute() has already been called by this object.
* @post: Nothing is printed.
* @param: None
*/
void Display::display() const {
    
}