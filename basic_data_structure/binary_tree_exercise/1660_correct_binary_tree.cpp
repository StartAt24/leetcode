#include "BTree.h"
class Solution{
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (!root)
            return nullptr;
        
        // error node
        if(root->right && _cache.count(root->right->val)) {
            return nullptr;
        }

        _cache.insert(root->val);
        
        // right child first to ensure right is the fisrt one to visit;
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);

        return root;
    }
private:
    std::unordered_set<int> _cache;
};