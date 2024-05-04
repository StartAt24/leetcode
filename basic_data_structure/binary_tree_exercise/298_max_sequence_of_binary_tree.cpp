#include "Btree.h"

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        traverse(root, INT_MIN, 1);
        return _res;
    }
private:
    void traverse(TreeNode* n, int val, int len) {
        if (!n)
            return;
        if (n->val == val) {
            len++;
        } else {
            len = 1;
        }
        _res = max(_res, len);

        traverse(n->left, n->val + 1, len);
        traverse(n->right, n->val + 1, len);
    }
    int _res = 0;
};