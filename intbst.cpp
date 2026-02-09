// intbst.cpp
// Implements class IntBST
// Lucas Zhou, 1/20/2026

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
BST::BST() { 
  root = nullptr; //root null
}

// destructor deletes all nodes
IntBST::~IntBST() {
  clear(root); //starting from the root, call
  root = nullptr; //safety check (no garbage): set root to null
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
  if (n == nullptr) { //null node?
    return; //do nothing! no nodes to be deleted
  }
  clear(n->left); //go down left subtree
  clear(n->right); //go down right subtree
  delete n; //delete the "roots" at the end (could be subtree's root)
}
//works!
//redos: 1

// insert value in tree; return false if duplicate
/*
You don’t have root, so make new root node, give it a value.

Then:
for all other values to be inserted, check if it’s greater than or less than the current parent. If less, insert left. If greater, insert right.
*/
bool IntBST::insert(int value) {
  if (root == nullptr) { //helper function asks node inserted from is never zero (null), so start from root in non-helper
    root = new Node; //give some memory
    root->info = value; //give it a value
    root->left = nullptr; //no left child
    root->right = nullptr; //no right child
    root->parent = nullptr; //no parent
    return true; //got one!
  }
  return insert(value, root); //go insert based on rest of the nodes!
}
// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
  if (value < n->info) { //value to be inserted is less than current node's info
    if (n->left == nullptr) { //only if current's left is null
      n->left = new Node; //make new node for n left
      n->left->info = value; //that new left node gets assigned the value
      n->left->parent = n; //make sure to link left child back to parent (curr node)
      return true; //successfully added
    } else { //leaf not reached
      return insert(value, n->left); //if not, recurse down left subtree (all the way)
    }
  } else if (value > n->info) { //value to be inserted is GREATER than current node's info
    if (n->right == nullptr) { //current's right is null
      n->right = new Node; //give mem
      n->right->info = value; //right node gets value
      n->right->parent = n; //link right back to parent (curr node)
      return true; //successfully added
    } else { //leaf not reached
      return insert(value, n->right); //recurse down right
    }
  } else { //equal duplicates?
    return false; //no duplicates!
  }
}
//redos: 1
//works!

 
  


// print tree data pre-order
void IntBST::printPreOrder() const {
  printPreOrder(root); //start from root
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
  if (n == nullptr) { //null node
    return; //exit
  }
  cout << n->info << " "; //node
  printPreOrder(n->left); //left
  printPreOrder(n->right); //right
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
  printInOrder(root); //start from root
}
void IntBST::printInOrder(Node *n) const {
  if (n == nullptr) { //null node
    return; //exit
  }
  printInOrder(n->left); //left
  cout << n->info << " "; //node
  printInOrder(n->right); //right
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
  printPostOrder(root); //from root
}

void IntBST::printPostOrder(Node *n) const {
  if (n == nullptr) { //null node! (base case)
    return; //exit
  }
  printPostOrder(n->left); //left
  printPostOrder(n->right); //right
  cout << n->info << " "; //node
}

// return sum of values in tree
int IntBST::sum() const {
  return sum(root); //start root
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
  if (n == nullptr) { //null node 
    return 0; //don't do anything (sum stays zero)
  }
  return sum(n->left) + n->info + sum(n->right); //in order! (add info for sum)
}

// return count of values
int IntBST::count() const {
  return count(root); //start root
}

// recursive helper for count
int IntBST::count(Node *n) const {
  if (n == nullptr) { //null node
    return 0; //no count to update
  }
  return count(n->left) + 1 + count(n->right); //in order! (add 1 for count)
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
  if (n == nullptr) { //null node
    return nullptr; // null
  }
  if (value == n->info) { //value is that node's value!
    return n; //found!
  } else if (value < n->info) {//less?
    return getNodeFor(value, n->left); //go left!
  } else { //greater?
    return getNodeFor(value, n->right);
  }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
  Node* n = getNodeFor(value, root); //make n be the node that has the value starting from root
  if (n == nullptr) { //null node
    return false; //value isn't inside the bst
  } else { //non null
    return true; // value is in the tree!
  }
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
  Node* n = getNodeFor(value, root); //get the reference node to find the predecessor
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

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
  Node* pred = getPredecessorNode(value); //node for predecessor
  if (pred == nullptr) { //null pred
    return 0; // zero!
  } else {
    return pred->info; //get value of predecessor!
  }
}
//good: redo count: 1

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
  Node* n = getNodeFor(value, root); //get the reference node
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
//good redo count = 1


// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
  Node* s = getSuccessorNode(value); //successor
  if (s == nullptr) { //no succesor
    return 0; //0!
  } else { //yes successor?
    return s->info; //get it's value
  } 
}


// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
// no kids: 
//(1) -  with parent
	//unlink parent, remove self
//(2) - without parent
	// self is root, just delete self, root null!

