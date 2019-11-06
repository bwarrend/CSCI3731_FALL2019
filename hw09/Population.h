#ifndef POPULATION_H
#define POPULATION_H
class Fish;

//Class Population
//
//
class Population {

private:

    Fish** fishList;
    int maxFishes;
    int popCount;
        

public:

    Population(int maxFishes);

    void addFish(Fish* fish);
    void printSomething() const;
    void removeFish(int index);
    void removeFish(Fish* fish);
    const int getPopCount() const;
    const int getMaxFishes() const;
    Fish* getFish(int index) const;

    virtual ~Population();
};

void cls();
int rRange(int min, int max);


#endif