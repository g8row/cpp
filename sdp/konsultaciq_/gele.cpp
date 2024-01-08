#include <iostream>

//algoritmi
//merge, quick

//linked list
// - const konkatenaciq na dve kolekcii

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
void free(Node<T>*& head) {
    while (!head) {
        Node<T>* next = head->next;
        delete head;
        head = next;
    }
}

template <typename T>
void add(Node<T>*& head, Node<T>*& tail, int value) {
    if (!head) {
        head = new Node<T>{ value, nullptr };
        tail = head;
    }
    else {
        tail->next = new Node<T>{ value, nullptr };
        tail = tail->next;
    }
}

template <typename T>
void add(Node<T>*& head, Node<T>*& tail, Node<T>* element) {
    if (!head) {
        head = element;
        tail = head;
    }
    else {
        tail->next = element;
        tail = tail->next;
    }
}

template <typename T>
void print(Node<T>* head) {
    Node<T>* iter = head;
    while (iter) {
        std::cout << iter->value << " ";
        iter = iter->next;
    }
}

void zad1() {
    int n;
    std::cin >> n;
    Node<int>* list = nullptr;
    Node<int>* end = nullptr;

    for (int i = 0;i < n;i++) {
        int value;
        std::cin >> value;
        add(list, end, value);
    }

    Node<int>* evensBeg = nullptr;
    Node<int>* evensEnd = nullptr;
    Node<int>* oddBeg = nullptr;
    Node<int>* oddEnd = nullptr;

    Node<int>* iter = list;

    while (iter) {
        if (iter->value % 2 == 0) {
            add(evensBeg, evensEnd, iter);
        }
        else {
            add(oddBeg, oddEnd, iter);
        }
        iter = iter->next;
    }

    if (evensEnd) {
        evensEnd->next = nullptr;
    }
    if (oddEnd) {
        oddEnd->next = nullptr;
    }
    if (evensEnd) {
        evensEnd->next = oddBeg;
    }
    list = evensBeg;

    print(list);
    free(list);
}

//zad2

struct Dll {
    int data;
    Dll* next = nullptr;
    Dll* prev = nullptr;
};

Dll* remove(Dll* toRemove) {
    if (toRemove == toRemove->next) {
        delete toRemove;
        return nullptr;
    }
    else if (toRemove->next == toRemove->prev) {
        Dll* toReturn = toRemove->prev;
        toReturn->next = toReturn;
        toReturn->prev = toReturn;
        delete toRemove;
        return toReturn;
    }
    else {
        Dll* prev = toRemove->prev;
        Dll* next = toRemove->next;
        prev->next = next;
        next->prev = prev;
        delete toRemove;
        return prev;
    }
}

unsigned getSize(Dll* list) {
    unsigned size = 0;
    Dll* begin = list;
    do {
        size++;
        list = list->next;
    } while (begin != list);
    return size;
}

void print(Dll* list) {
    if (!list) {
        std::cout << "null";
        return;
    }
    Dll* begin = list;
    do {
        std::cout << list->data << " ";
        list = list->next;
    } while (begin != list);
}

Dll* removeByPred(Dll* begin, bool (*pred) (int, int, int)) {

    Dll* iter = begin;

    unsigned size = getSize(begin);
    for (int i = 0;i < size + 1;i++) {
        if (pred(iter->prev->data, iter->data, iter->next->data)) {
            iter = remove(iter);
            size--;
            i = 0;
        }
        else {
            iter = iter->next;
        }
    }
    return iter;
}

void zad2() {
    Dll* first = new Dll{ 10, nullptr, nullptr };
    Dll* second = new Dll{ 10, nullptr, nullptr };
    Dll* third = new Dll{ 10, nullptr, nullptr };
    Dll* fourth = new Dll{ 1, nullptr, nullptr };
    Dll* fifth = new Dll{ 10, nullptr, nullptr };

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = first;

    first->prev = fifth;
    second->prev = first;
    third->prev = second;
    fourth->prev = third;
    fifth->prev = fourth;

    print(removeByPred(first, [](int a, int b, int c) {return (a + b + c) % 10 == 0;}));
}

//zad3

int getClosingBracket(const std::string& str, int ind) {
    int count = 0;
    for (int i = ind; ;i++) {
        if (str[i] == '(')
        {
            count++;
        }
        else if (str[i] == ')') {
            count--;
            if (count == 0) {
                return i;
            }
        }

    }
}

int calc(const std::string& str) {
    if (str[0] >= '0' && str[0] <= '9') {
        return str[0] - '0';
    }
    if (str.size() == 3) {
        return str[1] - '0';
    }
    if (str[0] == '!') {
        return -calc(str.substr(2, str.size() - 1));
    }
    else {
        bool isPlus = str[1] == '+';
        std::string currentExpr;

        int result = 0;
        bool isFirst = true;

        for (int i = 3; i < str.size(); i++) {
            int closingBracketInd = getClosingBracket(str, i);
            currentExpr = str.substr(i, closingBracketInd - i + 1);
            i = closingBracketInd + 1;
            int data = calc(currentExpr);



            if (isPlus) {
                result += data;
            }
            else {
                if (isFirst) {
                    result += data;
                }
                else {
                    result -= data;
                }
            }

            isFirst = false;
        }
        return result;
    }
}

void zad3() {
    std::cout << calc("(+ (- (6) (5)) (3) (2))");
}
int main() {
    zad3();
}