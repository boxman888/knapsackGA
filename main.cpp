/***********************************************
* Created: 10/3/2020
* Auther:  Ethan Patterson
************************************************
* Discription
* Genetic Algorithm for solving the
* knapsack problem.
************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>

#include "Box.h"
#include "SpawnPool.h"

Box* buildBox(int value, int weight) {
    Box* box = new Box(value, weight);
    return box;
}

int main()
{
    std::vector<Box*> boxStack;
    for (int i = 0; i < 30; i++){
       int value = rand() % 10 + 1;
       int weight = rand() % 15;

        Box* box = buildBox(value, weight);
        boxStack.push_back(box);
    }
    SpawnPool pool(boxStack, 16, 50);
    pool.run(100);

    return 0;
}