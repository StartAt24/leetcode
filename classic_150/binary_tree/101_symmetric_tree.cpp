#include "BTree.h"
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return dfs(root->left, root->right);
    }
private:
    bool dfs(TreeNode* left, TreeNode* right) {
        // 两者都是null 则想等
        if (left == nullptr && right == nullptr)
            return true;
        
        // 其中有一个是nullptr
        if (left == nullptr || right == nullptr)
            return false;
        
        if (left->val != right->val)
            return false;
        
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};