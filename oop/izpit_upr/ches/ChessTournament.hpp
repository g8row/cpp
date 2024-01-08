#ifndef CHESS_TOURNAMENT
#define CHESS_TOURNAMENT
#include "ChessPlayer.hpp"

class ChessTournament {
protected:
    ChessPlayer** players;
    size_t size;
    float* points;
    void copy(const ChessTournament& tournament);
    void move(ChessTournament&& tournament);
    void free();
    size_t getPosFromId(size_t id);
public:
    ChessTournament(const ChessPlayer** players, size_t size);
    ChessTournament(const ChessTournament& tournament);
    ChessTournament(ChessTournament&& tournament);
    ChessTournament& operator=(const ChessTournament& tournament);
    ChessTournament& operator=(ChessTournament&& tournament);
    virtual ~ChessTournament();

    virtual bool finished() = 0;
    virtual void addGame(const ChessPlayer& p1, const ChessPlayer& p2, int result);
    ChessPlayer& getLeader();
    ChessPlayer& getWinner();
    friend std::ostream& operator<<(std::ostream& os, const ChessTournament& tournament);

    virtual ChessTournament* clone() = 0;
};

std::ostream& operator<<(std::ostream& os, const ChessTournament& tournament) {
    for (size_t i = 0;i < tournament.size;i++) {
        os << *(tournament.players[i]) << ", points: " << tournament.points[i];
    }
    return os;
}


size_t ChessTournament::getPosFromId(size_t id) {
    for (size_t i = 0;i < size;i++) {
        if (players[id]->getId() == id) {
            return i;
        }
    }
    throw "player not found";
}

void ChessTournament::addGame(const ChessPlayer& p1, const ChessPlayer& p2, int result) {
    if (finished()) {
        throw "game is finished";
    }
    switch (result) {
    case 1: points[getPosFromId(p1.getId())] += 1;break;
    case 0: points[getPosFromId(p1.getId())] += 0.5;points[getPosFromId(p2.getId())] += 0.5;break;
    case -1:points[getPosFromId(p2.getId())] += 1;break;
    default:throw "invalid result";
    }
}

ChessPlayer& ChessTournament::getLeader() {
    size_t result = 0;
    float currMax = 0;
    for (size_t i = 0;i < size;i++) {
        if (currMax < points[i]) {
            result = i;
        }
    }
    return *players[result];
}

ChessPlayer& ChessTournament::getWinner() {
    if (finished()) {
        return getLeader();
    }
    else {
        throw "tournament not finished";
    }
}


void ChessTournament::copy(const ChessTournament& tournament) {
    size = tournament.size;
    this->players = new ChessPlayer * [tournament.size];
    for (int i = 0;i < size;i++) {
        this->players[i] = new ChessPlayer(*(tournament.players[i]));
    }
    for (int i = 0;i < size;i++) {
        this->points[i] = tournament.points[i];
    }
}
void ChessTournament::move(ChessTournament&& tournament) {
    size = tournament.size;
    players = tournament.players;
    tournament.players = nullptr;
    points = tournament.points;
    tournament.points = nullptr;
}
void ChessTournament::free() {
    if (players != nullptr) {
        for (int i = 0;i < size;i++) {
            delete players[i];
        }
        delete[] players;
    }
    if (points != nullptr) {
        delete[] points;
    }
}


ChessTournament::ChessTournament(const ChessPlayer** players, size_t size) {
    this->players = new ChessPlayer * [size];
    points = new float[size];

    for (int i = 0;i < size;i++) {
        this->players[i] = new ChessPlayer(*players[i]);
        points[i] = 0;
    }
    this->size = size;
}

ChessTournament::ChessTournament(const ChessTournament& tournament) {
    copy(tournament);
}

ChessTournament::ChessTournament(ChessTournament&& tournament) {
    move(std::move(tournament));
}

ChessTournament& ChessTournament::operator=(const ChessTournament& tournament) {
    if (this != &tournament) {
        free();
        copy(tournament);
    }
    return *this;
}
ChessTournament& ChessTournament::operator=(ChessTournament&& tournament) {
    if (this != &tournament) {
        free();
        move(std::move(tournament));
    }
    return *this;
}
ChessTournament::~ChessTournament() {
    free();
}

#endif