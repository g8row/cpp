#include "FacebookPost.h"

class FacebookProfile {
    char* _name;
    FacebookPost* _posts;
    int _numOfPosts;
public:
    FacebookProfile();
    FacebookProfile(const char* name, const char* filename);
    FacebookProfile(const char*, int);//само име и размер 
    FacebookProfile(const char*, int, const FacebookPost*);
    FacebookProfile(const FacebookProfile&);
    FacebookProfile(FacebookProfile&&);
    FacebookProfile& operator=(const FacebookProfile&);
    FacebookProfile& operator=(FacebookProfile&&);
    ~FacebookProfile();

    void addPostAtIndex(const FacebookPost&, unsigned);
    FacebookPost& operator[](unsigned);
    bool isEmpty(unsigned);
};
