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

    // 将当前的节点的idx，从父节点传递下去，以及depth
    void traverse2(TreeNode* n, int id, int depth) {
        if (!n)
            return;
        // 这里是最左侧的节点，并且因为是先左后右的递归顺序，所以 必定是左侧第一个节点先进去的
        if (_firstId.size() == depth-1) {
            firstId.push_back(id);
        } else {
            _maxWidth = max(_maxWidth, id-_firstId[depth] + 1);
        }

        traverse2(root->left, id*2, depth+1);
        traverse2(root->right, id*2 + 1, depth+1);
    }
    int _maxWidth = 0;
    // 记录最左侧节点的编号
    vector<int> _firstId;

    int _res{0};
};