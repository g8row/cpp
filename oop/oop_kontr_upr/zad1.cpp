#include <string>
#include <fstream>
#include <iostream>

class Operations {
public:
    template <typename T>
    static void create(const T& obj, std::string filename);
    template <typename T>
    static T read(std::string filename, int index);
    template <typename T>
    static void update(const T& obj, std::string filename, int index);
    static void deleteAt(std::string filename, int index);
};
template<typename T>
void Operations::create(const T& obj, std::string filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::binary | std::ios::app);
    if (!file) {
        throw "File not open";
    }
    file.write((char*)&obj, sizeof(T));
}

template<typename T>
T Operations::read(std::string filename, int index)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        throw "File not open";
    }
    file.seekg(sizeof(T) * index);
    T temp;
    file.read((char*)&temp, sizeof(T));
    return temp;
}

template<typename T>
void Operations::update(const T& obj, std::string filename, int index)
{
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file) {
        throw "File not open";
    }
    file.seekp(sizeof(T) * index);
    file.write((char*)&obj, sizeof(T));
}

void Operations::deleteAt(std::string filename, int index)
{

}

class A {
public:
    int a;
    int b;
};


