#include "BTree.h"

int count(TreeNode* root) {
    if (!root)
        return 0;

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}