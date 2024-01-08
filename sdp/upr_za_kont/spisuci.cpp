#include <iostream>

//linked list
template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
void add(Node<T>*& head, T value) {
    if (!head) {
        head = new Node<T>({ value, nullptr });
    }
    else {
        Node<T>* iter = head;
        while (iter->next) {
            iter = iter->next;
        }

        iter->next = new Node<T>({ value, nullptr });
    }
}

template <typename T>
Node<T>* at(Node<T>* head, int index) {
    if (head == nullptr || index < 0) {
        throw "invalid list or index";
    }
    int currIndex = 0;
    Node<T>* currNode = head;
    while (currNode->next != nullptr && currIndex < index) {
        currNode = currNode->next;
        currIndex++;
    }
    if (currIndex == index) {
        return currNode;
    }
    else {
        throw "index out of bounds";
    }
}

template <typename T>
void remove(Node<T>*& head, int index) {
    if (head == nullptr || index < 0) {
        throw "invalid list or index";
    }
    int currIndex = 0;
    Node<T>* prevNode = nullptr;
    Node<T>* currNode = head;
    while (currNode->next != nullptr && currIndex < index) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currIndex == index) {
        if (index == 0) {
            head = head->next;
        }
        else {
            prevNode->next = currNode->next;
        }
        delete currNode;
    }
    else {
        throw "index out of bounds";
    }
}

void zad1() {
    int n, m;
    std::cin >> n >> m;
    Node<int>* list = nullptr;

    for (int i = 0;i < n;i++) {
        add(list, 3);
    }

    for (int i = 0; i < m; i++) {
        int saksii;
        std::cin >> saksii;

        for (int j = 0;j < saksii;j++) {
            int index;
            std::cin >> index;
            try {
                at(list, index - 1)->value = 4;
            }
            catch (const char* e) {

            }
        }

        int currIndex = 0;
        Node<int>* iter = list;

        while (iter) {
            if (iter->value - 1 == 0) {
                iter = iter->next;
                remove(list, currIndex);
            }
            else {
                iter->value--;
                iter = iter->next;
                currIndex++;
            }
        }
    }

    Node<int>* iter = list;
    int res = 0;
    while (iter) {
        res++;
        iter = iter->next;
    }
    std::cout << res;
}



int main() {
}