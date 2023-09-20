#include "common.hpp"

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // 确定最小值和最大值 
        // 最小值为 当前数组里的最小值，最大值为全部的数组
        int left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++) {
            left = max(left, nums[i]);
            right += nums[i];
        }
        right++;

        while (left < right) {
            int mid = left + (right - left) /2;
            int val = splitArray(nums, mid);

            if (val == k) {
                // 想左边取最小值
                right = mid;
            } else if ( val > k) {
                left = mid + 1;
            } else if ( val < k) {
                right = mid;
            }
        }
        return left;
    }
private:
    // 当前可以分成多少个 array,必须是 == k的
    int splitArray(const vector<int>& nums, int m) {
        int ret = 0;
        for (int i = 0; i < nums.size();) {
            int cap = m;
            while (i < nums.size()) {
                if (cap < nums[i]) {
                    // 没有能力装载更多的了
                    break;
                } else {
                    cap -= nums[i];
                }
                i++;
            }
            ret++;
        }
        return ret;
    }
};

