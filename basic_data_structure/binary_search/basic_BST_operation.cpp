#include "BTree.h"

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (root->val > val) {
        return insert(root->left, val);
    }

    if (root->val < val) {
        return insert(root->right, val);
    }

    return root;
}

TreeNode* minNode(TreeNode* node) {
    if (!node->left)
        return node;
    return minNode(node->left);
}

TreeNode* deleteNode(TreeNode* root, int key) {
    // not found
    if (!root)
        return nullptr;

    if (root->val > key) {
        root->left =  deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        // 如果只有一个存在的话, 因为前面已经排除了两者均为空的情况了。
        // 但是不能用下面这个写法，因为这个不能排除两者都为空的情况。应该改为判断哪个不存在
        // 即这种case下 可以说明至少有一个子节点是空的
        // if (root->right) 
        //     return root->right;
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        // both left and right exist 
        // swap max value of left tree or min value of right tree;
        auto min_n = minNode(root->right);
        root->right = deleteNode(root->right, min_n->val);

        // 指针操作, 可以避免把二叉树中的值拷贝 带来的object copy的问题。
        min_n->left = root->left;
        min_n->right = root->right;
        root = min_n;
    }
    
    return root;
}

TreeNode* find(TreeNode* root, int val) {
    if(!root)
        return nullptr;
    
    if (root->val > val) {
        find(root->left, val);
    }
    if (root->val < val) {
        find(root->right, val);
    }
    return root;
}

void modify(TreeNode* root, int oldVal, int newVal) {
    auto n = find(root, oldVal);
    if (!n)
        return;
    n->val = newVal;    
}