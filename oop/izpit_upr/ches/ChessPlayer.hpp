#ifndef CHESS_PLAYER
#define CHESS_PLAYER
#include <string>
#include <iostream>

class ChessPlayer {
    size_t id;
    static size_t idGen;
    std::string name;
public:
    ChessPlayer(const char* name);
    size_t getId() const;
    friend std::ostream& operator<<(std::ostream& os, const ChessPlayer& player);
};

size_t ChessPlayer::idGen = 0;
ChessPlayer::ChessPlayer(const char* name) : name(name), id(idGen++) {}
size_t ChessPlayer::getId() const {
    return id;
}
std::ostream& operator<<(std::ostream& os, const ChessPlayer& player) {
    os << player.id << ": " << player.name;
    return os;
}
#endif
