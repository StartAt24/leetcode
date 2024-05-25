#include "BTree.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        _targetSum = targetSum;
        return path(root, 0);
    }

private:
    bool path(TreeNode* root, int targetVal) {
        if (!root)
            return false;
        // leaf node
        if (root && !root->left && !root->right && root->val == targetVal) {
            return true; 
        }

        auto left = path(root->left, targetVal - root->val);
        auto right = path(root->right, targetVal - root->val);

        return left || right;
    }
    int _targetSum;
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        _targetSum = targetSum;
        path(root, 0);
        return _res;
    }

private:
    void path(TreeNode* root, int pathLen) {
        if (!root)
            return;
        // leaf node
        if (root && !root->left && !root->right) {
            pathLen += root->val;
            if (pathLen == _targetSum)
                _res = true;
        }
        path(root->left, pathLen+root->val);
        path(root->right, pathLen+root->val);
    }
    bool _res = false;
    int _targetSum;
};