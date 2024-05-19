#include "BTree.h"
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // 行数只能从第一行开始，不能从第0行开始
        vector<int> res;
        while(label>1) {
            res.push_back(label);
            label = label/2;

            int row = std::log2(val);
            int minVal = pow(2, row);
            int maxVal = pow(2, row+1) - 1;
            label = maxVal - (label-minVal);
        }
        path.push_back(1);
        std::reverse(res.begin(), res.end());
        return res;
    }
};