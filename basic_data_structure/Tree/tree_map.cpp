#include <map>

struct Node {
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int k, int v) : key(k), val(v) {

    }

    int val;
    int key;
};

class TreeMap {
public:
    TreeMap() {

    }

    ~TreeMap() {

    }

    void Put(int k, int v) {
        _root = Put(k, v, _root);
    }

    Node* Put(int k, int v, Node* node) {
        if (node == nullptr) {
            _size++;
            return new Node(k, v);
        }

        if (k > node->key) {
            node->right = Put(k, v, node->right);
        }

        if (k < node->key) {
            node->left = Put(k, v, node->left);
        }

        if (k == node->key) {
            node->val = v;
        }

        return node;
    }

    int Get(int k) {
        return Get(k, _root);
    }

    int Get(int k, Node* node) {
        // key not exist;
        if (node == nullptr)
            return -1;

        // key exist;
        if (node->key == k)
            return node->val;
        
        // key may exist in right tree;
        if (k > node->key) {
            return Get(k, node->right);
        }

        // key may exisit in left tree;
        if (k < node->key) {
            return Get(k, node->left);
        }
    }

    void RemoveMin() {
        if (IsEmpty()) {
            return;
        }

    }

    void RemoveMax() {
        if (IsEmpty()) {
            return;
        }

    }

private:
    bool IsEmpty () {
        return _size == 0;
    }

private:
    Node* _root = nullptr;
    int _size = 0;
};