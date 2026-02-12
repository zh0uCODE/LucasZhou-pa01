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
     for (auto it = b.rbegin(); it != b.rend(); --it) { //back
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
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  BST aliceCards; //set for alice cards
  BST bobCards; //set for bob cards
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }


  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit;
    string value;
    stringstream ss(line);
    ss >> suit >> value;
    Card c(value, suit);
    aliceCards.insert(c);
    //cout << suit << " " << value << endl;
  }
  cardFile1.close();
/*
  aliceCards.printInOrder();
  cout << endl;
  Card c1("a",'d');
  //BST::Node* p = aliceCards.getPredecessorNode(c1);
  //cout << p->c << endl; 
  //BST::Node* s = aliceCards.getSuccessorNode(c1);
  //cout << s->c << endl;
  aliceCards.remove(c1);
  aliceCards.printInOrder();
  cout << "Alice cards contains (c 4) " << aliceCards.contains(c1) << endl;
*/   
  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit;
    string value;
    stringstream ss(line);
    ss >> suit >> value;
    Card c(value, suit);
    bobCards.insert(c);
    //cout << suit << " " << value << endl;
  }
  cardFile2.close();
  playGame(aliceCards, bobCards);
  //print result
  //alice
  cout << endl;
  cout << "Alice's cards:" << endl;
  for (auto it = aliceCards.begin(); it != aliceCards.end(); ++it) {
    cout << *it << endl;
  }
  cout << endl;
  //bob
  cout << "Bob's cards: " << endl;
  for (auto it = bobCards.begin(); it != bobCards.end(); ++it) {
    cout << *it << endl;
  } 
  return 0;
}
