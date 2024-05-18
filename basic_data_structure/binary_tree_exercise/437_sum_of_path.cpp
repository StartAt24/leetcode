#include "BTree.h"
#include <map>
using namespace std;
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> m;
        m[0] = 1;
        traverse(root, targetSum, 0, m)
        return _res;
    }


private:
    void traverse(TreeNode* node, int targetSum, int sum, unordered_map<long long, int> m) {
        if (!node)
            return;

        sum += node->val; 
        long long targetVal = sum - targetSum;
        if(m.contains(targetVal)) {
            _res += m[targetVal];
        }

        m[sum]++;
        traverse(node->left, targetSum, sum, m);
        traverse(node->right, targetSum, sum, m);
    }

    int _res = 0;
};