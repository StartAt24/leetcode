#include "common.hpp"

int f(int x,  const vector<int>& nums) {
    return nums[x];
}

int left_bound(int target, vector<int> nums) {
    int left = 0, right = nums.size();
    while(left < right) {
        int mid = left + (right -left)/2;
        int val = f(mid, nums);
        if (val == target) {
            right = mid;
        } else if ( val > target) {
            right = mid;
        } else if ( val < target) {
            left = mid+1;
        }
    }
    if (left >= nums.size())
        return -1;

    return nums[left] == target ? left : -1;
}