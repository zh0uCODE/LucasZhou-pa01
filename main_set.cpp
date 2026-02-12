// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
#include <sstream>
using namespace std;
void playGame(set<Card>& a, set<Card>& b) {
   while(1) {
     bool removeHappened = false; //init
    //alice turn
     for (auto it = a.begin(); it != a.end(); ++it) {
       if (b.contains(*it)) {
         cout << "Alice picked matching card " << *it << endl;
         b.erase(*it);
         a.erase(*it);
         removeHappened = true; //removed
         break;
       }
     }
    //bob turn
     for (auto it = b.rbegin(); it != b.rend(); ++it) { //back
       if (a.contains(*it)) {
         cout << "Bob picked matching card " << *it << endl;
         a.erase(*it);
         b.erase(*it);
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
/*

  //testing val helper
  Card c1("a",'d');
  cout << c1.cardOrderHelper() << endl; 
  
  //print cards test
  cout << c1 << endl;
  
  //test operator ==
  Card c2("7",'c');
  cout << (c1 == c2) << endl;
    
  //test operator <
  cout << (c1 < c2) << endl;

  //test operator >
  cout << (c1 > c2) << endl;

*/
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  set<Card> aliceCards; //set for alice cards
  set<Card> bobCards; //set for bob cards

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
  }
  cardFile1.close();

  cout << endl;
  while (getline (cardFile2, line) && (line.length() > 0)){ 
    char suit;
    string value;
    stringstream ss(line);
    ss >> suit >> value;
    Card c(value, suit);
    bobCards.insert(c);
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


