#include <cstring>

class Vehicle {
    int id;
    static int idGen;
    char model[33];
    double range;
public:
    Vehicle(const char* model, double range) : range(range) {
        id = idGen++;
        int len = strlen(model);
        if (len > 32) {
            throw "invalid model";
        }
        strcpy(this->model, model);
    }
};

class Car {

};

int Vehicle::idGen = 0;