#include <iostream>

template <typename T>
struct DCLE {
    T inf;
    DCLE<T>* next;
    DCLE<T>* prev;
};

template <typename T>
DCLE<T>* remove(DCLE<T>* toRemove) {
    if (toRemove == toRemove->next) {
        delete toRemove;
        return nullptr;
    }
    else if (toRemove->next == toRemove->prev) {
        DCLE<T>* toReturn = toRemove->next;
        toReturn->next = toReturn;
        toReturn->prev = toReturn;
        delete toRemove;
        return toReturn;
    }
    else {
        DCLE<T>* toReturn = toRemove->prev;
        toRemove->next->prev = toRemove->prev;
        toRemove->prev->next = toRemove->next;
        delete toRemove;
        return toReturn;
    }
}
template <typename T>
int getSize(DCLE<T>* begin) {
    if (!begin) {
        return 0;
    }
    int size = 0;
    DCLE<T>* iter = begin;
    do {
        size++;
        iter = iter->next;
    } while (iter != begin);
    return size;
}

template <typename T>
void print(DCLE<T>* begin) {
    if (!begin) {
        std::cout << "null" << std::endl;
    }
    DCLE<T>* iter = begin;
    do {
        std::cout << iter->inf << std::endl;
        iter = iter->next;
    } while (iter != begin);
}

template <typename T>
void free(DCLE<T>* begin) {
    DCLE<T>* iter = begin;
    do {
        delete iter;
        iter = iter->next;
    } while (iter != begin);
}


template <typename T>
DCLE<T>* removeEligable(DCLE<T>* begin) {
    int size = getSize(begin);
    DCLE<T>* iter = begin;
    for (int i = 0;i < size;i++) {
        if (iter->next->inf + iter->prev->inf == iter->inf) {
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

/* int main() {
    DCLE<int>* first = new DCLE<int>{ 2, nullptr, nullptr };
    DCLE<int>* second = new DCLE<int>{ 4, nullptr, nullptr };
    DCLE<int>* third = new DCLE<int>{ 7, nullptr, nullptr };
    DCLE<int>* fourth = new DCLE<int>{ 1, nullptr, nullptr };
    DCLE<int>* fifth = new DCLE<int>{ 3, nullptr, nullptr };
    DCLE<int>* sixth = new DCLE<int>{ 5, nullptr, nullptr };

    first->next = second;
    first->prev = sixth;

    second->next = third;
    second->prev = first;

    third->next = fourth;
    third->prev = second;

    fourth->next = fifth;
    fourth->prev = third;

    fifth->next = sixth;
    fifth->prev = fourth;

    sixth->next = first;
    sixth->prev = fifth;

    print(removeEligable(sixth));


} */