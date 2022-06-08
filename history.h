/*---------------------------------------------------------------------------
* @file: history.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the history (type of transaction) class 
//------------------------------------------------------------------------*/
// History Class: Just as in a real library, a patron's entire history can be 
// shown to the user. This class is implemented to avoid using switch-cases
// and to not violate the open-closed principle. 
//---------------------------------------------------------------------------
// Features:
// -- Displays a Patron's history of transactions at a Library.
//
// Assumptions/implementation:
// -- Calling execute(Library&, ifstream&) won't be done with uninitialized 
//    objects. 
// -- The patron's history can be empty or contain Transactions. 
// -- Library is accessed and passed by reference to history so that 
//    the list of patrons and their associated transactions can be accessed. 
// -- Patron is unchanged after history is displayed.
//---------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H

class History : public Transaction {
  public:
        /*-------------------------------------------------------------------------
        * Constructor 
        *
        * Initializes patronID to be 0
        * @pre: Nothing
        * @post: new History object exists
        * @param: None
        */
        History();

        /*-------------------------------------------------------------------------
        * Destructor
        *
        * Nothing to delete
        * @pre: History object exists
        * @post: Memory associated with that History object is released
        * @param: None
        */
        ~History();

        /*-------------------------------------------------------------------------
        * create()
        *
        * Returns a pointer to a newly created & empty History object
        * This method is used inside of TransactionFactory to create new objects 
        * without using Switch-Case or If-else statements. 
        * @pre: Nothing 
        * @post: empty History object is returned to the caller 
        * @param: None
        * @return: returns the new History object
        */
        virtual History* create() const; 

        /*-------------------------------------------------------------------------
        * execute(Library&, ifstream&)
        *
        * Executes the History command: Displays a Patron's recorded transaction 
        * history.
        * @post: Transaction data for a Patron is printed in a formatted manner.
        * @param: ifstream& - the ifstream providing data for commands (1 per line),
        * in this case marked by an H, followed by a 4 digit number for patronID. 
        * @return: returns a bool marking whether or not to save this History
        * to patron history. Always returns false, as there is no information to 
        * save or print in the future related to this History object.
        */
        virtual bool execute(Library&, ifstream&);

        /*-------------------------------------------------------------------------
        * display() 
        *
        * Prints to the std::cout the History action, which is always nothing.
        * This function is never called on this object b/c it's never saved as part 
        * of a patron's history. Whenever a history object is created, execute() 
        * handles printing the associated patron's entire history of transactions 
        * with the library. 
        * @pre: execute() has already been called by this object.
        * @post: Nothing gets printed for history 
        * @param: None
        */
        virtual void display() const;
  private:
    int patronID;
};

#endif