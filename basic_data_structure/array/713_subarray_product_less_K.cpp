#include "common.hpp"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 没必要用前缀乘积，实在是太难写。
        if (k <= 1)
            return 0;
        int n = nums.size(), ret = 0, product = 1, left = 0;
        for ( int right = 0; right < n; right++) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            ret += right - left + 1;
        }

        return ret;
    }
};