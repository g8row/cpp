#include <cstring>
#include <iostream>
#include <stdexcept>

class Registration {
    char arr[9];
public:
    Registration(const char*);
    Registration& operator=(const Registration&);
    Registration& operator=(const char* str);
    bool operator==(const Registration&) const;
    const char* toString() const;
};

bool isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isValid(const char* str) {
    if (strlen(str) != 8) {
        return 0;
    }
    if (!isLetter(str[0]) && !isLetter(str[1]) && !isLetter(str[6]) && !isLetter(str[7])) {
        return 0;
    }
    if (!isDigit(str[2]) && !isDigit(str[3]) && !isDigit(str[4]) && !isDigit(str[5])) {
        return 0;
    }
    return 1;
}

Registration::Registration(const char* str) {
    if (!isValid(str)) {
        throw std::invalid_argument("invalid string");
    }
    strcpy(arr, str);
}

Registration& Registration::operator=(const Registration& other) {
    strcpy(arr, other.arr);
    return *this;
}

Registration& Registration::operator=(const char* str) {
    if (!isValid(str)) {
        throw std::invalid_argument("invalid string");
    }
    strcpy(arr, str);
    return *this;
}

bool Registration::operator==(const Registration& other) const {
    return !strcmp(arr, other.arr);
}

const char* Registration::toString() const {
    return arr;
}

class Vehicle {
public:
    const Registration regnum;
    char* description;
    Vehicle(const char* _regnum, const char* _description);
    ~Vehicle();
};

Vehicle::~Vehicle() {
    delete[]description;
}

Vehicle::Vehicle(const char* _regnum, const char* _description): regnum(_regnum) {
    description = new char[strlen(_description)];
    strcpy(description, _description);
}

class VehicleList {
    Vehicle** list;
    std::size_t _capacity;
    std::size_t _size;
public:
    VehicleList(std::size_t capacity);
    VehicleList(const VehicleList&);
    VehicleList& operator=(const VehicleList&);
    ~VehicleList();

    void insert(const char* regnum, const char* description);
    const Vehicle& at(size_t index) const;
    const Vehicle& operator[](size_t pos) const;
    bool empty() const;
    std::size_t capacity() const;
    std::size_t size() const;
    const Vehicle* find(const Registration& regnum) const;
};

VehicleList::~VehicleList() {
    for (int i = 0;i < _size;i++) {
        delete* (list + i);
    }
    delete[] list;
}


VehicleList::VehicleList(std::size_t capacity): _capacity(capacity) {
    _size = 0;
    list = new Vehicle * [_capacity] {nullptr};
}
VehicleList::VehicleList(const VehicleList& other): _capacity(other._capacity), _size(other._size) {
    list = new Vehicle * [_capacity] {nullptr};
    for (int i = 0;i < _size;i++) {
        *(list + i) = new Vehicle(other.at(i).regnum.toString(), other.at(i).description);
    }
}

void VehicleList::insert(const char* regnum, const char* description) {
    if (_capacity == _size) {
        throw std::out_of_range("list is full");
    }
    for (int i = 0;i < _size;i++) {
        if (!strcmp(this->at(i).regnum.toString(), regnum)) {
            throw std::invalid_argument("already added");
        }
    }
    *(list + _size) = new Vehicle(regnum, description);
    _size++;
}
const Vehicle& VehicleList::at(size_t index) const {
    if (index<0 || index>_size) {
        throw std::out_of_range("invalid index");
    }
    return *(*(list + index));
}
const Vehicle& VehicleList::operator[](size_t pos) const {
    if (pos<0 || pos>_size) {
        throw std::out_of_range("invalid index");
    }
    return *(*(list + pos));
}
bool VehicleList::empty() const {
    return _size == 0;
}
std::size_t VehicleList::capacity() const {
    return _capacity;
}
std::size_t VehicleList::size() const {
    return _size;
}

const Vehicle* VehicleList::find(const Registration& regnum) const {
    for (int i = 0;i < _size;i++) {
        if (this->at(i).regnum == regnum) {
            return list[i];
        }
    }
    return nullptr;
}

int main() {
    VehicleList list(4);
    list.insert("SA1234MA", "LMALOLAO");
    std::cout << list.at(0).regnum.toString() << std::endl;
    list.insert("SA1233MA", "elemeio");
    std::cout << list.at(1).regnum.toString() << std::endl;
    std::cout << list.size() << std::endl;
    std::cout << list.find(Registration("SA1233MA"))->description;
}



