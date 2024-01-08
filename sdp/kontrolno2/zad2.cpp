#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* left, * right;
};

template <typename T>
int getHeight(Node<T>* root) {
    if (!root) {
        return 0;
    }
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

template <typename T>
bool isAvl(Node<T>* root) {
    if (!root) {
        return true;
    }
    if (root->left != nullptr && root->left->data > root->data) {
        return false;
    }
    if (root->right != nullptr && root->right->data < root->data) {
        return false;
    }
    int bf = getHeight(root->left) - getHeight(root->right);
    if (bf < -1 || bf > 1) {
        return false;
    }
    return isAvl(root->left) && isAvl(root->right);
}

int main() {
    Node<int>* root = new Node<int>{ 1, new Node<int>{0,nullptr, nullptr}, new Node<int>{2, nullptr, nullptr} };
    std::cout << isAvl(root);

}