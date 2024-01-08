#include "TextBook.hpp"
#include <iostream>
int main() {
    unsigned arr[4] = { 3,3,3,3 };

    ArgumentText<int> argu("am.is.we.me.", arr, 4);

    char* keys[2];
    keys[0] = new char(4);
    strcpy(keys[0], "key");
    keys[1] = new char(4);
    strcpy(keys[1], "key");

    Poem poem("poema", keys, 2);

    delete[]keys[0];
    delete[]keys[1];

    Poem p2(poem);

    ArgumentText<int> a2(argu);

    //std::cout << Text::getNextId() << std::endl;

    Text* texts[3];
    texts[0] = &argu;
    texts[1] = &poem;
    texts[2] = &p2;

    TextBook book(texts, 3);

    book.print();
    book[0]->print();
}