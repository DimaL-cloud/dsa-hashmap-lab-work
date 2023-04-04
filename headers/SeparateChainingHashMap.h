#ifndef LAB2_SEPARATECHAININGHASHMAP_H
#define LAB2_SEPARATECHAININGHASHMAP_H

#include "LinkedList.h"

#define INITIAL_CAPACITY 11
#define MAX_LOAD_FACTOR 0.75

struct SeparateChainingHashMap {
private:
    int capacity = INITIAL_CAPACITY;
    int elementsAmount = 0;

    LinkedList *bucketsArray;

public:
    SeparateChainingHashMap();

    virtual ~SeparateChainingHashMap();

    void insert(long long key, const Minister& minister);

    Minister *find(long long key);

    void erase(long long key);

    int size() const;

private:
    int hash(long long key) const;

    void relocateMemory();
};

#endif //LAB2_SEPARATECHAININGHASHMAP_H
