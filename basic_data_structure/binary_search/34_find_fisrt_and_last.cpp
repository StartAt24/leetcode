#include "common.hpp"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector{leftBoundryBinarySearch(nums, target), rightBoundryBinarySearch(nums, target)};
    }
private:
    int leftBoundryBinarySearch(vector<int> nums, int target) {
        if (nums.size() == 0)
            return -1;

        int left = 0, right = nums.size();
        // search area is [left, right)
        while(left < right) {
            int mid = left + (right-left)/2;
            int val = nums[mid];
            if (val == target) {
                right = mid;
            } else if (val > target) {
                right = mid;
            } else if (val < target) {
                left = mid + 1;
            }
        }
        if (left < 0 || left >= nums.size())
            return -1;

        return nums[left] == target? left : -1;
    }

    int rightBoundryBinarySearch(vector<int> nums, int target) {
        if (nums.size() == 0)
            return -1;

        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left)/2;
            int val = nums[mid];
            if (val == target) {
                left = mid + 1;
            } else if (val > target) {
                right =  mid;
            } else if (val < target) {
                left = mid + 1;
            }
        }

        if (left - 1 < 0 || left - 1 >= nums.size())
            return -1;
        
        return nums[left - 1] == target ? left -1 : -1;   
    }
};