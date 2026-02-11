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
  cout << "Empty List Iterator Tests" << endl;
  for (auto it = Cards.begin(); it != Cards.end(); ++it) {
    cout << *it << endl;
  }
  for (auto it = Cards.rbegin(); it != Cards.rend(); ++it) {
    cout << *it << endl;
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
  Card c7("2",'s');
  Cards.insert(c7);
  if (Cards.contains(c2)) {
    cout << "This card is in the list" << endl;
  }
  if (Cards.contains(c5)) {
    cout << "This card is in the list" << endl;
  }
  if (Cards.contains(c6)) {
    cout << "This card is in the list" << endl;
  }
  if (Cards.contains(c7)) {
    cout << "This card is in the list" << endl;
  }  

  //test remove non-existent card
  Card c3("6",'s');
  if (!Cards.remove(c3)) {
    cout << "This card is not in the list!" << endl;
  }
  Cards.printInOrder();  
  //test remove cards that exist
  if (Cards.remove(c1)) {
    cout << "Card removed!" << endl;
  }
  Cards.printInOrder();
  if (Cards.remove(c2)) {
    cout << "Card removed!" << endl;
  }
  if (Cards.remove(c5)) {
    cout << "Card removed!" << endl;
  }
  Cards.printInOrder();
  if (Cards.remove(c6)) {
    cout << "Card removed!" << endl;
  }
  Cards.printInOrder();

  //test duplicate insert
  Card c4("a",'d');
  if (!Cards.insert(c4)) {
    cout << "Cannot insert duplicate card!" << endl;
  }
  Cards.printInOrder();


 



}
