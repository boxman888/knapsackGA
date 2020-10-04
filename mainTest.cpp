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

#include "Box.h"
#include "SpawnPool.h"

int main()
{
    // START of test setup
    // temp weight and values for testing,
    // will be randomized later for larger sets.
    int tempVal[] = {5, 2, 3, 2};
    int tempWgt[] = {1, 4, 2, 3};

    std::vector<Box*> boxStack;
    for (int i = 0; i < 4; i++){
        Box* box = new Box(tempVal[i], tempWgt[i]);
        boxStack.push_back(box);
    }
    std::sort(boxStack.begin(), boxStack.end());

    std::cout << "Boxes created: " << std::endl;
    for (size_t i = 0; i < boxStack.size(); i++){
        std::cout << boxStack[i] -> getValue() << std::endl;
    }
    // END of test setup.
    SpawnPool pool(boxStack, 8, 8);
    pool.run(250);

    return 0;
}
