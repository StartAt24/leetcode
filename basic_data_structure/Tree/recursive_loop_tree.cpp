#include "common_tree.hpp"

void Print(Node* root) {
    vector<int> vals;
    Print(root, vals);
    for (const auto& i: vals) {
        cout << i << endl;
    }
}
//  a
// b c

// 前|中|后 序遍历，指的是 根节点的位置.

// 中序遍历 -> b a c
void Print(Node* node, vector<int>& vals) {
    Print(node->left, vals);
    vals.push_back(node->val);
    Print(node->right, vals);

    return;
}

// 前序遍历 -> a b c
void Print(Node* node, vector<int>& vals) {
    vals.push_back(node->val);
    Print(node->left, vals);
    Print(node->right, vals);

    return;
}


// 后序遍历 ->  b c a
void Print(Node* node, vector<int>& vals) {
    Print(node->left, vals);
    Print(node->right, vals);
    vals.push_back(node->val);

    return;
}