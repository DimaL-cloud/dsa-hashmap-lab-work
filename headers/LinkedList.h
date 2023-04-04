#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include "Minister.h"

struct HashNode {
private:
    long long key;
    Minister minister;
    HashNode *next;

public:
    HashNode(long long int key, const Minister &minister, HashNode *next);

    long long int getKey() const;

    void setKey(long long int key);

    Minister *getMinister();

    void setMinister(const Minister &minister);

    HashNode *getNext() const;

    void setNext(HashNode *next);
};

struct LinkedList {
private:
    HashNode *head;

    int listSize;

public:
    LinkedList();

    virtual ~LinkedList();

    void push_front(long long key, const Minister& minister);

    void pop_front();

    void remove(long long key);

    long long getFrontElementKey();

    Minister *get(long long key);

    int size() const;
};


#endif //LAB2_LINKEDLIST_H
