#include "SpawnPool.h"

SpawnPool::SpawnPool(std::vector<Box*> &stack, int population, size_t capacity) : boxStack(stack) {
    this -> population = population;
    this -> capacity = capacity;
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
    std::sort(winners.begin(), winners.end());
    children.push_back(winners[0]); //Elitism, strongest moves to next generation.

    while (children.size() < population) {
        org1 = rand() % winners.size();
        org2 = rand() % winners.size();

        Genetics* child = breed(winners[org1], winners[org2], org1 == org2);
        children.push_back(child);
    }

    spawn.swap(children);
    winners.clear();
    children.clear();
}

Genetics* SpawnPool::breed(Genetics* org1, Genetics* org2, bool asexual) {
    int del = (int)round(org1->getGenomeSize() * 0.50);
    Genetics* child = org1->breed(org2, asexual, del);
    
    child->mutation(0.1);
    Grade(child);

    return child;
}

void SpawnPool::run(int generations) {
    initPopulation();
    for (int i = 0; i < generations; i++)
        Dual((size_t)ceil((float) population * 0.25));
    sort(spawn.begin(), spawn.end());

    std::cout << "Best orginism score is: " << spawn[0] -> getFitness() << std::endl;
    std::cout << "Orginism's DNA is: ";
    int* dna = spawn[0] -> getGenome();
    for (int i = 0; i < spawn[0] -> getGenomeSize(); i++) {
        std::cout << dna[i] << " ";
    }
    std::cout << "\n" << std::endl;
}