/*---------------------------------------------------------------------------
* @file: periodicalbook.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: Header file for a specific type of book: periodical
---------------------------------------------------------------------------*/
// PeriodicalBook Class: Specific type of Book containing information for a 
// periodical.
//---------------------------------------------------------------------------
// Features:
// -- Derived class of Book. Contains all data members of Book and Item.
// -- Fully implemented comparison operators for comparison to any other Item
//    (mainly for other PeriodicalBook objects).
// -- Can modify its data based on lines from text files.
// -- Displays itself in a formatted manner.
// -- Can create new PeriodicalBook objects outside of constructor.
//
// Assumptions/implementation: 
// -- Contains a month published
// -- Data that is passed to setData and setTransactionData is correctly
//    formatted for a periodical.
// -- stock is automatically set to 1 whenever a new PeriodicalBook is 
//    instantiated. 
// -- comparison operators use year then month for any comparison/sort
//---------------------------------------------------------------------------


#ifndef PERIODICALBOOK_H
#define PERIODICALBOOK_H

#include <fstream>

class PeriodicalBook : public Book {
  public:

    /*-------------------------------------------------------------------------
    * PeriodicalBook Constructor
    * 
    * Calls Book constructor to initialize members inherited from Book, sets 
    * members to default values (month = 0)
    * @pre: None
    * @post: PeriodicalBook object exists
    * @param: None
    */
    PeriodicalBook();
    
    /*-------------------------------------------------------------------------
    * Destructor
    * 
    * Calls Book destructor to delete members inherited from Book
    * @pre: PeriodicalBook object exists
    * @post: All memory associated with the PeriodicalBook is released
    * @param: None
    */
    ~PeriodicalBook();
    
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
    PeriodicalBook* create() const;

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
    void setData(ifstream &);

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
    void setTransactionData(ifstream&);

    /*-------------------------------------------------------------------------
    * displayItem() 
    * 
    * Inherited from Item - displays info about the PeriodicalBook
    * @pre: PeriodicalBook object exists
    * @post: the members of PeriodicalBook are printed in a formatted manner
    * @param: None 
    */
    void displayItem() const;
    
    // ************************************** //
    // ******** Operator Overloading ******** //
    // ************************************** //

    /*-------------------------------------------------------------------------
    * operator==() 
    * 
    * Inherited from Item - tests equality of two PeriodicalBook objects
    * Compares title, year, month, format
    */
    virtual bool operator==(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator!=(const Item&) 
    * 
    * Inherited from Item - tests inequality of two PeriodicalBook objects
    * Compares title, year, month, format
    */
    virtual bool operator!=(const Item&) const;
    
    /*-------------------------------------------------------------------------
    * operator<=(const Item&) 
    * 
    * Inherited from Item - tests <= of two PeriodicalBook objects
    * Compares by year then month
    */
    virtual bool operator<=(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator>=(const Item&) 
    * 
    * Inherited from Item - tests >= of two PeriodicalBook objects
    * Compares by year then month
    */
    virtual bool operator>=(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator<(const Item&) 
    * 
    * Inherited from Item - tests < of two PeriodicalBook objects
    * Compares by year then month
    */
    virtual bool operator<(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator>(const Item&) 
    * 
    * Inherited from Item - tests > of two PeriodicalBook objects
    * Compares by years then month
    */
    virtual bool operator>(const Item&) const;
  private:
    int month;    // Month of book
};
#endif //