#include <iostream>


template <typename T>
struct Node {
    T value;
    Node* next;
};



template <typename T>
void push_front(const T& value, Node<T>*& list) {
    Node<T>* newList = new Node<T>{ value,list };
    list = newList;
}

template <typename T>
Node<T>* reverse(Node<T>*& list) {
    Node<T>* reversed = nullptr;
    if (!list) throw "Empty list";
    while (!list->next) {
        push_front(list->value, reversed);
    }
}

int main() {

}