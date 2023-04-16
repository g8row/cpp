#include "potrow.hpp"

PotRow::PotRow() {
    plants = nullptr;
    count = 0;
}

PotRow::PotRow(int num) {
    plants = new Plant * [num] {nullptr};
    count = 0;
    capacity = num;
}

PotRow::PotRow(const PotRow& row) {
    plants = new Plant * [row.count] {nullptr};
    count = row.count;
    for (int i = 0;i < count;i++) {
        plants[i] = new Plant(*(row.plants[i]));
    }
    capacity = row.capacity;
}
PotRow& PotRow::operator=(const PotRow& row) {
    free();
    plants = new Plant * [row.count] {nullptr};
    count = row.count;
    for (int i = 0;i < count;i++) {
        plants[i] = new Plant(*(row.plants[i]));
    }
    capacity = row.capacity;
    return *this;
}

PotRow& PotRow::operator=(PotRow&& row) {
    if (this != &row) {
        free();
        plants = row.plants;
        row.plants = nullptr;
        capacity = row.capacity;
    }
    return *this;
}

PotRow::PotRow(PotRow&& row) {

    plants = row.plants;
    row.plants = nullptr;
    capacity = row.capacity;

}

void PotRow::free() {
    for (int i = 0;plants != nullptr && i < count;i++) {
        delete plants[i];
    }
    delete[] plants;
    count = 0;
}

void PotRow::add(const Plant& plant) {
    if (!hasFreeSpots()) {
        throw std::invalid_argument("no free spots on row");
    }
    plants[firstFreeSpot()] = new Plant(plant);
    count++;
}

int PotRow::firstFreeSpot() { //-1 if there are no free spots
    for (int i = 0;i < capacity;i++) {
        if (plants[i] == nullptr) {
            return i;
        }
    }
    return -1;
}

bool PotRow::hasFreeSpots() {
    return count != capacity;
}

Plant PotRow::remove(int index) {
    if (index < 0 || index >= capacity || plants[index] == nullptr) {
        std::cout << "rhuw";
        throw std::invalid_argument("invalid index");
    }
    Plant temp(*plants[index]);
    plants[index] = nullptr;
    return temp;
}

PotRow::~PotRow() {
    free();
}
