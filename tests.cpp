// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
#include <sstream>
//Do not include set in this file

using namespace std;

void playGame(BST& a, BST& b) {
   while(1) {
     bool removeHappened = false; //init
    //alice turn
     for (auto it = a.begin(); it != a.end(); ++it) {
       if (b.contains(*it)) {
         cout << "Alice picked matching card " << *it << endl;
         b.remove(*it);
         a.remove(*it);
         removeHappened = true; //removed
         break;
       }
     }
    //bob turn
     for (auto it = b.rbegin(); it != b.rend(); ++it) { //back
       if (a.contains(*it)) {
         cout << "Bob picked matching card " << *it << endl;
         a.remove(*it);
         b.remove(*it);
         removeHappened = true; //removed
         break;
       }
     }
    //game over check
     if (!removeHappened) { //didn't remove
       return; //exit
     }
   }
}
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
  cout << "Single Node Iterator Tests" << endl;
  for (auto it = Cards.begin(); it != Cards.end(); ++it) {
    cout << *it << endl;
  }
  for (auto it = Cards.rbegin(); it != Cards.rend(); ++it) {
    cout << *it << endl;
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
  cout << "Testing Multiple Nodes" << endl;
  for (auto it = Cards.begin(); it != Cards.end(); ++it) {
    cout << *it << endl;
  }
  cout << endl;
  auto it = Cards.end();
  while (it != Cards.begin()) {
    --it;
    cout << *it << endl;
  }
  
  cout << endl;
  
  //test equal
  if (it == Cards.begin()) {
    cout << "== works!" << endl;
  }  
  cout << endl;
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
  for (auto it = Cards.begin(); it != Cards.end(); ++it) {
    cout << *it << endl;
  }
  cout << endl;
  it = Cards.end();
  while (it != Cards.begin()) {
    --it;
    cout << *it << endl;
  }
  cout << endl;
  Cards.printInOrder();  
  //test remove cards that exist
  if (Cards.remove(c1)) {
    cout << "Card removed!" << endl;
  }
  Cards.printInOrder();
  if (Cards.remove(c2)) {
    cout << "Card removed!" << endl;
  }
  for (auto it = Cards.begin(); it != Cards.end(); ++it) {
    cout << *it << endl;
  }
  cout << endl;
  it = Cards.end();
  while (it != Cards.begin()) {
    --it;
    cout << *it << endl;
  }
  cout << endl;
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
  
  //testing playGame (one empty)
  cout << "Playing the Game (one empty)" << endl;
  BST a_cards;
  BST b_cards;
  Card a1("a", 's');
  a_cards.insert(a1);
  playGame(a_cards,b_cards);
  a_cards.printInOrder();
  b_cards.printInOrder();
  
  //testing playGame (common cards)
  cout << "Playing the Game (common cards)" << endl;
  Card a2("3", 'd');
  Card b1("a", 's');
  Card b2("6", 'h');
  a_cards.insert(a2);
  b_cards.insert(b1);
  b_cards.insert(b2);
  playGame(a_cards,b_cards);
  a_cards.printInOrder();
  b_cards.printInOrder();
  
  //now, no matching cards after common cards are removed!
  cout << "Playing the Game (no matching cards)" << endl;
  playGame(a_cards,b_cards);
  a_cards.printInOrder();
  b_cards.printInOrder();  
 



}
