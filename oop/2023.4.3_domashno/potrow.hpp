#pragma once
#include "plant.hpp"

class PotRow {
    Plant** plants;
    int count;
    int capacity;
public:
    PotRow();
    PotRow(int num);
    PotRow(const PotRow&);
    PotRow(PotRow&&);
    PotRow& operator=(const PotRow&);
    PotRow& operator=(PotRow&&);
    int firstFreeSpot();
    bool hasFreeSpots();
    void add(const Plant& plant);
    Plant remove(int index);
    void free();
    ~PotRow();
};