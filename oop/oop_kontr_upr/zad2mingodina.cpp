#include <iomanip>
#include <cstring>
#include <iostream>
#include <iomanip>

class TrainTravel {
protected:
    char* trainLine;
    double price;
    void free() {
        delete[] trainLine;
    }
    void copy(const TrainTravel& obj) {
        this->trainLine = new char[strlen(obj.trainLine) + 1];
        strcpy(this->trainLine, obj.trainLine);
        this->price = obj.price;
    }
public:
    TrainTravel(const char* trainLine, double price) {
        this->trainLine = new char[strlen(trainLine) + 1];
        strcpy(this->trainLine, trainLine);
        this->price = (int)(price * 100) / 100.0;
    }
    TrainTravel(const TrainTravel& obj) {
        copy(obj);
    }
    TrainTravel& operator=(const TrainTravel& obj) {
        if (this != &obj) {
            free();
            copy(obj);
        }
        return *this;
    }
    ~TrainTravel() {
        free();
    }
    double getPrice() {
        return (int)(price * 100) / 100.0;
    }
};

class CarTravel {
protected:
    int regNumb[5];
    int distance;
    double price;
public:
    CarTravel(int regNumb[5], int distance, double price) {
        for (int i = 0;i < 5;i++) {
            (this->regNumb)[i] = regNumb[i];
        }
        this->distance = distance;
        this->price = price;
    }
    double getPrice() {
        return (int)(price * 100) / 100.0;
    }
};

class CombinedTrip : public TrainTravel, public CarTravel {
public:
    CombinedTrip(const char* trainLine, double price, int regNumb[5], int distance, double price2) : TrainTravel(trainLine, price), CarTravel(regNumb, distance, price2) {
        std::cout << TrainTravel::getPrice() << " " << CarTravel::getPrice();
    }
};
