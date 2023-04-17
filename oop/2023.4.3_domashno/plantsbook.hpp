#include "plant.hpp"
#pragma once

class Plantsbook
{
private:
    char filename[128];
    unsigned countRows();
public:
    Plant getPlant(const char*);
    Plantsbook(const char* name);
    Plantsbook(const Plantsbook& other);
    void addPlant(const char* name, Plant::Environment env, unsigned freq);
    void addPlant(const Plant& plant);
};
