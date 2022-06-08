/*---------------------------------------------------------------------------
* @file: childrenbook.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: Header file for a specific type of book: children's books 
---------------------------------------------------------------------------*/
// ChildrenBook Class: Specific type of Book containing information for a 
// children's book.
// Features:
// -- Derived class of Book. Contains all data members of Book and Item.
// -- Fully implemented comparison operators for comparison to any other Item
//    (mainly for other ChildrenBook objects).
// -- Can modify its data based on lines from text files.
// -- Displays itself in a formatted manner.
// -- Can create new ChildrenBook objects outside of constructor.
//
// Assumptions/implementation: 
// -- Contains an author 
// -- Data that is passed to setData and setTransactionData is correctly
//    formatted for a children's book.
// -- stock is automatically set to 5 whenever a new ChildrenBook is 
//    instantiated. 
// -- comparison operators use title then author for any comparison/sort 
//---------------------------------------------------------------------------

#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H

#include <fstream>

using namespace std;

class ChildrenBook : public Book {
  public:
    /*-------------------------------------------------------------------------
    * ChildrenBook Constructor
    * 
    * Calls Book constructor to initialize members inherited from Book, sets 
    * members to default values (author = "", stock = 5)
    * @pre: None
    * @post: ChildrenBook object exists
    * @param: None
    */
    ChildrenBook();

    /*-------------------------------------------------------------------------
    * Destructor
    * 
    * Calls Book destructor to delete members inherited from Book
    * @pre: ChildrenBook object exists
    * @post: All memory associated with the ChildrenBook is released
    * @param: None
    */
    ~ChildrenBook();          // Destructor

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
    ChildrenBook* create() const; 
    
    /*-------------------------------------------------------------------------
    * setData(ifstream&)
    * 
    * Inherited from Item - updates the members of the current book according 
    * to a provided ifstream (data from a file)
    * @pre: ChildrenBook object exists
    * @post: The ChildrenBook's members have been set to data from line in
    * ifstream
    * @param: ifstream& line of data in the format: author, title, year 
    */
    void setData(ifstream&);   

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
    void setTransactionData(ifstream&); 



    /*-------------------------------------------------------------------------
    * displayItem() 
    * 
    * Inherited from Item - displays info about the ChildrenBook
    * @pre: ChildrenBook object exists
    * @post: the members of ChildrenBook are printed in a formatted manner
    * @param: None 
    */
    void displayItem() const;
    
    // ************************************** //
    // ******** Operator Overloading ******** //
    // ************************************** //
    
    /*-------------------------------------------------------------------------
    * operator==() 
    * 
    * Inherited from Item - tests equality of two ChildrenBook objects
    * Compares title, author, format
    */
    virtual bool operator==(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator!=(const Item&) 
    * 
    * Inherited from Item - tests inequality of two ChildrenBook objects
    * Compares title, author, format
    */
    virtual bool operator!=(const Item&) const;
    
    /*-------------------------------------------------------------------------
    * operator<=(const Item&) 
    * 
    * Inherited from Item - tests <= of two ChildrenBook objects
    * Compares by title then author
    */
    virtual bool operator<=(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator>=(const Item&) 
    * 
    * Inherited from Item - tests >= of two ChildrenBook objects
    * Compares by title then author
    */
    virtual bool operator>=(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator<(const Item&) 
    * 
    * Inherited from Item - tests < of two ChildrenBook objects
    * Compares by title then author
    */
    virtual bool operator<(const Item&) const;

    /*-------------------------------------------------------------------------
    * operator>(const Item&) 
    * 
    * Inherited from Item - tests > of two ChildrenBook objects
    * Compares by title then author
    */
    virtual bool operator>(const Item&) const;

  private:
    string author;          // Store author's name
  };
#endif //CHILDRENBOOK_H