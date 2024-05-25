#include "BTree.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        onSideMax(root);
        return _res;
    }
    int onSideMax(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftMaxSum = max(0, onSideMax(root->left));
        int rightMaxSum = max(0, onSideMax(root->right));
        int pathMaxSum = root->val +leftMaxSum + rightMaxSum;
        _res = max(_res, pathMaxSum);

        return max(leftMaxSum, rightMaxSum) + root->val;
    }
private:
    int _res = INT_MIN;
};