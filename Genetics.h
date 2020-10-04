/***********************************************
* Created: 10/3/2020
* Auther:  Ethan Patterson
************************************************
*
************************************************/
#ifndef GENETICS_H
#define GENETICS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Genetics{
    private:
        int fitness; // fitness score.
        int genomeSize;
        int* genome;

        int* splice(int* left, int* right, int delimiter);
    public:
        Genetics(int size);

        bool randomGen();
        bool transformation(int *genome, int size);
        
        Genetics* breed(Genetics* parent, bool mix, int delimiter);

        void printDNA();
        void setFitness(int score);
        int mutation(float thresh);
        int getGenomeSize();
        int getFitness();
        int* getGenome();
        bool operator<(Genetics& b) const;
        
        ~Genetics();
};
#endif