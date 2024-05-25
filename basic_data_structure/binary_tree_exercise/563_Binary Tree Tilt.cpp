#include "BTree.h"

class Solution {
public:
    int findTilt(TreeNode* root) {
        sum(root);
        return _res;
    }
private:
    int sum(TreeNode* root) {
        if (!root)
            return 0;
            
        int left = sum(root->left);
        int right = sum(root->right);
        _res += abs(left-right);

        return left + right + root->val;
    }

private:
    int _res = 0;
};