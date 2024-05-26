#include "BTree.h"

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traverse(root, low, high);
    }
private:
    TreeNode* traverse(TreeNode* root, int low, int high) {
        if (!root)
            return nullptr;
        
        auto val = root->val;
        if (val < low) {
            // all left should be cut
            return traverse(root->right, low, high);
        }
        if (val > high) {
            return traverse(root->left, low, high);
        }

        root->left = traverse(root->left, low, high);
        root->right = traverse(root->right, low, high);

        return root;
    }
};