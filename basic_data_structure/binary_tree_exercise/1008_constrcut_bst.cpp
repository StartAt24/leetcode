#include "BTree.h"
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end)
            return nullptr;
        
        int rootVal = preorder[start];
        TreeNode* root = new TreeNode(rootVal);

        int p = start + 1;
        while (p <= end && preorder[p] < rootVal) {
            p++;
        }
        // [start + 1, p -1 ] 是左子数
        root->left = build(preorder, start + 1, p - 1);
        // [p, end] 是右子树
        root->right = build(preorder, p, end);
        return root;
    }
};