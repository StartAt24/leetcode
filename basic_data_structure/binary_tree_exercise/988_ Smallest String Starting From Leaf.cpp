#include "BTree.h"

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        traverse(root, _path);
        return _res;
    }
private:
    void traverse(TreeNode* root, string path) {
        if (!root)
            return;
        path =  string(1 ,'a' + root->val) + path;

        // leaf node
        if (!root->left && !root->right) {
            if (_res.empty() || _res.compare(path) > 0) {
                _res = path;
            }
        }
        traverse(root->left, path);
        traverse(root->right, path);

        path = path.substr(0, 1);
    }
    string _path;
    string _res;
};