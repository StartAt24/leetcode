#include "BTree.h"

class Solution {
public:
    TreeNode* closestNode(TreeNode* root) {

    }
private:
    void Traverse(TreeNode* node, TreeNode* target) {
        queue<TreeNode*> que;
        que.push(node);

        while(!que.empty()) {
            int currentSize = que.size();
            for(int i = 0; i < currentSize; i++) {
                auto n = que.front();
                que.pop();
                if (n->val == target->val) {
                    if (i + 1 < currentSize) {
                        _res = que.front();
                    } else {
                        _res = nullptr;
                    }
                    return;
                }

                if (n->left) {
                    que.push(n->left);
                }

                if (n->right) {
                    que.push(n->right);
                }
            }
        }
    }

    // 先序遍历的结果，当第二次遍历到同一个层级的时候，就是上一次这个层级的 右侧节点。
    void Traverse(TreeNode* node, TreeNode* target, int depth) {
        if (!node)
            return;

        if (_depth == depth) {
            _res = node;
            return;
        }

        if (node->val == target->val) {
            _depth = depth;
        }
        Traverse(node->left, target, depth+1);
        Traverse(node->right, target, depth+1);
    }
    int _depth = -1;

    TreeNode* _res = nullptr;
}