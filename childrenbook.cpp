/*---------------------------------------------------------------------------
* @file: childrenbook.cpp
* @authors: Braxton Goss & Elijah Shaw
* @brief: implementation for ChildrenBook
*/
#include "book.h"
#include "childrenbook.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "constants.h"

using namespace std;

/*-------------------------------------------------------------------------
* ChildrenBook Constructor
* 
* Calls Book constructor to initialize members inherited from Book, sets 
* members to default values (author = "", stock = 5)
* @pre: None
* @post: ChildrenBook object exists
* @param: None
*/
ChildrenBook::ChildrenBook() : Book() {
    author = "";
    stock = 5;
}

/*-------------------------------------------------------------------------
* Destructor
* 
* Calls Book destructor to delete members inherited from Book
* @pre: ChildrenBook object exists
* @post: All memory associated with the ChildrenBook i
* @param: char format - represents different formats to set the Book to
*/
ChildrenBook::~ChildrenBook() {
    // no dynamic memory to delete
}

/*-------------------------------------------------------------------------
* create()
* 
* Inherited from Item - Creates a new instance of ChildrenBook
* @pre: ChildrenBook object exists
* @post: an empty ChildrenBook object is made, allocating new memory. This
* object remains unchanged.
* @param: None 
* @return: returns the newly created ChildrenBook object
*/
ChildrenBook* ChildrenBook::create() const {
    return new ChildrenBook();
}

/*-------------------------------------------------------------------------
* setData(ifstream&)
* 
* Inherited from Item - updates the members of the current book according 
* to a provided ifstream (data from a file)
* @pre: ChildrenBook object exists
* @post: The ChildrenBook's members have been set to data from line in
* ifstream
* @param: istream& line of data in the format: author, title, year 
*/
void ChildrenBook::setData(ifstream& infile) {
    infile.get();                     // get (and ignore) blank before author
                                      // don't use if you want to keep the blank
    getline(infile, author, ',');     // input author, looks for comma terminator
    
    infile.get();                     // get (and ignore) blank before title
    getline(infile, title, ',');      // input title
   
    infile >> year;                   // input year
    this->setFormat('H');
}

/*-------------------------------------------------------------------------
* setTransactionData(ifstream&)
* 
* Inherited from Item - Sets the data of the current ChildrenBook to the data
* that is fed in from the command data file. Only differs from setData due to 
* the data ordering and format provided in the commands file.
* @pre: ChildrenBook object exists 
* @post: the current ChildrenBook object's members are set to the current
* line of the command ifstream data.
* @param: ifstream& infile - a file stream allowing processing of file data
*/
void ChildrenBook::setTransactionData(ifstream &infile) {
    infile.get();                // get (and ignore) blank before title
                                 // don't use if you want to keep the blank
    getline(infile, title, ','); // input author, looks for comma terminator

    infile.get();                // get (and ignore) blank before title
                                 // don't use if you want to keep the blank
    getline(infile, author, ',');

}

/*-------------------------------------------------------------------------
* displayItem() 
* 
* Inherited from Item - displays info about the ChildrenBook
* @pre: ChildrenBook object exists
* @post: the members of ChildrenBook are printed in a formatted manner
* @param: None 
*/
void ChildrenBook::displayItem() const {
    cout << setw(AVAIL_WIDTH) << left << stock;
    cout << setw(TITLE_WIDTH) << left << title.substr(0, TITLE_WIDTH - 1);
    cout << setw(MONTH_AUTHOR_WIDTH) << left << author.substr(0, MONTH_AUTHOR_WIDTH - 1);
    cout << setw(YEAR_WIDTH) << left << year;
    cout << endl;
}

/*-------------------------------------------------------------------------
* operator==() 
* 
* Inherited from Item - tests equality of two ChildrenBook objects
* Compares title, author, format
*/
bool ChildrenBook::operator==(const Item& other) const {
    if (typeid(*this) != typeid(other)){
        return false;
    }
    ChildrenBook that = static_cast<const ChildrenBook&>(other);
    return (this->author == that.author) && (this->title == that.title) 
            && (this->format == that.format);
}

/*-------------------------------------------------------------------------
* operator!=(const Item&) 
* 
* Inherited from Item - tests inequality of two ChildrenBook objects
* Compares title, author, format
*/
bool ChildrenBook::operator!=(const Item& other) const {
    return !(*this == other);
}

/*-------------------------------------------------------------------------
* operator<=(const Item&) 
* 
* Inherited from Item - tests <= of two ChildrenBook objects
* Compares by title then author
*/
bool ChildrenBook::operator<=(const Item& other) const {
    return *this == other || *this < other; 

}

/*-------------------------------------------------------------------------
* operator>=(const Item&) 
* 
* Inherited from Item - tests >= of two ChildrenBook objects
* Compares by title then author
*/
bool ChildrenBook::operator>=(const Item& other) const {
    return *this == other || *this > other;
}

/*-------------------------------------------------------------------------
* operator<(const Item&) 
* 
* Inherited from Item - tests < of two ChildrenBook objects
* Compares by title then author
*/
bool ChildrenBook::operator<(const Item& other) const {
    if (typeid(*this) != typeid(other)){
        return false;
    }

    const ChildrenBook that = static_cast<const ChildrenBook&>(other);
    return (this->title < that.title) || ((this->title == that.title) && (this->author < that.author));
}

/*-------------------------------------------------------------------------
* operator>(const Item&) 
* 
* Inherited from Item - tests > of two ChildrenBook objects
* Compares by title then author
*/
bool ChildrenBook::operator>(const Item& other) const {
    if (typeid(*this) != typeid(other)){
        return false;
    }
    const ChildrenBook that = static_cast<const ChildrenBook&>(other);
    return (this->title > that.title) || ((this->title == that.title) && (this->author > that.author));
}