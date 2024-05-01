#include "BTree.h"
#include <set>
#include <vector>
using std::vector;
using std::set;

TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    unordered_set<int> values(nodes.begin(), nodes.end());
    return find(root, values);
}

TreeNode* find(TreeNode* root, unordered_set<int>& values) {
    if (!root)
        return nullptr;
    
    if (values.count(root->val)) {
        return root;
    }

    auto left = find(root->left, values);
    auto right = find(root->right, values);

    if (left && right)
        return root;
    
    return left ? left : right;
}