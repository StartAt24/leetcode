#include "BTree.h"
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }

        traverse(root, val, depth, 1);
        return root;
    }
private:
    void traverse(TreeNode* n, int val, int depth, int currentDepth) {
        if (!n)
            return;
        if (currentDepth == depth - 1) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            leftNode->left = n->left;
            n->left = leftNode;
            rightNode->right = n->right;
            n->right = rightNode;
        }
        currentDepth++;
        traverse(n->left, val, depth, currentDepth);
        traverse(n->right, val, depth, currentDepth);
    }
};