#ifndef TEXTB
#define TEXTB

#include "ArgumentText.hpp"
#include "Poem.hpp"
#include <fstream>

class TextBook {
    Text** texts;
    unsigned size;
    void free();
    void copy(const TextBook&);
public:
    TextBook(Text**, unsigned);
    TextBook(const TextBook&);
    TextBook& operator=(const TextBook&);
    Text* operator[](unsigned);
    ~TextBook();
    void print() {
        for (int i = 0;i < size;i++) {
            if (texts[i] != nullptr) {
                texts[i]->print();
            }
        }
    }
};

Text* TextBook::operator[](unsigned pos) {
    if (pos < 0 || pos >= size || texts[pos] == nullptr) {
        throw "invalid position";
    }
    std::ofstream file("text.txt", std::ios::out);
    file.write(texts[pos]->getStr(), strlen(texts[pos]->getStr()));
    file.close();
    return texts[pos];
}


void TextBook::free() {
    for (unsigned i = 0;i < size;i++) {
        delete texts[i];
    }
    delete[] texts;
}

void TextBook::copy(const TextBook& book) {
    size = book.size;
    texts = new Text * [size] {0};
    for (unsigned i = 0;i < size;i++) {
        texts[i] = book.texts[i]->clone();
    }
}

TextBook::TextBook(Text** _texts, unsigned size) : size(size) {
    texts = new Text * [size] {0};
    for (unsigned i = 0;i < size;i++) {
        texts[i] = _texts[i]->clone();
    }
}

TextBook::TextBook(const TextBook& book) {
    copy(book);
}

TextBook& TextBook::operator=(const TextBook& book) {
    if (this != &book) {
        free();
        copy(book);
    }
    return *this;
}

TextBook::~TextBook() {
    free();
}



#endif