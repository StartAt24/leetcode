#include "common.hpp"
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        // 结束的条件是  left == right, 因为题目存在解，所以结束的时候不需要多循环一次。
        while (left < right) {
            int mid = left + (right - left) / 2;
            int mid_val = arr[mid];
            int mid_right_val = arr[mid+1];
            if (mid_val < mid_right_val)
                left = mid+1;
            else 
                right = mid;
        }

        return left;
    }
};