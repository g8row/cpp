#include <fstream>
#include <cstring>
#include <iostream>


class FacebookPost {
    int _reactions[7]{ 0 };
    char _description[1024];
    char _photoPath[32];
public:
    FacebookPost();
    FacebookPost(const char* description, const char* photoPath);
    FacebookPost(const FacebookPost&);
    FacebookPost& operator=(const FacebookPost&);
    FacebookPost& operator=(FacebookPost&&);
    friend std::ostream& operator<<(std::ostream& os, FacebookPost post);
    void addReaction(unsigned);
    void printPost();
};