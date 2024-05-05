#include "BTree.h"
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        traverse(root);
        return _sum;
    }
private:
    void traverse(TreeNode* root) {
        if (!root)
            return;
        
        _path += to_string(root->val);
        // leaf node;
        if (!root->left && !root->right) {
            _sum += stoi(_path, nullptr, 2);
        }

        traverse(root->left);
        traverse(root->right);

        _path.pop_back();
    }
    string _path;
    int _sum{0};
};