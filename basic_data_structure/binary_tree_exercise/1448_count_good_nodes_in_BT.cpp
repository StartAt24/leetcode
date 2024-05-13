#include "BTree.h"

class Solution {
public:
    int goodNodes(TreeNode* root) {
        traverse(root, -MAX_INT);
        return _res;
    }
private:
    void traverse(TreeNode* node, int maxInPath) {
        if (!node)
            return;
        if (node->val >= maxInPath) {
            _res++;
            maxInPath = node->val;
        }

        traverse(node->left, maxInPath);
        traverse(node->right, maxInPath);
    }

    int _res = 0;
};