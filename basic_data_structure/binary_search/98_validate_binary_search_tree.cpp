#include <BTree.h>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        isValid(root);
        return _res;
    }
private:
    int _preNum  = 0;
    bool _res = true;
    bool _firstOne = true;
    void isValid(TreeNode* root) {
        if (!root) {
            return;
        }
        isValid(root->left);
        if (_firstOne) {
            _firstOne = false;
            _preNum = root->val;
        }
        else {
            if (root->val <= _preNum) {
                _res = false;
                return;
            }
            _preNum = root->val;
        }
        isValid(root->right);
    }

    // 这种验证方式实际上是 只考虑当前这个节点的情况，当前节点的值 怎么样才算合理。
    // 实际是从BinarySearch Tree的定义出发的。
    bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root)
            return true;
        if (min && root->val <= min->val)
            return false;
        if (max && root->val >= max->val)
            return false;
        return isValid(root->left, min, root) && isValid(root->right, root, max);
    }
};
