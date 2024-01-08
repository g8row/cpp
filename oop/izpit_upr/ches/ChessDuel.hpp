#ifndef CHESS_DUEL
#define CHESS_DUEL

#include "ChessTournament.hpp"

class ChessDuel : public ChessTournament {
    size_t gamesPlayed;
public:
    ChessDuel(const ChessPlayer** players);
    virtual bool finished();
    virtual void addGame(const ChessPlayer& p1, const ChessPlayer& p2, int result);
    virtual ChessTournament* clone();
};

ChessDuel::ChessDuel(const ChessPlayer** players) : ChessTournament(players, 2), gamesPlayed(0) {};

bool ChessDuel::finished() {
    return abs(points[0] - points[1]) >= 2 || gamesPlayed >= 10;
}

void ChessDuel::addGame(const ChessPlayer& p1, const ChessPlayer& p2, int result) {
    ChessTournament::addGame(p1, p2, result);
    gamesPlayed++;
}

ChessTournament* ChessDuel::clone() {
    return new ChessDuel(*this);
}


#endif