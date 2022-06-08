/**
* @file periodicalbook.cpp
* @author Braxton Goss, Elijah Shaw
* @brief implementation of PeriodicalBook class
*/
#include "book.h"
#include "periodicalbook.h"
#include "constants.h"
#include <fstream>
#include <iostream>
#include <iomanip> 

/*-------------------------------------------------------------------------
* PeriodicalBook Constructor
* 
* Calls Book constructor to initialize members inherited from Book, sets 
* members to default values (month = 0)
* @pre: None
* @post: PeriodicalBook object exists
* @param: None
*/
PeriodicalBook::PeriodicalBook() : Book() {
    month = 0;
    stock = 1;
}

/*-------------------------------------------------------------------------
* Destructor
* 
* Calls Book destructor to delete members inherited from Book
* @pre: PeriodicalBook object exists
* @post: All memory associated with the PeriodicalBook is released
* @param: None
*/
PeriodicalBook::~PeriodicalBook() {
    // no dynamic memory to delete
}

/*-------------------------------------------------------------------------
* create()
* 
* Inherited from Item - Creates a new instance of PeriodicalBook
* @pre: PeriodicalBook object exists
* @post: an empty PeriodicalBook object is made, allocating new memory. This
* object remains unchanged.
* @param: None 
* @return: returns the newly created PeriodicalBook object
*/
PeriodicalBook* PeriodicalBook::create() const {
    return new PeriodicalBook();
}

/*-------------------------------------------------------------------------
* setData(ifstream&)
* 
* Inherited from Item - updates the members of the current book according 
* to a provided ifstream (data from a file)
* @pre: PeriodicalBook object exists
* @post: The PeriodicalBook's members have been set to data from line in
* ifstream
* @param: ifstream& line of data in the format: title, month, year
*/
void PeriodicalBook::setData(ifstream &infile) {
    infile.get();                // get (and ignore) blank before title
                                 // don't use if you want to keep the blank
    getline(infile, title, ','); // input author, looks for comma terminator

    infile >> month; // input month
    infile >> year;  // input year
    this->setFormat('H');
}

/*-------------------------------------------------------------------------
* setTransactionData(ifstream&)
* 
* Inherited from Item - Sets the data of the current PeriodicalBook to the data
* that is fed in from the command data file. Only differs from setData due to 
* the data ordering and format provided in the commands file.
* @pre: PeriodicalBook object exists 
* @post: the current PeriodicalBook object's members are set to the current
* line of the command ifstream data.
* @param: ifstream& infile - a file stream allowing processing of file data
*/
void PeriodicalBook::setTransactionData(ifstream &infile) {
    infile >> year;  // input year
    infile >> month; // input month
    infile.get();                // get (and ignore) blank before title
                                 // don't use if you want to keep the blank
    getline(infile, title, ','); // input author, looks for comma terminator
}

/*-------------------------------------------------------------------------
* displayItem() 
* 
* Inherited from Item - displays info about the PeriodicalBook
* @pre: PeriodicalBook object exists
* @post: the members of PeriodicalBook are printed in a formatted manner
* @param: None 
*/
void PeriodicalBook::displayItem() const {
    cout << setw(AVAIL_WIDTH) << left << stock;
    cout << setw(TITLE_WIDTH) << left << title.substr(0, TITLE_WIDTH - 1);
    cout << setw(MONTH_AUTHOR_WIDTH) << left << month;
    cout << setw(YEAR_WIDTH) << left << year;
    cout << endl;
}

/*-------------------------------------------------------------------------
* operator==() 
* 
* Inherited from Item - tests equality of two PeriodicalBook objects
* Compares title, year, month, format
*/
bool PeriodicalBook::operator==(const Item &other) const {
    if (typeid(*this) != typeid(other)) {
        return false;
    }
    PeriodicalBook that = static_cast<const PeriodicalBook &>(other);
    return (this->month == that.month) && (this->title == that.title) 
            && (this->year == that.year) && (this->format == that.format);
}


/*-------------------------------------------------------------------------
* operator!=(const Item&) 
* 
* Inherited from Item - tests inequality of two PeriodicalBook objects
* Compares title, year, month, format
*/
bool PeriodicalBook::operator!=(const Item &other) const {
    return !(*this == other);
}

/*-------------------------------------------------------------------------
* operator<=(const Item&) 
* 
* Inherited from Item - tests <= of two PeriodicalBook objects
* Compares by year then month
*/
bool PeriodicalBook::operator<=(const Item &other) const {
    return *this == other || *this < other;
}

/*-------------------------------------------------------------------------
* operator>=(const Item&) 
* 
* Inherited from Item - tests >= of two PeriodicalBook objects
* Compares by year then month
*/
bool PeriodicalBook::operator>=(const Item &other) const {
    return *this == other || *this > other;
}

/*-------------------------------------------------------------------------
* operator<(const Item&) 
* 
* Inherited from Item - tests < of two PeriodicalBook objects
* Compares by year then month
*/
bool PeriodicalBook::operator<(const Item &other) const {
    if (typeid(*this) != typeid(other)) {
        return false;
    }
    const PeriodicalBook that = static_cast<const PeriodicalBook &>(other);
    return (this->year < that.year) ||
           ((this->year == that.year) &&
            ((this->month < that.month) ||
             (this->month == that.month && this->title < that.title)));
}


/*-------------------------------------------------------------------------
* operator>(const Item&) 
* 
* Inherited from Item - tests > of two PeriodicalBook objects
* Compares by years then month
*/
bool PeriodicalBook::operator>(const Item &other) const {
    if (typeid(*this) != typeid(other)) {
        return false;
    }
    const PeriodicalBook that = static_cast<const PeriodicalBook &>(other);
    return (this->year > that.year) ||
           ((this->year == that.year) &&
            ((this->month > that.month) ||
             (this->month == that.month && this->title > that.title)));
}
