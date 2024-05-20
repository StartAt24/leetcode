#include "BTree.h"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return false;
        _subRoot = subRoot;
        return traverse(root);
    }

private:
    TreeNode* _subRoot = nullptr;

    bool traverse(TreeNode* node) {
        if (!node)
            return false;

        if (node->val == _subRoot->val) {
            if(traverse(node, _subRoot))
                return true;
        }

        return traverse(node->left) || traverse(node->right);
    }

    bool traverse(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2)
            return true;

        if (!n2 || !n1)
            return false;
        
        if (n1->val != n2->val)
            return false;
        
        return traverse(n1->left, n2->left) && traverse(n1->right, n2->right);
    }
    
};