#include <string>
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* left, * right;
};

bool beginsWith(std::string a, std::string b) {
    const char* aptr = a.c_str();
    const char* bptr = b.c_str();

    if (aptr == nullptr || bptr == nullptr) {
        return false;
    }
    while (*aptr != '\0' && *bptr != '\0') {
        if (*aptr != *bptr) {
            return false;
        }
        aptr++;
        bptr++;
    }
    return true;
}

void removeBeg(std::string& a, std::string& b) {
    a.erase(0, b.size());
}

Node<std::string>* findWordHelper(Node<std::string>* root, std::string& str, Node<std::string>*& beg) {
    if (!root) {
        return nullptr;
    }

    if (beginsWith(str, root->data)) {
        removeBeg(str, root->data);
        if (str.empty()) {
            return beg;
        }
        if (beg == nullptr) {
            beg = root;
        }
        return beg;
    }

    if (root->left != nullptr && str < root->data) {
        if (findWordHelper(root->left, str, beg) != nullptr) {
            if (str.empty()) {
                return beg;
            }
            if (beginsWith(str, root->data)) {
                removeBeg(str, root->data);
                if (str.empty()) {
                    return beg;
                }
                return findWordHelper(root->right, str, beg);
            }
        }
    }
    if (str.empty()) {
        return beg;
    }
    return nullptr;
}

Node<std::string>* findWord(Node<std::string>* root, std::string str) {
    Node<std::string>* beg = nullptr;
    return findWordHelper(root, str, beg);
}

int main() {
    //Node<int>* root = new Node<int>{ 1, new Node<int>{10, nullptr, nullptr}, new Node<int>{4, nullptr, nullptr} };
    Node<std::string>* root = new Node<std::string>{ "xel", new Node<std::string>{"go", new Node<std::string>{"al", new Node<std::string>{"ab", nullptr, nullptr}, nullptr}, new Node<std::string>{"thms",new Node<std::string>{"ri",nullptr,nullptr}, new Node<std::string>{"u",nullptr,nullptr}}}, nullptr };
    std::cout << findWord(root, "algorithms")->data;
}