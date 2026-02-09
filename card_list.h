// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"
class BST{
  public:
    // ctor, dtor, insert and one print method already done in intbst.cpp:
    BST();                   // constructor
    ~BST();                  // destructor
    bool insert(Card& c);     // insert value; return false if duplicate

    // 8 METHODS YOU MUST IMPLEMENT in intbst.cpp:
    void printInOrder() const;       // print tree data in-order to cout
    bool contains(Card& c) const;  // true if value is in tree

    // THESE ARE HARDER! DO THESE LAST
    Card& getPredecessor(Card& c) const;       // returns the predecessor value of the given value or 0 if there is none
    Card& getSuccessor(Card& c) const;         // returns the successor value of the given value or 0 if there is none
    bool remove(Card& c);                    // deletes the Node containing the given value from the tree

    struct Node {
	Card c;
	Node *left, *right, * parent;
	// useful constructor:
    Node(Card& theCard) : c(theCard), left(nullptr), right(nullptr), parent(nullptr) { }
    };

    // just one instance variable (pointer to root node):
    Node *root;
    
    

    // recursive utility functions for use by public methods above
    Node* getNodeFor(Card& c, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(Card& c, Node *n); // note overloading names for simplicity
    void printInOrder(Node *n) const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(Card& c) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(Card& c) const; // returns the Node containing the predecessor of the given value

};
//revised bst for pa01
    
    
#endif
