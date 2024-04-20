#include "BTree.h"

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        // need to know the sum of its right sub tree
        traverse(root);
        return root;
    }
private:
    // used to record the sum of all greater numbers.
    int _sum = 0;

    void traverse(TreeNode* root) {
        if (!root)
            return;
        // first right node, then mid, then left;
        // it will loop all element from max to min;
        traverse(root->right);
        // 目前用的这个方法 只关注当前节点这一个节点的信息 以及一个额外的 比他大的数字的和，
        // 所以就算改变了右侧节点的值 也无所谓。
        _sum+= root->val;
        root->val = _sum;
        traverse(root->left);
    }
};