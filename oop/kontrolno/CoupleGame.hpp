#include "TVGame.hpp"

struct Pair {
    unsigned id1, id2;
};

class CoupleGame : public TVGame {
private:
    const int numOfParticipants = 12;
    const int numOfCouples = 6;
    Pair couples[6];
    bool find(int id) const;
public:
    CoupleGame(std::vector<Person*> participants, Person hostOfTheGame, Pair couples[6]);
    virtual void doEvent() override;
};

bool CoupleGame::find(int id) const {
    for (int i = 0;i < numOfParticipants;i++) {
        if (participants[i]->getId() == id) {
            return 1;
        }
    }
    return 0;
}

CoupleGame::CoupleGame(std::vector<Person*> participants, Person hostOfTheGame, Pair couples[6]) :TVGame(participants, hostOfTheGame) {
    if (participants.size() != numOfParticipants) {
        throw "participants too many or too few";
    }
    for (int i = 0;i < numOfCouples;i++) {
        if (!find(couples[i].id1) || !find(couples[i].id1)) {
            throw "invalid couple";
        }
        else {
            (this->couples)[i] = couples[i];
        }
    }
}

void CoupleGame::doEvent() {
    double currIntel = __DBL_MAX__;
    int currIndex = 0;
    for (int i = 0;i < numOfCouples;i++) {
        if (couples[i].id1 != 13) {
            double intl = findPersonById(couples[i].id1).getIntellect() + findPersonById(couples[i].id1).getIntellect();
            if (intl < currIntel) {
                currIntel = intl;
                currIndex = i;
            }
        }
    }
    std::string str = findPersonById(couples[currIndex].id1).getName();
    str.append(" ");
    str.append(findPersonById(couples[currIndex].id2).getName());
    str.append(" have left.");
    addEvent(str.c_str());
}