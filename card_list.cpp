// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h
#include <iostream>
#include "card_list.h"
using namespace std;
BST::BST() {
  root = nullptr; //root null
}

// destructor deletes all nodes
BST::~BST() {
  clear(root); //starting from the root, call
  root = nullptr; //safety check (no garbage): set root to null
}

// recursive helper for destructor
void BST::clear(Node *n) {
  if (n == nullptr) { //null node?
    return; //do nothing! no nodes to be deleted
  }
  clear(n->left); //go down left subtree
  clear(n->right); //go down right subtree
  delete n; //delete the "roots" at the end (could be subtree's root)
}
bool BST::insert(Card& c) {
  if (root == nullptr) { //helper function asks node inserted from is never zero (null), so start from root in non-helper
    root = new Node(c); //give some memory
    root->left = nullptr; //no left child
    root->right = nullptr; //no right child
    root->parent = nullptr; //no parent
    return true; //got one!
  }
  return insert(c, root); //go insert based on rest of the nodes!
}
// recursive helper for insert (assumes n is never 0)
bool BST::insert(Card& c, Node *n) {
  if (c < n->c) { //value to be inserted is less than current node's info
    if (n->left == nullptr) { //only if current's left is null
      n->left = new Node(c); //make new node for n left
      n->left->parent = n; //make sure to link left child back to parent (curr node)
      return true; //successfully added
    } else { //leaf not reached
      return insert(c, n->left); //if not, recurse down left subtree (all the way)
    }
  } else if (c > n->c) { //value to be inserted is GREATER than current node's info
    if (n->right == nullptr) { //current's right is null
      n->right = new Node(c); //give mem
      n->right->parent = n; //link right back to parent (curr node)
      return true; //successfully added
    } else { //leaf not reached
      return insert(c, n->right); //recurse down right
    }
  } else { //equal duplicates?
    return false; //no duplicates!
  }
}
void BST::printInOrder() const {
  printInOrder(root); //start from root
}
void BST::printInOrder(Node *n) const {
  if (n == nullptr) { //null node
    return; //exit
  }
  printInOrder(n->left); //left
  cout << n->c << " " << endl; //node
  printInOrder(n->right); //right
}
BST::Node* BST::getNodeFor(Card& c, Node* n) const{
  if (n == nullptr) { //null node
    return nullptr; // null
  }
  if (c == n->c) { //value is that node's value!
    return n; //found!
  } else if (c < n->c) {//less?
    return getNodeFor(c, n->left); //go left!
  } else { //greater?
    return getNodeFor(c, n->right);
  }
}

// returns true if value is in the tree; false if not
bool BST::contains(Card& c) const {
  Node* n = getNodeFor(c, root); //make n be the node that has the value starting from root
  if (n == nullptr) { //null node
    return false; //value isn't inside the bst
  } else { //non null
    return true; // value is in the tree!
  }
}
BST::Node* BST::getPredecessorNode(Card& c) const{
  Node* n = getNodeFor(c, root); //get the reference node to find the predecessor
  if (n == nullptr) { //nothing?
    return nullptr; //no predecessor of nothing!?!?!
  }
  if (n->left != nullptr) { //left child exists!
    Node* p = n->left; //mark the pointer at the left child of reference node
    while (p->right != nullptr) { //right subtrees are open for the left child to go!
      p = p->right; //keep moving down
    }
    return p; //reached the right most node of left subtree! get the predecessor
  } else { //no left child!
    Node* np = n->parent; //assign a parent of n (pointer)
    while (np != nullptr && np->left == n) { //parent isn't null & parent's left child is n
      n = np; //n updated to parent position
      np = np->parent; //update parent (until parent's right child is n!) -> parent is predecessor!
    }
    return np; //return that parent predecessor!
  }
}

BST::Node* BST::getSuccessorNode(Card& c) const{
  Node* n = getNodeFor(c, root); //get the reference node
  if (n == nullptr) { //node null
    return nullptr; //null!
  }
  if (n->right != nullptr) { //right child exists
    Node* s = n->right; //assign a successor tracker
    while (s->left != nullptr) { //make sure the left of s is still non null!
      s = s->left; //move s
    }
    return s; //reached the left most node of right subtree, so return s!
  } else { //no right child?
    Node* np = n->parent; //parent node for n
    while (np != nullptr && np->right == n) { //parent should be non null, right child is n
      n = np; //update n to parent's postition
      np = np->parent; //update parent
    }
    return np; //now, parent's LEFT child is whatever n is (current node), we found our successor!
  }
}


