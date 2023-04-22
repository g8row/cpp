#pragma once
#include "plant.hpp"

class PotRow {
    Plant** plants;
    int count;
    int capacity;
    void free();
    int firstFreeSpot();
public:
    PotRow();
    PotRow(int num);
    PotRow(const PotRow&);
    PotRow(PotRow&&);
    PotRow& operator=(const PotRow&);
    PotRow& operator=(PotRow&&);
    void add(const Plant& plant);
    bool hasFreeSpots();
    Plant remove(int index);
    friend std::ostream& operator<<(std::ostream& os, const PotRow& row);
    int getCount() const;
    ~PotRow();
};