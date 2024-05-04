#include "BTree.h"
#include <pair>
#include <queue>
using std::queue;
using std::pair;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        traverse(root);
        return _res;
    }

private:
    void traverse(TreeNode* n) {
        if (!n)
            return;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({n, 1});

        while (!q.empty()) {
            _res = max(_res, q.back().second - q.front().second + 1);
            for (int i = 0; i < cnt; i++) {
                auto& [node, idx] = q.front();
                q.pop();
                if (node->left) {
                    q.push({node->left, idx*2});
                }
                if (node->right) {
                    q.push({node->right, idx*2 + 1});
                }
            }
        }
    }

    int _res{0};
};