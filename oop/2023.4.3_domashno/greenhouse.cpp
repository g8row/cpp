#include "greenhouse.hpp"
#include <cstdlib>
#include <ctime>

int Greenhouse::getRow(Plant::Environment env) {
    if (env == Plant::Environment::sunny) {
        return 0;
    }
    else  if (env == Plant::Environment::neutral) {
        return 1;
    }
    else return 2;
}

Greenhouse::Greenhouse(const Greenhouse& other):book(other.book) {
    for (int i = 0;i < 3;i++) {
        rows[i] = other.rows[i];
    }
}

Greenhouse& Greenhouse::operator=(const Greenhouse& other) {
    for (int i = 0;i < 3;i++) {
        rows[i] = other.rows[i];
    }
    return *this;
}

Greenhouse::Greenhouse(int sunny, int neutral, int shady, const Plantsbook& book): book(book) {
    rows[0] = PotRow(sunny);
    rows[1] = PotRow(neutral);
    rows[2] = PotRow(shady);
}

Greenhouse::Greenhouse(int sunny, int neutral, int shady, const char* filename): book(filename) {
    rows[0] = PotRow(sunny);
    rows[1] = PotRow(neutral);
    rows[2] = PotRow(shady);
}

void Greenhouse::addPlant(const char* name) {
    Plant plant = book.getPlant(name);

    int toAdd;

    int currRow = getRow(plant.getEnvironment());

    if (rows[currRow].hasFreeSpots()) {
        toAdd = currRow;
    }
    else {
        int opt1, opt2;
        bool changed = 0;
        for (int i = 0;i < 3;i++) {
            if (i != currRow && rows[i].hasFreeSpots()) {
                if (!changed) {
                    opt1 = i;
                }
                opt2 = i;
                changed = 1;
            }
        }
        std::srand(std::time(0));
        float rand = (std::rand()) * 1.0 / RAND_MAX;
        toAdd = (rand > 0.5) ? opt1 : opt2;
    }
    int days = plant.getFrequency() - toAdd + currRow;
    if (days <= 0) {
        days = 1;
    }
    plant.setFrequency(days);
    rows[toAdd].add(plant);
}

Plant Greenhouse::remove(int row, int index) {
    if (row > 3 || row < 0) {
        throw std::invalid_argument("invalid row");
    }
    return rows[row].remove(index);
}


