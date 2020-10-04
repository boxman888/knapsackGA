/***********************************************
* Created: 10/3/2020
* Auther:  Ethan Patterson
************************************************
*
************************************************/

#ifndef SPAWNPOOL_H
#define SPAWNPOOL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

#include "Box.h"
#include "Genetics.h"

class SpawnPool{
    private:
        int capacity;
        size_t population;
        std::vector<Box*>& boxStack;
        std::vector<Genetics*> spawn;

        int Grade(Genetics* gene);
        Genetics* breed(Genetics* org1, Genetics* org2, bool asexual);

    public:
        SpawnPool(std::vector<Box*> &stack, int population, size_t capacity);
        void initPopulation();
        void printSpawns();
        void Dual(size_t rate);
        void run(int generations);
};

#endif