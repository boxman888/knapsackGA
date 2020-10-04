/***********************************************
* Created: 10/3/2020
* Auther:  Ethan Patterson
************************************************
* Discription
* Boxes are used to hold the weight and value
* of treasure.
************************************************/

#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box {
    private:
        int value;
        int weight;

    public:
        Box(int value, int weight);
        int getValue();
        int getWeight();
        bool operator<(Box& b) const;
};

#endif