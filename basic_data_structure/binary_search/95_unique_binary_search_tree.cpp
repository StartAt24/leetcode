#include "BTree.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        // 假设这个数是 [1,2]
        // 则以1为root 就一种情况，以2为root 也是一种情况





    }
private:
    TreeNode* generateTrees(int l, int r) {
        if (l > r)
            return nullptr;
        generateTrees();
    }
    vector<vector<int>> _cache(9, vector<int>(9, 0));
};
