/*---------------------------------------------------------------------------
* @file: display.h
* @authors: Elijah Shaw, Braxton Goss
* @brief: header file for the display (type of transaction) class 
//------------------------------------------------------------------------*/
// Display Class: Just as in a real library, the entire library can be 
// shown to the user. This class is implemented to avoid using switch-cases
// and to not violate the open-closed principle. 
// Features:
// -- Displays a Library's contents
//
// Assumptions/implementation:
// -- Calling execute(Library&, ifstream&) won't be done with uninitialized 
//    objects. Executing a display requires the use of the binarysearchtree's
//    display method. This method uses a recursive helper function and with
//    a large enough library, may cause a stack overflow. 
// -- The library can either be empty or full of objects. 
// -- The library is unchanged after being displayed.
//---------------------------------------------------------------------------

#ifndef DISPLAY_H
#define DISPLAY_H

class Display : public Transaction {
    public:

        /*-------------------------------------------------------------------------
        * Constructor 
        *
        * Nothing to initialize
        * @pre: Nothing
        * @post: new Display object exists
        * @param: None
        */
        Display();

        /*-------------------------------------------------------------------------
        * Destructor
        *
        * Nothing to delete
        * @pre: Display object exists
        * @post: Memory associated with that Display object is released
        * @param: None
        */
        ~Display();

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
        virtual Display* create() const;  // creates new Display object

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
        virtual bool execute(Library&, ifstream&); // Perform borrowed operation in Transaction class 

        

        /*-------------------------------------------------------------------------
        * display()
        *
        * Prints to the std::cout the Display action, which is always nothing.
        * @pre: execute() has already been called by this object.
        * @post: Nothing is printed
        * @param: None
        */
        virtual void display() const;
    
}; //DISPLAY_H

#endif