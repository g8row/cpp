#ifndef ATEXT
#define ATEXT

#include "Text.hpp"

template <typename T>
class ArgumentText : public Text {
    unsigned lengths[4];
    T arg;
public:
    ArgumentText(const char*, unsigned[4], T);
    ArgumentText(const ArgumentText&);
    void print();
    Text* clone();
};

template <typename T>
void ArgumentText<T>::print() {
    std::cout << id << ": beginning - ";
    unsigned currPos = 0;
    for (unsigned i = 0;i < lengths[0];i++, currPos++) {
        std::cout << str[currPos];
    }
    std::cout << " thesis - ";
    for (unsigned i = 0;i < lengths[1];i++, currPos++) {
        std::cout << str[currPos];
    }
    std::cout << " arguments - ";
    for (unsigned i = 0;i < lengths[2];i++, currPos++) {
        std::cout << str[currPos];
    }
    std::cout << " conclusion - ";
    for (unsigned i = 0;i < lengths[3];i++, currPos++) {
        std::cout << str[currPos];
    }
    std::cout << " ; arg = " << arg << std::endl;
}

template <typename T>
ArgumentText<T>::ArgumentText(const char* str, unsigned lengths[4], T arg) : Text(str), arg(arg) {
    for (int i = 0;i < 4;i++) {
        this->lengths[i] = lengths[i];
    }
}

template <typename T>
Text* ArgumentText<T>::clone() {
    return new ArgumentText<T>(*this);
}

template <typename T>
ArgumentText<T>::ArgumentText(const ArgumentText& arg) :Text(arg.str), arg(arg.arg) {
    for (int i = 0;i < 4;i++) {
        lengths[i] = arg.lengths[i];
    }
}



#endif