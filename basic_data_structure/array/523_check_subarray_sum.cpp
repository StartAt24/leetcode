#include "common.hpp"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> umap;
        int n = nums.size();
        int remainder = 0;
        
        // 如果从第一位开始计算，到某个长度的时候刚好出现余数为0的情况，这个时候去map里查找。
        // 是会发现没有 0对于的index的，其实这个0对应的index 就是 index为0的情况。
        // 所以等于-1 来确保 idx-这个值的时候长度算的是对的
        umap[0] = -1;
        for (int i = 0; i < n; i++) {
            // 检测到当前的所有数字的和 与 k的余数
            remainder = (remainder + nums[i])%k;
            // 如果余数有相同的，则说明减去这部分 剩余的部分就是想要的
            if (umap.contains(remainder)) {
                int pre_idx = umap[remainder];
                if (i - pre_idx >= 2)
                    return true;
            } else {
                umap[remainder] = i;
            }
        }
        return false;
    }
};
