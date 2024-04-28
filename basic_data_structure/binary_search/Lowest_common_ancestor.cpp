#include "BTree.h"

// this is a binary tree not BST;
TreeNode* find(TreeNode* root, int val) {
    if(!root)
        return nullptr;
    
    if (root->val == val)
        return root;
    
    auto leftResult = find(root->left, val);
    if (leftResult)
        return leftResult;

    auto rightResult = find(root->right, val);
    if (rightResult)
        return rightResult;

    return nullptr;
}

TreeNode* findCommonAncestor(TreeNode* root, int val1, int val2) {
    if(!root)
        return nullptr;
    
    if (root->val == val1 || root->val == val2)
        return root;
    
    auto leftRes = findCommonAncestor(root->left, val1, val2);
    auto rightRes = findCommonAncestor(root->right, val1, val2);

    return leftRes ? leftRes: rightRes;
}