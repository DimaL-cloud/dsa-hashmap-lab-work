#ifndef LAB2_MINISTER_H
#define LAB2_MINISTER_H

#include <string>

struct Minister {
private:
    std::string name;
    std::string politicalParty;
    int corruptionCases;

public:
    Minister();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getPoliticalParty() const;

    void setPoliticalParty(const std::string &politicalParty);

    int getCorruptionCases() const;

    void setCorruptionCases(int corruptionCases);
};

#endif //LAB2_MINISTER_H
