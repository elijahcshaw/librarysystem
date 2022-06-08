/*--------------------------------------------------------------------------
* @file: return.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the return (type of transaction) class
---------------------------------------------------------------------------*/
// Return Class: Just as in a real library, a return is a specific type
// of transaction that gets applied to the library and added to patron's 
// individual histories. One copy of an available item is returned to the
// library and taken from the patron who checked it out.
//---------------------------------------------------------------------------
// Features: 
//  -- Contains an associated patronID
//  -- Contains a ptr to an associated Item to this return 
//  -- Returns cannot be made to the library unless the patron checked 
//     out the Item before making the return and the Item exists in library.
//  -- Can display entire return and all associated data fields 
//
// Assumptions/implementation:
// -- Calling execute(Library&, ifstream&) won't be done with uninitialized 
//    objects.
// -- Deleting a Return doesn't delete the Item associated with it.
//---------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

class Return : public Transaction {
  public:
    /*-------------------------------------------------------------------------
    * Constructor 
    *
    * Initializes patronID to be 0 and item to be nullptr.
    * @pre: Nothing
    * @post: new Return object exists
    * @param: None
    */
    Return();

    /*-------------------------------------------------------------------------
    * Destructor
    *
    * Nulls out the member item. Transactions aren't responsible for deleting
    * Item objects they are associated with.
    * @pre: Return object exists
    * @post: Memory associated with that Return object is released (except
    * for item)
    * @param: None
    */
    ~Return();

    /*-------------------------------------------------------------------------
    * create()
    *
    * Returns a pointer to a newly created & empty Return object
    * This method is used inside of TransactionFactory to create new objects 
    * without using Switch-Case or If-else statements. 
    * @pre: Nothing 
    * @post: empty Return object is returned to the caller 
    * @param: None
    * @return: returns the new Return object
    */
    virtual Return* create() const;

    /*-------------------------------------------------------------------------
    * execute(Library&, ifstream&)
    *
    * Executes the Return command: validates the patronID, validates the item 
    * that is requested to be checked out, assigns the Return to the patron's 
    * history, and adds 1 quantity of that item to the library quantity. 
    * @pre: Library and a command file exist
    * @post: An item in zero or one library trees is modified, associated with
    * this Return, and associated with the Patron given by command data.
    * @param: Library& - the library the command should change
    * @param: ifstream& - the ifstream providing data for commands (1 per line),
    * in this case marked by an R as the first char of the line. The rest of the
    * line should provide patronID, item type and item data
    * @return: returns a bool marking whether or not to save this Return
    * to patron history. Returns true if the Return should be saved, and
    * false otherwise (determined by validity of data for Return objects).
    */
    virtual bool execute(Library&, ifstream&);


    /*-------------------------------------------------------------------------
    * display()
    *
    * Prints to the std::cout the Return action and what item is associated 
    * with the Return. 
    * @pre: execute() has already been called by this object.
    * @post: user is notified of Return data 
    * @param: None
    */
    virtual void display() const;
    
  private:
    int patronID; // ID of the patron returning something in the library
    Item* item; // item being returned to the library
}; //RETURN_H

#endif