//one kid:
//(1) - find kid, some c
//(2) - link parent to child
        //null parent? n is the root! after delete n? update root with child
	//non null parent? 
		//if parent left is self, then link parent left to child (Bst property hold)
		//if parent right is self, then link parent right to child (Bst property hold)
//(3) - link child back to parent
//(4) delete self

//two kids:
//find successor/predecessor
//save info to temp
//recursive remove (continuously, don't stop)
//update current node value to temp
//then return true (don't return twice)
//redos: 1
  Node* n = getNodeFor(value, root); //find node
  if (n == nullptr) { //nothing to be removed
    return false; //doesn't exist
  }
  Node* p = n->parent; //parent for n
  if (n->left == nullptr && n->right == nullptr) { //no kids
    if (p == nullptr) { //no parent
      delete n; //just delete n
      root = nullptr; //to be clear, make list empty! bst is NULL
      return true; //deleted a single node!!!
    } else { //has a parent
      if (p->left == n) { //p's left is current node to be deleted
        p->left = nullptr; //detach
        delete n; //delete n
        return true; //delete success
      } else { //parent's right is n
        p->right = nullptr; //detach
        delete n; //delete n
        return true; //deleted!
      }
    }
  } else if (n->left != nullptr && n->right == nullptr) { //left kid
    Node* c = n->left; //left child!
    c->parent = p; //parent to child
    if (p == nullptr) { //no parent
      root = c; //save root as child
      delete n; //get rid of self
      return true; //success
    } else { //yes parent
      if (p->left == n) { //parent's left is current node
        p->left = c; //p's left link to child
        delete n; //safely delete n
        return true; //success
      } else { //parent's right is n
        p->right = c; //p's right link to child 
        delete n; //safely delete n
        return true; //success
      }
    }
  } else if (n->right != nullptr && n->left == nullptr) { //right kid
    Node* c = n->right; //right child
    c->parent = p; //child->parent
    if (p == nullptr) { //no parent
      delete n; //delete n
      root = nullptr; //root null
      return true; //deleted
    } else { //there is a parent 
      if (p->right == n) { //parent's right is current node
        p->right = c; //parent's right points to child
        delete n; //safely delete n
        return true; //success
      } else { //parent's left is n
        p->left = c; //parent's left points to child
        delete n; //safely delete n
        return true; //success
      }
    }
  } else { //2 kids
    Node* succ = getSuccessorNode(value); //get successor
    int temp = succ->info; //save in temp
    remove(succ->info); //delete successor node
    n->info = temp; //replace after deleting, done!
    return true; //deleted
  }
}


      
      
     
  


 //all good! 

//Extra Leetcode
//maxDepth
int IntBST::maxDepth() const { //wrapper for lp1
  return maxDepth(root); //call using private data
}
int IntBST::maxDepth(const Node* root) const { //lp1 //helper
  if (root == nullptr) { //base case, no root, empty bst
    return 0; //nothing!
  }
  int left_sum = 1 + maxDepth(root->left); //add one and go down the left, keep adding one for each left other than root
  int right_sum = 1 + maxDepth(root->right); //add one, go down right
  if (left_sum > right_sum) { //left > right
    return left_sum; //return left
  } else { //right greater than or equal to (== covered because could return either one)
    return right_sum; //return right
  }
} //good

//sortedArrayToBST
void IntBST::sortedArrayToBST(vector<int>& nums) { //lp2
  root = buildHelper(nums, 0, nums.size() - 1, nullptr); //start from the beginning to (num elements -1)
}

IntBST::Node* IntBST::buildHelper(vector<int>& nums, int left, int right, Node* p) { //helper (takes in array, left and right index), don't forget parent!
  if (left > right) { //indexes out of order! 
    return nullptr; //can't build anymore, stop!
  }
  int mid = left + (right - left) / 2; //find middle (subtraction helps reduce large numbers overflow (left + right = too big)
  Node* node = new Node; // allocate memory for new node
  node->info = nums[mid]; //set info to middle element
  node->parent = p; //don't forget parent!
  node->left = buildHelper(nums, left, mid-1, node); //get the sub problem for left (left to one before middle), must connect to current node
  node->right = buildHelper(nums, mid+1, right, node); //get sub problem for right (one after middle to the right), must connect to current node
  return node; //return the node (this is for each sub problem)
}
//it works!

//mode


//priority:
//lca
IntBST::Node* IntBST::lca(Node* root, Node* p, Node* q) { //lca code
  Node* n = root; //set a current pointer for the node
  if (n == nullptr || p == nullptr || q == nullptr) { //empty, no p, or no q
    return nullptr; //no lca
  } else { //n is null
    if (p->info < n->info && q->info < n->info) { //both p and q VALUE are less than current node
      return lca(n->left,p,q); // recurse down left subtree
    } else if (p->info > n->info && q->info > n->info) { //p and q VALUE are greater than current node
      return lca(n->right,p,q); //recurse down right subtree
    } else { //either p and q are on both sides of n, or either p or q is n (covers both)
      return n; //give the current node
    }
  }
}
//it works!!!
//kthsmall/large

