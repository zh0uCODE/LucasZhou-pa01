// card.cpp
// Author: Lucas Zhou
// Implementation of the classes defined in card.h
#include <ostream> 
#include "card.h"

bool Card::operator==(const Card& other) const{ //equal equal
  if (this->cardOrderHelper() == other.cardOrderHelper()) { //value and suit equal
    return true; //true
  } else { //not
    return false; //false
  }
} //it works

bool Card::operator<(const Card& other) const{ //less than (check if self is less than other!)
  if (this->cardOrderHelper() < other.cardOrderHelper()) { //value and suit equal
    return true; //true
  } else { //not
    return false; //false
  }
}
//it works

bool Card::operator>(const Card& other) const{ //greater than
  if (this->cardOrderHelper() > other.cardOrderHelper()) { //value and suit equal
    return true; //true
  } else { //not
    return false; //false
  }
}
//it works

std::ostream& operator<<(std::ostream& os, const Card& c) { //global overloading the print function
  os << c.suit << " " << c.value; //modify the print
  return os; //return the object
}
