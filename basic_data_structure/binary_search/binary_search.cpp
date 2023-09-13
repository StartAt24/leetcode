#include "common.hpp"

int binarySearch(vector<int> nums, int target) {
    int left = 0, right = ...;
    while(...) {
        int mid = left + (right-left)/2;
        if (nums[mid] == target) {
            ...
        } else if (nums[mid] > target) {
            right = ...
        } else if (nums[mid] < target) {
            left = ...
        }
        return ...
    }
}


int leftBoundryBinarySearch(vector<int> nums, int target) {
    int left = 0, right = nums.size();
    // search area is [left, right)
    while(left < right) {
        // left 最大为right-1 所以 mid永远不会越界。
        int mid = left + (right-left)/2;
        if (mid == target) {
            // 向左继续搜索 [left, mid)
            right = mid;
        } else if (mid > target) {
            // 正常处理
            right = mid;
        } else if (mid < target) {
            left = mid + 1;
        }
    }
    // 结束的时候 因为始终是在往左靠近，
    // 且 left == right, 因为这个时候 right其实就是刚刚得到的最后一个正确答案。
    // 所以如果存在target的话，那么
    if (left < 0 || left > nums.size()-1)
        return -1;
    // 所以这里 应该判断 left是否是这个target的值
    return nums[left] == target? left : -1;
}