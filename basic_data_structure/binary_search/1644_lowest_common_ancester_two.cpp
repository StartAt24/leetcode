#include "BTree.h"

bool foundP = false, foundQ = false;

TreeNode* find(TreeNode* root, int val1, int val2) {
    if (!root)
        return nullptr;
    
    auto left = find(root->left, val1, val2);
    auto right = find(root->left, val1, val2);
    // this is the end node of the whole tree;
    if (left && right)
        return root;

    // 因为是从下往上递归的，所以返回的永远是比较靠近root的值 
    // 假设两个节点中，有一个是lowest ancester, 那么返回的肯定是靠近root的 即符合要求
    if (root->val == val1 || root->val == val2) {
        if (root->val == val1) foundP = true;
        if (root->val == val2) foundQ = true;
    }

    return left ? left : right;
}