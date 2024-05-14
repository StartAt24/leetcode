#include "BTree.h"

class Solution {
public:
    vector<int> singleNode(TreeNode* root) {
        traverse(root);
        return _res;
    }
private:
    void traverse(TreeNode* node) {
        if (!node)
            return;
        
        if (!node->left && node->right) {
            _res.push_back(node->right->val);
        }

        if (node->left && !node->right) {
            _res.push_back(node->left->val);
        }

        traverse(node->left);
        traverse(node->right);
    }
    vector<int> _res;
}