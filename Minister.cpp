#include "headers/Minister.h"

using namespace std;

Minister::Minister() {
    string names[] = {
            "Arkadiy", "Artem", "Arseniy",
            "Vladislav", "Volodymyr", "Vsevolod",
            "Evgeniy", "Egor"
    };

    string politicalParties[] {
        "Sun", "Free country", "Happy future"
    };

    this->name = names[rand() % names->size()];
    this->politicalParty = politicalParties[rand() % politicalParties->size()];
    this->corruptionCases = rand() % 5;
}

const string &Minister::getName() const {
    return name;
}

void Minister::setName(const string &name) {
    Minister::name = name;
}

const string &Minister::getPoliticalParty() const {
    return politicalParty;
}

void Minister::setPoliticalParty(const string &politicalParty) {
    Minister::politicalParty = politicalParty;
}

int Minister::getCorruptionCases() const {
    return corruptionCases;
}

void Minister::setCorruptionCases(int corruptionCases) {
    Minister::corruptionCases = corruptionCases;
}

