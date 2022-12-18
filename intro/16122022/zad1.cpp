#include<iostream>

void initPointer(char*& toInitialize) {
    toInitialize = new char[26 + 1];

    for (size_t i = 97; i < 123; i++)
        toInitialize[i - 97] = (char)(i);

    toInitialize[26] = '\0';
}

int main() {
    char* result = nullptr;
    initPointer(result);
    std::cout << result;
    delete[] result;
}