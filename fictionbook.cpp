/*-----------------------------------------------------------------------
* @file: fictionbook.cpp
* @authors: Elijah Shaw, Braxton Goss
* @brief: implementation for the FictionBook class
------------------------------------------------------------------------*/

#include "book.h"
#include "fictionbook.h"
#include <iostream>
#include <iomanip>
#include "constants.h"
#include <fstream>

using namespace std;

/*-------------------------------------------------------------------------
* FictionBook Constructor
* 
* Calls Book constructor to initialize members inherited from Book, sets 
* members to default values (author = "", stock = 5)
* @pre: None
* @post: FictionBook object exists
* @param: None
*/
FictionBook::FictionBook() : Book() {
    author = "";
    stock = 5;
}

/*-------------------------------------------------------------------------
* Destructor
* 
* Calls Book destructor to delete members inherited from Book
* @pre: FictionBook object exists
* @post: All memory associated with the FictionBook is released
* @param: None
*/
FictionBook::~FictionBook() {
    // no dynamic memory to delete
}

/*-------------------------------------------------------------------------
* create()
* 
* Inherited from Item - Creates a new instance of FictionBook
* @pre: FictionBook object exists
* @post: an empty FictionBook object is made, allocating new memory. This
* object remains unchanged.
* @param: None 
* @return: returns the newly created FictionBook object
*/
FictionBook* FictionBook::create() const {
    return new FictionBook();
}

/*-------------------------------------------------------------------------
* setData(ifstream&)
* 
* Inherited from Item - updates the members of the current book according 
* to a provided ifstream (data from a file)
* @pre: FictionBook object exists
* @post: The FictionBook's members have been set to data from line in
* ifstream
* @param: ifstream& line of data in the format: author, title, year 
*/
void FictionBook::setData(ifstream& infile) {
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
* Inherited from Item - Sets the data of the current FictionBook to the data
* that is fed in from the command data file. Only differs from setData due to 
* the data ordering and format provided in the commands file.
* @pre: FictionBook object exists 
* @post: the current FictionBook object's members are set to the current
* line of the command ifstream data.
* @param: ifstream& infile - a file stream allowing processing of file data
*/
void FictionBook::setTransactionData(ifstream &infile) {
    infile.get();                

    getline(infile, author, ','); 

    infile.get();                
    
    getline(infile, title, ',');
}

/*-------------------------------------------------------------------------
* displayItem() 
* 
* Inherited from Item - displays info about the FictionBook
* @pre: FictionBook object exists
* @post: the members of FictionBook are printed in a formatted manner
* @param: None 
*/
void FictionBook::displayItem() const {
    cout << setw(AVAIL_WIDTH) << left << stock;
    cout << setw(TITLE_WIDTH) << left << title.substr(0, TITLE_WIDTH - 1);
    cout << setw(MONTH_AUTHOR_WIDTH) << left << author.substr(0, MONTH_AUTHOR_WIDTH - 1);
    cout << setw(YEAR_WIDTH) << left << year;
    cout << endl;
}

/*-------------------------------------------------------------------------
* operator==() 
* 
* Inherited from Item - tests equality of two FictionBook objects
* Compares author, title, format
*/
bool FictionBook::operator==(const Item& other) const {
    if (typeid(*this) != typeid(other)){
        return false;
        
    }
    FictionBook that = static_cast<const FictionBook&>(other);
    return (this->author == that.author) && (this->title == that.title) 
            && (this->format == that.format);
}

/*-------------------------------------------------------------------------
* operator!=(const Item&) 
* 
* Inherited from Item - tests inequality of two FictionBook objects
* Compares author, title, format
*/
bool FictionBook::operator!=(const Item& other) const {
    return !(*this == other);

}

/*-------------------------------------------------------------------------
* operator<=(const Item&) 
* 
* Inherited from Item - tests <= of two FictionBook objects
* Compares by author then title
*/
bool FictionBook::operator<=(const Item& other) const {
    return *this == other || *this < other; 

}

/*-------------------------------------------------------------------------
* operator>=(const Item&) 
* 
* Inherited from Item - tests >= of two FictionBook objects
* Compares by author then title
*/
bool FictionBook::operator>=(const Item& other) const {
    return *this == other || *this > other;
}

/*-------------------------------------------------------------------------
* operator<(const Item&) 
* 
* Inherited from Item - tests < of two FictionBook objects
* Compares by author then title
*/
bool FictionBook::operator<(const Item& other) const {
    if (typeid(*this) != typeid(other)){
        return false;
    }
    const FictionBook that = static_cast<const FictionBook&>(other);
    return (this->author < that.author) || ((this->author == that.author) && (this->title < that.title));
}

/*-------------------------------------------------------------------------
* operator>(const Item&) 
* 
* Inherited from Item - tests > of two FictionBook objects
* Compares by author then title
*/
bool FictionBook::operator>(const Item& other) const {
    if (typeid(*this) != typeid(other)){
        return false;
    }
    const FictionBook that = static_cast<const FictionBook&>(other);
    return (this->author > that.author) || ((this->author == that.author) && (this->title > that.title));
}


