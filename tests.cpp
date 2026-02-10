// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
#include <sstream>
//Do not include set in this file

using namespace std;
int main(int argv, char** argc){
  BST Cards; //general bst card for tests
  
  //testing empty BST
  Card c1("a",'d'); 
  if (!Cards.contains(c1)) { 
    cout << "PASSED empty test" << endl;
  }
  
  //testing single node
  if (Cards.insert(c1) == true) {
    cout << "PASSED insert test" << endl;
  }
  
  //testing multiple nodes
  Card c2("5",'h');
  if (Cards.insert(c2) == true) {
    cout << "PASSED multiple node test (added another node)" << endl;
  }
  Card c5("8",'d');
  if (Cards.insert(c5) == true) {
    cout << "PASSED multiple node test (added another node)" << endl;
  }
  Card c6("9",'s');
  if (Cards.insert(c6) == true) {
    cout << "PASSED multiple node test (added another node)" << endl;
  }
  
  //test contains
  Card c1("a",'d');
  if (Cards.contains(c1)) {
    cout << "This card is in the list" << endl;
  }
  Card c1("a",'d');
  if (Cards.contains(c1)) {
    cout << "This card is in the list" << endl;
  }
  Card c1("a",'d');
  if (Cards.contains(c1)) {
    cout << "This card is in the list" << endl;
  }
  Card c1("a",'d');
  if (Cards.contains(c1)) {
    cout << "This card is in the list" << endl;
  }  

  //test remove non-existent card
  Card c3("6",'s');
  if (!Cards.remove(c3)) {
    cout << "This card is not in the list!" << endl;
  }
  
  
  //test duplicate insert
  Card c4("a",'d');
  if (!Cards.insert(c4)) {
    cout << "Cannot insert duplicate card!" << endl;
  }


 



}
