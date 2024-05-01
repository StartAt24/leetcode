#include "BTree.h"
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        traverse(root, path);
        return _res;
    }
private:
    void traverse(TreeNode* root, string path) {
        if (!root->left && !root->right) {
            if (!path.empty()) {
                path.pop_back();
                path.pop_back();
                _res.push_back(path);
            }
            return;
        }

        path += to_string(root->val);
        path += "->";
        traverse(root->left, path);
        traverse(root->right, path);
    }

    vector<string> _res;
};