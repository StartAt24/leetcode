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

TreeNode* maxNode(TreeNode* node) {
    if (!node || !node->right)
        return node;
    return maxNode(node->right);
}

TreeNode* remove(TreeNode* root, int val) {
    // not found
    if (!root)
        return nullptr;

    if (root->val > val) {
        return remove(root->left, val);
    }
    if (root->val < val) {
        return remove(root->right, val);
    }

    // root->val = val
    // root is the leaf node, remove it directly
    if (!root->left && !root->right)
        return nullptr;

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
    auto max_node = maxNode(root->left);
    root->left = remove(root->left, max_node->val);

    // 指针操作, 可以避免把二叉树中的值拷贝 带来的object copy的问题。
    max_node->left = root->left;
    max_node->right = root->right;
    root = max_node;

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