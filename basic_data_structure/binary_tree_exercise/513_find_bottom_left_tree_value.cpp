#include "BTree.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        traverse(root, 1);
        return _res;
    }
private:
    void traverse(TreeNode* node, int depth) {
        if (!node)
            return;

        if (depth > _maxDepth) {
            _res = node->val;
            _maxDepth = depth;
        }

        traverse(node->left, depth+1);
        traverse(node->right, depth+1);
    }
    int _res;
    int _maxDepth = 0;
};

// 两种解法，一个层序遍历，最后一轮遍历的第一个元素就是 target node;