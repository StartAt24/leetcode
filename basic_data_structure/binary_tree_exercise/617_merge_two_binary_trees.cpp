#include "BTree.h"
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        int val = root1->val + root2->val;
        TreeNode* n = new TreeNode(val);

        n->left = mergeTrees(root1->left, root2->left);
        n->right = mergeTrees(root1->right, root2->right);

        return n;
    }
};