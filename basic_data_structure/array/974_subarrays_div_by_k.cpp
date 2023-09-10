#include "common.hpp"
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pre_sum = 0;
        int n = nums.size();
        int ret = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)  {
            pre_sum += nums[i];
            int reminder = pre_sum % k;
            if (reminder == 0) {
                ret++;
            } else {
                umap[reminder]++;
                if (umap.contains(k-reminder)) {
                    ret += umap[k-reminder];
                }
            }
        }
        return ret;
    }
};