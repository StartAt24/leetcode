#include "BTree.h"
class Solution {
private:
    TreeNode* _resNode;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode* dummyNode = new TreeNode(-1);
        _resNode = dummyNode;
        traverse(root);
        return _resNode;
    }

    void traverse(TreeNode* n) {
        if (!n)
            return;

        traverse(n->left);
        _resNode->right = node;
        node->left = nullptr;
        resNode = resNode->right;
        traverse(n->right);
    }
};