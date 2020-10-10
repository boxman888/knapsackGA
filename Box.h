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
        int value; // Value of item.
        int weight; // Weight of item.

    public:
        /*
        * Constructor for Box.
        * @param value, value of item.
        * @param weight, weight of item.
        */
        Box(int value, int weight);
        // Returns the value of the Box.
        int getValue();
        // Returns the weight of a Box.
        int getWeight();
        // Overload operator used for sorting.
        bool operator<(Box& b) const;
};

#endif