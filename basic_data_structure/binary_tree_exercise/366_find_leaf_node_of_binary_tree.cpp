#include "BTree.h"
class Solution {

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        maxDepth(root);
        return res;
    }
private:
    // get the height of a node
    int maxHeight(TreeNode* root) {
        if (!root)
            return 0;
        
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);

        // current height;
        int h = max(left, right);

        // allocate space
        if (_res.size() < h) {
            res.push_back(vector<int>());
        }
        // push to the final result
        res[h-1].push_back(root->val);

        return h;
    }
    vector<vector<int>> _res;
};