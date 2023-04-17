#include "greenhouse.hpp"
int main() {
    Plantsbook book("book.txt");
    book.addPlant("roza", Plant::Environment::shady, 10);
    Plant testplant("lale");
    testplant.setEnvironment("sunny");
    testplant.setFrequency(6);
    book.addPlant(testplant);
    book.addPlant("kokiche", Plant::Environment::sunny, 8);
    book.addPlant("kaktus", Plant::Environment::neutral, 3);

    Greenhouse house(1, 2, 2, book);
    house.addPlant("roza");
    house.addPlant("kaktus");
    house.addPlant("lale");
    house.addPlant("kokiche");
    house.addPlant("kokiche");

    std::cout << house << std::endl;
}