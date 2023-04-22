#include "greenhouse.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>


int main() {
    std::srand((unsigned)std::time(0));

    Plantsbook book("book.txt");
    book.addPlant("roza", Plant::Environment::shady, 10);
    Plant testplant("lale");
    testplant.setEnvironment("sunny");
    testplant.setFrequency(6);
    book.addPlant(testplant);
    book.addPlant("kokiche", Plant::Environment::sunny, 8);
    book.addPlant("kaktus", Plant::Environment::neutral, 3);

    Greenhouse house(2, 1, 2, book);
    house.addPlant("kokiche");
    house.addPlant("kaktus");
    house.addPlant("lale");
    house.addPlant("kokiche");
    house.addPlant("roza");

    std::cout << house << std::endl;
    house.printStatistic();

    house.remove(0, 0);
    std::cout << house << std::endl;
    house.printStatistic();

    std::ofstream ofs("book.txt", std::ios::trunc | std::ios::out);
}