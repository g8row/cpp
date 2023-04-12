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

Plant& Plant::operator=(const Plant& other) {
    strcpy(this->name, other.name);
    this->env = other.env;
    this->freq = other.freq;
    return *this;
}
Plant& Plant::operator=(Plant&& other) {
    this->name = other.name;
    other.name = nullptr;
    this->env = other.env;
    this->freq = other.freq;
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

const char* Plant::getEnvironmentString() const
{
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

Plant::Environment Plant::getEnvironmentFromString(const char* str) const
{
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
    this->freq = freq;
}

Plant::~Plant() {
    delete[] this->name;
}

class Plantsbook
{
private:
    char filename[128];
    unsigned rows;
    unsigned countRows();
public:
    Plantsbook(const char* name);
    void addPlant(const char* name, Plant::Environment env, unsigned freq);
    void addPlant(const Plant& plant);
};

Plantsbook::Plantsbook(const char* filename)
{
    strcpy(this->filename, filename);
    std::ofstream ofs(this->filename, std::ios::app | std::ios::out);
    if (!ofs.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    this->rows = countRows();
}

void Plantsbook::addPlant(const char* name, Plant::Environment env, unsigned freq)
{
    rows = countRows() + 1;
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

int main() {
    Plant pedal = Plant("pedal");
    pedal.setEnvironment("sunny");
    pedal.setFrequency(4);
    Plantsbook buk("book.txt");
    buk.addPlant(pedal);
}