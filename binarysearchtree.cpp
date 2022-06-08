/*
* @file: binarysearchtree.cpp
* @authors: Braxton Goss & Elijah Shaw
* @brief: implementation of BinarySearchTree class used in for Library storage
*/

#include "binarysearchtree.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "constants.h"
using namespace std;

/*-------------------------------------------------------------------------
* BinarySearchTree Constructor (with name and header)
*
* @pre: nothing
* @post: tree with null root is allocated in memory
* @param: string name - name of tree 
* @param: string header - combination of headers used for display
*/
BinarySearchTree::BinarySearchTree(string name, string header) {
    root = nullptr;
    this->name = name;
    this->header = header;
}

/*-------------------------------------------------------------------------
* BinarySearchTree Destructor
*
* @pre tree exists, can be empty or not
* @post: calls makeEmpty() to empty out all of the data and memory in tree
* @param: None
* Note: uses public member method makeEmpty()
*/
BinarySearchTree::~BinarySearchTree() { 
    makeEmpty(); 
}


/*-------------------------------------------------------------------------
* display()
*
* @pre: tree is declared (empty or not)
* @post: tree contents are printed according to an inorder traversal
* @param: None
* Note: uses private member method makeEmptyHelper for recursion
*/
void BinarySearchTree::display() const {
    cout << '\n' << this->name << endl;
    // Header AVAIL, AUTHOR, TITLE, YEAR ETC
    stringstream headers(header);
    string currentHeader;
    getline(headers, currentHeader, ',');
    cout << setw(AVAIL_WIDTH) << left << currentHeader;
    getline(headers, currentHeader, ',');
    cout << setw(TITLE_WIDTH)<< left << currentHeader;
    getline(headers, currentHeader, ',');
    cout << setw(MONTH_AUTHOR_WIDTH) << left << currentHeader;
    getline(headers, currentHeader, ',');
    cout << setw(YEAR_WIDTH) << left << currentHeader << endl;
    displayHelper(root);
}

// recursive output helper
void BinarySearchTree::displayHelper(Node *root) const {

    if (root == nullptr) {
        return;
    }
    displayHelper(root->left);
    root->data->displayItem();
    displayHelper(root->right);
}

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
bool BinarySearchTree::retrieve(const Item &target, Item *&found) const {
    Node *temp = root;
    bool result = false;
    while (temp != nullptr && !result) {
        if (*temp->data == target) {
            found = temp->data;
            result = true;
        } else if (*temp->data > target) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return result;
}

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
bool BinarySearchTree::insert(Item *obj) {
    Node *ptr = new Node; // exception is thrown if memory is not allocated
    ptr->left = ptr->right = nullptr;
    ptr->data = obj;
    obj = nullptr;
    // if tree is empty, new node is at root
    if (root == nullptr) {
        root = ptr;
    } else {
        Node *current = root;
        bool inserted = false;

        // if item is less than current item, insert in left subtree,
        // if item is greater than current item, insert at right subtree
        // otherwise, return false (no dupes allowed)
        while (!inserted) {
            if (*ptr->data < *current->data) {
                if (current->left == nullptr) { // at leaf, insert left
                    current->left = ptr;
                    inserted = true;
                } else {
                    current = current->left; // one step left
                }
            } else if (*ptr->data > *current->data) {
                if (current->right == nullptr) { // at leaf, insert right
                    current->right = ptr;
                    inserted = true;
                } else {
                    current = current->right; // one step right
                }
            } else { // failed < and >, objects are ==
                delete ptr;
                ptr = nullptr;
                return false;
            }
        }
    }
    return true;
}

/*-------------------------------------------------------------------------
* isEmpty()
*
* @pre: tree must be declared
* @post: root is examined to determine empty or not, result returned
* @param: None
* @return boolean - true if tree contains no nodes, false otherwise
*/
bool BinarySearchTree::isEmpty() const {
    return (root == nullptr);
}

/*-------------------------------------------------------------------------
* makeEmpty()
*
* @pre: tree is declared (empty or not)
* @post: all memory is deallocated and pointers are freed. The root is set
* to nullptr at the end
* @param: None
* Note: uses private member method makeEmptyHelper for recursion
*/
void BinarySearchTree::makeEmpty() { 
    makeEmptyHelper(root); 
}

// Helper to makeEmpty(). postOrder deletion: left, right, node
void BinarySearchTree::makeEmptyHelper(Node *&node) {
    if (node == nullptr) {
        return;
    }
    makeEmptyHelper(node->left);
    makeEmptyHelper(node->right);
    delete node->data;
    node->data = nullptr;
    delete node;
    node = nullptr;
}


