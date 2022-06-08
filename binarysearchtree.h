/*---------------------------------------------------------------------------
* @file: binarysearchtree.h
* @authors: Braxton Goss & Elijah Shaw
* @brief: header file for BinarySearchTree class
*/
//---------------------------------------------------------------------------
// BinarySearchTree Class: Object that creates a structure for nodes to be 
// stored in a classic tree format with specialized functionality for Library
// storage. 
// --------------------------------------------------------------------------
// Features: 
//  -- Allows for insertion (in sorted order) and retrieval of Nodes 
//  -- Displays tree using an in-order traversal 
//  -- Dump the entire tree using makeEmpty() or by calling delete 
//
// Assumptions/implementation:
// -- implemented using classic Node, left, right implementation. Each node
//    of the tree knows about its data and two children only. 
// -- Instantiation of a BinarySearchTree requires a indentifying 
//    name and formatted string of headers.
// -- Must use insert() to build the tree from Item(s). 
// -- No duplicate Item objects allowed in a single tree.
// -- Nodes contain a pointer to the Item data.
//---------------------------------------------------------------------------
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "item.h"

class Node {

    private:
    // pointer to data object Item 
    Item *data; 

    // left subtree pointer (can be null for leaves)
    Node *left; 
    
    // right subtree pointer (can be null for leaves)
    Node *right;    

    // BinarySearchTree class can access all private variables
    friend class BinarySearchTree; 
};

class BinarySearchTree {

public:
    /*-------------------------------------------------------------------------
    * BinarySearchTree Constructor (with name and header)
    *
    * @pre: nothing
    * @post: tree with null root is allocated in memory
    * @param: string name - name of tree 
    * @param: string header - combination of headers used for display
    */
    BinarySearchTree(string, string);

    /*-------------------------------------------------------------------------
    * BinarySearchTree Destructor
    *
    * @pre tree exists, can be empty or not
    * @post: calls makeEmpty() to empty out all of the data and memory in tree
    * @param: None
    * Note: uses public member method makeEmpty()
    */
    ~BinarySearchTree();

    /*-------------------------------------------------------------------------
    * retrieve()
    *
    * retrieves a copy of the first parameter target, if it is successfully
    * retrieved, found will be a pointer-reference to a copy of the target
    * @pre: tree must be declared and target must be passed of type: Item
    * @post: if a match is found, 2nd parameter will contain a copy of target
    * otherwise, 2nd parameter will contain garbage value set by compiler
    * @param: None
    * @return: bool - true if found, false if not
    */
    bool retrieve(const Item &target, Item *&found) const;

    /*-------------------------------------------------------------------------
    * insert()
    *
    * @pre: current tree must be declared and the parameter passed must be
    * of type Item (which can store any data e.g. string/int/ADT)
    * @post: data is inserted (if not a duplicate)
    * @param: Item* data - the Item object to be inserted into tree
    * @return: true if inserted correctly, false if a duplicate
    * Duplicates can be passed but will not be inserted (return is false)
    * Relies on Item comparison operators < and > to find space in tree
    */
    bool insert(Item *data);

    /*-------------------------------------------------------------------------
    * isEmpty()
    *
    * @pre: tree must be declared
    * @post: root is examined to determine empty or not, result returned
    * @param: None
    * @return boolean - true if tree contains no nodes, false otherwise
    */
    bool isEmpty() const;

    /*-------------------------------------------------------------------------
    * makeEmpty()
    *
    * @pre: tree is declared (empty or not)
    * @post: all memory is deallocated and pointers are freed. The root is set
    * to nullptr at the end
    * @param: None
    * Note: uses private member method makeEmptyHelper for recursion
    */
    void makeEmpty();

    /*-------------------------------------------------------------------------
    * display()
    *
    * @pre: tree is declared (empty or not)
    * @post: tree contents are printed according to an inorder traversal
    * @param: None
    * Note: uses private member method displayHelper for recursion
    */
    void display() const;


private:

    Node *root; // root of the tree
    string name; // name of the tree
    string header;
    
    // ************************************** //
    // **** utility functions start here **** //
    // ************************************** //

    // recursive function to help display the entire tree
    void displayHelper(Node *root) const;

    // recursive function to help delete the entire tree and free memory
    void makeEmptyHelper(Node *&node);

};

#endif //BINARYSEARCHTREE_H