#include "BTree.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // so it include all the right value, from top to bottom;
        // I have to find it's right silibing;
        queue<TreeNode*> nodes;
        if (root)
            nodes.push(root);

        while(!nodes.empty()) {
            auto n = nodes.front();
            _res.push_back(n->val);
            auto size = nodes.size();
            while(size--) {
                auto cur = nodes.front();
                nodes.pop();
                if (cur->right)
                    nodes.push(cur->right);
                if (cur->left)
                    nodes.push(cur->left);
            }
        }

        return _res;
    }
private:
    vector<int> _res;
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        traverse(root);
        return _res;
    }
private:
    void traverse(TreeNode* root) {
        if (!root)
            return;
        _depth++;
        if (_res.size() < depth) {
            _res.push_back(root->val);
        }

        traverse(root->right);
        traverse(root->left);
        _depth--;
    }

    vector<int> _res;
    int _depth = 0;
};