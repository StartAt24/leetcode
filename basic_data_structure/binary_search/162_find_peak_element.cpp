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
                // 这里要注意搜索区间的变化，
                // 如果是 mid+1 > mid的话，则说明 mid肯定不是峰值，可以在下一轮的循环中去掉，所以是 left = mid+1；
                // 如果是 mid+1 < mid的话，则说明 mid自己可能是峰值，在下一轮的循环中仍然需要，所以是 right = mid;
                right = mid;
            }
        }
        return left;
    }
};