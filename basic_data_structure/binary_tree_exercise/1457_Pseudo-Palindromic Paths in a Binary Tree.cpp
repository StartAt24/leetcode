#include "BTree.h"
#include <map>
using std::unordered_map;
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {

    }
private:
    bool isPsedudoPalindromic() {
        int odd = 0;
        for (int i = 1; i <= 9; i++) {
            if(_count[i] % 2 != 0) {
                odd++; 
            }
        }

        if (odd > 1) {
            return false;
        } 

        return true;
    }

    void traverse(TreeNode* root) {
        if (!root)
            return;
        
        _count[root->val]++;

        if (!root->left && !root->right) {
            if (isPsedudoPalindromic())
                _res++;

            _count[root->val]--;
            return;
        }

        traverse(root->left);
        traverse(root->right);
        _count[root->val]--;
    }

    int _res{0};
    int _count[10]{0};
};