#include "FacebookProfile.h"

FacebookProfile::FacebookProfile() {
    _name = nullptr;
    _numOfPosts = 0;
    _posts = nullptr;
}
FacebookProfile::FacebookProfile(const char* name, int numOfPosts, const FacebookPost* posts) {
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    _numOfPosts = numOfPosts;
    if (_numOfPosts > 0) {
        _posts = new FacebookPost[_numOfPosts];
        for (int i = 0;i < _numOfPosts;i++) {
            _posts[i] = posts[i];
        }
    }
}
FacebookProfile::FacebookProfile(const char* name, int numOfPosts) {
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    _numOfPosts = numOfPosts;
    _posts = new FacebookPost[_numOfPosts];
}


FacebookProfile::FacebookProfile(const char* name, const char* filename) {
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    std::ifstream file(filename, std::ios::in | std::ios::binary); //файлът ще започва ли с броя на постовете? какъв е капацитета на редицата?
    /*  file.read((char*)&_numOfPosts, sizeof(int));
     _posts = new FacebookPost[_numOfPosts]; */
    int capacity = 1024;
    _posts = new FacebookPost[capacity];//нека капацитета на редицата е 1024
    _numOfPosts = 0;
    while (!file.eof()) {
        if (_numOfPosts == 1024) {
            break;
        }
        FacebookPost temp;
        file.read((char*)&temp, sizeof(FacebookPost));
        if (!temp.isEmpty()) {
            _posts[_numOfPosts] = temp;
            _numOfPosts++;
        }
    }

}

FacebookProfile::FacebookProfile(const FacebookProfile& other) {
    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);
    _numOfPosts = other._numOfPosts;
    if (_numOfPosts > 0) {
        _posts = new FacebookPost[_numOfPosts];
        for (int i = 0;i < _numOfPosts;i++) {
            _posts[i] = other._posts[i];
        }
    }
}
FacebookProfile::FacebookProfile(FacebookProfile&& other) {
    _name = other._name;
    _numOfPosts = other._numOfPosts;
    _posts = other._posts;
    other._name = nullptr;
    other._numOfPosts = 0;
    other._posts = nullptr;
}
FacebookProfile& FacebookProfile::operator=(const FacebookProfile& other) {
    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);
    _numOfPosts = other._numOfPosts;
    if (_numOfPosts > 0) {
        _posts = new FacebookPost[_numOfPosts];
        for (int i = 0;i < _numOfPosts;i++) {
            _posts[i] = other._posts[i];
        }
    }
    return *this;
}
FacebookProfile& FacebookProfile::operator=(FacebookProfile&& other) {
    _name = other._name;
    _numOfPosts = other._numOfPosts;
    _posts = other._posts;
    other._name = nullptr;
    other._numOfPosts = 0;
    other._posts = nullptr;
    return *this;
}


FacebookProfile::~FacebookProfile() {
    delete[] _name;
    delete[] _posts;
}

void FacebookProfile::addPostAtIndex(const FacebookPost& post, unsigned index) {
    _posts[index] = post;
}
FacebookPost& FacebookProfile::operator[](unsigned index) {
    if (_posts[index].isEmpty()) {
        throw std::invalid_argument("post is empty");
    }
    return _posts[index];
}
bool FacebookProfile::isEmpty(unsigned index) {
    return _posts[index].isEmpty();
}
