#pragma once
#include "potrow.hpp"
#include "plantsbook.hpp"

class Greenhouse {
    Plantsbook book;
    PotRow rows[3];
    int getRow(Plant::Environment env);
public:
    Greenhouse(int sunny, int neutral, int shady, const char* filename);
    Greenhouse(int sunny, int neutral, int shady, const Plantsbook& book);
    Greenhouse(const Greenhouse&);
    Greenhouse& operator=(const Greenhouse&);
    void addPlant(const char* name);
    Plant remove(int row, int index);
    friend std::ostream& operator<<(std::ostream& os, const Greenhouse& house);
    void printStatistic() const;
};