int IntBST::getkthsmallest(int k) const { //function setup
  int kthcount = 0; //initialize a kth count
  int kthval = 0; //initialize a kth value
  return getkthsmallesthelper(root, kthcount, k, kthval); 
}

int IntBST::getkthsmallesthelper(Node* n, int& count, int k_idx, int& k_val) const{
  if (n == nullptr) { //null node
    return 0; //do nothing
  }
  getkthsmallesthelper(n->left, count, k_idx, k_val); //go left assuming it works
  if (count == k_idx) { //counted enough
    return k_val; //return the kval
  }
  count++; //add one to count (node)
  k_val = n->info; //update k_val with n_info (node only)
  if (count == k_idx) { //counted enough
    return k_val; //return the kval
  }
  getkthsmallesthelper(n->right, count, k_idx, k_val); //go right assuming it works
  if (count == k_idx) { //counted enough
    return k_val; //return the k_val
  }
  return 0; //no kth smallest!
}
//recoded: 1 2

//works!!!!

int IntBST::countLeaves() const{ //count leaves
  int count = 0; //can only accept local variable
  inOrderHelperLeaves(root, count); //start from root, update the cound
  return count; //return its value
}
void IntBST::inOrderHelperLeaves(Node* n, int& c) const{ //helper must be const
  if (n == nullptr) { //null node
    return; //don't do anything
  }
  inOrderHelperLeaves(n->left,c); //go left (assume works)
  if (n->left == nullptr && n->right == nullptr) { //leaf reached (node case
    c++; //add one to leaf count
  } 
  inOrderHelperLeaves(n->right,c); //go right (assume works)
}
// it works! 

int IntBST::countLeavesPreOrder() const{ //public wrapper
  return preOrderHelperLeaves(root); //return
}
//wechat method: pre order
int IntBST::preOrderHelperLeaves(Node* n) const{ //different method
  if (n == nullptr) { //null node
    return 0; //0 return
  }
  if (n->left == nullptr && n->right == nullptr) { //node step: check node for leaf
    return 1; //get 1
  }
  return preOrderHelperLeaves(n->left) + preOrderHelperLeaves(n->right); //assuming it works keep totaling up the leaf count based on left and right
}


vector<int> IntBST::getKeysAtDepth(int d) const{ //get the keys
  int curr_level = 0; //start at a current level (zero)
  vector<int> result; //result vector init
  bfsHelper(root, result, d, curr_level); //helper to add
  return result; //return the final resulf
}

void IntBST::bfsHelper(Node* n, vector<int>& v, int targetDepth, int currentDepth) const{ //helper 
  if (n == nullptr) { //nullnode
    return; //stop
  }
  if (currentDepth == targetDepth) { //check if current level matches the target
    v.push_back(n->info); //push back the current value
    return; //stop
  } 
  bfsHelper(n->left, v, targetDepth, currentDepth + 1); //recurse left, updating current depth by one
  bfsHelper(n->right, v, targetDepth, currentDepth + 1); //recurse right, updating current depth by one
}
//it works 
//redo count: 1

int IntBST::kthLargest(int k) const{ //setup
  int kth_count = 0; //init kth count
  int kth_value = 0; //init kth value
  return kthLargestHelper(root, k, kth_count, kth_value); //call helper, recursive return 
}
int IntBST::kthLargestHelper(Node* n, int k_idx, int& count, int& k_val) const{ //helper (node, index, count, value)
  if (n == nullptr) { //null node
    return 0; //zero returned, do nothing
  }
  kthLargestHelper(n->right, k_idx, count, k_val); //go right
  if (count == k_idx) { //count matches desired index
    k_val = n->right->info; //update kval with current right
    return k_val; //stop and return, done with right case
  }
  count++; //add 1 to k count at every node
  if (count == k_idx) { //count matches desired index
    k_val = n->info; //node update
    return k_val; //stop and return, done with node case
  }
  kthLargestHelper(n->left, k_idx, count, k_val); //go left
  if (count == k_idx) { //count matches desired index
    k_val = n->left->info; //left node update
    return k_val; //stop and return
  }
  return 0; //if all else fails, no kth larges
}




int IntBST::countInRange(int low, int high) const { 
  int count = 0; //init local 
  return inOrderHelperCount(root, count, low, high); //return in order helper
}

int IntBST::inOrderHelperCount(Node* n, int& c, int min, int max) const{ //helper
  if (n == nullptr) { //null node
    return 0; //zero! didn't count anything!
  }
  inOrderHelperCount(n->left, c, min, max); //assume works left
  if (n->info >= min && n->info <= max) { //current node info needs to be between min and max (universal)
    c++; //add one to count (pass by reference)!
  }
  inOrderHelperCount(n->right, c, min, max); //assume it works for right case 
  return c; //return the c variable
}

//O(n), not O(h + k)
//function (int arr[], int n)
//for( int i = 0; i < n; i++) {
      //for int j = i+1; j < n; j++) {
           //









    
  










    
    
