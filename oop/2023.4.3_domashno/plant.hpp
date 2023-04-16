#pragma once
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
    const char* getEnvironmentString() const;
    unsigned getFrequency() const;
    Environment getEnvironmentFromString(const char* str) const;

    void setName(const char*);
    void setEnvironment(Environment);
    void setEnvironment(const char*);
    void setFrequency(unsigned);

    Plant& operator=(const Plant&);
    Plant& operator=(Plant&&);

    friend std::istream& operator>>(std::istream& is, Plant& plant);
    friend std::ostream& operator<<(std::ostream& os, Plant& plant);

    ~Plant();
private:
    char* name;
    Environment env;
    unsigned freq;
};
