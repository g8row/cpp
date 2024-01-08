#ifndef PTEXT
#define PTEXT

#include "Text.hpp"

class Poem : public Text {
    char** key;
    unsigned size;
    void free();
    void copy(const Poem&);
public:
    Poem(const char*, char**, unsigned);
    Poem(const Poem&);
    Poem& operator=(const Poem&);
    void print();
    ~Poem();

    Text* clone();
};

void Poem::print() {
    std::cout << id << ": " << str << "; keys : ";
    for (int i = 0;i < size;i++) {
        std::cout << key[i] << ", ";
    }
    std::cout << std::endl;
}

void Poem::free() {
    for (unsigned i = 0;i < size;i++) {
        delete[] key[i];
    }
    delete[] key;
}

void Poem::copy(const Poem& _poem) {
    this->key = new char* [_poem.size];
    for (unsigned i = 0;i < _poem.size;i++) {
        this->key[i] = new char[strlen(_poem.key[i]) + 1];
        strcpy(this->key[i], _poem.key[i]);
    }
}


Poem::Poem(const char* str, char** key, unsigned size) :Text(str), size(size) {
    this->key = new char* [size];
    for (unsigned i = 0;i < size;i++) {
        unsigned keyLen = strlen(key[i]);
        if (keyLen <= 15) {
            this->key[i] = new char[keyLen + 1];
            strcpy(this->key[i], key[i]);
        }
        else {
            throw "invalid key size";
        }
    }
}

Poem::Poem(const Poem& _poem) :Text(_poem.str), size(_poem.size) {
    copy(_poem);
}

Poem& Poem::operator=(const Poem& _poem) {
    if (this != &_poem) {
        free();
        copy(_poem);
    }
    return *this;
}

Poem::~Poem() {
    free();
}

Text* Poem::clone() {
    return new Poem(*this);
}

#endif