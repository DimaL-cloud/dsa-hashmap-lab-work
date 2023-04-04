#include "headers/OpenAddressingHashMap.h"

HashEntry::HashEntry() = default;

HashEntry::HashEntry(long long key, const Minister &minister, bool active) : key(key), minister(minister),
                                                                             removed(removed) {}

long long HashEntry::getKey() const {
    return key;
}

void HashEntry::setKey(long long key) {
    HashEntry::key = key;
}

Minister *HashEntry::getMinister() {
    return &minister;
}

void HashEntry::setMinister(const Minister &minister) {
    HashEntry::minister = minister;
}

bool HashEntry::isRemoved() const {
    return removed;
}

void HashEntry::setRemoved(bool removed) {
    HashEntry::removed = removed;
}

OpenAddressingHashMap::OpenAddressingHashMap() {
    entriesArray = new HashEntry[capacity];
}

OpenAddressingHashMap::~OpenAddressingHashMap() {
    delete[] entriesArray;
}

void OpenAddressingHashMap::insert(long long key, const Minister &minister) {
    double loadFactor = (double) elementsAmount / capacity;

    if (loadFactor >= MAX_LOAD_FACTOR) {
        relocateMemory();
    }

    int index = hashIndex(key);
    int step = hashStep(key);

    while (entriesArray[index].getKey() != -1 && !entriesArray[index].isRemoved() && entriesArray[index].getKey() != key) {
        index = (index + step) % capacity;
    }

    if (entriesArray[index].getKey() != key || entriesArray[index].isRemoved()) {
        elementsAmount++;
    }

    entriesArray[index].setKey(key);
    entriesArray[index].setMinister(minister);
    entriesArray[index].setRemoved(false);
}

Minister *OpenAddressingHashMap::find(long long key) const{
    int index = hashIndex(key);
    int step = hashStep(key);

    while (entriesArray[index].getKey() != -1) {
        if (entriesArray[index].getKey() == key && !entriesArray[index].isRemoved()) {
            return entriesArray[index].getMinister();
        }

        index = (index + step) % capacity;
    }

    return nullptr;
}

void OpenAddressingHashMap::erase(long long key) {
    int index = hashIndex(key);
    int step = hashStep(key);

    while (entriesArray[index].getKey() != -1) {
        if (entriesArray[index].getKey() == key && !entriesArray[index].isRemoved()) {
            entriesArray[index].setRemoved(true);
            elementsAmount--;
            return;
        }

        index = (index + step) % capacity;
    }
}

int OpenAddressingHashMap::size() const {
    return elementsAmount;
}

int OpenAddressingHashMap::hashIndex(long long key) const {
    return (int) (key % capacity);
}

int OpenAddressingHashMap::hashStep(long long key) const {
    return (int) 7 - (key % 7);
}

void OpenAddressingHashMap::relocateMemory() {
    int oldCapacity = capacity;
    capacity = capacity * 2;

    HashEntry *oldEntriesArray = entriesArray;
    entriesArray = new HashEntry[capacity];

    elementsAmount = 0;

    for (int i = 0; i < oldCapacity; i++) {
        if (oldEntriesArray[i].getKey() != -1 && !oldEntriesArray[i].isRemoved()) {
            insert(oldEntriesArray[i].getKey(), *oldEntriesArray[i].getMinister());
        }
    }

    delete[] oldEntriesArray;
}