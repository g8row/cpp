#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <climits>

const int MAX_ARR_SIZE = 64;

class Person {
protected:
    unsigned id;
    std::string name;
    unsigned age;
    std::string businessCard;
    double intellect;
    void copy(const Person& obj) {
        this->id = obj.id;
        this->name = obj.name;
        this->age = obj.age;
        this->businessCard = obj.businessCard;
        this->intellect = obj.intellect;
    }
public:
    static unsigned nextID;
    Person(std::string name, unsigned age, std::string businessCard, double intellect);
    Person(const Person&);
    Person& operator=(const Person&);
    friend std::ostream& operator<<(std::ostream& os, const Person& obj);
    double getRatio() const;
    std::string getName() const;
    double getIntellect() const;
    unsigned getId() const;
    ~Person() {}
};
Person::Person(std::string name, unsigned age, std::string businessCard, double intellect) {
    id = nextID;
    nextID++;
    if (name.length() > 200) {
        throw "name too long";
    }
    this->name = name;
    this->age = age;
    if (businessCard.length() > 500) {
        throw "business card too long";
    }
    this->businessCard = businessCard;
    if (intellect < 0 || intellect >1) {
        throw "invalid intelect";
    }
    this->intellect = intellect;
}
Person::Person(const Person& obj) {
    copy(obj);
}
Person& Person::operator=(const Person& obj) {
    if (this != &obj) {
        copy(obj);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Person& obj) {
    os << "id: " << obj.id << ", " << obj.name << ", age " << obj.age << ", card: " << obj.businessCard << ", intellect " << obj.intellect;
    return os;
}

double Person::getRatio() const {
    return intellect / age;
}
std::string Person::getName() const {
    return name;
}

double Person::getIntellect() const {
    return intellect;
}

unsigned Person::getId() const {
    return id;
}


unsigned Person::nextID = 0;
