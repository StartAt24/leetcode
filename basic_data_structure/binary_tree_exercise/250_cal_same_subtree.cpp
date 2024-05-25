#include "BTree.h"

class Solution {
public:
    int maxSubTree(TreeNode* root) {
        nodeCount(root);
        return _res;
    }
private:
    int nodeCount(TreeNode* n) {
        if (!n)
            return 0;
        
        int left = nodeCount(n->left);
        int right = nodeCount(n->right);

        _res = max(_res, left + right + 1);
        return left + right + 1;
    }

    int _res = -1;
};