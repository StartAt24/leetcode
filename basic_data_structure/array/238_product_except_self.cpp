#include "common.hpp"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_product_vec(nums.size(), nums[0]);
        vector<int> after_product_vec(nums.size(), nums[n-1]);
        vector<int> res(nums.size());


        for (int i = 1; i < nums.size(); i++) {
            pre_product_vec[i] = pre_product_vec[i-1] * nums[i];
        }

        for (int i = nums.size()-2; i>=0; i--) {
            after_product_vec[i] = after_product_vec[i+1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            res[i] = pre_product_vec[i-1]*after_product_vec[i+1];
        }

        return res;
    }
};