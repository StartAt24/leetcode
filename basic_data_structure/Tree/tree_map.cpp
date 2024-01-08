#include <map>
#include <vector>
using std::vector;

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

    // remove k and return deleted value;
    int Remove(int k) {
        Remove(_root, k);
    }

    Node* Remove(Node* node, int k) {
        if (k > node->key) {
            node->right = Remove(node->right, k);
        } else if (k < node->key) {
            node->left = Remove(node->left, k);
        } else {
            // 找到了当前的元素，需要删除
            // 删除有三种情况。
            // 1.元素为叶子节点，直接删除即可
            // 2.元素的左右子树其中一个为nullptr, 直接将另一个子树接在父节点的相同位置上
            // 这段代码也同时处理了 情况1.
            if (node->left == nullptr)
                return node->right;
            if (node->right == nullptr)
                return node->left;

            // 两个子树均不为空，这个时候需要将左子树的最大节点 或者 右子树的最小节点与当前节点交换，
            // 来保持BST的定义
            Node* maxLeft = MaxNode(node->left);
            node->left = RemoveMax(node->left);
            node = maxLeft;
        }

        return node;
    }

    void RemoveMin() {
        if (IsEmpty()) {
            return;
        }
        _root = RemoveMin(_root);
    }

    Node* RemoveMin(Node* node) {
        // if the node is the most left one, need to return the right one 
        // to keep the struct of the tree.
        if (node->left == nullptr) {
            return node->right;
        }

        node->left = RemoveMin(node->left);

        return node;
    }

    int FloorKey(int key) {
        return FloorKey(key, _root)->key;
    }

    vector<int> Keys() {
        vector<int> vec;
        Keys(_root, vec);
        return vec;
    }

    void Keys(Node* node, vector<int>& vec) {
        Keys(node->left, vec);
        vec.push_back(node->key);
        Keys(node->right, vec);
    }

    Node* FloorKey(int key, Node* node) {
        // key not exist;
        if (node == nullptr)
            return nullptr;

        // key may exist in right tree;
        if (key > node->key) {
            // 如果右子树里不存在floorkey的话，当前这个node就是小于key的存在的最大key。
            auto n =  FloorKey(key, node->right);
            if (n == nullptr) {
                return node;
            }
            return n;
        }

        // key may exisit in left tree;
        if (key < node->key) {
            return FloorKey(key, node->left);
        }

        return node;
    }

    Node* CeilingKey(int key) {
        return CeilingKey(key, _root);
    }
    
    Node* CeilingKey(int key, Node* node) {
        // key not exist;
        if (node == nullptr)
            return nullptr;

        // key may exist in right tree;
        if (key > node->key) {
            auto n =  FloorKey(key, node->right);
            return n;
        }

        // key may exisit in left tree;
        // 如果左子树里不存在floorkey的话，当前这个node就是小于key的存在的最大key。
        if (key < node->key) {
            auto n =  FloorKey(key, node->right);
            if (n == nullptr) {
                return node;
            }
            return n;
        }

        return node;
    }

    void RemoveMax() {
        if (IsEmpty()) {
            return;
        }
        _root = RemoveMax(_root);
    }

    Node* RemoveMax(Node* node) {
        if (node->right == nullptr)
            return node->left;
        
        node->right = RemoveMax(node->right);                                   `
        return node;
    }

private:
    Node* MaxNode(Node* node) {
        while(node->right) {
            node = node->right;
        }
        return node;
    }

    bool IsEmpty () {
        return _size == 0;
    }

private:
    Node* _root = nullptr;
    int _size = 0;
};