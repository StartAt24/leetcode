#include "BTree.h"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

    }

private:
    bool traverse(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2)
            return true;

        if (n1 && !n2)
            return false;

        if (!n1 && n2)
            return false;
        
        if (n1->val != n2->val)
            return false;
        
        return traverse(n1->left, n2->left) && traverse(n1->right, n2->right);
    }
    
};