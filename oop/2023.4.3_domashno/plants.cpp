#include <cstring>
#include <fstream>
#include <iostream>



class Plant {
public:
    enum class Environment {
        sunny,
        neutral,
        shady,
        unspecified
    };

    Plant(const char* name);
    Plant(const Plant&);
    Plant(Plant&&);

    const char* getName() const;
    Environment getEnvironment() const;
    unsigned getFrequency() const;
    void setName(const char*);
    void setEnvironment(Environment);
    void setFrequency(unsigned);

    Plant& operator=(const Plant&);
    Plant& operator=(Plant&&);

    friend std::istream& operator>>(std::istream& is, Plant& plant) {
        char buf[129];
        is >> buf;
        delete[] plant.name;
        plant.name = new char[strlen(buf) + 1];
        strcpy(plant.name, buf);

        char env[8];
        is >> env;
        if (!strcmp(env, "sunny")) {
            plant.env = Plant::Environment::sunny;
        }
        else  if (!strcmp(env, "neutral")) {
            plant.env = Plant::Environment::neutral;
        }
        else if (!strcmp(env, "shady")) {
            plant.env = Plant::Environment::shady;
        }
        else {
            plant.env = Plant::Environment::unspecified;
        }
        is >> plant.freq;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, Plant& plant) {
        os << plant.name << " ";
        if (plant.env == Plant::Environment::sunny) {
            os << "sunny" << " ";
        }
        else  if (plant.env == Plant::Environment::neutral) {
            os << "neutral" << " ";
        }
        else if (plant.env == Plant::Environment::shady) {
            os << "shady" << " ";
        }
        else if (plant.env == Plant::Environment::unspecified) {
            os << "unspecified" << " ";
        }
        os << plant.freq;
        return os;
    }

    ~Plant();
private:
    char* name;
    Environment env;
    unsigned freq;
};

Plant::Plant(const char* name) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}
Plant::Plant(const Plant& other) {
    name = new char[strlen(other.name)];
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
unsigned Plant::getFrequency() const {
    return this->freq;
}

void Plant::setName(const char* name) {
    delete[] name;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}
void Plant::setEnvironment(Plant::Environment env) {
    this->env = env;
}
void Plant::setFrequency(unsigned freq) {
    this->freq = freq;
}

Plant::~Plant() {
    delete[] this->name;
}

int main() {

}