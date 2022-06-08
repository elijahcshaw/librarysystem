/*---------------------------------------------------------------------------
* @file: fictionbook.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for FictionBook (type of Book) class 
//------------------------------------------------------------------------*/
// FictionBook Class: Specific type of Book containing information for a 
// fiction book.
//--------------------------------------------------------------------------
// Features:
// -- Derived class of Book. Contains all data members of Book and Item.
// -- Fully implemented comparison operators for comparison to any other Item
//    (mainly for other FictionBook objects).
// -- Can modify its data based on lines from text files.
// -- Displays itself in a formatted manner.
// -- Can create new FictionBook objects outside of constructor.
//
// Assumptions/implementation: 
// -- Contains an author 
// -- Data that is passed to setData and setTransactionData is correctly
//    formatted for a fiction book.
// -- stock is automatically set to 5 whenever a new FictionBook is 
//    instantiated. 
// -- comparison operators use author then title for any comparison/sort
//---------------------------------------------------------------------------
#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include <fstream>

using namespace std;

class FictionBook : public Book  {
  public:
    /*-------------------------------------------------------------------------
    * FictionBook Constructor
    * 
    * Calls Book constructor to initialize members inherited from Book, sets 
    * members to default values (author = "", stock = 5)
    * @pre: None
    * @post: FictionBook object exists
    * @param: None
    */
    FictionBook();

    /*-------------------------------------------------------------------------
    * Destructor
    * 
    * Calls Book destructor to delete members inherited from Book
    * @pre: FictionBook object exists
    * @post: All memory associated with the FictionBook is released
    * @param: None
    */
    ~FictionBook();

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
    FictionBook* create() const; 

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
    void setData(ifstream&);

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
    void setTransactionData(ifstream&);

    /*-------------------------------------------------------------------------
    * displayItem() 
    * 
    * Inherited from Item - displays info about the FictionBook
    * @pre: FictionBook object exists
    * @post: the members of FictionBook are printed in a formatted manner
    * @param: None 
    */
    void displayItem() const;

    // ************************************** //
    // ******** Operator Overloading ******** //
    // ************************************** //

    
    /*-------------------------------------------------------------------------
    * operator==() 
    * 
    * Inherited from Item - tests equality of two FictionBook objects
    * Compares author, title, format
    */
    virtual bool operator==(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator!=(const Item&) 
    * 
    * Inherited from Item - tests inequality of two FictionBook objects
    * Compares author, title, format
    */
    virtual bool operator!=(const Item&) const;
    
    /*-------------------------------------------------------------------------
    * operator<=(const Item&) 
    * 
    * Inherited from Item - tests <= of two FictionBook objects
    * Compares by author then title
    */
    virtual bool operator<=(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator>=(const Item&) 
    * 
    * Inherited from Item - tests >= of two FictionBook objects
    * Compares by author then title
    */
    virtual bool operator>=(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator<(const Item&) 
    * 
    * Inherited from Item - tests < of two FictionBook objects
    * Compares by author then title
    */
    virtual bool operator<(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator>(const Item&) 
    * 
    * Inherited from Item - tests > of two FictionBook objects
    * Compares by author then title
    */
    virtual bool operator>(const Item&) const;
    
  private:
    string author; // name of book's author
  };
#endif //FICTIONBOOK_H