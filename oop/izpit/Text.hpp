#ifndef TEXT
#define TEXT

#include <iostream>
#include <cstring>
class Text {
private:
protected:
    char* str;
    unsigned id;
    static unsigned idGen;
public:
    Text(const char*);
    Text(const Text&);
    Text& operator=(const Text&);
    virtual ~Text();

    virtual void print() = 0;
    virtual Text* clone() = 0;
    const char* getStr() {
        return str;
    }

    static unsigned getNextId() {
        return idGen;
    }
};

unsigned Text::idGen = 1;

Text::Text(const char* _str) :id(idGen++) {
    str = new char[strlen(_str) + 1];
    strcpy(str, _str);
}

Text::Text(const Text& _text) {
    str = new char[strlen(_text.str) + 1];
    strcpy(str, _text.str);
}

Text& Text::operator=(const Text& _text) {
    if (this != &_text) {
        delete[] str;
        str = new char[strlen(_text.str) + 1];
        strcpy(str, _text.str);
    }
    return *this;
}

Text::~Text() {
    delete[] str;
}

#endif