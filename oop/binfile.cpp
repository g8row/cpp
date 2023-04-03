#include <fstream>
#include <iostream>

struct Student {
    int fn;
    char* name;
};

int main() {
    std::ofstream oFileName;
    Student st1;
    st1.fn = 44394;
    st1.name = new char[20];
    oFileName.open("file.o", std::ios::out | std::ios::binary); // check
    oFileName.seekp(0, std::ios::beg);
    oFileName.write((char*)&st1, sizeof(st1)); // int + char* !!!
    oFileName.close();

    std::ifstream iFileName;
    iFileName.open("file.o", std::ios::binary);
    Student st2;
    std::cout << st2.fn << std::endl;
    std::cout << st2.name << std::endl;
    iFileName.close();

}