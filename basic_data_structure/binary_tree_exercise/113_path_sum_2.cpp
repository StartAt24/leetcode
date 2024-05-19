#include "BTree.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        _targetSum = targetSum;
        vector<int> values;
        traverse(root, 0, values);
        return _res;
    }
private:
    void traverse(TreeNode* node, int pathSum, vector<int> values) {
        if (!node)
            return;

        pathSum += node->val; 
        values.push_back(node->val);
        if (!node->left && !node->right && pathSum == _targetSum) {
            _res.push_back(values);
            return;
        }

        traverse(node->left, pathSum, values);
        traverse(node->right, pathSum, values);
    }

    vector<vector<int>> _res;
    int _targetSum = 0;
};