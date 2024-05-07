#include "BTree.h"
class Solution{
    public:
        int closetest(TreeNode* root, int target) {
            
        }
    private:
    void traverse(TreeNode* n, int target) {
        if (!n)
            return;
        
        if (abs(n->val - target) < abs(_res - target)) {
            _res = n->val;
        }
        if (n->val < target) {
            traverse(n->right, target);
        } else {
            traverse(n->left, target);
        }
    }

    int _res = INT_MAX;
};

// 只要是从小到大的顺序遍历，那么第一个更新的就是比较小的那个值
void traverse(TreeNode* n, int target) {
    if (!n)
        return;
    
    if (n->val > target) {
        traverse(n->left, target);
        // 这个位置是 中序遍历的位置
        if(abs(n->val - target) < abs(_res - target)) {
            _res = n->val;
        }

    } else {
        // 这个位置， 也是中序位置
        if(abs(n->val - target) < abs(_res - target)) {
            _res = n->val;
        }
        traverse(n->right, target);
    }
}