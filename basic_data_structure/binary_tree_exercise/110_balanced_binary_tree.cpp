#include "BTree.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        depth(root);
        return _res;
    }

private:
    int depth(TreeNode* n) {
        if (!n)
            return 0;

        int left = depth(n->left);
        int right = depth(n->right);

        if (abs(left-right) > 1) {
            _res = false;
            return -1;
        }

        return max(left, right) + 1;
    }

    bool _res = true;
};