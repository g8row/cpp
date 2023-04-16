#include "plantsbook.hpp"
#include <stdexcept>
#include <cstring>
#include <fstream>

Plantsbook::Plantsbook(const char* filename)
{
    strcpy(this->filename, filename);
    std::ofstream ofs(this->filename, std::ios::app | std::ios::out);
    if (!ofs.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    this->rows = countRows();
}

Plantsbook::Plantsbook(const Plantsbook& other) {
    strcpy(this->filename, other.filename);
    rows = other.rows;
}

void Plantsbook::addPlant(const char* name, Plant::Environment env, unsigned freq)
{
    rows = countRows() + 1;
    if (env == Plant::Environment::unspecified) {
        env = Plant::Environment::neutral;
    }
    if (freq == -1) {
        freq = 3;
    }
    if (rows == 1) {
        std::ofstream ofs(this->filename, std::ios::trunc | std::ios::out);
        if (!ofs.is_open()) {
            throw std::invalid_argument("file cannot be opened");
        }
        Plant temp = Plant(name);
        temp.setEnvironment(env);
        temp.setFrequency(freq);
        ofs << strlen(name) << " " << temp << '\n';
        return;
    }
    bool isAdded = 0;
    Plant** plants = new Plant * [rows + 1];
    Plant** beg = plants;
    std::ifstream ifs(this->filename, std::ios::in);
    if (!ifs.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    for (int i = 1;i < rows;i++) {

        int size;
        ifs >> size;
        ifs.ignore();

        char* buffer = new char[size + 1];
        ifs.getline(buffer, size + 1, ' ');

        int comp = 0;
        if (!isAdded) {
            comp = strcmp(name, buffer);
            if (comp == 0) {
                throw std::invalid_argument("invalid name");
            }
        }

        char envBuffer[12];
        ifs.getline(envBuffer, 12, ' ');

        unsigned freqBuffer;
        ifs >> freqBuffer;

        if (!isAdded && comp < 0) {
            *plants = new Plant(name);
            (**plants).setEnvironment(env);
            (**plants).setFrequency(freq);
            plants++;
            isAdded = 1;
        }
        *plants = new Plant(buffer);
        (**plants).setEnvironment(envBuffer);
        (**plants).setFrequency(freqBuffer);
        plants++;

        delete[] buffer;
    }
    ifs.close();
    if (!isAdded) {
        *plants = new Plant(name);
        (**plants).setEnvironment(env);
        (**plants).setFrequency(freq);
    }
    std::ofstream ofs(this->filename, std::ios::trunc | std::ios::out);
    if (!ofs.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    plants = beg;
    for (int i = 0;i < rows;i++) {
        ofs << strlen((**plants).getName()) << " " << **plants << '\n';
        plants++;
    }
    for (int i = 0;i < rows;i++) {
        delete beg[i];
    }
    delete[] beg;
}

void Plantsbook::addPlant(const Plant& plant) {
    addPlant(plant.getName(), plant.getEnvironment(), plant.getFrequency());
}

Plant Plantsbook::getPlant(const char* name) {
    std::ifstream ifs(this->filename, std::ios::in);
    if (!ifs.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    bool isFound = 0;
    Plant* temp;
    for (int i = 1;i < rows && !isFound;i++) {
        int size;
        ifs >> size;
        ifs.ignore();

        char* buffer = new char[size + 1];
        ifs.getline(buffer, size + 1, ' ');

        int comp = strcmp(name, buffer);
        if (comp == 0) {
            isFound = 1;
        }
        char envBuffer[12];
        ifs.getline(envBuffer, 12, ' ');

        unsigned freqBuffer;
        ifs >> freqBuffer;

        if (isFound) {
            temp = new Plant(buffer);
            temp->setEnvironment(envBuffer);
            temp->setFrequency(freqBuffer);
        }
        delete[] buffer;
    }

    if (!isFound) {
        throw std::invalid_argument("plant not in book");
    }
    return *temp;
}


unsigned Plantsbook::countRows()
{
    int rows = 0;
    std::ifstream ifs(this->filename, std::ios::in);
    if (!ifs.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    char temp;
    while (ifs) {
        temp = ifs.get();
        if (temp == '\n') {
            rows++;
        }
    }
    return rows;
}
