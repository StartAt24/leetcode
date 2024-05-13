#include "BTree.h"

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        traverse(root);
        return _res;
    }
private:
    void traverse(TreeNode* n) {
        if (!n)
            return;
        if (n->val % 2 == 0) {
            _res += grandsonValue(n);
        }
        traverse(n->left);
        traverse(n->right);
    }
    int _res = 0;

    int grandsonValue(TreeNode* n) {
        if (!n)
            return 0;
        int ret = 0;
        if (n->left) {
            if (n->left->left) {
                ret+= n->left->left->val;
            }
            if (n->left->right) {
                ret+= n->left->right->val;
            }
        }

        if (n->right) {
            if (n->right->left) {
                ret += n->right->left->val;
            }
            if (n->right->right) {
                ret += n->right->right->val;
            }
        }
        return ret;
    }
};