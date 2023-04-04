#include <iostream>
#include <vector>
#include <string>

#define PRIME 13
#define BIG_PRIME 2'147'483'647

using namespace std;

int computeHash(const string& inputString, int length) {
    int hashValue = 0;

    for (int i = 0; i < length; i++) {
        hashValue = (hashValue * PRIME + inputString.at(i)) % BIG_PRIME; // Modified: adding mod prime number
    }

    return hashValue;
}

int computePower(int length) {
    int power = 1;

    for (int i = 0; i < length - 1; i++) {
        power = (power * PRIME) % BIG_PRIME;

        cout << power << endl;
    }

    return power;
}

bool equals(string text, string pattern, int startingIndex) {
    for (int i = 0; i < pattern.length(); i++) {
        if (text.at(startingIndex + i) != pattern.at(i)) {
            return false;
        }
    }

    return true;
}

vector<int> stringMatch(const string &text, const string &pattern) {
    vector<int> indexes;

    int textLength = text.length();
    int patternLength = pattern.length();

    int patternHash = computeHash(pattern, patternLength);
    int textHash = computeHash(text, patternLength);

    int power = computePower(patternLength);

    for (int i = 0; i < textLength - patternLength + 1; i++) {
        if (textHash == patternHash) {
            if (equals(text, pattern, i)) {
                indexes.push_back(i);
            }
        }

        if (i < textLength - patternLength) {
            textHash = (((textHash - text.at(i) * power) * PRIME) % BIG_PRIME + text.at(i + patternLength)) % BIG_PRIME;
        }
    }

    return indexes;
}

template<class T>
void print(vector<T> dynamicArray) {
    for (auto i : dynamicArray) {
        cout << i << " ";
    }
}

int main() {
    string text = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    string searchedPattern = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

    vector<int> indexes = stringMatch(text, searchedPattern);

    cout << "Text: " << text << endl;
    cout << "Searched pattern: " << searchedPattern << endl;

    cout << "Pattern matches at: ";
    print(indexes);

    return 0;
}