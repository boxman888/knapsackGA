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
#include "omp.h"

Box* buildBox(int value, int weight) {
    Box* box = new Box(value, weight);
    return box;
}

int main()
{
    int results[3];
    std::vector<Box*> boxStack;

    for (int i = 0; i < 30; i++){
       int value = rand() % 10 + 1;
       int weight = rand() % 15;

        Box* box = buildBox(value, weight);
        boxStack.push_back(box);
    }

    omp_set_num_threads(3);
    #pragma omp parallel sections
    {   
	#pragma omp section
	{
            SpawnPool pool_1(boxStack, 16, 50);
	    results[0] = pool_1.run(100);
	}
	#pragma omp section
	{
	    SpawnPool pool_2(boxStack, 16, 50);
	    results[1] = pool_2.run(100);
	}
	#pragma omp section
	{
	    SpawnPool pool_3(boxStack, 16, 50);
	    results[2] = pool_3.run(100);
	}
    }// implied barrier. All functions must return in order to move forward.

    int max = 0;
    for (int i = 0; i < 3; i++){
    	if (max < results[i])
	    max = results[i];
    }
    std::cout << "Best fitness value is: " << max << std::endl;

    return 0;
}
