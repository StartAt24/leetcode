#include "common.hpp"
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 反过来思考，寻找最长连续子数组
        // 使得 最长连续子数组的和为 nums.sum() - x;
        x = std::accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> umap{{0,-1}};
        int res = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (!umap.contains(sum)) {
                umap[sum] = i;
            }

            if (umap.contains(sum - x)) {
                int j = umap[sum-x];
                if (res == -1)
                    // i-j等于中间的数字个数，n-(i-j)即剩余的个数，也就是题目要求的解
                    res = n-(i-j);
                else {
                    res = min(res, n-(i-j));
                }
            }
        }

        return res;
    }
};