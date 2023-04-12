#include "FacebookProfile.h"

int main() {
    FacebookProfile profile("Alexander Gurov", 2);
    profile.addPostAtIndex(FacebookPost("hihi", "photo.txt"), 0);
    profile[0].printPost();

}