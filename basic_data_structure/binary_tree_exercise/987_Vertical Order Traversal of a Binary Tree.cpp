#include "BTree.h"
 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        for (auto&[k, v] : _cache) {
            std::sort(v.begin(), v.end());
            _res.push_back(v);
        }
        return _res;
    }

private:
    void traverse(TreeNode* node, int row, int col) {
        if (!node)
            return;

        _cache[col].push_back(node->val);

        traverse(node->left, row+1, col-1);
        traverse(node->right, row+1, col+1);
    }

    map<int, vector<int>> _cache;
    vector<vector<int>> _res;
};