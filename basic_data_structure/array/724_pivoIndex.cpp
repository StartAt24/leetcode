#include "common.hpp"
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sum_vec(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum_vec[i+1] = sum_vec[i] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            int sum_left = sum_vec[i];
            int sum_right = sum_vec[nums.size()] - sum_vec[i+1];

            if (sum_left == sum_right)
                return i;
        }
        return -1;
    }
};