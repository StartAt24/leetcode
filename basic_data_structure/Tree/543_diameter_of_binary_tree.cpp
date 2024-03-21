#include "BTree.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // find the longest of left tree and right tree;
        height(root);
        return _maxDiameter;
    }
private:
    int height(TreeNode* n) {
        if (!n)
            return 0;
        int leftMax = height(n->left);
        int rightMax = height(n->right);

        int maxDiameter = leftMax+rightMax;
        _maxDiameter = max(maxDiameter, _maxDiameter);
        return 1 + max(leftMax, rightMax);
    }
    int _maxDiameter = 0;
};