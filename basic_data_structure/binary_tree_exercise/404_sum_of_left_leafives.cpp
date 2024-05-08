#include "BTree.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root);
        return _res;
    }
private:
    void traverse(TreeNode* n) {
        if (!n)
            return;
        auto leftNode = n->left;
        if(leftNode && !leftNode->left && !leftNode->right)
            _res += leftNode->val;

        traverse(n->left);
        traverse(n->right);
    }
    int _res{0};
};