template <typename T>
class List {
    struct Node
    {
        T value;
        Node* next;
        Node(const T& value, Node* next = nullptr) value(value), next(next) {}

        Node* copy(Node* other) {
            if (!other) return nullptr;
            return new Node(other->value, copy(other->next))
        }
    };
    Node* first;
    Node* last;

    void copy(Node* other) {
        if (!other) return;
        push_back(other->value);
        copy(other->next);
    }

    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

    bool empty() const {
        return first == nullptr;
    }

    List() : first(nullptr), last(nullptr) {}

    List(const List& other) : first(nullptr), last(nullptr) {
        copy(other);
    }
    ~List() {
        clear(first);
    }

    void pop_back() {
        if (empty()) throw "Empty list";
        Node* iter = first;
        while (iter->next) {
            if (!iter->next->next) {
                iter->next = nullptr;
            }
            iter = iter->next;
        }
        delete last;
    }

    void push_back(const T& value) {
        Node* to_add = new Node(value);
        if (empty()) {
            first = to_add;
        }
        else {
            last->next = to_add;
        }
        last = to_add;
    }
    void push_front(const T& value) {
        Node* to_add = new Node(value, first);
        first = to_add;
    }

    List<T>& operator=(const List<T>& other) {
        if (this != other) {
            clear();

        }
    }

    const T& front() const {
        if (empty()) throw "Empty list";
        return first->value;
    }

    const T& back() const {
        if (empty()) throw "Empty list";
        return last->value;
    }

};