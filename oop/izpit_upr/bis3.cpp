#include <iostream>
#include <cstring>

class A {
private:
    size_t size;
    size_t* array;
    void copy(const A&);
    void free();
    void move(A& a);
public:
    A();
    A(const A&);
    A(A&&);
    A& operator=(const A&);
    A& operator=(A&&);
    virtual ~A();
};

void A::copy(const A& a) {
    size = a.size;
    array = new size_t[size];
    for (int i = 0;i < size;i++) {
        array[i] = a.array[i];
    }
}

void A::free() {
    delete[] array;
}

void A::move(A& a) {
    size = a.size;
    array = a.array;
    a.array = nullptr;
}

A::A() {
    size = 0;
    array = nullptr;
}

A::A(const A& a) {
    copy(a);
}

A::A(A&& a) {
    move(a);
}

A& A::operator=(const A& a) {
    if (this != &a) {
        free();
        copy(a);
    }
    return *this;
}

A& A::operator=(A&& a) {
    if (this != &a) {
        free();
        move(a);
    }
    return *this;
}
A::~A() {
    free();
}

class B : virtual public A {
private:
    bool b;
public:
    B();
    B(const B&);
    B(B&&);
    B& operator=(const B&);
    B& operator=(B&&);
    virtual ~B();
};

B::B() : A() {
    b = 0;
}

B::B(const B& b) : A(b) {
    this->b = b.b;
}

B::B(B&& b) : A(std::move(b)) {
    this->b = b.b;
}

B& B::operator=(const B& b) {
    if (this != &b) {
        A::operator=(b);
        this->b = b.b;
    }
    return *this;
}
B& B::operator=(B&& b) {
    if (this != &b) {
        A::operator=(std::move(b));
        this->b = b.b;
    }
    return *this;
}

B::~B() {}

class C : virtual public A {
private:
    char* c;
    void copy(const C&);
    void free();
    void move(C& a);
public:
    C();
    C(const C&);
    C(C&&);
    C& operator=(const C&);
    C& operator=(C&&);
    virtual ~C();
};

void C::copy(const C& c) {
    this->c = new char[strlen(c.c) + 1];
    strcpy(this->c, c.c);
}

void C::free() {
    delete[] c;
}

void C::move(C& c) {
    this->c = c.c;
    c.c = nullptr;
}

C::C() : A() {
    char* c = nullptr;
}

C::C(const C& c) : A(c) {
    copy(c);
}

C::C(C&& c) : A(std::move(c)) {
    move(c);
}

C& C::operator=(const C& c) {
    if (this != &c) {
        free();
        A::operator=(c);
        copy(c);
    }
    return *this;
}

C& C::operator=(C&& c) {
    if (this != &c) {
        free();
        A::operator=(std::move(c));
        move(c);
    }
    return *this;
}

C::~C() {
    delete[] c;
}

class D : public B, public C {
private:
    double d;
};
