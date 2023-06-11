#include "Person.hpp"

class TVGame {
protected:
    std::vector<Person*> participants;
    Person* hostOfTheGame;
    char* events[64];
    int numberOfEvents;
public:
    Person& findPersonById(unsigned id);
    TVGame(std::vector<Person*> participants, Person hostOfTheGame);
    virtual void showEvents(int limit) const;
    virtual void printFormatInformation() const;
    virtual void doEvent() = 0;
    void addEvent(const char* str);
    ~TVGame();
};
TVGame::TVGame(std::vector<Person*> participants, Person hostOfTheGame) {
    if (participants.size() > MAX_ARR_SIZE) {
        throw "too many participants";
    }
    this->participants = participants;
    this->hostOfTheGame = new Person(hostOfTheGame);
    if (numberOfEvents > MAX_ARR_SIZE) {
        throw "too many events";
    }
    this->numberOfEvents = 0;
}
TVGame::~TVGame() {
    for (int i = 0;i < participants.size();i++) {
        delete participants[i];
    }
    delete hostOfTheGame;
    for (int i = 0;i < numberOfEvents;i++) {
        delete events[i];
    }
}

Person& TVGame::findPersonById(unsigned id) {
    for (int i = 0; i < participants.size();i++) {
        if (participants[i] != nullptr) {
            if (participants[i]->getId() == id) {
                return *participants[i];
            }
        }
    }
    throw "not found";
}


void TVGame::showEvents(int limit) const {
    for (int i = 0;i < limit && i < numberOfEvents;i++) {
        std::cout << events[i] << std::endl;
    }
    if (limit > numberOfEvents) {
        std::cout << "no more events" << std::endl;
    }
}
void TVGame::printFormatInformation() const {
    std::cout << "Host: " << *hostOfTheGame << std::endl << "Participants:\n";
    for (int i = 0;i < participants.size();i++) {
        std::cout << *(participants[i]) << std::endl;
    }
}

void TVGame::addEvent(const char* str) {
    if (numberOfEvents >= MAX_ARR_SIZE) {
        throw "too many events";
    }
    events[numberOfEvents] = new char[strlen(str) + 1];
    strncpy(events[numberOfEvents], str, strlen(str) + 1);
    numberOfEvents++;
}