#include "common.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 相当于把一个连续的数组截成了两个
        // 且两端都是连续的
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            // 因为存在水平的区域，所以要先把这部分剔除掉，这样逻辑就和之前一样了。
            while (left < right && nums[left] == nums[left+1])
                left++;
            
            while (left < right && nums[right] == nums[right-1])
                right--;

            int mid = left + (right - left) / 2;
            int mid_val = nums[mid];
            // 确定 mid当前的位置是在哪里
            if (mid_val == target)
                return mid;

            if (mid_val >= nums[left]) {
                // mid 在左侧断崖上
                // 则 [left, mid] 为单调递增
                if (nums[left] <= target && target < mid_val) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }

            } else {
                // mid 在右侧断崖上
                // 原因是右侧断崖上的所有数字都比左侧小
                // [mid, right] 为单调递增
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};