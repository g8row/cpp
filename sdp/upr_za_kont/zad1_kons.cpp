#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template<typename T>
void push(Node<T>*& head, T value) {
    if (!head) {
        head = new Node<T>{ value, nullptr };
    }
    else {
        Node<T>* temp = head;
        head = new Node<T>{ value, temp };
    }
}

template <typename T>
T top(Node<T>* head) {
    if (!head) throw "nullptr head";
    return head->value;
}

template <typename T>
void pop(Node<T>*& head) {
    if (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void clear(Node<T>*& head) {
    while (!head) {
        pop(head);
    }
}

void split(std::string input, Node<int>*& numbers, Node<char>*& operations) {
    if (input.empty()) {
        return;
    }
    int index = 0;
    int number = 0;
    while (index < input.length()) {
        switch (input[index]) {
        case '+':
        case '-':
        case '/':
        case '*': {
            push(operations, input[index]);
            index++;
            break;
        }
        case ' ': index++; break;
        default: {
            while (input[index] != ' ') {
                number = number * 10 + (input[index] - 48);
                index++;
            }
            push(numbers, number);
            number = 0;
        }
        }
    }
}

int calculate(Node<int>*& numbers, Node<char>*& operations) {
    while (operations)
    {
        int y = top(numbers);
        pop(numbers);
        int x = top(numbers);
        pop(numbers);

        switch (top(operations)) {
        case '+': x += y; break;
        case '-': x -= y; break;
        case '/': x /= y; break;
        case '*': x *= y; break;
        }
        pop(operations);
        push(numbers, x);
    }
    int result = top(numbers);
    clear(numbers);
    return result;
}

