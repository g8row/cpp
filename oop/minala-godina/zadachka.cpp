#include <fstream>
#include <iostream>
#include <stdexcept>

class Date {
    int _day, _month, _year;

public:
    unsigned toNum() const;
    Date(int, int, int);
    Date();
    Date& operator=(const Date&);
    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    Date(const Date&);
    Date(Date&&);

};
unsigned Date::toNum() const {
    return _year * 10000 + _month * 100 + _day;
}
Date::Date(int day, int month, int year) {
    _day = day;
    _month = month;
    _year = year;
}
Date::Date(): Date(0, 0, 0) {}
Date& Date::operator=(const Date& other) {
    _day = other._day;
    _month = other._month;
    _year = other._year;
}
bool Date::operator==(const Date& other) const {
    return toNum() == other.toNum();
}
bool Date::operator<(const Date& other) const {
    return toNum() < other.toNum();
}
bool Date::operator>(const Date& other) const {
    return toNum() > other.toNum();
}
Date::Date(const Date& other) {
    _day = other._day;
    _month = other._month;
    _year = other._year;
}
