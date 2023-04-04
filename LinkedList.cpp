#include "headers/LinkedList.h"

HashNode::HashNode(long long int key, const Minister &minister, HashNode *next) : key(key), minister(minister),
                                                                                   next(next) {}

long long int HashNode::getKey() const {
    return key;
}

void HashNode::setKey(long long int key) {
    HashNode::key = key;
}

void HashNode::setMinister(const Minister &minister) {
    HashNode::minister = minister;
}

HashNode *HashNode::getNext() const {
    return next;
}

void HashNode::setNext(HashNode *next) {
    HashNode::next = next;
}

Minister *HashNode::getMinister() {
    return &minister;
}

LinkedList::LinkedList() {
    head = nullptr;

    listSize = 0;
}

LinkedList::~LinkedList() {
    HashNode *currentNode = head;
    HashNode *previousNode;

    while (currentNode != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->getNext();

        delete previousNode;
    }
}

void LinkedList::push_front(long long key, const Minister &minister) {
    if (head == nullptr) {
        head = new HashNode(key, minister, nullptr);
    } else {
        HashNode *oldHead = head;
        head = new HashNode(key, minister, oldHead);
    }

    listSize++;
}

void LinkedList::pop_front() {
    HashNode *nextHead = head->getNext();

    delete head;
    head = nextHead;

    listSize--;
}

Minister *LinkedList::get(long long key) {
    HashNode *currentNode = head;

    while (currentNode != nullptr) {
        if (currentNode->getKey() == key) {
            return currentNode->getMinister();
        }

        currentNode = currentNode->getNext();
    }

    return nullptr;
}

int LinkedList::size() const {
    return listSize;
}

long long LinkedList::getFrontElementKey() {
    return head->getKey();
}

void LinkedList::remove(long long int key) {
    if (head->getKey() == key) {
        HashNode *headNext = head->getNext();
        delete head;
        head = headNext;
    } else {
        HashNode *nodeBeforeDeletedNode = head;

        while (nodeBeforeDeletedNode->getNext()->getKey() != key) {
            nodeBeforeDeletedNode = nodeBeforeDeletedNode->getNext();
        }

        HashNode *deletedNode = nodeBeforeDeletedNode->getNext();
        nodeBeforeDeletedNode->setNext(deletedNode->getNext());
        delete deletedNode;
    }

    listSize--;
}


