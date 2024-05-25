#include "BTree.h"

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);
        
    }
private:
    int sum(TreeNode* root) {
        if (!root)
            return 0;

        int left = sum(root->left);
        int right = sum(root->left);
        int sumVal = left + right + root->val;
        _cache[sumVal]++;

        return sumVal;
    }
    unordered_map<int, int> _cache;
    vector<int> _res;
};