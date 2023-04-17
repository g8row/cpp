#include "plant.hpp"
#include "cstring"

Plant& Plant::operator=(const Plant& other) {
    if (this != &other) {
        strcpy(this->name, other.name);
        this->env = other.env;
        this->freq = other.freq;
    }
    return *this;
}

Plant& Plant::operator=(Plant&& other) {
    if (this != &other) {
        this->name = other.name;
        other.name = nullptr;
        this->env = other.env;
        this->freq = other.freq;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, Plant& plant) {
    os << plant.name << " ";
    os << plant.getEnvironmentString() << " ";
    os << plant.freq;
    return os;
}

std::istream& operator>>(std::istream& is, Plant& plant) {
    unsigned size;
    is >> size;

    delete[] plant.name;
    plant.name = new char[size + 1];
    is.getline(plant.name, size + 1, ' ');

    char env[8];
    is.getline(env, 8, ' ');

    is >> plant.freq;
    return is;
}

Plant::Plant(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    env = Environment::unspecified;
    freq = -1;
}

Plant::Plant(const Plant& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    env = other.env;
    freq = other.freq;
}

Plant::Plant(Plant&& other) {
    name = other.name;
    env = other.env;
    freq = other.freq;

    other.name = nullptr;
    other.env = Environment::neutral;
    other.freq = 0;
}

const char* Plant::getName() const {
    return this->name;
}

Plant::Environment Plant::getEnvironment() const {
    return this->env;
}

const char* Plant::getEnvironmentString() const {
    if (this->env == Plant::Environment::sunny) {
        return "sunny";
    }
    else  if (this->env == Plant::Environment::neutral) {
        return "neutral";
    }
    else if (this->env == Plant::Environment::shady) {
        return "shady";
    }
    else {
        return "unspecified";
    }
}

unsigned Plant::getFrequency() const {
    return this->freq;
}

Plant::Environment Plant::getEnvironmentFromString(const char* str) const {
    if (!strcmp(str, "sunny")) {
        return Plant::Environment::sunny;
    }
    else  if (!strcmp(str, "neutral")) {
        return Plant::Environment::neutral;
    }
    else if (!strcmp(str, "shady")) {
        return Plant::Environment::shady;
    }
    else {
        return Plant::Environment::unspecified;
    }
}

void Plant::setName(const char* name) {
    delete[] name;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

void Plant::setEnvironment(Plant::Environment env) {
    this->env = env;
}

void Plant::setEnvironment(const char* env) {
    this->env = getEnvironmentFromString(env);
}

void Plant::setFrequency(unsigned freq) {
    if (freq <= 0) {
        freq = 1;
    }
    this->freq = freq;
}

Plant::~Plant() {
    delete[] this->name;
}
