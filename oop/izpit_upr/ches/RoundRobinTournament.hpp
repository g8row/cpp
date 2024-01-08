#ifndef RRT
#define RRT

#include "ChessTournament.hpp"

class RRTournament : public ChessTournament {
    bool** games;
public:
    RRTournament(const ChessPlayer** players, size_t size);
    virtual bool finished();
    virtual void addGame(const ChessPlayer& p1, const ChessPlayer& p2, int result);
    virtual ChessTournament* clone();
};

RRTournament::RRTournament(const ChessPlayer** players, size_t size) : ChessTournament(players, size) {
    games = new bool* [size];
    for (size_t i = 0;i < size;i++) {
        games[i] = new bool[size];
    }
};

bool RRTournament::finished() {
    for (size_t i = 0;i < size;i++) {
        for (size_t j = 0;j < size;j++) {
            if (!games[i][j] && i != j) {
                return 0;
            }
        }
    }
    return 1;
}

void RRTournament::addGame(const ChessPlayer& p1, const ChessPlayer& p2, int result) {
    if (games[getPosFromId(p1.getId())][getPosFromId(p2.getId())]) {
        throw "game's been played";
    }
    ChessTournament::addGame(p1, p2, result);
}

ChessTournament* RRTournament::clone() {
    return new RRTournament(*this);
}

#endif