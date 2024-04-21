#include "BTree.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        
        if (root->val > val) 
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);
        // here it means the value equals to the root;
        return root;
    }
};