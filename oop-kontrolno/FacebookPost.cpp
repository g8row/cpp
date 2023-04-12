#include "FacebookPost.h"


bool FacebookPost::isEmpty() {
    return empty;
}

FacebookPost::FacebookPost() {
    strcpy(_description, "");
    strcpy(_photoPath, "");
    empty = 0;
}

FacebookPost::FacebookPost(const char* description, const char* photoPath) {
    strcpy(_description, description);
    strcpy(_photoPath, photoPath);
}
FacebookPost::FacebookPost(const FacebookPost& other) {
    strcpy(_description, other._description);
    strcpy(_photoPath, other._photoPath);
    for (int i = 0;i < 7;i++) {
        _reactions[i] = other._reactions[i];
    }
}
FacebookPost& FacebookPost::operator=(const FacebookPost& other) {
    strcpy(_description, other._description);
    strcpy(_photoPath, other._photoPath);
    for (int i = 0;i < 7;i++) {
        _reactions[i] = other._reactions[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const FacebookPost post) {
    std::ifstream file(post._photoPath, std::ios::in);
    if (!file.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    while (file) {
        int temp = file.get();
        char temp1 = (temp != -1) ? temp : '\0';
        os << temp1;
    }
    return os;
}
void FacebookPost::addReaction(unsigned index) {
    _reactions[index]++;
}
void FacebookPost::printPost() {
    std::cout << _description << std::endl;
    std::cout << *this << std::endl;
    for (int i = 0;i < 7;i++) {
        std::cout << "Reaction " << i << ": " << _reactions[i] << std::endl;
    }
}