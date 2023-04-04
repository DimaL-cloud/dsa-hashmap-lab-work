#ifndef LAB2_OPENADDRESSINGHASHMAP_H
#define LAB2_OPENADDRESSINGHASHMAP_H

#include "Minister.h"

#define INITIAL_CAPACITY 11
#define MAX_LOAD_FACTOR 0.5

struct HashEntry {
private:
    long long key = -1;
    Minister minister;
    bool removed = false;

public:
    HashEntry();

    HashEntry(long long key, const Minister &minister, bool active);

    long long getKey() const;

    void setKey(long long key);

    Minister *getMinister();

    void setMinister(const Minister &minister);

    bool isRemoved() const;

    void setRemoved(bool removed);
};

struct OpenAddressingHashMap {
private:
    int capacity = INITIAL_CAPACITY;
    int elementsAmount = 0;

    HashEntry *entriesArray;

public:
    OpenAddressingHashMap();

    virtual ~OpenAddressingHashMap();

    void insert(long long key, const Minister& minister);

    Minister *find(long long key) const;

    void erase(long long key);

    int size() const;

private:
    int hashIndex(long long key) const;

    int hashStep(long long key) const;

    void relocateMemory();
};


#endif //LAB2_OPENADDRESSINGHASHMAP_H
