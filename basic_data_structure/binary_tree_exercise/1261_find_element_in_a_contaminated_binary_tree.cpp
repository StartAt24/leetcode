#include "BTree.h"

class FindElements {
public:
    FindElements(TreeNode* root) {
        restore(root, 0);
    }
    
    bool find(int target) {
        return find(_root, target);
    }

private:
    bool find(TreeNode* node, int target) {
        if (!node)
            return false;

        if (node->val == target){
            return true;
        }
        // 恢复之后 并不是一个二叉搜索树！
        return find(node->right, target) || find(node->right, target);
    }

    void restore(TreeNode* node, int val) {
        if(!node)
            return;
        node->val = val;
        restore(node->left, val*2+1);
        restore(node->right, val*2+2);
    }
};