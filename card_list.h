// card_list.h
// Author: Lucas Zhou
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
    
    //to help with -- iterator:
    Node* getMaxNode() const{
      Node* n = root;
      if (n == nullptr) {
        return nullptr;
      }
      while (n->right != nullptr) { 
        n = n->right;
      }
      return n;
    }

    // recursive utility functions for use by public methods above
    Node* getNodeFor(Card& c, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(Card& c, Node *n); // note overloading names for simplicity
    void printInOrder(Node *n) const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(Card& c) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(Card& c) const; // returns the Node containing the predecessor of the given value
    
   class Iterator{
     private:
       Node* curr;
       BST* cardList; 
     public:
       Iterator(Node* n, BST* c_list) : curr(n), cardList(c_list) { }
       Iterator& operator++() {
         if (curr == nullptr) {
           return *this;
         }
         curr = cardList->getSuccessorNode(curr->c);
         return *this; 
      }
      Iterator& operator--() {
        if (curr == nullptr) {
          curr = cardList->getMaxNode();
          return *this;
        }
        curr = cardList->getPredecessorNode(curr->c);
        return *this;
      }
      bool operator!=(const Iterator& other) const {
        return this->curr != other.curr;
      }
      bool operator==(const Iterator& other) const {
        return this->curr == other.curr;
      }
      Card& operator*() const {
        return curr->c; //object!
      }
      Card* operator->() const {
        return &curr->c; //memory address!
      }
  };
  Iterator begin() const {
    Node* n = root; 
    while (n != nullptr && n->left != nullptr) {
      n = n->left;
    }
    return Iterator(n, (BST*)this);
  }
  Iterator end() const {
    return Iterator(nullptr, (BST*)this); 
  }
  Iterator rbegin() const {
    Node* n = root;
    while (n != nullptr && n->right != nullptr) {
      n = n->right;
    }
    return Iterator(n, (BST*)this);
  }
  Iterator rend() const {
    return Iterator(nullptr, (BST*)this);
  }  
};
//revised bst for pa01
    
    
#endif
