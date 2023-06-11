#include "TVGame.hpp"

class WomenGame : public TVGame {
private:
    const int numOfParticipants = 11;
    const int numOfTasks = 12;
    char* tasks[12];
    int nextTask;
    int findGirlIndex();
public:
    WomenGame(std::vector<Person*> participants, Person hostOfTheGame, char* tasks[12]);
    virtual void doEvent() override;
};

WomenGame::WomenGame(std::vector<Person*> participants, Person hostOfTheGame, char* tasks[12]) :TVGame(participants, hostOfTheGame) {
    if (participants.size() != numOfParticipants) {
        throw "participants too many or too few";
    }
    for (int i = 0;i < numOfTasks;i++) {
        (this->tasks)[i] = new char[strlen(tasks[i]) + 1];
        strncpy((this->tasks)[i], tasks[i], strlen(tasks[i]) + 1);
    }
    nextTask = 0;
}

int WomenGame::findGirlIndex() {
    double currRatio = 2000000;
    int currIndex = 0;
    for (int i = 0;i < numOfParticipants;i++) {
        if (participants[i] != nullptr) {

            if ((currRatio - participants[i]->getRatio()) > 0.0001) {
                currRatio = participants[i]->getRatio();
                currIndex = i;
            }
        }
    }
    return currIndex;
}

void WomenGame::doEvent() {
    if (nextTask >= numOfTasks) {
        throw "no more tasks";
    }
    int girl = findGirlIndex();

    std::string str = "Task was ";
    str.append(tasks[nextTask]);
    str.append(", ");
    str.append(participants[girl]->getName());
    str.append(" has left.");
    delete participants[girl];
    participants[girl] = nullptr;
    addEvent(str.c_str());
    std::cout << events[numberOfEvents - 1];
    nextTask++;
}