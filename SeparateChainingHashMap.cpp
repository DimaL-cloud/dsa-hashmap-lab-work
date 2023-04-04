#include "headers/SeparateChainingHashMap.h"

using namespace std;

SeparateChainingHashMap::SeparateChainingHashMap() {
    bucketsArray = new LinkedList[INITIAL_CAPACITY];
}

SeparateChainingHashMap::~SeparateChainingHashMap() {
    delete[] bucketsArray;
}

int SeparateChainingHashMap::hash(long long int key) const {
    return (int) (key % capacity);
}

void SeparateChainingHashMap::relocateMemory() {
    int oldCapacity = capacity;
    capacity = capacity * 2 + 1; // prime numbers are always odd. Thus, we add one to not have even capacity

    LinkedList *oldBucketsArray = bucketsArray;
    LinkedList *newBucketsArray = new LinkedList[capacity];
    bucketsArray = newBucketsArray;

    for (int i = 0; i < oldCapacity; i++) {
        LinkedList *oldList = &oldBucketsArray[i];

        while (oldList->size() > 0) {
            long long key = oldList->getFrontElementKey();

            int index = hash(key);
            LinkedList *list = &bucketsArray[index];

            list->push_front(key, *oldList->get(key));

            oldList->pop_front();
        }
    }

    delete[] oldBucketsArray;
}

void SeparateChainingHashMap::insert(long long int key, const Minister& minister) {
    double loadFactor = (double) elementsAmount / capacity;

    if (loadFactor >= MAX_LOAD_FACTOR) {
        relocateMemory();
    }

    int index = hash(key);
    LinkedList *list = &bucketsArray[index];

    Minister *ministerByKey = find(key);

    if (ministerByKey == nullptr) {
        list->push_front(key, minister);

        elementsAmount++;
    } else *ministerByKey = minister;
}

Minister *SeparateChainingHashMap::find(long long int key) {
    int index = hash(key);
    LinkedList *list = &bucketsArray[index];

    return list->get(key);
}

void SeparateChainingHashMap::erase(long long int key) {
    int index = hash(key);

    LinkedList *list = &bucketsArray[index];

    if (list->get(key) != nullptr) {
        list->remove(key);
        elementsAmount--;
    }
}

int SeparateChainingHashMap::size() const {
    return elementsAmount;
}

