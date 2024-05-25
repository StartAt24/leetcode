#include "BTree.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        path(root);
        return _res;
    }


    int path(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = path(root->left);
        int right = path(root->right);

        int currentPath = left + right;

        _res = max(currentPath, _res);
        return 1 + max(left, right);
    }
private:
    int _res = 0;
};