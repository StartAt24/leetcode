#include "BTree.h"

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        traverse(root, x, y, 1, -1);
        auto [x_depth, x_parent] = _x;
        auto [y_depth, y_parent] = _y;
        if (x_depth == y_depth && x_parent != y_parent) {
            return true;
        }
        return false;
    }
private:
    void traverse(TreeNode* node, int x, int y,int depth, int parent) {
        if (!node)
            return;
        
        if (node->val == x) {
            _x = std::make_pair(depth, parent);
        }
        if (node->val == y) {
            _y = std::make_pair(depth, parent);
        }

        traverse(node->left, x, y, depth+1, node->val);
        traverse(node->right, x, y, depth+1, node->val);
    }

    std::pair<int, int> _x;
    std::pair<int, int> _y;
};