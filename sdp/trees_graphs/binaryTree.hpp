#ifndef _B_TREE_
#define _B_TREE_

template <typename T>
class BTree {
    T value;
    BTree<T>* left;
    BTree<T>* right;

    void copy(const BTree<T>& tree) {
        this->value = tree.value;
    }

    void clear() {
        if (left) {
            left->clear();
            delete left;
        }

        if (right) {
            right->clear();
            delete right;
        }
    }

public:
    BTree(const T& value) : value(value), left(nullptr), right(nullptr);
    BTree(const BTree<T>&);
    BTree<T>& operator= (const BTree<T>&);
    ~BTree() {
        clear();
    }

    void add(BTree<T>* child, const BTree<T>* othre)

        void addLeft(const BTree<T>* tree) {
        if (this->left) {
            delete this->left;
        }
        this->left = new BTree<T>(tree->value);
        if (tree->left) {
            this->left->addLeft(tree->left);
        }
        if (tree->right) {
            this->left->addRight(tree->right);
        }
    }

    void addRight(const BTree<T>* tree) {
        if (this->right) {
            delete this->right;
        }
        this->left = new BTree<T>(tree->value);
        if (tree->left) {
            this->left->addLeft(tree->left);
        }
        if (tree->right) {
            this->left->addRight(tree->right);
        }
    }

};


#endif 