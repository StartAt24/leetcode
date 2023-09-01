#include "common.hpp"
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = nums.size();
        vector<int> sum_vec(count + 1, 0);
        std::unordered_map<int, int> sum_map;
        for (int i = 0; i < count; i++) {
            sum_vec[i+1] = sum_vec[i] + nums[i];
            sum_map[sum_vec[i+1]] = i;
        }

        for (int i = 0; i < count; i++) {
            
        }
    }
};