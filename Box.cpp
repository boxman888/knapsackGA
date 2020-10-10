/***********************************************
* Created: 10/3/2020
* Auther:  Ethan Patterson
************************************************
* Discription
* Boxes are used to hold the weight and value
* of treasure.
************************************************/
#include "Box.h"
/*
* Constructor for Box.
* @param value, value of item.
* @param weight, weight of item.
*/
Box::Box(int value, int weight) {
    this -> value = value;
    this -> weight = weight;
}
// Returns the value of the Box.
int Box::getValue() {
    return this -> value;
}
// Returns the weight of a Box.
int Box::getWeight() {
    return this -> weight;
}
// Overload operator used for sorting.
bool Box::operator<(Box& b) const{
    if (this -> value < b.getValue())
        return true;
    else
        return false;
}

