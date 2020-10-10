/***********************************************
* Created: 10/3/2020
* Auther:  Ethan Patterson
************************************************
* Handles the genetics of an orginism.
* Modifies the anyting relating to DNA.
************************************************/
#ifndef GENETICS_H
#define GENETICS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Genetics{
    private:
        int fitness; // Fitness score.
        int genomeSize; // Size of the genome/chromosomes.
        int* genome; // Holdes the genome/chromosomes.
        
        /* Used to splice chromosomes togeather.
        * @Param left, Parant chromosome,
        * @Param right,
        * @Param dilimiter,
        * Output is new chromosome.
        */ 
        int* splice(int* left, int* right, int delimiter);
    public:
        Genetics(int size);

        // Genereates a random genome.
        // Used for init.
        bool randomGen();

        // Physicly scoop out the DNA of an orginism and
        // Manually set a new one.
        // @Param genome, genome to insert to the organism.
        // Size of the new genome.
        bool transformation(int *genome, int size);

        // Breeds this object with that of another of the same type.
        // @Param parent, other organism to breed.
        // @Param mix, which parent to mix from first.
        // Allows you to state order of the genome inherited.

        // Example: p1 : [0,1,0,1], p2: [1,1,0,0]
        // delimiter = 50%
        // mix = true. child = [0,1,0,0]
        // mix = false. child = [1,1,0,1]

        // @Param delimiter, set the delimiter for the split between the two organisms.
        // delimiter reads left to right.
        // This will usally be a 50% split between the two.
        // Returns child of this and that of same type.
        Genetics* breed(Genetics* parent, bool mix, int delimiter);
        
        // Prints the DNA of the orginism.
        void printDNA();
        
        // Sets the fitness level of the orginism.
        // @Param score, score value to set for the orginism.
        void setFitness(int score);

        // Mutat the genetic code.
        // @Param thresh, is the upper probability limit for a single
        // muation to occure at each gene.
        // Returns number of mutations to occure.
        int mutation(float thresh);

        // Return Genome/Chromosome size.
        int getGenomeSize();
        // Return the fitness level.
        int getFitness();
        // Return the Genome.
        // WARNING, modifying this pointer will modify the genome.
        int* getGenome();

        // Operator overload for sorting.
        bool operator<(Genetics& b) const;
        
        // Destructor.
        ~Genetics();
};
#endif