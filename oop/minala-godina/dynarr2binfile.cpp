#include <iostream>
#include <cstring>
#include <fstream>

class Person {
public:
    int age = 0;
    int size = 0;
    char* name = nullptr;
    Person(int, const char*);
    Person(const Person&);
    ~Person();
};

Person::Person(const Person& other) {
    this->age = other.age;
    this->size = other.size;
    name = new char[size + 1];
    strcpy(this->name, other.name);
}

Person::Person(int age, const char* name) {
    this->age = age;
    this->size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name, name);
}

Person::~Person() {
    delete[] name;
}

int main() {
    Person lilman(8, "peis");

    std::ofstream of("names.bin", std::ios::binary | std::ios::out);
    of.write((char*)&lilman, sizeof(Person));
    of.write(lilman.name, lilman.size * sizeof(char));
    of.close();

    Person bigman(10, "bralamo");

    std::ifstream inf("names.bin", std::ios::binary | std::ios::in);
    inf.read((char*)&bigman, sizeof(int) * 2);
    inf.seekg(sizeof(Person));
    delete[] bigman.name;
    bigman.name = new char[bigman.size];
    inf.read(bigman.name, bigman.size * sizeof(char));

    std::cout << bigman.age << bigman.name << std::endl;

}