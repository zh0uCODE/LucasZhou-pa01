// card.h
// Author: Lucas Zhou
// All class declarations related to defining a single card go here
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;
class Card { //class card
  public: //private var
//A 2 3 4 5 6 7 8 9 10 J Q K
//C D S H 
    string value; //value of card
    char suit;  //suit 
    int valueHelper() const {
      if (value == "a") {
        return 1;
      } else if (value == "j") {
        return 11;
      } else if (value == "q") {
        return 12;
      } else if (value == "k") {
        return 13;
      } else {
        return stoi(value);
      }
    }
    int rankHelper() const { //get rank order
      switch(suit){ //options
        case 'c' : return 100; //c is first
        case 'd' : return 200; //d is second
        case 's' : return 300; //s is third
        case 'h' : return 400; //h is fourth
      }
      return -1; //none? return -1 (error, cant find it!)
    }
    int cardOrderHelper() const {
      return valueHelper() + rankHelper();
    }

  //public: //methods
    Card() = default; //unparameterized (don't plan to implement)
    Card(string v, char s) : value(v), suit(s) {} //parameterized
    bool operator==(const Card& other) const; //== (takes another card obj) (const card = can't modify the card, also can't modify variables out of scope - local, not global)
    bool operator>(const Card& other) const;  //> 
    bool operator<(const Card& other) const; //<
    friend ostream& operator<<(ostream& os, const Card& c); //print //friend function
};


#endif



