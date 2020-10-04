#include "Box.h"

Box::Box(int value, int weight) {
    this -> value = value;
    this -> weight = weight;
}

int Box::getValue() {
    return this -> value;
}

int Box::getWeight() {
    return this -> weight;
}

bool Box::operator<(Box& b) const{
    if (this -> value < b.getValue())
        return true;
    else
        return false;
}

