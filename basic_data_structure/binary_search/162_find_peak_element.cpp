#include "common.hpp"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        // 因为题目必有解， 所以 left == right为结束条件
        while (left < right) {
            int mid = left + (right - left)/2;
            int mid_val = nums[mid];
            int mid_right_val = nums[mid+1];
            if (mid_val < mid_right_val) {
                // 证明峰值在右边
                left = mid + 1;
            } else if (mid_val > mid_right_val){
                // mid 自身为峰值 或者 峰值在mid左侧
                right = mid;
            }
        }
        return left;
    }
};