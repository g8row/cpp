#include <queue>
#include <iostream>


template <typename T>
struct Node {
    T data;
    Node<T>* left, * right;
};

bool isOddEven(Node<int>* root) {
    std::queue<std::pair<int, Node<int>*>> nodes;
    nodes.push(std::pair<int, Node<int>*>{ 0, root});
    std::pair<int, Node<int>*> prev{ 0, nullptr };

    while (!nodes.empty()) {
        std::pair<int, Node<int>*> node = nodes.front();
        nodes.pop();
        if (prev.first != node.first) {
            prev = std::pair<int, Node<int>*>{ node.first, nullptr };
        }
        if (node.first % 2 == 0) {
            if (node.second->data % 2 == 0) {
                return false;
            }
            if (prev.second != nullptr && prev.second->data > node.second->data) {
                return false;
            }
            if (node.second->left != nullptr) {
                nodes.push(std::pair<int, Node<int>*>{ node.first + 1, node.second->left});
            }
            if (node.second->right != nullptr) {
                nodes.push(std::pair<int, Node<int>*>{ node.first + 1, node.second->right});
            }
            prev = node;
        }

        if (node.first % 2 != 0) {
            if (node.second->data % 2 != 0) {
                return false;
            }
            if (prev.second != nullptr && prev.second->data < node.second->data) {
                return false;
            }
            if (node.second->left != nullptr) {
                nodes.push(std::pair<int, Node<int>*>{ node.first + 1, node.second->left});
            }
            if (node.second->right != nullptr) {
                nodes.push(std::pair<int, Node<int>*>{ node.first + 1, node.second->right});
            }
            prev = node;
        }
    }
    return true;
}

int main() {
    //Node<int>* root = new Node<int>{ 1, new Node<int>{10, nullptr, nullptr}, new Node<int>{4, nullptr, nullptr} };
    Node<int>* root = new Node<int>{ 1, new Node<int>{10, new Node<int>{3, new Node<int>{12, nullptr, nullptr}, new Node<int>{8, nullptr, nullptr}}, nullptr}, new Node<int>{20, new Node<int>{7, new Node<int>{6, nullptr, nullptr}, nullptr}, new Node<int>{9, nullptr, new Node<int>{2, nullptr, nullptr}}} };
    std::cout << isOddEven(root);
}