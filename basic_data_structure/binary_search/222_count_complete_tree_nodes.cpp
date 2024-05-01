#include "BTree.h"
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// perfect binary tree;
class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        return std::pow(2, h) - 1;
    }
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int val = 1;
        while (root->left) {
            val++;
            root = root->left;
        }
        return val;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int left_h = height(root->left);
        int right_h = height(root->right);
        if (left_h == right_h)
            return pow(2,h) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int val = 1;
        while (root->left) {
            val++;
            root = root->left;
        }
        return val;
    }
};