#include "common.hpp"

class Solution {
    int solve(vector<int> nums, int k) {
        unordered_map<int, int> umap{{0, -1}};
        int pre_sum = 0;
        int len = 0;

        for (int i = 0; i < nums.size(); i++) {
            pre_sum += nums[i];
            if (!umap.contains(pre_sum)) {
                umap[pre_sum] = i;
            }
            int target_val = pre_sum - k;
            if (umap.contains(target_val)) {
                int j = umap[target_val];
                len = max(i-j, len);
            }
        }
        return len;
    }
};