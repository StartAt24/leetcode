#include "BTree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        
        if (root->val == p->val || root->val == q->val)
            return root;
        
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        // why left or right return the top node?g
        if (left && right)
            return root;
        
        return left ? left : right;
    }
};