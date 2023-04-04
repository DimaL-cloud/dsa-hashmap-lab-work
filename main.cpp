#include <iostream>
#include <unordered_map>

#include "headers/main.h"

#define MIN_DIGITS_AMOUNT 11
#define MAX_DIGITS_AMOUNT 15

using namespace std;

long long generateRandLong() {
    long long randomNumber = 0;

    int digitsAmount = MIN_DIGITS_AMOUNT +
                       rand() % (MAX_DIGITS_AMOUNT - MIN_DIGITS_AMOUNT + 1);

    long long rank = 1;

    for (int i = 0; i < digitsAmount; i++) {
        int randomDigit;

        if (i != digitsAmount - 1) {
            randomDigit = rand() % 10;
        } else randomDigit = 1 + rand() % 9;

        randomNumber += randomDigit * rank;
        rank *= 10;
    }

    return randomNumber;
}


template<class T>
bool testHashTable() {
    const int iters = 500'000;
    const int keysAmount = iters * 100;

    // generate random keys:
    long long *keys = new long long[keysAmount];

    long long *keysToInsert = new long long[iters];
    long long *keysToErase = new long long[iters];
    long long *keysToFind = new long long[iters];

    for (int i = 0; i < keysAmount; i++) {
        keys[i] = generateRandLong();
    }
    for (int i = 0; i < iters; i++) {
        keysToInsert[i] = keys[generateRandLong() % keysAmount];
        keysToErase[i] = keys[generateRandLong() % keysAmount];
        keysToFind[i] = keys[generateRandLong() % keysAmount];
    }

    // test my HashTable:
    T hashMap;

    clock_t myStart = clock();
    for (int i = 0; i < iters; i++) {
        hashMap.insert(keysToInsert[i], Minister());
    }
    int myInsertSize = hashMap.size();
    for (int i = 0; i < iters; i++) {
        hashMap.erase(keysToErase[i]);
    }
    int myEraseSize = hashMap.size();
    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++) {
        if (hashMap.find(keysToFind[i]) != NULL) {
            myFoundAmount++;
        }
    }
    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    // test STL hash table:
    unordered_map<long long, Minister> unorderedMap;

    clock_t stlStart = clock();
    for (int i = 0; i < iters; i++) {
        unorderedMap.insert({keysToInsert[i], Minister()});
    }
    int stlInsertSize = unorderedMap.size();
    for (int i = 0; i < iters; i++) {
        unorderedMap.erase(keysToErase[i]);
    }
    int stlEraseSize = unorderedMap.size();
    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++) {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end()) {
            stlFoundAmount++;
        }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

    cout << "My HashTable:" << endl;
    cout << "Time: " << myTime << ", after insert: " << myInsertSize << ", after erase: " << myEraseSize << ", found: "
         << myFoundAmount << endl;
    cout << "STL unordered_map:" << endl;
    cout << "Time: " << stlTime << ", after insert: " << stlInsertSize << ", after erase: " << stlEraseSize
         << ", found: " << stlFoundAmount << endl << endl;

    delete[] keys;
    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;

    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount) {
        cout << "The lab is completed" << endl;
        return true;
    }

    cerr << ":(" << endl;
    return false;
}

int main() {
    srand(time(nullptr));

    cout << "Separate chaining HashMap: " << endl;
    testHashTable<SeparateChainingHashMap>();

    cout << endl;

    cout << "Open addressing HashMap: " << endl;
    testHashTable<OpenAddressingHashMap>();

    return 0;
}
