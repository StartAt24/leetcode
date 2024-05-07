#include "BTree.h"
class Solution{
    public:
        int closetest(TreeNode* root, int target) {
            
        }
    private:
    void traverse(TreeNode* n, int target) {
        if (!n)
            return;
        
        if (abs(n->val - target) < abs(_res - target)) {
            _res = n->val;
        }
        if (n->val < target) {
            traverse(n->right, target);
        } else {
            traverse(n->left, target);
        }
    }

    int _res = INT_MAX;
};