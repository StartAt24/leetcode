#include "BTree.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.emplace_back(nullptr);
            return res;
        }

        for (int i = l; i <= r; i++) {
            auto leftTrees = generateTrees(l, i-1);
            auto rightTrees = generateTrees(i+1, r);

            for (const auto& left : leftTrees) {
                for (const auto& right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.emplace_back(root);
                }
            }
        }
        return res;
    }
};
// assume [1,2]
// it has two unique BST.
// i = 1; i <=2; i++
// generateTrees(1, 0) -> {nullptr}
// generateTrees(2, 2) -> i =2; i<=2 -> 2,1, 3,2 -> {nullptr}, {nullptr}
