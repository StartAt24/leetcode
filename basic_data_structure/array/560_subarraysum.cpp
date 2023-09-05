#include "common.hpp"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> umap;
        int sum = 0;
        int n = nums.size();
        int res = 0;
        umap[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (umap.contains(sum-k)) {
                res += umap[sum-k];
            }
            umap[sum]++;
        }
        return res;
    }
};