#include <iostream>
#include <cstring>
#include <assert.h>
class first {
public:
    first(const char* = "first", int = 0);
    ~first();
    first(const first&);
    first& operator=(const first&);
    void print() const;
private:
    char* str;
    int x;
};
first::first(const char* s, int y) {
    std::cout << "first(" << s << "," << y << ")\n";
    str = new char[strlen(s) + 1];
    assert(str != 0);
    strcpy(str, s);
    x = y;
}
first::~first() {
    std::cout << "~first()\n";
    delete[] str;
}
first::first(const first& s) {
    std::cout << "first(const s)\n";
    str = new char[strlen(s.str) + 1];
    assert(str != 0);
    strcpy(str, s.str);
    x = s.x;
}
first& first::operator=(const first& s) {
    std::cout << "first::operator=()\n";
    if (this != &s) {
        delete[] str;
        str = new char[strlen(s.str) + 1];
        assert(str != 0);
        strcpy(str, s.str);
        x = s.x;
    }
    return *this;
}
void first::print() const {
    std::cout << str << " " << x << std::endl;
}
int main() {
    first a("***"), b("+++", 12), c(b);
    a.print(); b.print();
    c.print();
    c = a;
    c.print();
    first* p = new first("---", -5);
    assert(p != 0);
    p->print();
    delete p;
    return 0;
}
