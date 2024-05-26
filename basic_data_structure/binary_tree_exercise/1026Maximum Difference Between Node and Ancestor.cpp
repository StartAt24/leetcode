#include "BTree.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        minMax(root);
        return _res;
    }
private:
    std::pair<int, int> minMax(TreeNode* root) {
        if(!root)
            return {0, 0};
        
        auto [leftMin, leftMax] = minMax(root->left);
        auto [rightMin, rightMax] = minMax(root->right);

        minVal = min(leftMin, rightMin);
        maxVal = max(leftMax, rightMax);

        _res = max(abs(root->val - minVal), abs(root->val - maxVal));

        return {min(leftMin, rightMin, root->val), max(leftMax, rightMax, root->val)};
    }

    int _res = 0;
};