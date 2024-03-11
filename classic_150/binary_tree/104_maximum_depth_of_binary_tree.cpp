#include "Btree.h"
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return maxDepth2(root, 0);
    }

private:
    int maxDepth2(TreeNode* n, int d) {
        if (!n->left && !n->right)
            return d + 1;

        int leftDepth = 0, rightDepth = 0;
        if (n->left) {
            leftDepth = maxDepth2(n->left, d+1);
        }

        if (n->right) {
            rightDepth = maxDepth2(n->right, d+1);
        }
        return max(leftDepth, rightDepth);
    }
};

class Solution{
    public:
    int maxDepth(TreeNode* root){
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
}