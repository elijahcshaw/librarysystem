/*---------------------------------------------------------------------------
* @file: checkout.h
* @authors: Braxton Goss & Elijah Shaw
* @brief: header file for Checkout class
*/
//---------------------------------------------------------------------------
// Checkout Class: Just as in a real library, a checkout is a specific 
// type of transaction that gets applied to the library and added to patron's 
// individual histories. One copy of an available item is given to a patron
// checking it out.
// Features: 
//  -- Contains an associated patronID
//  -- Contains a ptr to an associated Item to this Checkout 
//  -- Items are not allowed to be checked out unless they have remaining 
//     stock and they exist in the library. 
//  -- Can display entire Checkout and all associated data fields 
//
// Assumptions/implementation:
// -- Calling execute(Library&, ifstream&) won't be done with uninitialized 
//    objects.
// -- Deleting a Checkout doesn't delete the Item associated with it.
//---------------------------------------------------------------------------
#ifndef CHECKOUT_H
#define CHECKOUT_H

class Checkout : public Transaction {
    public:
        /*-------------------------------------------------------------------------
        * Constructor 
        *
        * Initializes patronID to be 0 and item to be nullptr.
        * @pre: Nothing
        * @post: new Checkout object exists
        * @param: None
        */
        Checkout();

        /*-------------------------------------------------------------------------
        * Destructor
        *
        * Nulls out the member item. Transactions aren't responsible for deleting
        * Item objects they are associated with.
        * @pre: Checkout object exists
        * @post: Memory associated with that Checkout object is released (except
        * for item)
        * @param: None
        */
        ~Checkout();

        /*-------------------------------------------------------------------------
        * create()
        *
        * Returns a pointer to a newly created & empty Checkout object
        * This method is used inside of TransactionFactory to create new objects 
        * without using Switch-Case or If-else statements. 
        * @pre: Nothing 
        * @post: empty Checkout object is returned to the caller 
        * @param: None
        * @return: returns the new Checkout object
        */
        virtual Checkout* create() const;

        /*-------------------------------------------------------------------------
        * execute(Library&, ifstream&)
        *
        * Executes the checkout command: validates the patronID, validates the item 
        * that is requested to be checked out, assigns the checkout to the patron's 
        * history, and removes 1 quantity of that item from the library quantity. 
        * @pre: Library and a command file exist
        * @post: A item in zero or one library trees is modified, associated with
        * this Checkout, and associated with the Patron given by command data.
        * @param: Library& - the library the command should change
        * @param: ifstream& - the ifstream providing data for commands (1 per line),
        * in this case marked by a C as the first char of the line. The rest of the
        * line should provide patronID, item type and item data
        * @return: returns a bool marking whether or not to save this Checkout
        * to patron history. Returns true if the Checkout should be saved, and
        * false otherwise (determined by validity of data for Checkout objects).
        */
        virtual bool execute(Library&, ifstream&);


        /*-------------------------------------------------------------------------
        * display()
        *
        * Prints to the std::cout the checkout action and what item is associated 
        * with the checkout. 
        * @pre: execute() has already been called by this object.
        * @post: user is notified of checkout data 
        * @param: None
        */
        virtual void display() const;

    private:
        int patronID; // ID of the patron checking something out of the library
        Item* item; // item being checked out
};
#endif 