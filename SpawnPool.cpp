/***********************************************
* Created: 10/3/2020
* Auther:  Ethan Patterson
************************************************
*
************************************************/
#include "SpawnPool.h"

SpawnPool::SpawnPool(std::vector<Box*> &stack, int population, size_t capacity) : boxStack(stack) {
    this -> population = population;
    this -> capacity = capacity;
}

static bool compareFitness(Genetics* a, Genetics *b) {
    return (a->getFitness() > b -> getFitness());
}

int SpawnPool::Grade(Genetics* org) {
    int* gene = org -> getGenome();
    int score = 0;
    int weight = 0;

    for (size_t i = 0; i < boxStack.size(); i++) {
        if (gene[i]) { 
            score += boxStack[i]->getValue();
            weight += boxStack[i]->getWeight();
        }
    }
    if (weight > capacity)
        score = 0;

    org -> setFitness(score);
    return score;
}

void SpawnPool::initPopulation(){
    for (size_t i = 0; i < population; i++){
        Genetics* org = new Genetics(boxStack.size());
        org->randomGen();
        Grade(org);
        spawn.push_back(org);
    }
}

void SpawnPool::printSpawns() {
    for (size_t i = 0; i < spawn.size(); i++) {
        std::cout << i << ": ";
        spawn[i] -> printDNA();
    }
}

// Pick n random pairs of organisms to dual.
// The ones that survive will be alowed to breed the
// new spawn population.
// The selection process for duling is random.
//@param rate, % of population that can be selected. 
void SpawnPool::Dual(size_t rate) {
    std::vector<Genetics*> winners;
    std::vector<Genetics*> children;

    int org1, org2;
    while (winners.size() < rate) {
        org1 = rand() % spawn.size();
        org2 = rand() % spawn.size();

        if (spawn[org1]->getFitness() < spawn[org2]->getFitness())
            winners.push_back(spawn[org2]);
        else
            winners.push_back(spawn[org1]);
    }

    while (children.size() < population) {
        org1 = rand() % winners.size();
        org2 = rand() % winners.size();

        Genetics* child = breed(winners[org1], winners[org2], org1 == org2);
        children.push_back(child);
    }
    //std::cout << "Old spawn size: " << spawn.size() <<std::endl;

    manageSpawn(children);
    //std::cout << "new spawn size: " << spawn.size() <<std::endl;
}

void SpawnPool::manageSpawn(std::vector<Genetics*> &children) {
    for (size_t i = children.size(); i > 1; i--) {
        Genetics* p = spawn[i];
        delete p;
        spawn.pop_back();
    }

    for (size_t i = spawn.size(); i < children.size(); i++){
        spawn.push_back(children[i]);
    }

}

Genetics* SpawnPool::breed(Genetics* org1, Genetics* org2, bool asexual) {
    int del = (int)round(org1->getGenomeSize() * 0.50);
    Genetics* child = org1->breed(org2, asexual, del);
    
    child->mutation(0.1);
    Grade(child);

    return child;
}

int SpawnPool::run(int generations) {
    initPopulation();
    sort(spawn.begin(), spawn.end(), compareFitness);

    for (int i = 0; i < generations; i++) {
        Dual((size_t)ceil((float) population * 0.25));
        sort(spawn.begin(), spawn.end(), compareFitness);
    
       /* std::cout << "Best orginism score is: " << spawn[0] -> getFitness() << std::endl;
        std::cout << "Orginism's DNA is: ";
        int* dna = spawn[0] -> getGenome();
        for (int i = 0; i < spawn[0] -> getGenomeSize(); i++) {
            std::cout << dna[i] << " ";
        }*/
        //std::cout << "\n" << std::endl;
    }

    return spawn[0] -> getFitness();
}
