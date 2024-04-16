#include "BTree.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        _nth = k;
        traverse(root);
        return _res;
    }
private:
    void traverse(TreeNode* node) {
        if (!node)
            return;
        traverse(node->left);
        _count++;
        if(_nth == _count) {
            _res = node->val;
            return;
        }
        traverse(node->right);
    }
    int _nth = 0;
    int _count = 0;
    int _res = -1;
};