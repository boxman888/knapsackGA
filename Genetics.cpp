#include "Genetics.h"

Genetics::Genetics(int size) {
    this -> fitness = 0;
    this -> genomeSize = size;
    this -> genome = new int[size];
}

bool Genetics::transformation(int *genome, int size){
    if (size != genomeSize){
        std::cout << "Bad genomeSize." <<std::endl;
        return false;
    }

    delete[] this -> genome;
    this -> genome = genome;

    return true;
}

bool Genetics::randomGen() {
    for (int i = 0; i < genomeSize; i++) {
        genome[i] = round((float) rand()/RAND_MAX);
    }

    return true;
}
// Breeds this object with that of another of the same type.
// @param parent, other organism to breed.
// @param mix, which parent to mix from first.
// Allows you to state order of the genome inherited.

// Example: p1 : [0,1,0,1], p2: [1,1,0,0]
// delimiter = 50%
// mix = true. child = [0,1,0,0]
// mix = false. child = [1,1,0,1]

// @param delimiter, set the delimiter for the split between the two organisms.
// delimiter reads left to right.
// This will usally be a 50% split between the two.
// Returns child of this and that of same type.
Genetics* Genetics::breed(Genetics* parent, bool mix, int delimiter) {
    Genetics* child = new Genetics(genomeSize);
    int* cross;
    if (mix) { 
        cross = splice(this->genome, parent -> getGenome(), delimiter);
    }
    else{
        cross = splice(parent -> getGenome(), this->genome, delimiter);
    }

    child -> transformation(cross, genomeSize);
    return child;
}

int* Genetics::splice(int *left, int *right, int delimiter) {
    int* cross = new int[genomeSize];
    for(int i = 0; i < delimiter; i++){
        cross[i] = left[i];
    }
    for (int i = delimiter; i < genomeSize; i++){
        cross[i] = right[i];
    }

    return cross;
}

// Mutat the genetic code.
// @param thresh is the upper probability limit for a single
// muation to occure at each gene.
// Returns number of mutations to occure.
int Genetics::mutation(float thresh) {
    int count = 0;
    for (int i = 0; i < genomeSize; i++) {
        float prob = (float) rand()/RAND_MAX;
        
        if (prob <= thresh) {
            if (genome[i] == 0)
                genome[i] = 1;
            else
                genome[i] = 0;
            count++;
        }
    }
    return count;
}

void Genetics::setFitness(int score) {
    fitness = score;
}

int Genetics::getFitness() {
    return fitness;
}

int Genetics::getGenomeSize(){
    return genomeSize;
}

int* Genetics::getGenome() {
    return genome;
}

void Genetics::printDNA() {
    for (int i = 0; i < genomeSize; i++){
        std::cout << genome[i] << " ";
    }
    std::cout << "\n" << std::endl;
}

bool Genetics::operator<(Genetics& b) const{
    if (this -> fitness < b.getFitness())
        return true;
    else
        return false;
}

Genetics::~Genetics(){
    delete[] genome;
}