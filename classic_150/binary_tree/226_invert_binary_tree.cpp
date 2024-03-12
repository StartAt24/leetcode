#include "BTree.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)        
            return nullptr;

        TreeNode* l = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(l);

        return root;
    }
private:
    void swap(TreeNode* n) {
        TreeNode* l = n->left;
        n->left = n->right;
        n->right = l;
    }
};