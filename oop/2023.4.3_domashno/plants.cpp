#include "greenhouse.hpp"
int main() {
    Greenhouse house(1, 1, 1, "book.txt");
    house.addPlant("pedal");
    house.addPlant("ledal");
    house.addPlant("milal");
    Plant bruh(house.remove(0, 0));
    std::cout << bruh << std::endl;
    bruh = Plant(house.remove(1, 0));
    std::cout << bruh << std::endl;
    bruh = Plant(house.remove(2, 0));
    std::cout << bruh << std::endl;
}