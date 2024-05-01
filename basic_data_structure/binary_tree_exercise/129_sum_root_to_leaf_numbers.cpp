#include "BTree.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        string path;
        traverse(root, path);
        int result = 0;
        for(auto& s : _res) {
            result += std::stoi(s);
        }
        return result;
    }

private:
    void traverse(TreeNode* root, string path) {
        if (!root)
            return;
        // leaf node
        if (!root->left && !root->right) {
            path += to_string(root->val);
            _res.push_back(path);
        }
        path += to_string(root->val);
        traverse(root->left, path);
        traverse(root->right, path);
    }
    vector<string> _res;
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        
    }
    void traverse(TreeNode* root) {
        if (!root)
            return;

        path += to_string(root->val)
        if (!root->left && !root->right) {
            res += std::stoi(path);
            return;
        }
        traverse(root->left);
        traverse(root->right);
        path.pop_back();
    }
private:
    string path;
    int res{0};
};