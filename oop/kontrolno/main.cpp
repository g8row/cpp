#include "WomenGame.hpp"

int main() {
    std::vector<Person*> vec;
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasda", 123, "asda", 0.1));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    vec.push_back(new Person("dasd", 123, "asda", 0.7));
    Person host("host", 123, "dasd", 1);
    char* tasks[12];
    for (int i = 0;i < 12;i++) {
        tasks[i] = new char[2];
        strncpy(tasks[i], "1", 2);
    }
    WomenGame game(vec, host, tasks);
    game.doEvent();
}