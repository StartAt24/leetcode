#define NULL 0

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
//        1 
//   2          3
// 4    5     6   7
//8 9 10 11 12 13 14 15

class Solution {
public:
    Node* connect(Node* root) {
        // every point's left node point to it's right node;
        if(!root)
            return nullptr;
        connect(root->left, root->right);
        return root;        
    }

    void connect (Node* l, Node* r) {
        if (!l || ! r)
            return;

        l->left = r;

        // 链接各自节点的左右节点
        connect(l->left, l->right);
        connect(r->left, r->right);
        // 跨越节点链接。
        // 层数深入之后 这行代码起了主要作用。
        connect(l->right, r->left);
    }
};