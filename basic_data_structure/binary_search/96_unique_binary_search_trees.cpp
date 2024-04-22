#include "BTree.h"
#include <vector>
using std::vector;

class Solution {
public:
    int numTrees(int n) {
        return numTrees(1, n);
    }

    int numTrees(int l, int r) {
        if (l > r)
            return 1;
        if (_cache[l][r] != 0)
            return _cache[l][r];
        
        int res = 0;
        for (int i = l; i <= r; i++) {
            int left = numTrees(l, i-1);
            int right = numTrees(i+1, r);
            res += left*right;
        }
        _cache[l][r] = res;
        return res;
    }
private:
    vector<vector<int>> _cache{20, vector<int>(20, 0)};
};